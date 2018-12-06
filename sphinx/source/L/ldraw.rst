..  _ldraw:

LDRAW
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LDRAW x1,y1 TO x2,y2, col                                        |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

This command is similar to DRAW, ie. it draws quite a thick line on the
screen, but LDRAW is part of the same Toolkit as SET
and uses a different col parameter to DRAW, see SET for that.

**Example**

Well, the sample listing which follows on below, is a bit too long for a
simple demonstration of LDRAW.

The variable rstep% in line 110 determines via pics% how much
memory is required to run the animation.

Unless you have SMS or Minerva, you will have to replace i% and j% by i and j.

::

    100 WINDOW 512,64,0,0: PAPER 0: INK 3: CLS
    110 rstep% = 20
    120 pics% = 360 / rstep%: DIM adr(pics%): i% = 0
    130 FOR r = 0 TO 360-rstep% STEP rstep%
    140   i%=i%+1: CLS: AT 0,0: PRINT "(";i%;")";TO 6;r;"ø"
    150   PYRAMID 20, 256, 32, r, r, r, 3
    160   adr(i%) = ALCHP(HEX("2000"))
    170   IF NOT adr(i%) THEN CLCHP: STOP: REMark memory overflow
    180   MM_MOVE HEX("20000"), adr(i%), HEX("2000")
    190 END FOR r
    200 REPeat Animation
    210   FOR i% = 1 TO pics%
    220     MM_MOVE adr(i%), HEX("20000"), HEX("2000")
    230     IF KEYROW(1)&&8 THEN EXIT Animation
    240   END FOR i%
    250 END REPeat Animation
    260 CLCHP: STOP
    270 :
    290 DEFine PROCedure PYRAMID (size, px%,py%, rotx,roty,rotz, c%)
    300   LOCal i%, j%, p1(2), p2(2)
    310   RESTORE 410
    320   FOR i% = 1 TO 8
    330     READ p1(0),p1(1),p1(2), p2(0),p2(1),p2(2)
    340     ROTATION p1(0),p1(1),p1(2), rotx, roty, rotz
    350     ROTATION p2(0),p2(1),p2(2), rotx, roty, rotz
    360     FOR j%=0 TO 2: p1(j%)=size*p1(j%): p2(j%)=size*p2(j%)
    370     LDRAW px%+p1(0),py%+p1(1) TO px%+p2(0),py%+p2(1), c%
    380   END FOR i%
    390   RETurn
    400 :
    410   REMark base square
    420   DATA -1, -1, 0, 1,-1, 0
    430   DATA 1, -1, 0, 1, 1, 0
    440   DATA 1, 1, 0, -1, 1, 0
    450   DATA -1, 1, 0, -1,-1, 0
    460   REMark top
    470   DATA -1, -1, 0, 0, 0, 2
    480   DATA 1, -1, 0, 0, 0, 2
    490   DATA 1, 1, 0, 0, 0, 2
    500   DATA -1, 1, 0, 0, 0, 2
    510 END DEFine PYRAMID
    520 :
    530 :
    540 DEFine PROCedure ROTATION (x, y, z, wx, wy, wz)
    550   REMark rotate point (x,y,z) by angles wx, wy and wz
    560   REMark in degrees around point (0,0,0)
    570   LOCal x1, y1, x2, z2
    580   LOCal cx, cy, cz, sx, sy, sz
    590   cx = COS(RAD(wx)): cy = COS(RAD(wy)): cz = COS(RAD(wz))
    600   sx = SIN(RAD(wx)): sy = SIN(RAD(wy)): sz = SIN(RAD(wz))
    610   x1 = x * cz -y * sz
    620   y1 = x * sz + y * cz
    630   x = x1 * cy - z * sy
    640   z2 = x1 * sy + z * cy
    650   y = y1 * cx + z2 * sx
    660   z = -y1 * sx + z2 * cx
    670 END DEFine ROTATION
    680 :
    700 DEFine PROCedure MM_MOVE (addr1, addr2, bytes)
    710   REMark move memory
    720   LOCal routine
    730   IF VER$ = "JSL1" THEN
    740     routine = PEEK_W(344) + 16384
    750     CALL routine, bytes, 2, 3, 4, 5, 6, 7, addr2, addr1
    760   ELSE
    770     REMark with HCO:
    780     BMOVE addr1, addr1+bytes TO addr2
    790   END IF
    800 END DEFine MM_MOVE

**NOTE 1**

LDRAW assumes that the screen is in a resolution of 512x256 pixels and
is located at $20000.

**NOTE 2**

LDRAW only works correctly in MODE 4.

**WARNINGS**

See SET.

**CROSS-REFERENCE**

:ref:`draw`. Please use
:ref:`ldraw` only if you know what you are doing, do
not intend to write user-friendly programs, and especially if you do not
intend to show your program listing to someone else! You can always use
:ref:`line` and :ref:`line-r`,
commands, :ref:`dotlin` and
:ref:`xdraw`, which can draw dotted lines
(:ref:`dotlin`) or work in
:ref:`xor` mode (:ref:`xdraw`).

