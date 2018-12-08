..  _par-use:

PAR\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PAR\_USE [device]                                                |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E, SuperQBoard, PAR/SER Interfaces, Super Gold Card  |
+----------+-------------------------------------------------------------------+

As with many other devices, such as RAM, FLP and WIN, it can be useful
to alter the three letter description used to access the parallel
printer port on the Atari ST. The command PAR\_USE allows you to replace
the three letter description by any other three letters. If device is
not specified, this changes the description back to PAR.

**Example**

::

    PAR_USE ser

will divert any attempt to access the serial ports to the parallel
printer port.

**CROSS-REFERENCE**

:ref:`ram-use`,
:ref:`flp-use`,
:ref:`win-use`,
:ref:`ser-use` and
:ref:`prt-use` are all very similar.

