..  _smove:

SMOVE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  SMOVE scrno, adr [,xpos, ypos]                                   |
+----------+-------------------------------------------------------------------+
| Location |  Ecran Manager                                                    |
+----------+-------------------------------------------------------------------+

The command SMOVE will copy a stored screen (saved with SSAVE, where adr
comes from) to the first (scrno=0) or second screen (scrno=1) - the
latter is only possible if your system supports a dual screen mode.

Optionally, it is possible to specify a location where the screen part's
upper left corner (absolute co-ordinates) should be placed; SMOVE will
correct the xpos and ypos automatically if the restored picture would
exceed the screen borders.

**NOTE**

See SSAVE.

**CROSS-REFERENCE**

:ref:`sshow`, :ref:`sload`

