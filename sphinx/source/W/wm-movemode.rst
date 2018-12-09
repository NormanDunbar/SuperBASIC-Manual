..  _wm-movemode:

WM\_MOVEMODE
============

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_MOVEMODE mode                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.01                                                  |
+----------+-------------------------------------------------------------------+

Sets the mode in which windows are moved.

Modern window managers allow moving a window about the screen in various ways:

0 - the "classic" way - the pointer changes to the "move window" sprite which
is moved about the screen.

1 - "Outline": click on the move icon with the MOUSE - keep holding the button
down -, an outline of the window will appear which you can move around and
position where you want it. Release the mouse button and the window positions
itself correctly.

2 - "Full window". This is the same as 1 above, but instead of an outline, the
entire window contents will be displayed during the movement. For Q40/Q60 users,
switching on the Cache is advisable...

3 - "Full window with transparency" (implemented in SMSQ/E v. 3.16). This is the
same as 2 above, but the window to be moved is made "transparent" : one can
"see through" it.  This is done via "alpha blending". Alpha blending requires
a lot of computing power. So, even if your machine can theoretically handle this
type of move, in practice it might not be feasible. For Q40/Q60 users, switching
on the Cache is advisable.

**Example**

::

    WM_MOVEMODE 0

Sets the window move mode to "classic", i.e. moving with the move icon.

**NOTE 1**
In any but move mode 0 windows cannot be moved by the keyboard and strictly
require a mouse. When moving windows with the keyboard, the move falls back
to the "classic" icon move for this operation.

**NOTE 2**
"Move with transparency" (mode 3) is only implemented for display modes where
alpha blending actually makes sense, i.e. modes 16, 32 and 33. In other display
modes, such as the QL screen modes, or Atari mono modes, this will be redirected
to move mode 2.

**NOTE 3**
The move modes are configured on a system-wide basis - you cannot have one job
moving in mode 0 and the other in mode 1.

**NOTE 4**
The window move mode can be configured in the operating system config blocks.

