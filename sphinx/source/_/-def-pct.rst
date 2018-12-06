..  _-def-pct:

\_DEF%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  \_DEF% [ (#channel) ]                                            |
+----------+-------------------------------------------------------------------+
| Location |  DEFS (DIY Toolkit - Vol A)                                       |
+----------+-------------------------------------------------------------------+

This function creates a table of all of the SuperBASIC PROCedures and
FuNctions used within the program currently in memory. The table appears
in the specified CONsole channel, if any (default #2). You can use the
cursor keys to highlight the required PROCedure or FuNction name and
then press <ENTER>, in which case the function will return the line
number of the program line which contains the relevant DEFine PROCedure
or DEFine FuNction. If you press the <ESC> key an 'Incomplete' error is
caused. If no PROCedures or FuNctions are defined, then a 'Not Found'
error is reported.

**Example**

::

    ED _DEF%

**CROSS-REFERENCE**

:ref:`-def-dlr` and
:ref:`-name-dlr` are similar.
:ref:`codevec` returns the machine code base
address of a Machine Code Procedure or Function.

