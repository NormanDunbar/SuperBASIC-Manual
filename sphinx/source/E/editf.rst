..  _editf:

EDITF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  EDITF ([#ch,] {default \| default$} [,maxlen%])                  |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function is similar to EDLINE$. However, EDITF is intended solely for asking
the user to enter a floating point number. The specified default (which may be
given as a number or a string) is printed at the current text cursor position
in #ch  (default #1) and allows you to edit it. The parameter maxlen%  dictates
the maximum number of characters allowed (this defaults to the amount set when
the Turbo Toolkit is configured). The edited result is returned when <ENTER>
is pressed. If the string contains a nonsensical value when <ENTER> is pressed,
a warning beep is sounded.

**NOTE**

On non-SMS machines, a buffer full error could be reported if an
attempt was made to enter a string longer than 118 characters, or the
length of the longest SuperBASIC line listed or edited to date,
whichever is longer.

**CROSS-REFERENCE**

See :ref:`edline-dlr`.
:ref:`edit-pct` and :ref:`edit-dlr`
are also useful.

--------------


