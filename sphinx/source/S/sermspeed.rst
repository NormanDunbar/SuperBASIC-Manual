..  _sermspeed:

SERMSPEED
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SERMSPEED mul%, div%, acc% [,cursormul%, cursordiv%]             |
+----------+-------------------------------------------------------------------+
| Location |  SERMouse                                                         |
+----------+-------------------------------------------------------------------+

This command allows you to set various parameters to dictate the speed
and resolution of the mouse. As a mouse moves, it sends a stream of data
to the computer containing details of the direction moved and the
distance moved. These details are sent every few microseconds and
converted by the driver to x,y coordinates on screen. The speed at which
these details are sent is known as the resolution of the mouse.

This command allows you to alter the resolution of the mouse so that you do
not have to move the mouse as far to get the pointer (or cursor) on
screen to move across the whole screen.

The mul% and div% parameters can be in the range 0..127 (with 0 disabling this feature - the default).

The distance sent by the mouse is multiplied by the mul% factor and
divided by the div% factor - with these both set to 0, only two-thirds
of the distance moved by the mouse is passed to the Pointer Interface to
be translated into movements of the Pointer.

The acc% parameter can be
in the range (0...8) and defaults to 4 - this is used to calculate an
acceleration factor, so that the faster that the mouse is moved the
quicker the details sent by the mouse are passed on to the Pointer
Interface (thus making the Pointer move in bigger and bigger steps).

The
last two parameters are optional and are only relevant when the Mouse
Driver is used in Cursor Mode (see SERMCUR). These two parameters affect
the resolution of the mouse when being used to move the Basic Cursor -
the standard values are both 1.

**CROSS-REFERENCE**

:ref:`sermaws` works in conjunction with this
command. All of these parameters can be configured in the SERMouse file.
See also :ref:`sermcur` and
:ref:`sermptr`.

--------------


