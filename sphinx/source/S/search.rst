..  SEARCH, here, as a label, causes problems when building the docs
    as it conflicts with the actual search function of the generated
    documentation. Hence, this label (and all cross references to the
    SEARCH command, must use the label searches, as in :ref:`searches`.

    And, watch out, you cannot put a comment, like this, between a label
    and the immediately following chapter/section header or the label
    is not recognised.

..  _searches:

SEARCH
======

+----------+------------------------------------------------------------------+
| Syntax   | SEARCH (add1 TO add2, tofind$)  or                               |
|          |                                                                  |
|          | SEARCH (add1 TO add2, tofind$ [!] )(BTool only)                  |
+----------+------------------------------------------------------------------+
| Location | TinyToolkit, BTool                                               |
+----------+------------------------------------------------------------------+

This function scans RAM memory from address add1 to add2 for the given
string tofind$ and returns the address of its first occurrence or zero
if it was not found. The search is not case-dependent in the TinyToolkit
version whilst BTool introduces an optional switch: a '!' after tofind$
disables case-sensitivity and reduces speed.

**Example**

The following small program will scan the whole memory, ROM included,
from adr onwards for string$. Tiny-Toolkit SEARCH is assumed, PHYSTOP is
also necessary::

    100 string$="dev v" : REMark what we are looking for
    110 add=0 : REMark start address
    120 MODE 4: CSIZE 0,0: PAPER 0: INK 5: CLS
    130 REPeat searching
    140   add=SEARCH(add+1,PHYSTOP-add,string$)
    150   IF NOT add THEN EXIT searching
    160   PRINT \"Address ="!add
    170   PRINT PEEK$(add-20,19);
    180   INK 7: PRINT PEEK$(add,LEN(string$));
    190   INK 5: PRINT PEEK$(add+LEN(string$),20)
    200 END REPeat searching
    210 PRINT "That's all."

**NOTE**

The search string tofind$ will always be found at least twice in memory
because tofind$ itself needs to be stored somewhere.

**CROSS-REFERENCE**

:ref:`peek-dlr`, :ref:`dev-use`.
See other implementation of :ref:`searches`. See
:ref:`msearch`,
:ref:`search-mem` and
:ref:`ttfindm` also.

--------------


SEARCH
======

+----------+-------------------------------------------------------------------+
| Syntax   |  SEARCH (array$, tofind$, start, compare [,row] )                 |
+----------+-------------------------------------------------------------------+
| Location |  ARRAY                                                            |
+----------+-------------------------------------------------------------------+

The function SEARCH searches in a two or three-dimensional string array
array$ for the string tofind$. The search is not case-sensitive but
nevertheless very fast (as the example shows). SEARCH will always look
at one row only - there is just one if the array is two-dimensional but
for three-dimensional string arrays (where there are in fact
two-dimensions of strings because the third dimension is the maximum
string length) the optional row parameter which defaults to the first
row can be used to select a certain row. The start parameter allows you
to tell SEARCH from which element in the row onwards it should look
(remember that the first element is indexed with 0). Compare specifies
the number of characters at the start of each entry to ignore, so 0 will
search the whole entry for tofind$. The search stops if tofind$ was
found in an entry but not if the entry and tofind$ are identical.

SEARCH
returns the entry index or -1 if no suitable entry was found.

**Example**

Lines 100 to 170 of the following example initialise the name$ array
with n (here 1000) random strings of varying length, from four to 10
characters; this can take a while. After that, the whole array is
scanned for the string QL and all occurrences are listed. If you want to
check out the tremendous speed of SEARCH, amend line 100, set n to 10000
and assure that at least 100K of memory is free for the huge array: you
will be surprised, even the 10000 entries are searched in next to no
time!

::

    100 n = 1000: DIM name$(n,10)
    110 FOR i = 1 TO n
    120   name$(i) = ""
    130   FOR j = 1 TO 10
    140     name$(i) = name$(i) & CHR$(RND(65 TO 90))
    150     IF j > 3 AND NOT RND(5) THEN EXIT j
    160   END FOR j
    170 END FOR i
    180 :
    190 first = 1
    200 REPeat loop
    210   found = SEARCH(name$, "QL", first, 0)
    220   IF found < 0 THEN EXIT loop
    230   PRINT name$(found)
    240   IF found = n THEN EXIT loop: ELSE first = found + 1
    250 END REPeat loop

Minerva and SMS users can use integers for n, i, j, first
and found to speed up things, so replace them by n%, i%, j%, first% and
found%.

**CROSS-REFERENCE**

Use :ref:`instr` to locate a sub-string in a string.
:ref:`inarray-pct` is similar. See the other
implementation of :ref:`searches`.

