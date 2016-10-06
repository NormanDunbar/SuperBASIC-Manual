==========
Keywords U
==========


UINT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  UINT (x%)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function UINT returns the unsigned value of a (signed) integer::

    unsigned = signed% + 2^16
    
or::

    unsigned = UINT(signed%)

**CROSS-REFERENCE**

`SINT <KeywordsS.clean.html#sint>`__

--------------

UNDER
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  UNDER [#ch,] switch                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command switches underlining in the specified window (default #1)
either on or off. Underlining is enabled if switch=1
or disabled if switch=0. Other values of switch will return a 'bad
parameter' error. 

If underlining is enabled, whenever anything is
PRINTed, a line will be drawn in the current INK colour in the bottom
but one row of the character. 

If FLASH is enabled, although the
character will continue to flash, the underline itself will not. MODE
will disable underlining.

**Example 1**

::

    UNDER 1: PRINT 'Title:'!: UNDER 0: PRINT !'QL SuperBASIC'

**Example 2**

If you don't like the line which is drawn by underline than you can use
OVER to draw your own line with a different colour. Note however that
this line ought to be drawn before the underlined text since the line
should not overlap letters like g, p, q and j. 

::

    100 DEFine PROCedure PRNT_UNDL (ch, x, y, text$, col1, col2) 
    110   AT#ch,x,y: INK#ch,col2: OVER#ch,0 
    120   PRINT#ch,FILL$("_",LEN(text$)) 
    130   AT#ch,x,y: INK#ch,col1: OVER#ch,1 
    140   PRINT#ch,text$ 
    150   OVER#ch,0 
    160 END DEFine PRNT_UNDL  

::

    PAPER 3: CLS 
    PRNT_UNDL #1,3,3,"Looking good.",7,0

**NOTE**

MODE will reset the current underline mode in all windows.

**CROSS-REFERENCE**

`INK <KeywordsI.clean.html#ink>`__ sets the current ink colour for the
specified channel, `PRINT <KeywordsP.clean.html#print>`__ prints out
characters.

--------------

UNJOB
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  UNJOB drive\_filename                                            |
+----------+-------------------------------------------------------------------+
| Location |  UNJOB                                                            |
+----------+-------------------------------------------------------------------+

This command sets the file type of the given file (the full filename
must be supplied) to zero. The reason for this command is that certain
assemblers and tools set the file type to 1 (executable file) even
though the file cannot be started as a job. Since commands like EX or
EXEC check the file type to decide whether a file can be executed, they will
try to start such a file and crash the system in most cases. A simple
UNJOB prevents this in the long term.

**NOTE**

v1.00 of this command did not work on most QL ROM versions, giving a bad
parameter error.

**CROSS-REFERENCE**

Each file has a file type which can be found with the
`FTYP <KeywordsF.clean.html#ftyp>`__ and
`FILE\_TYP <KeywordsF.clean.html#file-typ>`__ functions or directly by looking
at the file header (`HEADR <KeywordsH.clean.html#headr>`__). It is also
possible to set the file type by rewriting the whole file header with
`HEADS <KeywordsH.clean.html#heads>`__; alternatively,
`UNJOB <KeywordsU.clean.html#unjob>`__ does the same.

--------------

UNL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  UNL                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch on underline
printing on an EPSON compatible printer, PRINT UNL is the same as::

    PRINT CHR$(27) & "-" & CHR$(1)

**CROSS-REFERENCE**

`NORM <KeywordsN.clean.html#norm>`__, `BLD <KeywordsB.clean.html#bld>`__,
`EL <KeywordsE.clean.html#el>`__, `DBL <KeywordsD.clean.html#dbl>`__,
`ENL <KeywordsE.clean.html#enl>`__, `PRO <KeywordsP.clean.html#pro>`__,
`SI <KeywordsS.clean.html#si>`__, `NRM <KeywordsN.clean.html#nrm>`__,
`ALT <KeywordsA.clean.html#alt>`__, `ESC <KeywordsE.clean.html#esc>`__,
`FF <KeywordsF.clean.html#ff>`__, `LMAR <KeywordsL.clean.html#lmar>`__,
`RMAR <KeywordsR.clean.html#rmar>`__, `PAGDIS <KeywordsP.clean.html#pagdis>`__,
`PAGLEN <KeywordsP.clean.html#paglen>`__.

--------------

UNLOAD
======

+----------+-------------------------------------------------------------------+
| Syntax   |  UNLOAD program\_name                                             |
+----------+-------------------------------------------------------------------+
| Location |  MutiBASIC (DIY Toolkit - Vol M)                                  |
+----------+-------------------------------------------------------------------+

Despite the name, this toolkit is completely different to the
MultiBASICs which are provided on Minerva ROMs. This toolkit actually
provides a quick means of saving and loading programs in memory - this
allows you to load a program which you are working on, store it in
memory and then alter the program. If the new alterations to the program
do not work out as planned and you want to revert to the original
version, you can simply RELOAD the original version from program in a
matter of seconds (rather than the minutes which it would take to LOAD
the original version from disk). 

This can be very useful for program
development, or, for example, if you have a SuperBASIC utility program
which you use a lot. 

This command allows you to store the currently
loaded SuperBASIC program in memory. You have to supply a name for the
program (similar to the name which you could use with the SAVE command,
except there is no need for a device name and the program name can be up
to 127 characters long). The program is then stored - details of the
programs which have been stored with this command are available from the
jobs list (see JOBS). When the program is stored in memory, the contents
of all variables and pointers are also stored, which makes certain that
if you UNLOAD a program whilst it is RUNning, you can later RELOAD it
and re-start it from the same place (with CONTINUE). 

Version 4.0+ of the
toolkit, allows you to store the current screen display and mode along
with the program, so that when the program is RELOADed, the display is
in a known layout. To further extend the usefulness of this toolkit, any
commands which appear after UNLOAD will be automatically executed when
the program is RELOADed, for example::

    UNLOAD test: RUN
    
will always RUN the program when you::

    RELOAD test

**NOTE 1**

The toolkit expects the display to be located at 131072 and be 512x256
pixels and so you should switch off the screen storage facility if you
are using a higher resolution display or a dual screen system.

**NOTE 2**

If a job already exists with the name which you have given to the
program, 'Already Exists' will be reported.

**NOTE 3**

Although the toolkit can be used to store programs from a Minerva
MultiBASIC, you cannot load the toolkit from a Multiple BASIC - an
'incomplete' error is reported.

**NOTE 4**

The current channel details are not stored when you use UNLOAD - you may
therefore need to re-open the channels when the program is RELOADed, or
use something akin to::

    UNLOAD 'watch': OPEN #3,con_448x200a32x16
    
which will always ensure that #3 is OPEN whenever the program is
RELOADed.

**NOTE 5**

If a program uses ALCHP to grab some memory, unless you intend to always
RUN the program from the start when you RELOAD
it, do not use any command which will release this area of common heap
memory before you RELOAD the program. Commands which do this include::


    CLCHP
    CLEAR
    NEW
    LOAD

**WARNING 1**

This toolkit does not work on SMSQ/E and can crash the computer.

**WARNING 2**

Unfortunately, attempts to use this toolkit to UNLOAD files from one
interpreter and then RELOAD the files into another Multiple BASIC will
crash that Multiple BASIC (or have other various undesirable effects).

**CROSS-REFERENCE**

`SCR\_SAVE <KeywordsS.clean.html#scr-save>`__ allows you to dictate whether
the screen display and mode should be stored together with the program.
`RESAVE <KeywordsR.clean.html#resave>`__ is similar.
`REMOVE <KeywordsR.clean.html#remove>`__ allows you to remove a program stored
in memory with this command. See also `RELOAD <KeywordsR.clean.html#reload>`__
and `QSAVE <KeywordsQ.clean.html#qsave>`__.

--------------

UNLOCK
======

+----------+-------------------------------------------------------------------+
| Syntax   |  UNLOCK file,code$,code                                           |
+----------+-------------------------------------------------------------------+
| Location |  CRYPTAGE                                                         |
+----------+-------------------------------------------------------------------+

See `LOCK <KeywordsL.clean.html#lock>`__.

**Example**

::

    UNLOCK ram1_secret_txt,"Phew",7241

--------------

UNSET
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  UNSET (variable)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  PARAMS (DIY Toolkit - Vol P)                                     |
+----------+-------------------------------------------------------------------+

This is the same as `DEFINED <KeywordsD.clean.html#defined>`__ and suffers from the same problem!

--------------

UPC$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  UPC$ (string$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  LWCUPC                                                           |
+----------+-------------------------------------------------------------------+

This is the same as `UPPER$ <KeywordsU.clean.html#upper>`__.

--------------

UPPER$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  UPPER$ (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, Function (DIY Toolkit - Vol R)                      |
+----------+-------------------------------------------------------------------+

This function takes the given string and converts any lower case
letters to capitals and then returns the whole string. Normally, only
the ASCII alphabet is catered for, which means that no national
characters are converted, ie. the function only works with A..Z and
a..z. 

The DIY Toolkit version will cope with accented characters, but
you may have to modify the source code in order for this function to
work with some international character sets which use an extended
alphabet.

**Example**

This is not quite an example for UPPER$ but a replacement which converts
all characters where an upper character is available:: 

    100 DEFine FuNction UPPER_$ (string$) 
    110   LOCal i,c,u,u$: u$="" 
    120   FOR i=1 TO LEN(string$) 
    130   c=CODE(string$(i)): u=c 
    140   SELect ON c=97 TO 122: u=c-32:=128 TO 139: u=c+32 
    150   u$=u$ & CHR$(u) 
    160   END FOR i 
    170   RETurn u$ 
    180 END DEFine UPPER_$

**CROSS-REFERENCE**

`UPC$ <KeywordsU.clean.html#upc>`__ returns the same as
`UPPER$ <KeywordsU.clean.html#upper>`__. See also
`CONVCASE <KeywordsC.clean.html#convcase>`__ and
`LOWER$ <KeywordsL.clean.html#lower>`__.

--------------

UPUT
====

+----------+-----------------------------------------------------------------------------+
| Syntax   || UPUT [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
|          || UPUT [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+-----------------------------------------------------------------------------+
| Location || SMSQ/E v2.55+                                                              |
+----------+-----------------------------------------------------------------------------+

This command is the same as BPUT, except that any bytes sent by it to
the specified channel (default #3) are not affected by the TRA command.
This command is therefore useful for sending printer control codes.

**CROSS-REFERENCE**

See `BPUT <KeywordsB.clean.html#bput>`__, `WPUT <KeywordsW.clean.html#wput>`__ and
`LPUT <KeywordsL.clean.html#lput>`__.

--------------

USE
===

+----------+-------------------------------------------------------------------+
| Syntax   |  USE [ #channel ]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  USE (DIY Toolkit - Vol C)                                        |
+----------+-------------------------------------------------------------------+

Many commands and functions which are described in this manual, expect
a channel number to be passed to them and if one is not supplied, will
default to a specific channel. This command can be used to re-direct all
machine code commands and functions which normally default to #1. 

After using this command, if a channel parameter is not specified, the
commands and functions will then default to the channel specified by USE
instead of #1. Also, *even* if you explicitly pass a channel number #1 as a
parameter to a command or function, then the command or function will
*still* be re-directed to the channel specified by USE. If no parameter is
specified, then this is equivalent to USE #1.

**Example**

::

    PRINT 'This is channel #1': USE #2: PRINT 'This is using Channel #2' 
    PRINT #1, 'This is still channel #2' USE: PRINT 'This is channel #1 again!'

**NOTE**

There is a slight difficulty in using this command in that when you USE
#1 some of the information used by SuperBASIC for the channel which you
have been using as the default will be lost. This is the last graphics
co-ordinates, turtle graphics direction, pen status, character position
on line and line width for files (set with WIDTH) will be lost. You will
also lose the original values for these offsets for channel #1 (ie. the
values which were in use prior to the USE #ch command). Instead, the
values are set to pen up, position 0,0, width 80, direction
left-to-right. You can use::

    PEEK_W(\48\chan*40+offset) 
    
to store these
values before the USE call and then restore them with POKE. Refer to
QDOS/SMS Reference Manual Section 18.4.1 to find out how these values
are stored.

**WARNING**

If used from within a SMS SBASIC, v0.2 (at least) of this command will
crash the computer when output is redirected to #1 using either USE or
USE#1. The problem only occurs when you try to send output to #1.

**CROSS-REFERENCE**

`PRINT <KeywordsP.clean.html#print>`__,\ `CSIZE <KeywordsC.clean.html#csize>`__,\ `INK <KeywordsI.clean.html#ink>`__,\ `PAPER <KeywordsP.clean.html#paper>`__
and\ `STRIP <KeywordsS.clean.html#strip>`__ are just a few of the commands
which default to #1 and are therefore affected by this command.
