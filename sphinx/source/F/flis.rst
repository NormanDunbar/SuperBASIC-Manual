..  _flis:

FLIS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FLIS (procfn$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Tiny Toolkit                                                     |
+----------+-------------------------------------------------------------------+

If procfn$ is the name of a SuperBASIC PROCedure or FuNction then
FLIS will return the line number where the PROCedure or FuNction is
defined.

If however, it is a machine code keyword (eg. "FILL$") then the
function FLIS will return 0.

If the name is not recognised the error 'Not Found' is reported.

**CROSS-REFERENCE**

:ref:`key-add`, :ref:`elis`,
:ref:`new-name` Also see
:ref:`find`.

