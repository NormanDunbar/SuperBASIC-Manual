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

The following examples should make it clear::

    1000 REMark Opens three channels, #0, #1 and #2 over the top of, and the 
    1005 REMark same size as the existing windows in SuperBASIC;
    1010 SBASIC 
    1015 :
    1020 REMark Opens one channel, #0, as con_256x62a0x128;
    1025 SBASIC 2: REMark Or SBASIC '2'
    1030 : 
    1035 REMark Opens one channel, #0, as con_256x62a0x192;
    1040 SBASIC 3: REMark Or SBASIC '3'
    1045 :
    1050 REMark Opens one channel, #0, as con_256x62a256x64;
    1055 SBASIC 11: REMark Or SBASIC '11'
    1060 :
    1065 REMark Opens one channel, #0, as con_256x62a256x128;
    1070 SBASIC 12: REMark Or SBASIC '12'
    1075 :
    1080 REMark Opens one channel, #0, as con_256x62a768x128;
    1085 SBASIC 32: REMark Or SBASIC '32'


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

