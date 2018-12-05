..  _upper-dlr:

UPPER$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  UPPER$ (string$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, Function (DIY Toolkit - Vol R)                      |
+----------+-------------------------------------------------------------------+

This function takes the given string and converts any lower case
letters to capitals and then returns the whole string. Normally, only
the ASCII alphabet is catered for, which means that no national
characters are converted, ie. the function only works with A..Z and
a..z.

The DIY Toolkit version will cope with accented characters, but
you may have to modify the source code in order for this function to
work with some international character sets which use an extended
alphabet.

**Example**

This is not quite an example for UPPER$ but a replacement which converts
all characters where an upper character is available::

    100 DEFine FuNction UPPER_$ (string$)
    110   LOCal i,c,u,u$: u$=""
    120   FOR i=1 TO LEN(string$)
    130   c=CODE(string$(i)): u=c
    140   SELect ON c=97 TO 122: u=c-32:=128 TO 139: u=c+32
    150   u$=u$ & CHR$(u)
    160   END FOR i
    170   RETurn u$
    180 END DEFine UPPER_$

**CROSS-REFERENCE**

:ref:`upc-dlr` returns the same as
:ref:`upper-dlr`. See also
:ref:`convcase-dlr` and
:ref:`lower-dlr`.

--------------


