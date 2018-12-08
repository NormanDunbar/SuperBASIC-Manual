..  _sort:

SORT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  SORT array$, offset [,row]                                       |
+----------+-------------------------------------------------------------------+
| Location |  ARRAY                                                            |
+----------+-------------------------------------------------------------------+

The SORT command takes a two or three-dimensional string array and sorts it
in ascending order. offset is an even number which allows you to apply different
sort criteria by telling SORT to compare the sub-strings to the right of
position offset+1. The third, optional parameter is only necessary for
three-dimensional arrays: it selects the row to be sorted.

**Example**

CAT lists a sorted directory, including deleted files, to window #1.
Sorting the directory in fact requires just one line here (390), the
entries are sorted by file length because the format of each entry is as
follows::

    1        10       20        30      37      45
    |--------|--------|---------|-------|-------|
    filename                            length

Changing the SORT in line 390 to::

    390 SORT entry$, 0

will sort the list alphabetically. The other parts of the example
PROCedure are written to require only Toolkit II, that makes reading the
directory (the j loop from line 240 to 280) quite slow. If you are
wondering why the file header is stored twice, both as a string
(header$) and for direct memory access (header), this is for getting the
best out of basic QL facilities, namely PEEK\_W, PEEK\_L and string
slicing (line 310).

::

    100 DEFine PROCedure CAT (dir$)
    110   LOCal ch%, entries%, header, header$(64)
    120   LOCal c%, l%, i
    130   PRINT "Directory of"!dir$;": ";
    140   ch% = FOP_DIR(dir$)
    150   IF ch% < 0 THEN
    160     PRINT \"Cannot open directory,"\"because ";
    170     REPORT#1, ch%: RETurn
    180   END IF
    190   entries% = FLEN(#ch%) / 64
    200   DIM entry$(entries%, 45)
    210   header = ALCHP(64)
    220   FOR i = 0 TO entries% - 1
    230     header$ = ""
    240     FOR j = 0 TO 63
    250       BGET#ch%, c%
    260       POKE header+j, c%
    270       header$ = header$ & CHR$(c%)
    280     END FOR j
    290     l% = PEEK_W(header + 14)
    300     IF l% THEN
    310       entry$(i) = header$(17 TO 16 + l%) & FILL$(" ", 37 - l%)
    320       entry$(i) = entry$(i) & (PEEK_L(header) - 64)
    330     ELSE
    340       entry$(i) = "(deleted)" & FILL$(" ", 28) & "n.a."
    350     END IF
    360     PRINT ".";
    370   END FOR i
    380   CLOSE#ch%: RECHP header: PRINT
    390   SORT entry$, 36
    400   FOR i = 0 TO entries% - 1
    410     PRINT entry$(i)
    420   END FOR i
    430 END DEFine CAT

**CROSS-REFERENCE**

:ref:`searches` searches string arrays.

