..  _button-pct:

BUTTON%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  BUTTON% (flag)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I), Amiga QDOS v3.20+           |
+----------+-------------------------------------------------------------------+

This function can be used to find out if any mouse buttons have been
pressed and if so which ones. Unfortunately, you cannot use this to find
out if a button has been pressed twice quickly in succession (known as
double-clicking).

The value of flag is used to tell the function which buttons you wish to
interrogate:

-  0 - Has any key been pressed ? If so, the value returned will be 0
   plus the following numbers if the relevant key(s) has been pressed:

   -  +1 - Button One Pressed
   -  +2 - Button Two Pressed
   -  +4 - Button Three Pressed

-  1 - Has Button One been pressed (this is the left hand mouse button)?
   If so 1 is returned, otherwise 0.
-  2 - Has Button Two been pressed (this is the right hand mouse
   button)? If so, 1 is returned, otherwise 0.
-  3 - Has Button Three been pressed (this is the middle mouse button)?
   If so, 1 is returned, otherwise 0.


**Example**

A routine to wait for the user to press the right and left mouse button
at the same time:

::

    100 DEFine PROCedure WAIT_MOUSE
    110 REPeat mloop
    120   IF BUTTON%(0)=1+2:RETurn
    130 END REPeat mloop
    140 END DEFine


**CROSS-REFERENCE**

:ref:`x-ptr-pct`, :ref:`y-ptr-pct`
and :ref:`ptr-fn-pct` can also be used to
interrogate the mouse.

