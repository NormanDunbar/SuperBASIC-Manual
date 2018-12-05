..  _ew:

EW
==

+----------+----------------------------------------------------------------------+
| Syntax   |  EW file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`\ }]\ :sup:`\*`|
+----------+----------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                                 |
+----------+----------------------------------------------------------------------+

This command causes the given file (which must be an executable program) to be executed.

If the drivename is not given, or the file cannot be found on the given device, EW
will load the first file from the default program directory (see PROGD$), with subsequent
programs being loaded from the default data directory (see DATAD$). The calling program
will be stopped whilst the new job is running (ie. the new job cannot multitask with the
calling program). If you supply any channels (which must already be open in the calling
program) or filenames as parameters, these form channels which can be accessed by the job.

If your program has been compiled with QLiberator or is to be run as an SBASIC job under
SMS then each supplied channel will become #0, #1, #2 ....

Note that with Turbo compiled programs the channels work backwards and will become #15, #14,
#13 ... To access these channels from within the job, merely ensure that the job does not
try to open its own channel with the same number, and then write the program lines as if
the channels were open. Further, you can pass a command string (cmd$) to the program
specifying what the executed job should do. It depends on the job what cmd$ should look
like and also how you will access the given string. The Turbo and QLiberator compilers
include commands in their Toolkits to read the supplied string; and Minerva MultiBASICs
and SMS SBASICs include the function CMD$  which allows you to read the supplied string.

If you have not used one of these compilers to produce the job, then you will need to
read the string from the stack. Please note that the command string must appear as the
last parameter for the command. The command string can be explicit strings and names as
well as expressions. However, variables must be converted into expressions, for example
by::

    EW 'flp1_xchange';(dataspace)

On some very early versions of Toolkit II, you needed::

    EW 'flp1_xchange';dataspace&""

Executable programs often return an error code back to the owner job (the program which
started it). Especially with 'C' compiled programs, this will be non-zero if there are any
errors. EW stops the owner job if this happened. There is unfortunately no way to stop
this from happening unless you use error trapping (eg. WHEN ERRor, or Q\_ERR\_ON
from QLiberator).

**Example 1**

::

    EW QED;"flp1_readme_txt"

The editor will be started from the default program directory and told
to load the file readme\_txt.

**Example 2**

::

    EW mdv1_QUILL

will start QUILL from microdrive 1.

**NOTE 1**

There are problems with EW and EX in Toolkit II v2.05 (and previous
versions) which make them unreliable and difficult to use with compiled
programs. The main problem lay in what was classed to be the owner of a
secondary Job. From v2.06 onwards, the owner for EX has been Job 0 and
the owner for EW, the current Job.

**NOTE 2**

TinyToolkit and BTool allow you to break out of a program started with
EW at any time by pressing <CTRL><SPACE> - the program can then be
treated as if it was started with EX.

**NOTE 3**

On some versions of the QL ROM (and Toolkit II), unless the Pointer
Environment is loaded, you may need to press <CTRL><C> to get back the
cursor at the end of the task.

**NOTE 4**

You cannot use EW (or similar) to execute a file stored on a PC or TOS
disk (even with Level-3 Device Drivers) - see the Device Drivers
Appendix, in particular the notes on Level-3 Device Drivers for further
details.

**MINERVA NOTES**

As from v1.93+, MultiBASICs can be started up with the command:

    EW pipep :sup:`*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`}]\ :sup:`*` [;cmd$]

Prior to this version, you needed to load the file Multib\_exe contained on
the disk supplied with Minerva and use the command:

    EW flp1_Multib_exe :sup:`*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`}]\ :sup:`*` [;cmd$]

How any supplied channels are dealt with is slightly different to all other
implementations. Its effect depends on how many channels are passed:

- No channels passed - MultiBASIC started with a single small window which is
  the same for #0 and #1.
- One channel passed - This becomes both #0 and #1.
- Two channels passed - These become #0 and #1 respectively.
- Three or more channels passed - The first two become #0 and #1 respectively, then any
  additional ones become #3 onwards.

Minerva MultiBASICs also treat any command string passed to them in a special way:

- If the last character of the command string is an exclamation mark (!), then the
  MultiBASIC is started up with the original keywords built into the ROM,
  and any which had been linked into SuperBASIC subsequently (for example
  Toolkit II) will not be available to that MultiBASIC. This character is
  then removed from the command string before it can be read by the
  MultiBASIC.

- If the command string contains the greater than sign
  (>), then anything which appears before that character in the string, is
  opened as an input command channel (thus allowing you to run a
  MultiBASIC program in the background) and then all characters up to and
  including the greater than character are deleted from the command string
  before it can be read by the MultiBASIC.

**Example**

Take a simple BASIC program to convert a given file (say
flp1\_TEST\_TXT) into uppercase::

    110 REPeat loop
    120   IF EOF(#0) THEN EXIT loop
    130   INPUT #0,a$
    140   IF a$='' THEN NEXT loop
    150   FOR i=1 TO LEN(a$)
    160     IF CODE(a$(i))>96 AND CODE(a$(i))<123 THEN
    170       a$(i)=CHR$(CODE(a$(i))-32)
    180     END IF
    190   END FOR i
    200   PRINT a$
    210 END REPeat loop
    220 IF VER$(-1):CLOSE #0

Save this as flp1\_UC\_bas and then enter the command::

    OPEN #3,con
    EW pipep,flp1_test_txt,#3;'flp1_UC_bas>'

or, prior to v1.93, use::

    OPEN #3,con
    EW flp1_Multib_exe,flp1_test_txt,#3;'flp1_UC\_bas>'


The last line checks to make sure this program is not being run from
the original SuperBASIC interpreter (job 0) in which case, it then
closes #0. Unfortunately, on v1.97 (at least), this program fails to
spot the end of the file (try PEND instead of EOF), and therefore
reports an 'End of File' error on completion. Oddly, this error is not
reported if you use EX to run the program.

**SMS NOTE**

SMS allows EW and EX to run basic programs in the background, as an
SBASIC job. For example, using the Minerva example program above, this
could be used with the line::

    EW flp1_UC_bas,flp1_test_txt,#3

This does not report an error on completion. Beware however that prior
to v2.69, this command would not work in Qliberated programs to start an
SBASIC program. Because of this ability, SMS v2.58+ has amended the EW
set of commands so that it searches for a file in much the same way as
LOAD under SMS.

Taking a default program device to be flp1\_,

::

    EW ram1_TEST

will look for the following files:

- ram1_TEST
- ram1_TEST_sav
- ram1_TEST_bas
- flp1_ram1_TEST
- flp1_ram1_TEST_sav
- flp1_ram1_TEST_bas

**CROSS-REFERENCE**

For further information see :ref:`ex`.
:ref:`sbasic` allows you to set up several SBASIC
jobs under SMS. :ref:`mb` allowed you to start up a
MultiBASIC on early versions of Minerva. Please also see the appendix on
Multiple BASICs.

--------------


