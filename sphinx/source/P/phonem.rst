..  _phonem:

PHONEM
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PHONEM (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Ähnlichkeiten                                                    |
+----------+-------------------------------------------------------------------+

This function returns a string (even though the name does not end with
$) which is a (more Germanic) phonetic transcription of the supplied
string. If two words sound similar or are even homophones, their
PHONEM's are identical. The function is not case-sensitive.

**Examples**

::

    A$ = PHONEM ("Toolkit")
    A$ = PHONEM ("DoolGid")
    A$ = PHONEM ("DOLGYD")

All of which return "DOLCYD".

**NOTE**

An expression such as::

    PRINT PHONEM (a$) INSTR PHONEM (b$)

will always return 0 on pre Minerva ROMs. Use temporary variables to
get around this problem::

    t1$=PHONEM(a$) : t2$=PHONEM(b$)
    PRINT t1$ INSTR t2$

which will work properly.

**CROSS-REFERENCE**

:ref:`soundex`, :ref:`wld`.

