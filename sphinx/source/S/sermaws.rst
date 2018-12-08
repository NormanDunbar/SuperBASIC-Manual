..  _sermaws:

SERMAWS
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  SERMAWS acc%, wup%                                               |
+----------+-------------------------------------------------------------------+
| Location |  SERMouse                                                         |
+----------+-------------------------------------------------------------------+

This command is used to set two parameters which control the effect
that moving the serial mouse has on the on-screen pointer under the
Pointer Environment. The first parameter sets the speed at which the
pointer will accelerate across the screen (this can be any value in the
range 0...9). A standard value is 6. The second parameter sets the
initial speed of the pointer. A standard value is 3. The values can also
be set by configuring the SERMouse file.

**CROSS-REFERENCE**

:ref:`sermptr` makes the mouse driver affect the
Pointer only. Qpac 2 allows you to set the same parameters from the
Sysdef menu. Also refer to\ :ref:`sermspeed` and
:ref:`sermon`. See the appendix on Mouse Drivers
for more information.

