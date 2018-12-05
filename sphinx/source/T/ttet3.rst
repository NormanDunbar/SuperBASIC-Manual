..  _ttet3:

TTET3
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTET3 ( [#ch,] [timeout%,] trapno%, bufadr)                      |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This is a really extraordinary function because it allows you to call
the TRAP #3 operating system calls which handle screen devices, so you
would not theoretically need many other commands other than this one to
manipulate windows, if the use of TTET3 were not complicated by the
nature of its design.

The function TTET3 should only be used by
experienced users (except for some fool-proof usages shown in the
examples), so do not worry if you do not understand the following...
although we have tried to keep it simple.

Let's first turn to the syntax:

- The channel #ch (default #1) must refer to a window (con\_ or scr\_).
- The timeout for the machine code call trap is optional, the
  default is -1 (that means the operating system will try indefinitely to
  execute the trap) which is fine for most purposes.
- Trapno% is a small positive integer that identifies the trap.
- Bufadr must point to a piece of memory at least 16 bytes long.

Since this toolkit provides its own
buffer starting at TTV, it is recommended and safe to use this for
bufadr.

The required 16 bytes buffer is used to communicate with the
processor, the registers D1, D2, A1 and A2 occupy four bytes (one
longword) each within the buffer - they are copied to the processor when
the trap is executed and after the trap has finished will hold any
return values and be copied back into the buffer so that they may be
read with the lines::

    D1=PEEK_L(bufadr)
    D2=PEEK_L(bufadr+4)
    A1=PEEK_L(bufadr+8)
    A2=PEEK_L(bufadr+12)

**Example 1**

Superfluous with CLS but::

    x=TTET3(#2,32,TTV)

does a::

    CLS#2.

**Example 2**

The procedure SD\_ENQUIRE reads the window size and cursor position, the
values are placed in the passed integer variables. You can test if
anything went wrong (eg. #ch does not refer to a window) by checking if
any of the values returned are negative.

The parameter what% determines
the units,

- what% = 0 will have the effect that wsx% and wsy% are the window width and height in pixels and that (cpx%, cpy%) is the position of the text cursor in screen pixels;
- what%<>0 will give the same information but in characters.

::

    100 FOR i = 0, 1
    110   SD_ENQUIRE #2, i, a%, b%, c%, d%
    120   PRINT a%, b%, c%, d%
    130 END FOR i
    140 :
    150 DEFine PROCedure SD_ENQUIRE (ch, what%, wsx%, wsy%, cpx%, cpy%)
    160   LOCal trapno%
    170   POKE_L TTV+8, TTV+16
    180   trapno% = 10 + NOT(NOT what%)
    190   IF TTET3(#ch, 100, trapno%, TTV) THEN
    200     wsx% = -1: wsy% = -1: cpx% = -1: cpy% = -1
    210     RETurn
    220   END IF
    230   wsx% = PEEK_W(TTV+16): wsy% = PEEK_W(TTV+18)
    240   cpx% = PEEK_W(TTV+20): cpy% = PEEK_W(TTV+22)
    250 END DEFine SD_ENQUIRE

On Minerva, you can write NOT (NOT what%) without brackets. SD\_ENQUIRE
is absolutely clean, there is no danger at all that the system might
crash, that it does not run on all QDOS machines or anything like that.

All other machine code traps available through TTET3 are covered by
commands in this manual, but TTET3 can be used to avoid the need to link
in a Toolkit.

**CROSS-REFERENCE**

Please refer to system documentation for details on each trap! See also
:ref:`io-trap`, :ref:`qtrap`
and :ref:`mtrap`.

--------------


