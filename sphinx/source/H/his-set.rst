..  _his-set:

HIS\_SET
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_SET #channel                                                |
+----------+-------------------------------------------------------------------+
| Location |  History Device (Needs Pointer Environment)                       |
+----------+-------------------------------------------------------------------+

The History Device is an extension to the internal QDOS routine
IO.EDLIN which reads editable text input from the keyboard; IO.EDLIN is
used if, for example, you use INPUT on a window - even the interpreter
uses IO.EDLIN to get its commands from #0. But let's see how the History
Device alters keyboard input.

The toolkit must be loaded into Resident
Procedure Memory (with RESPR) before any Jobs are started, but after the
Pointer Environment and Lightning / Speedscreen (or any other drivers
which alter the con\_ device driver) are installed (if either of these
two packages are required).

Often, if you respond to a set of questions
asked by a program, the same answers crop up again and again. For
example, take the SuperBASIC interpreter, if you have entered a command,
it will carry it out and wait for the next command to be entered. You
may find that you want to type in the same text - or something which you
entered a few loops ago again.

Toolkit II and the Hotkey System install
a last line recall when the <ALT><ENTER> key combination is pressed (can
be configured with the Hotkey System) - this is widely accepted (it's
even supported by keyboard interfaces), but, has not proved to be very
reliable or useful: recalling the last line typed generally works well,
but for lines which were entered some time ago, things become easily
messed up.

The History Device sits on the afore-mentioned QDOS trap and
stores a specified number of entered lines for any console channel. If a
program then requests input, previously entered lines can be recalled
using the <↑> and <↓> keys - this is called a command line history (hence
the name of the History Device).

A history for a console channel must be
explicitly installed, by using the HIS\_SET command. HIS\_SET can only
accept channel numbers which point to a con\_ device, it breaks with
'bad parameter' if that is not the case. Once the history is installed,
you will need to activate it by using the command HIS\_SIZE.

**Example**

To install a command line history for the SuperBASIC interpreter - these
lines could be added to a BOOT program::

    HIS_SET #0: REMark Install a command line history for #0
    HIS_SIZE #0, 40: REMark Activate history which stores 40 lines

**NOTE 1**

The History Device does not run on at least pre E.21 drivers of the
ST/QL or STE/QL due to a bug in the IO.EDLIN trap of these drivers.
History is fine for Minerva up to v1.93, although there are harmless
problems with v1.96 in that the current line is not displayed before the
line is altered. QView and Jochen Merz Software have been informed about
these difficulties, so these may already be fixed by now.

**NOTE 2**

You cannot redefine the keys used for last line recall!!

**SMS NOTE**

The History device is built into SMSQ/E, although the HIS\_... commands
are not included with SMSQ/E, so in reality, you can only use the
HISTORY device as a Last In First Out pipe system - see Devices
Appendix. In any event the HIS\_... commands do not appear to work on
SMS.

**CROSS-REFERENCE**

A history is automatically removed when a channel is closed but removal
can also be forced with :ref:`his-unset`. The
QDOS/SMS Reference Manual contains full details of IO.EDLIN

--------------


