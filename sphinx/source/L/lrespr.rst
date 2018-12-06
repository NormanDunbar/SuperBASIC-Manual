..  _lrespr:

LRESPR
======

+----------+-------------------------------------------------------------------+
| Syntax   |  LRESPR mc\_file                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command is used as a quick way of loading and starting machine
code routines (mainly Toolkits). It will grab enough memory from the
Resident Procedure Area to hold the given file, load the file into
memory and then call it. Toolkit II sub-directories and the default data
device are supported. LRESPR could be re-written as the following
SuperBASIC procedure::

    100 DEFine PROCedure LRESPR (mc_file$)
    110   LOCal length,adress
    120   length=FLEN(\mc_file$)
    130   adress=RESPR(length)
    140   LBYTES mc_file,adress
    150   CALL adress
    160 END DEFine LRESPR

**Examples**

::

    LRESPR BeuleTools_bin
    LRESPR ram1_MyTool_obj

**NOTE 1**

It is impossible to remove a program loaded with LRESPR so that the
occupied memory can be given back for other purposes.

**NOTE 2**

On version 2.23 (or later) of Toolkit II, LRESPR works even if a job is
running because in this case, it will load the file into the Common
Heap. CLCHP, NEW, CLEAR etc. do not remove code loaded in this way, so a
crash is impossible.

**NOTE 3**

When using LRESPR (or any other means) to link in extensions to
SuperBASIC, bear in mind that pre JS ROMs needed the command NEW (or
LOAD / LRUN) before those commands will be available. This happens on MG
ROMs sometimes as well.

**NOTE 4**

If this command is used to link a toolkit into a MultiBASIC under
Minerva or a multiple SBASIC under SMS, then that toolkit will be local
to that BASIC interpreter - when you remove that BASIC, the toolkit will
also disappear.

**CROSS-REFERENCE**

See the second example for :ref:`alchp`. See also
:ref:`linkup` and
:ref:`lresfast`.

