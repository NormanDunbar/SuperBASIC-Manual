..  _parstr-dlr:

PARSTR$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARSTR$ (name,number)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function, together with its associated functions: PARTYP, PARUSE
and PARNAM$ allows you to find out information about a parameter passed
to a SuperBASIC PROCedure or FuNction.

PARSTR$ is aimed for use in
PROCedures or FuNctions where a user might more naturally pass a
parameter as a name rather than a string (for example, when passing a
filename).

Many users will have noted how many machine code procedures
and functions do not need filenames to be passed as a string, for
example::

    SAVE flp1_boot

and wondered why when they write a PROCedure, it has to be passed as a
string, for example::

    SSAVE 'flp1_boot'

Well, PARSTR$ allows you to do either!!

The two parameters which need to be supplied
to PARSTR$ are the name of the parameter as listed in the definition
line and the number of that parameter in the parameter list.

**Example**

A re-write of a SAVE routine to keep the current file version up to date
(this could be used for example when developing a program)::

    100 DEFine PROCedure SSAVE(file)
    110   LOCal version
    120   file$=PARSTR$(file,1)
    130   version=FVERS(\file$)
    140   SAVE file$
    150   SET_FVERS \file$, version+1
    160 END DEFine

To update the saved version of the program in memory, you can then use
either::

    SSAVE flp1_program_bas

or

    SSAVE 'flp1_program_bas'.

Note that SMS users can just use SAVE (without a filename) to achieve this.

**NOTE 1**

If you try to assign the string returned by PARSTR$ back into the
original parameter (eg. change the variable file in the example program
to the variable file$), this will cause an 'error in expression'. You
could try adding file$ to the LOCal
definition, however although this will avoid the 'error in expression',
file$ is set to a nul string by the LOCal definition!!

**NOTE 2**

TURBO and SuperCHARGE cannot compile programs which use PARSTR$.

**CROSS-REFERENCE**

Please also see :ref:`parnam-dlr`.
:ref:`fbkdt` also contains a useful example of
:ref:`parstr-dlr`.

--------------


