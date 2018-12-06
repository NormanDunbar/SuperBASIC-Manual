..  _exec:

EXEC
====

+----------+---------------------------------------------------------------------------------------------------------+
| Syntax   | EXEC program  or                                                                                        |
|          |                                                                                                         |
|          | EXEC file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`}]\ :sup:`\*` [;cmd$] (Toolkit II, THOR XVI)  or |
|          |                                                                                                         |
|          | EXEC file :sup:`\*`\ [,#ch\ :sup:`x`]\ :sup:`\*` [;cmd$] (Minerva v1.93+)                               |
+----------+---------------------------------------------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                                                                      |
+----------+---------------------------------------------------------------------------------------------------------+

This command loads and starts a machine code or compiled program, but
then returns control to the calling job (ie. the job which issued EXEC)
so that both jobs are multitasking.

Minerva v1.97+ has now implemented a sub-set of the Toolkit II standard,
in that you can pass details of existing channels to a job as well as a command string.

**CROSS-REFERENCE**

With Toolkit II installed or on a THOR XVI,
:ref:`exec` is the same as
:ref:`ex`. See also
:ref:`exec-w`, :ref:`ew`,
:ref:`ttex` and :ref:`et`. If you
are using the Hotkey System or SMS then
see :ref:`exep` in this manual.

