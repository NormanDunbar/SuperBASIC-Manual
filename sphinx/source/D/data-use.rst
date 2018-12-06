..  _data-use:

DATA\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DATA\_USE default\_device                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

If you have Toolkit II installed, all of the additional extensions
connected with file or device handling and all original SuperBASIC
commands use the default device if no other device name is specified.

On a THOR XVI, some of the commands support default devices without Toolkit
II.

The effect of the default devices would make LOAD proggy\_bas
work as LOAD flp1\_proggy\_bas (assuming that flp1\_ is the default
data device). The actual effect depends on the command being executed,
but generally the file will be looked for in three steps:

- Does the given file include a valid device? proggy\_bas does not,
  ram1\_proggy\_bas does (ram1\_). If not, the parameter is assumed to be
  a filename and Toolkit II looks for a device on which it can find it; so:
- Add the default data device to the filename. If that does not work,
  then:
- Add the default program device (PROGD$) and try again.

The
default program device is defined by PROG\_USE, DATA\_USE
defines the default data device. See PROG\_USE as to the difference
between the two defaults. The last two steps add the default devices to
the filename. These defaults can be interpreted as sub-directories.

Here, a sub-directory means that where a prefix is separated by
underscores, this means that the file concerned is held in the
sub-directory specified by that prefix. Thus, win1\_QUILL\_readme\_doc
could be readme\_doc on a hard disk in the sub-directory QUILL or doc in
the sub-subdirectory readme of QUILL.

Sub-directories can be nested but
the complete filename, including prefix must not be longer than 41
characters (note that if you are using a network device, for example
n1\_win1\_proggy\_bas, the maximum permitted filename length is reduced
to 39 in current versions of the QL device drivers).


**Examples**

::

    DATA_USE flp1_QUILL (or flp1_QUILL_)
    DATA_USE MDV2_
    DATA_USE win1_Psion_ARCHIVE
    DATA_USE n2_ram1_
    DATA_USE mdv3_games_arcade_invaders_


**NOTE 1**

If there is no underscore at the end of DATA\_USE's parameter, it will
be added automatically.


**NOTE 2**

A few programs do work with these sub-directories (if Toolkit II is
present), but most do not. To make any program work with them, you can
fool them so that they believe that for instance FLP1\_games\_BOOT is
FLP1\_BOOT or BOOT (default device FLP1\_games): See the PTH\_... and
DEV\_... commands.


**NOTE 3**

Toolkit II sub-directories should not be mixed up with wild cards.
DATA\_USE flp1\_\_bas makes WDIR list all BASIC programs on floppy 1,
but after PROG\_USE flp1\_\_bas, SAVE test will not save the current
program as flp1\_test\_bas but as flp1\_\_bas\_test.


**NOTE 4**

The default device is the current sub-directory on level-2 drivers.


**NOTE 5**

If you wish to turn off this feature, you can assign a null string ("")
to DATA\_USE.


**NOTE 6**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to assign a longer string will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

:ref:`datad-dlr` contains the default data device,
:ref:`dlist` lists all default devices.
:ref:`ddown`, :ref:`dup` and
:ref:`dnext` allow you to skip from sub-directory to
sub-directory, climb up the tree and much more.
:ref:`prog-use` changes the default program
device, and :ref:`spl-use`
/:ref:`dest-use` the default destination device.
See also :ref:`dev-use` and
:ref:`pth-add` for path search.

