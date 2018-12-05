..  _call:

CALL
====

+----------+-----------------------------------------------------------------------------------+
| Syntax   |  CALL address [,d1[,d2[,d3[,d4[,d5[,d6[,d7 [,a0[,a1[,a2[,a3[,a4[,a5 ]]]]]]]]]]]]] |
+----------+-----------------------------------------------------------------------------------+
| Location |  QL ROM                                                                           |
+----------+-----------------------------------------------------------------------------------+

This command allows you to call a machine code routine loaded at the
memory location address from SuperBASIC. At the same time, you can set
the initial 68008 registers by supplying more than one parameter. Each
additional parameter should be an integer value and is placed into the
appropriate machine code register.

You cannot return values to SuperBASIC using this command, although you
can return errors by setting D0 from the machine code on return.

If the machine code register D0 contains a number other than an error
code (or 0) on return, the program will stop with the error 'At line '.

Various useful routines can be CALLed on a Minerva ROM - these are
discussed on the next few pages.

**NOTE 1**

This command could crash the computer if used from within a program
longer than 32K on pre JS ROMs. This is fixed by Toolkit II, the THOR
XVI and Minerva.

**NOTE 2**

It can be dangerous to CALL addresses in memory unless you know that you
have loaded a specified machine code routine into that location.

    MINERVA NOTES:

**MINERVA NOTES**

Minerva adds various routines which can be CALLed from within a
SuperBASIC program to perform various tasks quickly and efficiently. The
routines are as follows:

**(1) Reset machine**

CALL 390,param

This routine resets the QL and allows you to set various parameters
according to the value of param, which allows you, for example, to cut
the amount of memory available to the machine. >/p>

To calculate the value of param, look at the following table and decide
what effects you want the reset to have.

Next, look up the value of that effect and add it to param.

**EffectValue to add**

-  Skip memory test = 1
-  Skip ROM scanning (ignore extras) = 2
-  Alter maximum memory = 4
-  Default to TV mode = 8
-  Ignore F1..F4 (no wait) = 16
-  Leave n\*256 bytes between screen and System Variables = n\*256
-  Set ramtop to nKB = (n+128)\*1024

**Examples**

(a) reset machine and force dual screen TV mode (no memory test):

CALL 390,8+16+128+1

(b) reset machine to 640K:

CALL 390,(640+128)\*1024+4

**MINERVA WARNINGS**

CALL 390 can crash the machine - always set the new ramtop to a multiple
of 64K and do not try to allocate more memory than is in the system.

If you leave space between the screen and System Variables, this will
reduce the amount of memory available accordingly!!

If your system uses a keyboard linked to SuperHermes, do not use CALL to
reset the system unless you include a line such as PAUSE 40 prior to the
CALL command to clear all pending input, otherwise SuperHermes becomes
confused!

**(2) Move memory quickly:**


CALL PEEK\_W(344)+16384,length,2,3,4,5,6,7,dest,source

This command allows you to move length bytes from the source address to
the destination address (dest) extremely quickly.

Either source or dest may be odd addresses, and the code will even cope
with overlapping areas.

    Minerva Example:

**Minerva Example**

To copy the whole of the main screen to a screen storage area pointed to
by the variable scr\_store

::

    10 scr_size=SCR_LLEN*SCR_YLIM
    20 scr_store=ALCHP(scr_size)
    30 CALL PEEK_W(344)+16384,scr_size,2,3,4,5,6,7,scr_store,SCR_BASE

**(3) Clear memory quickly**

CALL PEEK\_W(360)+16384,length,2,3,4,5,6,7,address

This command allows you to clear length bytes from the given start
address onwards extremely quickly. It could for example, be used to
clear storage buffers.

Please note that address may be odd.

**CROSS-REFERENCE**

:ref:`lbytes`, :ref:`sbytes`
can be used to load and save areas of memory (and machine code
routines).

:ref:`alchp` and :ref:`respr`
can be used to set aside areas of memory for user routines.

:ref:`bmove` and similar commands allow you to move
areas of memory on other ROM implementations.

--------------


