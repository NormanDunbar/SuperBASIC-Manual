..  _px1st:

PX1ST
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PX1ST [{ flag }]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

This function can be used to determine whether IS\_PTRAP has been used
to dictate that any screen operations should just be ignored (this is
the default under PEX on JS and MG ROMs). The function name has a digit one in
it, not a letter 'eye'.

If the value returned is 0,
then (providing that you do not have a JS or MG ROM), PEX may be
allowing background screen access.

If the value is not 0, then screen
operations are merely ignored by the operating system (and therefore the
display is not affected).

If you use this function to pass a parameter,
then if the parameter is 0, then screen operations will not be ignored
and whether they cause a Buried program to halt will depend on whether
PEX is active. If you pass a non-zero parameter, then any screen
operations will be ignored.

**CROSS-REFERENCE**

See :ref:`peon` and in particular, refer to
:ref:`is-ptrap` for more details. See also
:ref:`is-peon`.

--------------


