..  _quit:

QUIT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  QUIT  [return code]                                              |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This command is used to force remove a Multiple SBASIC Interpreter or a
compiled Job (in the latter case it is the same as STOP).

An optional error code may be supplied to pass back to the calling job. This is only effective if the calling job is waiting for this one - ie, started with :ref:`exec-w`, :ref:`few` etc, otherwise the returned error code is ignored.

**NOTE**

If this command is used from SuperBASIC Job 0, it will return an
'Incomplete' error.

**CROSS-REFERENCE**

See :ref:`mb`, :ref:`few` and :ref:`sbasic`.
:ref:`close` #0 has the same effect from within
a Multiple SBASIC or MultiBASIC Interpreter

