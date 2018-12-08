..  _view:

VIEW
====

+----------+------------------------------------------------------------------+
| Syntax   | VIEW [#channel,] text\_file  or                                  |
|          |                                                                  |
|          | VIEW \\channel, text\_file                                       |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This command reads the contents of the given text\_file line by line
and prints it to the given channel (default #1). If a line is longer
than the window, it is not split and continued in the next line (as
PRINT would do) but truncated. The second syntax allows you to open a
temporary channel to which the output will be sent, for example you
could use::

    VIEW \con,text_file

or::

    VIEW \ram1_test,flp1_text_file

Note that the latter is the same as::

    COPY flp1_text_file TO ram1_test

Lines in a text file are separated by line feed characters <LF>, ie.
CHR$(10). If output is sent to a window, then when a window page is
full, VIEW generates a <CTRL><F5>, and waits for a keypress to continue
VIEWing. Sub-directories and default directories are supported by this
command, which will look on the default data directory for the given
file if necessary (see DATAD$).

**NOTE**

If the final line in the file being VIEWed does not contain a line feed,
it will not appear on screen.

**WARNING**

There is a possibility that if a file is longer than 32767 characters
and does not include a newline character, the system may crash!

**CROSS-REFERENCE**

:ref:`spl` file TO #1 copies all
kinds of files to a window, for example without truncating lines.

Compare :ref:`copy` and
:ref:`more`.

