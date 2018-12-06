..  _a13-extended-pe:

A13 Extended Pointer Environment
================================

It would appear likely that future QDOS compatible operating systems
will be written by Tony Tebby, the original designer of QDOS, and the
author of the Extended Pointer Environment. The Extended Environment is
supplied built-in with the Atari-QL Emulators, the QXL, and SMSQ/E, and
is provided with various software packages for the Sinclair QL and other
emulators (the only QDOS compatible computer it will not work on
successfully is the Thor XVI).

When supplied with software, the user will receive a copy of the Pointer
Interface (called ptr\_gen), the Window Manager (called wman) and the
Hotkey System II (called hot\_rext). These system extensions are
backwardly compatible and therefore you should only ever need to install
the latest version of each package once to be able to run all software
written with the Pointer Environment in mind (although see TH\_FIX).

SMSQ/E comes complete with its own version of the Pointer Environment
files built in and therefore these files should not be loaded into a
computer with SMSQ/E - if the version of the Pointer Environment built
into SMSQ/E is not recent enough for the software you are using (an
error will be generated), you need to update your copy of SMSQ/E.

The Pointer Interface provides sensible control of the QL's multitasking
abilities, ensuring that whenever part of a program's windows are
covered by another program, that program is hidden and cannot try to
access the screen (if you think of all of the programs' windows as tiles
on the screen, only those tiles which are at the top of the pile can be
accessed). It also provides you with a pointer which can be moved around
the screen with either the cursor keys or a mouse in order to select
different options or programs.

The Window Manager provides various utilities which enable programs to
make use of the Pointer Interface, allowing them to generate menus which
can be accessed by using the pointer, and which provide programs a
similar feel - making it easier for a user new to the program to become
accustomed to how to operate the program.

The Hotkey System II provides both a Hotkey System and a Thing System
(both are independent of each other).

The Hotkey System allows you to set up various keys which (in
combination with <ALT>) will provide direct access to different
programs, as well as allowing you to stuff strings into the keyboard
queue, pass information from one program to another and to recall the
last line to have been typed. This facility is known as either ALTkeys
or Hotkeys.

The Thing System is a means of providing QDOS with a list of named
resources which can be accessed by different programs, which merely need
to check if the resources they require are present.

Some general notes about writing programs which will work under the
Pointer Environment appear in Section 4.

**NOTE 1**

If you have Hotkey System II installed, then you will need to use the
command HOT\_GO before any of the ALTkeys will work.

**NOTE 2**

Programs such as PIE and PEX affect the way in which the Pointer
Environment works - see PIE\_ON and PEON.


