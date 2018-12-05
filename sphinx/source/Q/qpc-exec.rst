..  _qpc-exec:

QPC\_EXEC
=========

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_EXEC command$[, parameter$]                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This command can be used to call an external DOS or Windows program. The name of the executable file is given in the first parameter. Optionally, you can also supply a second parameter, which is then passed to the executed program as its command line arguments.

Furthermore, you can supply a data file as the first parameter. In this case, the associated application for this file type is executed.

**Example**

::

    QPC_EXEC 'notepad','c:\text.txt'

Starts notepad and loads the c:\\text file.

::

    QPC_EXEC 'c:\text.txt'

Starts the default viewer for .txt files.

--------------


