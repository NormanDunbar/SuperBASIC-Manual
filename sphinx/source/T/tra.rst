..  _tra:

TRA
===

+----------+------------------------------------------------------------------+
| Syntax   | TRA table1 [,table2] or                                          |
|          |                                                                  |
|          | TRA [table1] ,table2                                             |
+----------+------------------------------------------------------------------+
| Location | QL ROM (post JM Version)                                         |
+----------+------------------------------------------------------------------+

This command allows you to perform various translations on data that is
passing through the serial ports. It is however one of the most
difficult commands in SuperBASIC to use.

The use of TRA will (on non-SMS
implementations) affect all data which is sent through the serial ports
after the command has been issued, translating bytes whether they are
screen dumps, printer control codes, or letters of the alphabet.

The two
parameters are addresses of two tables, table1 which contains details of
translations to be carried out on both incoming and outgoing data and
table2 which contains details of various messages used by the system.
Both tables are recognised by the word 19195 ($4AFB) at their start. If
either parameter is not specified, then the default value of -1 is
assumed, which tells QDOS to leave that translation table alone.

When
QDOS is first initiated translation is not enabled, which means that
data passing through the serial ports is unaffected. You can revert to
this situation by using the command TRA 0. You can also revert to the
original error messages with TRA ,1 (use TRA 0,1 to reset both to their
original status). The English character set is used in all ROM
implementations of the QL (no matter which country the machine is set up
for). However, you can select to use the 'local' character set for
serial communication purposes if you wish by using the command TRA 1
which tells QDOS to use the 'local' translation table (this has no
effect on UK ROMs).

The two translation tables have different formats
and uses, depending on whether the serial ports are being used for
transmission or receipt of data. We therefore deal with each table
separately. Note that TRA is implemented differently on THORs and SMS
see the separate notes on the make up of their translation tables.

**Table 1**


Table 1 is actually split into two lists:

- Transa contains a list of single character conversions;
- Transb which contains a list of multiple character conversions.

As to which list is used depends on whether the
channel is sending or receiving data:

1. If the channel is sending data, the outgoing character is first translated
   according to Transa, using the character code as an index. If the resulting
   value is a zero, Transb
   is scanned for the proper entry. However, if the resulting value is
   non-zero, then this is used as a replacement for the byte to be sent.

2. When receiving, only Transa is used. The table is scanned cyclically
   starting at the received character's position until a position is found
   containing the received value. The translated value will be this
   position index. If the received value is not found in the table, the
   value itself is used.

The physical format of table1 is as follows:

::

    Table1 Word      19195
           Word      Offset of Transa from Table1 (Transa-Table1)
           Word      Offset of Transb from Table1 (Transb-Table1)

    Transa 256 bytes (see below)
    Transb Byte      Number of multiple translations or 0 x bytes(see below)

Transa is a 256 byte list of character substitute codes for each character code from 0 to 255.
If you wish to use multiple translates for a given character, then you will
need to insert 0 in the appropriate place in this list.

Transb is a
table of multiple translations (which can only be used in transmit
mode). It is made up of four bytes for each translate, being the code to
be translated, followed by three replacement codes. If you do not need
three replacement codes, the unused ones should be zero. Unfortunately,
you cannot combine the effects of these various translations (see the
second example below).

**Table 2**

Table 2 allows you to set the various system and error messages used by
QDOS (for example to implement other languages). The format of Table2 is
even more complex::

    Table2  Word      19195
            Word      Offset of error1 from Table2 (error1-Table2)
            Word      Offset of error2 from Table2 (error2-Table2)
            ....
            Word      Offset of error20 from Table2 (error20-Table2)
            Word      Offset of error21 from Table2 (error21-Table2)
            Word      Offset of mess1 from Table2 (mess1-Table2)
            Word      Offset of mess2 from Table2 (mess2-Table2)
            ....
            Word      Offset of mess7 from Table2 (mess7-Table2)
            Word      Offset of mess8 from Table2 (mess8-Table2)

    error1  Word      Length of string
            Bytes     String forming message for 'not complete'

    error2  Word      Length of string
            Bytes     String forming message for 'invalid job'

            ....

    error21 Word      Length of string
            Bytes     String forming message for 'Bad Line'

    mess1   Word      Length of string
            Bytes     String to replace 'At line ' (***)

    mess2   Word      Length of string
            Bytes     String to replace ' sectors'

    mess3   Word      Length of string
            Bytes     String to replace 'F1 .. monitor F2 .. TV ' (***)

    mess4   Word      Length of string
            Bytes     String to replace '© 1983 Sinclair Research Ltd' (***)

    mess5   Word      Length of string
            Bytes     String to replace 'during WHEN processing'

    mess6   Word      Length of string
            Bytes     String to replace 'PROC/FN cleared'

    mess7   Bytes     String to replace 'SunMonTueWedThuFriSat' (***)

    mess8   Bytes     String to replace 'JanFebMarAprMayJunJulAugSepOctNovDec' (***)

Please note that all strings *other* than those marked (\*\*\*) *must* end with
a newline, CHR$(10).

Also please also note the differing format of mess7 and mess8.

Although the THOR computers support both of the above table
formats, the THOR has extended the usefulness of TRA in order to allow
you to send longer strings of characters for each translation. On the
other hand, SMS has implemented a different way of amending the messages
generated by the operating system (see below). Examples of the standard
format follow:

**Example 1**

A program to change all of the error messages to more meaningful
messages::

    100 Chk$=VER$
    105 IF Chk$='AH' OR Chk$='JM': PRINT'Not supported'
    110 table2=ALCHP(1024)
    120 RESTORE
    130 POKE_W table2,19195
    140 mess_add=table2+30*2
    150 FOR errx=1 TO 29
    160 POKE_W table2+errx*2,mess_add-table2
    170 READ mess$
    180 IF errx<28
    190 SELect ON errx: =1 TO 21,23,26 TO 27: mess$=mess$&CHR$(10)
    200 POKE_W mess_add,LEN(mess$): mess_add=mess_add+2
    210 END IF
    220 FOR move_mess=1 TO LEN(mess$)
    230 POKE mess_add,CODE(mess$(move_mess)): mess_add=mess_add+1
    240 END FOR move_mess
    250 overf=mess_add/2:IF overf<>INT(overf): mess_add=mess_add+1
    260 END FOR errx
    270 TRA 0,table2
    280 DATA 'Operation Not Complete'
    290 DATA 'Job Does Not Exist'
    300 DATA 'Insufficient Memory'
    310 DATA 'Parameter Outside Permitted Range'
    320 DATA 'Buffer Full'
    330 DATA 'Channel Not Open'
    340 DATA 'File or Device Not Found'
    350 DATA 'File Already Exists'
    360 DATA 'File or Device In Use'
    370 DATA 'End of File'
    380 DATA 'Drive Full'
    390 DATA 'Invalid File or Device Name'
    400 DATA 'Transmit Error'
    410 DATA 'Format Failed'
    420 DATA 'Invalid Parameter'
    430 DATA 'Filing System Medium Check Failed'
    440 DATA 'Invalid Expression'
    450 DATA 'Maths Overflow'
    460 DATA 'Operation Not Implemented'
    470 DATA 'Read Only Device'
    480 DATA 'Invalid Syntax'
    490 DATA 'At line '
    500 DATA ' sectors'
    510 DATA 'F1 .. monitor'&CHR$(10)&'F2 .. TV'
    520 DATA '©1983 Sinclair Research Ltd.'
    530 DATA 'During WHEN processing'
    540 DATA 'PROC/FN Definition Cleared'
    550 DATA 'SunMonTueWedThuFriSat'
    560 DATA 'JanFebMarAprMayJunJulAugSepOctNovDec'

**Example 2**

A short program to allow you to print pound signs (£) from SuperBASIC
(this assumes an Epson compatible printer which is set up in US ASCII
mode)::

    100 table1=ALCHP(1024)
    110 POKE_W table1,19195
    120 Transa=table1+6
    130 Transb=Transa+256
    140 FOR i=0 TO 255:POKE Transa+i,i
    150 POKE_W table1+2,Transa-table1
    160 POKE_W table1+4,Transb-table1
    170 POKE Transb,3
    175 POKE Transa+128,0: POKE Transa+129,0: POKE Transa+CODE('£'),0
    180 POKE Transb+1,128
    190 POKE Transb+2,27: POKE Transb+3,CODE('R'): POKE Transb+4,3
    200 POKE Transb+5,129
    210 POKE Transb+6,27: POKE Transb+7,CODE('R'): POKE Transb+8,0
    215 POKE Transb+9,CODE('£')
    216 POKE Transb+10,128: POKE Transb+11,CODE('#'): POKE Transb+12,129
    220 TRA table1,0

Unfortunately, despite lines 215 and 216, the command::

    OPEN #3,ser1: PRINT #3,'£'

will still fail to produce a pound sign on your printer (you will get a
single quote mark normally).

This demonstrates the fact that you cannot
link translates. To get a pound sign, you will need to use the line::

    OPEN #3,ser1: PRINT#3,CHR$(128) & '£' & CHR$(129)

Indeed, because of the nature of the translation tables, the following
has exactly the same effect as the above program::

    100 table1=ALCHP(1024)
    110 POKE_W table1,19195
    120 Transa=table1+6
    130 Transb=Transa+256
    140 FOR i=0 TO 255:POKE Transa+i,i
    150 POKE_W table1+2,Transa-table1
    160 POKE_W table1+4,Transb-table1
    170 POKE Transb,2
    180 POKE Transa+128,0:POKE Transa+129,0
    190 POKE Transa+CODE('£'),CODE('#')
    200 POKE Transb+1,128
    210 POKE Transb+2,27: POKE Transb+3,CODE('R'):POKE Transb+4,3
    220 POKE Transb+5,129
    230 POKE Transb+6,27: POKE Transb+7,CODE('R'):POKE Transb+8,0
    240 TRA table1,0

**NOTE 1**

An extended serial driver is available in the public domain which
enables Minerva machines and Amiga QDOS to use a translation table the
same as the extended translation table provided on the THOR XVI.

**NOTE 2**

On Minerva ROMs (v1.83 or earlier), there are problems when using TRA
with only one parameter.

**NOTE 3**

JS ROMs have problems in translating characters above CHR$(127)

**SMS NOTES**

SMS supports the standard format table1. However, the messages cannot be
altered using table2 - use LANG\_USE for this. As with the original
version, if table1 is specified to be 0, this will deactivate the
translation. However, it does not smash the pointer to a user-defined
translation routine which can then be re-activated with TRA 1 (compare
the original version where you would need to re-run the program setting
up the user-defined translation table).

SMS also allows you to have
language dependent translation tables (linked to one of the languages
currently loaded - see LANG\_USE). To enable these, use the command::

    TRA 1,lang

where lang is the Car Registration Code or Language code of the
country.

::

    TRA 0,lang

will set up the relevant translation table, ready to be enabled with
TRA 1.

There are also several in-built language independent translate
tables which are accessed by setting table1 to small values. The
dip-switches on your printer need to be set to USA. Currently there are
only two language independent translate tables supported (so far as we
are aware):

- The command TRA 3 will enable IBM Graphics translation table:

    - QDOS CHR$(HEX('C0')) to CHR$(HEX('DF')) and
      CHR$(HEX('F0')) to CHR$(HEX('FF')) are passed through the channel unchanged.
    - CHR$(HEX('E0')) to CHR$(HEX('EF')) are translated to represent CHR$(HEX('B0')) to
      CHR$(HEX('BF')) respectively.
    - As from v2.50, the paragraph sign, CHR$(HEX('15')) is also passed through unaffected.


- The command TRA 5 will enable GEM VDI translation table:

    - Here QDOS CHR$(HEX('C0')) to CHR$(HEX('FF')) are passed through the port unchanged.

Also please note that under SMS, TRA will only affect
channels which are OPENed after the TRA command, or channels which have
already been OPENed with TRA active. In any case, TRA 0
never affects OPEN channels. TRA address will also not affect OPEN
channels which have been affected by TRA 0. Note however that changing
the BAUD rate will affect the translate on ALL channels.

**SMS Example**

::

    TRA 1: REMark Enable translate table for Country set up by default.
    TRA 1,F: REMark Enable French Translation table.
    TRA 0: REMark Disable Translate Tables.
    TRA 1: REMark Re-enable French Translation Table

**THOR XVI NOTES**

The THOR XVI supports both the standard translation format above and
also an expanded Translation Table, which replaces Table1 by a larger
table in the following format:

**Thor Table1**

The format of the new expanded Translation Table is::

    Table1  Longword  $4AFB0001 Distinguishes the new table from the old one.
            Word      Offset of Transa from table1 (Transa-table1)
            Word      Offset of Transb from table1 (Transb-table1)
            Longword  Offset of Pream from table1 (Pream-table1)
            Longword  Offset of Post from table1 (Post-table1)

    Transa  256 Bytes (See below)
    Transbx Bytes     (See below)
    Pream   Word      Length of preamble string
            Bytes     String to be sent when channel is opened
    Post    Word      Length of postamble string
            Bytes     String to be sent when channel is closed

The format of Transa and Transb is slightly different from the standard
translation table:

Transa is a 256 byte list of one character conversions, with an entry of zero if Transb is to be used.

Transb is however much more complex as each entry is made up of the following
(allowing a string of up to 255 characters to be sent as a replacement
for the given character)::

    Transb  Byte      Character to be replaced
            Byte      Length of a string to replace character x
            Bytes     A string (up to 255 characters long) to replace the given character.

The last entry in this list must be 0,1,0 to allow nul characters to be sent.

Transb is generally therefore in the following format::

    Transb   x Bytes ch1,len1,'text1'
             x Bytes ch2,len2,'text2'
             ....
             x Bytes chn,lenn,'textn'
             x Bytes 0,1,0

**THOR Example**

For example, following upon our earlier example, one entry in Transb
would allow for trouble-free translation of the pound sign. This could
therefore be achieved by the program listed below::

    100 table1=ALCHP(1024)
    110 POKE_L table1,HEX('4AFB0001')
    120 Transa=table1+16
    130 Transb=Transa+256
    140 FOR i=0 TO 255: POKE Transa+i,i
    150 POKE_W table1+4,Transa-table1
    160 POKE_W table1+6,Transb-table1
    170 POKE_L table1+8,0
    180 POKE_L table1+12,0
    190 POKE Transa+CODE('£'),0
    200 POKE Transb,CODE('£')
    210 POKE Transb+1,7
    220 POKE Transb+2,27: POKE Transb+3,CODE('R'): POKE Transb+4,3
    230 POKE Transb+5,CODE('#')
    240 POKE Transb+6,27: POKE Transb+7,CODE('R'): POKE Transb+8,0
    250 POKE Transb+9,0: POKE Transb+10,1: POKE Transb+11,0
    260 TRA table1,0

The preamble and postamble entries allow you to set up the printer when
the channel is opened or closed. These can both be up to 32767
characters long.

From version 6.41, the TRA command has been enhanced to
make extra use of the various different character sets supplied as
standard on this QDOS implementation. The Russian, Russisk and Greek
language set-ups now use a table converting $80 ... $BF to $60 ... $DF
to allow use with down-loaded character sets or Brother/HP Laser Jet +
laser printers, where codes $80 ... $9F are often treated as control
codes.

The default translate table (TRA 1) now works reasonably with ISO
codes, allowing printers to be set in the appropriate language range.
This works okay with the French, Danish, Spanish, Japanese, and German
set-ups (except for the paragraph character in German). On the Swedish
language set-up, only U/u umlaut (Ü/ü) does not work and the Italian language
set-up fails on e grave (é), u and a acute (ú and á), due to the conflict with French.

A special extended translation table will always be required for the
Russisk, Russian and Greek language set-ups, depending on the type of
printer connected to the system.

**CROSS-REFERENCE**

Please refer to the Appendix concerning serial and parallel device
drivers.

--------------


