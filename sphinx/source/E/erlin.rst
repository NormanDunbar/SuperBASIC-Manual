..  _erlin:

ERLIN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ERLIN                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM version)                                         |
+----------+-------------------------------------------------------------------+

This function returns the line where the last error occurred.
If the error occurred in a line typed into the command window (#0), then zero is
returned (zero is also returned if there is no error).

**Example**

It takes a lot of time to debug programs, so save typing by including a
variation of the following line in your BOOT program. Then, if an error
occurs and the program stops with an error message, simply press
<ALT><E> to see and edit the line where something went wrong::

    ALTKEY "e","ED ERLIN-20"&CODE(216)&CODE(216),""

or::

    ALTKEY "e","AUTO ERLIN",""

**CROSS-REFERENCE**

:ref:`ernum` returns the error number,
:ref:`report` invokes an error message and :ref:`when--error`
allows error trapping. :ref:`erlin-pct` is exactly the same.

