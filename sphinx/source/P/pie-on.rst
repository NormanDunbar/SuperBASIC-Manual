..  _pie-on:

PIE\_ON
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PIE\_ON                                                          |
+----------+-------------------------------------------------------------------+
| Location |  PIE                                                              |
+----------+-------------------------------------------------------------------+

The Window Manager forms part of the Pointer Environment and is a
standard system extension. It allows you to multitask all kinds of
programs easily, provides non-destructible windows and more.

One of the
main problems with current versions of the Window Manager is that if any
part of the windows owned by a given Job is buried under another Job's
windows (ie. you cannot see that part of the window on-screen because of
another program), then if that buried Job tries to access the screen
(with PRINT for example), the Window Manager will pause that Job until
its window is no longer buried.

The Pointer Interface Extension (PIE)
modifies the Pointer Environment so that a program is not halted when it
tries to send screen output while its window is fully or partially
buried by another job.

It does this by storing the changes to the buried
window in memory and then when the buried Job is brought to the top of
the pile (see PICK%), then its window is updated.

PIE\_ON enables PIE,
PIE\_OFF disables it. These commands on their own cannot lead to any
problems, you can switch PIE on and off whenever you like.

**CROSS-REFERENCE**

:ref:`pie-ex-on` and
:ref:`pie-ex-off`. See also
:ref:`peon` and :ref:`pxon` which
greatly enhance these facilities. :ref:`pend` can be
used to check if a Job can send output to the screen.

--------------


