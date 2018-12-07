..  _wipe:

WIPE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WIPE                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools, WIPE                                                 |
+----------+-------------------------------------------------------------------+

This command clears the whole screen so that it is completely black.

WIPE is an alternative to::

    OPEN#11,scr_512x256a0x0:
    CLS#11:
    CLOSE#11

or::

    SCRBASE SCREEN: SCLR 0

**NOTE**

This command presumes that the screen starts at 131072 and measures
512x256 - it will therefore not work on higher resolutions.

**CROSS-REFERENCE**

:ref:`cls` clears a window in its current paper
colour, :ref:`sclr` the (background) screen in a
given colour. :ref:`cls-a` is a global
:ref:`cls`.

