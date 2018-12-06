..  _find:

FIND
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FIND (procfn$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

If procfn$ is the name of a machine code keyword (eg. "FILL$") then
the function FIND returns the address where the definition is stored in
memory.

If, however, procfn$ contains the name of a SuperBASIC PROCedure
or FuNction then FIND will return the line number where the PROCedure or
FuNction starts.

FIND returns 0 if the passed name is unknown.

**Example**

<ALT><r> requests a Procedure/Function name and calls Toolkit II's
full screen editor accordingly::

    ALTKEY "r","ED FIND('')"&CHR$(192)&CHR$(192)

**CROSS-REFERENCE**

:ref:`key-add`, :ref:`elis`,
:ref:`new-name` Also see
:ref:`flis`.

