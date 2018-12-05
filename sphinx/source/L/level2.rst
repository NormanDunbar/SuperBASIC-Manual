..  _level2:

LEVEL2
======

+----------+-------------------------------------------------------------------+
| Syntax   | present = LEVEL2(#channel)                                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

If the device that has the given channel opened to it has the level 2 drivers, then present will be set to 1, otherwise it will be set to 0.  The level 2 drivers allow such things as sub_directories to be used, when a :ref:`dir` is done on one of these devices, sub-directories show up as a filename with '->' at the end of the name. Gold Cards and later models of Trump cards have level 2 drivers. Microdrives don't.

**EXAMPLE**

::

    2500 DEFine PROCedure MAKE_DIRECTORY
    2510   LOCal d$, t$, l2_ok, ch
    2520   INPUT 'Enter drive names :';d$
    2530   IF d$(LEN(d$)) <> '_' THEN d$ = d$ & '_': END IF
    2540   PRINT 'Please wait, checking ...'
    2550   ch = DJ_OPEN_OVER (d$ & CHR$(0) & CHR$(0))
    2560   IF ch < 0: PRINT 'Cannot open file on ' & d$ & ', error: ' & ch: RETurn
    2570   l2_ok = LEVEL2(#ch)
    2580   CLOSE #ch
    2590   DELETE d$ & CHR$(0) & CHR$(0)
    2600   IF l2_ok
    2610     INPUT 'Enter directory name please : ';t$
    2620     MAKE_DIR d$ & t$
    2630   ELSE
    2640     PRINT 'Sorry, no level 2 drivers!'
    2650   END IF
    2660 END DEFine MAKE_DIRECTORY


-------



