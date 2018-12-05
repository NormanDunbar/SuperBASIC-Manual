..  _save:

SAVE
====

+----------+--------------------------------------------------------------------------------+
| Syntax   | SAVE device\_filename :sup:`\*`\ [,range]\ :sup:`\*` or                        |
|          |                                                                                |
|          | SAVE [device\_] filename :sup:`\*`\ [,range]\ :sup:`\*`\ (Toolkit II only)  or |
|          |                                                                                |
|          | SAVE(SMS only)                                                                 |
+----------+--------------------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                                             |
+----------+--------------------------------------------------------------------------------+

If no line range is given, this command saves the whole of the
currently loaded SuperBASIC program to the given directory device, under
the given filename. However, a range of lines can be given (as with
LIST), in which case only the given lines will be saved. If the filename
already exists on that device, the error 'Already Exists' is reported,
unless you have Toolkit II present, in which case, a prompt will be
printed in #0 asking you whether it is okay to overwrite that file. If
the device is already full, the 'Device Full' error is reported,
however, the effects should the drive become full during the actual SAVE
command, depends upon the implementation (see below).

The file is saved
in pure ASCII format, which means that it can be COPYed to the screen or
a printer (using COPY\_N). The Toolkit II variant of the command will
add the data default directory to the filename if it cannot find the
given device, or no device is specified.

**Examples**

Save the whole of the current program to microdrive 1 with the filename
BOOT::

    SAVE mdv1_BOOT

Save the whole of the current program to the current data default
directory with the filename prog\_bas::

    SAVE prog_bas

Save lines 1, 100 to 150 (inclusive) and 300 to the end of the program
to the current data default directory with the filename cut\_bas::

    SAVE cut_bas,1,100 TO 150,300 TO

**NOTE 1**

SAVE can lead to incomplete files if the Break key is pressed or the
device fills up during access, although Toolkit II (v2.13+) will report
any file errors during output (other than the Break key being pressed),
leaving the incomplete file on the device.

**NOTE 2**

Minerva (pre v1.80) deleted the file if SAVE was aborted for any reason.

**NOTE 3**

If you try to SAVE a file on top of a sub-directory name, Toolkit II
will repeatedly ask if it is OK to overwrite that file until you answer
<N> (for No).

**SMS NOTES**

The third variant of the command will allow you to SAVE the program in
memory under the same filename as when LOAD or QLOAD
was last used (with the \_BAS suffix appended if necessary). If the
original filename used when the program was LOADed ended in \_SAV, then
SAVE will alter this to be the \_BAS suffix. This variant will also take
the version number of the file when it was LOADed (or QLOADed) and then
increase this by one.

If you SAVE a file on a disk, then use DELETE to
remove that file, and then change the disk before issuing the SAVE
command without a filename being specified, SMSQ/E fails to recognise
that the disk has been swapped and repeatedly tries to write out the
file using the old directory map. Further, if you enter SAVE without a
parameter and no disk is in the drive - SMSQ/E asks if it is OK to
overwrite the file!!

**CROSS-REFERENCE**

:ref:`load` loads a saved file from the given device
into memory. :ref:`save-o` is another variant of
this command. See also :ref:`qsave` for a different
means of :ref:`save`\ ing a SuperBASIC program.

--------------


