..  _delete:

DELETE
======

+----------+-------------------------------------------------------------------+
| Syntax   | DELETE file  or                                                   |
|          |                                                                   |
|          | DELETE file :sup:`\*`\ [,file\ :sup:`i`]\ :sup:`\*` (THOR XVI)    |
+----------+-------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                                |
+----------+-------------------------------------------------------------------+

The command DELETE removes the stated file from a medium (it actually
only deletes its entry from the directory map, which thus allows these
files to be recovered if necessary, with a utility such as the Public
Domain RETTUNGE\_exe, provided that nothing has been written to the disk
since it was deleted).

The filename must include the name of the medium,
unless you have Toolkit II installed, which alters the command so that
the default data device is recognised (see DATAD$).

The command does not
report an error if a file was not found! However, if an invalid device
is used and Toolkit II is not present, an error will be reported.

The
THOR XVI variant of this command follows the original proposal for this
command, allowing you to delete several files at the same time by
listing each filename, eg::

    DELETE flp1_boot,flp1_main_bas

This latter syntax is accepted on non-Minerva systems, but only the
first file will be deleted. If Toolkit II is present, error -15 (bad
parameter) is reported.


**Example**

::

    DELETE mdv2_PROG_bak
    DELETE PROG_bak


**CROSS-REFERENCE**

:ref:`wdel` deletes several files interactively.
:ref:`wdel-f`, :ref:`wdir` and
:ref:`ttedelete` are also worth a look.

--------------


