..  _wtv:

WTV
===

+----------+------------------------------------------------------------------+
| Syntax   | WTV [mode] or                                                    |
+----------+------------------------------------------------------------------+
| Syntax   | WTV [mode] [, xoff] [, yoff](SMS Only)                           |
+----------+------------------------------------------------------------------+
| Location | THOR 8 (v4.20+), THOR XVI, Toolkit II                            |
+----------+------------------------------------------------------------------+

When the QL is first started up in TV mode, the windows #0, #1 and #2
are opened in the following sizes and positions, without any borders:-

- #0 is 448x40a32x216
- #1 is 448x200a32x16
- #2 is 448x200a32x16

Whilst testing
programs, it is all too easy for these three windows to be redefined
(especially #1 which is the default window). The command WTV allows you
to easily set those three windows to their default size and position as
well as taking an additional parameter for setting the mode in the same
way as the MODE command (default MODE 4).

Any border attached to each
window is switched off, except under SMS (see below). Also, if the
second variant is used, if an outline has previously been defined (for
example with OUTLN), then the contents of the three windows will be
retained and moved to the new position - this is equivalent to following
the WTV command with an OUTLN command with the details of the new position and
size.

**NOTE 1**

WTV does not reset the PAPER and INK colours of the three windows.

**NOTE 2**

On some versions of Minerva (pre v1.78) and Toolkit II, if you do not
specify the mode, this command will have no effect.

**NOTE 3**

On SMS prior to v2.53 WTV would create an OUTLN if one does not exist.

**SMS NOTE**

The SMS version of the command adds a border to #0, #1 and #2 (as with
WMON) and also allows you to reposition the main windows (see WMON).
v2.67+ also fixed several problems with this command.

**CROSS-REFERENCE**

Also see :ref:`wmon`.

--------------


