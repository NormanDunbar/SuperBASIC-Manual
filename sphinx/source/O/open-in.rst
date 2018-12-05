..  _open-in:

OPEN\_IN
========

+----------+------------------------------------------------------------------+
| Syntax   | OPEN\_IN #channel, device\_filename  or                          |
|          |                                                                  |
|          | OPEN\_IN #channel, [device\_]filename (Toolkit II only)  or      |
|          |                                                                  |
|          | OPEN\_IN #channel, device\_filename, type (Minerva v1.80+ only)  |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

This command is a specialised version of OPEN which is aimed at
allowing you to read data from files. This opens the specified channel
(#channel must be an integer in the range 0...32767) for input only to
the specified filename on the given device.

Any number of channels may
be linked to a file using OPEN\_IN, although if you try to use any other
type of OPEN call to that filename, the error 'in use' will be reported.

The Toolkit II variant of this command supports the default data device
if necessary (see DATAD$), but in any case, if the file does not exist
(either on the specified device or on the default data device), the
error 'Not Found' (-7) will be reported.

**NOTE 1**

OPEN\_IN will close a channel which is already open with the same
channel number prior to opening the new channel - do not try to OPEN\_IN
#0 unless you have read the notes to OPEN!

**NOTE 2**

On AH ROMs, if two tasks tried to read the same file at the same time,
the second task was likely to miss the start of the file and read the
directory header instead.

**NOTE 3**

On QL ROMs (pre MG) there is a maximum of 32767 OPENs in a session.

**NOTE 4**

If instead of device\_filename, another type of device is used, such as
scr\_, OPEN\_IN has the same effect as OPEN.

**MINERVA NOTES**

On v1.80 and later, a third parameter is supported by OPEN\_IN
as with OPEN. This means that this command (if the third parameter is
used) has exactly the same effect as OPEN.

**CROSS-REFERENCE**

:ref:`fop-in` is an error trapped equivalent to
this command. :ref:`open-dir` allows you to
access directories on drives. :ref:`open` contains a
general description of all the open types.
:ref:`open-new` and
:ref:`open-over` are also linked with this.

--------------


