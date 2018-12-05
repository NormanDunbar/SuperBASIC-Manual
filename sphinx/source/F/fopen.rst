..  _fopen:

FOPEN
=====

+----------+------------------------------------------------------------------+
| Syntax   | FOPEN (#ch, name) or                                             |
|          |                                                                  |
|          | FOPEN (name)                                                     |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This function is designed to allow you to access files safely without
causing errors which force a program to stop.

If the first variant of
FOPEN is used, this is actually very similar to the command OPEN in
operation, except that if for some reason opening the specified channel
(#ch) with the specified name would cause an error, FOPEN returns the
relevant error code. If the specified channel is successfully opened,
then FOPEN returns 0.

By contrast, if the second variant of the command
is used, where no specific channel number is used, if successful, FOPEN
will return a positive number representing the number of the next
available channel (ie. the number of the lowest entry in the channel
table which is empty).

If a negative number is returned, this is the
appropriate error number, allowing the programmer to take any necessary
action (such as requesting the user to input a new file name).

**Examples**

::

    ERRno = FOPEN(#3,scr_448x200a32x16)
    Chan = FOPEN('flp1_Input_dat'): IF Chan>0 THEN INPUT #Chan,x

**NOTE 1**

All versions of this command (other than v2.28 of Toolkit II or later)
can be confused by filenames which exceed 36 characters, in which case
FOPEN will return 0. On later versions, FOPEN supports 41 character
filenames (including any default directory).

**NOTE 2**

Although FOPEN opens a file for both reading and writing, it will only
return an error if the file does not already exist or is in use. It does
not check whether the file is read only. Use FOP\_NEW or DMEDIUM\_RDONLY
for this. If you do not check whether the file is read only, an error
will only be reported if you try to write to the file!!

**CROSS-REFERENCE**

:ref:`ernum` contains details of the various error
messages. :ref:`when--error` allows you to
error trap a complete program. Also see
:ref:`fop-dir`,
:ref:`fop-in`,
:ref:`fop-over` and
:ref:`fop-new`. Also see
:ref:`open`. :ref:`ftest` allows
you to test the status of a file without (explicitly) opening a channel.

--------------


