..  _wmon:

WMON
====

+----------+------------------------------------------------------------------+
| Syntax   | WMON [mode] or                                                   |
+----------+------------------------------------------------------------------+
| Syntax   | WMON [mode] [, xoff] [, yoff](SMS Only)                          |
+----------+------------------------------------------------------------------+
| Location | THOR 8, THOR XVI, Toolkit II                                     |
+----------+------------------------------------------------------------------+

When the QL is first started up in Monitor mode, the windows #0, #1 and
#2 are opened in the following sizes and positions, with the following
borders:-

- #0 is con\_512x50a0x206 (no border)
- #1 is con\_256x202a256x0 (BORDER #1,1,7,0)
- #2 is con\_256x202a0x0 (BORDER #2,1,7,0)

As with WTV, this
command resets the three default windows to the above sizes, positions
and borders. If one parameter is passed, this will alter the screen
MODE.

The second variant allows you to move the SuperBASIC windows, by
specifying an offset which will be used to calculate the top left hand
position of the windows. If only one parameter (other than the MODE) is
specified, then this will be taken to be both the x and y offset,
otherwise you can specify both. This will only work on higher resolution
displays. Also, if the second variant is used, if an outline has
previously been defined (for example with OUTLN), then the contents of
the three windows will be retained and moved to the new position - this
is equivalent to following the WMON
command with an OUTLN command with the details of the new position and
size.

**Example**

::

    WMON 4

Will reset standard windows and set MODE 4.

::

    WMON , 50

Resets the standard windows, in current MODE. The windows are set as follows:

- #0 is con\_512x50a50x256(BORDER #0,1,7,0)
- #1 is con\_256x202a306x50(BORDER #1,1,7,0)
- #2 is con\_256x202a50x50(BORDER #2,1,7,0)


::

    WMON 4,50,50

Is the same except it forces MODE 4.

**NOTE 1**

WMON does not reset the PAPER and INK colours of the three windows.

**NOTE 2**

On some versions of Minerva (pre v1.78) and Toolkit II, if you do not
specify the mode, this command will have no effect.

**NOTE 3**

On versions of the THOR 8 (pre v4.01) #0 appeared one pixel too far up
the screen following WMON.

**NOTE 4**

On SMS prior to v2.53 WMON would set an OUTLN if one had not already
been set.

**SMS NOTE**

As well as adding the second variant, SMS adds a border to #0 (see
example above). v2.67+ has also fixed various problems with this
command.

**CROSS-REFERENCE**

Also see :ref:`wtv`, :ref:`wm`,
:ref:`wset`, :ref:`wmov` and
:ref:`mode`.

--------------


