..  _a-oldscr:

A\_OLDSCR
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  A\_OLDSCR                                                        |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v2.27+)                                             |
+----------+-------------------------------------------------------------------+

A lot of software (mainly non-pointer driver programs), and some of the
toolkits covered by this book, written for the Sinclair QL in the past
always assumed that the QL screen would appear at the memory location
131072 ($20000 in hexadecimal).

These programs and toolkits will not work properly (if at all) on the
QVME board or some higher resolution screens. One of the solutions to
this is to use the command A\_OLDSCR which forces ST/QL Emulators to set
up a Job copying the QL's screen as stored at 131072 (onwards) to the
real display screen 20 times a second. This obviously slows down the
operation of the computer and thus if possible, a new version of the
software should be produced / obtained.

As from v2.30, this command will not affect the display speed as much on
a machine fitted with a blitter chip.

**NOTE 1**

This command cannot fix the problem with programs and toolkits which
assume that the QL's display is 512x256 pixels.

**NOTE 2**

This command reports 'Not Implemented' on other ST-QL Emulators.

**NOTE 3**

SuperBasic (Job 0) must be the only Job running on the machine when this
command is issued, otherwise the error 'Not Complete' is reported.

**NOTE 4**

If you try to use this command after it has already been issued, the
errror 'Already Exists' is reported.

**CROSS-REFERENCE**

:ref:`screen` can be used to find the screen
address.

:ref:`scr-size` can be used to set the
resolution of the display - much software will insist that this is set
to 512x256 pixels also.

