..  _is-peon:

IS\_PEON
========

+----------+-------------------------------------------------------------------+
| Syntax   |  IS\_PEON [{ #ch \| chan\_ID \| job\_name$ }]                     |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

This function takes the same parameter as PEON and returns 0 if PEX is
not activated for the specified window (or Job) and returns a value not
equal to 0 if PEX is active. If no parameter is specified, then this
function just checks if PEX is active at all. If a pre-JS ROM is
installed, then this function will return the value -19.

**CROSS-REFERENCE**

See :ref:`peon` and
:ref:`is-ptrap` for more details.

