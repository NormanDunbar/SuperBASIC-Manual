..  _disp-update:

DISP\_UPDATE
============

+----------+------------------+
| Syntax   | DISP\_UDPATE x,y |
+----------+------------------+
| Location | QXL (SMSQ only)  |
+----------+------------------+

This is an undocumented command and it is uncertain what its parameters do - it affects the rate at which the screen is updated on the QXL. The higher x and y, the faster that the screen is updated (and hence the smoother the graphics), although this also slows down the other parts of the QXL. If x and y are equal to 0, the screen is only updated when you press a key - this allows the QXL to perform complex maths routines very quickly (so long as they do not access the screen).

**NOTE 1**

Prior to SMSQ/E v2.65 if you used DISP\_UPDATE with a parameter larger
than 1 in MODE 8, this could cause problems on screen.


**NOTE 2**

Using parameters smaller than 0 could lock up some versions of QXL.
SCR\_PRIORITY is similar under Amiga QDOS.

