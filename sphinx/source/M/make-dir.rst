..  _make-dir:

MAKE\_DIR
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  MAKE\_DIR subdirectory                                           |
+----------+-------------------------------------------------------------------+
| Location |  Level-2 and Level-3 Drivers, THOR XVI                            |
+----------+-------------------------------------------------------------------+

The command MAKE\_DIR creates a sub-directory which allows a group of
files to be regarded as one unit when the contents of a medium are
listed. Operations other than the standard DIR, WDIR, WSTAT and WDEL,
are not affected. A file belongs to a sub-directory if the
sub-directory's name appears as a prefix of the file, whether the file
was created before or after the sub-directory.

Sub-directories are only
supported on Level-2 (or higher) floppy disks, hard disks and ramdisks.

A sub-directory name can be any name but any underscore at its end will
be ignored by MAKE\_DIR.

If there is no medium in the given device, or
if you do not specify a device name, the current default data device
will be used (see DATAD$).

Sub-directories are identified by a "->" in
directory listings and programs can identify them by examining their
file type (255).

Empty sub-directories can be deleted as normal files,
but a sub-directory which is not empty, cannot be deleted: error -9 (in
use) will be reported. Actually, sub-directories are normal files which
hold a list of the files which are contained within them. The list
consists of the standard file headers of these files, each being 64
bytes long.

A sub-directory file never decreases in length if a file in
the sub-directory has been deleted, instead, the file header is just
marked as deleted by setting the name to a zero string.

All normal
operations are allowed on sub-directory files (except RENAME), and they
can be accessed using OPEN\_DIR and FOP\_DIR.

**Example**

If FLP1\_ contains an empty disk and we then save the current SuperBASIC
program as flp1\_my\_prog\_bas and a backup as flp1\_backup\_bas::

    SAVE flp1_my_prog_bas
    SAVE flp1_backup_bas

a directory of flp1\_, produced with WDIR flp1\_ (for example), shows
the following contents::

    my_prog_bas
    backup_bas

Now, we create the sub-directory my (or my\_) with::

    MAKE_DIR flp1_my_

or::

    MAKE_DIR flp1_my

(both forms are equivalent) and look at the directory again::

    my ->
    backup_bas

MAKE\_DIR created a new file "my" (not "my ->") which is
marked as a sub-directory with the "->" sign by the DIR, WDIR
and WSTAT commands. The file type of my is 255, PRINT FTYP(\\flp1\_my)
will return that.

But where is my\_prog\_bas? It was moved into the
sub-directory my\_ and DIR flp1\_my\_ will show it again.

**NOTE 1**

The QUBIDE interface does not allow you to use MAKE\_DIR to create a
sub-directory if any files already exist which would fall into that
sub-directory.

**NOTE 2**

The level-2 device drivers introduced a new standard for subdirectories
- other methods which were implemented in the past are not recognised
in this (e)book.

**NOTE 3**

If a disk with a sub-directory is read by a level-1 device driver, the
sub-directory appears as just another file and files which have been
added to a sub-directory after its creation cannot be accessed or seen
by the system. However, if a file had been created before the
sub-directory, the level-1 device driver finds this file just as if the
sub-directory did not exist. So, if you prepare a disk which should also
be readable on level-1 device drivers, either don't use sub-directories
or create them after everything else.

**NOTE 4**

Sub-directory names longer than 27 characters on Toolkit II may hang up
the SuperBASIC interpreter. Since the system does not treat nested
sub-directories differently, the above warning applies to long
sub-directory prefixes as well. However, this lock up will only occur
when creating sub-directories not when using them. This problem is
fixed on SMS v2.85.

**NOTE 5**

A filename cannot be longer than 36 characters and as described above,
sub-directories are prefixes which reduce the maximum possible length of
a filename. If you try to create a file (eg. SAVE) in a sub-directory so
that the combined length of the file name and sub-directory are longer
than 36 characters, a 'not found' error will be returned.

**WARNING 1**

It is possible to create a sub-directory so that it cannot be removed
any more **(do not try this on a hard disk, you have been warned)**\ ::

    SAVE test_
    MAKE_DIR test

The file test\_ (with an underscore) has been moved into the test directory, but it cannot
be deleted to empty test. - This has been fixed in drivers later than
version 2.28.

**WARNING 2**

::

    MAKE_DIR net_
    MAKE_DIR "net"

and similar commands lock-up the machine, so if you want you create a sub-directory called 'net' in the
current directory, use::

    MAKE_DIR DATAD$ & "net".

**WARNING 3**

::

    MAKE_DIR flp1__
    MAKE_DIR flp1___

and similar commands could create recursive directories until this was fixed in SMS v2.77.

**CROSS-REFERENCE**

:ref:`fmake-dir` is a syntactical variation of
:ref:`make-dir`.
:ref:`open-dir` and
:ref:`fop-dir` allow you to read directories of
disks as well as sub-directories on level-2 drivers. The
:ref:`dup`, :ref:`ddown`,
:ref:`dnext` and
:ref:`data-use` commands are used to move around
in a sub-directory tree. See :ref:`fop-dir` for a
program which lists a sub-directory tree. To enable programs to read
sub-directories which have not been written for that purpose, the
DEV\_ device exists (see
:ref:`dev-use`). The only legal way of
identifying a sub-directory is by examining its file type as returned by
:ref:`ftyp` or
:ref:`file-type` for example.

