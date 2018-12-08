..  _poke-l:

POKE\_L
=======

+----------+----------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | POKE address,value  or                                                                                                           |
|          |                                                                                                                                  |
|          | POKE address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ (Minerva and SMS only)  or                               |
|          |                                                                                                                                  |
|          | POKE address, {value\ :sup:`1` \| value\ :sup:`1`\ $} :sup:`\*`\ {,value\ :sup:`i` \| value\ :sup:`i`\ $}\ :sup:`\*` (SMS only)  |
|          |                                                                                                                                  |
|          | and                                                                                                                              |
|          |                                                                                                                                  |
|          | POKE\_W address,value  or                                                                                                        |
|          |                                                                                                                                  |
|          | POKE\_W address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ (Minerva and SMS only)                                |
|          |                                                                                                                                  |
|          | and                                                                                                                              |
|          |                                                                                                                                  |
|          | POKE\_L address,value  or                                                                                                        |
|          |                                                                                                                                  |
|          | POKE\_L address, value\ :sup:`1` :sup:`\*`\ [,value\ :sup:`i`]\ :sup:`\*`\ (Minerva and SMS only)                                |
+----------+----------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                           |
+----------+----------------------------------------------------------------------------------------------------------------------------------+

Both kinds of internal memory (RAM and ROM) are organised as a stream
of values. The basic unit for memory is a bit (a value of 0 or 1
relating to false or true), which relates to the binary system of
counting.

Eight bits are combined to form a byte (0 to 255), sixteen
bits make a word, and thirty-two a longword. Words and longwords are
signed whilst bytes are unsigned.

The POKE commands allow you to set values in memory.

It is however unwise to POKE just anywhere, because
there could be important code present in that part of memory which will
be disrupted by POKEs and could crash your computer. You would generally
have already set aside a part of memory for use by your own programs, by
using RESPR or ALCHP and then you would POKE
different values in that part of memory, eg. for storing data. This is
a representation of the relationship between bits, bytes, words and
longwords:

.. COMMENT (Norman)
   I think Rich missed something here. The data in the following table has
   leading '1' bits, so as a 16 bit word, the value must be negative. PEEK_W and
   PEEK_L return negatives as necessary.

   The original values were 39048 and 57272, both of which are bigger than
   32,767, so must be negative. Flip the bits and add 1 to get the
   correct/negative values here.

   He did correctly identify the negativity of the long word though.

+------------+----------+----------+----------+----------+
| Bits       | 10011000 | 10001000 | 11011111 | 10111000 |
+------------+----------+----------+----------+----------+
| Bytes      | 152      | 136      | 223      | 184      |
+------------+----------+----------+----------+----------+
| Words      | -26488              | -8264               |
+------------+----------+----------+----------+----------+
| Long Word  | -1.73586E9                                |
+------------+----------+----------+----------+----------+

or

+------------+----------+----------+----------+----------+
| Bits       | 01110110 | 11000111 | 01100000 | 00000011 |
+------------+----------+----------+----------+----------+
| Bytes      | 118      | 199      | 96       | 3        |
+------------+----------+----------+----------+----------+
| Words      | 30407               | 24579               |
+------------+----------+----------+----------+----------+
| Long Word  | 1.992778E9                                |
+------------+----------+----------+----------+----------+

**NOTE 1**

Negative values can also be stored in memory. However, they are stored
by deducting the number from the maximum number which can be stored in a
byte plus one.

::

    POKE 131072,255
    POKE 131072,-1

have the same effect.

**NOTE 2**

Do not try to POKE\_W or POKE\_L to an odd address (eg. 10001) as this
will cause an error unless you are using Minerva (see below).

**NOTE 3**

If you try to poke a value which is too big to fit into the given space,
eg::

    POKE 131072, -32768

then only the least significant byte is used
(with POKE) and the low word is used (with POKE\_W).

**NOTE 4**

The THOR XVI limits value to the following ranges: POKE: -128..255;
POKE\_W: -32768..65535

**MINERVA NOTES**

The POKE, POKE\_W and POKE\_L commands on Minerva (version 1.77 or
later) are very much enhanced and different. Minerva allows you to
POKE\_W and POKE\_L to odd addresses. eg::

    POKE_W 131073,100100

Minerva has also added to the usefulness of the POKE, POKE\_W
and POKE\_L commands by allowing them to store a list of numbers in one
go.

As an example the following two program lines have exactly the same
effect, although only line 100 will run on a non-Minerva QL.

::

    100 POKE_W start,10: POKE_W start+2,125: POKE_W start+4,10322
    110 POKE_W start,10,125,10322

Minerva also allows the BASIC programmer to access the QL's SuperBASIC
variables, system variables and Minerva's own System Xtensions (although
the extended PEEKs should be of more use). You will need a good book on
QDOS (eg. QDOS/SMS Reference Manual) to find out what the possible
values are. The syntax for these extra commands is:

**Alter SuperBASIC variables**

::

    POKE \\SBvar,value: REMark SBvar=0...256
    POKE_W \\SBvar,value
    POKE_L \\SBvar,value

::

    POKE \SBvar\Offset,value
    POKE_W \SBvar\Offset,value
    POKE_L \SBvar\Offset,value

**Alter System variables**

::

    POKE !!Sysvar,value: REMark Sysvar=0...1152
    POKE_W !!Sysvar,value
    POKE_L !!Sysvar,value

::

    POKE !Sysvar!Offset,value
    POKE_W !Sysvar!Offset,value
    POKE_L !Sysvar!Offset,value

The command

::

    POKE \\SBvar,value

will alter the SuperBASIC variable pointed to by Sysvar, such as the
current line number. The most useful of these are variables $68 onwards.


The command

::

    POKE \SBvar\Offset,value

allows you to alter the different SuperBASIC tables used by the QL (eg.
the channel table). The start addresses of the different tables are
contained in the SuperBASIC variables $0 to $64. SBvar must contain the
relevant SuperBASIC variable (the pointer to the required table), then
the Offset is the required address within the table.

The command

::

    POKE !!Sysvar,value

allows you to alter the different system variables (normally stored at
$28000 on a QL, but they can move!). These are useful for accessing the
current network number, finding free space, accessing device drivers,
forcing <CAPSLOCK>..... Sysvar merely contains the number of the
required system variable.

The command

::

    POKE !Sysvar!Offset,value

takes the address contained within the given system variable, adds the
Offset to that address and then pokes it with the given value.

On a Minerva machine the system variable stored at $7C (124) (SV.CHTOP)
contains the address of the Minerva System Xtensions, therefore to alter
these::

    SysX = PEEK_L (ver$(-2) + 124)
    POKE SysX + offset,value
    POKE_W SysX + offset,value
    POKE_L SysX + offset,value

Minerva's System Xtensions provide such things as the addresses for
translation tables, the attributes for the size type and colour of a
cursor, the fonts for all subsequently opened windows and much more...
(see Minerva manual for list).

**Minerva Example 1**

It is sometimes useful to alter the key repeat delay and frequency to
make allowances for when a different keyboard is attached to the QL, so
that you can type more quickly without having the problem that you are
waiting around for auto-repeat to take effect. These two values can now
simply be altered using::

    POKE_W !!140, key_delay
    POKE_W !!142, key_frequency

**Minerva Example 2**

Want to attach a new font to all channels which will be opened in the
future?

::

    100 a=RESPR(2000)
    110 LBYTES flp1_new_font, a
    120 POKE_L !124!40, a

**Minerva Example 3**

It might be useful in an error trapping routine to find the current DATA
position (eg. if there is an error when reading data into a variable),
so that the position may be returned to later once the error has been
overcome. You may even wish to miss out the problem DATA line. This
program is an 'intelligent' data-loader::

    100 WHEN ERRor
    110 data_line=PEEK_W(\\148)
    115 PRINT 'ERROR IN DATA LINE'!data_line!';statement'! PEEK(\\151)-1
    120 INPUT 'Go to next data line (y/n)'!a$
    130 IF a$=='y': POKE_W\\148,data_line+1: POKE\\150,1:POKE\\151,1: RETRY
    140 IF a$=='n' THEN
    145   data_store=PEEK_W(\\148)*65536+(PEEK(\\150)-1)*256+PEEK(\\151)-1
    147   PRINT"Alter offending line then enter re_run":STOP
    149 END IF
    150 END WHEN 155 :
    160 RESTORE
    170 ax=RESPR(100):i=0
    180 REPeat data_load
    190   IF EOF: EXIT data_load
    200   READ b
    210   PRINT b,i:POKE ax+i,b
    220   i=i+1
    230 END REPeat data_load
    240 DATA 10,10,2,3,3a,10
    250 DATA 10,2,2,3,3,2
    255 :
    260 DEFine PROCedure RE_run
    270   POKE_L \\148,data_store: GO TO 170
    280 END DEFine

**SMS NOTE**

POKE, POKE\_W and POKE\_L have been made the same as on Minerva except
that POKE\_W and POKE\_L cannot address odd addresses.

SMS does not
possess Minerva's System Xtensions.

Please also note that SMS's improved
interpreter won't allow you to enter line 240 in the Minerva Example 3
as the data item 3a will be rejected.

One extra addition to SMS is that the POKE command can actually accept a
string as a value to be poked into memory. If a string is passed as a
parameter, each character of the string is converted to its character
code and then that byte poked into memory, for example::

    POKE base,0,5,'WIN1_'

will store 'WIN1\_' as a standard QL string (a word containing its
length followed by the string itself) at the address in memory pointed
to by base. Note that if you pass an empty string, this will have no
effect.

**WARNING**

**If you are POKEing around in memory then make sure that you know what
you are doing.**

On every QDOS machine, even RAM areas which have not been
set aside for program use are used by the operating system, eg. for
buffering purposes. On Emulators and QLs fitted with a Gold Card, the
operating system itself is no longer in ROM but is moved into RAM.
POKEing in this area will almost surely lead to crashes. Even advanced
users who know which parts of memory are used by QDOS should avoid
amending QDOS directly. There are more elegant and safer methods how to
do this which will run on every QDOS compatible computer.

**CROSS-REFERENCE**

:ref:`peek`, :ref:`peek-w`,
:ref:`peek-l` and :ref:`peek-dlr`
read memory values and :ref:`poke-dlr` is another
command to set them. :ref:`char-def` allows you
to attach a font to all channels :ref:`open`\ ed
after the command. :ref:`pokes` allows you to
:ref:`poke` memory in Supervisor mode.

