..  _new:

NEW
===

+----------+-------------------------------------------------------------------+
| Syntax   |  NEW                                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

If the command NEW is issued under the interpreter, the current
SuperBASIC program is removed from memory, the values of all variables
are forgotten, all channels owned by the interpreter (job 0) which have
a number equal to or higher than #3 are closed and the windows #0, #1,
#2 are cleared (in this order).

The Minerva, THOR XVI and Toolkit II
versions of NEW also disable WHEN ERRor clauses. A bug in JS and MGx
ROMs meant that these clauses could not be disabled once activated.

From within a compiled program, NEW removes the job from which it was issued
(ie. the current job).

**WARNING**

All data stored in variables is lost.

**CROSS-REFERENCE**

:ref:`clear`, :ref:`kill-a`.
Inside compiled programs, :ref:`new` and
:ref:`stop` are effectively the same.
:ref:`reset` clears the whole system by restarting
it.
