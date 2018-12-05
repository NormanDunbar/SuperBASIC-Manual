..  _open-dir:

OPEN\_DIR
=========

+----------+------------------------------------------------------------------+
| Syntax   | OPEN\_DIR #channel, device\_directory  or                        |
|          |                                                                  |
|          | OPEN\_DIR #channel, [device\_]directory(Toolkit II only)         |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

This command is a specialised version of OPEN which is aimed at
allowing you to read directories of any given drive device. The
directory of a drive contains a copy of every file header which has ever
been created on that medium.

When a file is deleted, its entry is
blanked out (with zeros) in the directory, thus enabling recovery
programs to actually still read the file (provided that nothing else has
been written to the sectors where it was stored). It can therefore be
very useful to access these directories, for example to provide the user
with a selection of files to choose from.

It is however important to
differentiate between directories and the output from the DIR
command!

On Level-2 and Level-3 device drivers, it is quite easy to
access a directory as the directory is stored in a file. For example, on
a floppy disk, try::

    COPY flp1_ TO scr

this will show the directory file.

Sub-directories are similar in that after the command::

    MAKE_DIR flp1_Quill_

the file flp1_Quill will be created which contains a copy of all of
the file headers for the files within that sub-directory.

Standard
device drivers on the other hand are another kettle of fish, in that
they allow you to create a file without any name. For example::

    SAVE mdv1_

If you then::

    COPY mdv1_ TO scr


you will see that this is exactly the same as if you had used::

    SAVE mdv1_boot

(apart from the name of the file).

Such files are not revealed by DIR
and can be used as a form of copy-protection by some programs. Because
of this, you might suffer from a 'Not Found' (-7) error if you tried to::

    COPY flp1_ TO scr

from a disk with a Level-1 device driver. A disk
created on a level-1 driver does not look different to a level-2 driver.

If a file with a zero length name was created under a level-1 driver,
then this file will only be accessible under the same driver level. To
use the command OPEN\_DIR, you will need to supply the intended channel
number which must be an integer in the range 0...32767. As with OPEN
this must be kept as low as possible. After this, comes the name of the
directory to be opened. This should generally be simply the name of the
device to be accessed, such as::

    OPEN_DIR #ch,mdv1_

OPEN\_DIR works correctly with standard device drivers even if there
is a file on the drive without a name, eg. mdv1\_.

If you have Level-2
device drivers, sub-directories may be accessed by providing the name of
the drive plus the name of the sub-directory, for example::

    OPEN_DIR #3,flp1_Quill

If Toolkit II is present, the default data device is supported (see
DATAD$), although a directory will still need to be provided, therefore
to simply access the default data directory, you will need to use::

    OPEN_DIR #ch,''

Having opened the directory, you can then examine the file header for
each file which has been stored on that drive by fetching blocks of 64
bytes from the channel at a time and examining each block per file.

**Example**

A short program which will provide a more detailed directory listing of
any device::

    100 WINDOW 448,200,32,16:PAPER 0:MODE 4:CLS
    110 INK 7
    120 INPUT 'Read directory of which device? - ';dev$
    130 CLS:PRINT 'Directory of ';dev$
    140 PRINT 'Filename';TO 40;'File length';TO 54;'Update date'
    150 head_start=0
    160 INK 4
    170 OPEN_DIR #3,dev$:no_files=FLEN(#3)/64
    180 FOR listing=1 TO no_files
    190   BGET #3\head_start+0,flen1,flen2,flen3,flen4,faccess,ftype
    200   flength=flen4+flen3*2^8+flen2*2^16+flen1*2^24-64
    210   IF flength>0
    220     GET #3\head_start+14, File$
    230     BGET #3\head_start+52,fdate1,fdate2,fdate3,fdate4
    240     fdate=fdate4+fdate3*2^8+fdate2*2^16+fdate1*2^24
    245     IF LEN(File$)=0:File$='<Un-named>'
    250     IF ftype<255
    260       PRINT File$;TO 40;flength;TO 54;DATE$(fdate)
    270     ELSE
    280       PRINT File$&'->'
    290     END IF
    300   END IF
    310   head_start=head_start+64
    320 END FOR listing
    330 CLOSE #3
    340 INK 7:PRINT 'End of Listing'

**NOTE 1**

The OPEN\_DIR command will close a channel which is already open with
the same channel number prior to opening the new channel - do not try to
OPEN\_DIR #0 unless you have read the notes to OPEN!

**NOTE 2**

On QL ROMs (pre MG) there is a maximum of 32767 OPENs (in total) in a
session.

**NOTE 3**

If you specify a device which is not actually used for the storage of
files (for example::

    OPEN_DIR#3,scr
    OPEN_DIR#3,pipe_1000

then this command has exactly the same effect as the OPEN command.

**NOTE 4**

If the specified directory actually points to a non-directory file (or
the file does not even exist), then OPEN\_DIR will actually open the
directory in which that file is located, for example, if the directory
flp1\_TK\_ contained the file flp1\_TK\_FN\_cde::

    OPEN_DIR#3,flp1_TK_FN_cde
    OPEN_DIR#3,flp1_TK_FN
    OPEN_DIR#3,flp1_TK

would all have exactly the same effect.

**NOTE 5**

Because of the way in which Level-2 and Level-3 device drivers work,
provided that you only use the name of an actual directory (or
sub-directory) as the parameter, you could actually use OPEN or OPEN\_IN
instead of OPEN\_DIR, but this has its limits, in that it would be
useless with standard device drivers and creates havoc if the name of a
non-directory file is supplied.

**NOTE 6**

Except under SMS, if a channel has been opened with OPEN\_DIR
to a main directory, no other channel can access that directory at the
same time. Several channels can however be open to the same
sub-directory (a bug perhaps) or to a sub-directory further down the
tree, which for example allows::

    100 OPEN_DIR #3,flp1_
    110 OPEN_DIR #4,flp1_TK
    120 OPEN_DIR #5,flp1_TK

but not::

    100 OPEN_DIR #3,flp1_TK
    110 OPEN_DIR #4,flp1_

This also has the result that whilst a channel which has been opened
with OPEN\_DIR is open to a main directory, commands such as DIR, WDIR,
WDEL etc. will report 'in use' as they cannot access the directory
themselves. The result of this (combined with the operation of the
OPEN\_DIR command) makes it actually possible to have two channels open
to the main directory, by ensuring that the filename passed to the
OPEN\_DIR commands does not exist on the drive, for example::

    OPEN_DIR #3,flp1_test
    OPEN_DIR #4,flp1_test

will leave both channels #3 and #4 open to the main directory (flp1\_).

Under SMS you can have several channels open to the same directory
thereby avoiding these problems.

**CROSS-REFERENCE**

Please see :ref:`open`. Commands such as
:ref:`flen`, :ref:`fgeth-dlr` and
:ref:`headr` allow you to examine parts of each
files header - see :ref:`fgeth-dlr` for details of the
file header. :ref:`fop-dir` is an error trapped
version of :ref:`open-dir`. The Minerva variant
of :ref:`open`, :ref:`open-in`
and :ref:`open-new` can all be made to work in a
similar way to :ref:`open-dir`.

--------------


