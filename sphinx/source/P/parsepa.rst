..  _parsepa:

PARSEPA
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARSEPA (name)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  PARAMS (DIY Toolkit - Vol P)                                     |
+----------+-------------------------------------------------------------------+

This function is a useful addition that allows you to check on the type
of separator which follows a value passed as a parameter to a SuperBASIC
PROCedure or FuNction. The value returned by PARSEPA is:

+---------+-----------------------------------------------------+
| PARSEPA | Meaning                                             |
+=========+=====================================================+
| 0       | No separator follows - this is the end of the line. |
+---------+-----------------------------------------------------+
| 1       | A comma (,) follows.                                |
+---------+-----------------------------------------------------+
| 2       | A semicolon (;) follows.                            |
+---------+-----------------------------------------------------+
| 3       | A backslash (\\) follows.                           |
+---------+-----------------------------------------------------+
| 4       | An exclamation mark (!) follows.                    |
+---------+-----------------------------------------------------+
| 5       | The word TO follows.                                |
+---------+-----------------------------------------------------+

**NOTE**

This function suffers from the same problems as PARHASH.

**CROSS-REFERENCE**

See\ :ref:`parhash` in particular - this contains
an example which uses this function.

