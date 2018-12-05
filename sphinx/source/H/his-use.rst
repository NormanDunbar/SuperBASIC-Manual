..  _his-use:

HIS\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_USE device$                                                 |
+----------+-------------------------------------------------------------------+
| Location |  History Device                                                   |
+----------+-------------------------------------------------------------------+

History's command line history is installed as a device driver to allow
you to use it from languages other than SuperBASIC. The default device
name is HIS and can be opened as an input pipe whenever a IO.EDLIN call
is to be used.

The HIS\_USE instruction allows you to rename this device
name to any other three letter code, passed as a string. The use of the
HIS device is beyond the scope of this book because it's not necessary
for SuperBASIC where the HIS\_SET, HIS\_SIZE and HIS\_UNSET commands are
available to handle it. Please refer to the original documentation!

**SMS NOTE**

The History device built into SMSQ/E uses the device name HISTORY and
can therefore be used alongside this version of the History Driver. You
cannot rename SMSQ/E's version.

**CROSS-REFERENCE**

See :ref:`his-use-dlr` and
:ref:`his-set`.

--------------


