..  _cvl:

CVL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CVL (mkl\_$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function converts the internal representation of a long integer
number (a four character long string) to the actual value and returns
that. CVL is the inverse of MKL$.

**Example**

CVL( MKL$( 10010 ) = "10010"

**CROSS-REFERENCE**

:ref:`mkl-dlr`, :ref:`cvi-pct`,
:ref:`cvf`, :ref:`cvs-dlr`.

:ref:`fputl` and :ref:`fgetl`
provide similar facilities to enable you to write and read long integers
from files in their internal format.

