..  _unload:

UNLOAD
======

+----------+-------------------------------------------------------------------+
| Syntax   |  UNLOAD program\_name                                             |
+----------+-------------------------------------------------------------------+
| Location |  MutiBASIC (DIY Toolkit - Vol M)                                  |
+----------+-------------------------------------------------------------------+

Despite the name, this toolkit is completely different to the
MultiBASICs which are provided on Minerva ROMs. This toolkit actually
provides a quick means of saving and loading programs in memory - this
allows you to load a program which you are working on, store it in
memory and then alter the program. If the new alterations to the program
do not work out as planned and you want to revert to the original
version, you can simply RELOAD the original version from program in a
matter of seconds (rather than the minutes which it would take to LOAD
the original version from disk).

This can be very useful for program
development, or, for example, if you have a SuperBASIC utility program
which you use a lot.

This command allows you to store the currently
loaded SuperBASIC program in memory. You have to supply a name for the
program (similar to the name which you could use with the SAVE command,
except there is no need for a device name and the program name can be up
to 127 characters long). The program is then stored - details of the
programs which have been stored with this command are available from the
jobs list (see JOBS). When the program is stored in memory, the contents
of all variables and pointers are also stored, which makes certain that
if you UNLOAD a program whilst it is RUNning, you can later RELOAD it
and re-start it from the same place (with CONTINUE).

Version 4.0+ of the
toolkit, allows you to store the current screen display and mode along
with the program, so that when the program is RELOADed, the display is
in a known layout. To further extend the usefulness of this toolkit, any
commands which appear after UNLOAD will be automatically executed when
the program is RELOADed, for example::

    UNLOAD test: RUN

will always RUN the program when you::

    RELOAD test

**NOTE 1**

The toolkit expects the display to be located at 131072 and be 512x256
pixels and so you should switch off the screen storage facility if you
are using a higher resolution display or a dual screen system.

**NOTE 2**

If a job already exists with the name which you have given to the
program, 'Already Exists' will be reported.

**NOTE 3**

Although the toolkit can be used to store programs from a Minerva
MultiBASIC, you cannot load the toolkit from a Multiple BASIC - an
'incomplete' error is reported.

**NOTE 4**

The current channel details are not stored when you use UNLOAD - you may
therefore need to re-open the channels when the program is RELOADed, or
use something akin to::

    UNLOAD 'watch': OPEN #3,con_448x200a32x16

which will always ensure that #3 is OPEN whenever the program is
RELOADed.

**NOTE 5**

If a program uses ALCHP to grab some memory, unless you intend to always
RUN the program from the start when you RELOAD
it, do not use any command which will release this area of common heap
memory before you RELOAD the program. Commands which do this include::


    CLCHP
    CLEAR
    NEW
    LOAD

**WARNING 1**

This toolkit does not work on SMSQ/E and can crash the computer.

**WARNING 2**

Unfortunately, attempts to use this toolkit to UNLOAD files from one
interpreter and then RELOAD the files into another Multiple BASIC will
crash that Multiple BASIC (or have other various undesirable effects).

**CROSS-REFERENCE**

:ref:`scr-save` allows you to dictate whether
the screen display and mode should be stored together with the program.
:ref:`resave` is similar.
:ref:`remove` allows you to remove a program stored
in memory with this command. See also :ref:`reload`
and :ref:`qsave`.

--------------


