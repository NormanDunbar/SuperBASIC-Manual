..  _to:

TO
==

+----------+------------------------------------------------------------------+
| Syntax   | ... TO line (GO TO) or                                           |
|          |                                                                  |
|          | TO column (Separator)                                            |
+----------+------------------------------------------------------------------+
| Location |  QL ROM                                                          |
+----------+------------------------------------------------------------------+

This keyword has two uses. The first syntax operates as part of the
keyword GO TO. The second syntax is used as a separator in the commands
PRINT and INPUT (and also in some toolkit extensions). We shall only
deal with the use of TO for PRINT and INPUT here.

As a separator, TO can
be very useful for placing data into columns. Its effect is to place the
text cursor onto the specified column, or if the text cursor is already
at or past that column, then the text cursor is moved one column to the
right. This means for instance that::

    PRINT TO 0

will always leave the leftmost column blank!

TO is also affected by the
WIDTH setting on non-screen devices. If the specified column is greater
than the WIDTH
value, the text cursor will be placed onto the next line. On screen
devices, if the specified column is too great to fit in the window, the
text cursor is placed onto the next line rather than causing an error -
note however, that TO carries on counting!!.

TO has no meaning on its
own and will cause the error 'Bad Line' if entered on its own.

**NOTE**

On the THOR XVI, if the cursor is already at or past the given column,
the text cursor is not moved, in contrast to all other implementations.
Programs compiled with Turbo will however display the text as per the
standard QL implementation.

**CROSS-REFERENCE**

See :ref:`go--to` and
:ref:`print`, :ref:`input`.
:ref:`at` and :ref:`cursor` allow
you to position the text cursor more precisely.

--------------


