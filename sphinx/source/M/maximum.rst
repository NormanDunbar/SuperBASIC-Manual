..  _maximum:

MAXIMUM
=======

+----------+------------------------------------------------------------------+
| Syntax   | MAXIMUM [ ( array ) ] or                                         |
|          |                                                                  |
|          | MAXIMUM ( :sup:`\*`\ [ value ]\ :sup:`\*` )                      |
+----------+------------------------------------------------------------------+
| Location | Minmax (DIY Toolkit - Vol Z)                                     |
+----------+------------------------------------------------------------------+

The effect of this function depends on the parameter supplied. It is
however an extremely fast way of comparing values. If no parameter is
supplied, then the greatest possible floating point number supported by
the QL is returned - this is equivalent to 1.61585 e616.

If a single
parameter is supplied which is a single dimensional floating point
array, then MAXIMUM will return the value of the largest number stored
within that array.

If you want to compare the values of an integer
array, then use MAXIMUM% (a 'bad parameter' is generated with this (MAXIMUM)
function).

If, however, you use the second variant to pass a list of
values (either numbers or variables), then the highest value out of
those parameters will be returned. Please note that you cannot pass an
array in this instance - it is therefore the same as MAX.

**Example**

::

    PRINT MAXIMUM

Returns 1.61585e616

::

    DIM x(3): x(0)=10: x(1)=200: x(2)=2.5: x(3)=50.4
    PRINT MAXIMUM (x)

Returns 200.

::

    PRINT MAXIMUM (100, ax ,21*10+ac)

Returns the highest value.

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmax`,
:ref:`maximum-pct` and :ref:`max`
are similar. Refer also to :ref:`minimum` and
:ref:`minimum-pct`.

