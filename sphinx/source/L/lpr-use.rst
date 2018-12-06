..  _lpr-use:

LPR\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  LPR\_USE device                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

LPR\_USE sets the default output device for LPRINT and LLIST. This can
be any valid QDOS device name, provided it is not longer than 24
characters. The definition can be found with LPRINT$, the default is
SER1 (ie. if LPR\_USE has not yet been used).

**Examples**

::

    LPR_USE par
    LPR_USE ram1_print_dat
    LPR_USE n2_ser1
    LPR_USE con

**NOTE**

LPR\_USE does not check the validity of the given device, so even
completely wrong parameters are accepted::

    LPR_USE #2

will set LPRINT$ to "2", LPRINT$ and LLIST will report the error.

**CROSS-REFERENCE**

LLIST, LPRINT$.

