..  _max-devs:

MAX\_DEVS
=========

+----------+-------------------------------------------------------------------+
| Syntax   | how_many = MAX\_DEVS                                              |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns the number of installed directory device drivers in your QL. It can be used to :ref:`dim`\ ension a string array to hold the device names as follows::

    1000 REMark Count directory devices
    1010 :
    1020 how_many = MAX_DEVS
    1030 :
    1040 REMark Set up array
    1050 :
    1060 DIM device$(how_many, 10)
    1070 :
    1080 REMark Now get device names
    1090 addr = 0
    1100 FOR devs = 1 to how_many
    1110   device$(devs) = DEV_NAME(addr)
    1120   IF addr = 0 THEN EXIT devs: END IF
    1130 END FOR devs


**CROSS-REFERENCE**

:ref:`dev-name`.


-------



