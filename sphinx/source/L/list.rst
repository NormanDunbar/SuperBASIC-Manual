..  _list:

LIST
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LIST [#ch,] [range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*` ]    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command lists (in ASCII form) the specified range of the currently
loaded SuperBASIC program to the specified channel (default #2). Range
must be in the form: [[start\_line] TO [end\_line]].

The default
start\_line is 1 and the default end\_line is 32767, therefore if no
range is given, the LISTing range defaults to: 1 TO 32767.

Except under
SMS, when the last line of the given range is reached, a table is set up
which stores the current list range. This list range contains a list of
the lines of the program which are currently shown in #2 - if you alter
one of these lines (for example with EDIT or DLINE), then the listing in
#2 is re-drawn to reflect the change. Alterations to lines outside the
list range will have no effect.

Again, except under SMS, special note is
also taken of the program line just above the displayed listing, and the
program line just below the displayed listing - if either of these lines
is altered, then the display will scroll accordingly to show the newly
altered line on screen.

**Examples**

::

    LIST #3

List the whole of the program in #3

::

    LIST 1

List program line 1 in #2

::

    LIST 100,1000 TO

List lines 100 and from 1000 onwards in #2

::

    OPEN#3,SER1: LIST#3: CLOSE#3

will list the current program to a printer connected to ser1.

**NOTE 1**

Except under SMS, you may sometimes find a large chunk of the program
listing scrolling before your eyes if you alter a line outside the range
displayed in #2. This should not create any problems and generally
occurs when you press Break before the List Range has been updated.

**NOTE 2**

Version 2.13 (and later) of Toolkit II alters this command so that if
you are using LIST to output to a file, any errors will be reported
(such as 'Device Full' or 'Not Complete').

**NOTE 3**

Prior to SMS v2.67 LIST #ch where #ch does not exist would attempt to
SAVE the file.

**CROSS-REFERENCE**

When :ref:`list`\ ing to a file, this command is the
same as :ref:`save`.
:ref:`dline`, :ref:`ed`,
:ref:`edit`, and :ref:`renum` are
other commands for dealing with a SuperBASIC program in memory.

