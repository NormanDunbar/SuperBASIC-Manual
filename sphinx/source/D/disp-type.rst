..  _disp-type:

DISP\_TYPE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DISP\_TYPE                                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function returns a number which allows you to find out the type of
display driver which is currently being used. The values returned are:

- 0 Original ST QL Emulator, QL Hardware (either of these two may support
  MODE 8) plus QXL and QPC. All of these (except the original ST QL
  emulator) may support higher resolutions.
- 1 Extended Mode 4 Emulator (either 512x256 or 768x280 pixel screen)
- 2 QVME Mode 4 Emulator
- 4 Monochrome display (only two colours)


**CROSS-REFERENCE**

See :ref:`disp-inverse`.
:ref:`machine` and
:ref:`processor` allow you to find out more
about the hardware which a program is being run on.

