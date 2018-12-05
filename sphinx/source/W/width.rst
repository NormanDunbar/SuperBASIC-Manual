..  _width:

WIDTH
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  WIDTH [#channel,] x                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The WIDTH command is an output formatting command which allows the user
to specify the width of a device which is being used by the QL for
output (such as a printer) on the given channel (default #1). This can
only be used on non-screen (ie. not scr\_ or con\_) channels and only
has any effect if you use one of the separators exclamation mark (!);
comma (,) or TO when PRINTing.

The value of x should represent the number of characters
wide which the output device is to use (the default is 80 characters).

**Example**

A short procedure to output text to a non-screen device of a given width
without chopping off any words at the end of each line::

    100 :
    110 t$ = 'The way in which the WIDTH command works is very particular to the QL '
    120 t$ = t$ & 'and is really only suited for specific types of work. If you do not '
    130 t$ = t$ & 'use the separators ! or , then the text will still be output at the '
    140 t$ = t$ & 'default width of 80'
    115 :
    200 OPEN_NEW #3,ram2_junk
    210 DUMP_TEXT #3, t$, 80
    220 DUMP_TEXT #3, t$, 40
    230 :
    240 CLOSE#3
    250 :
    260 :
    1000 DEFine PROCedure DUMP_TEXT(chan,str$,wid)
    1010   LOCal word$
    1020   WIDTH #chan,wid
    1030   IF str$="" THEN RETurn
    1040   word_start=1
    1050   REPeat word_loop
    1060     word_end=(' ' INSTR str$)-1
    1070     IF word_end>=word_start
    1080       word$=str$(word_start TO word_end)
    1090     ELSE
    1100       word$=str$(word_start TO )
    1110     END IF
    1120     PRINT #chan;!word$!:PRINT !word$!:PAUSE
    1130     IF word_end+2>LEN(str$) OR word_end=-1:EXIT word_loop
    1140     str$=str$(word_end+2 TO )
    1150   END REPeat word_loop
    1160 END DEFine

**CROSS-REFERENCE**

See :ref:`open` and :ref:`print`.

--------------


