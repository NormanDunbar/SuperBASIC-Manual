..  _wset:

WSET
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WSET type [,mode]                                                |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

This command resets the windows #0, #1, and #2 to a pre-defined size
and position. There are a set of eight definitions built into the
Emulator, which can be chosen by setting type to a value in the range
0...7.

::

    WSET -1

will reset the three windows to the size and positions
specified with the WSET\_DEF command. If the optional parameter mode is
supplied, this will alter the display mode to that specified, otherwise,
the screen mode remains unchanged.

**CROSS-REFERENCE**

:ref:`wmon` and :ref:`wtv` are
similar commands under Toolkit II. Normally, you would use
:ref:`mode` to alter the screen mode only. See also
:ref:`wset-def`.

--------------


