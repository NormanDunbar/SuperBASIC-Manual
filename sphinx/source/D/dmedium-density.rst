..  _dmedium-density:

DMEDIUM\_DENSITY
================

+----------+-------------------------------------+
| Syntax   | DMEDIUM\_DENSITY [(#channel)] or    |
|          |                                     |
|          | DMEDIUM\_DENSITY (\\file)           |
+----------+-------------------------------------+
| Location | SMSQ/E v2.73+                       |
+----------+-------------------------------------+

This function returns a number representing the density of the medium
on which the specified file or directory is located, or to which the
specified channel is open. If no parameter is specified, it looks to
channel #3 (or #1 if #3 is not open). An error will occur if the
specified channel is not open or the given file does not exist.

The value returned is:

- 0 Non-directory device
- 1 Double Density
- 2 High Density
- 3 Extra Density
- 255 Hard disk or ram disk as they have no density.


**Example**

::

    PRINT DMEDIUM_DENSITY(\flp1_)


**CROSS-REFERENCE**

:ref:`dmedium-name-dlr` gives the name of the
disk attached to the specified channel.
:ref:`dmedium-rdonly` and
:ref:`dmedium-format` are also useful.

--------------


