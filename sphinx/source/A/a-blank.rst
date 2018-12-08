..  _a-blank:

A\_BLANK
========

+----------+----------------------------------------+
| Syntax   |  A\_BLANK [minutes]                    |
+----------+----------------------------------------+
| Location | ST/QL (Pre v2.24)                      |
+----------+----------------------------------------+

This command creates a small job which blanks out the screen if a key
has not been pressed for a specified number of minutes (default 5).

This command is useful, because if a very bright picture is drawn on
screen (eg. a white line on black paper), and the screen does not alter,
this can lead to what is known as 'burn in' when the monitor screen
becomes permanently marked with the 'ghost' of the picture. This does
not tend to happen very often nowadays, but in the past, monitors tended
to become unuseable as more and more of their screen became covered with
these 'ghosts'.

**NOTE**

This command will only work within the Pointer Environment.

**CROSS-REFERENCE**

:ref:`bls` is a similar function under SERMouse.

