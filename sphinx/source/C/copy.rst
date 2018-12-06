..  _copy:

COPY
====

+----------+-------------------------------------------------------------------+
| Syntax   | COPY file1 TO file2  or                                           |
|          |                                                                   |
|          | COPY [file] [TO file2] (Toolkit II)  or                           |
|          |                                                                   |
|          | COPY file1 [,file2 [,file3...]] {TO \| !} fileb (THOR XVI)        |
+----------+-------------------------------------------------------------------+
| Location | QL ROM, Toolkit II, THOR XVI                                      |
+----------+-------------------------------------------------------------------+

The command COPY duplicates file1, so that file2 is an exact copy. The
parameters can also be a device (eg. ser1, con, scr, scr\_400x20) or, if
you have Toolkit II installed, a channel (eg. #3) can be used for the
second parameter.

If Toolkit II is present, COPY supports the default devices and
sub-directories. COPY will look for the file to be copied on the default
data device if necessary (see DATAD$).

The rules for determining the destination parameter can be somewhat
complex under Toolkit II:

(1) If no device is given, but a filename is specified, then Toolkit II
looks at the first parameter. The destination device is then assumed to
be the same as the source device (ie. the device name specified as part
of the first parameter, or the default data device - see DATAD$).

Under SMS, it will use the default data device whether or not the first
parameter contains a device.

(2) If the second parameter is omitted, then again Toolkit II looks at
the first parameter. The same filename as for the first parameter will
be used. If a device is given in the first parameter, then this is used
as the destination device (unfortunately meaning that Toolkit II tries
to copy the file onto itself!). On the other hand, if no device was
specified, then the default destination device will be used (see
DESTD$).

Under SMS, if a device is specified in the first parameter, SMSQ/E
(v2.85 at least) tries to copy the file to the default destination
device without a filename! Normally unless the default destination
device is either PAR or SER, this will report an error 'is in use'.

(3) If a second parameter is given which includes a device name, then
this is used!

If the destination is an existing file, unlike the normal ROM COPY
command, Toolkit II will not break COPY with the error -8 (already
exists), but instead it will print: >file<exists, OK to overwrite..Y or
N? in channel #0 and wait for the user to press either <Y> or <N> -
<ESC> and <CTRL><SPACE> mean <N> here.

**Examples**

Assuming that the default data device is flp1\_ and the default
destination device is ram2\_ (using Toolkit II or SMS implementation):

+-------------------------------------+---------------------------------------------------------------------+
| Command                             | Effect                                                              |
+=====================================+=====================================================================+
| COPY mdv1\_quill TO flp1\_quill     | Copies mdv1\_quill to flp1\_quill                                   |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas, ram2\_tmp     | Copies ram1\_prog\_bas to ram2\_tmp                                 |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas, scr\_200x100  | Copies ram1\_prog\_bas to a window                                  |
+-------------------------------------+---------------------------------------------------------------------+
| COPY prog\_bas, ser1                | Copies flp1\_prog\_bas to ser1                                      |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ser2 TO ram1\_prog\_bas        | Copies data from ser2 to a file                                     |
+-------------------------------------+---------------------------------------------------------------------+
| COPY con TO ser                     | Copies everything typed to ser1                                     |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas                | Tries to copy ram1\_prog\_bas to itself unless on SMS               |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas                | Tries to copy ram1\_prog\_bas to ram2\_ and will report an error    |
+-------------------------------------+---------------------------------------------------------------------+
| COPY prog\_bas                      | Copies flp1\_prog\_bas to ram2\_prog\_bas                           |
+-------------------------------------+---------------------------------------------------------------------+
| COPY ram1\_prog\_bas TO #2          | Copies ram1\_prog\_bas to a channel                                 |
+-------------------------------------+---------------------------------------------------------------------+

**NOTE 1**

The TO separator can be replaced by a comma ',' (although note the THOR
XVI variant!).

**NOTE 2**

Each file includes a file header of 64 bytes to store supple-mentary
information such as the time of the last update, file type, length and
much more. Without Toolkit II, COPY will always copy the header if a
file is copied. The Toolkit II COPY command does not copy the header to
serial devices (eg. ser) if this is specified as the destination.

**NOTE 3**

COPY without any parameters is allowed with Toolkit II, but it can cause
problems (at least in versions up to v2.28 Toolkit II and v2.85 SMS)

As an exception to rule 2, when first used it would appear to try to
copy the file "" on DATAD$ onto itself. On systems without level-2
drivers, such files can exist, but have no special function, whereas on
level-2 drivers, these files contain the sub-directories. Thus, with the
standard combination of Toolkit II and level-2 drivers installed, a pure
COPY normally breaks with error -9 (in use) (see FMAKE\_DIR for the
reason).

However, due to a bug in current versions of Toolkit II, when first used
it may report error -15 (bad parameter), in which case it will have left
the file flp1\_ open and prevent most of any further access to that
device (unless you can close the channel with CLOSE% or a desktop).

**NOTE 4**

On SMS pre v2.58, if you used COPY and were asked if you wanted to
overwrite the file, and answered N, an error code was returned.

**THOR XVI NOTES**

The THOR XVI (v6.41 and later) supports the third variant of COPY. This
allows you to merge several files:

COPY flp1\_texta,flp1\_textb TO flp2\_Book will create a new file
flp2\_Book made up of the merged files flp1\_texta and flp1\_textb. The
headers will (of course) not be copied.

If you alter the TO delimiter to !, ie: COPY flp1\_texta,flp1\_textb !
flp2\_Book

then it is assumed that fileb already exists and file1, file2 and file3
are all appended to it.

**CROSS-REFERENCE**

:ref:`spl-use` and
:ref:`dest-use` set the destination device.

See :ref:`copy-n` and
:ref:`copy-h` for copying file headers and
:ref:`copy-o` on how to force overwriting.

:ref:`spl` performs a background copy (ie. it
multitasks).

See :ref:`append` which is similar to the THOR
variant.

