..  _freeze-pct:

FREEZE%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  frozen = FREEZE%                                                 |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FREEZE% returns either 0 or 1 (for OFF or ON
respectively) if <CTRL><F5> has been disabled by FREEZE or not.

**Example**

::

    frozen = FREEZE%
    IF frozen THEN do_stuff: END IF

**CROSS-REFERENCE**

:ref:`on` and :ref:`off` are constant
expressions for 1 and 0. :ref:`freeze-pct` returns
the current state. Compare :ref:`freeze` and
:ref:`freeze-pct` to :ref:`break`
and :ref:`break-pct`.

