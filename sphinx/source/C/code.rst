..  _code:

CODE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CODE (character$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function returns the internal code used to represent the given
character$ (this will be a value between 0 and 255).

If the supplied parameter is more than one character in length, the code
of the first character will be returned. The result 255 represents the
ALT key, although this will only be produced with the statement PRINT
CODE(INKEY$) if the <ALT> key is being pressed together with a second
key, in which case the code of the second key quickly follows. If
character$ is a nul string, CODE will return 0.

**Example 1**

PRINT CHR$(CODE('Alpha'))

will print 'A'.

**Example 2**

A short program to reveal the code of the current key being pressed
(with special code to trap the instance of the ALT key being pressed):

::

    100 REPeat loop
    110   AT 0,0: a$ = INKEY$(#1, -1)
    120   IF CODE(a$) = 255
    130     PRINT 'ALT+' & CODE(INKEY$) & '  '
    140   ELSE PRINT CODE(a$);'      '
    150   END IF
    160 END REPeat loop

Try replacing lines 110 to 150 with: 110 AT 0,0: PRINT CODE(INKEY$(-1))

**CROSS-REFERENCE**

Please refer to the Characters section of the Appendix for a full list
of the characters and their internal codes.

--------------


