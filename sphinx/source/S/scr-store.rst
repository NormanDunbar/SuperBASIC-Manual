..  _scr-store:

SCR\_STORE
==========

+----------+------------------------------------------------------------------+
| Syntax   | SCR\_STORE [#channel,] address  or                               |
|          |                                                                  |
|          | SCR\_STORE width,height,x,y TO address                           |
+----------+------------------------------------------------------------------+
| Location | SuperWindow Toolkit                                              |
+----------+------------------------------------------------------------------+

This command allows you to store a part of the screen at the given
address in RAM. The section of the screen to be stored can be either a
window channel number (default #1) or the dimensions of a rectangle. The
amount of memory SCR\_STORE needs is returned by SCR\_SIZE. SCR\_STORE
needs eight bytes plus the actual amount of space taken up by the
section of the screen. These four words (one word consists of two bytes)
are kept at the start of the storage area and contain the size and
position of the screen part as passed by the second syntax above. They
can easily be read like this: width = PEEK\_W (adress) height = PEEK\_W
(adress+2) x = PEEK\_W (adress+4) y = PEEK\_W (adress+6)

**Example**

The SCR\_STORE and SCR\_REFRESH commands are ideal tools to create and
show animations. The actual speed of SCR\_REFRESH is independent from
the contents of the screen, so it does not matter how long it took to
create the pictures... Enjoy it.

::

    100 wx=70: wy=70: px=100: py=100
    110 OPEN#3,"scr_" & wx & "x" & wy & "a" & px & "x" & py: CLS#3
    120 size=SCR_SIZE(wx, wy): DIM adr(20)
    130 bx=2: by=2: pmax=10
    140 :
    150 FOR p=1 TO pmax
    160   adr(p)=ALCHP(size)
    170   FOR x=0 TO wx-bx STEP bx
    180     a=2*SQRT(p)*x/wx-SQRT(p)
    190     FOR y=0 TO wy-by STEP by
    200       b=2*SQRT(p)*y/wy-SQRT(p)
    210       z=((a*a+b*b)^^(a*b-b*b)) MOD 7
    220       BLOCK#3,bx,by,x,y,z
    230     END FOR y
    240   END FOR x
    250 SCR_STORE wx,wy,px,py TO adr(p)
    260 END FOR p
    270 :
    280 REPeat Animation
    290   FOR p=1 TO pmax: SCR_REFRESH adr(p)
    300   FOR p=pmax-1 TO 2 STEP -1: SCR_REFRESH adr(p)
    310   IF KEYROW(1)=8 THEN EXIT Animation
    320 END REPeat Animation
    330 CLCHP

**CROSS-REFERENCE**

See :ref:`scr-refresh` and
:ref:`scr-size`. See also
:ref:`w-store` and
:ref:`w-crunch`. Use
:ref:`alchp` to set aside some memory to hold the
copy of the window. Use :ref:`rechp` to remove that
memory definition.

