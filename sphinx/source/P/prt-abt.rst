..  _prt-abt:

PRT\_ABT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PRT\_ABT                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Trump Card, Gold Card, QXL                                       |
+----------+-------------------------------------------------------------------+

Because all output sent to the Trump Card, Gold Card and Super Gold
Card's built in PRT device is buffered (except if you are running SMSQ/E
which uses its own PRT device), it can be useful to stop the port from
outputting any further data.

PRT\_ABT will prevent any further output and clear the contents. The message
\*\*\*\*\*\* ABORTED \*\*\*\*\*\*  will then be sent to the port.

**CROSS-REFERENCE**

:ref:`prt-use` allows you to specify the type of
output to be buffered. The ST/QL Emulator and SMSQ/E support a similar
function with :ref:`prt-abort`,
:ref:`par-abort` and
:ref:`ser-abort`.

