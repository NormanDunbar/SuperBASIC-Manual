..  _ttfindm:

TTFINDM
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTFINDM (addr, length, tosearch$)                                |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function will search for a given string in memory, see SEARCH,
MSEARCH and BLOOK. Memory is scanned from address addr for length bytes
onwards. The search is case-sensitive. TTFINDM returns zero if the
string was not found or the positive relative address plus one where the
string first occurs.

**Example**

Old or badly written programs and Toolkits require the screen located at
address $20000 and the System Variables at $28000, this causes great
problems an Minerva in Dual Screen Mode and other advanced systems as
well.

Our demonstration for TTFINDM loads a file into memory and scans
it for the occurrence of the two mentioned numbers in their internal
format. This method of checking code is pretty reliable for hand-written
machine code. The problem$ values have been computed with::

    MKL$(HEX("20000"))

and ::

    MKL$(HEX("28000"))

::

    100 file$ = "flp2_tool_shape_cde"
    110 length = FLEN(\file$)
    120 DIM problem$(2,4)
    130 problem$(1) = CHR$(0)&CHR$(2)&CHR$(0)&CHR$(0)
    140 problem$(2) = CHR$(0)&CHR$(2)&CHR$(128)&CHR$(0)
    150 :
    160 PAPER 3: CLS: INK 7
    170 PRINT "Allocating memory...";
    180 adr = TTALL(length): PRINT "done"
    190 IF adr = 0 THEN PRINT "No memory.": STOP
    200 PRINT "Loading"!file$;"...";
    210 LBYTES file$ TO adr: PRINT "done"
    220 FOR test = 1 TO DIMN(problem$)
    230   PRINT "Test"!test;"...";
    240   found = TTFINDM(adr, length, problem$(test))
    250   IF found THEN
    260     PRINT "failed"
    270     DUMPIT adr+found-1, 4, 20
    280   ELSE PRINT "ok"
    290   END IF
    300 END FOR test
    310 PRINT "Releasing memory...";
    320 TTREL adr: PRINT "done"
    330 :
    340 DEFine PROCedure DUMPIT (adr, length%, surr%)
    350   INK 4: PRINT TTPEEK$(adr-surr%, surr%);
    360   INK 7: PRINT TTPEEK$(adr, length%);
    370   INK 4: PRINT TTPEEK$(adr+length%, surr%): INK 7
    380 END DEFine DUMPIT

**CROSS-REFERENCE**

:ref:`searches`, :ref:`blook`,
:ref:`msearch` are all similar.

