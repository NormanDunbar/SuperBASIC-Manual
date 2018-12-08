..  _close:

CLOSE
=====

+----------+---------------------------------------------------------------------------+
| Syntax   | CLOSE #channel  or                                                        |
|          |                                                                           |
|          | CLOSE #channel1 [, #channel2 ...] (Toolkit II, Btool & Minerva v1.81+) or |
|          |                                                                           |
|          | CLOSE (Toolkit II, THOR & Minerva v1.81+, BTool)                          |
+----------+---------------------------------------------------------------------------+
| Location | QL ROM, Toolkit II, BTool,. THOR                                          |
+----------+---------------------------------------------------------------------------+

CLOSE is a procedure which closes a specified channel, (or even several
channels if the second or third variant is used). The contents of that
channel will however remain unchanged.

The second variant allows any number of specified channels to be closed
at the same time and the third closes all channels with channel numbers
of #3 or above.

Every CLOSE command will first flush the contents of internal buffers to
ensure that all information has been passed to the channel before it is
closed.

**Examples**

::

    CLOSE#3
    CLOSE#n
    CLOSE #1
    CLOSE#8,#3,#6
    CLOSE

**NOTE 1**

On Minerva pre v1.81 and other ROMs, unless Toolkit II is installed,
CLOSE will report 'channel not open' if the channel is not open. Toolkit
II and later versions of Minerva stop this from happening.

**NOTE 2**

There is a harmless bug in Toolkit II's CLOSE. This will report error
-15 (bad parameter) if channel #32767 was opened and CLOSE issued
without parameters, or even if you use the explicit command CLOSE #32767
(unless you have SMS). Although #32767 will still be closed
successfully, any further attempt to use CLOSE without parameters will
continue to report error -15 until the program is cleared out with NEW,
LOAD or LRUN.

**NOTE 3**

On Minerva, if you have Lightning installed, then unless you CLOSE
channels in the opposite order to that in which they were OPENed, you
may end up with several CLOSEd windows which are still visible on
screen. This will only disappear when another channel with the same
channel number is opened. The Pointer Interface and SMS cure this.

**NOTE 4**

Unless you have a THOR XVI or Minerva (without SMS), do not CLOSE a
network out (eg. NETO\_1) channel unless you have written something to
it. The machine will lock up if you do so be warned! On a THOR, the
system will lock up for 30 seconds and then report an 'Xmit Error'. On
Minerva, you will need to press <CTRL><SPACE>.

**NOTE 5**

QL ROMs (pre MG) had problems in closing ser2 - they tended to close one
serial channel for output and the other for input instead!

    NOTE 6:

**NOTE 6**

If you are writing to a file (especially on a microdrive cartridge),
ensure that the drive has finished turning after issuing the CLOSE
command, before trying to access the file (otherwise you may find that
all of the changes are not present!). The other solution is to FLUSH the
file before CLOSEing it.

**MINERVA NOTE**

CLOSE #1 will also remove a MultiBasic job in certain instances - see
appendix on Multiple Basics.

**WARNING**

Although under the interpreter, channel #0 (the command window) and
channels #1 and #2 can be closed, this will lock up the SuperBASIC
interpreter. It does no harm at all in compiled programs.

Minerva and SMS prevents this from being disastrous, but some programs
may behave a little strangely on the newly opened #0. If you use CLOSE
#0 from within a MultiBASIC or one of SMS's SBASICs, this will remove
the MultiBASIC (or SBASIC) Job.

**CROSS-REFERENCE**

:ref:`open`, :ref:`channels`,
:ref:`close-pct`
:ref:`scr-store` and related commands can be
used to provide the QL with a windowing environment whereby the contents
of the screen are restored when a window is
:ref:`close`\ d.

