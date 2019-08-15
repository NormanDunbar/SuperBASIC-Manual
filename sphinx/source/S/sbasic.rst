..  _sbasic:

SBASIC
======

+----------+------------------------------------------------------------------+
| Syntax   | SBASIC [pos] or                                                  |
|          |                                                                  |
|          | SBASIC pos$                                                      |
+----------+------------------------------------------------------------------+
| Location | SMS                                                              |
+----------+------------------------------------------------------------------+

This command is used to start up a Multiple SBASIC interpreter, which
is nearly an exact copy of the main interpreter (Job 0) and will contain
a copy of all of the toolkit commands used by the parent Job when this
command is invoked. Any toolkits subsequently loaded into the new SBASIC
interpreter cannot be used by its parent and vice versa. In its simplest
form::

    SBASIC

a new Interpreter will be started up which has windows #0,#1 and #2
open as per Job 0.

You can however pass either a one or two digit number
(either as a numeric pos or a string pos$), in which case only #0 will
be opened and its position will depend upon the number which has been
passed as a parameter. This enables you to start up a new SBASIC
Interpreter without its windows overlapping existing programs.

If only
one digit is passed, this is taken to be the SBASIC row number. Row 0 is
at the top of the screen, Row 1 is 64 pixels from the top, Row 2 128
pixels from the top and so on...

If two digits are passed, the first
digit is taken to be the SBASIC column number, the second becomes the
SBASIC row number (see above).

The column number is calculated as,
Column 0 being the left hand side of the screen, Column 1 is 256 pixels
from the left, Column 2 512 pixels from the left and so on....

**Example**

* ``SBASIC``: opens three channels, #0, #1 and #2 over the top of, and the same size as the existing windows in SuperBASIC;
* ``SBASIC 2`` (or ``SBASIC '2'``): Opens one channel, #0, as ``con_256x62a0x128``;
* ``SBASIC 3`` (or ``SBASIC '3'``): Opens one channel, #0, as ``con_256x62a0x192``;
* ``SBASIC 11`` (or ``SBASIC '11'``): Opens one channel, #0, as ``con_256x62a256x64``;
* ``SBASIC 12`` (or ``SBASIC '12'``): Opens one channel, #0, as ``con_256x62a256x128``;
* ``SBASIC 32`` (or ``SBASIC '32'``): Opens one channel, #0, as ``con_256x62a768x128``;


**CROSS-REFERENCE**

See :ref:`mb` and :ref:`ew` for other
ways of starting up additional interpreters. In addition SMS users can
use :ref:`exep` SBASIC or even use the Exec
button from QPAC II and Minerva users can use
:ref:`ex` PIPEP. :ref:`wmon` and
:ref:`wtv` can be used to reposition the SBASIC
windows. Also see the appendix on Multiple BASICs.
:ref:`job-name` can be used to alter the name of
a SBASIC Job.

