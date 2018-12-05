..  _reset:

RESET
=====

+----------+------------------------------------------------------------------+
| Syntax   | RESET [new\_ramtop](Not SMSQ/E) or                               |
|          |                                                                  |
|          | RESET(SMSQ/E only)                                               |
+----------+------------------------------------------------------------------+
| Location | TinyToolkit, Beuletools, BTool, SMSQ/E, RES                      |
+----------+------------------------------------------------------------------+

This command performs a system reset. Except under SMSQ/E, this can be
used to simulate a system with less memory or to get old games and
problem software running, you can reduce the available memory (via
new\_ramtop) to anything between 128K (TinyToolkit: 64K) and RAMTOP in
64K steps (RES and BTool set a maximum of 640K).

**NOTE**

Do not include this command in a program without asking the user to
confirm that it is OK since the computer may be writing some essential
data to disk at the time (or still have some in memory).

**CROSS-REFERENCE**

On Gold Cards use :ref:`res-128` and
:ref:`res-size` for a faster reset. Minerva
allows you to use :ref:`call`  390,x to reset
the system.

--------------


