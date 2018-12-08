..  _a7-multiple--basics:

A7 Multiple Basics
==================

The Sinclair QL is one of a few computers which allow you to run several
BASIC programs in memory at the same time, multitasking them as if they
were machine code programs.

The QL implementation of this is more flexible than most other
implementations and certainly a lot cheaper, requiring only a standard
QL with Minerva ROM (or a QL with Gold Card and SMSQ/E) at the least.

Both Minerva and SMS provide the ability to use several SuperBASIC
interpreters at the same time, allowing you to work on more than one
BASIC program at a time and run them alongside other BASIC programs.

There is not really a great deal of difference between the two
implementations and so we shall first of all describe the Minerva
implementation (known as MultiBASICs) and then describe the differences
in SMS's implementation (known as Multiple SBASICs).

A7.1 MINERVA MultiBASICS
------------------------

A MultiBasic on Minerva is very similar to the standard QL's SuperBasic
interpreter. This means that once a MultiBasic has been created, you can
use it in practically the same way as you would normal SuperBasic (that
is to say that you can enter programs, load and run programs using the
standard commands set out in this manual).

There are several advantages in using MultiBasics, but the main
advantages are:

- You can have several programs running at the same time (one program
  under each MultiBasic, and one under the standard SuperBasic
  interpreter) in much the same way as you can have several machine code
  programs

- You can tell a MultiBasic to ignore any machine code extensions other
  than the standard ROM keywords (letting you test programs on semi-clean
  machines)

- If a program 'locks up the QL', provided that it is running in a
  MultiBasic, it will only lock up that interpreter and you should be able
  to return to the standard SuperBasic interpreter.

A Multibasic can be created in one of three ways:

	EXEC 'flp1\_multib\_exe' :sup:`\*`\ [,file\ :sup:`x`]\ :sup:`\*` [;cmd$]

or:

	MB

or:

	EXEC pipep :sup:`\*`\ [,file\ :sup:`x`]\ :sup:`\*` [; cmd$]

The first two methods are for use on Minerva ROMs pre v1.93 (the file
multib\_exe is contained on the disk supplied with the Minerva ROM). The
second method is for use on later versions of Minerva which have the
relevant machine code built into the ROM.

A7.1.1 Channels OPENed automatically in MultiBASICs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When one of the above commands is entered, Minerva will examine the
parameters passed using the command. It first of all has to decide how
to set up the standard channels (#0 - the primary command channel and #1
- the primary output channel).

If neither a file nor cmd$ is supplied, for example::

	EXEC pipep

then a single window is opened on screen which is used by both #0 and
#1. #2 is not opened. The actual position of this window on the screen
cannot be set by the user and is dictated by how many MultiBasics are
already running (you can of course redefine #0 and #1 from within the
MultiBasic by using WINDOW, although as both #0 and #1 use the same
window, any attempt to redefine #0 will affect #1 and vice versa).

If however, cmd$ is supplied, for example::

	EXEC pipep;'This is a Command String'

channels #0, #1 and #2 will all be set up as in the standard SuperBasic
interpreter. You can then CLOSE #1 or CLOSE #2 without removing the
MultiBasic. Sections A7.1.2 to A7.1.4 explain how the command string is
dealt with.

If one file (or channel) is supplied, for example::

	EXEC pipep,flp1_inputfile

Minerva will open both #0 and #1 to access that file, whereas if two
files are supplied, #0 is opened to access file1 and #1 is opened to
access file2. If three or more files are supplied, then #0 is opened to
access file1, #1 to access file2, #3 to access file3 and so on (#2 is
omitted).

A7.1.2 Starting a MultiBASIC with the Original QL ROM Commands only
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

cmd$ is used to pass different parameters to a MultiBasic. If the last
character is an exclamation mark (!) then this is taken to be the ROM
marker, and the MultiBasic will start up recognising only the original
keywords contained in the Minerva ROM.

A7.1.3 Multitasking a MultiBASIC Program
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In order to run a BASIC program as a multitasking program, it is
necessary to start a MultiBASIC interpreter and pass the name of the
program to be run as part of cmd$ passed to the MultiBASIC by the
start-up command.

If cmd$ contains the file marker (>), the characters in the string
before that marker are taken to represent a file name which will be
opened to read commands from (similar to a stream device). The
MultiBasic will open both #0 and #1 to this filename and will read the
characters from the file and try to interpret them as a program.

If the program does not open any screen windows and print to them, this
will allow a SuperBasic program to run in the background, for example,
as a filter.

You will be unable to redefine #0 from within the program, as this will
stop the MultiBasic from accessing the command file. This could for
example, be used to test programs::

	EXEC pipep;'flp1_boot>'

A7.1.4 What Happens to the Rest of the Command String?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Having stripped all of the information needed in Section A7.1.2 and
A7.1.3 from cmd$, any characters left in the string supplied can then be
read from within a MultiBasic itself by simply accessing CMD$. For
example::

	PRINT 'Your Name is :'!CMD$

A7.1.5 Loading Toolkits into a MultiBASIC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Any toolkits which are LRESPR'd from within a MultiBASIC are defined as
local to that MultiBASIC and will not be recognised from any other
interpreter (unless you start yet another MultiBASIC from within that
MultiBASIC interpreter). They will therefore be removed when you remove
the MultiBASIC interpreter which loaded the extensions.

For this reason, MultiBASICs should not be used to link in system
extensions (such as BTOOL which adds new device drivers).

A7.2 SMS Multiple SBASICs
-------------------------

These are extremely similar to Minerva MultiBASICs and can be used in
much the same way as MultiBASICs and have the same advantages (except
that you cannot at present tell SMS to start up an SBASIC with only the
standard QL ROM keywords).

On versions of SMSQ which do not incorporate the Hotkey System II
automatically (and therefore need the file HOT\_REXT to be loaded), you
will need to enter the command SB\_THING to create the SBASIC Thing (see
below).

A Multiple SBASIC can be created in one of several ways. The more usual
methods are:

	EXEC 'flp1\_program\_bas' :sup:`\*`\ [,file\ :sup:`x`]\ :sup:`\*` [;cmd$]

or:

	SBASIC [offset]

or:

	EXEP 'SBASIC';cmd$

The first method allows you to automatically load a BASIC program to run
under an SBASIC interpreter multitasking alongside the normal SuperBASIC
interpreter (Job 0). This allows you to start a program up from within
Qpac 2's File Menu.

The second method merely starts up an SBASIC interpreter.

Because SBASIC is implemented as a Thing under the Hotkey System II, you
can also set start an SBASIC Interpreter using the third method, or even
from Qpac 2's Exec Menu. You can even set up a hotkey to start an SBASIC
interpreter. For example::

	ERT HOT_THING ('L','SBASIC')

will start up a new SBASIC interpreter whenever <ALT><L> is pressed.

A7.2.1 Channels OPENed automatically in SBASICs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you use the command SBASIC to start an Interpreter, the initial
windows which will be OPEN depends upon whether an offset parameter is
passed:

- If no offset is passed then all the standard Windows #0,#1 and #2 will
  be OPENed (as per WMON)

- If offset is specified, only #0 will be opened and the offset is used
  to determine the location on screen of that window.

If you use the third method of invoking SBASIC, or Qpac 2's Exec Menu or
a Hot Key to start an Interpreter, then it depends upon whether you pass
a string as a parameter:

- If no string is passed, then the standard windows #0, #1 and #2 are
  OPENed.

- If you pass a string to the interpreter, then no windows are OPENed and
  the string is treated as a command as if it had been entered in the
  command line (see Section A7.2.7 below!). For example::

	EXEP 'SBASIC';'LRUN flp1_PROG_Bas'

is the same as::

	EXEC flp1_PROG_bas

If you instead use a command such as EXEC to start up a program under a
SBASIC interpreter, then no windows will be OPENed by default and the
program will need to OPEN all of its own channels.

However, if any files (or open channels) are specified then (as with
MultiBASICs) these are OPENed as #0, #1 onwards (#2 is not omitted in
this case).

We would refer you to the explanation of EW about setting up Filters by
making use of these facilities.

A7.2.2 The Command String
^^^^^^^^^^^^^^^^^^^^^^^^^

The effect of the command string depends upon the circumstances.

If the SBASIC Interpreter is started using the EXEC command (or similar)
then SMS does nothing with the command string and it can merely be read
from within the SBASIC Interpreter with the function CMD$.

If however, SBASIC is started using the Thing System, then the command
string is executed as if it were a direct command (see Section A7.2.1).

A7.2.3 Starting an SBASIC with the Original QL ROM Commands only
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is currently not possible.

A7.2.4 Multitasking an SBASIC Program
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is much easier than under MultiBASIC and the standard form for
doing this is to use a command such as::

	EXEC flp1_program_bas

Provided that the name of the program ends in \_bas or \_sav, then this
BASIC program will be started as a separate multitasking program running
under an SBASIC Interpreter.

You can also use SBASIC's characteristics as a Thing to start a BASIC
program - see Section A7.2.1.

A7.2.5 Loading Toolkits into an SBASIC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This follows exactly the same rules as on a MultiBASIC.

A7.2.6 Defining the Name of an SBASIC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can do this by using the command JOB\_NAME from within the SBASIC
Interpreter.

If you start an SBASIC using the HOT\_THING command, you can also use
this to define the name of the Job, for example::

	ERT HOT_THING('L','SBASIC','INT 1')

However, all future SBASICs started from the hot key will still be given
the same name!!

A7.2.7 Channel #0, #1 and #2
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Channel #0, #1 and #2 are dealt with differently under an SBASIC
Interpreter than under the main SuperBASIC Interpreter (due to the fact
that they may not be OPEN - see Section A7.2.1).

- All standard QL ROM and Toolkit II commands which would normally
  default to #1 or #2 will access #0 if the relevant default channel is
  not OPEN.

- If a standard keyword tries to access #0 by default (or as in the
  previous paragraph), if #0 is not OPEN already, then a small default #0
  will be OPENed automatically.

- If you have RUN a program under SBASIC (for example used EXEC
  flp1\_PROG\_BAS) and on completion of the program #0 is not OPEN, the
  SBASIC Interpreter will be removed.

- If an error occurs and #0 is not OPEN, a small default #0 will be
  OPENed automatically to report the error.

A7.2.8 Removing an SBASIC
^^^^^^^^^^^^^^^^^^^^^^^^^

CLOSE #0 will remove an SBASIC if a program is not RUNning. However, it
is better to use the explicit command QUIT.

A7.2.9 Keywords Which are Useful in SBASICs
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Reference should be made to SEND\_EVENT and WAIT\_EVENT.

DEVTPYE allows you to find out is a channel is OPEN.

QUIT and JOB\_NAME are only of any relevance from within an SBASIC.

WMON and WTV allow you to move the SBASIC windows.



