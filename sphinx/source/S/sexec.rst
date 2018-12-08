..  _sexec:

SEXEC
=====

+----------+-----------------------------------------------------------------------------+
| Syntax   | SEXEC device\_file,start,length,data  or                                    |
|          |                                                                             |
|          | SEXEC device\_file,start[,length[,data[,extra[,type]]] (Minerva v1.80+)  or |
|          |                                                                             |
|          | SEXEC [device\_]file,start,length,data (Toolkit II)  or                     |
|          |                                                                             |
|          | SEXEC #channel,start,length,data (SMS only)                                 |
+----------+-----------------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                                          |
+----------+-----------------------------------------------------------------------------+

In order for a program to be stored as an executable Job, it is
necessary to store the machine code in a specified format on disk. The
command SEXEC allows you to do this, taking a specified amount of code
from memory and storing it in the specified file in a form which can
later be EXECuted.

You will need to specify the start address of the
machine code, the length of the code to be stored and the amount of data
space to be given to the program when it is loaded back into memory
(the data space represents the amount of working memory which is linked
with the program when it is loaded, either for storing data at the end
of the program or for the user stack - see a good QL machine code book
for more details). The specified file name must include the name of the
device to be used, unless Toolkit II is present, in which case the default
program device is supported. If Toolkit II is present and the file
already exists, you will be given the option of overwriting the file.

**Example**

To amend a given executable program, you may need to do the following::

    100 length=FLEN(\example_exe)
    110 datasp=FDAT(\example_exe)
    120 start=RESPR(length)
    130 LBYTES example_exe, start
    140 POKE start + 1024, 100
    150 SEXEC flp1_example_exe, start, length, datasp

**NOTE 1**

On Minerva ROMs (pre v1.80), if SEXEC was aborted for some reason whilst
writing to a file, the file would be deleted. On later versions of
Minerva and all other QL ROMs, the incomplete file is kept. Toolkit II
reports Medium Full if this is the case.

**NOTE 2**

The Minerva variant is overwritten by the Toolkit II version of this
command.

**NOTE 3**

On Minerva pre v1.83, SEXEC set the wrong file type!

**MINERVA NOTE**

On Minerva v1.80 (or later) the command SEXEC is practically the same as
SBYTES. The only difference is the type parameter which defaults to 1 as
opposed to 0 with SBYTES.

**SMS NOTE**

The fourth variant of this command allows you to save the data to an
already existing channel which is OPEN to a file, thus cutting down on
the number of times you need to access the file for error trapping (for
example). See SBYTES for an example.

**WARNING**

Saving part of the QL's memory with SEXEC does not make it into
EXECutable code - you must ensure that the program concerned has a
proper Job header and conforms with the normal QDOS rules for EXECutable
programs.

**CROSS-REFERENCE**

:ref:`sexec-o` is very similar.
:ref:`exec` and :ref:`exec-w`
allow you to load a program saved with :ref:`sexec`.

