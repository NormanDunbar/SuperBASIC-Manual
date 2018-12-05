..  _fwrite-dlr:

FWRITE$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  FWRITE$ [#ch,] string$                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FWRITE$ is a command (not a function as the $ may suggest) and writes
string$ to #ch (default #1). It's the same as PRINT#ch,string$;.

**Example**

::

    FWRITE$ "Hello World"

**NOTE**

The Line feed character {CHR$(10)} is *not* printed at the end of the
text.

--------------


