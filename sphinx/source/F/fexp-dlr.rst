..  _fexp-dlr:

FEXP$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FEXP$ (value,length,ndp)                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function is different to CDEC$ in that it always prints the
given value in exponential format. This means that there is always only
one character to the left of the decimal point (plus any sign), and ndp
(number of decimal places) states how many characters should be to the right
of the decimal point.

FEXP$ does not assume that value is an integer and therefore also caters
for floating point values. The length of the field must be at least
ndp+7, otherwise an empty string is returned.

If necessary, values are
rounded up or down to fit in the specified ndp number of decimal places.

**Examples**

::

    PRINT FEXP$(-100.235,11,4)

will print -1.0023E+02

::

    PRINT FEXP$$(100.235,11,4)

will print 1.0024E+02

**CROSS-REFERENCE**

:ref:`cdec-dlr`, :ref:`idec-dlr`,
:ref:`fdec-dlr` and
:ref:`print-using` all provide means of
formatting number output.

