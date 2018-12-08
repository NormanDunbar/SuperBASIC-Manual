..  _default-device:

DEFAULT\_DEVICE
===============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT\_DEVICE devicename$                                      |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command can be used in a similar way to PROG\_USE and DATA\_USE.
It sets the default device (up to 31 characters), for the following
Turbo Toolkit commands:

- CHARGE,
- EXECUTE,
- EXECUTE\_A,
- EXECUTE\_W
- LINK\_LOAD,
- LINK\_LOAD\_A,
- LINK\_LOAD\_W.

It has no effect on any other commands.


**Example**

For a series of linked programs, you may want to use the following in a
boot file::

    DEFAULT_DEVICE win1_PROGS_

Each program could call another by using::

    EXECUTE_W program2_task


**NOTE 1**

Prior to v3d27, this command only supported 5 characters (although prior
to v2.00 no error was reported if more than 5 characters were used - the
command simply ignored the additional characters).


**NOTE 2**

As from v1.26, you do not need to pass the device name as a string, for
example::

    DEFAULT_DEVICE flp1_


**CROSS-REFERENCE**

:ref:`prog-use`.

