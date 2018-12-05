..  _win-slug:

WIN\_SLUG
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_SLUG x                                                      |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for Atari                                          |
+----------+-------------------------------------------------------------------+

Some winchester (hard disk) ASCI drives, in particular the Megafile and
Vortex drives, need a special parameter to be passed to them before they
can be accessed by the QL due to timing faults in their controllers.
WIN\_SLUG allows you to set this parameter.

The value of x will depend
upon the drive being used, and can be anything in the range 0...255. It
is measured in units which are 0.8ms. This parameter sets the minimum
time that must elapse between operations on the ASCI bus. Most
controllers work with the default setting of 30 (which equates to a time
of 2.5ms). Refer to the disk documentation for further details.

--------------


