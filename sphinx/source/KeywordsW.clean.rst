
==========
Keywords W
==========

TODO
====

- WIN_DRIVE and WIN_DRIVE$ have the same URL.



..  _wait-event:

WAIT\_EVENT
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  WAIT\_EVENT (event [,timeout] )                                  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.71+                                                    |
+----------+-------------------------------------------------------------------+

This function access the Event Accumulator for the current job and
checks whether the specified event (or events) have occured. If you want
to check for the occurence of several events, you merely need to add
together the numbers of the events. If any one of the specified events
has already occured then the function will return the total value of the
specified events which have occured. If none of the specified events
have occured, then this function will suspend the current program until
one of those events has occured or the specified timeout (if any) has
elapsed. If timeout is not specified then the function will wait
forever. If the reason for the function returning was that the timeout
has elapsed (and none of the specified events have occured) then the
returned value will be 0.

**Example**

::

    PRINT WAIT_EVENT(12)
    
This wait for event numbers 4 and 8 (4+8=12). If event 8 was notified
as having occured, then the value 8 would be shown on screen.

**CROSS-REFERENCE**

:ref:`send-event` notifies a Job's Event
Accumulator that one or more events have occured.

--------------


..  _wbase:

WBASE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  WBASE [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  Tiny Toolkit                                                     |
+----------+-------------------------------------------------------------------+

This function is exactly the same as WIN\_BASE.

**CROSS-REFERENCE**

See :ref:`win-base`.

--------------


..  _wcopy:

WCOPY
=====

+----------+------------------------------------------------------------------+
| Syntax   | WCOPY [#ch,] [wild1] [TO wild2](Toolkit II)  or                  |
+----------+------------------------------------------------------------------+
| Syntax   | WCOPY [#ch,] wild1 TO wild2(THOR)                                |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THORs                                                |
+----------+------------------------------------------------------------------+

The command WCOPY is intended to allow you to copy several files with a
common root from one device to another, quickly and easily. 

It is
however necessary to understand the way in which Toolkit II's wildcards
work, as WCOPY uses these wildcards to find the required files. A
wildcard is a means of finding several files which have similar names.

The first thing which any wildcard command does is to look at the
supplied parameter and then compare this against each entry in the
directory of the given device. If any of the filenames match exactly, or
if the parameter forms the start of any filenames, those files are
marked as chosen. For example::

    WCOPY flp1_D TO flp2_
    
would copy all files whose names are either 'D' or begin with the
letter 'D' to flp2\_ (the comparison is case independent). 

However,
wildcards can be much more complex and wonderful on the QL. If you place
two underscores ('\_') together as part of wild1, this is taken to be a
wildcard and can in fact be replaced by any string of characters in
order to match filenames with wild1. Wildcards are further complicated
by the fact that if a device name is not provided as part of wild1, then
the default device will be added (which ends with an underscore, so if
wild1 begins with an underscore, you will have a wildcard symbol!!) A few
examples of wildcards (assuming default device is 'flp1\_'):

+-------------+-----------------+------------------------------+
| Wild1       | Wild Card Name  || File Matches                |
+=============+=================+==============================+
| t           | flp1\_t         || flp1\_testa                 |
|             |                 || flp1\_test\_v1.00\_bas      |
+-------------+-----------------+------------------------------+
| \_t         | flp1\_\_t       || flp1\_testa                 |
|             |                 || flp1\_test\_v1.00\_bas      |
|             |                 || flp1\_old\_v0.01\_test\_bas |
+-------------+-----------------+------------------------------+
| flp1\_old\_ | \_flp1\_old\_\_ || flp1\_old\_v0.01\_test\_bas |
|             |                 || flp1\_old\_v1.00\_exe       |
|             |                 || flp1\_old\_data             |
+-------------+-----------------+------------------------------+

WCOPY uses both wildcards for
ascertaining the names of the files to be copied, and the files to be
created. However, both wild1 and wild2 are dealt with distinctively.

WCOPY will use the rules on wildcards to search for files which match
with wild1 on the specified device, or the default data device if no
device is specified. However, the rules for determining the destination
parameter wild2 are complex: 

#. If no device is given, but a filename is
   specified, WCOPY looks at wild1. The destination device is then assumed
   to be the same as the source device (ie. the device name specified as
   part of wild1, or if omitted, DATAD$). 
#. If the second parameter is
   omitted, then again WCOPY
   looks at wild1. If a device is given in the first parameter, then this
   is used as the destination device. On the other hand, if no device was
   specified, then the default destination device will be used (see
   DESTD$). 
#. If a second parameter is given which includes a device name,
   then this is used! Having decided upon the device to which the files are
   to be copied, WCOPY then looks at the remainder of wild2 to ascertain
   what to do with the filenames it has found. 

Before trying to understand
how this works, it is essential to realise that there is an implicit
wildcard placed at the end of both wild1
and wild2. 

WCOPY will look at wild2 and compare each filename that it
has found using the wildcards in wild1 in turn. If a wildcard in wild1
is matched by a wildcard in wild2, then that part of the source
filename will be inserted into the destination filename. However, beyond
this, WCOPY will use the rest of wild2 as the actual destination
filename. Any additional sections in wild1 or wild2 will be inserted
after the drive name in the destination filename. See the examples
below! 

Having decided which files are to be copied and the names they
are to be given on the device where they are being copied to, WCOPY will
then request confirmation in the specified channel (default #0) for each
file, by printing the following message in the channel::

    source_file TO destination_file..Y/N/A/Q?
    
You will then need to press <Y> to copy that file across, <N> to miss
that file out, <A> to copy all files which match with wild1, or <Q> to
leave WCOPY. In this instance, <ESC> and <CTRL><SPACE> both act as <Q>.

If the destination file already exists, another prompt will be shown in
the form::

    OK to overwrite..Y/N/A/Q?
    
You will then need to press <Y> to overwrite that file, <N> to go onto
the next file, <A> to overwrite this and all other files being copied if
they already exist, or <Q> to stop WCOPY. Again, <ESC> and <CTRL><SPACE>
act as <Q>.

**Examples**

Assuming that the default data device is flp1\_ and the default
destination device is ram2\_::

    WCOPY

Copies all files on flp1\_ to ram2\_ 

::

    WCOPY flp1_test TO ram2_old

Copies::

    flp1_testa to ram2_olda
    flp1_test_v1.00_bas to ram2_old_v1.00_bas

::

    WCOPY flp1_test, ram2_old_

Copies::

    flp1_testa to ram2_olda
    flp1_test_v1.00_bas to ram2_old_v1.00_bas

::

    WCOPY _bas to ram2_
    
Copies::

    ram1_test_v1.00_bas to ram2_bas
    ram1_old_v0.01_test_bas to ram2_bas

::

    WCOPY _bas, ram2__
    
Copies::

    ram1_test_v1.00_bas to ram2_test_v1.00_bas
    ram1_old_v0.01_test_bas to ram2_old_v0.01_test_bas

::

    WCOPY old__ TO ram2_
    
Copies::

    ram1_old_v0.01_test_bas to ram2_v0.01_test_bas
    ram1_old_v1.00_exe to ram2_v1.00_exe 
    ram1_old_data to ram2_data

**NOTE 1**

The TO in the syntax can be replaced by a comma ',' as per a number of the above examples.

**NOTE 2**

On the THOR range (v4.02+) the word 'TO' in the prompts is replaced by the
symbol =>

**NOTE 3**

On the THOR range, the prompt message are altered from 'Y/N/A/Q' to
'Yes/No/All/Quit'.

**NOTE 4**

As with COPY, WCOPY does not copy the header to serial devices (eg. ser)
if this is specified as the destination. However, the THOR variant of
this command actually looks to see whether the file-type or file
dependent information fields are non-zero in which case the header is
always copied.

**NOTE 5**

If you have level-2 device drivers, any sub-directories in the specified
source directory are ignored by WCOPY. For example, if:: 

    DIR flp1_ 

gave the following result::

    Psion Disk 
    400/1440 sectors 
    QUILL-> 
    ABACUS-> 

Then::

    WCOPY flp1_ 

would have no effect. However, compare::

    WCOPY flp1_QUILL_
    
which would copy all of the files in the sub-directory 'QUILL' to the
current destination device.

**NOTE 6**

Both parameters must be supplied for the THOR variant of this command,
otherwise the error 'Bad Parameter' will be reported.

**NOTE 7**

Current versions (at least up to v2.85) of WCOPY do not work correctly
with the DEV device when this is pointing at a sub-directory (eg::


    DEV_USE 1, flp1_QUILL_: WCOPY DEV1_
    
WCOPY will however work if the DEV device is pointing at a root directory, eg::

    DEV_USE 1, flp1_.

**CROSS-REFERENCE**

:ref:`spl-use` and
:ref:`dest-use` set the destination device. See
:ref:`copy`, :ref:`wcopy-f`
and :ref:`wcopy-o` which are all similar.
:ref:`wren`, :ref:`wdir`,
:ref:`wstat` and :ref:`wdel` all
use wildcards. :ref:`copy` and
:ref:`spl` allow you to copy specific files.

--------------


..  _wcopy-f:

WCOPY\_F
========

+----------+-------------------------------------------------------------------+
| Syntax   |  WCOPY\_F [#ch,] wild1 TO wild2                                   |
+----------+-------------------------------------------------------------------+
| Location |  THORs                                                            |
+----------+-------------------------------------------------------------------+

This command works in a similar way to WCOPY. However, although it
lists the files being copied to the given channel (default #0), the user
is not prompted to confirm that each file should be copied. The user
will however be asked to confirm should the destination filename already
exist.

**CROSS-REFERENCE**

See :ref:`wcopy`.

--------------


..  _wcopy-o:

WCOPY\_O
========

+----------+-------------------------------------------------------------------+
| Syntax   |  WCOPY\_O [#ch,] wild1 TO wild2                                   |
+----------+-------------------------------------------------------------------+
| Location |  THORs                                                            |
+----------+-------------------------------------------------------------------+

WCOPY\_O is the same as WCOPY\_F except that any existing files are
automatically overwritten without any prompting.

**CROSS-REFERENCE**

See :ref:`wcopy-f`.

--------------


..  _wdel:

WDEL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WDEL [#ch,] [wild]                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THORs                                                |
+----------+-------------------------------------------------------------------+

WDEL allows you to delete several files which match the given wildcard
at the same time. If wild contains a device name, then each file on that
device is checked to see if its name matches the wildcard, otherwise the
files on the default data directory are checked. 

If any files are found
which match the wildcard, a prompt will appear in the specified window
(default #0) to the effect::

    filename..Y/N/A/Q?
    
You must then either press <Y> to delete the offered file, <N> to leave
that file, <A> to delete that file and all other files which match the
wildcard, or <Q> to stop WDEL. <ESC> and <CTRL><SPACE> will have the
same effect as <Q>.

**Example**

::

    WDEL win1_v1_ 
   
will delete all files in the sub-directory v1.

**NOTE 1**

The THOR variant of WDEL has amended the prompt to read: 'Yes/No/All/Quit'

**NOTE 2**

Current versions of WDEL (at least up to v2.88) do not work with the DEV
device when this is pointing to a sub-directory. Even if you can
persuade WDEL to offer you the filename for deletion, when you press <Y>
or <A>, WDEL fails to delete the file!

**NOTE 3**

If you try to use WDEL on a write protected disk, it will ask you
whether you want to delete each file in turn reporting for each filename
that the disk is write-protected, rather than stopping altogether.

**CROSS-REFERENCE**

:ref:`wcopy` provides details about wildcards.
:ref:`delete` allows you to delete single files.

--------------


..  _wdel-f:

WDEL\_F
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  WDEL\_F [#ch,] [wild]                                            |
+----------+-------------------------------------------------------------------+
| Location |  THORs                                                            |
+----------+-------------------------------------------------------------------+

WDEL\_F is exactly the same as WDEL except no prompts or information
about the files being deleted is shown on screen.

**CROSS-REFERENCE**

See :ref:`wdel`.

--------------


..  _wdir:

WDIR
====

+----------+------------------------------------------------------------------+
| Syntax   | WDIR [#ch,] [wild] or                                            |
+----------+------------------------------------------------------------------+
| Syntax   | WDIR \\file [,wild] (Toolkit II only)                            |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THORs                                                |
+----------+------------------------------------------------------------------+

WDIR allows you to produce a list of all of the filenames on a given
medium which match with the specified wildcard. If wild
contains a device name, then a list of all of the files on that device
which match with the wildcard is printed out to the specified channel
(default #1). If however, a device is not specified, the default data
device is used. 

The second variant is only supported by Toolkit II and
allows you to send the results to the specified file instead of sending
it to a channel. If file does not include a valid device, the default
data device is used, and if the file already exists, you will be asked
whether or not you wish to overwrite it. The file is then opened by the
WDIR command, the list of files written to it and then closed again.

**Examples**

::

    WDIR \ser1, flp1___scr
    
will produce a list of all of the files on flp1\_ whose names end with
\_scr. 

::

    WDIR my
    
lists all files in the current directory which start with my. 

::

    WDIR _my
    
lists files which start with my or contain \_my somewhere.

**CROSS-REFERENCE**

:ref:`dir` will produce a list of all of the files on
a given medium. :ref:`wcopy` contains details of how
wildcards operate.

--------------


..  _wget:

WGET
====

+----------+----------------------------------------------------------------------------+
| Syntax   | WGET [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
+----------+----------------------------------------------------------------------------+
| Syntax   | WGET [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+----------------------------------------------------------------------------+
| Location | SMSQ/E                                                                     |
+----------+----------------------------------------------------------------------------+

This command is very similar to BGET, except that this fetches a word
(in the range 0..65535) from the given channel (default #3).

**CROSS-REFERENCE**

See :ref:`wput` and :ref:`bget`.

--------------


..  _when--condition:

WHEN condition
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  WHEN condition                                                   |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM), THOR XVI, Not SMSQ/E                           |
+----------+-------------------------------------------------------------------+

WHEN is used to identify the start of a SuperBASIC structure which is
used to surround lines of SuperBASIC code which should be executed
whenever the given condition is met. The condition is not checked when a
variable is READ, or INPUT. 

The syntax of the SuperBASIC structure can
take two forms:

WHEN condition:statement:sup:`\*`\ [:statement]\ :sup:`\*` 

or 

WHEN condition  :sup:`\*`\ [statements]\ :sup:`\*` .. END WHEN

The condition can be anything which is accepted by the IF
command, provided that it begins with the name of a variable (for
example, WHEN a-10=b is acceptable, but WHEN 10-a=b is not). The
variable cannot be an array. 

When a program is run, the interpreter will
make a note of the variable being tested and then jump to the statement
following the END WHEN statement (unless the in-line format is used when
control jumps to the next line if END WHEN does not appear on that
line). Great care must however, be taken where the condition refers to
more than one variable, as an 'error in expression' will be reported if
a variable is not defined when the condition is tested, for example, the
following stops with 'error in expression' at line 4::

    4 WHEN x>1 AND y>1
    5   x=x+1:PRINT 'hello' 
    6 END WHEN 
    7 PRINT 'Start' 
    8 :
    100 FOR x=1 TO 2 
    110   FOR y=1 TO 2 
    120     PRINT x,y;' '; 
    130   END FOR y 
    140 END FOR x
 
This is because when line 100 is processed, the interpreter jumps to
the WHEN clause. At this stage, y is undefined, hence the error. The
program will work if you add the line::

    1 y=0
    
Although blocks can be specified which check for various conditions of
the same variable, if the conditions overlap, there is no guarantee as
to which WHEN statement will be executed first. Blocks cannot be mixed
together. In the following example, although if a$='me' the messages
'hello' and 'who' will be printed, and if a=2 the only message which
will be printed is 'A is 2' - when the program is RUN, the first END
WHEN command is matched with line 1, thus the message 'who' is also
printed when the program is run (it is extremely bad programming
practice in any event to mix program structures of this sort). 

::

    1 WHEN a$='me' 
    2   PRINT 'hello' 
    3   WHEN a=2 
    4     PRINT 'A is 2' 
    5   END WHEN 
    6   PRINT 'Who' 
    7 END WHEN

WHEN processing is turned off by the command WHEN anything, and also
when the NEW, CLEAR, LOAD, LRUN, MERGE, and MRUN commands are issued.
You can also switch off WHEN processing on a given variable (eg. b) by
the command WHEN b (in the following example).

**Example**

::

    110 WHEN a>100 AND a<1000: PRINT 'A is now in the range 100-1000': a=a+100 
    120 WHEN b=a 
    130   PRINT 'B is now the same as A ': PRINT B,A: A=A+50 
    140 END WHEN 
    150 WHEN b MOD 100=0: b=b+200 
    155 :
    160 LET a=100: b=a 
    170 a=10 
    180 REPeat Loop 
    190   a=a+1: b=b-1 
    200   AT 0,0: PRINT 'A='!a\\'B='!b 
    210 END REPeat Loop

**NOTE 1**

This command does not work reliably on any QL versions other than
Minerva v1.77 or later: although Toolkit II improves the reliability,
problems include calling the block more than once, and reporting 'bad
name' when the block is called. WHEN clauses will also remain in force
despite NEW, CLEAR, LRUN, LOAD, MERGE and MRUN, unless Toolkit II is
present.

**NOTE 2**

A WHEN clause will not be called if it is already active, even though
the program may have jumped out of the actual WHEN
clause. For example::

    100 WHEN a=100: PRINT 'A=100': GOTO 400 
    115 :
    110 a=10 
    120 REPeat loop 
    130   a=a+10: PRINT a 
    140 END REPeat loop 
    150 STOP 
    160 :
    400 FOR a=10 TO 200 STEP 30 
    410   PRINT a 
    420 END FOR a

**NOTE 3**

On JS MG and THOR XVI ROMs, a maximum of 20 WHEN clauses can be active
at any time.

**CROSS-REFERENCE**

Other SuperBASIC structures are :ref:`when--error`, 
:ref:`select--on` and
:ref:`if`..\ :ref:`end--if`. 

:ref:`end--when` defines the end of a WHEN XXX structure.

--------------


..  _when--error:

WHEN ERRor
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  WHEN ERRor                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM (post JM), THOR XVI                                       |
+----------+-------------------------------------------------------------------+

This command marks the beginning of the SuperBASIC structure which is
used to surround lines of SuperBASIC code which should be executed
whenever an error is generated whilst error trapping is active. Error
trapping is activated as soon as the interpreter reads a line containing
WHEN ERRor. It is therefore not activated by a WHEN ERRor command being
entered into the command window (#0) - indeed this has a special purpose
(see below). The syntax of the SuperBASIC structure can take two forms:

WHEN ERROR: statement :sup:`\*`\ [:statement]\ :sup:`\*` 

or 

WHEN ERROR  :sup:`\*`\ [statements]\ :sup:`\*` .. END WHEN

In the normal course of progress, the WHEN ERRor block would appear at
the start of a SuperBASIC program, and error trapping would therefore be
enabled as soon as a program is RUN. Once error trapping is enabled,
whenever an error is generated, control is passed to the WHEN ERRor
clause, allowing you to specify how it the error to be dealt with. 

It must however be borne in mind that whilst active, errors will trigger
the WHEN ERRor clause whether they are generated whilst the program is
being RUN or at some other stage (eg. if a direct command causes an
error). If the interpreter comes across more than one WHEN ERRor
block, then the latest one is used to trap errors. 

Errors generated
within the WHEN ERRor block itself are reported as normal, although the
message 'during WHEN processing' is displayed along with the error
message. Unless you include a STOP statement in the WHEN ERRor clause,
after going through all of the lines within the clause, the program will
continue running from the statement following the one which caused the
error. 

You can force this to happen with CONTINUE, whereas RETRY can be
used to re-execute the command which caused the error. Error trapping is
turned off by the command WHEN ERRor (when entered as a direct command),
and also when the NEW, CLEAR, LOAD, LRUN, MERGE, and MRUN commands are
issued.

**Example**

A program which provides a fully error trapped educational aid::

    100 WHEN ERRor 
    110   STRIP#0,2 
    120   IF ERR_XP 
    130     PRINT#0,'Please enter a number!'\'Press a key' 
    140     PAUSE:STRIP #0,0:RETRY 320 
    150   END IF 
    160   IF ERR_OV 
    170     PRINT#0,'Divide by zero is undefined!'\'Press a key' 
    180     PAUSE:STRIP #0,0:RETRY 320 
    190   END IF 
    200   STRIP #0,0 
    210   PRINT #0,'At line: ';ERLIN:REPORT:STOP 
    220 END WHEN 
    225 :
    230 MODE 8 
    240 WINDOW 448,200,32,16:PAPER 0:INK 6:CLS 
    250 WINDOW #0,448,40,32,216:PAPER#0,0:INK#0,7:CLS#0 
    260 CSIZE 2,0:AT 8,8:PRINT 'Maths Division Tutor' 
    270 CSIZE 1,0 
    280 REPeat loop 
    290   y=RND(1 TO 10):x=RND(1 TO 10)*y 
    300   IF y>x:ya=x:x=y:y=ya 
    310   IF RND>.9:x=0:y=0 
    320   REPeat answer 
    330     AT 10,0:CLS 2:AT 11,0:CLS#0 
    340     INPUT 'Enter number to divide'!(x)!'by to give'!(y)!': ';a 
    350     IF x/a=y THEN EXIT answer 
    360     PRINT \\'Wrong - Please try again'\'Press a key' 
    370     PAUSE 
    380   END REPeat answer 
    390   PRINT \\'Correct - Another one...'\'Press a key' 
    400   PAUSE 
    410 END REPeat loop

**NOTE 1**

This SuperBASIC structure does not work very reliably on any QL versions
other than Minerva v1.77 (or later), SMS or the THOR XVI: although
Toolkit II improves the reliability, problems include crashing the
machine if an error is generated inside a function whilst error trapping
is enabled {eg. PRINT SQRT(-1)}, or if you try to carry out INKEY$ at
the end of a file. WHEN ERRor clauses will also remain in force despite
NEW, CLEAR, LRUN, LOAD, MERGE and MRUN.

**NOTE 2**

WHEN ERRor cannot trap the Break key <CTRL><SPACE> (and <ESC> on
Minerva), which will continue to stop a SuperBASIC program.

**NOTE 3**

You should not try to nest several WHEN ERRor clauses - under SMS the
error 'WHEN clauses may not be nested' is reported.

**SMS NOTE**

Even in the in-line version of WHEN ERRor it is imperative that END WHEN
is specified, otherwise the error 'Incomplete WHEN clause' will be
reported.

**CROSS-REFERENCE**

:ref:`erlin` returns the line number on which the
error occurred. :ref:`ernum` returns the error
number itself. There are several functions in the form
:ref:`err-...` which return 1 if the given error
has occurred. :ref:`break-off` allows you to
turn the Break key off. :ref:`end--when` defines
the end of the error handling block.

--------------


..  _where-fonts:

WHERE\_FONTS
============

+----------+-------------------------------------------------------------------+
| Syntax   | address = WHERE\_FONTS(#channel, 1\_or\_2)                        |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns a value that corresponds to the address of the fonts in use on the specified channel. The second parameter must be 1 for the first font address or 2 for the second, there are two fonts used on each channel. If the result is negative then it will be a normal QDOS error code. The channel must be a CON\_ or a SCR\_ channel to avoid errors.

**EXAMPLE**

The following example will report on the two fonts used in any given channel, and will display the character set defined in that font::

    4480 DEFine PROCedure REPORT_ON_FONTS (channel)
    4485   LOCal address, lowest, number, b
    4490   REMark show details of channel's fonts
    4495   CLS
    4500   FOR a = 1,2
    4505     address = WHERE_FONTS(#channel, a)
    4510     lowest = PEEK(address)
    4515     number = PEEK(address + 1)
    4520     PRINT '#'; channel; ' font '; a; ' at address '; address
    4525     PRINT 'Lowest character code = '; lowest
    4530     PRINT 'Number of characters  = '; number + 1
    4535     REMark print all but default characters
    4540     PRINT : REMark blank line
    4545     FOR b = lowest + 1 TO lowest + number :PRINT CHR$(b);
    4550     PRINT \\\ : REMark 2 blank lines
    4555   END FOR a
    4560 END DEFine REPORT_ON_FONTS

--------------


..  _width:

WIDTH
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  WIDTH [#channel,] x                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The WIDTH command is an output formatting command which allows the user
to specify the width of a device which is being used by the QL for
output (such as a printer) on the given channel (default #1). This can
only be used on non-screen (ie. not scr\_ or con\_) channels and only
has any effect if you use one of the separators exclamation mark (!);
comma (,) or TO when PRINTing. 

The value of x should represent the number of characters
wide which the output device is to use (the default is 80 characters).

**Example**

A short procedure to output text to a non-screen device of a given width
without chopping off any words at the end of each line:: 

    100 :
    110 t$ = 'The way in which the WIDTH command works is very particular to the QL '
    120 t$ = t$ & 'and is really only suited for specific types of work. If you do not '
    130 t$ = t$ & 'use the separators ! or , then the text will still be output at the '
    140 t$ = t$ & 'default width of 80'
    115 :
    200 OPEN_NEW #3,ram2_junk 
    210 DUMP_TEXT #3, t$, 80 
    220 DUMP_TEXT #3, t$, 40 
    230 :
    240 CLOSE#3 
    250 :
    260 :
    1000 DEFine PROCedure DUMP_TEXT(chan,str$,wid) 
    1010   LOCal word$ 
    1020   WIDTH #chan,wid 
    1030   IF str$="" THEN RETurn 
    1040   word_start=1 
    1050   REPeat word_loop 
    1060     word_end=(' ' INSTR str$)-1 
    1070     IF word_end>=word_start 
    1080       word$=str$(word_start TO word_end) 
    1090     ELSE 
    1100       word$=str$(word_start TO ) 
    1110     END IF 
    1120     PRINT #chan;!word$!:PRINT !word$!:PAUSE 
    1130     IF word_end+2>LEN(str$) OR word_end=-1:EXIT word_loop 
    1140     str$=str$(word_end+2 TO ) 
    1150   END REPeat word_loop 
    1160 END DEFine

**CROSS-REFERENCE**

See :ref:`open` and :ref:`print`.

--------------


..  _window:

WINDOW
======

+----------+----------------------------------------------------------------------+
| Syntax   | WINDOW [#ch,] x, y, posx, posy  or                                   |
+----------+----------------------------------------------------------------------+
| Syntax   | WINDOW [#ch,] x, y, posx, posy [\\border] (Minerva v1.79+, THOR XVI) |
+----------+----------------------------------------------------------------------+
| Location | QL ROM, Minerva, THOR XVI                                            |
+----------+----------------------------------------------------------------------+

This command redefines the given screen window (default #1) by
specifying the new size and position of the window. The values must all
be calculated in the pixel co-ordinate system, which means that x and
posx can be in the range 0...XLIM (in both MODE 4 and MODE 8), provided
that x+posx<=XLIM and y and posy can be in the range 0..YLIM, provided
that y+posy<=YLIM. 

On a standard QL resolution screen (ie. 512x256
pixels), due to the shape of the screen, a window which measures 100x100
pixels will not appear square. You will need to use a size of 137x100
pixels instead! The Minerva and THOR XVI variants allow you to specify a
border to be drawn around the window at the same time, by the addition
of up to a further four parameters in the form: [\\border\_size [,colour
[,colour2 [,stipple ]]]] This therefore allows you to combine the WINDOW
and BORDER commands. For example::

    WINDOW 448,200,32,16\2,2
    
is the same as::

    WINDOW 448,200,32,16:cBORDER 2,2.

**Example**

::

    WINDOW 448,200,32,16 
    
is similar to::

    OPEN #1,CON

**NOTE 1**

Although the '\\' separator is not checked for on the Minerva and THOR
XVI implementations, it is recommended to ensure that this is present to
ensure future compatibility. Older ROM versions did not check the number
of parameters, which could result in some software causing problems
unless the separator is actually checked for.

**NOTE 2**

You cannot have a gap of one pixel between windows, even in MODE 4 -
this is to ensure compatibility between MODE 4 and MODE 8. Any odd
parameters will be rounded down.

**MINERVA NOTE**

In a MultiBasic, both channel #0 and #1 are inextricably linked.
Unfortunately, this means that in certain cases both channel #0 and
channel #1 must have the same size and position: any attempt to re-size
#0 will re-size #1 and vice versa. See the MultiBasic appendix for
further details.

**CROSS-REFERENCE**

:ref:`open` allows you to open a window ready for
use. :ref:`border` allows you to set an implicit
border.

--------------


..  _winf-dlr:

WINF$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  WINF$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

This is the same as :ref:`wman-dlr`.

--------------


..  _win2:

WIN2
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN2 directory                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card, THOR XVI and ST/QL (Level C-19+)                      |
+----------+-------------------------------------------------------------------+

This command simulates the drive win2\_ if only one harddisk (win1\_)
is present. All access to win2\_ will be redirected to directory.

**Example**

    WIN2 system: DIR win2_
    
will produce a listing of the files held in the sub-directory
win1\_system. This is equivalent to::

    DIR win1_system
    

**NOTE**

Do not specify the device as part of directory.

**CROSS-REFERENCE**

:ref:`dev-use` is much more flexible.

--------------


..  _win-base:

WIN\_BASE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_BASE [(#channel)]                                           |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

This function returns the start address of the definition block for the
specified window (default #1). If an error occurs WIN\_BASE returns the
appropriate QDOS error code, eg. -15 if the channel does not apply to a
window or -6 if the channel is not open.

**Example**

Some information about the internal structure of QDOS is necessary to
make use of WIN\_BASE from SuperBASIC. This function returns the PAPER
background colour of a window::

    100 DEFine FuNction GET_PAPER (winchan) 
    110   IF WIN_BASE(#winchan)<0 THEN 
    120     PRINT#0,"GET_PAPER: ";: REPORT #0, WIN_BASE(#winchan) 
    130     PAUSE 800: STOP 
    140   END IF 
    150   RETurn PEEK(WIN_BASE(#winchan)+68) 
    160 END DEFine GET_PAPER

**NOTE**

The Window Manager changes the structure of window definition blocks.

**CROSS-REFERENCE**

:ref:`sys-base`, :ref:`set`

--------------


..  _win-drive:

WIN\_DRIVE
==========

+----------+------------------------------------------------------------------+
| Syntax   | WIN\_DRIVE driveno [, unit, disk] or                             |
+----------+------------------------------------------------------------------+
| Syntax   | WIN\_DRIVE driveno, unit [,disk] [,partition ](SMSQ/E only)  or  |
+----------+------------------------------------------------------------------+
| Syntax   | WIN\_DRIVE driveno, path$(QPC & QXL SMSQ/E only)                 |
+----------+------------------------------------------------------------------+
| Location | ST/QL, SMSQ/E for Atari and QXL / QPC                            |
+----------+------------------------------------------------------------------+

It is possible not only to have several hard disk units attached to the
Atari ST, but each hard disk unit can also have more than one drive in
it (for example, you might own a hard disk unit which has both a
standard hard disk and a changeable hard disk inside). 

The normal chain
of events is that each WIN drive would attach itself to the equivalent
hard disk unit, for example, WIN1\_ would be connected to hard disk unit
0, WIN2\_ to hard disk unit 1 and so on... However, so that you may link
the WIN drives to specific disks within each unit, the WIN\_DRIVE
command exists. 

WIN\_DRIVE takes the WIN drive number supplied by
driveno and will attach this to the specified disk which is housed in
the specified unit. 

Driveno must be in the range 1...8 - this
corresponds to the number which will be attached to WIN to refer to the
relevant drive (eg. WIN4\_). If a unit and disk are not specified, this
command will remove the definition attached to the specified driveno.

Unit should be in the range 0...7 and represents the number of the disk
drive controller. An internal disk drive controller is normally unit 0,
but external controller unit numbers will depend upon the setting of the
switches on the back of the box. 

If you are running SMSQ/E on the TT and
wish to access a SCSI disk controller, then you will need to add 8 to
the value of unit. 

Disk can be in the range 0...7 and represents the
number of the disk drive actually addressed by the given controller. It
is however rare in the Atari world to have more than one disk drive per
controller and so this value is normally either 0 or 1. The default is
0. 

Finally, each disk can be partitioned, so that an area of each disk
is set aside for specific uses (eg. for QDOS or for GEM). You therefore
need to specify the number of the partition. Default is 0. Although you
can configure SMSQ/E to start from a specific drive and partition, it
normally looks for a BOOT file in any partition on unit 0 (on the TT it
will look at SCSI unit 0 and then ASCI unit 0). If found, WIN1\_ will be
set to this partition. 

In current versions of SMSQ/E WIN2\_ will not be
linked to anything until you use the WIN\_DRIVE command.

**Example**

Assume that you have two hard disk units plugged into the Atari ST,
the first one of which (unit 0) contains a normal hard disk unit (disk
0) and a changeable hard disk unit (disk 1). 

On starting the Emulator,
WIN1\_ would refer to the normal hard disk in unit 0 and WIN2\_ would be
undefined. You could not therefore access the changeable hard disk from
the Emulator. To avoid this, use the commands::

    WIN_DRIVE 2,0,1,0
    WIN_DRIVE 3,1,0,2
    
This will link WIN2\_ to the changeable hard disk (this is disk number
1 in unit 0, partition 0) and WIN3\_ would then point to the hard disk
in the second unit (disk 0 in unit 1, partition 2).

**NOTE**

Disk must be specified unless it is 0. - this means that if three
parameters are specified, the third parameter is taken to be the
partition number.

**QPC / QXL NOTE**

From v2.89 of SMSQ/E, WIN\_DRIVE is implemented slightly differently on
these emulators. For each driveno, you can specify a PC related path for
the hard disk (the hard disk under QPC and QXL is implemented as a
single file stored on the PC's hard disks). For example, use::

    WIN_DRIVE 2,'D:\qxl.win'
    
to make win2\_ on the QL emulator look use the file qxl.win on the PC's
D: drive. In this way, CD-ROMs and DVD-RAMs can be used on the PC as a
hard drive for the QL emulator. Although QPC allows you to have several
QL hard disk files on each PC device, QXL only allows one qxl.win file
per PC device!!

**WARNING 1**

You must not make the QDOS WIN drive point to another physical drive if
that WIN device has been accessed already. For example, if you wanted to
follow the above example, but had just loaded a program from WIN2\_ you
*must not* use::

    WIN_DRIVE 2,0,1.

**WARNING 2**

Do not attempt to make two WIN drives point to the same physical drive!

**CROSS-REFERENCE**

:ref:`win-drive-dlr` returns the parameters
already associated with a WIN drive.
:ref:`win-format` allows you to format a hard
disk.

--------------


..  _win-drive-dlr:

WIN\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_DRIVE$ (drive)                                              |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Atari and QXL / QPC                                   |
+----------+-------------------------------------------------------------------+

On SMSQ/E for the Atari, this function returns a string containing the
unit, disk and partition numbers addressed by the specified WIN drive.

Under SMSQ/E for the QXL and QPC (v2.89+), this function will return a
string indicating the file on the PC which is used as that hard drive.

If the specified drive has not been linked to any particular hard disk
partition, an empty string is returned.

**Atari Examples**

::

    WIN_DRIVE 2,0,1,0 
    PRINT WIN_DRIVE$(2): REMark Will print 0,1,0

**QXL / QPC Examples**

::
    
    WIN_DRIVE 2,'C:\qxlback.win' 
    PRINT WIN_DRIVE$(2): REMark will print C:\qxlback.win

**CROSS-REFERENCE**

See :ref:`win-drive`.

--------------


..  _win-format:

WIN\_FORMAT
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_FORMAT drive [,protect]                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E (v2.73+) for Atari and QXL / QPC                          |
+----------+-------------------------------------------------------------------+


In order to prevent you from accidentally formatting your hard disk (or
a partition of your hard disk) and overwriting important information,
SMSQ/E has implemented a form of protection. Before formatting a QDOS
partition, you will first of all need to create that partition using
either the Atari's or the PC's operating system (see the SMSQ/E
documentation for details). You must then use the WIN\_DRIVE command,
followed by WIN\_FORMAT to allow the FORMAT command to work on the hard disk. 

Protect is a flag - if it is omitted, this removes the protection from the partition
pointed to by the specified WIN drive. protect=1 sets the protection
again after FORMATting.

**Example**

To format a QDOS partition called PROGS, pointed to by WIN2 on unit 1,
partition 1::

    WIN_DRIVE 2,1,1 
    WIN_FORMAT 2 
    FORMAT win2_PROGS
    WIN_FORMAT 2,1

**NOTE**

Earlier versions of SMSQ/E did not include this command and the FORMAT
command would work once WIN\_DRIVE had been used to set up the WIN drive
name.

**CROSS-REFERENCE**

See :ref:`format` and
:ref:`win-drive`.

--------------


..  _win-remv:

WIN\_REMV
=========

+----------+------------------------------------------------------------------+
| Syntax   | WIN\_REMV driveno, flag (SMSQ/E & ST/QL Level C-24+)  or         |
+----------+------------------------------------------------------------------+
| Syntax   | WIN\_REMV driveno                                                |
+----------+------------------------------------------------------------------+
| Location | ST/QL (Level C-20+), SMSQ/E for Atari, QXL / QPC                 |
+----------+------------------------------------------------------------------+

The advent of changeable hard disk drives caused a lot of problems,
since it is just about feasible that you might try to remove the hard
disk unit whilst it is being accessed, which can cause serious damage to
the drive unit. Although the drives attempt to warn the computer when
they are and are not removeable, it is next to impossible to ensure that
when the drive says it can be removed, it is not actually powering up or
down. 

The command WIN\_REMV tells the system that the drive connected to
the specified port is a removeable hard disk drive - the door on the
unit will then remain firmly locked as long as any files on the hard
disk are open. 

Note that driveno must be in the range 1...8. SMSQ/E
allows the first variant - flag can be omitted which is equivalent to 1
(signifies a removeable hard disk). It can also be one of the following
values: 

- 0: Clear the removeable flag from the drive 
- V: Mark the drive as being a VORTEX drive

**Example**

::

    WIN_REMV 2 
    
denotes win2\_ as a removeable disk drive.

**NOTE**

It is essential that WIN\_REMV is used as early as possible - either
before the drive is first accessed or as the first line of your boot
program if the Emulator is being booted from the hard disk in question.

**SMSQ/E NOTE**

SMSQ/E manages to detect removeable hard disks 100% on SCSI ports. It is
also normally successful in detecting removeable hard disks connected to
ASCI ports unless you configure it to ignore them, therefore this
command is only really needed on ASCI drives.

**QPC NOTE**

You need v1.43+ of QPC to use removeable drives.

**WARNING**

Never try to remove a hard disk (removeable or otherwise!) whilst it is
running.

**CROSS-REFERENCE**

:ref:`win-stop` will park the head on the drive
prior to removal. :ref:`dmedium-remove`
can tell you if the given device is a removeable hard disk.

--------------


..  _win-slug:

WIN\_SLUG
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_SLUG x                                                      |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for Atari                                          |
+----------+-------------------------------------------------------------------+

Some winchester (hard disk) ASCI drives, in particular the Megafile and
Vortex drives, need a special parameter to be passed to them before they
can be accessed by the QL due to timing faults in their controllers.
WIN\_SLUG allows you to set this parameter. 

The value of x will depend
upon the drive being used, and can be anything in the range 0...255. It
is measured in units which are 0.8ms. This parameter sets the minimum
time that must elapse between operations on the ASCI bus. Most
controllers work with the default setting of 30 (which equates to a time
of 2.5ms). Refer to the disk documentation for further details.

--------------


..  _win-start:

WIN\_START
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_START driveno                                               |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for Atari and QPC / QXL                            |
+----------+-------------------------------------------------------------------+

After the head on a changeable hard disk drive has been parked, it is
necessary to tell it to release its head before you can access the
drive. WIN\_START issues the command to do this. The parameter driveno
is the number of the hard disk to be told to release the head. Driveno
must be in the range 1...8.

**Example**

::

    WIN_START 1 
    
releases the head on win1\_.

**NOTE**

Some hard disk drives will not release the head even after WIN\_START
unless the power to the drive is switched off and back on.

**CROSS-REFERENCE**

See also :ref:`win-drive` and
:ref:`win-stop`.

--------------


..  _win-stop:

WIN\_STOP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_STOP driveno                                                |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E for Atari and QPC / QXL                            |
+----------+-------------------------------------------------------------------+

If you are going to move a computer around, or swap over a changeable
hard disk drive, it is *essential* that you make sure that the head on the
hard disk drive is parked. This basically means that the drive locks the
head away and ensures that it cannot be banged onto the surface of the
hard disk drive. 

Some hard disk interfaces (such as the Miracle Hard
Disk system for the QL) automatically park the head if the drive has not
been accessed for a while. However, on other systems, it is necessary to
do this explicitly. WIN\_STOP tells the hard disk in the specified drive
to park its head. driveno must be in the range 1...8.

**Example**

::

    WIN_STOP 2
    
will park the head in win2\_.

**WARNING 1**

Never move a hard disk about unless its head is parked as this can cause
permanent damage to the drive.

**WARNING 2**

Some hard disk drives require that you park the head before
disconnecting the power to the drive. Refer to the instructions for the
hard disk which you are using.

**WARNING 3**

You may find that some drives will refuse to respond to access calls if
stopped accidentally, or when using this command. If WIN\_START does not
revive them, then unfortunately the only thing to do is to reset the
system (switching the power back and back on).

**CROSS-REFERENCE**

:ref:`win-start` releases the head so that the
drive can be used again.

--------------


..  _win-use:

WIN\_USE
========

+----------+--------------------------------------------------------------------+
| Syntax   |  WIN\_USE [device]                                                 |
+----------+--------------------------------------------------------------------+
| Location |  THOR XVI, ST/QL, Hard disk driver, SMSQ/E for Atari and QXL / QPC |
+----------+--------------------------------------------------------------------+


As with FLP\_USE this allows you to assign another three letter
description to the WIN device driver, so that it can be accessed by
programs which do not allow you to alter their devices. If no device is
specified, then the device name is returned to the default win.

**Example**

::

    WIN_USE mdv
    
will ensure that any further attempt to access mdv1\_ will actually
access win1\_. If you later use the command::

    WIN_USE
    
or::

    WIN_USE win
    
then you will once again be able to use the microdrives as well as
win1\_.

**NOTE**

The QL's operating system tests for directory device drivers in a fixed
order: DEV, FLP, RAM, WIN and MDV. This means that if you rename a
driver to three letters which refer to a device driver earlier in the
list, that original device driver will be used in preference. For
example::

    WIN_USE flp
    
will not work (attempts to read a file from flp1\_ will still try to
read floppy disk drive number one) - you will need to also rename the
floppy disk driver::

    FLP_USE flp

**CROSS-REFERENCE**

:ref:`flp-use`,
:ref:`ram-use`,
:ref:`dev-use` are similar.
:ref:`dmedium-type` can be used to find out
the type of device which a name actually refers to.
:ref:`dmedium-name-dlr` will return the default
name of a device.

--------------


..  _win-wp:

WIN\_WP
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  WIN\_WP drive, protect                                           |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Atari and QXL / QPC                                   |
+----------+-------------------------------------------------------------------+

This command allows you to mark a specified WIN drive as read only
protect=1 will write protect the hard disk. protect=0 (the default) will
remove the write protection.

**CROSS-REFERENCE**

:ref:`dmedium-rdonly` will tell you if a
device is read only. See also :ref:`win-remv`
and :ref:`win-format` for other types of
protection.

--------------


..  _wipe:

WIPE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WIPE                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools, WIPE                                                 |
+----------+-------------------------------------------------------------------+

This command clears the whole screen so that it is completely black.

WIPE is an alternative to::

    OPEN#11,scr_512x256a0x0: 
    CLS#11: 
    CLOSE#11
    
or::

    SCRBASE SCREEN: SCLR 0

**NOTE**

This command presumes that the screen starts at 131072 and measures
512x256 - it will therefore not work on higher resolutions.

**CROSS-REFERENCE**

:ref:`cls` clears a window in its current paper
colour, :ref:`sclr` the (background) screen in a
given colour. :ref:`cls-a` is a global
:ref:`cls`.

--------------


..  _wld:

WLD
===

+----------+------------------------------------------------------------------+
| Syntax   | WLD (word1$, word2$ [,dummy] )  or                               |
+----------+------------------------------------------------------------------+
| Syntax   | WLD (word1$, word2$, w1, w2, w3 [,dummy] )                       |
+----------+------------------------------------------------------------------+
| Location | Ähnlichkeiten                                                    |
+----------+------------------------------------------------------------------+

This function calculates the weighted levenstein phonetic distance
between two strings: the smaller the result, the more that the two
strings are phonetically similar. 

If two strings are found to be
identical, then 0 is returned, otherwise a postive integer is returned.

The value of the dummy parameter does not actually matter - if it is
present then the function will not distinguish between upper and lower
case characters. 

The three additional parameters of the second syntax
allow you to alter the importance of three possible factors used to
calculate the difference between the strings - each parameter should
have a positive value: 

- w1: wrong letters 
- w2: strings too short 
- W3: strings too long

**Example**

::

    100 a$="Sinclair QL": b$="IBM PC": CLS 
    110 PRINT a$;" <-> ";b$ 
    120 PRINT\WLD(a$,b$), WLD(a$,b$,0) 
    130 PRINT WLD(a$,b$,1,1,1), WLD(a$,b$,1,1,1,0) 
    140 PRINT WLD(a$,b$,0,0,0) 
    150 PRINT WLD(a$,b$,1,2,3), WLD(a$,b$,3,2,1)

**CROSS-REFERENCE**

:ref:`soundex`,
:ref:`phonem`.

--------------


..  _wm:

WM
==

+----------+-------------------------------------------------------------------+
| Syntax   |  WM                                                               |
+----------+-------------------------------------------------------------------+
| Location |  WM                                                               |
+----------+-------------------------------------------------------------------+

QPAC2 uses a Button Frame which is normally situated across the top of
the screen. The command WM sets up the three basic windows #0, #1 and #2
so that there is space for two rows of buttons. At the same time, the
window attributes are reset to the status they would have been in had
you reset the system and pressed <F1> for monitor mode. The current
screen resolution mode is not affected.

**NOTE**

QPAC2 and the Pointer Environment are not necessary to use WM.

**CROSS-REFERENCE**

:ref:`wmon` restores the original monitor windows and
:ref:`wtv` the TV mode. Use
:ref:`ink`, :ref:`paper`,
:ref:`border` and :ref:`strip`
to change window attributes.

--------------


..  _wman-dlr:

WMAN$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  WMAN$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

This function returns the version number of the Window Manager. If no
Window Manager is present, WMAN$ returns an empty string.

**Example 1**

SCR\_SIZE is incompatible with the Window Manager because the channel
definition blocks for windows are different from those used when no
Window Manager is present, causing SCR\_SIZE to return wrong values or
produce errors. But calculating the result of SCR\_SIZE is so simple
that it can be replaced by a BASIC procedure to be used whenever the
Window Manager is detected. w\_width and w\_height define the window
size. 

::

    100 IF LEN(WMAN$) THEN 
    110   size=8+w_width*w_height/8 
    120 ELSE size=SCR_SIZE 
    130 END IF

**Example 2**

Non-destructible windows can be simulated by programs if there is no
Window Manager present to take over that work. 

::

    100 OPEN#3,con_200x50a100x50 
    110 IF WMAN$="" THEN ScrTmp=S_SAVE(#3) 
    120 BORDER#3,1,4: PAPER#3,3: CLS#3

    ...... (main program using #3) ... 
     
    800 CLOSE#3 
    810 IF WMAN$="" THEN S_LOAD ScrTmp 
    820 STOP

**CROSS-REFERENCE**

:ref:`qram-dlr` returns the version number of the
Pointer Interface.

--------------


..  _wmon:

WMON
====

+----------+------------------------------------------------------------------+
| Syntax   | WMON [mode] or                                                   |
+----------+------------------------------------------------------------------+
| Syntax   | WMON [mode] [, xoff] [, yoff](SMS Only)                          |
+----------+------------------------------------------------------------------+
| Location | THOR 8, THOR XVI, Toolkit II                                     |
+----------+------------------------------------------------------------------+

When the QL is first started up in Monitor mode, the windows #0, #1 and
#2 are opened in the following sizes and positions, with the following
borders:- 

- #0 is con\_512x50a0x206 (no border) 
- #1 is con\_256x202a256x0 (BORDER #1,1,7,0) 
- #2 is con\_256x202a0x0 (BORDER #2,1,7,0) 

As with WTV, this
command resets the three default windows to the above sizes, positions
and borders. If one parameter is passed, this will alter the screen
MODE. 

The second variant allows you to move the SuperBASIC windows, by
specifying an offset which will be used to calculate the top left hand
position of the windows. If only one parameter (other than the MODE) is
specified, then this will be taken to be both the x and y offset,
otherwise you can specify both. This will only work on higher resolution
displays. Also, if the second variant is used, if an outline has
previously been defined (for example with OUTLN), then the contents of
the three windows will be retained and moved to the new position - this
is equivalent to following the WMON
command with an OUTLN command with the details of the new position and
size.

**Example**

::

    WMON 4
    
Will reset standard windows and set MODE 4.

::

    WMON , 50
    
Resets the standard windows, in current MODE. The windows are set as follows: 

- #0 is con\_512x50a50x256(BORDER #0,1,7,0) 
- #1 is con\_256x202a306x50(BORDER #1,1,7,0) 
- #2 is con\_256x202a50x50(BORDER #2,1,7,0) 


::

    WMON 4,50,50
    
Is the same except it forces MODE 4.

**NOTE 1**

WMON does not reset the PAPER and INK colours of the three windows.

**NOTE 2**

On some versions of Minerva (pre v1.78) and Toolkit II, if you do not
specify the mode, this command will have no effect.

**NOTE 3**

On versions of the THOR 8 (pre v4.01) #0 appeared one pixel too far up
the screen following WMON.

**NOTE 4**

On SMS prior to v2.53 WMON would set an OUTLN if one had not already
been set.

**SMS NOTE**

As well as adding the second variant, SMS adds a border to #0 (see
example above). v2.67+ has also fixed various problems with this
command.

**CROSS-REFERENCE**

Also see :ref:`wtv`, :ref:`wm`,
:ref:`wset`, :ref:`wmov` and
:ref:`mode`.

--------------


..  _wmov:

WMOV
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WMOV [#] channel [!]                                             |
+----------+-------------------------------------------------------------------+
| Location |  PEX (v20+)                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to interactively alter the size and position of the specified Window
channel by using the following keys: 

- <cursor keys>  Move the Origin.
- <SHIFT><cursors>  Alter the size of the Window. (See below) 
- <ESC>  Leave the procedure - do not alter Window size and position. 
- <ENTER>  Accept the new size and position. 

Note that <ALT> plus the <cursor keys> or <SHIFT><cursors> allows you to move more quickly. 

You can use this 
command to re-size a specified BASIC window (use # before channel) or a
window used by another Job. If you wish to do the latter, then you will
need to omit the # and channel must be the QDOS Channel number (see
CHANNELS). PEX22 onwards ensured that when you use this command to alter
the size and position of the primary window of a job (set with OUTL),
the sizes and relative origins of all secondary windows are preserved.
PEX22 onwards also allows you to place an exclamation mark (!) after the
channel number, in which case the window sizes cannot be altered - only
their position.

**WARNING**

Do not press <CTRL><C> or change Jobs whilst using this command - it can
crash the system!!

**CROSS-REFERENCE**

Also see :ref:`wtv`, :ref:`wmon`,
:ref:`pick-pct`, and :ref:`outl`.

--------------


..  _wput:

WPUT
====

+----------+----------------------------------------------------------------------------+
| Syntax   | WPUT [#ch\\position,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..] or |
+----------+----------------------------------------------------------------------------+
| Syntax   | WPUT [#ch,] [item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` ..]              |
+----------+----------------------------------------------------------------------------+
| Location | SMSQ/E                                                                     |
+----------+----------------------------------------------------------------------------+

This command is very similar to BPUT, except that this sends a word (in
the range 0..65535) to the given channel (default #3).

**CROSS-REFERENCE**

See :ref:`wget` and :ref:`bput`.

--------------


..  _wren:

WREN
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WREN [#ch,] [wild1] [TO wild2]                                   |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to rename several files at the same time. It
allows wildcards on both the source and destination parameters. If the
source parameter (wild1) does not include a valid device, the default
data device will be used. However, the way in which wild2 is calculated,
is even more complex than normal: 

#. If wild2 is not specified, rename each file using the default destination directory. 
#. If wild2 is specified and contains a device, use that device. 
#. If wild2 does not include a device, use the same device as for wild1 (ie. the device
   specified as part of wild1 or DATAD$). 

Beyond this, WREN acts in a
similar way to WCOPY, listing each file that is being renamed to the
specified channel (default #0). However, instead of moving the old file,
the header is merely amended to reflect the new name.

**Examples**

::

    WREN flp1_QUILL_ TO flp1_
    
could be used to take all of the Quill files out of a sub-directory
into the main directory, by deleting the sub-directory prefix. 

::

    DEST_USE flp1_QUILL_ 
    DATA_USE flp1_ 
    WREN
    
would have the opposite effect.

**NOTE**

Any attempt to rename a file across to a different device will report
the error 'Bad Name'.

**CROSS-REFERENCE**

:ref:`rename` renames one file at a time.
:ref:`wcopy` contains details of wildcards.

--------------


..  _wset:

WSET
====

+----------+-------------------------------------------------------------------+
| Syntax   |  WSET type [,mode]                                                |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

This command resets the windows #0, #1, and #2 to a pre-defined size
and position. There are a set of eight definitions built into the
Emulator, which can be chosen by setting type to a value in the range
0...7. 

::

    WSET -1 
    
will reset the three windows to the size and positions
specified with the WSET\_DEF command. If the optional parameter mode is
supplied, this will alter the display mode to that specified, otherwise,
the screen mode remains unchanged.

**CROSS-REFERENCE**

:ref:`wmon` and :ref:`wtv` are
similar commands under Toolkit II. Normally, you would use
:ref:`mode` to alter the screen mode only. See also
:ref:`wset-def`.

--------------


..  _wset-def:

WSET\_DEF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  WSET\_DEF x0,y0,a0,b0, x1,y1,a1,b1, x2,y2,a2,b2                  |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

The command WSET\_DEF allows you to set up a user-defined size and
position for each of the three default windows, #0, #1 and #2. Each set
of four parameters is used to specify the size x,y
and position (a,b) of each window.

**Example**

::

    WSET_DEF 448,40,32,216, 448,200,32,16, 448,200,32,16 
    WSET -1,8
    
is the same as WTV 8

**CROSS-REFERENCE**

See :ref:`wset`.

--------------


..  _wstat:

WSTAT
=====

+----------+------------------------------------------------------------------+
| Syntax   | WSTAT [#ch,] [wild] or                                           |
+----------+------------------------------------------------------------------+
| Syntax   | WSTAT \\file [,wild] (Toolkit II only)                           |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THORs                                                |
+----------+------------------------------------------------------------------+

The command WSTAT works in a very similar way to WDIR except that
alongside the filenames, it lists the length of each file and the update
time.

**Example**

::

    WSTAT QUILL_
    
will produce a list of all of the files on the data device which are in
the QUILL sub-directory.

**NOTE**

In current versions of Toolkit II (up to v2.85 at least), WSTAT cannot
cope with the DEV device where this is pointing to a sub-directory.

**CROSS-REFERENCE**

:ref:`dir` will produce a list of all of the files on
a given medium. :ref:`wcopy` contains details of how
wildcards operate.

--------------


..  _wtv:

WTV
===

+----------+------------------------------------------------------------------+
| Syntax   | WTV [mode] or                                                    |
+----------+------------------------------------------------------------------+
| Syntax   | WTV [mode] [, xoff] [, yoff](SMS Only)                           |
+----------+------------------------------------------------------------------+
| Location | THOR 8 (v4.20+), THOR XVI, Toolkit II                            |
+----------+------------------------------------------------------------------+

When the QL is first started up in TV mode, the windows #0, #1 and #2
are opened in the following sizes and positions, without any borders:-

- #0 is 448x40a32x216 
- #1 is 448x200a32x16 
- #2 is 448x200a32x16 

Whilst testing
programs, it is all too easy for these three windows to be redefined
(especially #1 which is the default window). The command WTV allows you
to easily set those three windows to their default size and position as
well as taking an additional parameter for setting the mode in the same
way as the MODE command (default MODE 4). 

Any border attached to each
window is switched off, except under SMS (see below). Also, if the
second variant is used, if an outline has previously been defined (for
example with OUTLN), then the contents of the three windows will be
retained and moved to the new position - this is equivalent to following
the WTV command with an OUTLN command with the details of the new position and
size.

**NOTE 1**

WTV does not reset the PAPER and INK colours of the three windows.

**NOTE 2**

On some versions of Minerva (pre v1.78) and Toolkit II, if you do not
specify the mode, this command will have no effect.

**NOTE 3**

On SMS prior to v2.53 WTV would create an OUTLN if one does not exist.

**SMS NOTE**

The SMS version of the command adds a border to #0, #1 and #2 (as with
WMON) and also allows you to reposition the main windows (see WMON).
v2.67+ also fixed several problems with this command.

**CROSS-REFERENCE**

Also see :ref:`wmon`.

--------------


..  _w-crunch:

W\_CRUNCH
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  W\_CRUNCH ( #channel, colour )                                   |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This toolkit is designed (like the SuperWindow Toolkit) to provide you
with facilities for storing parts of the QL's screen in memory so that
you can recall them at a later date, thus providing the QL with
non-destructible windows inside programs. 

Whilst the Pointer Environment
provides programs with non- destructible windows, this only ensures that
when a program ends, the area of the screen which was occupied by that
program is restored so that it looks the same as when the program
started. Also, when you switch to another program, the whole of that
program's display area appears on screen, overwriting anything else (see
OUTLN) - the display covered by the newly activated program is then
stored in memory to be recalled at a later date. However, unless you use
specific functions (for example those supplied as part of the Qptr
Toolkit, or supplied with this toolkit), if a program OPENs one window
over the top of another window owned by that program, when that second
window is CLOSEd, the area underneath is not restored (see the example
below). 

This function allows you to store the area under a specified
window channel in memory in a compressed form. Ideally the window should
be a number of pixels wide which is divisible by eight and also have its
left boundary (after taking any BORDER into account) on a pixel which is
divisible by eight (if not then this function will store a slightly
larger area of the screen than that covered by the window). This
function compresses the screen by reference to the colour parameter -
this should either be 4 to store the green pixels or 2 to store the red
pixels. 

The function is therefore only really of use in MODE 4 since
other MODEs may use a lot more colours. Other pixels are ignored and
will therefore not be copied back onto the screen with W\_SHOW. Since
most screens have text in one colour on top of another background, this
function is ideal for those circumstances. This function is also very
useful for storing Icons and other symbols, since the image, once stored
with this function, can be copied back to the screen with W\_SHOW again
and again. The value returned by W\_CRUNCH is the address of the area in
memory where the copy of the screen is stored - you will need to keep
this address for use by the other functions in the toolkit.

**Example**

Try the short program which follows and note how when
you press <ENTER> to close the temporary window, the display does not
alter:: 

    100 OPEN #2,con_448x200a32x16: PAPER #2,0: CLS #2: INK #2,2 
    110 FOR i=1 TO 15 
    120   PRINT #2, 'This is window #2 - Line number '; i 
    130 END FOR i 
    140 INK #2,4: PRINT #2,'PRESS A KEY TO OPEN TEMPORARY WINDOW' 
    150 PAUSE
    160 OPEN #3,con_230x40a80x100: PAPER #3,2: CLS #3 
    170 INK #3,7: PRINT #3, 'This is a temporary window' 
    180 INPUT #3, 'Press <ENTER> to close this window ';a$ 
    190 CLOSE #3

Instead, you can use W\_CRUNCH to store #2 and then restore it once #3
has been closed - add the following lines:: 

    155 base=W_CRUNCH(#2,2) 
    200 CLS #2 
    210 W_SHOW #2,base

Note how only the characters which were printed in Red Ink were stored.
You could have just stored the area under the temporary
window by taking the original example and adding the lines::

    160 OPEN #3,con_230x40a80x100: PAPER #3,2 
    165 base = W_CRUNCH(#3,2): CLS #3 
    185 PAPER #3,0: CLS #3 
    187 W_SHOW #3,base

Note the need to store the contents of the window with W\_CRUNCH before
it is cleared with CLS !!.

**NOTE 1**

This function will only work on screen resolutions of 512x256 pixels.

**NOTE 2**

The memory used by the function will be reclaimed by CLCHP, or LOAD,
LRUN or NEW. You can also use DISCARD address or RECHP address+4
to remove it specifically (although note the different address
requirement for RECHP).

**CROSS-REFERENCE**

See :ref:`scr-refresh` and
:ref:`scr-store`. See also
:ref:`w-store`,
:ref:`w-show`.
:ref:`w-swap`,
:ref:`set-red` and
:ref:`set-green` allow you to recolour windows.

--------------


..  _w-show:

W\_SHOW
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  W\_SHOW #channel, address                                        |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This command takes an image stored at the specified address
using either the W\_CRUNCH or W\_STORE functions and then copies it
across to the specified window channel.

**NOTE 1**

This command will only work on screen resolutions of 512x256 pixels.

**NOTE 2**

The memory used by W\_CRUNCH or W\_STORE is not released, so that you
can re-display the screen again in the future.

**NOTE 3**

An out of range error will be reported if the stored image will not fit
within the specified window.

**CROSS-REFERENCE**

See :ref:`scr-refresh` and
:ref:`scr-store`. See also
:ref:`w-store`,
:ref:`w-crunch`.
:ref:`w-swop`,
:ref:`set-red` and
:ref:`set-green` allow you to recolour windows.

--------------


..  _w-store:

W\_STORE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  W\_STORE ( #channel )                                            |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This function is very similar to W\_CRUNCH except that it stores the
whole of the contents of the specified window (not in compressed form).
It also stores all of the colours, not just green or red.

**NOTE**

Refer to the notes for W\_CRUNCH.

**CROSS-REFERENCE**

See :ref:`w-crunch`!

--------------


..  _w-swap:

W\_SWAP
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  W\_SWAP #channel                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This command looks at the specified window channel and swaps over red
and green bits on the display, effectively changing the colours on
screen.

**NOTE 1**

This command will only work on screen resolutions of 512x256 pixels.

**NOTE 2**

This command should not really be used in MODE 8.

**CROSS-REFERENCE**

:ref:`w-swop` is exactly the same.
:ref:`recol`, :ref:`set-red`
and :ref:`set-green` also allow you to recolour
a window. Refer to the QL display Appendix.

--------------


..  _w-swop:

W\_SWOP
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  W\_SWOP #channel                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This command is exactly the same as :ref:`w-swap`.

