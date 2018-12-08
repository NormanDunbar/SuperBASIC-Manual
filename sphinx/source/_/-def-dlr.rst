..  _-def-dlr:

\_DEF$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  \_DEF$ [ (#channel) ]                                            |
+----------+-------------------------------------------------------------------+
| Location |  DEFS (DIY Toolkit - Vol A)                                       |
+----------+-------------------------------------------------------------------+

This function is similar to \_DEF% in that it creates a table of all of
the SuperBASIC PROCedures and FuNctions used within the program
currently in memory. The table appears in the specified CONsole channel
(if any - default #2). You can use the cursor keys to highlight the
required PROCedure or FuNction name and then press <ENTER>, in which
case the function will return the selected name of the PROCedure or
FuNction. If you press the <ESC> key an 'Incomplete' error is caused. If
no PROCedures or FuNctions are defined, then a 'Not Found' error is
reported.

**CROSS-REFERENCE**

See :ref:`-def-pct`

