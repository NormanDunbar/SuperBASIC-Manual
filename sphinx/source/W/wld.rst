..  _wld:

WLD
===

+----------+------------------------------------------------------------------+
| Syntax   | WLD (word1$, word2$ [,dummy] )  or                               |
+----------+------------------------------------------------------------------+
| Syntax   | WLD (word1$, word2$, w1, w2, w3 [,dummy] )                       |
+----------+------------------------------------------------------------------+
| Location | Ähnlichkeiten                                                    |
+----------+------------------------------------------------------------------+

This function calculates the weighted Levenstein phonetic distance
between two strings: the smaller the result, the more that the two
strings are phonetically similar.

If two strings are found to be
identical, then 0 is returned, otherwise a positive integer is returned.

The value of the dummy parameter does not actually matter - if it is
present then the function will not distinguish between upper and lower
case characters.

The three additional parameters of the second syntax
allow you to alter the importance of three possible factors used to
calculate the difference between the strings - each parameter should
have a positive value:

- w1: wrong letters
- w2: strings too short
- W3: strings too long

**Example**

::

    100 a$="Sinclair QL": b$="IBM PC": CLS
    110 PRINT a$;" <-> ";b$
    120 PRINT\WLD(a$,b$), WLD(a$,b$,0)
    130 PRINT WLD(a$,b$,1,1,1), WLD(a$,b$,1,1,1,0)
    140 PRINT WLD(a$,b$,0,0,0)
    150 PRINT WLD(a$,b$,1,2,3), WLD(a$,b$,3,2,1)

**CROSS-REFERENCE**

:ref:`soundex`,
:ref:`phonem`.

