..  _matrnd:

MATRND
======

+----------+------------------------------------------------------------------+
| Syntax   | MATRND array  or                                                 |
|          |                                                                  |
|          | MATRND array% [[ ,minval%] ,maxval%]                             |
+----------+------------------------------------------------------------------+
| Location | Math Package                                                     |
+----------+------------------------------------------------------------------+

This command initialises all of the elements of an integer or floating
point array with random numbers. Their default range depends on the type
of array: for integer arrays, the values range from -32768 to 32767,
whereas for floating point they range between 0 and 1.

MATRND selects
the range itself if there is just one parameter, but for integer arrays
only, an extended syntax allows you to specify another range (as in the
second variant).

If just a maximum value maxval% is specified then
values range from 0 to maxval%, if a minimum minval% is additionally
given then values range from minval% to maxval%.

MATRND will reject any
non-integer parameters for the second syntax.

**Examples**

::

    DIM array%(4,3,2), array(1,2): min%=10
    MATRND array
    MATRND array%
    MATRND array%,100
    MATRND array%,min%,100

**NOTE**

Like all other MAT... commands, MATRND cannot be compiled with
Supercharge or Turbo.

**WARNING**

MATRND allows a string array as a parameter. This leads to odd results
and can possibly hang the machine.

**CROSS-REFERENCE**

The random values chosen by :ref:`matrnd` can be
influenced by :ref:`randomise`.

