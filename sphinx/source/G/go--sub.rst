..  _go--sub:

GO SUB
======

+----------+-------------------------------------------------------------------+
| Syntax   |  GO SUB line\_number (GOSUB is expanded to GO SUB)                |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The command GO SUB was only implemented to make SuperBASIC more
compatible with other versions of BASIC.

SuperBASIC offers much more
elegant and powerful alternatives to this command - 'structured
programming'. Structured programs do not have to be longer than the same
program using GO SUB commands.

It is strongly recommended that you do
not use GO SUBs in programs. A similar effect (and much more besides)
can be achieved by using DEFine PROCedure and DEFine FuNction.

The idea behind GO SUB is that it jumps to a sub-routine within a program which
starts at the specified line\_number. Program flow then continues
through that sub-routine until a RETurn statement is found, in which
case, control is then returned to the statement following the original
GO SUB.

**Example**

A simple program which prints a title in shadow writing, using GO SUB to
call up the shadow writing routine::

    100 MODE 8
    110 WINDOW 448,200,32,16:PAPER 0:CLS
    120 a$='Hello there World'
    130 GO SUB 1000
    140 PAUSE
    150 CLS
    160 :
    999 STOP
    1000 CSIZE 2,0
    1010 AT 10,10:INK 4:PRINT a$
    1020 CURSOR 42,56,10,10:INK 7:OVER 1:PRINT a$:OVER 0
    1030 RETurn

This is actually much easier to read (and more flexible) if re-written
to use DEFine PROCedure instead (note that there is no longer any need
for line 999).

::

    100 MODE 8
    110 WINDOW 448,200,32,16:PAPER 0:CLS
    130 SHADOW_PRINT "Hello there World'
    140 PAUSE
    150 CLS
    160 :
    1000 DEFine PROCedure SHADOW_PRINT(v$)
    1010   CSIZE 2,0
    1020   AT 10,10:INK 4:PRINT v$
    1030   CURSOR 42,56,10,10:INK 7:OVER 1:PRINT a$:OVER 0
    1040 END DEFine

**NOTE 1**

It is not a crime to use GO SUB in your programs, after all, machines
are built for human beings, so the machines should be adapted to users,
and users must all find the most comfortable way for them to use their
machines.

**NOTE 2**

A calculated GO SUB statement, eg::

    GO SUB 1000+x*100

although allowed by the interpreter, is unlikely to be compiled successfully. Secondly,
RENUM is unable to change the line number of such GO SUBs. There were
also problems with using an expression for GO SUB in SMS pre v2.59.

**NOTE 3**

Avoid using GO SUB in an in-line FOR loop - see Note 2 of FOR.

**CROSS-REFERENCE**

Try to use SuperBASIC's more powerful
:ref:`repeat`, :ref:`for`,
:ref:`define--procedure` and :ref:`define--function` structures instead!

