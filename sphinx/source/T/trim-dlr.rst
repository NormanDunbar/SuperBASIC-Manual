..  _trim-dlr:

TRIM$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TRIM$ (string$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TRIM                                                             |
+----------+-------------------------------------------------------------------+

The function strips off all preceding and appended spaces from a string
and returns the result of this. Any string can be used as a parameter.

**Examples**

::

    TRIM$(" Hello World"): REMark = "Hello World"
    TRIM$("second try "): REMark = "second try"
    TRIM$(" "): REMark = ""
    TRIM$(""): REMark = ""
    TRIM$(CHR$(27)): REMark = CHR$(27)

**CROSS-REFERENCE**

:ref:`len` returns the length of a string.

