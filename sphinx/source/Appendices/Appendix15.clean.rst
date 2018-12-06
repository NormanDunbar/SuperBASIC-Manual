..  _a15-mouse--drivers:

A15 Mouse Drivers
=================

A mouse in computing terms is a small box which can be pushed around the
desk and as it moves, it is translated by the computer into cursor key
movements and hence moves the cursor (or a pointer) on screen instead of
using the keyboard.

Depending on the implementation, a mouse can make it very easy to use
programs, providing a quick means of moving the pointer on screen.

The type of mouse which can be used and how you need to link it to the
computer depends upon the QL implementation being used.

Many other devices have been created which send the same information as
a PC mouse and should therefore work with drivers which support PC mice.
This includes, trackerballs and bitpads.

A15.1 A Mouse for the Standard QL
---------------------------------

There have been several types of mouse which have been produced over the
years to be linked to a Sinclair QL. However, there are now only really
three types of mouse commonly used with the QL and its various guises.

A15.1.1 Quanta Mouse (or QIMI Mouse)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This mouse is linked into a hardware interface which needs to be plugged
into the computer - fitting involves opening up the QL case, carefully
removing one of the microchips from its socket and plugging in the
interface (plugging the microchip back into the top of the interface). A
long lead is attached to the interface into which you plug the mouse.

The mouse needs to be an Atari-style 2 button mouse. Limited cursor key
emulation is provided by holding down the left hand mouse button as the
mouse is moved around.

This mouse will not work with some older versions of the Pointer
Interface files (PTR\_GEN and WMAN) - upgrade them if you notice a
problem.

A15.1.2 AURORA Mouse Interface
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The AURORA replacement motherboard, includes a socket into which a QIMI
compatible mouse may be plugged - this emulates the QIMI Mouse Interface
described above.

A15.1.3 Serial Mouse
^^^^^^^^^^^^^^^^^^^^

This consists of a small wire connector which plugs into the QL's serial
port and allows a standard PC serial mouse to be plugged in. This in
itself will have no effect on the QL and you will also need to link in a
serial mouse driver which will need to be set up for either a two-button
mouse or a three button mouse (depending on which you have plugged into
the serial port).

The main problem with using Serial Mice is that they tend to need the
serial port set to BAUD 1200 which can be problematic if you need to use
a printer for example, on the other serial port running at BAUD 9600.
However, the serial mouse drivers can cope with this, generally
suspending the mouse driver whenever the baud rate is altered, or if the
other serial port is open (with a different Baud rate).

Another problem with Serial Mice is that they do not work very well with
communications software (such as mail-box programs); unless the Modem
(or mouse) is run through SuperHERMES. The problem is due to the
original QL design of the serial ports - a link between the serial ports
mean that if you move the mouse whilst using communications software, it
will corrupt data.

You can also have problems of the serial ports holding onto the
information sent by the mouse and then releasing it all at once
(particularly with three-button mice).

Although a serial mouse can therefore be used on a standard QL, you
should consider obtaining Hermes or SuperHermes which allow you to set
independent BAUD rates for each port and thereby avoids this problem
altogether (allowing you to still use the mouse whilst a channel is open
to a modem for example). SuperHermes also provides additional serial
ports which would allow you to use a Modem, Printer and Serial Mouse at
the same time for example.

Another problem with serial mice is that the 3-button mice can be
difficult to set up - some will automatically power up in 2-button mode
unless you hold down a mouse key when you switch on the QL. Others have
switches which force the mouse signals on a PC to generate straight
vertical or horizontal movements. It is therefore recommended that you
buy a suitable mouse from the supplier at the same time as buying the
serial mouse driver!!

There are three Serial Mouse drivers available for the standard QL:

SERMouse (by Albin Hessler Software)
""""""""""""""""""""""""""""""""""""

This is provided with SMSQ/E for the Gold Card family.

It is ideally for use under the Pointer Environment, although you can
use it to control the cursor as well if you prefer - see SERMCUR and
SERMPTR. It will handle both 2 and 3- button mice.

If you want to be able to read the position of the pointer (as
controlled by the mouse), you will need to use either EasyPTR or Qptr
commands. There are however, several commands added to SuperBASIC to
control the mouse - see SEMSPEED.

DIY Toolkit Serial Mouse (Vol I)
""""""""""""""""""""""""""""""""

This is a cardware version of a mouse driver, which comes with several
versions, allowing use of 2 and 3- button mice and also versions which
will only move a mouse pointer around the screen and ones which will
also emulate the cursor keys and various buttons on the keyboard. You
also have to load a version which is set up for the serial port which
you intend to plug the serial mouse into.

Note that current versions do not currently move the Pointer in the
Pointer Environment, although a commercial version of this driver is
available (called ms\_mus) which contains the same commands as SERMouse
and can be used to control the Pointer, although this driver appears to
be a little more selective over the serial mice which can be used with
it.

Several commands are added to SuperBASIC to allow you to read the
position of the mouse and control the mouse - see X\_PTR% and PTR\_ON.

SuperHERMES
"""""""""""

This includes a low speed serial interface into which a PC- style serial
mouse can be plugged, in much the same way as the Albin Hessler
SERMouse.

It emulates the QIMI Mouse Interface (see above).

A15.2 A Mouse for QPC / QXL
---------------------------

You cannot use a QL mouse driver with these emulators and will need
instead to set up the system to load a DOS mouse driver before QPC or
QXL is initiated. If the mouse does not have a PS/2 style mouse
connector, you will also need to configure SMS so that it does not
connect a serial port to the COM port to which the mouse is connected.

PS/2 style mice work with later versions of QPC (and all versions of
QXL) without having to disable either serial port.

Having done this, the DOS mouse normally used with the PC can be used
from within QPC and QXL to control programs written for the Pointer
Environment.

Some early versions of SMSQ/E had problems if you disabled one of the
serial ports (neither of them worked!) - you had to disable both serial
ports for the mouse to work!!

A15.3 A Mouse for ATARIs
------------------------

You cannot use a QL mouse driver with these emulators.

You can however use the Atari's mouse as soon as the file ATARI\_xxx
file is loaded which allows the Pointer Environment to work correctly
with the mouse.

A15.4 A Mouse for Unix and Macintoshes
--------------------------------------

The QL emulators for these computers simply recognise the mouse which is
normally used by the computer - do not try loading a QL mouse driver.

On the MacIntosh, you will need at least v2.1 of the Q- Emulator program
if the mouse is to work with the Emulator.

You can however use the Atari's mouse as soon as the file ATARI\_xxx
file is loaded which allows the Pointer Environment to work correctly
with the mouse.

A15.5 A Mouse for the Amiga
---------------------------

You cannot use a QL mouse driver with this computer.

Amiga QDOS has been able to use the Amiga's own mouse to control its
software since v3.20. Various functions and commands have been added to
SuperBASIC to control the mouse, as with the DIY Toolkit version (see
PTR\_ON).
