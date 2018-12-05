..  _dmedium-drive-dlr:

DMEDIUM\_DRIVE$
===============

+----------+------------------------------------------------------------------+
| Syntax   | DMEDIUM\_DRIVE$ [(#channel)] or                                  |
|          |                                                                  |
|          | DMEDIUM\_DRIVE$ (\\file)                                         |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E v2.73+                                                    |
+----------+------------------------------------------------------------------+

This function returns the three letter code representing the device
connected to the specified channel or file. If no parameter is specified
then it tries #1, unless channel #3 is open in which case it will access
#3. If an error occurs, for example you specify a channel which is not
open or a file which does not exist, then an error will occur. Luckily
due to the fact that directories are stored in files under Level-2 and
Level-3 drivers, this means that you can use::

    PRINT DMEDIUM_DRIVE$(\flp2_)

if you wish. If the specified channel is not
open to a directory device then an empty string will be returned.


**NOTE 1**

This function does not appear to work 100%, for example on Falkenberg
hard disk interfaces it returns 'WINq' - however you can get around this
by copying the returned string to another variable and only looking at
the first three letters, for example::

    DRV$=DMEDIUM_DRIVE$
    IF DRV$<>"":PRINT DRV$( TO 3)


**NOTE 2**

This function will ignore the dev\_ device, returning the three letter
name of the device to which dev points, for example::

    DEV_USE 1,'flp1_quill_'
    drv$=DMEDIUM_DRIVE$(\DEV1_)
    IF drv$<>'':PRINT drv$(to 3)

Compare::

    PRINT DMEDIUM_DRIVE$(\DEV1_)


**CROSS-REFERENCE**

:ref:`dmedium-name-dlr` allows you to find out
the name of the disk in the specified drive.

--------------


