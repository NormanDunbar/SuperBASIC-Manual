..  _screen:

SCREEN
======

+----------+------------------------------------------------------------------+
| Syntax   | SCREEN  or                                                       |
|          |                                                                  |
|          | SCREEN [(#ch)] (FN Toolkit only)                                 |
+----------+------------------------------------------------------------------+
| Location | Beuletools, Fn                                                   |
+----------+------------------------------------------------------------------+

The visible screen on a standard QL is actually 32K of memory. The
start address of the screen is normally 131072, but can change on
Minerva and higher resolution implementations of the QL, so the start
address should be determined before accessing the screen directly. The
function SCREEN returns that start address.

**NOTE**

The FN Toolkit version allows you to specify a channel - if the channel
is specified, then the start address for the screen on which that
channel is open is returned. This is mainly only of use to Minerva and
Amiga QDOS users who can have windows open on either the Default Screen
or the Other Screen (provided their dual screen mode is active). Thus
SCREEN(#3) can be used to find the start address of the second screen if
that is where #3 is located.

**CROSS-REFERENCE**

See :ref:`scr-base`.

--------------



