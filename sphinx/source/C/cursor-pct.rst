..  _cursor-pct:

CURSOR%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CURSOR% [#window]                                                |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns the current status of the text cursor in the
specified window (default #1). Results are:

-  0 for disabled,
-  1 for enabled and visible,
-  -1 for enabled but invisible.

An active cursor flashes, and therefore alternates between visible and
invisible status when enabled. Otherwise, it will appear as a solid
block on screen (unless there is no cursor attached to the specified
channel).

On Minerva it is possible to alter the shape and colour of the cursor.

**CROSS-REFERENCE**

:ref:`cursen`, :ref:`curdis`,
:ref:`cursor` and :ref:`cur`
enable or disable the cursor.

Also refer to :ref:`cursor-off` and
:ref:`cursor-on`.

--------------


