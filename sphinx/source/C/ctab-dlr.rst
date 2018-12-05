..  _ctab-dlr:

CTAB$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CTAB$ (string$ [,tabdist]) tabdist=1..255                        |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

CTAB$ is a function which will look for spaces in the supplied string$
and if there is at least a tabdist number of spaces, they will be
replaced by the TAB character, CHR$(9), so that ETAB$ or editors /
word-processors can re-expand them to the original string.

CTAB$ does not alter the actual string$ but will return it in its
compressed form.

The default value of tabdist is 8, and the length of string$ is limited
to 255 characters (so tabdist>255 does not make much sense).

**WARNING**

tabdist=0 will produce rubbish output and it is also possible that CTAB$
will crash the system. Negative values lead to nonsense results but do
not harm the system.

**CROSS-REFERENCE**

:ref:`etab-dlr` expands the TAB marks.

--------------


