..  _respr:

RESPR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  RESPR (bytes)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function sets aside a chunk of resident procedure space for use by
a program and returns the address of the start of that memory. Resident
procedure space is merely an area of RAM which can be used safely by the
user without fear of the system crashing if values are written to it.

When used, the RESPR function will search for an area in RAM which is
currently unused and which is at least 'bytes' long. If there is
insufficient space in RAM, then an 'Out of Memory' error is reported.

Memory set aside using RESPR cannot later be released and used for other
purposes (unless you have a Minerva ROM), and thus this command is used
mainly for linking in Toolkits and other system extensions in a boot
program.

**Example**

A simple boot program might look like this::

    100 x=RESPR(10*1024): LBYTES flp1_Toolkit,x: CALL x
    120 EXEC flp1_Program_obj

**NOTE 1**

If a task is running in memory (eg. with EXEC), when RESPR is used, the
resident procedure space cannot be accessed and the error 'Not Complete'
is reported. However, some Toolkits, SMS and Minerva rewrite the RESPR
command so that it will access the common heap if the resident procedure
space cannot be accessed.

**NOTE 2**

Normally, the function RESPR(0) will return the address of ramtop, this
can actually be used to find out the size of memory attached to the QL::


    PRINT RESPR(0)/1024-128.

However, this will not work on versions of the command which work when tasks are running in memory.

**NOTE 3**

On Minerva pre v1.96, adding machine code functions and procedures from
within a SuperBASIC PROCedure or FuNction definition could cause
problems after a CLEAR command.

**WARNING**

Several programs may try to use the same area of resident procedure
space if absolute addresses are used.

**CROSS-REFERENCE**

Please also see :ref:`alchp` which allocates memory
from the common heap, which can be accessed when tasks are running in
memory. Also see :ref:`reserve` and
:ref:`grab` which are similar to
:ref:`alchp`. It is also worth looking at
:ref:`resfast`.

