..  _etab-dlr:

ETAB$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ETAB$ (string$ [,tabdist]) where tabdist=1..255                  |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

Some editors and word-processors use the character CHR$(9) as a tab mark to save
the space which would otherwise be needed to store several spaces. The function
ETAB$ takes a given string, expands all tab marks in it and returns the result.

If the tabulator distance, tabdist, is not given, a default of eight characters
is assumed. The length of string$ has to be smaller than 256 characters:
LEN(string$)<256.

Tabdist>255 has no effect.

**Example**

The text file test\_txt is shown with all tab marks expanded::

    100 OPEN_IN#3,test_txt
    110 CLS
    120 REPeat all_lines
    130   IF EOF(#3) THEN EXIT all_lines
    140   INPUT#3,line$
    150   IF LEN(line$)>255 THEN line$=line$(1 TO 255)
    160   PRINT ETAB$(line$,4)
    170 END REPeat all_lines
    180 CLOSE#3

**NOTE**

A value of tabdist<=0 will not produce usable output.

**WARNING**

Although tab mark distances of 32766 and 32767 are allowed, ETAB$ will
not produce a sensible output. It may even possibly crash the system.

**CROSS-REFERENCE**

:ref:`ctab-dlr` is the complimentary function to
:ref:`etab-dlr`. :ref:`instr` finds
the position of a string in another string. :ref:`len`
returns the length of a string.

