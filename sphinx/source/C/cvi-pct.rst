..  _cvi-pct:

CVI%
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CVI% (mki\_$)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

CVI% is the inverse function of :ref:`mki-dlr` and expects a two character long
string, being the internal representation of an integer, and then
converts this into the actual integer number.

**Example**

MKI$( 20812 )="QL"

CVI%("QL")=20812

**CROSS-REFERENCE**

:ref:`mki-dlr`, :ref:`cvl`,
:ref:`cvf`, :ref:`cvs-dlr`.

:ref:`fget-pct` and :ref:`fput-pct`
provide similar facilities for writing and reading integers in their
internal format from files.

