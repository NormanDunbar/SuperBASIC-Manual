..  _bmove:

BMOVE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BMOVE adr1a, adr1b, adr2                                         |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

BMOVE is a procedure which copies the whole of the memory stored between
the two addresses adr1a and adr1b to the new address pointed to by adr2,
so the number of bytes moved is adr1b-adr1a.


**Example**

Dump some memory to screen (note that this only works with the screen at
131072 and at 512 x 256 resolution):

::

    100 FOR a = 0 TO 10240 STEP 128
    110   BMOVE a, a+HEX("8000") TO HEX("20000")
    120 END FOR a


**WARNING**

Always ensure that there is sufficient available free memory at adr2 to
hold the data from adr1a to adr1b, otherwise your machine is most likely
to crash.


**CROSS-REFERENCE**

It is a good idea to check with :ref:`ver-dlr` if
Minerva is present and use its extremely fast MM.MOVE machine code trap
via :ref:`call` as an alternative to
:ref:`bmove`; this is demonstrated by the example at
:ref:`ldraw`.

:ref:`copy-b`,
:ref:`ttpokem`,
:ref:`copy-w` and
:ref:`copy-l` also allow you to move memory.

