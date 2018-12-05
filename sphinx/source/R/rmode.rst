..  _rmode:

RMODE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  RMODE [(screen)]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

The function RMODE returns the current screen mode (of the screen
belonging to the job which executes RMODE if the Window Manager is
present).

If Minerva or Amiga QDOS v3.23 is present and is in dual
screen mode, then PRINT RMODE(1) will show the current screen mode for
the Other Screen (see MODE). If Minerva and Amiga QDOS is not present,
(or dual screen mode is not active), then RMODE(1) will return -19 (for
'Not Implemented'). Both RMODE and RMODE(0) return the mode of the
Default Screen on all ROMs:

+-------+----------------+---------+
| RMODE | Min Resolution | Colours |
+=======+================+=========+
| 2     | 640 x 400      |  2      |
+-------+----------------+---------+
| 4     | 512 x 256      |  4      |
+-------+----------------+---------+
| 8     | 256 x 256      |  8      |
+-------+----------------+---------+
| 12    | 256 x 256      | 16      |
+-------+----------------+---------+

**Example**

If a program is written to operate in one of these modes, it has to
change to that mode at the very beginning. A simple MODE 4 will do, if
high resolution is needed. But the MODE is executed even if the screen
was already in the correct mode. It looks better if MODE is only done if
the mode really has to be changed. CHANGE\_MODE should be used instead
of MODE::

    100 DEFine PROCedure CHANGE_MODE (mode%)
    110   IF RMODE(0)<> mode%
    120     MODE mode%
    130   END IF
    140 END DEFine CHANGE_MODE

**CROSS-REFERENCE**

:ref:`mode` sets the mode.
:ref:`qflim` returns the screen resolution.
:ref:`ttmode-pct` is similar.

--------------


