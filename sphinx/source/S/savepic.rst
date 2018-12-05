..  _savepic:

SAVEPIC
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  SAVEPIC file$                                                    |
+----------+-------------------------------------------------------------------+
| Location |  PICEXT                                                           |
+----------+-------------------------------------------------------------------+

This command saves the screen contents (from $20000) to the specified
file, which has to be given as a string and must include the full
filename. The file which will be created is 32K long.

::

    SBYTES file$, SCREEN, 32768

does exactly the same.

**NOTE**

SAVEPIC makes the same assumptions and suffers from the same
compatibility problems as LOADPIC.

**CROSS-REFERENCE**

:ref:`loadpic` displays the saved screen file.

--------------


