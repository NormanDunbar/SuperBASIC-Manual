..  _mt:

MT
==

+----------+-------------------------------------------------------------------+
| Syntax   |  MT (i,n)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function MT returns the value of (1+i)\ :sup:`n` where i and n can be
any floating point numbers. Instead of reporting an overflow error for
values which cannot be computed (eg. i=-1, n=-1) MT returns 1. If the
returned value would be too large, a modulated value is returned. It is
therefore imperative that the programmer takes care that the parameters
are correct, otherwise the return values may not make much sense.

**Example 1**

MT gives you a factor which indicates the increase (i>1) or decrease
(i<1) of capital at an interest rate i over a number of periods n. The
gain is known as compound interest. If you give any sum to a bank at an
interest rate of five percent (ie. annual 5 per 100 increase) for (say)
ten years, you will gain 62.9% because: MT(0.05, 10) = 1.628895

**Example 2**

::

    MT(1/n,n)

approximates EXP(1) for large values of n.

**CROSS-REFERENCE**

:ref:`va`, :ref:`vfr`,
:ref:`var`, :ref:`tca`,
:ref:`tnc`, :ref:`tee`,
:ref:`rae`, :ref:`rafe`

--------------


