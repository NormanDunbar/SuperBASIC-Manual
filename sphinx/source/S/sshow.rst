..  _sshow:

SSHOW
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  SSHOW adr                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Ecran Manager                                                    |
+----------+-------------------------------------------------------------------+

This command restores a screen part saved with SSAVE, therefore the
parameter adr must be the value returned by the SSAVE function. The
memory area where the picture is saved is unaffected, so SSHOW can be
executed any number of times.

**NOTE**

See SSAVE.

**CROSS-REFERENCE**

:ref:`sload` displays a saved screen part and frees
the memory used, :ref:`smove` allows you to view
such a saved screen part at a different location or on a different
screen.

--------------


