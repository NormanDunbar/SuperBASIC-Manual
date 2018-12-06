..  _copy-b:

COPY\_B
=======

+----------+------------------------------------------------------------------+
| Syntax   | COPY\_B adr1, adr2, n or                                         |
|          |                                                                  |
|          | COPY\_B adr1, n TO adr2                                          |
+----------+------------------------------------------------------------------+
| Location | BTool                                                            |
+----------+------------------------------------------------------------------+

The command COPY\_B copies n bytes from the memory address adr1 to adr2
without any restrictions. The programmer has to ensure that there is
sufficient room at the specified destination memory location (which must
be free useable memory).

**Example**

::

    100 RANDOMISE: n=10
    110 a1=ALCHP(6*n): a2=ALCHP(6*n)
    120 FOR i=0 TO 6*(n-1) STEP 6: POKE_F a1+i,RND
    130 COPY_B a1,6*n TO a2
    140 FOR i=0 TO 6*(n-1) STEP 6: PRINT PEEK_F(a2+i)
    150 RECHP a1: RECHP a2

**CROSS-REFERENCE**

:ref:`copy-w`,
:ref:`copy-l`,
:ref:`ttpokem` and
:ref:`xchange`

