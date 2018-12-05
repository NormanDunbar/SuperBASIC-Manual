..  _dlist:

DLIST
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DLIST [#channel]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command lists all three current default directories (otherwise
returned by the DATAD$, PROGD$ and DESTD$ functions) to the specified
channel (default #1).


**Example**

::

    DLIST

possible Output::

    flp1_Quill_letters_
    ram1_
    par


**NOTE**

Some Toolkit II manuals mention a second syntax: DLIST \\file
but it seems as though this was never implemented. This should not be a
problem since programs can read the same information from the DATAD$,
PROGD$ and DESTD$ functions.


**CROSS-REFERENCE**

:ref:`datad-dlr`
(:ref:`data-use`),
:ref:`progd-dlr`
(:ref:`prog-use`),
:ref:`destd-dlr`
(:ref:`spl-use` or
:ref:`dest-use`),
:ref:`ddown`, :ref:`dup` Compare
:ref:`devlist` and
:ref:`dev-list`.

--------------


