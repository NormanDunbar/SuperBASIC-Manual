..  _clear:

CLEAR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  CLEAR                                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command forces all variables to be cleared meaning that the
computer will no longer remember their values.

This does not affect SuperBASIC functions or resident keywords, for
example, PRINT PI will always return 3.141593.

On non-SMS machines, if a variable is PRINTed, which has not yet been
assigned a value, an asterisk appears on screen. If you try to *use* a
variable which has not yet been assigned a value, then an error will
occur (normally error in expression (-17)).

If Toolkit II is present (or you are using Minerva or a THOR XVI), any
valid WHEN structures are also suspended by the CLEAR command.

Adding CLEAR before a program is run ensures that all variables used in
a program will be defined properly. While developing a large program in
BASIC it may sometimes be helpful to set an essential variable directly
in the command line and not as a static statement in the listing.

**Example**

The following lines will produce a different output depending on whether
they have been run before or not:

::

    100 PRINT a
    110 a=5
    120 PRINT a

The first run shows... \* 5 This is because the contents of a were not
defined until line 110 was reached.

The second time, a was still set and so the output is slightly
different... 5 5

**NOTE**

CLEAR may cause some problems on pre Minerva ROMs if it is issued after
having deleted a PROCedure or a FuNction in a SuperBASIC program which
appeared as the last thing in a program. This is fixed by Toolkit II.

**SMS NOTE**

Variables which have not been assigned a value on SMS will return 0
(zero) if a numeric variable or otherwise an empty string - an error
will therefore not occur if you try to use such a variable.

On a machine fitted with SMS the example would therefore have printed 0
5 on the first run, and 5 5 on the second.

**CROSS-REFERENCE**

:ref:`close`,
:ref:`clear-hot`,
:ref:`clchp`, :ref:`clrmdv`,
:ref:`run`.

--------------


