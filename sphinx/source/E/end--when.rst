..  _end--when:

END WHEN
========

+----------+-------------------------------------------------------------------+
| Syntax   |  END WHEN                                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM)                                                 |
+----------+-------------------------------------------------------------------+

This marks the end of the SuperBASIC structures: WHEN ERRor and WHEN condition ...
END WHEN, and has no meaning on its own. When the program is first run, the
interpreter marks the start of this structure and then (unless it is an in-line
structure) looks for the end of the block marked with END WHEN.

This means that if this statement is missing, except under SMS, the interpreter
will carry on searching through the program and may just stop without an error
if END WHEN does not appear anywhere in the program.

**NOTE**

END WHEN need not appear in a single line WHEN or WHEN ERRor statement, eg::

    100 WHEN a>4:PRINT 'a>4'.

**SMS NOTES**

Checks are made on a program before it is run, and so if an END WHEN
statement is missing, this will be reported as an error.

SMS's improved
interpreter will also report the error 'Misplaced END WHEN' if END WHEN
does not mark the end of a WHEN ERROR definition block.

**CROSS-REFERENCE**

Please see :ref:`when--error` and :ref:`when--condition`. Other SuperBASIC
structures are :ref:`define--procedure`,
:ref:`define--function`,
:ref:`if`, :ref:`repeat`,
:ref:`select` and :ref:`for`.

