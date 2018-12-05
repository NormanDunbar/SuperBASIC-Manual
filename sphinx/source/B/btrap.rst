..  _btrap:

BTRAP
=====

+----------+-----------------------------------------------------+
| Syntax   | BTRAP #ch,key [,d1 [,d2 [,d3 [,a1 [,a2 ]]]]]        |
+----------+-----------------------------------------------------+
| Location | TRAPS (DIY Toolkit Vol T)                           |
+----------+-----------------------------------------------------+

This command is identical to QTRAP, except that the address parameters
(a1 and a2) are taken to be relative to A6, therefore allowing you to
access system calls which need to access the SuperBASIC variables, so
that you can for example save and load arrays direct!!


**WARNING**

Several TRAP #3 calls can crash the computer - make certain that you
know what you are doing!


**CROSS-REFERENCE**

See :ref:`io-trap`,
:ref:`mtrap` and :ref:`qtrap`.

Any return parameters can be read with
:ref:`datareg` and
:ref:`addreg`.

:ref:`cls`, :ref:`pan` and
:ref:`scroll` can also be used to call TRAP #3.

Refer to the QDOS/SMS Reference Manual (Section 15) for details of the
various system TRAP #3 calls.

Also refer to the DIY Toolkit documentation for this command.

--------------


