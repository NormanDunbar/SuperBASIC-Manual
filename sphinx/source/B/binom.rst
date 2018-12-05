..  _binom:

BINOM
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  BINOM (n,k)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function BINOM returns the value of the binomial coefficient which
is defined as the following (where n >= k):

n \* (n - 1) \* (n - 2) \* ... \* (n - k + 1) ) / ( 1 \* 2 \* ... \* k )
or, FACT(n) / ( FACT(k) \* FACT(n-k) )

The binomial coefficient gives the kth coefficient of the variables in
an expanded binomial series, this is called the binomial theorem:

(a+b)^n = BINOM(n,0) \* a^n + BINOM(n,1) \* a^(n-1) \* b + BINOM(n,2) \*
a^(n-2) \* b^2 + ... + BINOM(n,n-1) \* a \* b^(n-1) + BINOM(n,n) \* b^n

The binomial coefficient can also be used to calculate combinations and
probabilities. As the example shows, it is important to know the
mathematical theory behind this function to make full use of it.


**Example**

The following program calculates 2\ :sup:`n`:

::

    100 n=10: s=0
    110 FOR k=0 TO n: s=s+BINOM(n,k)
    120 PRINT s,2^n

It can be optimised by exploiting the fact that:

BINOM (n,k) = BINOM (n,n-k) which saves half of the loops:

::

    100 n=10
    110 IF NOT n MOD 2 THEN s=BINOM(n,n DIV 2): ELSE s=0
    120 FOR k=0 TO n DIV 2 - NOT n MOD 2
    130   s=s+2*BINOM(n,k)
    140 END FOR k
    150 PRINT s,2^n


**CROSS-REFERENCE**

:ref:`fact`\ .

--------------


