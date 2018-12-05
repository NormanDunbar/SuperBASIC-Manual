..  _alter:

ALTER
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ALTER 'variable' TO value                                        |
+----------+-------------------------------------------------------------------+
| Location |  ALTER (DIY Toolkit - Vol U)                                      |
+----------+-------------------------------------------------------------------+

This command works alongside SET from the same toolkit and allows you to
re-define the universal constants created with SET.

Unlike SET, the constant to be re-defined must appear in quotes as the
first parameter (otherwise the value of the constant is passed to be
altered by the command!!). As with SET, the constant and the value must
be of the same type, otherwise an 'error in expression' will be
reported.

If the constant has not previously been defined with SET, then if it is
recognised for some other reason an 'In Use' error will be reported. If
it is not recognised at all, then 'Not Found' will be reported.

Unlike SET, you can use ALTER from any program which is being used on
the QL and therefore you can use this to update constants or possibly
device names (or anything else you can invent).

**Example**

Set the following from SuperBASIC:

10 SET DEF\_DRIVE$ TO 'flp1\_'

If whilst using another program, the user re-defines the default device,
that program can use a line such as: ALTER 'DEF\_DRIVE$' TO
'win1\_prog\_' which will then alter the default device for all programs
which read this constant.

**NOTE**

ALTER does not work on SMS.

**CROSS-REFERENCE**

See :ref:`set`.

--------------


