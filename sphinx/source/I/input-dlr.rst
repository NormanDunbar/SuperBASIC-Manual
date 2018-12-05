..  _input-dlr:

INPUT$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  INPUT$ ([#ch,] length)                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

INPUT$ is identical to FREAD$ with the single difference that the
function also stops reading if a line feed character CHR$(10)
has been found. So, INPUT$ is dedicated to read line based text.

--------------


