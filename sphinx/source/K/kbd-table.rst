..  _kbd-table:

KBD\_TABLE
==========

+----------+------------------------------------------------------------------+
| Syntax   | KBD\_TABLE num     or                                            |
|          |                                                                  |
|          | KBD\_TABLE kcode  (SMS only)                                     |
+----------+------------------------------------------------------------------+
| Location | ST/QL (Level C-17 Drivers onwards), SMS (v2.31+)                 |
+----------+------------------------------------------------------------------+

Various keyboards can be attached to a computer depending on which
country the computer is being used in. It is therefore necessary to tell
the operating system which keyboard layout is to be used so that it can
recognise which keys are being pressed.

The command KBD\_TABLE does just
that. num will have one of six possible values depending on the keyboard
layout (under SMSQ/E this equates to the international dialling code for
that country) or you can use the second variant to pass up to four
letters representing the Car Registration Letters for that country (the
fourth letter is used where that country has more than one language):

+-----+-------+-------------+
| Num | Kcode | Language    |
+=====+=======+=============+
| 33  | F     | French      |
+-----+-------+-------------+
| 34  | E     | Spanish     |
+-----+-------+-------------+
| 44  | GB    | English     |
+-----+-------+-------------+
| 45  | DK    | Danish      |
+-----+-------+-------------+
| 46  | S     | Swedish     |
+-----+-------+-------------+
| 47  | N     | Norwegian   |
+-----+-------+-------------+
| 49  | D     | German      |
+-----+-------+-------------+

Num can also be used as a pointer to a user-defined keyboard
table for countries which are not covered. Details are beyond the scope
of this book. A description of how to create new keyboard tables and
languages appears in IQLR Volume 5 Issue 1 and 5.

**ST/QL NOTES**

The values for num must be one of the following values: 0 English 1
German 2 French 3 Norwegian 5 Danish 6 Spanish

**CROSS-REFERENCE**

:ref:`set-language` is similar for the
THOR XVI. :ref:`language` and
:ref:`language-dlr` allow you to enquire about a
language. :ref:`lang-use` allows you to change
the language used by the system. :ref:`tra` allows you
to change the output to a printer.

--------------


