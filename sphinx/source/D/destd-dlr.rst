..  _destd-dlr:

DESTD$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DESTD$                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+


This function always contains the current default destination device,
which is an unofficial QDOS standard and supported by the Toolkit II
variants of COPY, WCOPY, WREN, and SPL.

When Toolkit II is initiated,
DESTD$='SER'. The default device means that if no other device is stated
for the destination file, this device will be used. The default
destination device will also be consulted if a device name is supplied
but the given file cannot be found on that device.

For example, assuming
that DESTD$='flp2\_' and DATAD$='ram1\_', if you enter COPY
example\_txt, then the file ram1\_example\_txt will be copied to
flp2\_example\_txt. This idea can be extended to use prefixes as
sub-directories. Sub-directories are separated by underscores, DESTD$
always ends with an underscore.


**CROSS-REFERENCE**

:ref:`dest-use` and
:ref:`spl-use` both define the default
destination device\ .

:ref:`dup`, :ref:`ddown` and
:ref:`dnext` allow you to move around the
sub-directory tree. :ref:`progd-dlr` returns the
default program device, :ref:`datad-dlr` returns the
default data device. :ref:`dlist` prints all default
devices.

--------------


