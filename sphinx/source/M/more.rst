..  _more:

MORE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MORE [#ch,] filename                                             |
+----------+-------------------------------------------------------------------+
| Location |  MORE (DIY Toolkit - Vol V)                                       |
+----------+-------------------------------------------------------------------+

This command adds a quite sophisticated file viewing facility to the QL
which far surpasses the simple Toolkit II VIEW command.

In its simplest
form, MORE will open a channel to the specified filename (adding the
data default directory if the file does not exist) and display it in the
specified window channel (default #1). If #ch does not refer to a window
or is #0, then bad parameter will be reported. The file will then be
displayed in the specified channel, one window full at a time. #0 is
used by the command to display the length of the file in bytes and the
number of the last byte displayed in the window.

You can move around the
file by using the following keys:

- <ENTER> - Allows you to enter a file position to look at (this will be the first byte displayed in the window).
- <ALT><UP> - This moves back up the file one page at a time.
- <ALT><DOWN> - This moves down the file one page at a time.
- <DOWN> - Move down the file one line.
- <ESC> - Leave MORE.

MORE can however, also be used to look at the QL's memory (or that on a networked computer) by using the
MEM device. In this mode, only the address of the last byte on screen is
shown in #0 - there is no file length. For example::

    MORE #2,MEM

will allow you to use MORE to page through the whole of the QL's
memory.

::

    MORE #2,n2_MEM

allows you to page through the whole of another computer's memory.

::

    OPEN #3,MEM7_60p: PRINT #3,'Hello World': CLOSE #3

creates a permanent buffer (MEM7) and stores two words in it. If you follow the above by::

    MORE #2,MEM7

then you will be able to look at the contents of the buffer MEM7.

**NOTE**

Trying to use MORE on anything other than files or MEM
devices (for example on named pipes) will cause problems - press
<CTRL><SPACE> a few times to escape from this.

**CROSS-REFERENCE**

Refer to the Devices Appendix for more details on MEM.

Compare::

    COPY flp1_test_bas to SCR

and::


    VIEW flp1_test_bas

