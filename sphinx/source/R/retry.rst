..  _retry:

RETRY
=====

+----------+------------------------------------------------------------------+
| Syntax   | RETRY  or                                                        |
|          |                                                                  |
|          | RETRY [line\_no](Toolkit II and Minerva)                         |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

The command RETRY performs the same operation as CONTINUE
except that interpreting re-starts with the statement at which the
error occurred (CONTINUE re-starts the program from the next statement).

If you have Toolkit II or Minerva installed, you will be able to use the
second variant of this command which allows you to re-start processing
at a specified line number to help with error trapping. If the parameter
is specified, this is exactly the same as the second variant of
CONTINUE.

**Example**

Take the following short program::

    100 REPeat loop
    110 INPUT 'Enter a number: ';a
    120 PRINT 'The number you entered is: ';a
    130 END REPeat loop

Now, when prompted to enter a number, enter a letter, which results in
the error 'Error in Expression'. If you were to enter the command RETRY,
the program would re-start at line 110, asking you to enter a number.
However, if you entered the command CONTINUE, the program would re-start
at line 120, displaying the message::

    The number you entered is: *

**CROSS-REFERENCE**

Please refer to :ref:`continue`!

--------------


