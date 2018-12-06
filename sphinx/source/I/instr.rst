..  _instr:

INSTR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  str1$ INSTR str2$                                                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This operator searches str2$ for str1$ and if found, it will return the
position of the first character of str1$ in str2$. The search is not
normally case-sensitive. If str1$ cannot be found, the value 0 is
returned.

**Examples**

::

    s$='Hello World':PRINT 'world' INSTR s$

will print 7.

::

    PRINT 'worlds' INSTR s$

will print 0.

**NOTE**

If str1$ is a nul string, eg. str1$="", INSTR will always return the
value 1.

**SMS NOTE**

You can specify a case sensitive search using INSTR\_CASE.

**CROSS-REFERENCE**

See :ref:`instr-case`.
:ref:`inarray-pct` and
:ref:`search` can be used to compare entries within
arrays.

