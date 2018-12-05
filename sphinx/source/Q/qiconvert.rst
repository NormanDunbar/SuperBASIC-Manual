..  _qiconvert:

QICONVERT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  QICONVERT filename                                               |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command takes a file which is stored on a QL Format disk and
converts it into IBM Format. It will then convert special characters in
that file to IBM compatible characters as well as converting any
occurrence of a Line Feed character CHR$(10) to a Carriage Return
character CHR$(13) followed by a Line Feed character CHR$(10).

**CROSS-REFERENCE**

Compare :ref:`iqconvert` and
:ref:`aqconvert`. See also
:ref:`acopy` and :ref:`qcopy`.
See :ref:`iformat`.

--------------


