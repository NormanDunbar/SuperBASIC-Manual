..  _is-ptrap:

IS\_PTRAP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  IS\_PTRAP (trapno [,status] )                                    |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

Not only does PEX allow you to enable background screen access for
specific Jobs or windows, but you can also dictate how the various TRAP
#3 machine code routines should be treated (which has a knock on effect
on programs, since these routines are generally used to access the
screen). For each TRAP #3 routine, you can specify the following status:

- 0 - if the window is buried, then halt the program when this routine is
  called (this is the normal case under the Pointer Environment)

- 1 - Enable
  background screen access for this routine (if PEX is active - see PEON).

- 2 - This only enables background screen access for this routine if both
  PEX is active and PXON has been used to enable SD.EXTOP routine calls.

- 3 - If the window is buried, then just ignore this call and allow the
  program to carry on. This could be used for example to allow a program
  which has a large amount of calculation to do to carry on in the
  background, printing a message to the screen only when its window is not
  buried to inform the user of its progress.

On JS and MG ROMs, only
values of 0 and 3 are recognised - PEON activates all routines as having
a status of 3 on these implementations. On all other implementations
using the defaults provided with PEX, PEON activates all of the
following routines as having a status of 1.

- $05 iob.sbyt
- $07 iob.smul
- $09 iow.xtop to $0B iow.chrq
- $0F iow.dcur to $36 iog.sgcr
- $6C iop.flim
- $72 iop.rpxl to $76 iop.spry

If you use PEX\_SAVE, PEON will set the
various routines as specified by you previously. Not all TRAP #3 machine
code routines should be treated in this way - the following routines
should be avoided if possible:

- $00 iob.test
- $01 iob.fbyt
- $04 iob.elin
- $0C iow.defb
- $0E iow.ecur

If you decide to use this function to
fine-tune the operation of PEX, then you can save the various settings
using the PEX\_SAVE command. If status is not specified, then the value
returned will be the status of that particular machine code routine. If
a negative number is returned then you probably have a JS or MG ROM (or
earlier). If you are writing a program which will is to run on all QLs,
then you may wish to use IS\_PTRAP to set all of the routines to 0 if
the QL ROM version is JS, MG or earlier.

**NOTE**

You need a good book on the QL's operating system to be able to use this
feature.

**CROSS-REFERENCE**

See :ref:`peon` for more details. The QDOS/SMS
Reference Manual Section 15 contains details of the various TRAP #3
calls.

