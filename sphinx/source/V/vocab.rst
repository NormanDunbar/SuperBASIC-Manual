..  _vocab:

VOCAB
=====

+----------+------------------------------------------------------------------+
| Syntax   | VOCAB [ #channel, ] type  or                                     |
|          |                                                                  |
|          | VOCAB [ #channel ] [,type]                                       |
+----------+------------------------------------------------------------------+
| Location | VOCAB (DIY Toolkit, Vol X)                                       |
+----------+------------------------------------------------------------------+

This command lists all of the names which fall into a given category
and are recognised by the SuperBASIC interpreter in the given channel
(default #1). If type is not specified, then it is assumed to be type=8.

The names are listed in columns, calculated by reference to the width of
the specified channel (set by WIDTH for non-window devices). Once all of
the names of the given type have been listed, a line feed is printed to
end the list. The values for type are:

+------+--------------------------+
| Type | Category of names listed |
+======+==========================+
| 0    | Unset Names              |
+------+--------------------------+
| 2    | Simple Variables         |
+------+--------------------------+
| 3    | Dimensioned Variables    |
+------+--------------------------+
| 4    | SuperBASIC PROCedures    |
+------+--------------------------+
| 5    | SuperBASIC FuNctions     |
+------+--------------------------+
| 6    | Used REPeat loops        |
+------+--------------------------+
| 7    | Used FOR loops           |
+------+--------------------------+
| 8    | Machine code Procedures  |
+------+--------------------------+
| 9    | Machine code Functions   |
+------+--------------------------+

Other values or type=1 will report an error or may cause junk to appear on screen.

**NOTE 1**

For some reason, under SMS, VOCAB 2 will report rubbish on screen unless
a program has been RUN already and even then, the last entry may not be
an actual variable. No such problems seem to occur on Minerva or other
ROMs.

**NOTE 2**

VOCAB 6 and VOCAB 7 only list those REPeat and FOR loop names which have
actually been used in the program when it has been RUN.

**CROSS-REFERENCE**

Use :ref:`sxtras` if you have a lot of extensions
in memory and you are looking for a specific one.

See also
:ref:`txtras`, :ref:`extras`
and :ref:`type`.

