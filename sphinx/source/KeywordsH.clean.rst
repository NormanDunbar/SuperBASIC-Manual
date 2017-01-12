
==========
Keywords H
==========


..  _headr:

HEADR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  HEADR file, adr                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command reads the file header of the specified file and stores it
at the specified address (adr) in memory. Note that file must be the
full filename.

**CROSS-REFERENCE**

See :ref:`gethead` (and
:ref:`fgeth-dlr`)!

--------------


..  _heads:

HEADS
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  HEADS file, adr                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command sets the file header of the specified file to the 64 bytes
stored at adr.

**CROSS-REFERENCE**

See :ref:`headr` and
:ref:`sethead` (and
:ref:`fgeth-dlr`)!

--------------


..  _hex:

HEX
===

+----------+-------------------------------------------------------------------+
| Syntax   |  HEX (hex$)                                                       |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function returns the decimal value of a hexadecimal number. The
hexadecimal system of numbering is based upon base 16, which means that
instead of each digit being in the range 0..9 (as in decimal), each
digit can actually hold the value 0..15. 

Because a digit can only be one
character, a system was devised for representing the value 10..15 -
these values are represented by the letters A..F respectively. Any
digits outside the range 0..F will cause an 'error in expression'. 

Hex$ can be anything in the range $80000000 (which equates to -2^31) to
$79999999 (which equates to 2^31-1).

**Examples**

::

    PRINT HEX('F') 

will print the value 15. 

::

    PRINT HEX('10') 
    
will print the value 16.

**CROSS-REFERENCE**

:ref:`hex-dlr` works the other way around, converting
decimal numbers into their hexadecimal equivalent. See
:ref:`bin` and :ref:`bin-dlr` for the
binary versions. SMS users can achieve the same thing by using, for
example::

    PRINT $1AB 
    
instead of::

    PRINT HEX ('1AB').

--------------


..  _hex-dlr:

HEX$
====

+----------+-------------------------------------------------------------------+
| Syntax   || HEX$ (decimal,nibbles)  or                                       |
|          || HEX$ (decimal [,nibbles]) (THOR only)                            |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function converts a signed integer decimal number to the
equivalent hexadecimal number to a specified number of nibbles (ranging
from 1 to 32 - there are 4 nibbles in one digit). If nibbles is not
divisible by four, it is rounded up to the next multiple of four.
Negative values are also handled correctly provided that nibbles is set
to 32. The range of decimal is -2^31<decimal<2^31

**Examples**

::

    HEX (HEX$ (x,4)) 
    
Will = x if x is any number between 0 and 15. 

::

    PRINT HEX$ (300,10) 
    
will return the value 12C. 

::

    PRINT HEX$ (300,8) 
    
will return the value 2C.

**THOR XVI NOTE**

The THOR XVI version of this command will accept a value of zero for
nibbles {or even the command in the form HEX$(decimal)}. In both of
these cases the result is returned in the least number of Hexadecimal
digits necessary to store the number, for example:: 

    PRINT HEX$(32) 

gives the result 20.

**THOR XVI WARNING**

A second parameter of zero may crash some versions of this command
except on v6.41 of the THOR XVI.

**CROSS-REFERENCE**

See :ref:`hex` and :ref:`bin`,
:ref:`bin-dlr`.

--------------


..  _hget:

HGET
====

+----------+-------------------------------------------------------------------+
| Syntax   |  HGET [#ch] length [ , access [, type [, dataspace [, extra ]]]]  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to access the various parameters which are
contained in the header of the file attached to the specified channel
(default #3). The command will set the supplied parameters to the
required information. 

If the specified channel is not open to a file, then an Invalid Parameter error is reported. 

The information returned is as follows: 

- length = Length of the File 
- access = File Access Key 
- type   = File Type 
- dataspace = Dataspace for Executable Files 
- extra = Extra Information

**NOTE**

You will not be able to compile this command with Turbo or SuperCharge
due to the fact that it alters its own parameters.

**CROSS-REFERENCE**

:ref:`hput` saves the file header information. See
:ref:`fgeth-dlr` for information about the file
header. See also :ref:`headr` and
:ref:`gethead`.

--------------


..  _his-set:

HIS\_SET
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_SET #channel                                                |
+----------+-------------------------------------------------------------------+
| Location |  History Device (Needs Pointer Environment)                       |
+----------+-------------------------------------------------------------------+

The History Device is an extension to the internal QDOS routine
IO.EDLIN which reads editable text input from the keyboard; IO.EDLIN is
used if, for example, you use INPUT on a window - even the interpreter
uses IO.EDLIN to get its commands from #0. But let's see how the History
Device alters keyboard input. 

The toolkit must be loaded into Resident
Procedure Memory (with RESPR) before any Jobs are started, but after the
Pointer Environment and Lightning / Speedscreen (or any other drivers
which alter the con\_ device driver) are installed (if either of these
two packages are required). 

Often, if you respond to a set of questions
asked by a program, the same answers crop up again and again. For
example, take the SuperBASIC interpreter, if you have entered a command,
it will carry it out and wait for the next command to be entered. You
may find that you want to type in the same text - or something which you
entered a few loops ago again. 

Toolkit II and the Hotkey System install
a last line recall when the <ALT><ENTER> key combination is pressed (can
be configured with the Hotkey System) - this is widely accepted (it's
even supported by keyboard interfaces), but, has not proved to be very
reliable or useful: recalling the last line typed generally works well,
but for lines which were entered some time ago, things become easily
messed up. 

The History Device sits on the afore-mentioned QDOS trap and
stores a specified number of entered lines for any console channel. If a
program then requests input, previously entered lines can be recalled
using the <↑> and <↓> keys - this is called a command line history (hence
the name of the History Device). 

A history for a console channel must be
explicitly installed, by using the HIS\_SET command. HIS\_SET can only
accept channel numbers which point to a con\_ device, it breaks with
'bad parameter' if that is not the case. Once the history is installed,
you will need to activate it by using the command HIS\_SIZE.

**Example**

To install a command line history for the SuperBASIC interpreter - these
lines could be added to a BOOT program::

    HIS_SET #0: REMark Install a command line history for #0 
    HIS_SIZE #0, 40: REMark Activate history which stores 40 lines

**NOTE 1**

The History Device does not run on at least pre E.21 drivers of the
ST/QL or STE/QL due to a bug in the IO.EDLIN trap of these drivers.
History is fine for Minerva up to v1.93, although there are harmless
problems with v1.96 in that the current line is not displayed before the
line is altered. QView and Jochen Merz Software have been informed about
these difficulties, so these may already be fixed by now.

**NOTE 2**

You cannot redefine the keys used for last line recall!!

**SMS NOTE**

The History device is built into SMSQ/E, although the HIS\_... commands
are not included with SMSQ/E, so in reality, you can only use the
HISTORY device as a Last In First Out pipe system - see Devices
Appendix. In any event the HIS\_... commands do not appear to work on
SMS.

**CROSS-REFERENCE**

A history is automatically removed when a channel is closed but removal
can also be forced with :ref:`his-unset`. The
QDOS/SMS Reference Manual contains full details of IO.EDLIN

--------------


..  _his-size:

HIS\_SIZE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_SIZE #channel, lines                                        |
+----------+-------------------------------------------------------------------+
| Location |  History Device                                                   |
+----------+-------------------------------------------------------------------+

A history which has been already been installed with HIS\_SET has its
size specified and is activated (or de-activated) with HIS\_SIZE. The
different usages of the command are distinguished by the lines
parameter. 

- Positive numbers for lines will activate a history for the 
  given channel and tell it to store the next lines number of lines which
  are terminated by pressing <ENTER>. If a history had already been
  installed, then all stored lines are lost. 

- Negative numbers will have exactly the same effect except that if a history was already active, the
  absolute value of the given lines number is added to the memory capacity
  of the existing history. Exisiting stored lines are retained in memory.

- Zero simply turns off a history and clears the tables which hold the entered lines. 

History can store a maximum of 32767 lines which should
be more than sufficient. Memory is allocated dynamically, in four
kilobytes chunks, so there is a small danger of heap fragmentation.

**CROSS-REFERENCE**

See :ref:`his-set`.

--------------


..  _his-unset:

HIS\_UNSET
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_UNSET #channel                                              |
+----------+-------------------------------------------------------------------+
| Location |  History Device                                                   |
+----------+-------------------------------------------------------------------+

This command removes a history from a channel, regardless of its state
of activity and the stored lines. HIS\_UNSET can only be used on
channels where a history exists, otherwise an error will be reported.

**Example**

::

    HIS_UNSET #0

**CROSS-REFERENCE**

:ref:`his-use`,
:ref:`his-size`

--------------


..  _his-use:

HIS\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_USE device$                                                 |
+----------+-------------------------------------------------------------------+
| Location |  History Device                                                   |
+----------+-------------------------------------------------------------------+

History's command line history is installed as a device driver to allow
you to use it from languages other than SuperBASIC. The default device
name is HIS and can be opened as an input pipe whenever a IO.EDLIN call
is to be used. 

The HIS\_USE instruction allows you to rename this device
name to any other three letter code, passed as a string. The use of the
HIS device is beyond the scope of this book because it's not necessary
for SuperBASIC where the HIS\_SET, HIS\_SIZE and HIS\_UNSET commands are
available to handle it. Please refer to the original documentation!

**SMS NOTE**

The History device built into SMSQ/E uses the device name HISTORY and
can therefore be used alongside this version of the History Driver. You
cannot rename SMSQ/E's version.

**CROSS-REFERENCE**

See :ref:`his-use-dlr` and
:ref:`his-set`.

--------------


..  _his-use-dlr:

HIS\_USE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HIS\_USE$                                                        |
+----------+-------------------------------------------------------------------+
| Location |  History Device                                                   |
+----------+-------------------------------------------------------------------+

This function returns the three letter device name which has been set with HIS\_USE.

**CROSS-REFERENCE**

See :ref:`his-use`.

--------------


..  _hot:

HOT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT key, executable\_file                                        |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command will load the given executable job into memory and start
it running from memory each time that the specified key (together with
<ALT>) is pressed, so there will not be any need to access the drive,
but the code has to be stored twice: once as the code loaded by HOT, and
then the job created from that code. Thus it is only practical to load
small programs such as system utilities with this command.

**Examples**

::

    HOT c,FLP1_COLOURS_exe 
    HOT s,FLP1_tk2flp 
    HOT "4",FLP1_QED

**NOTE 1**

Any ALTKEY definitions which use the same hotkeys will be ignored.

**NOTE 2**

Non-standard machine code cannot be used (Supercharged or Turbo compiled
SuperBASIC for instance): the code has to be re-entrant, ie. when the
job stops it should disappear. Jobs which relocate themselves, redefine
the trap table, change their own code (ie. are not ROMable), or can only
be started one at a time, tend to produce system crashes and other
problems.

**WARNING**

Memory used by HOT-loaded programs cannot always be freed for use by
SuperBASIC.

**CROSS-REFERENCE**

:ref:`clear-hot` clears a hotkey defined with
:ref:`hot` and (hopefully!) returns the occupied
memory to QDOS. Use the Hotkey System if you have this available!!

--------------

..  _hot-chp:

HOT\_CHP
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_CHP (key$,filename [;cmd$] [,JobName$] [,options])          |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The main idea behind the Hotkey System II is that you can have access
to any number of QL programs by pressing one simple hotkey in order to
access each program, rather than having to use <CTRL><C> to cycle
through all of the programs currently stored in the QL's memory. 

The function HOT\_CHP will load an executable file with the specified
filename into the common heap and make it into an Executable Thing. Now,
each time that you press <ALT> plus the specified key$, a new copy of
the program will be started up in memory (although the same code is
used, meaning that very little memory is used by each additional copy).

As from v2.03 of Hotkey System II, if you use an upper case key$, then
you will need to press the upper case character, compare where you use a
lower case key$, which will recognise both the uppper and lower case
character (if the upper case character has not been assigned to another
hotkey). 

HOT\_CHP will support the current program default device if
Toolkit II is loaded, otherwise it will use its own default device which
can be configured by using the program CONFIG on the file HOT\_REXT.

When the program is loaded using this command, HOT\_CHP will look to see
whether the start of the program contains a Job name, if not, then the
program file name is used as the Job name (unless an alternative is
stipulated, using the Jobname$  parameter). 

As with EXEP, you can pass a command string to the program
which will be passed to each copy of the program as and when they are
started up. You can also supply a specific Job name for the program and
pass various options to the Pointer Interface to tell it how to treat
the program. As well as those options supported by EXEP, the following
option is also supported: 

- -I This tells the Hotkey System that the program code is 'impure' 
  (ie. it modifies its own code). This means that
  code cannot be shared by every copy of the program - this therefore
  means that each time that the program is called, a copy of the original
  code is made from which the program runs. For this reason, you should
  consider using HOT\_LOAD for such programs. The most common programs
  which fall within this category have been written under BCPL or compiled
  with Supercharge or Turbo. 

If the program is successfully loaded into
memory and set up as an executable Thing, HOT\_CHP will return 0,
otherwise one of the following error codes will be returned:

- -2 Specified filename is not executable 
- -3 Not enough memory to load the file 
- -7 The specified filename cannot be found 
- -9 The specified hotkey has already been defined, or the file is in use. 
- -12 The specified filename is not supported (bad filename).

**NOTE 1**

Any programs which are to be loaded into the Hotkey System II should be
re-entrant so that the same code can be shared by any number of copies
of the program, otherwise label them as Impure.

**NOTE 2**

Versions of the Hotkey System pre v2.21 do not allow you to pass a
command string.

**WARNING**

You should not specify a Job name for impure programs as this may cause
problems.

**CROSS-REFERENCE**

If you do not intend to remove the program in the future, use
:ref:`hot-res` or
:ref:`hot-res1` as these will ensure that the
program starts up more quickly. :ref:`hot-chp1`,
:ref:`hot-load`,
:ref:`hot-load1` are similar. The hotkey will
not be available until you enable the Hotkey System with HOT\_GO.

--------------


..  _hot-chp1:

HOT\_CHP1
=========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_CHP1 (key$,filename [;cmd$] [,Jobname$] [,options] )  or    |
|          || HOT\_CHP1 (key$,filename [;cmd$] !Wakename$ [,options] )         |
+----------+-------------------------------------------------------------------+
| Location ||  HOTKEY II                                                       |
+----------+-------------------------------------------------------------------+

The first variant of this function is very similar to HOT\_CHP except
that it will only start up a new copy of the program when the specified
hotkey is pressed if there is not already a copy of the program being
executed. If a copy of the program is already being executed, then the
hotkey will merely move that copy of the program to the top of the pile
so that you can access it (it will PICK the program and execute a WAKE
event, if supported by the program - a Wake event is normally used by a
program to force it to update its tables etc). 

The second variant of this command was introduced in v2.24 of the Hotkey System II and allows you
to specify a name of a job (Wakename$) which is to be woken up if there
is already one copy of the original program running in memory.
Unfortunately this variant acts differently from the first in one main
way: 

- If the original program is already running, and Wakename$ points
  to another program which is not yet running, a second copy of the
  original program will be started up.

**Example**

The following line will allow you to set up the <ALT><R> key to do one
of two things: 

- If a job called QR-Config is running already, this will be Woken; otherwise; 
- A copy of a program called flp1\_Route\_Obj will be started up (even if one is already running). 

::

    ERT HOT_CHP1 ('R','flp1_Route_obj';'flp1_\' ! 'QR-Config')

**NOTE 1**

On early versions of the Hotkey System II, HOT\_CHP1 did not create an
Executable Thing.

**NOTE 2**

Versions of the Hotkey System pre v2.21 do not allow you to pass a
command string.

**CROSS-REFERENCE**

See :ref:`hot-chp`.
:ref:`hot-pick` allows you to set up hotkeys to
PICK a program, and :ref:`hot-wake` allows you
to set up hotkeys to WAKE a program.
:ref:`hot-thing` allows you to call an
Executable Thing.

--------------


..  _hot-cmd:

HOT\_CMD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_CMD (key$,command$ :sup:`\*`\ [,command$]\ :sup:`\*`\ )     |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function allows you to set up a specify a key, which, when pressed
with <ALT> will call up the SuperBasic task (Job 0), Picking it to the
top of the pile, and then send each specified command to the command
console (normally #0) followed by <ENTER> at the end of each string.

**Example**

::

    ERT HOT_CMD ('d','INPUT "List Device: ";d$','DIR d$')
    
will set up a hotkey whereby whenever you press <ALT><d>, control will
be returned to SuperBasic and the user asked to enter a device, after
which, a directory of that device will be produced.

**NOTE**

Although HOT\_CMD will quite happily allow you to redefine an existing
hotkey created with HOT\_CMD or HOT\_KEY, if any other command has been
used to set up the hotkey, error -9 (in use) will be reported.

**CROSS-REFERENCE**

See :ref:`hot-key`.
:ref:`hot-go` is required in order to make hotkey
definitions operational. :ref:`force-type` is
very similar.

--------------


..  _hot-do:

HOT\_DO
=======

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_DO key$  or                                                 |
|          || HOT\_DO Thingname$                                               |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

Once a hotkey is operational (see HOT\_GO), you can call up the program
or action set up on that hotkey by using the command HOT\_DO, which
enables a program to emulate the user pressing <ALT><key>. 

The first variant expects you to supply the key which would normally be used
together with <ALT> to call up the facility. You can however, also use
the second variant to supply the name of an Executable Thing to be
called up.

**Example**

Take the following hotkey:: 

    100 ERT HOT_WAKE ('f',Files) 
    110 HOT_GO
    
The following would all have the same effect:

- Pressing <ALT><f> 
- HOT\_DO 'f'
- HOT\_DO Files

**CROSS-REFERENCE**

See the other :ref:`hot`... commands about setting
up hotkeys.

--------------


..  _hot-go:

HOT\_GO
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_GO                                                          |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The Hotkey System II is actually a Job (called HOTKEY) which sits in
the background of the QL looking for the user to press the previously
defined hotkeys. As many users should be aware, whenever a job is
present in the QL's memory, you cannot access the resident procedure
memory (which should be used to install SuperBasic extensions and device
drivers for example - see RESPR). 

For this reason, the Hotkey System II
was designed so that the Hotkey Job would not actually be created until
such time as the user was ready - ie. when all of the hotkeys had been
defined and everything loaded into the resident procedure memory. Users
who have used Toolkit II's ALTKEY system may have noticed that although
they have defined various hotkeys (with HOT\_KEY for example), they do
not work (or as soon as the Hotkey System II has been loaded, the last
line recall does not work). This is because the Hotkey Job has to be
started. This is achieved simply by using the command::

    HOT_GO
    
This will start the Hotkey Job which will support all of the currently
defined hotkeys, including the Hotkey Stuffer Buffer keys (which can be
re-defined by using the program CONFIG on the file HOT\_REXT), and the
last line recall. If you want to remove the Hotkey Job at any time, you
can do so by using the command HOT\_STOP, which has the same effect as
RJOB 'Hotkey'. This will not destroy any of the Hotkey definitions and
when you enter the command HOT\_GO again, they will all be available
once again.

**CROSS-REFERENCE**

:ref:`respr` allocates areas of the resident
procedure memory.

--------------


..  _hot-key:

HOT\_KEY
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_KEY (key$,string$ [,string2$ [,string3$... ]])              |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is very similar to the first variant of the command
ALTKEY provided by Toolkit II, except that it operates by virtue of the
Hotkey Job, rather than a polled task, which should make the hotkey a
little more reliable than the Toolkit II version (although this does
mean than a hotkey set up under the Hotkey System II cannot be accessed
from within a program running in Supervisor mode). 

As with ALTKEY, this
function creates a key macro which will be typed into the current
keyboard queue each time that you press <ALT> and the specified <key$>
at the same time. Again, if more than one string appears in the
definition, an <ENTER> (line feed) will be placed between each string.
If you want a line feed at the end of the final string, add a nul string
to the definition.

**NOTE**

Although HOT\_KEY will quite happily allow you to redefine an existing
hotkey created with HOT\_CMD or HOT\_KEY, if any other command has been
used to set up the hotkey (eg. ALTKEY), error -9 (in use) will be
reported.

**CROSS-REFERENCE**

As with other Hotkey System II definitions, you will need to use
:ref:`hot-go` before you can access this hotkey.
See :ref:`altkey` for more information.

--------------


..  _hot-list:

HOT\_LIST
=========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_LIST [#ch] or                                               |
|          || HOT\_LIST \\filename                                             |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This command will produce a list in the given channel (default #1) of
all of the currently set hotkeys recognised by the Hotkey System II. If
the second variant of the command is used, this will create a file with
the specified filename (default data device supported), offering the
option to overwrite any existing file, and list the hotkeys in that
file. Each hotkey will be listed in tabulated form, with the key (which
has to be pressed together with <ALT>) followed by the operation or
definition string. If you need to press <SHIFT> along with the key, the
key will be pre-fixed with 's'.

**CROSS-REFERENCE**

:ref:`hot-name-dlr` returns the description or
name for the hotkey. :ref:`hot-type` returns the
type of hotkey operation.

--------------


..  _hot-load:

HOT\_LOAD
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_LOAD (key$,filename [;cmd$] [,JobName$] [,options] )        |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is similar to HOT\_CHP in the parameters which it
expects. By contrast, however, HOT\_LOAD does not store the program in
memory, but, instead, each time that the specified hotkey is pressed, it
will look for the specified filename and then load the program at that
stage (this is therefore really designed for programs which are stored
on Hard Disk, as it is improbable that you will keep the same disk in a
drive all of the time).

**NOTE 1**

The I (Impure code) option is not needed with this function.

**NOTE 2**

HOT\_LOAD does not create an Executable Thing.

**NOTE 3**

Versions of the Hotkey System pre v2.21 do not allow you to pass a
command string.

**WARNING**

Versions of the Hotkey System II, earlier than v2.15 (or Level B-08 of
the ST/QL Drivers) contained serious bugs in HOT\_LOAD which could
either remove the Hotkey Job or crash the computer.

**CROSS-REFERENCE**

See :ref:`hot-load1` and
:ref:`hot-chp`.

--------------


..  _hot-load1:

HOT\_LOAD1
==========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_LOAD1 (key$,filename [;cmd$] [,Jobname$] [,options] )  or   |
|          || HOT\_LOAD1 (key$,filename [;cmd$] !Wakename$ [,options] )        |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function bears the same relationship to HOT\_LOAD as HOT\_CHP1
does to HOT\_CHP. See HOT\_CHP1.

**NOTE**

Versions of the Hotkey System pre v2.21 do not allow you to pass a
command string.

**CROSS-REFERENCE**

See :ref:`hot-load`.

--------------


..  _hot-name-dlr:

HOT\_NAME$
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_NAME$ (key$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The function HOT\_NAME$ returns the name of the Thing or the string
associated with the specified hotkey. A null string is returned if the
hotkey is not defined.

**Example**

::


    ERT HOT_RES ('/',flp2_Qram): ERT HOT_KEY ('s','Yours Sincerely','')
    HOT_GO 
    PRINT HOT_NAME$ ('/') , HOT_NAME$('s')

will show the following: Qram Yours Sincerely

**CROSS-REFERENCE**

:ref:`hot-list` will list details about all
currently defined hotkeys, :ref:`hot-type`
allows you to verify the type of hotkey defined.

--------------


..  _hot-off:

HOT\_OFF
========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_OFF (key$)  or                                              |
|          || HOT\_OFF (Thingname$)                                            |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The HOT\_OFF function allows you to turn off an individual hotkey by
either specifying the hotkey itself, or the name of the Thing accessed
by using the hotkey, if the second variant is used (if there are two
hotkeys which access the same Thing, the first hotkey alphabetically
will be turned off). 

The second variant even allows you to pass the
string or command used by HOT\_KEY or HOT\_CMD, although this is a
somewhat dubious method of doing this!! 

Even though the hotkey has been
turned off, it will still appear in the hotkey list (see HOT\_LIST),
although pressing the hotkey will have no effect.

**NOTE**

If the hotkey or Thingname cannot be found, the function will return -7.

**Example**

::

    HOT_OFF ('p') 
    
will turn off the <ALT><p> hotkey, eg. if this is used by a program as a command. 

::

    HOT_SET ('p')

will turn it back on.

**CROSS-REFERENCE**

:ref:`hot-set` will turn the hotkey back on
again. :ref:`hot-remv` will remove the hotkey
definition for good.

--------------


..  _hot-pick:

HOT\_PICK
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_PICK (key$, JobName$)                                       |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The function HOT\_PICK is used to specify a hotkey to Pick a job of a
specified name whenever that key is pressed together with <ALT>. In
effect, whenever the hotkey is pressed, the specified program will be
brought to the top of the pile, allowing you to continue work on it. The
Job Name given need only be the first word contained in the name shown
when you use the JOBS command, therefore meaning that Job names can be
as descriptive as you like! If the specified Job is not present in
memory when you press the hotkey, a warning beep will be sounded.

**Example**

::

    ERT HOT_PICK('p','Perfection')
    
will set up a hotkey which will allow you to jump straight into
Perfection from any other program (provided that Perfection is in
memory), just by pressing <ALT><p>.

**NOTE**

HOT\_PICK up to v1.22 gave problems on the ST Emulators.

**CROSS-REFERENCE**

:ref:`exep`, :ref:`hot-load`,
:ref:`hot-chp` and
:ref:`hot-res` all allow you to alter the Job
Name of a program as it is loaded. Compare
:ref:`hot-wake`.

--------------


..  _hot-remv:

HOT\_REMV
=========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_REMV (key$)  or                                             |
|          || HOT\_REMV (Thingname$)                                           |
+----------+-------------------------------------------------------------------+
| Location ||  HOTKEY II                                                       |
+----------+-------------------------------------------------------------------+

The HOT\_REMV function allows you to remove the hotkey definition
associated with the specified key or, if you prefer, the hotkey
associated with the specified Thing. If the hotkey refers to a program
which has been loaded into the common heap (eg. with HOT\_CHP), then
this area of the common heap will also be released.

**NOTE**

Prior to v2.26 of the Hotkey System 2, if key$ was an uppercase letter,
then any hotkey associated with the lowercase letter would also be
removed.

**CROSS-REFERENCE**

See :ref:`hot-off` for further details.

--------------


..  _hot-res:

HOT\_RES
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_RES (key$,filename [;cmd$] [,JobName$] [,options] )         |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is the same as HOT\_CHP except that the program is loaded
into the resident procedure area, and cannot therefore be removed in the
future. If the resident procedure area cannot be accessed (ie. if a task
is already being executed), this function will access the common heap.

**CROSS-REFERENCE**

:ref:`hot-chp`.

--------------


..  _hot-res1:

HOT\_RES1
=========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_RES1 (key$,filename [;cmd$] [,Jobname$] [,options] )  or    |
|          || HOT\_RES1 (key$,filename [;cmd$] !Wakename$ [,options] )         |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

HOT\_RES1 is the same as HOT\_CHP1 except that the program is loaded
into the resident procedure area. If this cannot be accessed for any
reason, the common heap will be used.

**CROSS-REFERENCE**

See :ref:`hot-res` and
:ref:`hot-chp1`.

--------------


..  _hot-set:

HOT\_SET
========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_SET (key$)  or                                              |
|          || HOT\_SET (Thingname$)  or                                        |
|          || HOT\_SET (newkey$,oldkey$)  or                                   |
|          || HOT\_SET (newkey$,oldThingname$)                                 |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The first two variants of this function are the opposite to HOT\_OFF in
that they re-activate the specified hotkey. If the specified hotkey does
not exist, the value -7 will be returned. By contrast, the second two
variants allow you to re-define a hotkey by assigning a new key which is
to replace the old key press. If the specified new hotkey already
exists, -9 will be returned, and if the old hotkey cannot be found, the
value -7 will be returned.

**Example**

::

    10 ERT HOT_CHP ('p','flp1_Perfection') 
    20 HOT_GO 
    30 ERT HOT_SET ('L','p') 
    40 ERT HOT_WAKE ('p','Pick')

**CROSS-REFERENCE**

See :ref:`hot-off` and
:ref:`hot-key`.

--------------


..  _hot-stop:

HOT\_STOP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_STOP                                                        |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

See :ref:`hot-go`\ !

--------------


..  _hot-stuff:

HOT\_STUFF
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_STUFF string$                                               |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The Hotkey System II allows you to pass information to a program by
using an area of memory known as the Hotkey Stuffer Buffer. The contents
of this buffer can be placed into the current keyboard queue by pressing
<ALT><SPACE> to read the last item to have been placed into the Stuffer
Buffer, or <ALT><SHIFT><SPACE> to read the previous item to have been
placed in the Stuffer Buffer. 

The keys used to recall the Stuffer
Buffers can be configured by using the program CONFIG on the file
HOT\_REXT. 

Each item can by default be a maximum of 512 characters long
(although this can be configured from between 128 and 16384 characters
if you wish). Note that two of the characters are used to store the
length of the Stuffer Buffer and must therefore be deducted from this
setting. 

The command HOT\_STUFF allows you to place the specified
string$ into the Stuffer Buffer so that it may be read by other
programs. If the Stuffer Buffer was previously empty, both <ALT><SPACE>
and <ALT><SHIFT> <SPACE> will return the same, however, if something was
already in the Stuffer Buffer, this will be read by <ALT><SHIFT><SPACE>,
and the new entry as <ALT><SPACE>.

**Example 1**

Place an address in the Stuffer Buffer::

    HOT_STUFF '10 Hardacre Way' & CHR$(10) & 'Hardacre' &CHR$(10) & 'Newcastle'
    
**Example 2**

Presuming an empty Stuffer Buffer, after::

    HOT_STUFF 'DIR flp1_'
    
the Stuffer Buffer would look like this::

    <ALT><SHIFT><SPACE> --- DIR flp1_ 
    <ALT><SPACE> --- DIR flp1_ 
    
If you then use::

    HOT_STUFF 'DIR flp2_'
    
the Stuffer Buffer would look like this::

    <ALT><SHIFT><SPACE> --- DIR flp1_ 
    <ALT><SPACE> --- DIR flp2_

**NOTE**

HOT\_STUFF "" caused various problems until SMS v2.73 - see GET\_STUFF$.
It could even crash compiled programs!!

**CROSS-REFERENCE**

:ref:`get-stuff-dlr` allows a program to read the
contents of the Stuffer Buffer. :ref:`hot-list`
will allow you to see the contents of the Stuffer Buffer.
:ref:`hot-go` is required before <ALT><SPACE> or
<ALT><SHIFT> <SPACE> will work!

--------------


..  _hot-thing:

HOT\_THING
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_THING (key$,Thingname$ [;cmd$] [,Jobname$] )                |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The function HOT\_THING allows you to define a hotkey which will start
up a new copy of an Executable Thing whenever the hotkey is pressed (if
the Thing is present at that stage). You can pass a command string to
the Executable Thing and even change the name of the Job which will be
created by passing Jobname$. 

More and more utilities are being written
for QDOS which are set-up as Executable Things (for example, most of the
menus provided by QPAC2 are in fact Executable Things), which is a means
of providing various resources which a program can make use of (if they
are present). 

Executable Things can be seen as an executable program
stored in memory, several copies of which can be started up at any time,
but the same piece of machine code will be used by all of the copies,
meaning that very little memory is required for each additional copy.

**Example**

::

    ERT HOT_CHP('p',flp1_Perfection,'Perfection WP') 
    ERT HOT_THING('P','Perfection WP')

Both <ALT><p> and <ALT><P> will now have the same effect.

**NOTE 1**

Thingname$ should contain the full name of the Thing, otherwise it will
not be recognised.

**NOTE 2**

Verions of the Hotkey System pre v2.21 do not allow you to pass a
command string. You also need v2.24+ to pass a job name.

**CROSS-REFERENCE**

:ref:`hot-chp` and
:ref:`hot-res` turn a file into an Executable
Thing. :ref:`thing` allows you to test if a Thing is
present.

--------------


..  _hot-thing1:

HOT\_THING1
===========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_THING1 (key$,Jobname$ [;cmd$] [,Jobname$])  or              |
|          || HOT\_THING1 (key$,Jobname$ [;cmd$] !Wakename$)                   |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.50+                                                    |
+----------+-------------------------------------------------------------------+

This command is exactly the same as HOT\_WAKE.

**CROSS-REFERENCE**

See :ref:`hot-wake`\ .

--------------


..  _hot-type:

HOT\_TYPE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_TYPE (key$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is useful to find out the type of hotkey associated with
the specified keypress. The values returned by HOT\_TYPE are as follows:

- -8 Hotkey for Last line recall 
- -6 Hotkey for recall previous Stuffer Buffer 
- -4 Hotkey for recall current Stuffer Buffer (HOT\_STUFF) 
- -2 Hotkey stuffs a defined string into the keyboard queue (HOT\_KEY) 
- 0 Hotkey PICKS SuperBasic and stuffs a command into #0 (HOT\_CMD) 
- 2 Hotkey DOES code 
- 4/5 Hotkey executes a Thing (HOT\_THING,HOT\_RES,HOT\_CHP) 
- 6 Hotkey executes a File (HOT\_LOAD) 
- 8 Hotkey PICKS a Job (HOT\_PICK) 
- 10/11 Hotkey WAKES or executes a Thing (HOT\_WAKE, HOT\_RES1, HOT\_CHP1) 
- 12 Hotkey WAKES or executes a File (HOT\_LOAD1)

**CROSS-REFERENCE**

:ref:`hot-name-dlr` returns the name of the Thing
or the string being accessed.

--------------


..  _hot-wake:

HOT\_WAKE
=========

+----------+-------------------------------------------------------------------+
| Syntax   || HOT\_WAKE (key$,Jobname$ [;cmd$] [,Jobname$])  or                |
|          || HOT\_WAKE (key$,Jobname$ [;cmd$] !Wakename$)                     |
+----------+-------------------------------------------------------------------+
| Location || HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

Many programs which have been written to use the Pointer Environment
will recognise what is known as a WAKE event - this defines something
that the program should do once control is returned to the program, for
example, updating its tables. 

Whereas PICKing a job merely brings it to
the top of the pile ready for use, when you WAKE a job, not only is it
brought to the top of the pile, but also a WAKE event is executed (if
supported). You should therefore WAKE any program which provides
information on the current state of the computer or SuperBasic program
for example. 

The function HOT\_WAKE allows you to set up a hotkey which
will Wake the specified Jobname$ if a copy of the program is already
being executed. However, if there is not already a copy of the specified
Job being executed, the hotkey will then look for an Executable Thing
with the same name as Jobname$
(which should therefore be specified in full), which, if found, will be
executed by the hotkey, creating a new copy of the program. 

As with the
other hotkey commands, a command string can be passed to the program
when it is executed (this will be ignored if the program is merely
woken). 

As with HOT\_CHP1, HOT\_RES1 and HOT\_LOAD1, you can specify a
Wakename$ which allows you to use the Hotkey to access two jobs, if at
least the first Job (or Executable thing) exists then the Hotkey will do
one of two things: 

- If there is a current job called Wakename$, then this will be woken; otherwise;
- The first Job (or Executable Thing) will be Woken if it exists (or otherwise will be started up). 

HOT\_WAKE is ideally suited for programs where you would not want more than one copy
to be executed at any one time (eg. a calendar program).

**Example**

Some users prefer to be able to have a choice between either Waking an
existing copy of a program (or executing the first copy) and loading
another copy of the program at a later stage. This can be achieved, for
example, with::

    ERT HOT_RES ('Q',flp1_QUILL,'QUILL') 
    ERT HOT_WAKE ('q','QUILL')

**NOTE**

Verions of the Hotkey System pre v2.21 do not allow you to pass a
command string. You also need v2.24+ to pass a job name.

**CROSS-REFERENCE**

:ref:`hot-pick` allows you to define a hotkey to
PICK an existing Job.

--------------


..  _hput:

HPUT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  HPUT [#ch] length [ , access [, type [, dataspace [, extra ]]]]  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This command allows you to set the various parameters which are
contained in the header of the file attached to the specified channel
(default #3). The command will use the supplied parameters to set the
required information. If the specified channel is not open to a file,
then an Invalid Parameter error is reported. The information which can
be set is as per HGET.

**NOTE**

You will not be able to compile this command with Turbo or SuperCharge
due to the fact that it alters its own parameters.

**CROSS-REFERENCE**

:ref:`hget` reads the file header information. See
:ref:`fgeth-dlr` for information about the file
header. See also :ref:`heads` and
:ref:`sethead`.

