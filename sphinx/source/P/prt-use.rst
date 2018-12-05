..  _prt-use:

PRT\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_USE device                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

The ST/QL Emulator and SMSQ/E allow you to set up the PRT
device so that it mimics the SER, STX or PAR device. This means that
programs can be written which merely send their output to the PRT device
and it is then up to the user to set the port and options required by
the device attached to either the serial or parallel port.

The command
PRT\_USE allows you to specify both the port and options to be
associated with PRT.

It will ignore SER\_USE and PAR\_USE settings and
therefore expects device to be in one of the following forms::

    PAR<port><translate><convert><eof>
    SER<port><parity><handshake><translate><convert><eof>
    STX<port><parity><handshake><translate><convert><eof>

See the Appendix on drivers for further details.

**Example**

::

    PRT_USE ser1etf

will cause all attempts to access the PRT device to be re-directed to
serial port 1 with Even parity, translation enabled and a form feed
being printed at the end of the file.

**CROSS-REFERENCE**

:ref:`ram-use`,
:ref:`flp-use`,
:ref:`win-use`,
:ref:`ser-use` and
:ref:`par-use` are all very similar. See the
other version of this command.

--------------


PRT\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_USE usage,device                                            |
+----------+-------------------------------------------------------------------+
| Location |  Qjump RAMPRT, Trump Card, Gold Card, QXL Card                    |
+----------+-------------------------------------------------------------------+

Unlike the ST/QL Emulator and SMSQ/E implementations of this command,
this version of this command is used to enable you to set up dynamic
buffering on serial and parallel ports. The command PRT\_USE enables you
to connect a buffer to a specified device, altering the description
(usage) used to access that buffered device. Initially, the default
usage is PRT and the default device is SER which means that any attempt
to send output to the PRT device will actually access ser1, using the whole of the available
memory as a buffer.

PRT\_USE will actually recognise the full device
name, allowing it to have a similar effect as the alternative version of
this command. For example, the following are both equivalent::

    PRT_USE prt,ser1c (On the Gold Card)
    PRT_BUFF 0: PRT_USE ser1c (Under SMSQ/E)

The PRT device will also allow the same options as the device which it
is emulating, for example, the following are both the same (except the
latter uses buffered output)::

    OPEN #3,ser1c
    PRT_USE prt,ser:OPEN #3,prt1c

If you wish to buffer output on a given device, then you merely need to
specify the usage to be the same as the device. For example::

    PRT_USE ser,ser

will create buffered output to the serial ports whenever ser is used.

PRT\_USE will also allow you to specify the device to be buffered at
run-time. This is achieved by leaving the device
parameter as an empty string. For example::

    PRT_USE buff_,""

allows you to use the device name buff\_ser1 to access ser1, buff\_par to
access the parallel port etc. and all with buffered output.

**NOTE 1**

::

    PRT_USE prt,ser

will return the QL to the normal state after being
switched on (ie. only buffered output will occur if the device PRT is
used).

**NOTE 2**

If PRT\_USE is used to allow background printing, then some characters
may be lost (especially if you are using an old serial to parallel
converter), if you use a command which stops the QL multitasking (for
example FORMAT, LOAD, LBYTES, SBYTES and SAVE).

You can tell when this happens as the printer will stop
while the command is being carried out.

**CROSS-REFERENCE**

See also :ref:`prt-abt`. See the other version of
this command.

--------------


