..  _io-trap:

IO\_TRAP
========

+----------+-------------------------------------------------------------------+
| Syntax   |  IO\_TRAP ( [#ch], D0 [,D1 [,D2 [,A1 [,A2 [,D3 ]]]]] )            |
+----------+-------------------------------------------------------------------+
| Location |  THOR XVI                                                         |
+----------+-------------------------------------------------------------------+

This function enables you to directly access QDOS's I/O TRAP (TRAP #3)
machine code utilities. You need to supply the number of the TRAP call
as the parameter D0, but you can also set certain of the other internal
machine code registers used by the trap call by setting the other
optional parameters. The TRAP call will affect the specified channel
(default #1). Apart from parameter D3 (this defaults to -1), the purpose
of the other parameters depends upon the TRAP call being used. Unless D3
is negative, 'Not Complete' errors will not be reported, thus allowing
programs to continue even though their windows are buried under the
THOR's windowing system and therefore unusable. The return parameter is
the value returned in the machine code register D0 by the call.

**Example 1**

A short program to get the current window sizes and cursor position in
the variables Window\_Width, Window\_Height, Window\_posx and
Window\_posy respectively::

    100 a = ALCHP (8)
    110 dummy=IO_TRAP (11,0,0,a) : REMark IOW.CHRQ TRAP
    120 Window_Width = PEEK_W (a): Window_Height = PEEK_W (a+2)
    130 Window_posx = PEEK_W (a+4): Window_posy = PEEK_W (a+6)
    140 RECHP a

**Example 2**

Switch on the cursor in #1 (call IOW.ECUR)::

    t = IO_TRAP ( HEX ('E') )

**Example 3**

Set cursor to column x in #3 (call IOW.SCOL)::

    t = IO_TRAP (#3,HEX ('11'), x )

**CROSS-REFERENCE**

:ref:`cls`, :ref:`scroll` and
:ref:`pan` all allow you to access machine code trap
calls on different ROMs. :ref:`ink` contains a good
example of how to use :ref:`io-trap`.
:ref:`ttet3`,\ :ref:`mtrap`,
:ref:`qtrap` and :ref:`btrap`
are much better as they can be used on all ROM versions. The QDOS/SMS
Reference Manual (Section 15) contains details of the I/O Access Traps.

