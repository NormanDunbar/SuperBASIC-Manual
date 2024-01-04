..  _do:

DO
==

+----------+-------------------------------------------------------------------+
| Syntax   |  DO [device\_] filename                                           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to execute a set of commands stored in a file
(acting as an overlay).

It is intended to perform tasks dictated by a
numberless file, which enables you to do many things whilst releasing
memory once the tasks have been performed.

DO is actually very similar to the Toolkit II variant MERGE
and will ensure that if the given file only contains numberless lines,
the channel is closed afterwards.

It does however work just as well as MERGE on numbered files!

A numberless program is basically a set of
SuperBASIC lines which do not have any line numbers. These can therefore
best be entered with the aid of an editor program. Each line is loaded
into the QL with the relevant command, and then executed (one line at a
time), as if they had been entered from the command line (#0).

This therefore means that although they can call resident SuperBASIC
PROCedures and FuNctions, you can only have in-line structures, such as
IF...END IF and SELect ON...END SELect.

Once each line has been
executed, it is lost and the memory occupied by that line released.

One
advantage for pre JS ROMs is that if you use a numberless file to link
resident keywords, such keywords can then be used in the same program
which MERGEd the numberless file. For example, if you have a numberless
file flp1\_resident\_bas such as::

    a=RESPR(12000)
    LBYTES flp1_Toolkit,a: CALL a

you can then link and use the Toolkit commands in the same program by
including a line such as::

    110 DO flp1_resident_bas


**NOTE**

On at least v2.28-v2.49 of Toolkit II, MERGE appears to work much better
than DO at executing numberless files. If DO is entered as a direct
command, none of the numberless lines are executed (compare MERGE which
executes the first line), and if DO
is part of a program, only the first line is executed (compare MERGE
which executes all of the commands in the numberless file). This is
fixed under SMS.


**CROSS-REFERENCE**

Please refer to :ref:`merge`. SMS allows you to
:ref:`exec`\ ute a SuperBASIC program, letting it run
in the background and perform functions on supplied data using pipes or
channels (see :ref:`ex`).

