
==========
Keywords X
==========

TODO
====

- Check this line `30     IF x=3 XOR y >1 AND y<3:PRINT x;'=>';y,` in the example for XOR. I'm not convinced it's a valid syntax! Maybe in C, but in SUPERBasic? 



..  _xchange:

XCHANGE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  XCHANGE (a1 TO a2, c1 TO c2)                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function XCHANGE replaces all occurrences of byte c1 by c2
from memory locations a1 to a2 inclusive. The function counts the
exchanged bytes and returns the sum.

**Example**

Provided that you have enough free memory, this small program replaces
line-feed characters CHR$(10) by carriage returns CHR$(13) in
ram1\_test\_txt as quickly as possible::

    100 ch=FILE_OPEN("ram1_test_txt",0) 
    110 IF ch<0 THEN REPORT ch: STOP 
    120 length=FLEN(#3) 
    130 memory=ALCHP(length) 
    140 IF NOT memory THEN REPORT -3: STOP 
    150 x=LOAD_FILE(#ch,memory,length) 
    160 IF XCHANGE(memory,memory+length-1,13,10) THEN 
    170   GET#ch\0 
    180   SAVE_FILE#ch,memory,x 
    190   TRUNCATE#ch 
    200 END IF 
    210 CLOSE#ch: RECHP memory

**CROSS-REFERENCE**

:ref:`search`, :ref:`copy-b`,
:ref:`copy-w`, :ref:`copy-l`

--------------


..  _xdraw:

XDRAW
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  XDRAW x1,y1 TO x2,y2                                             |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

The command XDRAW draws lines, just like LDRAW, but it draws the lines
in white ink, using the XOR mode; so drawing the same line will remove
it again without changing the background.

**Example**

::

    100 REPeat scan 110 w% = RND(1 TO 200) 
    120   FOR x% = 0 TO 511 + w% 
    130   IF x% < 512 THEN 
    140     XDRAW x%,0 TO x%,255 
    150   END IF 
    160   IF x% > w% - 1 THEN 
    170     XDRAW x%-w%,0 TO x%-w%,255 
    180   END IF 
    190   IF KEYROW(1)&&8 THEN EXIT scan 
    200   END FOR x% 
    210 END REPeat scan

**CROSS-REFERENCE**

:ref:`ldraw`, :ref:`line` with
:ref:`over`.

--------------


..  _xlim:

XLIM
====

+----------+-------------------------------------------------------------------+
| Syntax   || XLIM  or                                                         |
|          || XLIM #ch (v2.08+)                                                |
+----------+-------------------------------------------------------------------+
| Location || ATARI\_REXT (v1.29+)                                             |
+----------+-------------------------------------------------------------------+

This function returns the horizontal size of the screen in pixels. It
can therefore be used to ascertain if the Extended Mode-4 is present,
and if so, the size of the screen available to the program (ie. 512x256,
768x280 or larger!). The second variant makes this function the same as
SCR\_XLIM.

**Example**

A program may wish to use the whole of the screen for its output,
adapting itself accordingly::

    100 MAX_WIDTH=XLIM 
    110 MAX_HEIGHT=YLIM
    120 OPEN #1,'CON_' & MAX_WIDTH & 'x' & MAX_HEIGHT & 'a0x0'

**NOTE**

The Pointer Interface must be present in order for XLIM to work.

**CROSS-REFERENCE**

:ref:`ylim` returns the maximum screen height.
:ref:`qflim` and
:ref:`scr-xlim` are very similar. Use
:ref:`qram-dlr` or :ref:`wman-dlr` to
see if the Pointer Environment is available.

--------------


..  _xor:

XOR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  condition1 XOR condition2                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This combination operator combines two condition tests together and
will have the value 0 if both condition1 and condition2
are true or both are false or 1 if either condition1 or condition2
are true (but not both). 

Please note the difference between this and the bitwise XOR
operator: x^^y, which compares x and y bit by bit.

**Examples**

::

    PRINT 1 XOR 0: REMark Returns 1. 
    PRINT 2 XOR 10 REMark Returns 0. 
    
Compare:: 

    PRINT 2^^10
    
which returns 8. 

::

    10 FOR x=1 TO 5 
    20   FOR y=1 TO 5 
    30     IF x=3 XOR y >1 AND y<3:PRINT x;'=>';y, 
    40   END FOR y 
    50 END FOR x 

..  Does line 30 above actually work? This needs testing!

produces the following output::

    1=>2 2=>2 3=>1 3=>3 3=>4 3=>5 4=>2 5=>2

**CROSS-REFERENCE**

:ref:`and`, :ref:`or` and
:ref:`not` are the other combination operators.

--------------


..  _x-ptr-pct:

X\_PTR%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  X\_PTR%                                                          |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

This function will return the x co-ordinate of the pointer which is
controlled by the mouse. The value is given in absolute pixel
co-ordinates, with the point 0,0 being the top left hand corner of the
screen.

**CROSS-REFERENCE**

See :ref:`ptr-limits` and
:ref:`ptr-on`. :ref:`y-ptr-pct`
reads the y co-ordinate.

