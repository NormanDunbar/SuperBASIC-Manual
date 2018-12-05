..  _open-new:

OPEN\_NEW
=========

+----------+------------------------------------------------------------------+
| Syntax   | OPEN\_NEW #channel, device\_filename  or                         |
|          |                                                                  |
|          | OPEN\_NEW #channel, [device\_]filename(Toolkit II only)  or      |
|          |                                                                  |
|          | OPEN\_NEW #channel, device\_filename, type (Minerva v1.80+ only) |
+----------+------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                               |
+----------+------------------------------------------------------------------+

This command is yet another specialised version of OPEN. This time it
is aimed at providing a means of creating a new filename on the
specified device and opening a specified channel (#channel must be an
integer in the range 0..32767) to that filename for output.

If Toolkit
II is present, OPEN\_NEW supports the default data device (see DATAD$),
however in any case if the device (or default data device) does not
contain a formatted medium, the error 'not found' (-7) will be reported.
An error will also be reported if the medium is read only.

Without
Toolkit II, if the filename already exists, then the error 'already
exists' will be generated. On the other hand, Toolkit II will show the
familiar 'OK to Overwrite?' prompt.

Once the channel is open, any
attempt to open another channel to that same filename at the same time
will report an error 'In use'.

**Example**

A simple interactive copying routine::

    100 INPUT #0,'COPY :-'!in$!'=>'!out$
    110 OPEN_IN #3,in$
    120 OPEN_NEW #4,out$
    130 REPeat copy_loop
    140   IF EOF(#3):EXIT copy_loop
    150   a$=INKEY$(#3)
    160   PRINT a$;:PRINT #4,a$;
    170 END REPeat copy_loop
    180 CLOSE #4,#3
    190 PRINT #0,'Copying complete'

**NOTE 1**

The OPEN\_NEW command will close a channel which is already open with
the same channel number prior to opening the new channel - do not try to
OPEN\_NEW #0 unless you have read the notes on OPEN!

**NOTE 2**

If instead of device\_filename, another type of device is used, such as
scr\_, OPEN\_NEW has the same effect as OPEN.

**NOTE 3**

In version 2.05 of Toolkit II, if the filename already exists, the
channel may be left open.

**NOTE 4**

Similar problems exist with OPEN\_NEW to those encountered with SAVE
when trying to write to a write-protected microdrive cartridge.
Unfortunately however, the problem is made worse by the fact that the
problem is not revealed when the channel is opened. Instead 'bad or
changed medium' is only displayed when the file is written to (ie. when
512 characters have been written to the channel, or the channel is
CLOSEd).

**CROSS-REFERENCE**

:ref:`fop-new` is an error trapped function which
is equivalent to this command. :ref:`open-dir`
allows you to access directories on drives.
:ref:`open` contains a general description of all the
open types. :ref:`open-in` and
:ref:`open-over` are also linked with this.

--------------


