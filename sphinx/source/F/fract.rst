..  _fract:

FRACT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FRACT (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  FRACT                                                            |
+----------+-------------------------------------------------------------------+

The function FRACT separates the fractional part of any floating
point number x. It could easily be rewritten in SuperBASIC as the
following::

    100 DEFine FuNction MYFRACT (x)
    110   RETurn x - INT(x) - (x < 0)
    120 END DEFine MYFRACT

**CROSS-REFERENCE**

:ref:`trint` is complementary to
:ref:`fract`.

