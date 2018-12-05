..  _scrbase:

SCRBASE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  SCRBASE [adress]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

All commands belonging to the fast graphics Toolkit use the specified
parameter set with this command as the base address for their
operations: SCLR, PLOT, DRAW and REFRESH. This is intended to allow
background drawing. The default address is the address of the visible
screen, SCREEN.

**Example 1**

A simple demonstration and an animated version::

    100 SCRBASE ALCHP(32768): SCLR 0
    110 FOR t=0 TO 2*PI STEP PI/32
    120   x1=188*SIN(t)+255: y1=127*COS(t)+127
    130   x2=188*SIN(t+PI)+255: y2=127*SIN(t+PI)+127
    140   DRAW x1,y1 TO x2,y2 ,7
    150 END FOR t
    160 REFRESH: CLCHP

::

    100 Pics=INT((FREE_MEM-4096)/32768)
    110 DIM base(Pics)
    120 FOR c=2*PI/Pics TO 2*PI STEP 2*PI/Pics
    130   base(c/2/PI*Pics)=ALCHP(32768)
    140   SCRBASE base(c/2/PI*Pics): SCLR 0
    150   FOR t=0 TO 2*PI STEP PI/4
    160     x1=188*SIN(t)+255: y1=127*COS(t)+127
    170     x2=188*SIN(t+c)+255: y2=127*SIN(t+c)+127
    180     DRAW x1,y1 TO x2,y2 ,7
    190   END FOR t
    200 END FOR c
    210 :
    220 REPeat Animation
    230 FOR c=1 TO Pics: SCRBASE base(c): REFRESH
    240   IF KEYROW(1)=8 THEN EXIT Animation
    250 END REPeat Animation
    260 CLCHP

**Example 2**

Varying the base address by steps equal to the value of SCRINC (normally
128) simulates vertical scrolling. The first program views memory, the
other one loads an uncompressed 32K screen and then 'scrolls it in'.

::

    100 FOR A=0 TO 786432 STEP 128
    110   SCRBASE A
    120   REFRESH
    130 END FOR A

The second program appears on the next page.

::

    100 SCRFILE$="MDV1_SCREEN_SCR"
    110 SCROLLSPEED=4 120 :
    130 ADR=ALCHP(65536)
    140 LBYTES SCRFILE$,ADR+32768
    150 POKE$ ADR,FILL$(CHR$(0),32767): POKE SCREEN+32766,0
    160 FOR A=ADR TO ADR+32768 STEP SCROLLSPEED*SCRINC
    170   SCRBASE A
    180   REFRESH
    190 END FOR A
    200 RECHP ADR

**CROSS-REFERENCE**

See :ref:`sclr`, :ref:`plot`,
:ref:`draw` and :ref:`refresh`
for fast background drawing. :ref:`scr-store`
and :ref:`scr-refresh` are ideal to create
and display animated displays. Compare
:ref:`scr-base`!

--------------


