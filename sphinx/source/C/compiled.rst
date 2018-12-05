..  _compiled:

COMPILED
========

+----------+-------------------------------------------------------------------+
| Syntax   |  COMPILED                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function simply returns a value of 0 if the current program is
interpreted or 1 if it has been compiled.

**NOTE 1**

Although primarily for use with programs compiled with Turbo, versions
of this function after v3c27 will work even from within a program
compiled under QLiberator.

**NOTE 2**

Prior to v3c27, this function did not always return the correct value on
Minerva and SMS (particularly from within a MultiBASIC or SBASIC
daughter job).

**CROSS-REFERENCE**

See :ref:`job-name` for an example.

--------------


