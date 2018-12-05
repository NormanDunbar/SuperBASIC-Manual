..  _sclr:

SCLR
====

+----------+-------------------------------------------------------------------+
| Syntax   |  SCLR colour                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

This command causes the screen (pointed to by SCRBASE) to be cleared
with the given colour. This colour ranges from 0 (black) to 7 (white).
There is no default.

**Example**

Run this small program and watch how your screen seems to change size.
The greater the difference in apparent size, the worse your monitor
(there are more intelligent criteria as to the capability of your
monitor, for example radiance)::

    100 MODE 4:SCRBASE
    110 REPeat screen_test
    120   FOR n=0,2,4,6: SCLR n
    130 END REPeat screen_test

**NOTE**

See REFRESH !

**WARNING**

Never use SCLR without a parameter! The system will crash!

**CROSS-REFERENCE**

:ref:`plot`, :ref:`draw`,
:ref:`refresh` and
:ref:`scrbase` are the other commands connected
with this one.

--------------


