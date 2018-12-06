..  _ln:

LN
==

+----------+-------------------------------------------------------------------+
| Syntax   |  LN (x)                                                           |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the natural logarithm of the given value (in base
e), so that e\ :sup:`LN(x)`\ =x. Due to the nature of power numbers, the range of
x is 0>x<=2\ :sup:`2046`.

Logarithms were first invented to make multiplication
and division easier, because whatever base you are working in,
multiplication and division can be calculated by using logarithms. For
example, x\*y is the same as EXP(LN(x)+LN(y)), or
10\ :sup:`(LOG10(x)+LOG10(y))`\ ; and x/y is the same as EXP(LN(x)-LN(y)), and
10\ :sup:`(LOG10(x)-LOG10(y))`.

Another reason is that logarithms can make it
easier to calculate powers, for example, 10\ :sup:`(p\*LOG10(y))` gives the same
answer as y\ :sup:`p`, for any value of y or p.

Another use for logarithms is to
enable square roots to be calculated. On the assumption that
x\*x=10\ :sup:`(2\*LOG10(x))`, the square root of a number y can be calculated
using the formula: 10\ :sup:`(LOG10 (y) / 2)`.

Natural logarithms (base e) are
generally used in theoretical mathematics, as this can be useful in
differentiation, since if y=e\ :sup:`x`, dy<dx<y. Because negative values of x
cannot be handled by logarithms (in any base - this is because
x\ :sup:`y` must always be greater than zero!), you will need to check
for negative values and zero values separately.

**CROSS-REFERENCE**

:ref:`exp` converts natural logarithms to their true
numbers in base 10, :ref:`log10` provides logarithms
in base 10 (common logarithms), and :ref:`log2`
provides base 2 logarithms.

