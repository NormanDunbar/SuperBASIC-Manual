..  _hget:

HGET
====

+----------+-------------------------------------------------------------------+
| Syntax   |  HGET [#ch] length [ , access [, type [, dataspace [, extra ]]]]  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to access the various parameters which are
contained in the header of the file attached to the specified channel
(default #3). The command will set the supplied parameters to the
required information.

If the specified channel is not open to a file, then an Invalid Parameter error is reported.

The information returned is as follows:

- length = Length of the File
- access = File Access Key
- type   = File Type
- dataspace = Dataspace for Executable Files
- extra = Extra Information

**NOTE**

You will not be able to compile this command with Turbo or SuperCharge
due to the fact that it alters its own parameters.

**CROSS-REFERENCE**

:ref:`hput` saves the file header information. See
:ref:`fgeth-dlr` for information about the file
header. See also :ref:`headr` and
:ref:`gethead`.

