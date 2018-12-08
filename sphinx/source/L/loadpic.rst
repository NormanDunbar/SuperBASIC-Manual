..  _loadpic:

LOADPIC
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  LOADPIC file$                                                    |
+----------+-------------------------------------------------------------------+
| Location |  PICEXT                                                           |
+----------+-------------------------------------------------------------------+

This command will load an uncompressed 32K screen file and display it
on the main screen. - This works exactly the same as LBYTES
file$,131072. Note that LOADPIC needs the full filename to be supplied
as a string.

**Example**

    LOADPIC "flp1_Example_scr"

**NOTE 1**

LOADPIC assumes that the screen will be located at $20000 and will
therefore not work on Minerva's second screen.

**NOTE 2**

LOADPIC will not work on high resolution screens as it expects the
screen to be 512x256 pixels.

**CROSS-REFERENCE**

:ref:`savepic`,
:ref:`sbytes`, :ref:`lbytes`,
:ref:`screen`, :ref:`expand`,
:ref:`compress`.

