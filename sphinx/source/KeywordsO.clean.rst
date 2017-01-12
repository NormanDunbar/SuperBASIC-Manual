
==========
Keywords O
==========


..  _odd:

ODD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ODD (number)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

This function checks if the integer part of number can be divided by
two without remainder, ie. whether it is an odd number or not. If the
number is odd, the function will return 1, otherwise it will return 0.
The ODD function could easily be duplicated in BASIC by the following
function:: 

    10 DEFine FuNction ODD (number%) 
    20   RETurn number% MOD 2 
    30 END DEFine ODD

--------------


..  _off:

OFF
===

+----------+-------------------------------------------------------------------+
| Syntax   |  OFF                                                              |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This is a constant which returns 0. OFF and ON are intended to make
listings more readable.

**Example**

::

    FREEZE OFF

**CROSS-REFERENCE**

:ref:`on`, :ref:`false-pct`,
:ref:`true-pct`, :ref:`set`

--------------


..  _ojob:

OJOB
====

+----------+-------------------------------------------------------------------+
| Syntax   || OJOB (job\_ID)  or                                               |
|          || OJOB (jobnr, tag)  or                                            |
|          || OJOB (jobname)                                                   |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function will return the job\_id of the 'owner' of the given job.
Normally the owner of a job is the job which initiated it. So, if job 1
creates job 2 then job 1 is the owner of job 2. However, because jobs
can execute other jobs without becoming their owner, generally the owner
of a job is the job that will kill that job when it itself is removed. A
negative job\_ID points to the job which calls OJOB.

**CROSS-REFERENCE**

:ref:`job-dlr`, :ref:`nxjob` and
:ref:`pjob` return other information about a job.
:ref:`jobs` lists all jobs.

--------------


..  _on:

ON
==

+----------+-------------------------------------------------------------------+
| Syntax   |  ON                                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This is a constant which returns 1.

**Example**

::

    FREEZE ON

**CROSS-REFERENCE**

:ref:`off`, :ref:`false-pct`,
:ref:`true-pct`, :ref:`set`

--------------


..  _on...go--to:

ON...GO TO
==========

See :ref:`on...go--sub`.

--------------


..  _on...go--sub:

ON...GO SUB
===========

+----------+-------------------------------------------------------------------------------+
| Syntax   || ON condition GO TO line\ :sup:`1` :sup:`\*`\ [,line\ :sup:`i`]\ :sup:`\*` or |
|          || ON condition GO SUB line\ :sup:`1` :sup:`\*`\ [,line\ :sup:`i`]\ :sup:`\*`   |
+----------+-------------------------------------------------------------------------------+
| Location || QL ROM                                                                       |
+----------+-------------------------------------------------------------------------------+

The QL supports a structure which enables the program to jump to
specific lines depending upon the value of a variable. condition must be
an integer expression which returns a value of one or more. After the
command GO TO or GO SUB must appear a list of line numbers to jump to
depending on the value of the condition. The value returned is then used
to determine which of these line numbers will be jumped to, by counting
the different options. If the result of the condition is zero, or more
than the number of options, then the error 'Out of Range' will be
returned. If ON...GO SUB is used, then when a RETurn is executed from
within the sub-routine, the program will continue from the statement
following ON..GO SUB.

**Example**

A procedure to print out the locations in an adventure might look like
this::

    100 no_of_locations=3 
    110 start=0 
    120 PRINT_LOC 2 
    130 DEFine PROCedure PRINT_LOC (xa) 
    140   IF xa=0 OR xa>no_of_locations THEN PRINT 'Undefined Location':RETurn 
    150   ON xa+start GO SUB 170,180,190 
    160   PRINT 'What now?':RETurn 
    170   PRINT 'This is location 1':RETurn 
    180   PRINT 'This is location 2':RETurn 
    190   PRINT 'This is location 3':RETurn 
    200 END DEFine

For a simpler (and clearer) way of writing this PROCedure, please refer
to the example given for SELect ON.

**NOTE**

ON can also be used with the SELect ON structure - please refer to
:ref:`select--on` for further details.

**CROSS-REFERENCE**

These two commands can generally be replaced either by a calculated 
:ref:`go--sub` or :ref:`go--to`
statement, or the :ref:`select--on` structure.

--------------


..  _open:

OPEN
====

+----------+-------------------------------------------------------------------+
| Syntax   || OPEN #channel, device channel=0..32767  or                       |
|          || OPEN #channel, device, type    (Minerva v1.80+ only)             |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

This is the general command used to open a channel to a device for
input and/or output, so that data can be read from and written to the
specified device. The channel number can be any integer greater than or
equal to zero and should be kept as small as possible because QDOS
allocates roughly 40 bytes for each possible channel number below the
highest one. So if you open channel #1000, 40K of memory would be lost -
only badly written programs need a thousand channels. 

After the channel
has been OPENed, if a program needs to access that device in the future,
it can do so by passing that channel number to the relevant keyword.

Actually, a dozen channels should be sufficient and the Turbo compiler
strictly limits the highest channel number to 15, while QLiberator
allows you to configure this to the user's needs via a $$chan directive.
The compilers allocate memory for all of the channels when a job is
created so that the channel table of the job is independent of other
jobs and cannot be extended or decreased. 

Under the interpreter, the
channel table can be freely extended but not decreased - only NEW and
KILL\_A clear the channel tables. 

When talking about devices, it is
necessary to note the difference between drives (file drivers) and
serial devices: 

- A drive is a medium where files can be stored (eg.
  floppy disks or microdrive cartridges). Since there can always be
  several drives of a given type, drive names contain a drive number from
  1 to 8. Data is always stored in a stream of bytes. Data can be read in
  any order and from any position. 

- On the other hand, with a serial
  device, data has to be read as it comes in: byte by byte or in larger
  pieces. Another type of device is a screen device which is a defined
  section of the TV or Monitor display itself. 

There are also mixtures between all of these types. 

The difference between the device types
becomes obvious when looking at the operations which can be performed on
a device: the files on a drive can be listed in a directory and colours
are only available for windows, just to give a few examples. Other
operations (especially basic read and write operations) are independent
of the device, which is a characteristic of QDOS. 

This so-called device
independence makes it easy to re-direct basic input or output from a
program because the program has no need to know specifics about the
device other than its name and/or channel number. If you have Toolkit II
installed OPEN supports sub-directories and default devices when used on
drives. OPEN will look in the data directory (see DATAD$) for the given file if no
device is specified. 

Basic details of the various standard devices
supported by the QL follow (further details appear in the Drivers
Appendix):

+-----------------+---------+-----------------------------------------------------------+
| Device Type     | Name    || Typical uses                                             |
+=================+=========+===========================================================+
| Serial device   | ser     || Printers, communication with other computers or modems,  |
|                 |         || control of processes, reading analogue data.             |
+-----------------+---------+-----------------------------------------------------------+
|                 | par     || Output to printers via a centronics interface,           |
+-----------------+---------+-----------------------------------------------------------+
|                 | nul     || A dummy device which simply receives incoming            |
|                 |         || data and immediately forgets it, useful for debugging.   | 
|                 |         || There are several variants available.                    |
+-----------------+---------+-----------------------------------------------------------+
|                 | pipe    || Pipes are intended for communication between jobs, every |
|                 |         || pipe has an input and output side - there are both       |
|                 |         || standard pipes and named pipes. This is a First In First |
|                 |         || Out device.                                              |
+-----------------+---------+-----------------------------------------------------------+
|                 | history || Similar to a pipe, except that it is a Last In First     |
|                 |         || Out device.                                              |
+-----------------+---------+-----------------------------------------------------------+
|                 | net     || To send or receive data from another network station.    | 
+-----------------+---------+-----------------------------------------------------------+
|                 | mem     || A device to read and write in memory, especially useful  |
|                 |         || to directly access memory on remote network stations via |
|                 |         || the fileserver.                                          |
+-----------------+---------+-----------------------------------------------------------+
| Drives          | mdv     || Microdrives, the original drives on QLs - files are      |
|                 |         || stored on cartridges.                                    |
+-----------------+---------+-----------------------------------------------------------+
|                 | flp     || Floppy disk drives are regarded as standard today -      |
|                 |         || files are stored on disks, early drivers are called fdk. |
+-----------------+---------+-----------------------------------------------------------+
|                 | win     || Winchester drives, also called hard disks - files are    |
|                 |         || stored on a permanently installed very large and fast    |
|                 |         || disk.                                                    |
+-----------------+---------+-----------------------------------------------------------+
|                 | ram     || Ramdisks, virtual but extremely fast drives, the files   |
|                 |         || are stored in RAM and are lost when the computer is      |
|                 |         || switched off.                                            |
+-----------------+---------+-----------------------------------------------------------+
|                 | dev     || A kind of universal device, see DEV\_USE for an          |
|                 |         || introduction.                                            |
+-----------------+---------+-----------------------------------------------------------+
|                 | pth     || Very similar to dev - see PTH\_ADD.                      |
+-----------------+---------+-----------------------------------------------------------+
|                 | mos     || Permanent ramdisk, needs specific hardware.              |
+-----------------+---------+-----------------------------------------------------------+
|                 | rom     || Also a permanent ramdisk.                                |
+-----------------+---------+-----------------------------------------------------------+
| Windows         | con     || Interfaces to a console device (window) for input and    |
|                 |         || output.                                                  |
+-----------------+---------+-----------------------------------------------------------+
|                 | scr     || The same as con\_ but for output only.                   |
+-----------------+---------+-----------------------------------------------------------+
| Other devices   | n       || The fileserver device which allows you to access any     |
|                 |         || device on a remote network station.                      |
+-----------------+---------+-----------------------------------------------------------+
|                 | sdump   || A device for a general window dump.                      |
+-----------------+---------+-----------------------------------------------------------+

Please refer to other parts of this book for more specific information on the 
devices. A lot of examples are given throughout the book.

**NOTE 1**

The OPEN command will close a channel which is already open with the
same channel number prior to opening the new channel - do not try to
OPEN #0 (except from within a compiled program) unless you have Minerva
or SMS - even then, do not try to OPEN #0 as anything other than 
a CON\_ device, except from within a MultiBASIC/Multiple SBASIC.

**NOTE 2**

On AH ROMs, if two tasks tried to read the same file at the same time,
the second task was likely to miss the start of the file and read the
directory header instead.

**NOTE 3**

On QL ROMs (pre MG) there is a maximum of 32767 OPENs in a session.

**NOTE 4**

The pointer environment has a little bug in it which can lead to odd
results when OPENing screen windows. Try, for a laugh (and beware that
this will crash the QL eventually), the following::

    FOR I=1 TO 32768: OPEN #3,scr: PRINT#3,'Hello ';i

This is fixed under SMSQ/E and WMAN v1.52.

**NOTE 5**

The maximum number of channels which can be opened at the same time
depends on the amount of memory available, but in current
implementations, there is an overall maximum of 360 channels, unless you
are using Minerva (see below). SMS seems to allow a much larger number
of channels to be open at the same time.

**NOTE 6**

Any attempt to open more than one channel to a serial port will report
the error 'in use', unless you are using the ST/QL Emulator which allows
more than one input channel to be opened to a serial port.

**NOTE 7**

On the QXL (pre v2.50 of SMS), an attempt to OPEN #ch,ser2
would fail if ser1 was not available to the operating system for any
reason.

**MINERVA NOTES**

On v1.80 (and later), a third parameter is supported on this command
which can be used to specify the 'open type'. This is only of any use on
drives and pipes.

**Drives**

+-----------+------------------------------------------------------------------+
| Open type | Effect                                                           |
+===========+==================================================================+
| 0         | Open existing file for exclusive use (same as OPEN)              |
+-----------+------------------------------------------------------------------+
| 1         | Open existing file for shared use (same as OPEN\_IN)             |
+-----------+------------------------------------------------------------------+
| 2         | Open new file (same as OPEN\_NEW)                                |
+-----------+------------------------------------------------------------------+
| 3         | Open file and overwrite if already exists (same as OPEN\_OVER)   |
+-----------+------------------------------------------------------------------+
| 4         | Open directory file (same as OPEN\_DIR)                          |
+-----------+------------------------------------------------------------------+

(Compare this list with the list at FILE\_OPEN!)

**Minerva Example**

::

    OPEN#3,ram1_test_device,3
    
opens a new file called ram1\_test\_device whether or not it already
exists.

**Pipes**

The extra parameter supplies the QDOS channel number of the source end
of the pipe. This is therefore only of use when opening the 'read' end
of the pipe. This gets around the necessity for commands like QLINK. For
example these two lines are the same::

    OPEN#4,'pipe_4000': QLINK#4 TO #3
    OPEN#4, 'pipe_4000': pipe_id=PEEK_W (\48\4*40+2) : OPEN#3, 'pipe_', pipe_id

Unfortunately, Toolkit II replaces this variant of OPEN with its own,
but all of the above facilities (apart from pipe channel numbers) are
provided by specific Toolkit II commands in any event. Due to Minerva's
System Xtensions, the maximum number of permitted channels open at any
one time has been reduced to 304 on an expanded machine (earlier ROMs
allow 360). On an unexpanded machine, you can only open 112 under
Minerva. 

In MultiBasics, both channel #0 and channel #1 can be
inextricably linked. Due to the fact that the OPEN command closes an
existing channel before setting up the new channel with the given
parameters, OPEN #0 or OPEN #1 from within a MultiBasic will remove the
MultiBasic in certain instances - see MultiBasic appendix.

**CROSS-REFERENCE**

Opened channels are closed with :ref:`close` and can
be listed with :ref:`channels`.
:ref:`fopen` is the same as
:ref:`open` except it works as a function and
:ref:`open-in` /
:ref:`fop-in` open a device for input only.
:ref:`open-dir`
(:ref:`fop-dir`) opens a directory (or a
sub-directory on level-2 drivers). Also see
:ref:`open-new`,
:ref:`fop-over`,
:ref:`tteopen` and
:ref:`file-open`.
:ref:`newchan-pct` can be quite useful when
:ref:`open`\ ing channels.

--------------


..  _open-dir:

OPEN\_DIR
=========

+----------+-------------------------------------------------------------------+
| Syntax   || OPEN\_DIR #channel, device\_directory  or                        | 
|          || OPEN\_DIR #channel, [device\_]directory(Toolkit II only)         |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

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


..  _open-in:

OPEN\_IN
========

+----------+-------------------------------------------------------------------+
| Syntax   || OPEN\_IN #channel, device\_filename  or                          |
|          || OPEN\_IN #channel, [device\_]filename (Toolkit II only)  or      |
|          || OPEN\_IN #channel, device\_filename, type (Minerva v1.80+ only)  |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

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


..  _open-new:

OPEN\_NEW
=========

+----------+-------------------------------------------------------------------+
| Syntax   || OPEN\_NEW #channel, device\_filename  or                         |
|          || OPEN\_NEW #channel, [device\_]filename(Toolkit II only)  or      |
|          || OPEN\_NEW #channel, device\_filename, type (Minerva v1.80+ only) |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

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


..  _open-over:

OPEN\_OVER
==========

+----------+-------------------------------------------------------------------+
| Syntax   || OPEN\_OVER #channel, device\_filename  or                        |
|          || OPEN\_OVER#channel, [device\_]filename(Toolkit II only)          |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command is exactly the same as the Toolkit II version of OPEN\_NEW
except that if the specified filename already exists, the filename is
automatically overwritten. Also, the THOR XVI version of this command
does not support the default data device.

**CROSS-REFERENCE**

See :ref:`open-new`! The Minerva variant of
:ref:`open`, :ref:`open-in`
and :ref:`open-new` can all be made to work in
the same way as :ref:`open-over`.
:ref:`fop-over` is a function which operates
like :ref:`open-over` except that it allows any
errors to be trapped.

--------------


..  _or:

OR
==

+----------+-------------------------------------------------------------------+
| Syntax   |  condition1 OR condition2                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This combination operator combines two condition tests together and
will have the value 0 if both condition1 and condition2
are false, or 1 if either condition1 or condition2 are true (or both
are true). Please note the difference between this and the bitwise OR
operator: x\|\|y, which compares x and y bit by bit.

**Example 1**

::

    PRINT 1 OR 0 
    
Returns 1. 

::

    PRINT 12 OR 10

Returns 1.

Compare PRINT 12&&10 which returns 14).

**Example 2**

::

    10 FOR x=1 TO 5 
    20   FOR y=1 TO 5 
    30     IF x=3 OR y>3:PRINT x;'=>';y, 
    40   END FOR y 
    50 END FOR x

produces the following output:: 

    1=>4 1=>5 2=>4 2=>5 3=>1 3=>2 3=>3 3=>4 3=>5 4=>4 4=>5 5=>4 5=>5

**CROSS-REFERENCE**

:ref:`and`, :ref:`not` and
:ref:`xor` are the other combination operators.

--------------


..  _outl:

OUTL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  OUTL [#]chan [,width,height,x,y]                                 |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

This command is similar to OUTLN except for a few variations: 

#. If chan is not preceded by # then it is taken to be a QDOS channel number (and this command can therefore be used to redefine an Outline for any Job). 
#. You cannot specify a shadow. 
#. If only the chan parameter is used (with or without a #), then the current maximum sizes of the Jobs
   windows are used (similar to OUTLN without any parameters).

**CROSS-REFERENCE**

See :ref:`outln`.
:ref:`channels` allows you to find out about QDOS
channel numbers.

--------------


..  _outln:

OUTLN
=====

+----------+-------------------------------------------------------------------+
| Syntax   || OUTLN [#chan,] width,height,x,y [,x\_shad,y\_shad] or            |
|          || OUTLN (SMSQ/E only)                                              |
+----------+-------------------------------------------------------------------+
| Location || ATARI\_REXT (v2.12+), SMSQ/E                                     |
+----------+-------------------------------------------------------------------+

This command is used within the Pointer Environment to signal that a
specified window (default #0) which must already be open, is to be
looked after by the Pointer Environment (managed). 

Because of the way in
which the Pointer Environment works, it is always a good idea to use
OUTLN on the first window to be used for input/output by a program (this
is known as the Primary Window), as this will ensure that all windows
which are subsequently OPENed by the program will be what is known as
Secondary Windows and also managed. 

Because of this, if a program is to
be run under the SuperBASIC interpreter, OUTLN
should be used on #0, whereas in a compiled program, OUTLN needs to be
used on the first channel which is OPENed (ensure that the program is
compiled without any windows open). 

Hints on writing programs to run
under the Pointer Environment appear below, showing how OUTLN should be
used. 

If an OUTLN has been defined, any attempt to OPEN a window which
would fall outside of the managed Primary Window will cause an 'out of
range' error. If you then use OUTLN on a Secondary window, the first
time that OUTLN is encountered after the window is OPENed, the contents
of the screen under that window will be stored. Then, if you again use
OUTLN on the same window, the contents of the screen under the Secondary
Window are restored (see the example). 

With the first syntax of the
command, the first five parameters supplied to OUTLN are exactly the
same as with WINDOW, however, you can also add two further parameters,
x\_shad and y\_shad to specify the width of a shadow which will appear
to the right and bottom (respectively) of the window to make it stand
out. They both default to zero (no shadow). 

SMSQ/E v2.53+ allows the
second syntax, which will allow you to use OUTLN without any parameters
at all. In this case, the primary window will be outlined to the
smallest area which can encompass all currently OPEN windows at the time
that OUTLN is used.

**Writing programs to use the Pointer Environment**

Some information concerning this appears in Section 4, however, when
designing a program to use the Pointer Environment, it is useful to
follow this procedure:

#. Open a main channel to define the maximum screen area available to the job, eg: OPEN #1,con\_
   This should be the first window OPENed by the program - if it is compiled, compile the program without Windows enabled. 

#. Fetch the screen limits, eg::

     scr_width%=QFLIM (#1,0) 
     scr_height%=QFLIM (#1,1)
     
#. Ensure that the screen is in the right mode:: 

     IF RMODE<>0: MODE 4
     
#. Outline #1 (the main channel) to the size of the program::

     OUTLN #1,450,210,0,0
 
The program will then have a maximum screen area of 450x210 pixels
available. When you wish to resize the program's display, you will need
to mark the main channel (#1) as unmanaged and then use OUTLN to resize
the main channel. For example, the following method was used (using
commands from EasyPTR by Jochen Merz Software) to allow the user to re-
size the program Q-Route (available from Q Branch): 

The procedure is
called when the user highlights the Resize Loose Item on the main menu
(which is drawn on #1). In order for this to work, the main menu had to
be loaded as a separate file into the common heap area pointed to by the
variable m\_store (as there is no way in current versions of EasyPTR to allow you to find
the address of the original menu definition in an Appended definition
file - this is not the working menu definition used by the Window
Manager). 

For more general information on EasyPTR, you are directed to
the EasyPTR tutorial contained in the Quanta magazine in 1994. The
outline of a routine (excuse the pun) to re-size the main menu used by a
program appears on the next page (note that this requires EasyPTR (c)
Albin Hessler, and substantial additions to the code in order to work)::

    9620 DEFine PROCedure RESIZE_MAIN 
    9621   sel_key%=0 
    9622   DIM result%(16)
    9630   PVAL #Main_menu,result% 
    9635   old_x%=result%(14):old_y%=result%(15) 
    9637   : REMark Fetch original pointer co-ordinates 
    9640   pxpos%=old_x%:pypos%=old_y% 
    9650   RDPT #Main_menu,130,pxpos%,pypos% 
    9651   : REMark Draw and move re-size ICON
    9652   : REMark NOTE THIS CRASHES SUPERBASIC!! 
    9655   PVAL #Main_menu,result% 
    9660   IF result%(6)=27:st%=MSTAT%(#Main_menu,-3,0):RETurn: 
    9662   : REMark ESC pressed therefore ignore new setting 
    9665   Menu_add=m_store 
    9667   : REMark Look at where original Menu definition is stored. 
    9670   pwidth=PEEK_W(Menu_add+28):pheight=PEEK_W(Menu_add+30) 
    9675   : REMark These offsets contain the size of the existing menu 
    9675   px=prog_x:py=prog_y 
    9685   pwidth=pwidth-(pxpos%-old_x%):IF pwidth MOD 2:pwidth=pwidth+1 
    9690   pwidth=MAX(pwidth,450) 
    9695   pwidth=MIN(pwidth,scr_width%-12) 
    9700   px=MIN(pxpos%-34,(scr_width%-pwidth)-12) 
    9705   px=MAX(px,0) 
    9710   pheight=MAX(pheight-(pypos%-old_y%),210) 
    9715   pheight=MIN(pheight,scr_height%-10) 
    9720   py=MIN(pypos%-5,(scr_height%-pheight)-10) 
    9725   py=MAX(py,0) 
    9726   : REMark the lines 9675-9725 calculate the new width and height 
    9727   : REMark of the menu (minimum size 450x210) 
    9728   : REMark (maximum size scr_width%-12 x scr_height%-10) 
    9755   prog_x=px:prog_y=py  
    9760   MCLEAR #Main_menu:CLPT #1 
    9762   : REMark Remove the old working menu definition
    9765   OUTL #1,pwidth,pheight,px,py 
    9770   : REMark Resize outline & main window dimensions 
    9775   POKE_W Menu_add+28,pwidth:POKE_W Menu_add+30,pheight 
    9780   POKE_W Menu_add+76,pwidth:POKE_W Menu_add+78,pheight 
    9782   : REMark Alter the menu sizes in the menu definition 
    9784   : 
    9785   : REMark You will now need to re-position various loose items as necessary 
    9787   : REMark There is no easy way to find the offsets of the definitions 
    9788   : REMark within the original menu definition. 
    9790   : REMark You will also need to re-size Information and Application Sub-Windows 
    9795   : REMark as necessary. 
    9795   : 
    9865   MDRAW #1,m_store,px,py:Main_menu=MWDEF(#1) 
    9866   : REMark Redraw the main menu, creating a new Working Menu Definition 
    9870   : REMark you will now need to redraw any information which is normally shown in the 
    9875   : REMark main menu but not contained in the menu when it was designed.
    9885 END DEFine

**Example**

A short program which produces a graphical effect and then provides a
pull-down menu on a secondary window, using OUTLN
to restore the screen after you have used the menu. 

::

    100 OUTLN #0,512,256,0,0 
    110 PAPER #0,0:CLS#0 
    120 REMark Force #0 to Primary Window 
    130 WINDOW #0,448,40,32,216 
    140 WINDOW 448,200,32,16 
    150 PAPER 2:INK 7:CLS 
    180 PRINT 'This is a Secondary Window' 
    190 REPeat loop 
    200   INK RND(3 TO 7) 
    210   FOR i=0 TO 360 STEP RND(10 TO 30) 
    220     x=RAD(i):LINE 50,50 TO 50-40*SIN(x),50-40*COS(x) 
    230   END FOR i 
    235   OPEN #3,scr_400x100a56x20 
    236   PAPER #3,0:INK #3,7 
    240   OUTLN #3,400,100,56,20:CLS#3 
    250   PRINT #3,' MENU' 
    260   PRINT #3,'Press <ESC> to leave' 
    270   PRINT #3,'Press <SPACE> to continue' 
    280   REPeat keys 
    290     x$=INKEY$(-1):IF x$ INSTR ' '&CHR$(27):EXIT keys 
    300   END REPeat keys 
    310   OUTLN #3,400,100,56,20 
    315   CLOSE #3 
    320   IF x$=CHR$(27):EXIT loop
    330 END REPeat loop

Note the need to CLOSE #3 each time that it is removed from the screen.

If #3 was OPENed outside of the loop, OUTLN would only save the contents
of the screen under #3 the first time that line 240 was encountered, and
each subsequent time that it was used, will try to restore the contents
of the screen!

**NOTE 1**

If you use OUTLN to reduce the area of a Primary Window, any Secondary
Windows which would contain an area outside of the new Primary Window
will be re-sized so that they have exactly the same size and position as
the new Primary Window. Any saved contents will be lost. This is also
true of any windows which are OPENed after an OUTLN command - if they
would fall outside of the area defined by OUTLN, then the newly OPENed
window will occupy the same area as the OUTLN. Compare WINDOW which will
cause an error.

**NOTE 2**

Before v2.58 of SMSQ/E, OUTLN without any parameters did not work if an
OUTLN was already set.

**CROSS-REFERENCE**

See :ref:`qflim`. :ref:`outl` is
similar. :ref:`wmon` and :ref:`wtv`
also add an outline to a program.

--------------


..  _over:

OVER
====

+----------+-------------------------------------------------------------------+
| Syntax   |  OVER [#channel,] switch                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to set the way in which anything is written to
a specified window (default #1), whether by PRINT, LINE, BLOCK, or any
other command which prints something on a window. If the supplied
channel is not a window, then error -15 (bad parameter) will be
generated, as will any value of switch outside of the range -1..1. When
the QL is first initiated (or following a MODE  command), OVER is set to 0 (see 
below). This can be altered by giving a different value for switch which 
will have the following effect:

+--------+----------------------------------------------------------------------------+
| Switch || Effect                                                                    |
+--------+----------------------------------------------------------------------------+
| -1     || Everything is PRINTed on a transparent strip. However, each pixel         |
|        || which is drawn on that window in the current INK (or with BLOCK) is       |
|        || actually xored with the colour of the existing background.                |
+--------+----------------------------------------------------------------------------+
| 0      || This is the                                                               |
|        || standard mode, where characters are PRINTed in the current INK and STRIP  |
|        || and any pixels plotted on screen are also in the current INK.             |
+--------+----------------------------------------------------------------------------+
| 1      || This PRINTs characters on a transparent STRIP but pixels are drawn in the |
|        || current INK colour.  BLOCK is unaffected.                                 |
+--------+----------------------------------------------------------------------------+

When OVER -1 is used, it may be useful to calculate how
different colours will appear on screen. This can be achieved by XORing
the two colours in binary, with col1 ^^ col2, for example, a line drawn
in blue on a white background with OVER -1
will actually appear on screen to be INK 1^^7=6 (Yellow). A result of
OVER -1 is that if something is drawn twice in the same place in the
same colour, the object is effectively removed from the screen, leaving
the screen unaltered. This can be seen in the example program given for
IF.

**Example**

A simple demonstration which shows the effects of OVER on CIRCLE, PRINT
and BLOCK. See how easy/difficult it is to calculate how the end display
will look::

    100 MODE 8:WINDOW 448,200,32,16:PAPER 0:CLS 
    110 INK 2:SCALE 100,0,0 
    120 FILL 1:CIRCLE 50,50,35 
    125 PAUSE 
    130 INK 7:OVER -1:FILL 1:CIRCLE 50,50,35 
    135 PAUSE 140 FILL 0:OVER 0 
    150 PAPER 4:INK 7:PRINT"This is a simple circle" 
    155 PAUSE 
    160 OVER 1:PRINT"This is another line of text" 
    165 PAUSE 
    170 OVER -1:PRINT\"This is yet another line" 
    175 PAUSE 
    180 BLOCK 448,200,0,0,2

**NOTE 1**

OVER 0 is set after a MODE command.

**NOTE 2**

The following appears to be a bug in Minerva (pre v1.96) and most other
implementations: 

On Minerva pre v1.96, OVER#0 and OVER#1 are equivalent
to OVER#1,0 and OVER#1,1 respectively, OVER#2 gives bad parameter, as
does OVER#-1. OVER is equivalent to OVER #1,0!! 

On all later versions of
Minerva and SMS, the behaviour is more logical: 

The channel number
defaults to #1 and the switch  to 0, so OVER#0 is OVER#0,0, OVER#1 
is OVER#1,0 (not OVER#1,1), OVER#2 is OVER#2,0 and OVER#-1 naturally 
produces a 'channel not open' error.

**NOTE 3**

OVER -1 causes various problems with the FILL command - see FILL.

**CROSS-REFERENCE**

Please look at :ref:`ink` and
:ref:`print`.

