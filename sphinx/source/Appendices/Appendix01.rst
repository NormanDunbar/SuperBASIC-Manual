..  _a1-minerva:

A1. Minerva
===========

A1.1 INTRODUCTION
-----------------

Minerva is a brand new operating system which has been designed for the
QL by QView, parts of which are already incorporated in QDOS emulators.

Based upon the existing QL Roms, it has now developed into a system
which does not rely upon any of the existing code and thereby side-steps
problems with copyright. However, due to the new coding, there are bound
to be one or two slightly grey areas where compatibility must meet with
compromise. From the SuperBASIC point of view, there are no real
problems with using programs written for earlier ROMs (possibly
excluding FB Roms which insisted on using AT y,x instead of AT x,y), and
Minerva merely enhances this superb programming language to provide the
SuperBASIC programmer with one of the most flexible and quickest
implementations of BASIC ever devised.

However, there are one or two enhancements made by Minerva which are
unavailable on earlier ROMs, which of course will limit the portability
of programs which use these advanced features (unless the SuperBASIC
program is compiled with QLiberator or Turbo).

The idea of this section is therefore just to point out some of the
possible pitfalls with which programmers will be faced when writing
SuperBASIC which is specifically designed to run on all versions of
Minerva.

**WARNING:**

v1.98 of Minerva caused more problems than it solved and you should
therefore obtain v1.97 if you have this version of the operating system.

A1.2 Windows and Closing Windows
--------------------------------

A problem exists with some versions of Minerva and Lightning SE. The
problem appears to be that if Lightning is switched on, and then windows
are opened on screen, unless they are closed in the reverse order to
which they were opened, they will remain visible on screen despite NEW
or MODE commands until another window with the same channel number is
opened.

Example:

::

    100 OPEN#3,scr_448x200a32x16: PAPER#3,2: CLS#3
    110 OPEN#4,scr_448x200a32x56: PAPER#4,4: CLS#4
    120 CLOSE#3: CLOSE#4

This program will cause the problem and you will be unable to remove
either #3 or #4 from the screen until they are re-opened!

To avoid the problem, alter line 120 to read:

::

    120 CLOSE#4: CLOSE#3

QJump's Pointer Environment prevents this problem occurring and this can
be regarded as a standard system addition.


A1.3 Dual Screen Mode
---------------------

Perhaps the greatest problem with programs written on earlier ROMs is
that they (or machine code extensions used by them) tend to assume that
the screen display will always begin at 131072 ($20000) and that the
system variables will begin at 163840 ($28000). When Minerva is
started-up, the user can opt to run in Dual Screen Mode, which makes two
screens available to the programmer, the first of which is located at
the standard display address (131072 - $20000 in hexadecimal) and the
second of which is located on top of the old system variables address
(163840 - $28000 in hexadecimal) - the system variables are moved out of
the way. Programs can run on either of the screens and should be written
so that they make no assumptions about the start address of the screen.

Minerva allows the user to alter which screen a program will run on
before the program is actually loaded, by using the command MODE 96,-1,
and therefore the programmer has no control in general over which screen
will be used.

This problem can also exist with the THOR XVI which allows several
screens to be in operation at any one time.

Various functions exist to find the start address of the current screen
(eg. SCREEN) and also to find the start address of the system variables,
(eg. SYS\_BASE). These functions should be used whenever possible.

The other main problem is that in current versions of Minerva, when a
window is opened on screen, Minerva attempts to open it in the MODE of
the currently displayed screen, rather than the mode of the screen on
which it will be open. This can lead to various problems, such as
illegible writing and flashing on screen. The answer to this is to
ensure that the current screen when the program is started is also the
displayed screen - see MODE.

Other problems exist when using the dual screen mode with both Lightning
and the Pointer Environment, which can make it extremely difficult to
change MODEs on only one screen in the dual screen mode. At the moment
there is no answer to this, other than to pester Digital Precision and
Qjump to produce compatible products. There may also be similar problems
with Speedscreen, but we have been unable to test this.

The other remaining problem is that current versions of Turbo and
Supercharge do not support Minerva's dual screen mode, and programs
compiled with either of these packages will not run in the dual screen
mode.

A problem which users with printers may or may not have noticed, is that
Minerva tends to lose characters on their way to the printer when in
dual screen mode.

A1.4 Border
-----------

On some early Minerva ROMs (and on one or two of the THOR ROMs), the
BORDER command will not work correctly unless a parameter is supplied.

The original ROM accepted BORDER on its own to switch off the border on
#1 (although this was not pointed out by the QL Manual). It is therefore
essential that to retain compatibility BORDER 0 is used.

A1.5 Empty Brackets
-------------------

An empty bracket is always regarded as a syntax error by original QL
ROMs whereas Minerva tolerates them, for example to indicate that a
function is called with a parameter, eg. DATE(). If a program should be
portable than you have to avoid this style because all ROMs other than
Minerva and SMS mark such lines with a MISTake:

::

    100 MISTake PRINT DATE()

Since DATE() and VER$() are effectively the same as DATE and VER$, it is
recommended to use the latter syntax.

.. rubric:: A1.6 INTEGER TOKENISATION
   :name: a1.6-integer-tokenisation

From v1.79 onwards, Minerva has tidied up the storage of numbers in
SuperBASIC programs, in that if integer tokenisation is enabled, any
numbers contained in a program are stored in as few bytes as possible.
Although programs which are LOADed are unaffected by this since the
interpreter converts the ASCII characters into the internal format as
the program is loaded, certain utilities are unable to cope with integer
tokenisation. In particular, the Supercharge compiler and early versions
of the Turbo (pre v4.3) and QLiberator (pre v3.32) compilers are unable
to compile such programs.

If you use the QLOAD utility from Liberation Software, this stores a
program in its internal format so that it can be loaded very quickly.
Unfortunately, this does mean that programs which are QSAVEd on Minerva
whilst integer tokenisation means that if when the program is QLOADed
with integer QSAVEd, you can end up with a mixture of integer tokens and
floating point tokens within the same program.

To convert a program under Minerva which has been written with Integer
Tokenisation enabled so that it may be compiled with Supercharge or
early versions of Turbo, or even QLOADed on a different ROM version, you
will need to use something along the lines of:-

::

    SAVE ram1_convert_bas
    POKE \\212,128
    LOAD ram1_convert_bas

If you try to QLOAD a program which has been QSAVEd with Integer
Tokenisation enabled, on a different ROM, you will notice that various
numbers have disappeared from the listing.

A1.7 MultiBASICs
----------------

Minerva allows you to have several BASIC interpreters which can all
multitask. Essentially, you retain the original SuperBASIC interpreter
together with several copies of that interpreter, each of which is known
as a MultiBASIC.

A MultiBASIC will in fact operate in the same way as SuperBASIC, and you
can link different toolkits with each copy of the interpreter, knowing
that they will not be available to the other existing interpreters.

The only problem is that many toolkits have been written with only the
original SuperBASIC interpreter in mind, and some commands are therefore
unable to access the MultiBASIC's variables. Fortunately, the majority
of commands and functions do in fact still work with MultiBASICs, unless
used from within a compiled program.

A1.8 Strings
------------

Minerva has altered the way in which strings are handled, in much the
same way as SMSQ/E - please refer to DIM for an explanation of the way
in which dimensioned and undimensioned strings are dealt with on the
various QL implementations.

There was however a problem prior to v1.98 of Minerva in that if you
concatenated two strings together to make a string longer than 32764
characters, this could corrupt BASIC. An example of concatenation is:

::

    a$ = 'Hello' & b$
    
    


