..  _report:

REPORT
======

+----------+------------------------------------------------------------------------------+
| Syntax   | REPORT [#channel] or                                                         |
|          |                                                                              |
|          | REPORT [#channel,][error\_number](Toolkit II, THOR XVI, TinyToolkit, BTool)  |
+----------+------------------------------------------------------------------------------+
| Location | QL ROM (post JM), Toolkit II, TinyToolkit, THOR XVI and BTool                |
+----------+------------------------------------------------------------------------------+

This command will print an error message to the given channel (default
#0, the command line). The type of error is identified by the error
number. If an error number is not supplied, then the last error to have
occurred is displayed. The error message depends on the machine where
the program is running, see ERNUM for conventions. Positive error
numbers have no effect.

**WARNING**

Toolkit II's REPORT allows any value for the error\_number, whereas
TinyToolkit and BTool limit them to -1 to -21 and report undefined error
for values lower than -21. Except under SMS, with Toolkit II, negative
errors smaller than -27 may lead to undefined actions ie. printing a
continuous stream of characters to the report channel - this may never
stop.

**NOTE 1**

TRA can be used to redefine the error messages.

**NOTE 2**

For the original REPORT (QL ROM), only the first version of the command
can be used. Further, if the supplied channel is not yet open, no error
is reported and REPORT simply returns to BASIC as if it had carried out
its job successfully. Also, on Minerva, SMS and ST/QL Emulators with
E-Init software v1.27+, REPORT will show the line and statement number
where the error occurred (rather than merely the line number) in the
form: At line <line number>;<statement number><error message>

**CROSS-REFERENCE**

See :ref:`ernum` about error messages in general and
:ref:`tk2-ext`
/:ref:`tiny-ext` about updating Toolkits. Refer
to the Appendix for the different message texts in various languages.

--------------


