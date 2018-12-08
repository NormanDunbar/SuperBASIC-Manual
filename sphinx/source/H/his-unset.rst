..  _his-unset:

HIS\_UNSET
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_UNSET #channel                                              |
+----------+-------------------------------------------------------------------+
| Location |  History Device                                                   |
+----------+-------------------------------------------------------------------+

This command removes a history from a channel, regardless of its state
of activity and the stored lines. HIS\_UNSET can only be used on
channels where a history exists, otherwise an error will be reported.

**Example**

::

    HIS_UNSET #0

**CROSS-REFERENCE**

:ref:`his-use`,
:ref:`his-size`

