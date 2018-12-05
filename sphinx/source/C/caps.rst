..  _caps:

CAPS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  CAPS                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools                                                       |
+----------+-------------------------------------------------------------------+

After the command CAPS has been issued, any input from the keyboard via
INPUT, INKEY$ etc. is translated into capital letters. CAPS simulates
the use of the capslock key.

**Example**

To ask the user for any keyboard input, for example a

password where this should be entered in capital letters:

::

    100 CAPS
    110 INPUT "Please enter password:"!pass$
    120 NOCAPS

**NOTE**

Some old replacement keyboards use dirty tricks to engage capslock. If
you are fed up with the original QL keyboard then ensure you get the
latest release of a modern keyboard interface and an IBM-style keyboard.
If you do not do this, then you may have to change to capslock mode with
CAPS...

**CROSS-REFERENCE**

:ref:`nocaps` is self-explanatory.

--------------


