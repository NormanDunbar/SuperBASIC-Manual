..  _ftest:

FTEST
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FTEST (name)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

The function FTEST is designed to allow you to test for the status of
a file with the specified name. It will return a value of 0 if the given
name can be opened for input only. It may however return a negative
number representing an error code which would result if you tried to
OPEN or OPEN\_IN that file.

**NOTE 1**

The return of -6 (channel not open) has a special meaning in relation to
this function, it means that the function could not find any room in the
channel table to try and access the file.

**NOTE 2**

Due to the nature of the command, name can be used to represent any
valid device, and could therefore, for example, be used to check if a
resolution of 768x280 pixels is supported::

    100 a$='scr_768x280a0x0'
    110 IF FTEST(a$)<0
    120   a$='scr_512x256a0x0'
    130 END IF
    140 OPEN #3,a$

**NOTE 3**

On Level-2 and Level-3 devices, there is always a file with the same
name as the actual name of the device (eg. 'flp1\_'). This therefore
allows you to check if a medium is present in a Level-2 device::

    IF FTEST(flp1\_)<0 THEN PRINT 'Please insert disk'

You must however be aware that on Level-1 devices, it is unlikely
that such a file will be present and that FTEST will return -7 even if
there is a disk present.

**NOTE 4**

FTEST will not warn you if a disk is read only, which can create
problems.

**CROSS-REFERENCE**

:ref:`fopen` and :ref:`fop-in`
allow you to open files safely.
:ref:`dmedium-rdonly` can be used to find
out if a disk is write protected.

