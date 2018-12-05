..  _dev-use:

DEV\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   | DEV\_USE n,drive [,next\_dev] n=1..8 or                           |
|          |                                                                   |
|          | DEV\_USE [n](SMS v2.70+ only) or                                  |
|          |                                                                   |
|          | DEV\_USE [drivetype]                                              |
+----------+-------------------------------------------------------------------+
| Location | DEV device, GOLD CARD, ST/QL, SMS                                 |
+----------+-------------------------------------------------------------------+

The DEV device is a universal method of driving devices (MDV, FLP, WIN,
MOS, ROM), and thus allows old software to recognise default devices/
sub-directories as well as simplifying the use of them. It also
introduces fully programmable search paths to QDOS.

There are eight
separate DEV drives available, DEV1\_ to DEV8\_, each of which can point
to a real drive and directory defined with DEV\_USE.

The first parameter
of the command is the number of the DEV device to be defined.

The second specifies what DEVn\_ represents.

There is no default and nothing is predefined, but DEV\_USE permits only
valid drives and directories. Any default devices (DATAD$, PROGD$ etc)
are not recognised so the full directory name (including the drive name)
must be stated.

There is one special second parameter, the empty string,
which removes the definition of the given DEV device; there is no error
reported if it was not defined.

The second syntax (SMS v2.70+) also allows you to
remove a definition by simply passing the number of the DEV device to
delete.


**Example 1**

::

    DEV_USE 1,flp1_
    DEV_USE 2,flp1_SUBDIR_
    DEV_USE 3,flp1_SUBDIR
    DEV_USE 4

Each time that DEV1\_ is accessed, the actual drive which will be
accessed is FLP1\_, eg. DIR DEV1\_ lists a directory of FLP1\_.

However,
LOAD DEV2\_BOOT will load FLP1\_SUBDIR\_BOOT but especially note that
LOAD DEV3\_BOOT would try to load FLP1\_SUBDIRBOOT (that's not a typing
error).

You can therefore see the importance of specifying the
underscore! Whereas DATA\_USE always adds an underscore to the supplied
parameter if there one was not specified, DEV\_USE does not. Please pay
attention to this difference!

DEV\_USE's third parameter is optional and
ranges from 0 to 8. This is used to specify another DEV device which
should be tried if DEVn\_ was accessed for a given file, but the file
was not present on that DEV device.

In all other cases: if the drive in
general is currently inaccessible (eg. open for direct sector
read/write), the file is damaged or already in use, the DEV device will
stop with the appropriate error message, and behave as normal in such
situations.


**Example 2**

::

    DEV_USE 1,flp1_,2
    DEV_USE 2,flp1_TEST_

VIEW DEV1\_Prog\_bas will first try to show FLP1\_Prog\_bas and if it
did not find that file, it will then try DEV2\_Prog\_bas which is
actually FLP1\_TEST\_Prog\_bas. If this also fails, VIEW stops with a
'Not Found' error. You might notice that this could lead to an endless
search if DEV2\_ was told to jump back to DEV1\_ if
flp1\_TEST\_Prog\_bas also did not exist.


**Example 3**

::

    DEV_USE 1,flp1_,2
    DEV_USE 2,flp1_TEST_,1

Luckily, this is no problem - the DEV device never circles back to a
DEV which has already been tried. So, using the definition given for
example 3, VIEW DEV1\_Prog\_bas looks for FLP1\_Prog\_bas, then
FLP1\_TEST\_Prog\_bas and breaks with 'Not Found' because DEV1\_ has
already been tested.

That's why a DEV
device cannot point to another DEV device, DEV\_USE 1,DEV2\_ is
illegal.

It is advisable to give seldom used drives and directories a
lower search priority because it naturally takes a little time to scan
through a directory for a file. Preferred directories and fast RAM disks
(which take next to no time to check for a file) should be checked
before the less often-used directories are looked at.

**Example 4a**

::

    DEV_USE 1,flp2_SOURCES_,4
    DEV_USE 2,flp1_COMPILER_,3
    DEV_USE 3,flp1_COMPILER_UTILS_,4
    DEV_USE 4,ram1_,5
    DEV_USE 5,flp2_SOURCES_OTHER_,1

The search path for DEV1\_ is:

- FLP2\_SOURCES\_ go to DEV4\_
- RAM1\_ go to DEV5\_
- FLP2\_SOURCES\_OTHER\_ go to DEV1\_, we already tried that, so
  stop

The search path for DEV2\_ is:

- FLP1\_COMPILER\_go to DEV3\_
- FLP1\_COMPILER\_UTILS\_ go to DEV4\_
- RAM1\_ go to DEV5\_FLP2\_SOURCES\_OTHER\_ go to DEV1\_
- FLP2\_SOURCES\_ go to DEV4\_, already checked, so stop.

You see that the two search paths for DEV1\_ and DEV2\_ are connected in one way. This rather complicated example
suggests that it would be useful to set the data and program device as follows:

**Example 4b**

::

    DATA_USE DEV1_
    PROG_USE DEV2_

Taking into account that Toolkit II tries the program device after
failing to find a file on the data device, a VIEW TEXT will first search
through the DEV1\_ list and then DEV2\_ (thus looking through all DEVs)
while EX PROG\_exe stops after checking DEV2\_ and its connected DEVs.

All operations creating or deleting files will only check for the
original DEV definition and ignore the optional paths. This prevents
files from being unintentionally deleted or overwritten.

Given the
settings of examples 4a and 4b, OPEN\_IN #3,DEV1\_TEXT
will act as VIEW did before whereas OPEN\_NEW #3,DEV1\_TEXT creates
FLP2\_SOURCES\_TEXT or reports an error/asks if you want to overwrite
(if necessary).

DELETE always behaves as an exception in that it does
not report an error if a file was not found.

You may have noticed that
the third parameter allows a wider range than the DEV number. A zero as
the third parameter simply does the same as no third parameter.

The
third syntax of DEV\_USE is completely different from the first two. It
is analogous to the FLP\_USE, RAM\_USE and NFS\_USE
commands and allows you to use a different three letter code for the
DEV device::

    DEV_USE fry.

DEV1\_ is now called fry1\_, DEV2\_ fry2\_ and
so on. However, you can also use existing devices.

**Example 4c**

::

    DEV_USE FLP

Now, things become really complex. With examples 4a and 4b still being
valid, FLP1\_ actually refers to FLP1\_SOURCES\_, searching through all
the other DEV definitions as well in order to find a file.

The
definitions of DEV1\_ as FLP1\_SOURCES\_ and DEVs as FLP do not collide.
However, if you issued FLP\_USE DEV, FLP1\_ and DEV1\_ are not known any
more until FLP\_USE FLP restores the default name for disk drives.

Equally, DEV\_USE DEV restores the DEV name (although this can be
abbreviated by a DEV\_USE without any parameters).

**Example 5**

::

    DEV_USE DEV1_

refers to the true DEV1\_ again, DEV2\_, DEV3\_, ..., too.

Renaming DEV has been mainly implemented to convince existing software
believing that a directory file always has five letters (eg. MDV1\_) to
accept sub-directories of level-2 drivers as directory files, too.


**NOTE**

At least up to v2.01, the DEV device does not work fully on any machine.
For example WSTAT lists the file names but not the other information:
DEV\_USE 1,FLP1\_TEST\_ WSTAT DEV1\_


**CROSS-REFERENCE**

:ref:`data-use`,
:ref:`prog-use`,\ :ref:`dev-use-dlr`,
:ref:`dev-next`.
:ref:`dev-usen` is the same as the third syntax
on SMSQ/E. :ref:`dev-list` lists all DEV
definitions. :ref:`make-dir` and the
DMEDIUM_XXX commands, starting with :ref:`dmedium-density` are also
interesting.

--------------


