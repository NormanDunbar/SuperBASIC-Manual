..  _dir:

DIR
===

+----------+-------------------------------------------------------------------+
| Syntax   | DIR [#channel,] device  or                                        |
|          |                                                                   |
|          | DIR [#channel,] [device] (Toolkit II)  or                         |
|          |                                                                   |
|          | DIR \\file [,device] (Toolkit II)                                 |
+----------+-------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                                |
+----------+-------------------------------------------------------------------+

This command produces a listing to the specified channel
(default #1) of all of the files contained on the given device.

The
listing gives the name of the device (specified with FORMAT) followed by
the number of available sectors/the number of usable sectors; followed
by a list of the files in the order they appear on the disk. If you try
to get a directory of a ram disk, eg. DIR RAM1\_
then the name of the device shown on screen will be RAM1.

If Toolkit II
is present, and #channel is a window, a <CTRL><F5> keystroke (pausing
output) is generated at the end of each screen full of the listing. You
can however also use the third syntax to output the directory to the
specified file. If file already exists, you will be given the option of
overwriting it. If file doesn't include a device name, the data default
directory is used.

The Toolkit II variant also supports the default data
directory, which will be used if no device name is given in device, or
if the specified device name would result in the error 'Not Found'.

If
you have Level-2 or Level-3 device drivers, and there are any
sub-directories (created with MAKE\_DIR) in the given directory, then if
you have Toolkit II present, the names of these sub-directories will
appear with the suffix ->.

You can then list the contents of these sub-directories by using DIR
with the original device name plus the name of the sub-directory.
Level-3 drivers take this one step further in that after the name of the
disk in the specified device, appears details of the type of disk being
read, ie. MS-DOS or QDOS followed by SD, DD, HD or ED to confirm whether
the disk is Single Density, Double Density, High Density or Extra
Density. RAM disks are listed as QDOS SD.


**Example 1**

With a cartridge in the left hand microdrive slot,

::

    DIR mdv1_

might produce the following listing in window #1::

    QUILL 102/220 sectors
    boot
    QUILL
    install_exe
    printer_dat


**Example 2**

If Level-2 device drivers are present,

::

    DIR flp1_

might produce the following::

    PSION DISK 1000/2880 sectors
    QUILL ->
    ARCHIVE ->

With Level-3
drivers, you would get the same output except the first line would
become::

    PSION DISK QDOS HD

::

    DIR 'flp1_QUILL'

would on both Level-2 and
Level-3 drivers, then produce the following output::

    PSION DISK 1000/2880 sectors
    QUILL_boot
    QUILL_QUILL
    QUILL_install_exe
    QUILL_printer_dat


**NOTE 1**

With the Toolkit II variant, the <CTRL><F5> will be generated even where
the channel is a window which has been opened over the network (eg.
n1\_scr\_200x200), which can cause problems as the slave machine will
wait for a key to be pressed!

This can be avoided if you have the command FIXPF
(provided as part of the QPTR documentation), which will enable you to
re-install the ROM variant of DIR.

Alternatively write the directory to
a file and copy the file to the host machine, eg.

::

    DIR \ram1_tmp, flp1_
    SPL ram1_tmp TO n1_scr_200x200

It is even more sophisticated to use a named pipe instead of the
temporary file ram1\_tmp for the same job::

    SPL pipe_dir TO n1_scr_200x200
    DIR \pipe_dir_1000, flp1_


**NOTE 2**

The THOR XVI retains the original QL ROM variant of this command, which
does not support the default device, nor does it show sub-directory
names.


**NOTE 3**

Unless you have Toolkit II present, the Break key will not have any
effect on DIR. Press Break when the listing pauses at the end of a page
under Toolkit II (Minerva v1.78+ is supposed to recognise the Break key,
but it does not appear to work). The Break key is however recognised in
Minerva v1.97 (at least!).


**NOTE 4**

Prior to Toolkit II v2.25, DIR of a Level-2 device driver could cause
problems when used inside a TURBO compiled program.


**NOTE 5**

If a directory contains a file with a null string as a name (eg. SAVE
flp1\_), this file will not be listed on the directory listing. This was
used as a form of copy protection on some early QL software, but stops
the program from working on a QL with Level-2 or Level-3 Device Drivers
as they use this file to store the main directory!


**NOTE 6**

On some versions of Toolkit II, the third variant could cause problems
if you supply the name of an existing file to store the directory in,
for example::

    DIR \ram1_XDIR

if you said 'N' when asked if it was OK to Overwrite the existing
file - the display would be sent to #0 and #0 would then be CLOSEd!!
v2.49 of Toolkit II (and possibly earlier) does not cause any problems
but does not report an error. v2.85 of SMSQ/E (and possibly earlier)
also has no problems but reports the error 'Already Exists'.


**NOTE 7**

Some people try to divide up DIRectory listings by creating files such
as::

    SAVE 'flp1_----------------'

However, DIR will only list the
files in the order in which they were created if you are using a virgin
disk which has not had other files deleted from it already.


**CROSS-REFERENCE**

:ref:`data-use` sets the current data default
directory, :ref:`make-dir` creates
sub-directories, :ref:`wdir` allows wildcard names.

