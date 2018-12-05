..  _fastexpand:

FASTEXPAND
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FASTEXPAND adr1,adr2                                             |
+----------+-------------------------------------------------------------------+
| Location |  COMPICT                                                          |
+----------+-------------------------------------------------------------------+

If a screen which has been compressed and saved with COMPRESS is
loaded into memory with LBYTES (for example), this command allows
quicker expansion of the screen than would otherwise be possible with
EXPAND.

FASTEXPAND also allows you to expand the screen to any address
(provided that there is at least 32K of free memory stored there). adr1
is the address where the compressed screen is stored and adr2 the place
in RAM where the expanded screen should be moved to.

**Example**

::

    100 COMPRESS ram1_test_scr
    110 a=ALCHP(FLEN(\ram1_test_scr))
    120 LBYTES ram1_test_scr,a
    130 FASTEXPAND a,SCREEN
    140 RECHP a

**NOTE**

FASTEXPAND will not work on screen resolutions in excess of 512x256
pixels.

**CROSS-REFERENCE**

:ref:`compress`,
:ref:`expand`.

--------------


