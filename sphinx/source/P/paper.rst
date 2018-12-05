..  _paper:

PAPER
=====

+----------+------------------------------------------------------------------+
| Syntax   | PAPER [#window,] colour  or                                      |
|          |                                                                  |
|          | PAPER [#window,] colour1,colour2 [,pattern]                      |
+----------+------------------------------------------------------------------+
| Location |  QL ROM                                                          |
+----------+------------------------------------------------------------------+

This command sets the background colour inside a window (default #1).
Characters printed to that window will be written with the PAPER colour
as a background unless another colour has been specified with STRIP.

**Example**

::

    100 OPEN#3,scr_512x256a0x0
    110 REPeat forever
    120   FOR c=0 TO 7
    130     BORDER#3,RND(100)
    140     PAPER#3,c
    150     CLS#3
    160   END FOR c
    170 END REPeat forever

**NOTE**

PAPER also resets the STRIP to the specified colour.

**CROSS-REFERENCE**

:ref:`ink` sets the foreground colour and
:ref:`strip` the background for characters only.
:ref:`cls` clears a window in the current paper
colour. See :ref:`ink` concerning colour in general.

--------------


