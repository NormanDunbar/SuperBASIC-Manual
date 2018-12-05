..  _va:

VA
==

+----------+-------------------------------------------------------------------+
| Syntax   |  VA (i,n)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function VA returns the value of (1+i)\ :sup:`-n` = 1/MT(i,n) where i
and n can be any floating point numbers (see MT for error handling).

**Example**

VA allows you to find out about base capital which will grow to a
certain higher (i>0) capital at the interest rate i
over n periods. Assume that you want to buy an expensive car for $80000
in two years and your investment returns an annual gain of 10% (not
bad), then you need to invest 80000 \* VA(1/10, 2) = 66115.7

**CROSS-REFERENCE**

You can check the result of the above example with: 66115.7 \* :ref:`mt`\ (1/10,2) = 80000.

See also :ref:`vfr`, :ref:`var`,
:ref:`tca`, :ref:`tnc`,
:ref:`tee`, :ref:`rae`,
:ref:`rafe`.

--------------


