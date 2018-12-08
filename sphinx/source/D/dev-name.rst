..  _dev-name:

DEV\_NAME
=========

+----------+-------------------------------------------------------------------+
| Syntax   | device$ = DEV\_NAME(address)                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function must be called with a floating point variable name as its parameter.  The first time this function is called, address *must* hold the value zero, on all other calls, simply pass address *unchanged* back.  The purpose of the function is to return a directory device name to the variable device$, an example is worth a thousand explanations.

::

    1000 addr = 0
    1010 REPeat loop
    1020   PRINT "<" & DEV_NAME(addr) & ">"
    1030   IF addr = 0 THEN EXIT loop: END IF
    1040 END REPeat loop

This small example will scan the entire directory device driver list and return one entry from it each time as well as updating the value in 'addr'. The value in addr is the start of the next device driver linkage block and *must not be changed* except by the function :ref:`dev-name`. If you change addr and then call :ref:`dev-name` again, the results will be very unpredictable.

The check for addr being zero is done as this is the value returned when the final device name has been extracted, in this case the function returns an empty string for the device.  If the test was made before the call to :ref:`dev-name`, nothing would be printed as addr is zero on entry to the loop.

Please note, every QL has at least one device in the list, the 'MDV' device and some also have a device with no name as you will see if you run the above example (not the last one as it is always an empty string when addr becomes zero).

The above example will only show directory  devices, those that can have DIR used on them, or :ref:`format` etc, such as WIN, RAM, FLP, FDK etc, however, it cannot show the  non-directory  devices such as SER, PAR (or NUL if you have Lightning), as these are in another list held in the QL.

**Note**

From version 1.14 of DJToolkit onwards, there is a function that counts the number of directory devices present in the QL. See :ref:`max-devs` for details.


**CROSS-REFERENCE**

:ref:`max-devs`.

