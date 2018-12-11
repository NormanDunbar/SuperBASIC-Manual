..  _wcopy:

WCOPY
=====

+----------+------------------------------------------------------------------+
| Syntax   | WCOPY [#ch,] [wild1] [TO wild2](Toolkit II)  or                  |
|          |                                                                  |
|          | WCOPY [#ch,] wild1 TO wild2(THOR)                                |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THORs                                                |
+----------+------------------------------------------------------------------+

The command WCOPY is intended to allow you to copy several files with a
common root from one device to another, quickly and easily.

It is
however necessary to understand the way in which Toolkit II's wildcards
work, as WCOPY uses these wildcards to find the required files. A
wildcard is a means of finding several files which have similar names.

The first thing which any wildcard command does is to look at the
supplied parameter and then compare this against each entry in the
directory of the given device. If any of the filenames match exactly, or
if the parameter forms the start of any filenames, those files are
marked as chosen. For example::

    WCOPY flp1_D TO flp2_

would copy all files whose names are either 'D' or begin with the
letter 'D' to flp2\_ (the comparison is case independent).

However,
wildcards can be much more complex and wonderful on the QL. If you place
two underscores ('\_') together as part of wild1, this is taken to be a
wildcard and can in fact be replaced by any string of characters in
order to match filenames with wild1. Wildcards are further complicated
by the fact that if a device name is not provided as part of wild1, then
the default device will be added (which ends with an underscore, so if
wild1 begins with an underscore, you will have a wildcard symbol!!) A few
examples of wildcards (assuming default device is 'flp1\_'):

..  tabularcolumns::    |l|l|p{0.6\textwidth}|

..  table::
    :class: longtable

    +-------------+-----------------+------------------------------+
    | Wild1       | Wild Card Name  || File Matches                |
    +=============+=================+==============================+
    | t           | flp1\_t         || flp1\_testa                 |
    |             |                 || flp1\_test\_v1.00\_bas      |
    +-------------+-----------------+------------------------------+
    | \_t         | flp1\_\_t       || flp1\_testa                 |
    |             |                 || flp1\_test\_v1.00\_bas      |
    |             |                 || flp1\_old\_v0.01\_test\_bas |
    +-------------+-----------------+------------------------------+
    | flp1\_old\_ | \_flp1\_old\_\_ || flp1\_old\_v0.01\_test\_bas |
    |             |                 || flp1\_old\_v1.00\_exe       |
    |             |                 || flp1\_old\_data             |
    +-------------+-----------------+------------------------------+

WCOPY uses both wildcards for
ascertaining the names of the files to be copied, and the files to be
created. However, both wild1 and wild2 are dealt with distinctively.

WCOPY will use the rules on wildcards to search for files which match
with wild1 on the specified device, or the default data device if no
device is specified. However, the rules for determining the destination
parameter wild2 are complex:

#. If no device is given, but a filename is
   specified, WCOPY looks at wild1. The destination device is then assumed
   to be the same as the source device (ie. the device name specified as
   part of wild1, or if omitted, DATAD$).
#. If the second parameter is
   omitted, then again WCOPY
   looks at wild1. If a device is given in the first parameter, then this
   is used as the destination device. On the other hand, if no device was
   specified, then the default destination device will be used (see
   DESTD$).
#. If a second parameter is given which includes a device name,
   then this is used! Having decided upon the device to which the files are
   to be copied, WCOPY then looks at the remainder of wild2 to ascertain
   what to do with the filenames it has found.

Before trying to understand
how this works, it is essential to realise that there is an implicit
wildcard placed at the end of both wild1
and wild2.

WCOPY will look at wild2 and compare each filename that it
has found using the wildcards in wild1 in turn. If a wildcard in wild1
is matched by a wildcard in wild2, then that part of the source
filename will be inserted into the destination filename. However, beyond
this, WCOPY will use the rest of wild2 as the actual destination
filename. Any additional sections in wild1 or wild2 will be inserted
after the drive name in the destination filename. See the examples
below!

Having decided which files are to be copied and the names they
are to be given on the device where they are being copied to, WCOPY will
then request confirmation in the specified channel (default #0) for each
file, by printing the following message in the channel::

    source_file TO destination_file..Y/N/A/Q?

You will then need to press <Y> to copy that file across, <N> to miss
that file out, <A> to copy all files which match with wild1, or <Q> to
leave WCOPY. In this instance, <ESC> and <CTRL><SPACE> both act as <Q>.

If the destination file already exists, another prompt will be shown in
the form::

    OK to overwrite..Y/N/A/Q?

You will then need to press <Y> to overwrite that file, <N> to go onto
the next file, <A> to overwrite this and all other files being copied if
they already exist, or <Q> to stop WCOPY. Again, <ESC> and <CTRL><SPACE>
act as <Q>.

**Examples**

Assuming that the default data device is flp1\_ and the default
destination device is ram2\_::

    WCOPY

Copies all files on flp1\_ to ram2\_

::

    WCOPY flp1_test TO ram2_old

Copies::

    flp1_testa to ram2_olda
    flp1_test_v1.00_bas to ram2_old_v1.00_bas

::

    WCOPY flp1_test, ram2_old_

Copies::

    flp1_testa to ram2_olda
    flp1_test_v1.00_bas to ram2_old_v1.00_bas

::

    WCOPY _bas to ram2_

Copies::

    ram1_test_v1.00_bas to ram2_bas
    ram1_old_v0.01_test_bas to ram2_bas

::

    WCOPY _bas, ram2__

Copies::

    ram1_test_v1.00_bas to ram2_test_v1.00_bas
    ram1_old_v0.01_test_bas to ram2_old_v0.01_test_bas

::

    WCOPY old__ TO ram2_

Copies::

    ram1_old_v0.01_test_bas to ram2_v0.01_test_bas
    ram1_old_v1.00_exe to ram2_v1.00_exe
    ram1_old_data to ram2_data

**NOTE 1**

The TO in the syntax can be replaced by a comma ',' as per a number of the above examples.

**NOTE 2**

On the THOR range (v4.02+) the word 'TO' in the prompts is replaced by the
symbol =>

**NOTE 3**

On the THOR range, the prompt message are altered from 'Y/N/A/Q' to
'Yes/No/All/Quit'.

**NOTE 4**

As with COPY, WCOPY does not copy the header to serial devices (eg. ser)
if this is specified as the destination. However, the THOR variant of
this command actually looks to see whether the file-type or file
dependent information fields are non-zero in which case the header is
always copied.

**NOTE 5**

If you have level-2 device drivers, any sub-directories in the specified
source directory are ignored by WCOPY. For example, if::

    DIR flp1_

gave the following result::

    Psion Disk
    400/1440 sectors
    QUILL->
    ABACUS->

Then::

    WCOPY flp1_

would have no effect. However, compare::

    WCOPY flp1_QUILL_

which would copy all of the files in the sub-directory 'QUILL' to the
current destination device.

**NOTE 6**

Both parameters must be supplied for the THOR variant of this command,
otherwise the error 'Bad Parameter' will be reported.

**NOTE 7**

Current versions (at least up to v2.85) of WCOPY do not work correctly
with the DEV device when this is pointing at a sub-directory (eg::


    DEV_USE 1, flp1_QUILL_: WCOPY DEV1_

WCOPY will however work if the DEV device is pointing at a root directory, eg::

    DEV_USE 1, flp1_.

**CROSS-REFERENCE**

:ref:`spl-use` and
:ref:`dest-use` set the destination device. See
:ref:`copy`, :ref:`wcopy-f`
and :ref:`wcopy-o` which are all similar.
:ref:`wren`, :ref:`wdir`,
:ref:`wstat` and :ref:`wdel` all
use wildcards. :ref:`copy` and
:ref:`spl` allow you to copy specific files.

