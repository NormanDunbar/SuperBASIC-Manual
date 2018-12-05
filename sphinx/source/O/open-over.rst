..  _open-over:

OPEN\_OVER
==========

+----------+------------------------------------------------------------------+
| Syntax   | OPEN\_OVER #channel, device\_filename  or                        |
|          |                                                                  |
|          | OPEN\_OVER#channel, [device\_]filename(Toolkit II only)          |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This command is exactly the same as the Toolkit II version of OPEN\_NEW
except that if the specified filename already exists, the filename is
automatically overwritten. Also, the THOR XVI version of this command
does not support the default data device.

**CROSS-REFERENCE**

See :ref:`open-new`! The Minerva variant of
:ref:`open`, :ref:`open-in`
and :ref:`open-new` can all be made to work in
the same way as :ref:`open-over`.
:ref:`fop-over` is a function which operates
like :ref:`open-over` except that it allows any
errors to be trapped.

--------------


