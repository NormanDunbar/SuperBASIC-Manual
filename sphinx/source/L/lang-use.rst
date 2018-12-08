..  _lang-use:

LANG\_USE
=========

+----------+------------------------------------------------------------------+
| Syntax   | LANG\_USE num  or                                                |
|          |                                                                  |
|          | LANG\_USE kcode                                                  |
+----------+------------------------------------------------------------------+
| Location |  SMS                                                             |
+----------+------------------------------------------------------------------+

This command sets the language to be used by SMS for its message tables
(this includes interpreter messages and error messages). The value of
num and kcode can be the same as for the SMS implementation of
:ref:`kbd-table`\ . A description of the message tables and how to link in new
message modules is contained in IQLR Volume 5 Issue 1 and Issue 5.

**NOTE**

If you set a different language to the version of the Psion programs
which you are using, then you may find that the DATE
function in Archive and Abacus fails.

**CROSS-REFERENCE**

:ref:`language`
and :ref:`language-dlr` allow you to find out
about the current language. :ref:`tra` allows you to
set the various message tables also. See
:ref:`kbd-table` and
:ref:`set-language`.

