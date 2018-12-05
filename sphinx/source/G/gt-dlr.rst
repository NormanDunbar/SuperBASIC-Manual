..  _gt-dlr:

GT$
===

+----------+-------------------------------------------------------------------+
| Syntax   |  GT$ (type, string1$, string2$)                                   |
+----------+-------------------------------------------------------------------+
| Location |  Btool                                                            |
+----------+-------------------------------------------------------------------+

This function allows you to compare two strings using the comparison
types supported by QDOS - it is therefore more flexible than direct
comparison using operators (see Appendix 11). The function will always
return 1 if string1$ is greater than string2$ and is therefore similar
to::

    PRINT string1$ > string2$

However, you can specify one of four comparison types, which will
affect the outcome:

+------+-----------------------------------------------------------------------------------------------------------------------------------+
| TYPE | Effect                                                                                                                            |
+======+===================================================================================================================================+
| 0    | Compare the two strings character by character                                                                                    |
+------+-----------------------------------------------------------------------------------------------------------------------------------+
| 1    | Ignore the case of the letters                                                                                                    |
+------+-----------------------------------------------------------------------------------------------------------------------------------+
| 2    | If there is no difference in the characters, compare the values of any embedded numbers.                                          |
+------+-----------------------------------------------------------------------------------------------------------------------------------+
| 3    | Ignore the case of the letters and still if there is no difference in the characters, compare the values of any embedded numbers. |
+------+-----------------------------------------------------------------------------------------------------------------------------------+

The characters are compared by using the following order::

    SPACE
    !"#$%&'()\*+,-/:;<=>?@[\\]^\_£{\|}~© 01234567890
    AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz
    Foreign characters (in order of the character set)

**CROSS-REFERENCE**

See :ref:`instr`. GE,
LT, LE,
:ref:`eq-dlr` and NE are all
similar facilities.

