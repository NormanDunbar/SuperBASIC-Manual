..  _len:

LEN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  LEN (string$)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The function LEN returns the number of characters contained in the
given string expression. However, due to the QL's native coercion
routines, the expression passed as a parameter need not be a string (!)

**Examples**

::

    x=100: PRINT LEN(x): REMark Returns 3.
    PRINT LEN ('A string'): REMark Returns 8.
    DIM x$(12): PRINT LEN (x$): REMark Returns 0, but add the following
    : x$='Hello': PRINT LEN(x$): REMark Returns 5, the same as PRINT x$(0)

**NOTE**

On pre-JS ROMs, if you use PRINT LEN(x$), an 'Out of Memory' error will
be reported if you have previously tried to make x$
longer than 32766 characters, for example with::

    x$=FILL$('x',32764)
    x$=x$&'xxx'
    PRINT LEN (x$)

**CROSS-REFERENCE**

:ref:`fill-dlr` returns a string of a specified length.
:ref:`dimn` returns important information about
arrays. See also the Compatibility Appendix for some important
information concerning string lengths.

