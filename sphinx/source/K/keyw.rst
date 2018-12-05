..  _keyw:

KEYW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  KEYW (keyword$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

This is a function which can be used to find whether or not a given
keyword is linked into the interpreter. If the keyword is known to the
interpreter, KEYW returns 0, otherwise -7.

**Example**

The following function returns 1 on Gold Cards and 0 on other systems
(or some early Gold Cards if they do not support the SLUG command). It
will unfortunately always return 1 under SMS which has the SLUG command
built-in.

::

    100 DEFine FuNction Gold_Card
    110   RETurn NOT KEYW("FLP_DENSITY") + KEYW("SLUG")
    120 END DEFine Gold_Card

A better way would be to use the MACHINE function.

**NOTE**

This will always access Job 0, therefore it cannot tell you whether or
not a keyword is linked into a MultiBASIC interpreter or a multiple
SBASIC interpreter.

**CROSS-REFERENCE**

:ref:`elis`, :ref:`defined` and
:ref:`key-add` are similar. Compare
:ref:`lookup-pct`.

--------------


