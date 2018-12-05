..  _peeks-l:

PEEKS\_L
========

+----------+------------------------------------------------------------------+
| Syntax   | PEEKS(address) where address=0,1,2,3,...  and                    |
|          |                                                                  |
|          | PEEKS\_W(address) where address=0,2,4,6,...  and                 |
|          |                                                                  |
|          | PEEKS\_L(address) where address=0,2,4,6,...                      |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E and ATARI\_REXT v2.17+                                    |
+----------+------------------------------------------------------------------+

These three functions are only of any use on the Atari series of
computers. They are the same as the normal forms of PEEK, PEEK\_W and
PEEK\_L, except that they operate in Supervisor Mode and can therefore
be used to read data direct from the Atari's IO hardware. On all other
implementations they are the same as PEEK, PEEK\_W and PEEK\_L.

**CROSS-REFERENCE**

See :ref:`peek`. :ref:`pokes` is
the complementary command. See :ref:`prot-mem`
also.

--------------


