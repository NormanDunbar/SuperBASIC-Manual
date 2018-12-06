..  _dataspace:

DATASPACE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DATASPACE (file$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function returns the amount of dataspace which has been set aside
for the given file$. It is therefore similar to FDAT and FILE\_DAT.

Default devices are not supported, however errors are not reported.
The following error values may also be returned by the function:

- -2: The file is not executable
- -3 or -6: Insufficient memory to open file
- -7: File does not exist
- -9: Device or file is being written to by something else.
- -12: The device is valid, but the filename is not
- -16: Bad or changed medium error


**Example**

::

    PRINT DATASPACE('win1_start_QD_exe')


**CROSS-REFERENCE**

:ref:`data-area` allows you to set the
dataspace for a compiled program. See also
:ref:`fdat`.

