..  _mks-dlr:

MKS$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MKS$ (string$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns a string containing the internal format of a
string {which is stored as two bytes indicating the length of the string
(as returned by MKI$) and the string itself}.

**Example**
::

    MKS$("Test") = CHR$(0)&CHR$(4) & "Test"

because::

    MKI$ (4)

returns the string CHR$(0)&CHR$(4).

**CROSS-REFERENCE**

:ref:`cvs-dlr`, :ref:`mki-dlr`,
:ref:`mkf-dlr`, :ref:`mkl-dlr`

--------------


