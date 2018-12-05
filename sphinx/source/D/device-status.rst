..  _device-status:

DEVICE\_STATUS
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVICE\_STATUS ([open\_type,] filename$)                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function returns a value representing the current status of the
device to which the specified filename$ points and can be used to check
if an error will be generated when you try to access the given file. The
open\_type defaults to 2 and can take the following values:

- -1: Use for OPEN or OPEN\_NEW
-  0: Use for OPEN
-  1: Use for OPEN\_IN
-  2: Use for OPEN\_NEW

If an open\_type of 2 is specified, then the function will try to
create the file and return an error code if this is not possible. The
temporary file is deleted in all cases.

If an open\_type of 0 is
specified then the function will try to open the file for exclusive two
way access and report any errors.

If an open\_type of 1 is
specified the function opens the specified file for read only access,
which means that it does not care if a channel is already open to the
file from another program.

Finally, if an open\_type of -1 is specified,
the function will first of all try to open a channel to the file,
returning -8 if it already exists and can therefore be read.

If it does
not already exist, the function will try to create a temporary file and
then read back from it to check that the device can be written to and
read from, reporting any errors which are found. Any temporary file is
then deleted by the function. This enables IN USE and bad or changed
medium errors can be detected!

If the open is successful the amount of
free space on the drive is returned akin to DEVICE\_SPACE, otherwise a
standard QDOS error code is returned.


**NOTE 1**

Current versions of this fuction have difficulty returning the amount of
space on large capacity drives, such as hard disks. It assumes that a
sector contains 512 bytes and will only cope with a maximum of 65535
sectors.


**NOTE 2**

Due to a bug in the QL's hardware, it is impossible to check if a
microdrive is read only. In this instance, you will get a bad or changed
medium error code (-16).


**CROSS-REFERENCE**

See :ref:`device-space` for an example.

--------------


