..  _command-line:

COMMAND\_LINE
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  COMMAND\_LINE                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is really only of any use with the TYPE\_IN command. It
selects the SuperBASIC command line (#0) so that anything passed with
TYPE\_IN is automatically entered into that channel (as if it were
typed).

Note that COMMAND\_LINE cannot have any effect if SuperBASIC is doing
something or if the job which uses the command was started with EXEC\_W
or similar.

**NOTE 1**

COMMAND\_LINE pre v3c27 does not seem to work correctly on all versions
of the QL ROM.

**NOTE 2**

Two files called TurboFix\_bin and MiniCommdLin\_bin can be used to
allow COMMAND\_LINE to select the command line of a Minerva MultiBASIC -
this relies on the MultiBASIC being the job which uses the COMMAND\_LINE
command. Some early versions of TurboFix\_bin have bugs in it.

A similar version is available called SMSQCommdLin\_BIN which works in
the same way, except for SMS SBASIC interpreters. Some versions of
TurboFix\_BIN also support SBASIC but it is currently recommended that
this file is used instead.

**CROSS-REFERENCE**

See :ref:`type-in` for an example.

--------------


