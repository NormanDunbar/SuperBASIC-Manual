..  _ernum:

ERNUM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ERNUM                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM version)                                         |
+----------+-------------------------------------------------------------------+

This function returns the error number of the last error which occurred. An error
number is negative and can be returned by any program (SuperBASIC, jobs, M/C
Toolkits,...). The equivalent error messages are the same on all of the
implementations of SuperBASIC, although they are also supported in different
languages (see the Appendix for other languages):

+-------+------------------------+
| Error | English message        |
+=======+========================+
| -1    | Not Complete           |
+-------+------------------------+
| -2    | Invalid Job            |
+-------+------------------------+
| -3    | Out of Memory          |
+-------+------------------------+
| -4    | Out of Range           |
+-------+------------------------+
| -5    | Buffer Full            |
+-------+------------------------+
| -6    | Channel not Open       |
+-------+------------------------+
| -7    | Not Found              |
+-------+------------------------+
| -8    | Already Exists         |
+-------+------------------------+
| -9    | In Use                 |
+-------+------------------------+
| -10   | End of File            |
+-------+------------------------+
| -11   | Drive Full             |
+-------+------------------------+
| -12   | Bad Name               |
+-------+------------------------+
| -13   | Xmit Error             |
+-------+------------------------+
| -14   | Format Failed          |
+-------+------------------------+
| -15   | Bad Parameter          |
+-------+------------------------+
| -16   | Bad or Changed Medium  |
+-------+------------------------+
| -17   | Error in Expression    |
+-------+------------------------+
| -18   | Overflow               |
+-------+------------------------+
| -19   | Not Implemented Yet    |
+-------+------------------------+
| -20   | Read Only              |
+-------+------------------------+
| -21   | Bad Line               |
+-------+------------------------+


**NOTE**

Jobs may return a positive error number. The meaning of such a number
depends on the job. No error message will be reported.

**SMS NOTE**

The error messages have been redefined to try to make them more
intelligent, they are now:

+-------+------------------------+
| Error | English message        |
+=======+========================+
| -1    | Incomplete             |
+-------+------------------------+
| -2    | Invalid Job ID         |
+-------+------------------------+
| -3    | Insufficient memory    |
+-------+------------------------+
| -4    | Value out of range     |
+-------+------------------------+
| -5    | Buffer full            |
+-------+------------------------+
| -6    | Invalid channel ID     |
+-------+------------------------+
| -7    | Not found              |
+-------+------------------------+
| -8    | Already exists         |
+-------+------------------------+
| -9    | Is in use              |
+-------+------------------------+
| -10   | End of file            |
+-------+------------------------+
| -11   | Medium is full         |
+-------+------------------------+
| -12   | Invalid name           |
+-------+------------------------+
| -13   | Transmission error     |
+-------+------------------------+
| -14   | Format failed          |
+-------+------------------------+
| -15   | Invalid parameter      |
+-------+------------------------+
| -16   | Medium check failed    |
+-------+------------------------+
| -17   | Error in expression    |
+-------+------------------------+
| -18   | Arithmetic overflow    |
+-------+------------------------+
| -19   | Not implemented        |
+-------+------------------------+
| -20   | Write protected        |
+-------+------------------------+
| -21   | Invalid syntax         |
+-------+------------------------+
| -22   | Unknown message        |
+-------+------------------------+
| -23   | Access denied          |
+-------+------------------------+


Other errors are reported by the SBASIC
interpreter, but these are not covered by ERNUM.

**CROSS-REFERENCE**

:ref:`erlin` returns the line number where the error
occurred. :ref:`ernum-pct` is the same as this
function. :ref:`report` invokes an error message
and :ref:`when--error` can be used to trap
errors. The :ref:`err-...` functions are
alternatives to :ref:`ernum`.

--------------


