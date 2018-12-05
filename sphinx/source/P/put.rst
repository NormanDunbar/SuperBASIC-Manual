..  _put:

PUT
===

+----------+-------------------------------------------------------------------------------------------------+
| Syntax   | PUT [#channel\\file\_position,] [item\ :sup:`1` :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ...] or |
|          |                                                                                                 |
|          | PUT [#channel,] [item\ :sup:`1` :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ...]                    |
+----------+-------------------------------------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                                                            |
+----------+-------------------------------------------------------------------------------------------------+

This command forms the complement to GET and allows you to store
variables in the specified channel (default #3) in the QL's internal
format.

The variables are stored at the current position in the file (or
the file\_position given with the command, if the first variant is
used).

If you provide more than one variable name as the second, third
parameter etc, then several variables will be stored in the file in one
go.

If no variable is specified, the file pointer will be set to the
specified position if the first variant is used.

If the second variant
is used, this will have no effect.

If a variable is given as the file
pointer, then this variable will be updated with the current file
position once PUT has finished its work.

PUT can actually be used to
store variables in a different type to their current use (this might,
for example, be useful if storing part of a string), by adding the
following suffixes to each item:

+-------+-----------------------------------------------+
| +0    | Force floating point type (see note 2 below!) |
+-------+-----------------------------------------------+
| &''   | Force string type                             |
+-------+-----------------------------------------------+
| \|\|0 | Force integer type                            |
+-------+-----------------------------------------------+

**Example**

::

    a$='Entry 123':PUT #3,a$,a$(7 TO) || 0

will store in channel #3 two bytes giving the length of the string a$,
followed by the characters of the string itself, followed by two bytes
representing the integer value 123 (ie. 0\*256+123).

**NOTE 1**

On version 2.09 (or earlier) of Toolkit II, PUT could cause problems
when used on a channel opened over the network.

**NOTE 2**

Although PUT can convert variable types as above, if integer
tokenisation is enabled on Minerva, then PUT x%+0 will not work. You
need to use something such as PUT x%+1e-555 instead.

**NOTE 3**

Whenever storing data on disk, it is always preferable to store it in
its internal format (unless it is to be read on other systems as well).
Internal storage is faster because conversion between internal and
readable format is no longer necessary. It also produces shorter files
since the internal format needs less space and for floating point
numbers, the internal format gives the greatest possible accuracy.

**CROSS-REFERENCE**

See :ref:`put`, :ref:`bput`,
:ref:`wput`, :ref:`lput`,
:ref:`uput` and :ref:`get`.

--------------


