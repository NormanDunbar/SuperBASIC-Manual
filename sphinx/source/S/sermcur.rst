..  _sermcur:

SERMCUR
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  SERMCUR                                                          |
+----------+-------------------------------------------------------------------+
| Location |  SERMouse                                                         |
+----------+-------------------------------------------------------------------+

The SERMouse driver allows you to use a Mouse to control either the
Pointer (under the Pointer Environment) or the Basic cursor (used in
INPUT commands or similar). This command forces the mouse to control the
Basic cursor provided that the following condition is met: There is a
channel currently open which is awaiting for screen input with a visible
cursor. If you switch to a program which is reading the pointer (ie. a
program which uses the pointer interface) then the command SERMPTR is
automatically called.

**CROSS-REFERENCE**

:ref:`sermptr` switches to Pointer Mode. See also
:ref:`sermspeed`. You can also switch to cursor
mode by hitting the left hand mouse button twice in quick succession.

--------------


