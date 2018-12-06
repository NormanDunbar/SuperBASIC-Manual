..  _continue:

CONTINUE
========

+----------+------------------------------------------------------------------+
| Syntax   | CONTINUE or                                                      |
|          |                                                                  |
|          | CONTINUE [line\_no](Toolkit II & Minerva only)                   |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

This command allows the user to try and recover from an error (normally
after STOP or pressing the Break key), by telling the interpreter to
carry on running the program from the next statement. This will however
not work if the message 'PROC/FN Cleared'.

If you have Toolkit II, Minerva installed, you will be able to use the
second variant of this command which allows you to re-start processing
at a specified line number to help with error trapping.

**NOTE 1**

CONTINUE cannot carry on processing where the line which was stopped was
a direct command (ie. typed in at #0).

**NOTE 2**

Unless you are using the Toolkit II or Minerva variants of this command,
do not try to use CONTINUE after RENUMbering the program, as the
continuation table is not updated by the RENUM routine and may therefore
try to jump to the old line number.

**NOTE 3**

Beware that RENUM does not renumber line\_no if you have used this
command as part of a program.

**NOTE 4**

CONTINUE can only re-start processing if no new lines have been added;
no new variables have been added to the program; no lines have been
altered; and the PROC/FN Cleared message has not appeared.

**CROSS-REFERENCE**

See :ref:`retry` and also
:ref:`when--error`.

