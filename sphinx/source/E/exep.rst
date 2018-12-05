..  _exep:

EXEP
====

+----------+------------------------------------------------------------------+
| Syntax   | EXEP filename [;cmd$] [,Jobname$] [,options] or                  |
|          |                                                                  |
|          | EXEP Thingname$ [;cmd$] [,Jobname$] [,options] (version 2.17+)   |
+----------+------------------------------------------------------------------+
| Location | HOTKEY II                                                        |
+----------+------------------------------------------------------------------+

The first variant of the EXEP command is similar to the EX
and EW commands provided by Toolkit II. However, not only does EXEP
allow you to pass a command string to the program being called (as with
EX or EW), but you can also supply the Job name which will be shown in a
list of the Jobs currently loaded into memory.

In order to make various
'problem' programs work correctly under the Pointer Environment, it is
sometimes necessary to pass various parameters (options) to the Hotkey
System when the program is called in order to tell it how to treat the
program.

The command EXEP allows you to execute a program (in the same
way as with EXEC), but at the same time, pass these parameters to the
Pointer Environment. The parameters (or options) currently supported
are:

- P [,size]- This tells the Hotkey System that the program is a Psion
  program (eg. Quill) which will try to grab all of the available memory.

  If size is not specified, then the Hotkey System will ask the user to
  specify the maximum amount of memory (in kilobytes) that the program
  should use before the program actually starts. Otherwise, the program
  will be allowed to use size
  kilobytes of memory (if available).

  When the Pointer Environment was
  first released, Qjump produced a program (Grabber) which could be used
  to amend the amount of memory addressed by the Psion programs once and
  for all - if this program has been used on your copies of the Psion
  programs, then do not use this option.

- G [,x,y,a,b] - When a program is
  started, the Pointer Interface will store the area of the screen
  contained under each window as it is opened, restoring any part of the
  screen is no longer covered by an active window.

  This provides
  non-destructive windows, one of the major assets of the Pointer
  Interface. However, some programs have a habit of opening windows,
  writing to the screen and then closing the window so that the text
  cannot be altered - creating background information.

  Unfortunately, due
  to the way in which the Pointer Interface works, as soon as this window
  is closed, the background information would be lost.

  The solution to
  this is to use a guardian window (created using this parameter) which
  specifies the area of the screen which the program is allowed to use and
  which must therefore not be restored until the program has ended (even
  if there are no current windows open on that area). The parameters are
  used to open a guardian window x pixels wide by y pixels high at the
  origin (a,b).

  Any attempt by a program to open or resize a window so
  that part of it would fall outside this Guardian window will fail.

  If you do not pass the size of the Guardian window as a parameter (eg. EXEP
  flp1\_Graph\_exe,g), the maximum permissible window size will be assumed
  (eg. 512x256 on a standard QL).

- F - Some programs which use KEYROW to read
  the keyboard, or access the screen directly, can wreak havoc when
  multitasking alongside other programs.

  This parameter causes the
  computer to only pass any keypresses read with KEYROW to the program
  started with EXEP.

- U - With some programs, for example, a clock, it is
  desirable for this to be updated on screen even though it is not the Job
  at the top of the pile (ie. it is overwriting part of the current Job's
  windows).

  The Pointer Interface will allow you to do this by passing the
  u parameter (for unlock), for example::

    EXEP flp1_Clock,u

The second syntax of EXEP is similar, except that instead of loading a
task stored with the given filename, it searches through the Thing list
for an Executable Thing with the given Thingname and then (if present),
will start that up as a new Job (if it is not present, then EXEP will
look on the default program device for a file called Thingname).

For example, if you have QPAC2 present, EXEP Files will call up the files
sub-menu (in the latest versions of QPAC2, you could use, for example::

    EXEP files;'\S \D flp1__exe \O v','View _EXE'

to create a View files menu which will list all of the files on flp1\_
which end with \_exe, without any sort order; the job being called 'View
\_EXE' in the Jobs list).

**Example 1**

Consider the following program::

    100 MODE 4
    110 OPEN #0,CON_10x10a132x66
    120 OPEN #1,CON_448x200a32x16
    130 PAPER 0:INK 7:CLS
    140 BORDER 1,2:AT 10,9:PRINT 'Y AXIS'
    150 AT 15,35:PRINT 'X AXIS'
    160 OPEN #1,CON_248x100a132x66:BORDER 1,4
    170 PAUSE

If this program was compiled (without windows being copied across) and
then run, as soon as line 160 was reached, the information around the
sides of the graph would be lost! The reason for the PAUSE in line 170
is that as soon as the compiled program reached the end, it would close
all of its windows, and you would not be able to see anything! The
answer is to use a Guardian window (created using this parameter).
Presuming that the above program has been compiled under the filename
flp1\_Graph\_exe, you could use the line::

    EXEP flp1_Graph_exe,G,448,200,32,16

to define a Guardian window 448x200 pixels with its origin at (32,16).

**Example 2**

Try for example, compiling the following program and starting it
with::

    EXEP flp1_Test_exe,u

(presuming that is the filename you allocate to it)::

    100 OPEN #1,con_512x256a0x0
    110 REPeat Loop
    120   PRINT KEYROW(0)
    130 END REPeat Loop

You will find it very difficult to do anything (including removing this
job). The solution is to pass this parameter to the Pointer Interface
which tells it to Freeze the program when it is in buried under another
Job's windows (eg. if you used <CTRL><C> to change to another Job). For
example, use the line::

    EXEP flp1_Test_exe,f

**Example 3**

The SuperBASIC line::

    EXEP flp1_EDT;'flp2_Text',Editor,g

will start up an editor stored under the filename flp1\_EDT, which will
be given the Job name 'Editor' (which will be shown for example in the
JOBS table), provide it with a guardian window of 512x256, and tell it
to load a file called flp2\_Text.

**NOTE 1**

Before v2.21 of the Hotkey System II, you could not pass a command
string to the program being called.

**NOTE 2**

The various parameters can be mixed together, for example::

    EXEP flp1_Graph_exe,F,G,448,200,32,16;'ser1'

**NOTE 3**

Versions earlier than v2.24 will not allow you to alter the Job Name,
which will otherwise be the name given the program when it was created.

**CROSS-REFERENCE**

:ref:`thing` allows you to test whether or not a
given Thing is present. :ref:`ex`,
:ref:`exec`, :ref:`ew` and
:ref:`exec-w` are all similar to the first variant
of :ref:`exep`.
:ref:`get-stuff-dlr` will call up the QPAC2 files
sub-menu and allow you to read the chosen filename.
:ref:`hot-thing` allows you to set up a hotkey
to call an Executable Thing.

--------------


