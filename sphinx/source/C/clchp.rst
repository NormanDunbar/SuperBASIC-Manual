..  _clchp:

CLCHP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLCHP                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, Btool                                      |
+----------+-------------------------------------------------------------------+

A BASIC program can reserve space in the common heap with ALCHP. The
command CLCHP removes all space which has been grabbed using ALCHP and
returns it to the common heap so that it can be used for other purposes.

**CROSS-REFERENCE**

:ref:`alchp` reserves areas of the common heap, and
:ref:`rechp` releases a specified part of the common
heap.

Compare :ref:`reserve` and the Btool variant of
:ref:`alchp`.

:ref:`new` and :ref:`load` also
release areas of the common heap.

