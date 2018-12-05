..  _qflim:

QFLIM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QFLIM ([#channel,] n) n=0..3                                     |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

With the Pointer Interface present, each job has a maximum outline
window size in which it can open its windows to avoid storing more
information than necessary when switching between jobs and saving the
window contents. The function QFLIM returns the following information
about this maximum outline size, in the (window independent) absolute
co-ordinate system for the different n:

+---+------------------------------------------------------+
| N | Information Returned                                 |
+===+======================================================+
| 0 | Width in pixels (eg. 512 on a standard QL display).  |
+---+------------------------------------------------------+
| 1 | Height in pixels (eg. 256 on a standard QL display). |
+---+------------------------------------------------------+
| 2 | Leftmost horizontal position.                        |
+---+------------------------------------------------------+
| 3 | Uppermost vertical position.                         |
+---+------------------------------------------------------+

QFLIM needs an open window to get the
information from (default #1). The return values refer to the current
job. If any other values of n are used, a bad parameter error will be
generated.

**Example**

If there are no windows other than #0, #1 and #2, and their positions
are set up as follows::

    100 WINDOW #0,100,100,50,50
    110 WINDOW #1,20,20,0,0
    120 WINDOW #2,200,50,40,40
    130 FOR c=0 TO 2: PAPER #c,3: BORDER #c,1,4: CLS #c

The Pointer Interface will reduce the outline size of the screen
available to SuperBASIC, which can be checked with the next program or
by swapping to other jobs which fill the whole screen.

::

    100 ch=2
    110 xmin = QFLIM(#ch, 2): xmax = xmin + QFLIM(#ch,0)
    120 ymin = QFLIM(#ch, 3): ymax = ymin + QFLIM(#ch,1)
    130 PRINT "x = "; xmin; ".."; xmax
    140 PRINT "y = "; ymin; ".."; ymax
    150 percent% = 100 * QFLIM(#ch, 0) * QFLIM(#ch, 1) / (512 * 256)
    160 PRINT "fills"! percent%; "% of the screen"


Type WTV or WMON to restore standard window sizes. Note that this
example expects the display to be 512x256 pixels.

**NOTE 1**

The Pointer Interface makes a distinction between the primary window
(generally the first window to be used for input/output operations) and
secondary windows. Although using QFLIM on a secondary window will
return the maximum outlines for the current job's windows, using QFLIM
on the primary window (eg. #0 in SuperBASIC) will return the physical
screen size, ie. the parameters of the largest possible window::

    WINDOW QFLIM(#0, 0), QFLIM(#0, 1), QFLIM(#0, 2), QFLIM(#0, 3)

This can therefore be used to check whether or not the extra high
resolution modes provided by some Emulators and the AURORA is available::

    exten4 = 0
    IF QFLIM(#0,1) > 256: exten4 = 1

**NOTE 2**

QFLIM returns useless numbers greater than 10000 if the Pointer
Interface is not present.

**CROSS-REFERENCE**

:ref:`wman-dlr`, :ref:`winf-dlr` allow
you to find out various information about the Pointer Environment.
:ref:`xlim`, :ref:`scr-xlim`,
:ref:`ylim` and
:ref:`scr-ylim` are similar to
:ref:`qflim`. See also
:ref:`outln`.

--------------


