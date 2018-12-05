..  _ser-cdeof:

SER\_CDEOF
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  SER\_CDEOF [port,] time                                          |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL (Level D00 +), SMSQ/E                                      |
+----------+-------------------------------------------------------------------+

Serial ports are able to both send and receive data. It is therefore
imperative that the System can detect when data is no longer being sent
to a port which is being used to receive the data. Normally, the System
will wait until it receives an End Of File character (CTRL Z or EOF).
However, it can be useful to specify a time limit, whereby if no data is
received during that time, the System assumes End Of File.

The command
SER\_CDEOF time allows you to specify the number of frames for which the
System will wait for more data. If time  equals 0, then the System will
wait indefinitely until it receives an explicit End Of File character.

The time should be more than 5 in order
to distinguish it from the port number. For machines with more than one
serial port, you can specify the number of the serial port this command
is to apply to (default SER1).

**NOTE 1**

This command has no effect on a QL, QPC or QXL.

**NOTE 2**

This command would not work properly on SCC ports on the Atari Mega STE
or TT until v2.73+.

**CROSS-REFERENCE**

:ref:`eof` and :ref:`eofw` allow
you to detect an EOF character.

--------------


