..  _acos:

ACOS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  ACOS (x)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function ACOS, is the arc-cosine function, that is to say the
opposite to the cosine function (COS in SuperBASIC). However, x must
always be in the range -1...1 as the cosine of an angle can only ever be
in this range. Anything outside of this range will produce an Overflow
Error.

The angle returned will be in the range 0...PI with ACOS(1)=0 and
ACOS(-1)=PI. This means that the maximum angle which can be found with
the ACOS function is 180 degrees. It is up to you to check whether this
angle appears above or below the base line of the triangle (check the
co-ordinates of the corners).

Note that if a negative value of x is provided, the angle returned will
be the obtuse angle (ie. greater than 90 degrees).

**Example**

To calculate the angle at which a projectile was fired which has
travelled a horizontal distance of 250 metres after 10 minutes and is
travelling at 3 kilometres per hour (ignoring the effects of gravity):

::

    100 Speed=3:Distan=250/1000
    110 Time_elapsed=10
    120 Actual_distance=(Speed/60)*Time_elapsed
    130 PRINT 'Projectile fired at an angle of ';
    140 PRINT DEG(ACOS(Distan/Actual_distance))&' degrees'

**NOTE**

The angle returned will be in radians - if you wish to convert this
angle to degrees, use DEG ( ACOS (x) ).

**CROSS-REFERENCE**

:ref:`cos`, :ref:`asin`,
:ref:`sin`, :ref:`rad`.

Compare :ref:`arcosh`.

Also please see the Mathematics section in the Appendix.

