..  _minimum:

MINIMUM
=======

+----------+------------------------------------------------------------------+
| Syntax   | MINIMUM [ ( array ) ] or                                         |
|          |                                                                  |
|          | MINIMUM ( :sup:`\*`\ [ value ]\ :sup:`\*` )                      |
+----------+------------------------------------------------------------------+
| Location | Minmax (DIY Toolkit - Vol Z)                                     |
+----------+------------------------------------------------------------------+

The effect of this function depends on the parameter supplied. It is
however an extremely fast way of comparing values.

If no parameter is
supplied, then the smallest possible floating point number supported by
the QL is returned - this is equivalent to -1e614.

If a single parameter
is supplied which is a single dimensional floating point array, then
MINIMUM will return the value of the smallest number stored within that
array. If you want to compare the values of an integer array, then use
MINIMUM% (a 'bad parameter' is generated with this function if you attempt to use it for integers).

If, however, you
use the second variant to pass a list of values (either numbers or
variables), then the smallest value out of those parameters will be
returned.

Please note that you cannot pass an array in this instance -
it is therefore the same as MIN.

**Example**

::

    DIM x(3): x(0)=10: x(1)=200: x(2)=2.5: x(3)=50.4
    PRINT MINIMUM (x)

Returns 2.5

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmin`,
:ref:`minimum-pct` and :ref:`min`
are similar. Refer also to :ref:`maximum` and
:ref:`maximum-pct`.

