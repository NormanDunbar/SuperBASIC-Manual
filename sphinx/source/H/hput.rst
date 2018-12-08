..  _hput:

HPUT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  HPUT [#ch] length [ , access [, type [, dataspace [, extra ]]]]  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to set the various parameters which are
contained in the header of the file attached to the specified channel
(default #3). The command will use the supplied parameters to set the
required information. If the specified channel is not open to a file,
then an Invalid Parameter error is reported. The information which can
be set is as per HGET.

**NOTE**

You will not be able to compile this command with Turbo or SuperCharge
due to the fact that it alters its own parameters.

**CROSS-REFERENCE**

:ref:`hget` reads the file header information. See
:ref:`fgeth-dlr` for information about the file
header. See also :ref:`heads` and
:ref:`sethead`.

