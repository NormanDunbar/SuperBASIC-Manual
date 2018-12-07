..  _qtrap:

QTRAP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QTRAP #ch,key [,d1 [,d2 [,d3 [,a1 [,a2 ]]]]]                     |
+----------+-------------------------------------------------------------------+
| Location |  TRAPS (DIY Toolkit Vol T)                                        |
+----------+-------------------------------------------------------------------+

This command is similar to IO\_TRAP in that it allows you to access the
machine code TRAP #3 system calls directly.

You will need to pass at
least two parameters, the number of the channel to be affected and the
operation key to be carried out (this is equivalent to the value in D0
when TRAP #3 is performed).

The other parameters allow you to pass the
various register values which may be required by the system calls. The
timeout parameter (D3) defaults to -1 (infinite timeout).

This can be
used effectively to set the INK and PAPER colours for THOR XVI's MODE 12
and still allow the program to be compiled. For example::

    QTRAP #2,HEX('27'),4

will set the PAPER colour in the window #2 to Green (although the STRIP
colour will remain unaffected).

**WARNING**

Several TRAP #3 calls can crash the computer - make certain that you
know what you are doing!

**CROSS-REFERENCE**

See :ref:`io-trap`,
:ref:`ttet3`, :ref:`mtrap` and
:ref:`btrap`. Any return parameters can be read with
:ref:`datareg` and
:ref:`addreg`. :ref:`cls`,
:ref:`pan` and :ref:`scroll` can
also be used to call TRAP #3. Refer to the QDOS/SMS Reference Manual
(Section 15) for details of the various system TRAP #3 calls.

