..  _run:

RUN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  RUN [line]                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

There is one command which can be found in any BASIC language::

    RUN

Issuing RUN may actually be a little closer to the truth than you like
to admit, but you should be happy with BASIC. Assembly language is much
more terrifying, and if you have not yet reached that point of knowledge
and understanding which it is most frustrating to reach... However::

    RUN line

is identical to::

    GOTO line

and::

    RUN

without a parameter, could be replaced by GOTO 1.

Unlike some implementations of BASIC, the variables and the DATA pointer are not reset when you enter RUN.

**NOTE**

Jobs cannot be started with RUN but have to loaded and executed with EX,
EXEC\_W,... or a file manager/desktop. RUN will work okay from inside
compiled jobs to enable them to re-start themselves.

**CROSS-REFERENCE**

See :ref:`go--to` or even better, :ref:`repeat` and :ref:`for` loops.

