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

--------------


