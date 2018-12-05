..  _scr2dis:

SCR2DIS
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  SCR2DIS                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Super Gold Card                                                  |
+----------+-------------------------------------------------------------------+

Some programs make use of the QL's ability to support a second screen
(on a standard QL this is normally stored at $28000 (hex) - it
overwrites the system variables which are moved to another area in
memory). You can therefore see why it is important never to make
assumptions about the location of the screen or system variables in
memory (use SCREEN or SYS\_BASE instead).

Minerva extends this second
screen even further, allowing you to operate the computer in two-screen
mode, with programs being started up on one of two screens (thus
allowing you to have completely different displays on each screen) see
MODE. The main problem with this second screen is that it slows down the
operation of the computer and therefore if you do not intend to use the
second screen, you may wish to disable it.

You can disable the second
screen with the command SCR2DIS - this setting will be stored in memory
by the Gold Card and the second screen will henceforth always be
disabled.

**WARNING**

Some programs (mainly games) will not work properly with the second
screen disabled.

**CROSS-REFERENCE**

:ref:`scr2en` re-enables the second screen again.

--------------


