..  _mb:

MB
==

+----------+-------------------------------------------------------------------+
| Syntax   |  MB                                                               |
+----------+-------------------------------------------------------------------+
| Location |  Minerva                                                          |
+----------+-------------------------------------------------------------------+

Early versions of Minerva (pre v1.97) did not have built-in MultiBASICs
and they had to be EXECuted from disk. However, you could make them
resident by linking in the file Mulib\_rext with the LRESPR command and
then this command, MB would be available to start up MultiBASIC
interpreters. This is not a very convenient way of starting MultiBASICs
as you cannot pass parameters to the MultiBASIC, nor can you use the
command to run filter programs.

**NOTE**

This command is redundant on Minerva v1.97+, whereby MultiBASICs can be
started up using EXEC pipep.

**CROSS-REFERENCE**

See :ref:`sbasic` and :ref:`ew`.
Also see :ref:`quit`. Check out the appendix on
Multiple BASICs.

--------------


