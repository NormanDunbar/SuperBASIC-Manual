..  _artanh:

ARTANH
======

+----------+-------------------------------------------------------------------+
| Syntax   |  ARTANH (x)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Hyper                                                            |
+----------+-------------------------------------------------------------------+

The function ARTANH returns the value which must be passed to TANH to
give the specified result, so:

TANH ( ARTANH ( x )) = ARTANH ( TANH ( x )) = x

ARTANH(x) could be replaced by: LN((1+x) / (1-x)) / 2

**CROSS-REFERENCE**

See :ref:`atan`, :ref:`arcoth`,
and :ref:`arsinh`.

