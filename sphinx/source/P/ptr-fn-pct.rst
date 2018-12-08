..  _ptr-fn-pct:

PTR\_FN%
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTR\_FN% (offset)                                                |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I - v2.8+)                      |
+----------+-------------------------------------------------------------------+

The DIY Toolkit includes code which allows you to link a serial mouse
to the QL, similar to the commercial SERMouse package which is packaged
with SMSQ/E for the Gold Card. Refer to the Appendix on Mice for more
details.

The mouse is enabled with PTR\_ON. This function can be used to
read various values used by the DIY mouse driver and which can be
altered using other commands from this toolkit.

The value of offset
should be in the range 0...13 and returns the following:

+--------+------------------------------------------------+
| Offset | Meaning                                        |
+--------+------------------------------------------------+
| 0      | Latest X position (Read with X\_PTR%)          |
+--------+------------------------------------------------+
| 1      | Latest Y position (Read with Y\_PTR%)          |
+--------+------------------------------------------------+
| 2      | Maximum X co-ordinate (Set with PTR\_MAX)      |
+--------+------------------------------------------------+
| 3      | Maximum Y co-ordinate (Set with PTR\_MAX)      |
+--------+------------------------------------------------+
| 4      | Step X (Set with PTR\_INC)                     |
+--------+------------------------------------------------+
| 5      | Step Y (Set with PTR\_INC)                     |
+--------+------------------------------------------------+
| 6      | Details of buttons pressed (Read with BUTTON%) |
+--------+------------------------------------------------+
| 7      | Synchronisation counter (Read with SYNCH%)     |
+--------+------------------------------------------------+
| 8 or 9 | Zero, or serial channel ID                     |
+--------+------------------------------------------------+
| 10     | Accumulated X drift                            |
+--------+------------------------------------------------+
| 11     | Accumulated Y drift                            |
+--------+------------------------------------------------+
| 12     | Set = cursor key emulation (Set with PTR\_KEY) |
+--------+------------------------------------------------+
| 13     | Set = Pointer Wrap (Set with PTR\_KEY)         |
+--------+------------------------------------------------+

The Accumulated X and  Y drift are counters, used by the serial mouse driver to judge how far
off the horizontal / vertical the mouse has moved and whether to
continue moving the pointer in a straight line or to take this into
account.

**CROSS-REFERENCE**

For more details, refer to the individual commands/ functions.

