..  _cvf:

CVF
===

+----------+-------------------------------------------------------------------+
| Syntax   |  CVF (mkf\_$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function takes any six character long string, (the internal format
of a floating point number), and returns the value as a floating point
number.

**WARNING**

CVF locks SuperBASIC if the supplied parameter is six bytes long but not
a valid representation of a floating point number, eg. CVF("BlaBla").

MKF$ always returns a valid parameter for CVF which will not crash it.

**CROSS-REFERENCE**

:ref:`peek-f`, :ref:`mkf-dlr`,
:ref:`cvi-pct`, :ref:`cvl`,
:ref:`cvs-dlr`.

:ref:`fputf` and :ref:`fgetf`
enable you to read and write floating point numbers in internal format
to or from files.

