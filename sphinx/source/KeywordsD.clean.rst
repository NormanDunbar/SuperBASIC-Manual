==========
Keywords D
==========

TODO
====

- Can we do something about the SYNTAX table cell contents? We should have it split onto new lines for each "or".
- :ref:`devtype` references something called QRD to rename a device. It is not found.
- :ref:`dbl` references ESC whihc is not found.
- DISP_COLOUR is referenced from KeywordsI (Ink) but is not in this file.



..  _data:

DATA
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DATA expression :sup:`\*`\ [,expression]\ :sup:`\*`              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The QL allows a SuperBASIC program to store a set of data in the
program itself, which can then be assigned to a given variable by the
READ command. The DATA statement marks these areas for use by READ. The
information which can be stored at a DATA statement is basically
anything which can be stored in a variable, including strings,
variables, constants and expressions. 

Expressions will be calculated at
the time that the item in question is READ. Whilst a program is running,
unless a READ command is found, DATA statements are ignored.


**Example**

::

    1000 DATA "QL User",100,x*1000+10


**NOTE 1**

On Pre MG ROMs, if any values in a DATA statement start with a bracket,
then the other items on the line may be ignored. If you must specify
items starting with brackets, use for example: DATA 0+(...
This is fixed by MG ROMs, Minerva and SMS.


**NOTE 2**

Unless you have a Minerva ROM (v1.77 or later) or SMS, when you enter
the DATA statement, you will always need to type a space after the word
DATA as the parser will not automatically insert one. On later
implementations a space is automatically inserted where the first DATA
expression is a string, eg. DATA'Hello'.


**NOTE 3**

Entering a DATA statement as a direct command from #0 has no effect.
Under SMS an error is reported 'DATA in command line has no meaning'.


**NOTE 4**

Due to the way in which the interpreter works, it is always more
efficient to place DATA statements at the start of a program (the search
function always starts at the first line of the program).


**NOTE 5**

Various SuperBASIC compilers (such as Turbo) do not support expressions
in DATA statements.


**NOTE 6**

There appears to be no real check on the parameters given for DATA, so
the following line can be entered, but will in fact cause an error when
you try to READ it::

    10 DATA 1000,PRINT,10

SMS's improved interpreter does do more checks than earlier
implementations and will prevent you from entering the line::

    10 DATA 1,1,2a,3 

which other implementations allow (but give an error when they try to
READ the line).


**NOTE 7**

SMS may complain if you create numerous DATA statements inside a DEFine
PROCedure or DEFine FuNction struture.


**CROSS-REFERENCE**

:ref:`restore` allows you to set the current
:ref:`data` pointer. :ref:`read`
will assign the value at the current :ref:`data`
pointer to the given variable. :ref:`eof` will return
the value one if there are no more :ref:`data`
statements in the current program.

--------------


..  _datad-dlr:

DATAD$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DATAD$                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function always contains the current default data device, which is
an unofficial QDOS standard and supported by all Toolkit II extensions,
original SuperBASIC commands and most good software. 

The default device
means that if no other device is stated, if appropriate, this device
will be used. The default data device will also be consulted if a device
name is supplied but the given file cannot be found on that device. For
example, assuming that DATAD$='flp2\_', if you enter VIEW
ram1\_example\_txt and the file example\_txt is not present on ram1\_,
the command will then try flp2\_ram1\_example\_txt. 

This idea can be
extended to use prefixes as sub-directories. Sub-directories are
separated by underscores, DATAD$ always ends with an underscore.


**Example**

TK2DIR reads all files from the current default data device via a pipe,
strips off any network sub-directory prefix and then writes the
remainder of the filenames into the string array passed by parameter.

::

    100 DEFine PROCedure TK2DIR (Verz$) 
    110   LOCal e,n,sd$,sd,us 
    120   sd$=DATAD$: us="_" INSTR sd$ 
    130   IF us=3 AND LEN(sd$)>3 and sd$(1)="n" THEN 
    140     IF sd$(2) INSTR "12345678":sd$=sd$(4 TO):us="_" INSTR sd$ 
    160   END IF 
    170   OPEN#4,pipe_10000: STAT#4: WDIR#4 
    180   e=FILE_OPEN(#3,pipe_,CHANID(#4)): CLOSE#4 
    200   INPUT#3,Verz$(0) 
    210   FOR n=1 TO DIMN(Verz$) 
    220     IF EOF(#3) THEN EXIT n 
    230     INPUT#3,Verz$(n) 
    240     Verz$(n)=Verz$(n)(us+1 TO) 
    250   END FOR n 
    260   CLOSE#3 
    270 END DEFine TK2DIR

    DIM file$(20,30) 
    TK2DIR file$ 
    CLS: PRINT file$

Here only the first 20 files will be read into file$. NB. This would
require substantial amendment to make it search sub-directories also.


**CROSS-REFERENCE**

:ref:`data-use` defines the default device;
:ref:`dup`, :ref:`ddown` and
:ref:`dnext` allow you to move around the
sub-directory tree. :ref:`progd-dlr` returns the
default program device. :ref:`dlist` prints all
default devices.

--------------


..  _datareg:

DATAREG
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DATAREG [number]number=0...3                                     |
+----------+-------------------------------------------------------------------+
| Location |  TRAPS (DIY Toolkit Vol T)                                        |
+----------+-------------------------------------------------------------------+

This function returns the value of the Machine code data register
number (default 0) following the completion of a MTRAP, QTRAP or BTRAP
command. 

Because the default data register number is 0: PRINT DATAREG 
will be 0 if no error occured during the TRAP call or else the relevant
error code. 

Number will let you read the value of the relevant data register D0, D1, D2 or D3.


**CROSS-REFERENCE**

:ref:`addreg` allows you to read machine code
address registers - see this for an example of
:ref:`datareg`. See
:ref:`mtrap`, :ref:`qtrap` and
:ref:`btrap`.

--------------


..  _dataspace:

DATASPACE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DATASPACE (file$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function returns the amount of dataspace which has been set aside
for the given file$. It is therefore similar to FDAT and FILE\_DAT.

Default devices are not supported, however errors are not reported. 
The following error values may also be returned by the function: 

- -2: The file is not executable
- -3 or -6: Insufficient memory to open file 
- -7: File does not exist 
- -9: Device or file is being written to by something else. 
- -12: The device is valid, but the filename is not 
- -16: Bad or changed medium error


**Example**

::

    PRINT DATASPACE('win1_start_QD_exe')


**CROSS-REFERENCE**

:ref:`data-area` allows you to set the
dataspace for a compiled program. See also
:ref:`fdat`.

--------------


..  _data-area:

DATA\_AREA
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DATA\_AREA size size=0...850                                     |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command is only used by the Turbo compiler and should be located
at the start of your program before any active program lines. 

The
command specifies how much dataspace (size kilobytes) should be
specified for the compiled program. 

This dataspace is used by a task for
stack space and a temporary store whilst it is running.


**Example**

::

    10 DATA_AREA 32


**NOTE**

This setting will override a previous TURBO\_objdat directive in the
same program. It will also be overridden by a later TURBO\_objdat
directive in the same program.


**CROSS-REFERENCE**

:ref:`dataspace` allows you to find out how much
dataspace has been set aside for a program. See
:ref:`compiled` and
:ref:`turbo-objfil` for other compiler
directives. :ref:`turbo-objdat` is exactly
the same.

--------------


..  _data-use:

DATA\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DATA\_USE default\_device                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

If you have Toolkit II installed, all of the additional extensions
connected with file or device handling and all original SuperBASIC
commands use the default device if no other device name is specified. 

On a THOR XVI, some of the commands support default devices without Toolkit
II. 

The effect of the default devices would make LOAD proggy\_bas
work as LOAD flp1\_proggy\_bas (assuming that flp1\_ is the default
data device). The actual effect depends on the command being executed,
but generally the file will be looked for in three steps:

- Does the given file include a valid device? proggy\_bas does not, 
  ram1\_proggy\_bas does (ram1\_). If not, the parameter is assumed to be
  a filename and Toolkit II looks for a device on which it can find it; so:
- Add the default data device to the filename. If that does not work,
  then: 
- Add the default program device (PROGD$) and try again.

The
default program device is defined by PROG\_USE, DATA\_USE 
defines the default data device. See PROG\_USE as to the difference
between the two defaults. The last two steps add the default devices to
the filename. These defaults can be interpreted as sub-directories.

Here, a sub-directory means that where a prefix is separated by
underscores, this means that the file concerned is held in the
sub-directory specified by that prefix. Thus, win1\_QUILL\_readme\_doc
could be readme\_doc on a hard disk in the sub-directory QUILL or doc in
the sub-subdirectory readme of QUILL. 

Sub-directories can be nested but
the complete filename, including prefix must not be longer than 41
characters (note that if you are using a network device, for example
n1\_win1\_proggy\_bas, the maximum permitted filename length is reduced
to 39 in current versions of the QL device drivers).


**Examples**

::

    DATA_USE flp1_QUILL (or flp1_QUILL_) 
    DATA_USE MDV2_ 
    DATA_USE win1_Psion_ARCHIVE 
    DATA_USE n2_ram1_ 
    DATA_USE mdv3_games_arcade_invaders_


**NOTE 1**

If there is no underscore at the end of DATA\_USE's parameter, it will
be added automatically.


**NOTE 2**

A few programs do work with these sub-directories (if Toolkit II is
present), but most do not. To make any program work with them, you can
fool them so that they believe that for instance FLP1\_games\_BOOT is
FLP1\_BOOT or BOOT (default device FLP1\_games): See the PTH\_... and
DEV\_... commands.


**NOTE 3**

Toolkit II sub-directories should not be mixed up with wild cards.
DATA\_USE flp1\_\_bas makes WDIR list all BASIC programs on floppy 1,
but after PROG\_USE flp1\_\_bas, SAVE test will not save the current
program as flp1\_test\_bas but as flp1\_\_bas\_test.


**NOTE 4**

The default device is the current sub-directory on level-2 drivers.


**NOTE 5**

If you wish to turn off this feature, you can assign a null string ("")
to DATA\_USE.


**NOTE 6**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to assign a longer string will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

:ref:`datad-dlr` contains the default data device,
:ref:`dlist` lists all default devices.
:ref:`ddown`, :ref:`dup` and
:ref:`dnext` allow you to skip from sub-directory to
sub-directory, climb up the tree and much more.
:ref:`prog-use` changes the default program
device, and :ref:`spl-use`
/:ref:`dest-use` the default destination device.
See also :ref:`dev-use` and
:ref:`pth-add` for path search.

--------------


..  _date:

DATE
====

+----------+--------------------------------------------------------------------+
| Syntax   || DATE or                                                           |
|          || DATE (year,month,day,hour,minute,second)(Minerva & NewDate)  or   |
|          || DATE (year,month,day,hour,minute [,second])(SMS v2.57+)           |
+----------+--------------------------------------------------------------------+
| Location || QL ROM                                                            |
+----------+--------------------------------------------------------------------+


The function DATE returns the current date and time as the number of
seconds since midnight on 1st January 1961. For example, PRINT
DATE$(DATE) is exactly the same as PRINT DATE$. The NewDate version of
this command is exactly the same as Minerva's implementation.


**NOTE**

Due to the way in which the system clock is implemented on the QL (it is
stored as a 32-bit unsigned number), early versions of this function
have problems with dates after 3.14:07 on 19th January 2029 (this would
result in a number of seconds which needs to be stored in all 32 bits).

Although the SDATE and DATE$ functions treat the number correctly, the
DATE function ignores the most significant bit, meaning that it returns the
wrong value for dates later than this. 

The NewDate version of this
function, as well as Minerva ROMs and under SMS, DATE treats the figure
as a 32-bit signed number. Although this allows the line PRINT
DATE$(DATE) to work correctly for all dates between 0.0:00 on 1st Jan
1961 and 6.28:15 on 6th Feb 2097, note that any dates after 3.14:07 on
19th January 2029 are returned as negative numbers, with earlier dates
giving the largest negative number.


**MINERVA NOTE**

DATE can accept the same six parameters accepted by SDATE. This enables
you (for instance) to find out the day on a given date without having to
alter the QL clock: PRINT DAY$(DATE(1968,6,25,1,1,0))

This does also enable you to easily set the update date on a given file
without altering the QL clock::

    SET_FUPDT \flp2_test_file, DATE(1990,11,1,0,0,0)


**SMS NOTE**

As from v2.57, DATE has been brought up to the same standard as on
Minerva. However, the seconds do not have to be specified and will
default to zero if omitted.


**CROSS-REFERENCE**

:ref:`sdate` will alter the QL clock.
:ref:`day-dlr` returns the day on the given date,
:ref:`date-dlr` will return the current date.
:ref:`t-on` and
:ref:`t-start` can be used for accurate
stop-watches for timing programs.

--------------


..  _date-dlr:

DATE$
=====

+----------+--------------------------------------------------------------------+
| Syntax   || DATE$ [(date)] or                                                 |
|          || DATE$ (year,month,day,hour,minute [,second])(SMS v2.57+ only)     |
+----------+--------------------------------------------------------------------+
| Location || QL ROM                                                            |
+----------+--------------------------------------------------------------------+

DATE$ holds the current system date and time as a string in the
following format: yyyy mmm dd hh:mm:ss. 

::

    1991 May 06 18:18:44 (example)
    |  | | | || || || ||
    |  | | | || || || ++---- 19 TO 21 (seconds)
    |  | | | || || ++------- 16 TO 17 (minutes)
    |  | | | || ++---------- 13 TO 14 (hour, 24h)
    |  | | | ++------------- 10 TO 12 (day)
    |  | +-+----------------- 6 TO 8 (month as string)
    +--+--------------------- 1 TO 4 (year) 


If a parameter is used then DATE$ should return the date and time the given number of
seconds after 1/1/1961, DATE$(DATE) is identical to DATE$ for any date
before 3.14:07 on 19th Jan 2029 (see ADATE). However, for times after
this date, the number of seconds since 1/1/1961 is represented by a
negative number, calculated by number of seconds - 2147483648. 

This means that to calculate a specified date after 3.14:06 on 19th Jan 2029,
the following short function is required (for non-Minerva ROMs and
non-SMS machines only):

::

    100 DEFine FuNction DATE20$(seconds) 
    110   offset='2147483648' 
    120   RETurn DATE$(seconds-offset) 
    130 END DEFine

This function is not needed on Minerva ROMs, with the NewDate version
of DATE or under SMS - see DATE for a full explanation.


**Example 1**

It may be useful to read the different parts of the date from DATE$ and
reformat them for use in letters. 

::

    100 D$=DATE$ 
    110 year=D$(1 TO 4): day=D$(10 TO 12): D$=D$(6 TO 8) 
    120 month=(D$ INSTR "..JanFebMarAprMayJunJulAugSepOctNovDec")/3 
    130 DIM month$(12,9): RESTORE 150 
    140 FOR m=1 TO 12: READ month$(m) 
    150 DATA "January","February","March","April","May","June","July" 
    160 DATA "August","September","October","November","December" 
    170 ALTKEY "d", month$(month) & " " & day & ", " & year


**Example 2**

How to find the number of days between two dates::

    100 date1=DATE(2032,3,30,10,0,0)
    110 date2=DATE(2000,3,30,10,0,0)
    120 PRINT DAYS_DIFF(date2,date1)
    130 :
    140 DEFine FuNction DAYS_DIFF(dy1,dy2)
    150 LOCal offset,base_date,diff
    160 offset='2147483648'
    170 base_date=DATE(2029,1,19,3,14,7)
    180 IF (date1>=0 AND date2>=0) OR (date1<0 AND date2<0)
    190 IF date1>=date2:diff=date1-date2:ELSE diff=date2-date1
    240 ELSE
    250 IF date1<0
    260 diff=(base_date-date2)+(date1+offset
    270 ELSE
    280 diff=(base_date-date1)+(date2+offset)
    290 END IF
    300 END IF
    310 seconds_per_day=24*60*60
    320 RETurn INT(diff/seconds_per_day)
    330 END DEFine 

**NOTE 1**

Parts of string functions cannot be obtained by slicing them directly.
Expressions such as DATE$(DATE)(1 TO 4) are only valid on Minerva ROMs
or under SMS. On other ROMs, the value of the function has to be copied
to a variable before being sliced (as demonstrated in example 1).


**NOTE 2**

The QL's system clock is limited in the range of dates it can cover -
see ADATE.


**MINERVA NOTE**

Although on Minerva (v1.77 and later), DATE$ can now be directly sliced
to extract the year for instance. It is however, necessary to tell the
operating system that you are not actually providing a parameter to be
converted into a date. This is achieved by using the following format to
slice DATE$: DATE$ [([seconds]) [([start] TO [end])]] The following are
therefore all valid on Minerva::

    PRINT DATE$ 
    PRINT DATE$(DATE+86400)
    TIMER$ = DATE$()(13 TO ) 
    YEAR$ = (DATE$)(1 TO 4) 
    YEAR$ = DATE$(1E9)( TO 4)

Only the first two examples will work on other ROMs.


**SMS NOTE**

DATE$ works mainly as per Minerva, however from v2.57+, you can also
supply five or six parameters to DATE$ in common with DATE and SDATE.


**CROSS-REFERENCE**

Use :ref:`sdate` and
:ref:`adate` to set and alter the system time and
date. :ref:`date` holds the current date as a
floating point number, :ref:`day-dlr` holds the weekday
as a short string.

--------------


..  _day-dlr:

DAY$
====

+----------+--------------------------------------------------------------------+
| Syntax   || DAY$ [(date)] or                                                  |
|          || DAY$ (year,month,day,hour,minute [,second]) (SMS v2.57+ only)     |
+----------+--------------------------------------------------------------------+
| Location || QL ROM                                                            |
+----------+--------------------------------------------------------------------+

DAY$ holds the current day as a three character string: 

+-----+------------+
| Sun | Sunday     |
+-----+------------+
| Mon | Monday     |
+-----+------------+
| Tue | Tuesday    |
+-----+------------+
| Wed | Wednesday  |
+-----+------------+
| Thu | Thursday   |
+-----+------------+
| Fri | Friday     |
| Sat | Saturday   |
+-----+------------+

If you provide a parameter, DAY$ will return the day of the given date
(which is stated in seconds after 1/1/1961). DAY$(DATE) = DAY$.


**NOTE**

As with DATE$, you cannot slice DAY$ unless you have a Minerva ROM
(version 1.77 or later) or SMS - see DATE$ for further details.


**SMS NOTE**

In common with DATE$, from v2.57, DAY$ will now accept five or six
parameters as with SDATE and DATE. You can also slice DAY$ (like on Minerva) - see DATE$.


**CROSS-REFERENCE**

:ref:`tra` and
:ref:`set-language` allow you to re-define
the abbreviations used for the different days.
:ref:`date` holds the current system date (in seconds
after 1/1/1961) as a floating point number,
:ref:`date-dlr` as a string.

--------------


..  _dbl:

DBL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DBL                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to switch on emphasised mode on an EPSON compatible printer: DBL=CHR$(27)&"E".


**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`enl`,
:ref:`pro`, :ref:`si`,
:ref:`nrm`, :ref:`unl`,
:ref:`alt`, :ref:`esc`,
:ref:`ff`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _ddown:

DDOWN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DDOWN subdirectory                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command adds the specified subdirectory to the default data device
as a suffix. 

If the default program device is the same as the default
data device, then this will also be altered by DDOWN. 

If the default
destination device is a directory device (ie. if it ends with an
underscore), DDOWN also alters this (whether or not it points to another
drive). 

::

    win1_
    win1_C_
    win1_C_include_
    win1_C_objects_
    win1_BASIC_
    win1_QUILL_
    win1_QUILL_letters_
    win1_QUILL_translations
    win1_secret_


The above could be a directory tree on a hard disk. 

DATA\_USE win1\_ defines win1\_ as the default directory device, so WDIR will list
all of the files on win1\_. 

DDOWN C will move into the C sub-directory, ie. DATAD$ is now win1\_C\_. 

DDOWN include will make WDIR list all of
the files on the hard disk which are prefixed by C\_include\_ (eg.
win1\_C\_include\_math\_h).


**NOTE 1**

DDOWN does not check if there are any files with the given prefix which
exist.


**NOTE 2**

DDOWN breaks with error -17 (error in expression) if the parameter is a
resident keyword. So append an underscore to the directory name, eg.
DDOWN NEW\_, or specify the parameter between quote marks (eg. DDOWN
'NEW').


**NOTE 3**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to extend them beyond this will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

:ref:`dup` moves up the tree,
:ref:`dnext` skips from branch to branch.
:ref:`datad-dlr` and :ref:`dlist`
can be used to find out about the current sub-directory and default
devices respectively.

--------------


..  _deallocate:

DEALLOCATE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEALLOCATE address                                               |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This procedure is very similar to RECHP in that it cancels a
reservation of common heap memory. However, the specified address must
be an area of memory which had previously been set aside with
ALLOCATION.


**WARNING**

Prior to v3d27 this command could crash the system if the specified
address had already been deallocated, was an odd address, or had not
been set aside with ALLOCATION.


**CROSS-REFERENCE**

See :ref:`allocation` and
:ref:`rechp`.

--------------


..  _debug:

DEBUG
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DEBUG                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit (v3.20+)                                           |
+----------+-------------------------------------------------------------------+

This is a compiler directive intended to precede a DEFine PROCedure or
DEFine FuNction routine which is used for debugging a program. The
routine can be included or excluded from the program during compilation
using the DEBUG\_LEVEL directive. Current versions of the TURBO parser
do not support this.


**CROSS-REFERENCE**

See :ref:`debug-level`.

--------------


..  _debug-level:

DEBUG\_LEVEL
============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEBUG\_LEVEL level                                               |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit (v3.20+)                                           |
+----------+-------------------------------------------------------------------+

It is currently uncertain how this directive is used within TURBO
compiled programs.


**CROSS-REFERENCE**

See :ref:`debug` and the various TURBO_XXX commands starting with :ref:`turbo-diags`.

--------------


..  _default:

DEFAULT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT (expression, default\_value)                             |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function DEFAULT usually simply returns the result of the given
expression, unless the expression contains undefined variables or does
not produce a floating point number. In either of these latter cases
DEFAULT will return the given default\_value.


**Example**

WRITE simply PRINTs a text to a given channel. If the channel ch was not
a valid number for any reason then #1 is used::

    100 DEFine PROCedure WRITE (ch, text$) 
    110 ch = DEFAULT(ch, 1) 
    120 PRINT#ch,text$ 
    130 END DEFine WRITE

**CROSS-REFERECE**

:ref:`type`. :ref:`default-dlr`
and :ref:`default-pct` work exactly like
:ref:`default` for string and integer expressions.

--------------


..  _default-pct:

DEFAULT%
========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT% (expression%, default\_value%)                          |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

 See :ref:`default` !

--------------


..  _default-dlr:

DEFAULT$
========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT$ (expression$, default\_value$)                          |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

 See :ref:`default` !

--------------


..  _default-device:

DEFAULT\_DEVICE
===============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT\_DEVICE devicename$                                      |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This command can be used in a similar way to PROG\_USE and DATA\_USE. 
It sets the default device (up to 31 characters), for the following
Turbo Toolkit commands: 

- CHARGE, 
- EXECUTE, 
- EXECUTE\_A, 
- EXECUTE\_W
- LINK\_LOAD, 
- LINK\_LOAD\_A, 
- LINK\_LOAD\_W.

It has no effect on any other commands.


**Example**

For a series of linked programs, you may want to use the following in a
boot file::

    DEFAULT_DEVICE win1_PROGS_ 

Each program could call another by using::

    EXECUTE_W program2_task


**NOTE 1**

Prior to v3d27, this command only supported 5 characters (although prior
to v2.00 no error was reported if more than 5 characters were used - the
command simply ignored the additional characters).


**NOTE 2**

As from v1.26, you do not need to pass the device name as a string, for
example::

    DEFAULT_DEVICE flp1_


**CROSS-REFERENCE**

:ref:`prog-use`.

--------------


..  _default-scr:

DEFAULT\_SCR
============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT\_SCR                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Fn (v1.02 or later)                                              |
+----------+-------------------------------------------------------------------+

This function is really only useful on a Minerva ROM (although it will
work quite happily on any other ROM). It is sometimes useful when
writing programs which are to run in Minerva's dual screen mode to
discover which is the default screen. This is made necessary because all
new windows which are opened, and all MODE commands operate on the
current default screen. 

This therefore means that if a program is badly
written, it is possible that whilst the program is running the default
screen is switched, giving the result that some of its windows are
opened on scr0 and some on scr1. PRINT DEFAULT\_SCR
will return 0 or 1 depending whether the default screen is scr0 or
scr1. If Minerva is not in dual screen mode, or if Minerva is not
present, 0 will be returned.


**Example**

A program to change the MODE of the current program safely (ie. it will
only alter the MODE of the screen in which the program is running)::


    100 This_JOB=DEFAULT_SCR 
    110 SET_MODE 8 
    120 : 
    200 DEFine PROCedure SET_MODE (alp) 
    210   IF RMODE(This_JOB)=alp:RETurn 
    220   IF This_JOB=DEFAULT_SCR:MODE alp:RETurn 
    230   MODE 64+32,-1:MODE alp:MODE 64+32,-1 
    240 END DEFine


**CROSS-REFERENCE**

:ref:`mode` alters the mode of the current screen and
job and can be used to alter the current default screen,
:ref:`rmode` returns the mode of the given screen.

--------------


..  _define--xxx:

DEFine xxx
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFine ....                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This keyword forms part of the structures: 

- DEFine PROCedure, 
- DEFine FuNction,
- END DEFine. 

As such, it cannot be used on its own within a
program - this will cause a 'bad line' error, except under SMS where it
causes an error 'Incorrect Procedure or Function Definition'.


**CROSS-REFERENCE**

Please refer to the individual structure descriptions for more details.

--------------


..  _define--function:

DEFine FuNction
===============

+----------+--------------------------------------------------------------------------------+
| Syntax   | DEFine FuNction name[$ \| %] [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] |
+----------+--------------------------------------------------------------------------------+
| Location |QL ROM                                                                          |
+----------+--------------------------------------------------------------------------------+


This command marks the beginning of the SuperBASIC structure which is
used to surround lines of SuperBASIC code which forms an equivalent to a
machine code function, which can be called from within SuperBASIC and
will return a value dependent upon the code contained within the
structure. The syntax of the SuperBASIC structure can take two forms:

--------------

DEFine FuNction name[$ \| %] [(item\ :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*`\ )]: statement
:sup:`\*`\ [:statement]\ :sup:`\*`:RETurn value

or 

DEFine FuNction name[$ \| %] [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] :sup:`\*`\ [LOCal var
:sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*`]\ :sup:`\*` :sup:`\*`\ [statements]\ :sup:`\*` RETurn value END DEFine [name] 

--------------

When the specified function name is
called, the interpreter will search the SuperBASIC program for the
related DEFine FuNction statement. 

If a related DEFine FuNction cannot be found, then the
interpreter will search for a machine code function of that name. 

If the definition of name cannot be found, then the error 'Not Found' will be
reported if name was defined in the past, but the definition line has
since been deleted. 

If name has never been defined in the current SuperBASIC program, then it will be treated as a normal variable and
relevant error messages reported. 

Under SMS in both instances the value
0 will be returned (name is treated as an undefined variable). 

The method of searching for a FuNction means that if a SuperBASIC FuNction
is defined with the same name as a machine code one, the machine code
one will no longer be available, and when the SuperBASIC FuNction is
removed (for example with NEW), that keyword will no longer have any
effect. If entered as a direct command, even the in-line structure will
not have any effect unless it is also called on the same line, as the
interpreter must jump to the relevant DEFine FuNction statement when the function is called. 

If a DEFine FuNction statement
appears in a program, if the code is not called, program flow will
continue from the statement following the next END DEFine - it is
however good practice to keep all definition structures towards the end
of a program, and not to place the structure blocks in the middle of
program code, as this makes it very difficult to follow the flow of
programs. 

It is also good programming practice to make FuNctions
self-contained and not to jump out of them using GO TOs or GO SUBs (they
can of course call other FuNctions and PROCedures). 

To call the DEFine FuNction, you merely need to include its name in an expression. If
however any parameters are listed in the definition, you will need to
pass the same number of parameters in brackets after the name of the
FuNction, separated by any valid SuperBASIC separator {ie. comma (,),
semicolon (;), backslash (\\), exclamation mark (!) or TO }. You can
also place a hash (#) before the parameters if you so wish to indicate
that it is a channel number. 

If not enough parameters are supplied, the
program will report 'Error in Expression' when the missing parameter is
used, except under SMS where the missing parameters are treated as unset
variables and will therefore have the value 0 (if a numeric variable) or
else contain an empty string (if a string variable). 

If however, too
many parameters are passed, the extra parameters are ignored. Parameters
are passed by reference which means that the list of items in the DEFine
FuNction statement are deemed LOCal to that definition - this means that
any previous values of the items are stored whilst the definition block
is active. What is more, the type of each item does not actually matter
- they assume the type of the passed parameter. For example, the
following short program will work without any problems::

    10 a$=QUERY$('What is your name') 
    20 DEFine FuNction QUERY$(x) 
    30   INPUT (x)!b$ 
    40   RETurn b$ 
    50 END DEFine

Note though that the name of the FuNction must end with the correct
variable type, ie. $ if a string is to be returned, or % if an integer
is to be returned (although see note 7 below). 

One of the results of
passing variables by reference is that if the item is altered within the
definition block, if a variable is passed as a parameter, the variable
itself will also be altered (although see note 4). This can be shown
with the following short program::

    100 x=10 
    110 y=Square(x) 
    120 PRINT x;'^2=';y 
    130 DEFine FuNction Square(za) 
    140   za=za*za 
    150   RETurn za 
    160 END DEFine

This can be avoided by either assigning the item to a temporary
variable and then using the temporary variable instead (see the example
below), or by passing the variable as an expression, by placing it
inside brackets; for example by replacing line 110 with the following::


    110 y=Square((x))

Having passed the necessary parameters to the Function, you can then use
each item inside the definition block as normal.


**Example**

A short program to calculate the length of the hypotenuse in a triangle,
given the length of its two other sides::

    100 MODE 4: WINDOW 448,200,32,16: SCALE 100,0,0: PAPER 0 105 CLS: INK 7 
    110 AT 2,25: UNDER 1: PRINT'Pythagoras calculator': UNDER 0 
    120 INPUT \\'Enter length of base of triangle:'!base 
    130 INPUT \\'Enter height of triangle:'!height
    140 hypotenuse=Pythag(base,height) 
    150 INK 4: LINE 50,20 TO 100,20 TO 100,70 TO 50,20 
    160 INK 7: AT 16,35-LEN(base): PRINT base 
    170 AT 11,46: PRINT height 
    180 AT 11,31-LEN(hypotenuse): PRINT hypotenuse 
    190 : 
    1000 DEFine FuNction Pythag(x,y) 
    1010   LOCal x1,y1 
    1020   x1=x*x:y1=y*y 
    1030   RETurn SQRT(x1+y1) 
    1040 END DEFine

See what happens if you replace lines 1000 to 1040 with the following::

    1000 DEFine FuNction Pythag(x,y) 
    1010   x=x*x:y=y*y 
    1020   RETurn SQRT(x*y) 
    1030 END DEFine


**NOTE 1**

A FuNction must return a value under all circumstances. If the END
DEFine is reached without a value having been returned then SuperBASIC
will report an 'error in expression' (-17), specifying the error as
having occured at the line containing the END DEFine. 

Under SMS the
error 'RETurn not in PROCedure or FuNction' will be reported instead.


**NOTE 2**

On pre JS ROMs, you could not define new FuNctions with names which had
already been used in the same program.


**NOTE 3**

On pre MG ROMs, any more than nine parameters may upset the program,
corrupting it by replacing names with PRINT towards the end of a
program. This can however be circumvented by increasing the size of the
Name Table by 8 bytes for each name (plus a little more for luck), using
the line::

    CALL PEEK_W(282)+36,N


**NOTE 4**

Although a sub-set of a simple string is an expression and therefore
will not be altered within a function, a sub-set of a DIMensioned string
is not treated as an expression and will therefore be altered!!


**NOTE 5**

Recursive FuNctions (ie. FuNctions which call themselves, or call
another PROCedure or FuNction which in turn calls the original FuNction)
are allowed (up to 32767 recursions under Minerva). They do however
gobble up memory at an amazing rate and can cause problems in compiled
SuperBASIC due to the fact that they need an ever-increasing amount of
stack space. They should be avoided wherever possible because they are
also very slow. 

On SMS, if you try to use recursive functions too much,
you may end up with the rather esoteric error 'program structures nested
too deeply, my brain hurts'! It is however, more likely that you will
end up with an 'Out of Error' memory and not be able to do anything else
(not even NEW).


**NOTE 6**

The LOCal statement (if used) must appear as the next statement
following DEFine FuNction, otherwise an error will be reported. Under
SMS if this is not the case, the error 'Misplaced LOCal' will be
reported.


**NOTE 7**

SMS and QLiberator do not seem to mind if you do not end the FuNction
name with a $ symbol when a string is to be returned and the FuNction
will work perfectly well in the compiled version of the program.
However, this should be avoided as the program will not work on other QL
ROMs and also cannot be compiled with TURBO. For example, take the
following program, which works under SMS or when QLiberated. 

For other
ROMs and TURBO, rename the function to GETSUBDIR$::

    100 file$='n1_win2_test_bas' 
    110 test$=GETSUBDIR(file$) 
    295 : 
    300 DEFine FuNction GETSUBDIR(s$) 
    310   IF s$(LEN(s$))<>'_':s$=s$&'_' 
    320   IF LEN(s$)=5:IF s$(4) INSTR '1234567890':RETurn '' 
    322   REPeat t_loop 
    325     root=1 
    330     FOR x=1 TO LEN(s$) 
    340       IF s$(x)='_' 
    350       IF x=3:IF s$(2) INSTR '1234567890':root=3 
    360       IF x=5:IF s$(4) INSTR '1234567890':root=5
    370       IF x>5:IF root=1:s$=PROGD$ & s$:NEXT t_loop 
    380       IF x=8:IF root=3:root=8 
    390       END IF 
    400     NEXT x 
    410       IF root=1:s$=PROGD$ & s$:NEXT t_loop 
    415       as$=s$ 
    420       IF root=3:s$=s$(1 TO 3) & PROGD$ 
    425       IF root=3:IF LEN(as$)>3:s$=s$&as$(4 TO):NEXT t_loop:ELSE EXIT t_loop 
    430     END FOR x
    435     EXIT t_loop 
    440   END REPeat t_loop 
    445   as$=s$ 
    460   RETurn s$(1 to root) 
    470 END DEFine


**NOTE 8**

Do not try to DEFine one FuNction inside another - although this is
actually allowed under most implementations, compilers presume that an
END DEFine should be placed before the start of the next DEFine FuNction
and it makes programs very difficult to follow. 

Under SMS the error
'Defines may not be within other clauses' will be reported when you try
to RUN the program.


**NOTE 9**

On Minerva pre v1.96, if you try to link in machine code procedures or
functions from inside a DEFine PROCedure or DEFine FuNction block, problems could occur after a CLEAR command.

**WARNING 1**

On most ROMs (at least on JM, MGx, AH and Minerva up to v1.97), a single
line recursive FuNction will not respond to the break key. For example::

    10 DEFine FuNction Root(a): a=2^Root(a)

The solution for all ROMs (or all those tested so far!) - insert an additional colon (:) as in::

    10 DEFine FuNction Root(a)::a=2^Root(a)

This is fixed on SMS v2.59+.

**WARNING 2**

All ROMs also suffer from this problem on multiple line recursive
FuNctions, where there is no active program line between the definition
line and the line which calls the FuNction. For example::

    10 DEFine FuNction Root(a) 
    20   a = 2^Root(a) 
    30 END DEFine

The solution here is to insert another active program line at line 15 -
for example::

    15 :

or::

    15 PRINT

Do however note that a REMark, DATA or LOCal line at line 15 will not
be sufficient as these are not active commands. Again, this is fixed
under SMS v2.59.


**WARNING 3**

Except under SMS, if you assign the same name to a FuNction as a resident command, not only will you no longer be able to use the
resident command, but it may crash the system!


**SMS NOTES**

In v2.59+, if you fail to create a SuperBASIC function correctly, the
error INCOMPLETE DEFine appears (for example if you omit the END
DEFine). Prior to v2.89 SMS would only allow a single line DEFine
FuNction if END DEFine appeared on the same line. However, although
v2.89 would allow a single-line DEFine FuNction without an END DEFine ,
it would report an error if the END DEFine existed!! Thankfully, v2.90+
fixes this problem, allowing both.


**CROSS-REFERENCE**

:ref:`end--define` tells the interpreter where
the end of the definition block can be found.
:ref:`return` allows you to return the result of
the Function. :ref:`define--procedure`
is very similar. :ref:`local` allows you to assign
temporary variables with the same name as variables used outside the
definition block. :ref:`paruse` and
:ref:`partyp` allow you to examine the type of the
parameters which are passed to the definition block.

--------------


..  _define--procedure:

DEFine PROCedure
================

+----------+-------------------------------------------------------------------------+
| Syntax   | DEFine PROCedure name [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] |
+----------+-------------------------------------------------------------------------+
| Location | QL ROM                                                                  |
+----------+-------------------------------------------------------------------------+

This command marks the beginning of the SuperBASIC structure which is
used to surround lines of SuperBASIC code which forms an equivalent to a
machine code SuperBASIC procedure, which can be called from within
SuperBASIC as a sub-routine. This forms a powerful alternative to GO SUB
and helps to make SuperBASIC programs very easy to read and de-bug.

The syntax of the SuperBASIC structure can take two forms: 

--------------

DEFine PROCedure name [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )]: statement
:sup:`\*`\ [:statement]\ :sup:`\*` 

or 

DEFine PROCedure name [(item :sup:`\*`\ [,item\ :sup:`i`]\ :sup:`\*` )] :sup:`\*`\ [LOCal var
:sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*` ]\ :sup:`\*` :sup:`\*`\ [statements]\ :sup:`\*` [RETurn] END DEFine [name] 

--------------


When the specified procedure name is
called, the interpreter then searches the SuperBASIC program for the
related DEFine PROCedure statement. 

If this cannot be found, then the
interpreter will look for a machine code procedure of that name. 

If the
definition of name cannot be found, then the error 'Not Found' will be
reported if name was defined in the past, but the definition line has
since been deleted. 

If name has never been defined in the current
SuperBASIC program, then the 'Bad Name' error will be reported. As with
FuNctions, the method of searching means that a machine code PROCedure
can be overwritten with a SuperBASIC definition and then later lost.
Parameters and items are treated in the same manner as with DEFine
FuNction. However, please note that calling parameters should not appear
in brackets after the name (unless you intend to pass them otherwise
than by reference!). 

When called, all of the SuperBASIC code within the
definition block will be executed until either an END DEFine or RETurn
is found, in which case execution will return to the statement after the
calling statement. In contrast however, to DEFine FuNction, there is no
need for a PROCedure definition block to contain a RETurn statement.


Strictly a PROCedure cannot return a value - however due to the nature
of the parameters being passed by reference (see DEFine FuNction), this
*is* possible.


**Example**

A simple demonstration program which highlights the fact that a
PROCedure or FuNction can actually be recursive (ie. call itself), and
also highlights the effect of passing parameters by reference - keep an
eye on the values in #0::

    100 radius=50:height=125:CLS:CLS#0 
    110 Rndom_circle radius,(height),100 
    120 AT #0,0,0:PRINT#0,radius,height,100 
    125 :
    130 DEFine PROCedure Rndom_circle(x,y,z) 
    140   INK RND(7):FILL RND(1) 
    150   CIRCLE RND (y),RND(z),x 
    160   FILL 0 
    170   AT #0,0,0:PRINT#0,x,y,z:PAUSE 
    180   x=x-RND(5):y=y-1:z=z+1 
    190   IF x<1:RETurn 
    200   Rndom_circle (x),y,z 
    210 END DEFine


**NOTE 1**

On pre JS ROMs, you could not define new PROCedures with names which had
already been used in the same program.


**NOTE 2**

On pre MG ROMs, any more than nine parameters may upset the program,
corrupting it by replacing names with PRINT towards the end of a
program. This can however be circumvented by increasing the size of the
Name Table by 8 bytes for each name (plus a little more for luck), using
the line::

    CALL PEEK_W(282)+36,N


**NOTE 3**

Recursive PROCedures (ie. PROCedures which call themselves, or call
another PROCedure or FuNction which in turn calls the original
PROCedure) are allowed (up to 32767 recursions on Minerva). They do
however gobble up memory at an amazing rate and can cause problems in
compiled SuperBASIC due to the fact that they need an ever-increasing
amount of stack space. They should be avoided wherever possible. On SMS,
if you try to use recursive functions too much, you may end up with the
error 'program structures nested too deeply, my brain hurts'! It is
however, more likely that you will end up with an 'Out of Memory' error
and not be able to do anything else (not even NEW).


**NOTE 4**

The LOCal statement (if used) must appear as the next statement
following DEFine PROCedure, otherwise an error will be reported. Under
SMS if this is not the case, the error 'Misplaced LOCal' will be
reported.


**NOTE 5**

Do not try to DEFine one PROCedure inside another - although this is
actually allowed under most implementations, compilers presume that an
END DEFine should be placed before the start of the next DEFine
PROCedure and it makes programs very difficult to follow. Under SMS the
error 'Defines may not be within other clauses' will be reported when
you try to RUN the program.

**WARNING 1**

As with DEFine FuNction problems do exist with recursive PROCedures
which prevent the Break key from working. These problems are fixed by
SMS v2.59+

**WARNING 2**

Except under SMS, if you assign the same name to a PROCedure
as a resident command, not only will you no longer be able to use the
resident command, but it may crash the system!


**SMS NOTES**

From v2.59, as with DEFine FuNction, SMS insists that all PROCedures
have an END DEFine statement, even if they are on a single line. If this
does not exist, or there is something else wrong with the syntax, then
the error 'Incomplete DEFine is reported. The same problems exist in
versions prior to v2.90 as with DEFine FuNction for in-line code.


**CROSS-REFERENCE**

Please see :ref:`define--function`! Also
see :ref:`end--define`. Look at the example
for :ref:`swap` which provides a more practical use
of recursive :ref:`procedure`\ s.

--------------


..  _defined:

DEFINED
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFINED (anything)                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

SuperBASIC is different from other BASIC dialects in that it does not
assign a default value to newly introduced but still unset variables
(except on SMS which assigns the value Zero to an unset numeric variable
and an empty string to an unset string). 

This makes it possible for a
program to detect if a variable has been properly initialised - an
'error in expression' (-17) is reported if you try to carry out
operations on unset variables. 

The function DEFINED takes any parameter,
no matter what type it is, provided that it is a constant or a variable.
DEFINED returns 0 if the parameter was a variable but unset and 1 for defined
variables and constant expressions.


**NOTE**

This function does not work on SMS


**CROSS-REFERENCE**

:ref:`clear` makes all variables undefined.
:ref:`print` writes asterisks if unset variables are
required to be printed. :ref:`type` returns 1, 2 or 3
for undefined variables. See also :ref:`unset`.

--------------


..  _deg:

DEG
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DEG (angle)                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function is used to convert an angle in radians into an angle in
degrees (which is the system more readily used by humans). Although this
will work for any value of angle, due to the very nature of angles,
angle should be in the range 0...2π, which will return a value in the
range 0...360.


**CROSS-REFERENCE**

See :ref:`rad` and the Mathematics section of the
Appendix.

--------------


..  _delete:

DELETE
======

+----------+--------------------------------------------------------------------+
| Syntax   || DELETE file  or                                                   |
|          || DELETE file :sup:`\*`\ [,file\ :sup:`i`]\ :sup:`\*` (THOR XVI)    |
+----------+--------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                                |
+----------+--------------------------------------------------------------------+

The command DELETE removes the stated file from a medium (it actually
only deletes its entry from the directory map, which thus allows these
files to be recovered if necessary, with a utility such as the Public
Domain RETTUNGE\_exe, provided that nothing has been written to the disk
since it was deleted). 

The filename must include the name of the medium,
unless you have Toolkit II installed, which alters the command so that
the default data device is recognised (see DATAD$). 

The command does not
report an error if a file was not found! However, if an invalid device
is used and Toolkit II is not present, an error will be reported. 

The
THOR XVI variant of this command follows the original proposal for this
command, allowing you to delete several files at the same time by
listing each filename, eg::

    DELETE flp1_boot,flp1_main_bas

This latter syntax is accepted on non-Minerva systems, but only the
first file will be deleted. If Toolkit II is present, error -15 (bad
parameter) is reported.


**Example**

::

    DELETE mdv2_PROG_bak 
    DELETE PROG_bak


**CROSS-REFERENCE**

:ref:`wdel` deletes several files interactively.
:ref:`wdel-f`, :ref:`wdir` and
:ref:`ttedelete` are also worth a look.

--------------


..  _del-defb:

DEL\_DEFB
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEL\_DEFB                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

QDOS stores information concerning devices and files (and in relation
to files, even their contents) in areas of memory known as 'slave
blocks' (memory permitting). These slave blocks can be very useful,
since when the computer tries to access the same device (or file) again,
the access is much quicker, since the relevent details can be loaded
from memory, rather than the device - the computer only need look at the
device to make certain that it is the same device (or disk) as was
previously used. 

There are three problems with the use of these slave
blocks: 

- The initial device access is slowed down as all of the
  information is effectively read twice - once into memory and once into
  the program. 

- Some disk drives do not support a means of checking if a
  disk has been amended on a second computer since the last access -
  meaning that the old version of the information stored in the slave
  blocks can be loaded instead 

- On some hard-disks, the hard-disk itself
  may not have been altered (you may need to use a command such as
  WIN\_FLUSH). 

The command DEL\_DEFB can assist with the second of these
problems, by deleting all of the slave blocks from memory. Another
problem which can be assisted by DEL\_DEFB is 'heap fragmentation'. To
keep memory tidy, there is an internal list which says where to find
which pieces of information. These lists reserve memory and can lead to
the phenomenon known as heap fragmentation. The following example
demonstrates this::

    PRINT FREE_MEM 
    a=ALCHP(10000) 
    b=ALCHP(10000) 
    PRINT FREE_MEM 
    RECHP a 
    PRINT FREE_MEM

First, we noted how much memory is free and then we reserved 20000
bytes of memory in two steps. So there are now 20000 bytes of free
memory less. Now, we release the first 10000 bytes and look again at the
free memory: it has not actually increased as much as you would have
thought! Actually, the memory isn't lost. FREE\_MEM returns the largest
piece of free memory in RAM. A further ALCHP(10000) would not reduce
FREE\_MEM in the above example. 

Maybe an illustration would make memory management clearer:: 

    free memory          |-------------------------|
    ALCHP(10000)         |######|------------------|
    ALCHP(10000)         |######|######|-----------| 
    release first block  |======|######|-----------| 

Key::

    -- : free memory (returned by FREE_MEM) 
    ## : reserved memory 
    == : free memory (used for ramdisks) 

The
above-mentioned internal list allocates a small piece of memory which
may reduce the largest piece of free RAM available to certain operations
which draw large chunks of memory at a time, causing them to fail (out
of memory), even though there would be enough memory had the 'drive
definition blocks' not fragmented it. The command DEL\_DEFB clears these
blocks, thus helping to relieve the heap fragmentation.


**NOTE**

Because DEL\_DEFB deletes the slave blocks, future device accesses will
be slowed!


**WARNING**

Do not use DEL\_DEFB if any channels are open to a file.


**CROSS-REFERENCE**

:ref:`rechp`, :ref:`clchp`,
:ref:`release`,
:ref:`free-mem`, :ref:`free`.
Dynamic RAM disks use effectively all of the free memory.
:ref:`format` lists other ways of causing heap
fragmentation.

--------------


..  _despr:

DESPR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DESPR (bytes)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  DESPR                                                            |
+----------+-------------------------------------------------------------------+

The function DESPR uses an un-documented system call to try and release
a given number of bytes from the resident procedure memory on the QL. It
is unknown how the ROM tries to decide which bytes to release.


**WARNING**

The system call used only works properly on Minerva ROMs and can crash
some versions of the QL. This function should not be used!!


**CROSS-REFERENCE**

Use :ref:`respr` to allocate resident procedure
memory, and do not try to release it at a later stage. Use
:ref:`alchp` and :ref:`rechp` to
allocate areas of memory which may be later released.

--------------


..  _destd-dlr:

DESTD$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DESTD$                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

 
This function always contains the current default destination device,
which is an unofficial QDOS standard and supported by the Toolkit II
variants of COPY, WCOPY, WREN, and SPL. 

When Toolkit II is initiated,
DESTD$='SER'. The default device means that if no other device is stated
for the destination file, this device will be used. The default
destination device will also be consulted if a device name is supplied
but the given file cannot be found on that device. 

For example, assuming
that DESTD$='flp2\_' and DATAD$='ram1\_', if you enter COPY
example\_txt, then the file ram1\_example\_txt will be copied to
flp2\_example\_txt. This idea can be extended to use prefixes as
sub-directories. Sub-directories are separated by underscores, DESTD$
always ends with an underscore.


**CROSS-REFERENCE**

:ref:`dest-use` and
:ref:`spl-use` both define the default
destination device\ .

:ref:`dup`, :ref:`ddown` and
:ref:`dnext` allow you to move around the
sub-directory tree. :ref:`progd-dlr` returns the
default program device, :ref:`datad-dlr` returns the
default data device. :ref:`dlist` prints all default
devices.

--------------


..  _dest-use:

DEST\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEST\_USE name                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command sets the current default destination device to the named
directory device. An underscore will be added to the end of the name if
one is not supplied. If you supply name as an empty string, this will
turn off the default destination directory.


**Example**

::

    DEST_USE win1_Quill


**NOTE 1**

DEST\_USE will overwrite the default set with SPL\_USE.


**NOTE 2**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to assign a longer string will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

Please see :ref:`destd-dlr` and
:ref:`spl-use`.

--------------


..  _demo:

DEMO
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DEMO n                                                           |
+----------+-------------------------------------------------------------------+
| Location |  Shape Toolkit                                                    |
+----------+-------------------------------------------------------------------+

As the name suggests, this is only a demonstration. Try the command
DEMO 1 and see what happens. Use only odd parameters if you want the
screen to be restored to its previous status when the demonstration
finishes.


**CROSS-REFERENCE**

The function :ref:`odd` checks if a number is odd or
even.

--------------


..  _det:

DET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DET [array]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function DET returns the determinant of a square matrix, meaning
that the array (or the part passed) must have two dimensions of equal
size, otherwise DET breaks with error -15 (bad parameter). 

The array
needs to be a floating point array, any other type (including integer
arrays) will also produce error -15.

If no parameter is given, DET will
use the array that has been supplied to the previously executed MATINV
command as its source. If however, this command has not yet been used,
DET without a parameter will stop with the error -7 (not found). 

You may
ask what a determinant is? Briefly speaking, it represents a square
matrix by a single number so that important characteristics of the
matrix can be deduced from it, eg. the matrix cannot be inverted if the
determinant is zero.


**Example**

We will try to approach the eigenvalues of a matrix and list them all
(the so-called "spectrum" of a matrix). Due to approximation errors and
the simple algorithm employed, there can be more output values than
there should be. This can be improved by increasing estep in line 130,
but at the cost of speed. 

The range of expected eigenvalues (eval1 to
eval2) is adapted to the chosen matrix whose random elements only range
between 0 and 1. There is no limit for the positive size n of the
matrix, n=0 is allowed but does not make sense because CHARPOLY becomes
constant::

    100 CLEAR: RANDOMISE 10: PRINT "Eigenvalues:" 
    110 n=2: DIM matrix(n,n), one(n,n) 
    120 MATRND matrix: MATIDN one 
    130 : 
    140 eval1=-1: eval2=1: esteps=200 
    150 eprec<(eval2-eval1)/estep) 
    160 c1=CHARPOLY(matrix,eval1): count%=0 
    170 FOR eval=eval1+eprec TO eval2 STEP eprec 
    180 c2=CHARPOLY(matrix,eval) 
    190 IF SGN(c1)<>SGN(c2) THEN PRINT eval 
    200 c1=c2: count%=count%+1 
    210 AT#0,0,0: PRINT#0,INT(100*count%/esteps);"%" 
    220 END FOR eval 
    230 PRINT "absolute fault:"!eprec 
    240 : 
    250 DEFine FuNction CHARPOLY(matrix,lambda) 
    260   LOCal diff(n,n),i 
    270   FOR i=1 TO n: one(i,i)=lambda 
    280   MATSUB diff,matrix,one 
    290   RETurn DET(diff) 
    300 END DEFine CHARPOLY

In practice, a Newton iteration algorithm (or better) would be used.


**CROSS-REFERENCE**

:ref:`matinv` co-operates closely with
:ref:`det`, so that for each of them a matrix
parameter can be omitted if the other function has been called before;
:ref:`matinv` calls :ref:`det`
internally. In the example, we used the
:ref:`matrnd`, :ref:`matidn`,
:ref:`sgn` and :ref:`matsub`
keywords which are all part of the same Toolkit.

--------------



..  _dev-name:

DEV\_NAME
=========

+----------+-------------------------------------------------------------------+
| Syntax   | device$ = DEV\_NAME(address)                                      |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function must be called with a floating point variable name as its parameter.  The first time this function is called, address *must* hold the value zero, on all other calls, simply pass address *unchanged* back.  The purpose of the function is to return a directory device name to the variable device$, an example is worth a thousand explanations.

::

    1000 addr = 0
    1010 REPeat loop
    1020   PRINT "<" & DEV_NAME(addr) & ">"
    1030   IF addr = 0 THEN EXIT loop: END IF
    1040 END REPeat loop

This small example will scan the entire directory device driver list and return one entry from it each time as well as updating the value in 'addr'. The value in addr is the start of the next device driver linkage block and *must not be changed* except by the function :ref:`dev-name`. If you change addr and then call :ref:`dev-name` again, the results will be very unpredictable.

The check for addr being zero is done as this is the value returned when the final device name has been extracted, in this case the function returns an empty string for the device.  If the test was made before the call to :ref:`dev-name`, nothing would be printed as addr is zero on entry to the loop.

Please note, every QL has at least one device in the list, the 'MDV' device and some also have a device with no name as you will see if you run the above example (not the last one as it is always an empty string when addr becomes zero).

The above example will only show directory  devices, those that can have DIR used on them, or :ref:`format` etc, such as WIN, RAM, FLP, FDK etc, however, it cannot show the  non-directory  devices such as SER, PAR (or NUL if you have Lightning), as these are in another list held in the QL.

**Note**

From version 1.14 of DJToolkit onwards, there is a function that counts the number of directory devices present in the QL. See :ref:`max-devs` for details.


**CROSS-REFERENCE**

:ref:`max-devs`.


-------


..  _device-space:

DEVICE\_SPACE
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVICE\_SPACE ([#]channel)                                       |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function returns the number of unused bytes on the medium (disk,
hard disk or microdrive) to which the specified channel is open. The
channel must relate to an open file on a directory device (otherwise
junk figures may be returned).


**Example**

A short routine which saves an area of memory to disk, with error
checking. 

::

    100 OPEN #3,'CON_448X200A32X16' 
    110 CLS #3 
    120 FILE$='FLP1_MEMORY_BIN' 
    130 FILE_SIZE=20000: ADDR=ALCHP(FILE_SIZE)
    140 REPEAT LOOP 
    150   INPUT #3,'ENTER FILENAME TO SAVE MEMORY TO : [DEFAULT=';(FILE$);']';F$ 
    160   IF F$='': F$=FILE$: ELSE FILE$=F$ 
    170   OPEN_STATE=DEVICE_STATUS(2,FILE$) 
    180   IF OPEN_STATE=-20: PRINT #3,'DEVICE IS READ ONLY': NEXT LOOP 
    190   IF OPEN_STATE=-11: PRINT #3,'DEVICE IS FULL': NEXT LOOP 
    200   IF OPEN_STATE=-8 
    210     INPUT #3,'DO YOU WANT TO DELETE EXISTING FILE ? (Y/N)';A$ 
    220     IF A$=='Y' 
    230       CH=FOP_IN(FILE$) 
    240     ELSE 
    250       PRINT #3;'ENTER NEW FILENAME': PAUSE 100
    260       NEXT LOOP 
    270     END IF 
    275   ELSE 
    277     CH=FOP_NEW(FILE$) 
    280   END IF 
    300   IF CH<0:REPORT #3: NEXT LOOP 
    305   FREE_SPACE=DEVICE_SPACE(#CH) 
    307   IF OPEN_STATE=-8: FREE_SPACE=FREE_SPACE+FLEN(#CH) 
    310   IF FREE_SPACE>=FILE_SIZE: PRINT#3,'SAVING FILE': EXIT LOOP 
    320   PRINT #3;'NOT ENOUGH ROOM ON DEVICE' 
    330   CLOSE #CH 
    335   IF OPEN_STATE<>-8: DELETE FILE$ 
    340 END REPEAT LOOP 
    350 CLOSE #CH 
    355 DELETE FILE$ 
    360 SBYTES FILE$,ADDR,FILE_SIZE


**NOTE**

Current versions of this fuction have difficulty returning the amount of
space on large capacity drives, such as hard disks. It assumes that a
sector contains 512 bytes and will only cope with a maximum of 65535
sectors.


**CROSS-REFERENCE**

See :ref:`fopen` and
:ref:`device-status` for more details on
accessing directory devices. :ref:`devtype`
finds out what type of device a channel is looking at.

--------------


..  _device-status:

DEVICE\_STATUS
==============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVICE\_STATUS ([open\_type,] filename$)                         |
+----------+-------------------------------------------------------------------+
| Location |  Turbo Toolkit                                                    |
+----------+-------------------------------------------------------------------+

This function returns a value representing the current status of the
device to which the specified filename$ points and can be used to check
if an error will be generated when you try to access the given file. The
open\_type defaults to 2 and can take the following values:

- -1: Use for OPEN or OPEN\_NEW
-  0: Use for OPEN
-  1: Use for OPEN\_IN
-  2: Use for OPEN\_NEW

If an open\_type of 2 is specified, then the function will try to
create the file and return an error code if this is not possible. The
temporary file is deleted in all cases. 

If an open\_type of 0 is
specified then the function will try to open the file for exclusive two
way access and report any errors. 

If an open\_type of 1 is
specified the function opens the specified file for read only access,
which means that it does not care if a channel is already open to the
file from another program. 

Finally, if an open\_type of -1 is specified,
the function will first of all try to open a channel to the file,
returning -8 if it already exists and can therefore be read. 

If it does
not already exist, the function will try to create a temporary file and
then read back from it to check that the device can be written to and
read from, reporting any errors which are found. Any temporary file is
then deleted by the function. This enables IN USE and bad or changed
medium errors can be detected! 

If the open is successful the amount of
free space on the drive is returned akin to DEVICE\_SPACE, otherwise a
standard QDOS error code is returned.


**NOTE 1**

Current versions of this fuction have difficulty returning the amount of
space on large capacity drives, such as hard disks. It assumes that a
sector contains 512 bytes and will only cope with a maximum of 65535
sectors.


**NOTE 2**

Due to a bug in the QL's hardware, it is impossible to check if a
microdrive is read only. In this instance, you will get a bad or changed
medium error code (-16).


**CROSS-REFERENCE**

See :ref:`device-space` for an example.

--------------


..  _devlist:

DEVLIST
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVLIST [#channel]                                               |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command lists all directory devices recognised by the system to
the specified channel. A directory device is one which contains files.
The default list channel is #1.


**NOTE**

If device names appear in the listing more than once, this means that
more than one device driver is loaded. This normally happens with
ramdisks ("RAM").


**CROSS-REFERENCE**

Directory devices may be renamed with :ref:`change`
(this will have a corresponding effect on
:ref:`devlist`), whilst any device can be renamed
using :ref:`qrd` (this will have no effect on
:ref:`devlist`). Compare
:ref:`dlist`.

--------------


..  _devtype:

DEVTYPE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DEVTYPE [(#channel)]                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This function returns a value to indicate the type of device the
specified channel (default #0) is connected to. At present, you should
only look at the first three bits of the return value, ie::

    x%=DEVTYPE(#channel) 
    x%=x% && 3

The value returned is:

- 0 - a purely serial device 
- 1 - a screen device 
- 2 - a file system device (ie. it supports file positioning) 

Any other values indicate that there is something wrong with the channel (if the
value is >2) otherwise, a negative value means that the channel is not open.


**NOTE**

Prior to v2.71, DEVTYPE would return 'End of File' error if the
specified channel was attached to a file and the file pointer was at the
end of the file.


**CROSS-REFERENCE**

:ref:`open`, :ref:`open-in`,
:ref:`open-new` and
:ref:`open-over` allow you to open channels.

--------------


..  _dev-list:

DEV\_LIST
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_LIST [#channel]                                             |
+----------+-------------------------------------------------------------------+
| Location |  DEV device, GOLD CARD, ST/QL, SMS                                |
+----------+-------------------------------------------------------------------+

This command lists all DEV\_USE definitions to the given channel,
default #1. You can also use a public domain utility, DEV Manager, to
set and list DEV definitions on a per-program basis.


**Example**

DEV\_LIST for example 4a of DEV\_USE prints::

    DEV1_ FLP2_SOURCES_ -> DEV4_
    DEV2_ FLP1_COMPILER_ -> DEV3_
    DEV3_ FLP1_COMPILER_UTILS_ -> DEV4_
    DEV4_ RAM1_ -> DEV5_ 
    DEV5_ FLP1_SOURCES_OTHER_ -> DEV1_


**CROSS-REFERENCE**

:ref:`dev-use`,
:ref:`dev-use-dlr`,
:ref:`dev-next` Compare
:ref:`devlist` and
:ref:`dlist`.

--------------


..  _dev-next:

DEV\_NEXT
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_NEXT (n) n=1..8                                             |
+----------+-------------------------------------------------------------------+
| Location |  DEV device, GOLD CARD, ST/QL, SMS                                |
+----------+-------------------------------------------------------------------+

The function DEV\_NEXT returns the number of the next DEVice where a
given DEV will look on next if a file was not found. If a DEV is not
defined or has the search option disabled, DEV\_NEXT returns zero (0),
otherwise an integer from 1 to 8 will be returned.


**Example**

A program which lists a search path::

    100 INPUT "Which DEV device (1..8)?"!n 
    110 IF n<1 OR n>8 THEN RUN 
    120 DIM checked%(8) 
    130 REPeat SPate 
    140   IF NOT DEV_NEXT(n) OR checked%(n): EXIT SPate 
    150   PRINT DEV_USE$(n) 
    160   checked%(n)=1 
    170   n=DEV_NEXT(n) 
    180 END REPeat SPate

If you understood this example, then you will know exactly how the DEV
device works.


**CROSS-REFERENCE**

:ref:`dev-use-dlr`,
:ref:`dev-list`,
:ref:`dev-use`

--------------


..  _dev-use:

DEV\_USE
========

+----------+--------------------------------------------------------------------+
| Syntax   || DEV\_USE n,drive [,next\_dev] n=1..8 or                           | 
|          || DEV\_USE [n](SMS v2.70+ only) or                                  |
|          || DEV\_USE [drivetype]                                              |
+----------+--------------------------------------------------------------------+
| Location || DEV device, GOLD CARD, ST/QL, SMS                                 |
+----------+--------------------------------------------------------------------+

The DEV device is a universal method of driving devices (MDV, FLP, WIN,
MOS, ROM), and thus allows old software to recognise default devices/
sub-directories as well as simplifying the use of them. It also
introduces fully programmable search paths to QDOS. 

There are eight
separate DEV drives available, DEV1\_ to DEV8\_, each of which can point
to a real drive and directory defined with DEV\_USE. 

The first parameter
of the command is the number of the DEV device to be defined. 

The second specifies what DEVn\_ represents.

There is no default and nothing is predefined, but DEV\_USE permits only
valid drives and directories. Any default devices (DATAD$, PROGD$ etc)
are not recognised so the full directory name (including the drive name)
must be stated. 

There is one special second parameter, the empty string,
which removes the definition of the given DEV device; there is no error
reported if it was not defined. 

The second syntax (SMS v2.70+) also allows you to
remove a definition by simply passing the number of the DEV device to
delete.


**Example 1**

::

    DEV_USE 1,flp1_ 
    DEV_USE 2,flp1_SUBDIR_ 
    DEV_USE 3,flp1_SUBDIR
    DEV_USE 4

Each time that DEV1\_ is accessed, the actual drive which will be
accessed is FLP1\_, eg. DIR DEV1\_ lists a directory of FLP1\_. 

However,
LOAD DEV2\_BOOT will load FLP1\_SUBDIR\_BOOT but especially note that
LOAD DEV3\_BOOT would try to load FLP1\_SUBDIRBOOT (that's not a typing
error). 

You can therefore see the importance of specifying the
underscore! Whereas DATA\_USE always adds an underscore to the supplied
parameter if there one was not specified, DEV\_USE does not. Please pay
attention to this difference! 

DEV\_USE's third parameter is optional and
ranges from 0 to 8. This is used to specify another DEV device which
should be tried if DEVn\_ was accessed for a given file, but the file
was not present on that DEV device. 

In all other cases: if the drive in
general is currently inaccessible (eg. open for direct sector
read/write), the file is damaged or already in use, the DEV device will
stop with the appropriate error message, and behave as normal in such
situations.


**Example 2**

::

    DEV_USE 1,flp1_,2 
    DEV_USE 2,flp1_TEST_ 

VIEW DEV1\_Prog\_bas will first try to show FLP1\_Prog\_bas and if it
did not find that file, it will then try DEV2\_Prog\_bas which is
actually FLP1\_TEST\_Prog\_bas. If this also fails, VIEW stops with a
'Not Found' error. You might notice that this could lead to an endless
search if DEV2\_ was told to jump back to DEV1\_ if
flp1\_TEST\_Prog\_bas also did not exist.


**Example 3**

::

    DEV_USE 1,flp1_,2 
    DEV_USE 2,flp1_TEST_,1

Luckily, this is no problem - the DEV device never circles back to a
DEV which has already been tried. So, using the definition given for
example 3, VIEW DEV1\_Prog\_bas looks for FLP1\_Prog\_bas, then
FLP1\_TEST\_Prog\_bas and breaks with 'Not Found' because DEV1\_ has
already been tested. 

That's why a DEV
device cannot point to another DEV device, DEV\_USE 1,DEV2\_ is
illegal. 

It is advisable to give seldom used drives and directories a
lower search priority because it naturally takes a little time to scan
through a directory for a file. Preferred directories and fast RAM disks
(which take next to no time to check for a file) should be checked
before the less often-used directories are looked at.

**Example 4a**

::

    DEV_USE 1,flp2_SOURCES_,4 
    DEV_USE 2,flp1_COMPILER_,3 
    DEV_USE 3,flp1_COMPILER_UTILS_,4 
    DEV_USE 4,ram1_,5 
    DEV_USE 5,flp2_SOURCES_OTHER_,1

The search path for DEV1\_ is:

- FLP2\_SOURCES\_ go to DEV4\_ 
- RAM1\_ go to DEV5\_ 
- FLP2\_SOURCES\_OTHER\_ go to DEV1\_, we already tried that, so
  stop 

The search path for DEV2\_ is:

- FLP1\_COMPILER\_go to DEV3\_
- FLP1\_COMPILER\_UTILS\_ go to DEV4\_ 
- RAM1\_ go to DEV5\_FLP2\_SOURCES\_OTHER\_ go to DEV1\_ 
- FLP2\_SOURCES\_ go to DEV4\_, already checked, so stop.

You see that the two search paths for DEV1\_ and DEV2\_ are connected in one way. This rather complicated example
suggests that it would be useful to set the data and program device as follows:

**Example 4b**

::

    DATA_USE DEV1_ 
    PROG_USE DEV2_

Taking into account that Toolkit II tries the program device after
failing to find a file on the data device, a VIEW TEXT will first search
through the DEV1\_ list and then DEV2\_ (thus looking through all DEVs)
while EX PROG\_exe stops after checking DEV2\_ and its connected DEVs.

All operations creating or deleting files will only check for the
original DEV definition and ignore the optional paths. This prevents
files from being unintentionally deleted or overwritten. 

Given the
settings of examples 4a and 4b, OPEN\_IN #3,DEV1\_TEXT
will act as VIEW did before whereas OPEN\_NEW #3,DEV1\_TEXT creates
FLP2\_SOURCES\_TEXT or reports an error/asks if you want to overwrite
(if necessary). 

DELETE always behaves as an exception in that it does
not report an error if a file was not found. 

You may have noticed that
the third parameter allows a wider range than the DEV number. A zero as
the third parameter simply does the same as no third parameter. 

The
third syntax of DEV\_USE is completely different from the first two. It
is analogous to the FLP\_USE, RAM\_USE and NFS\_USE
commands and allows you to use a different three letter code for the
DEV device::

    DEV_USE fry. 

DEV1\_ is now called fry1\_, DEV2\_ fry2\_ and
so on. However, you can also use existing devices.

**Example 4c**

::

    DEV_USE FLP

Now, things become really complex. With examples 4a and 4b still being
valid, FLP1\_ actually refers to FLP1\_SOURCES\_, searching through all
the other DEV definitions as well in order to find a file. 

The
definitions of DEV1\_ as FLP1\_SOURCES\_ and DEVs as FLP do not collide.
However, if you issued FLP\_USE DEV, FLP1\_ and DEV1\_ are not known any
more until FLP\_USE FLP restores the default name for disk drives.

Equally, DEV\_USE DEV restores the DEV name (although this can be
abbreviated by a DEV\_USE without any parameters).

**Example 5**

::

    DEV_USE DEV1_ 

refers to the true DEV1\_ again, DEV2\_, DEV3\_, ..., too.

Renaming DEV has been mainly implemented to convince existing software
believing that a directory file always has five letters (eg. MDV1\_) to
accept sub-directories of level-2 drivers as directory files, too.


**NOTE**

At least up to v2.01, the DEV device does not work fully on any machine.
For example WSTAT lists the file names but not the other information:
DEV\_USE 1,FLP1\_TEST\_ WSTAT DEV1\_


**CROSS-REFERENCE**

:ref:`data-use`,
:ref:`prog-use`,\ :ref:`dev-use-dlr`,
:ref:`dev-next`.
:ref:`dev-usen` is the same as the third syntax
on SMSQ/E. :ref:`dev-list` lists all DEV
definitions. :ref:`make-dir` and the
DMEDIUM_XXX commands, starting with :ref:`dmedium-density` are also
interesting.

--------------


..  _dev-usen:

DEV\_USEN
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_USEN [drivetype]                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This command is provided on SMSQ/E to allow you to alter the three
letter reference used to access the DEV devices. If no parameter is
specified, then the name reverts to DEV.


**Example**

::

    DEV_USE 2,'win1_progs_' 
    DEV_USEN 'flp' DIR flp2_

This will provide a directory of win1\_progs\_ - this can be reset
with::

    DEV_USEN 
    DIR dev2_

**CROSS-REFERENCE**

:ref:`dev-use` allows you to do the same thing.
:ref:`flp-use` allows you to alter the three
letter description for floppy disks.

--------------


..  _dev-use-dlr:

DEV\_USE$
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_USE$ (n) where n=1..8                                       |
+----------+-------------------------------------------------------------------+
| Location |  DEV device, GOLD CARD, ST/QL, SMS                                |
+----------+-------------------------------------------------------------------+

The DEV\_USE$ function returns the actual drive and directory for the
number of a DEV device. If a device was not defined, DEV\_USE$ will
return an empty string "", LEN(DEV\_USE$(n))=0.


**Example**

A listing of all DEV definitions::

    100 UNDER 1: PRINT "DEV";: UNDER 0 
    110 PRINT " ";: UNDER 1: PRINT "definition": UNDER 0 
    120 found=0 
    130 FOR n=1 TO 8 
    140 IF LEN(DEV_USE$(n)) THEN 
    150   PRINT n TO 5;DEV_USE$(n) 
    160   found=1 
    170 END IF 
    180 END FOR n 
    190 IF NOT found: PRINT "no DEVs defined"


**CROSS-REFERENCE**

:ref:`dev-next`,
:ref:`dev-list`,\ :ref:`dev-use`.

--------------


..  _dim:

DIM
===

+----------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | DIM array (index1 :sup:`\*`\ [index\ :sup:`i`]\ :sup:`\*` ) :sup:`\*`\ [,array\ :sup:`j` (index :sup:`\*`\ [index\ :sup:`j`]\ :sup:`\*` )]\ :sup:`\*` |
+----------+-------------------------------------------------------------------------------------------------------------------------------------------------------+
| Location |QL ROM                                                                                                                                                 |
+----------+-------------------------------------------------------------------------------------------------------------------------------------------------------+

The command DIM allows you to set up one or more SuperBASIC arrays
which may be of string, integer or floating point type. Each index must
be an integer in the range 0...32767.

Numeric Arrays
~~~~~~~~~~~~~~

Each index defines the maximum number of elements (less one) in any one
direction, which provides the following examples::

    DIM a(10)

sets up a floating-point array a containing 11 elements, a(0) to a(10);

::

    DIM z%(10,10)

sets up a two dimensional integer array z% containing 121 elements,
z%(0,0) to z%(10,10) Each element can hold a different number which can
later be accessed by specific reference to each index. When the array is
set up, each element is set to zero.

String Arrays
~~~~~~~~~~~~~

String arrays are peculiar and have various differences to both
un-dimensioned strings and number arrays. 

In a string array, the final
index contains the maximum length of a string, rounded up to the next
even number (an attempt to assign a longer string to one of the array
elements will result in a truncated string). For example::

    DIM a$(10)

sets up a one-dimensional string array a$ with a maximum of 10
characters. This is similar to a$=FILL$(" ",10), except that a$ now has
a maximum length; 

::

    DIM z$(10,9)

sets up a two-dimensional string array, which can hold 11 strings
(z$(0) to z$(10)), each up to 9 characters long. 

When a string array is
set up with DIM, each entry is set to a nul string (""). The zero'th
element of each string array contains the actual length of that string,
for example::

    DIM a$(10,10): a$(1)='Hello': PRINT a$(1,0)

will return the value 5, as will PRINT LEN(a$(1)). 

If a$ is
undimensioned and a$='Hello World', PRINT a$(0) does not generally work
and will result in an 'Out of Range' error, except under SMS v2.60+ and
Minerva where PRINT a$(0) is the same as PRINT LEN(a$).

Sub-Sets of Arrays
~~~~~~~~~~~~~~~~~~

Sub-sets of arrays can also be accessed, for example::

    PRINT z$(0 TO 2)

will print the first three strings stored in the array z$.

Omitting Indices
~~~~~~~~~~~~~~~~

This can be one of the most difficult parts of SuperBasic from the point
of view of making programs compatible on all implementations of
SuperBASIC and also making programs work the same under the interpreter
and when compiled. 

The ST/QL Emulators (with E-Init v1.27 or later)
follow the same rules as SMS. If an index is omitted, SuperBASIC inserts
a default index of::

    0 TO DIMN (array,index_no)

For example, if array is a two-dimensional array, array(1) is the same
as using the form array (1,0 TO DIMN(array,2)). Unfortunately, string
arrays are slightly different when using the last index. 

If the last
index is omitted, this defaults to an index of::

    1 TO LEN(array$(x))

However, except on SMS, if a start descriptor is specified, but not an
end one, the last index defaults once again to: start\_descriptor TO
DIMN(array$,index\_no). On SMS this defaults to start\_descriptor TO LEN(array$(x).

Even more oddly, except on SMS and Minerva, if a start descriptor is
omitted, but an end descriptor specified, the index defaults to: 0 TO
end\_descriptor normally resulting in an error. (On SMS and Minerva this defaults to 1
TO end\_descriptor).

However, except on SMS and Minerva, if neither a
start nor end descriptor are specified, but the TO itself is specified,
this defaults to 0 TO DIMN (array$,index\_no), again normally causing an
error. 

On SMS this defaults to 1 TO LEN (Array$ (x)

On Minerva this defaults to 1 TO DIMN (array$,index\_no)

This creates the following result::

    DIM a$(10):a$='Hello' INK 7:PAPER 0
    STRIP 2 

::

    PRINT a$

Prints 'Hello' => a$ (1 TO LEN(a$) (On all implementations) 

::

    PRINT a$(1 TO)

Prints 'Hello ' => a$(1 TO DIMN(a$,1)) (except on SMS, where it prints
'Hello', unless the program is compiled with Qliberator in which case
the original system is adopted). 

::

    PRINT a$(TO)

Results in 'Out of Range' => a$(0 TO DIMN(a$,1)) (except on SMS, where
it prints 'Hello', and on Minerva where it prints 'Hello ' In both
cases, if the program is compiled with Qliberator it still reports an
error). 

::

    PRINT a$( TO 5)

Results in 'Out of Range' => a$(0 TO 5) (again on SMS and Minerva it
still prints 'Hello', unless the program is compiled with Qliberator,
which reports an error).

Un-Dimensioned Strings
~~~~~~~~~~~~~~~~~~~~~~

You can use sub-sets of un-dimensioned strings, for example::

    a$='Hello World':PRINT a$(1 TO 5)

However, such subsets are always treated as expressions, which means
that if such a subset was passed as a parameter to a FuNction or
PROCedure (see DEFine FuNction), it cannot be passed by reference and
the string will remain unaltered by the FuNction/PROCedure. 

Compare this
with a sub-set of a string array, which will be altered (this sub-set
exists as a sub-array). Please see Example 3 below. 

The handling of
descriptors is also different with un-dimensioned strings. If neither a
start nor an end descriptor are specified, this, like string arrays,
defaults to::

    1 TO LEN(string$)

However, if the start descriptor is specified, but not the end
descriptor, this defaults to::

    start_descriptor TO LEN(string$)

However, if the start descriptor is omitted (whether the end descriptor
is specified or just TO is used), unless you have Minerva or SMS, this
defaults to::

    0 TO end_descriptor

and::

    0 TO LEN(string$)

respectively, both of which cause an 'out of range' error. 

On Minerva
and SMS however, this defaults to::

    1 TO end_descriptor

and::

    1 TO LEN(string$)

respectively, thus avoiding this error. 

This leads to the following result::

    CLEAR 
    x$='Hello'
    INK 7: PAPER 0: STRIP 2 

::

    PRINT x$

This Prints 'Hello'. 

::

    PRINT x$(1 TO)

This prints 'Hello' 

::

    PRINT x$(TO) 

This results in 'Out of Range' or 'Hello' on Minerva and SMS. 

::

    PRINT x$( TO 10)

This results in 'Out of Range' or 'Hello' on Minerva and SMS.


ERRORS
~~~~~~

Due to the complexity of DIM, we felt that it would be useful to explain
some of the various errors which may be reported. SMS has an improved
Interpreter which reports more intelligible error codes, therefore those
have been used:

**Only arrays may be dimensioned**

This occurs when you try to DIM the name of a procedure or function. It
also occurs if you try to use DIM on one of the parameters of a
procedure or function and that parameter is not itself a dimensioned
variable::

    100 DIM x(10) 
    110 c=1:test x,1 
    130 DEFine PROCedure test (a,b)
    140   DIM b(10) 
    150 END DEFine

 On other implementations, 'Bad Name' is reported in both instances.

**Procedure and function parameters may not be dimensioned**

This only happens as in the example above where you try to DIMension a
variable which is in fact one of the parameters from the DEFine
PROCedure or DEFine FuNction line (eg. line 140). Here, if you pass a
dimensioned variable, eg: TEST 1,x, you get this error under SMS. Also
see note 7. On other implementations no error is reported and the
problems listed in Note 7 occur.

**SBASIC cannot put up with negative dimensions**

This occurs if you try to use a negative index, for example: DIM x(-10)
On other implementations 'Out of Range' is reported.

**Dimensional overflow - you cannot be serious!**

Too many indices have been specified in the DIM statement - refer to
Appendix 8.

**Error in Expression**

SMS has either been unable to make any sense of the index, or else it
exceeds 32767. On other ROMs you will get the error 'Overflow' if index
exceeds 32767.

**Unknown function or array**

This is generally reported of you try to use a Procedure name as the
index. Other implementations report 'Error in Expression'

EXAMPLES
~~~~~~~~

**Example 1**

A program which acts as a simple quiz program, but shows off some of the
best features of using arrays - it is simplicity itself to add new
questions and answers to this quiz (just amend quest and target and add
the new questions and answers as DATA at the end of the program)::

    100 MODE 8:WINDOW 512,256,0,0:PAPER 0:CLS 
    110 WINDOW 448,200,32,16 
    120 quest=5:target=5 
    130 DIM question$(quest,50),option$(quest,3,25),answer(quest) 
    140 RESTORE 
    150 FOR i=0 TO quest-1 
    160   READ question$(i) 
    170   FOR j=1 TO 3:READ option$(i,j) 
    180   READ answer(i) 
    190 END FOR i 
    200 REPeat main_loop 
    210   score=0 
    220   FOR i=1 TO 7,1:BORDER 10,i:PAUSE 2 
    230   PAPER 6:CLS:INK 2:AT 3,10:UNDER 1:CSIZE 2,1 
    240   PRINT 'QUIZ EXAMPLE':CSIZE 2,0:UNDER 0 
    250   INK 0:AT 0,20:PRINT 'SCORE = ';score 
    260   DIM asked(quest) 
    270   REPeat loop 
    280     opt=RND(1 TO quest) 
    290     IF asked(opt)=1 THEN 
    300       FOR j=1 TO quest 
    310         IF asked(j)=0:opt=j:EXIT j 
    320         NEXT j 
    330         DIM asked(quest):NEXT loop 
    340       END FOR j 
    350     END IF 
    360     asked(opt)=1 
    370     AT 4,0:CLS 2 
    380     ask_question(opt) 
    390     reply=get_answer 
    400     AT 16,0:PAPER 2:INK 7 
    410     IF reply=answer(opt-1) 
    420       PRINT 'Correct':score=score+1 
    430     ELSE 
    440       PRINT 'Wrong!':score=score-1
    450     END IF 
    460     PAPER 6:INK 0 
    470     AT 0,20:PRINT 'SCORE = ';score 
    480     PAUSE 
    490     IF score=target OR score<0:EXIT loop 
    500   END REPeat loop 
    510   PAPER 0:CLS 
    520   INK 2+2*(score=target):CSIZE 3,1 
    530   IF score=target
    540     PRINT 'Congratulations' 
    550   ELSE 
    560     PRINT 'Oh Dear' 
    570   END IF 
    580   CSIZE 2,0:INK 7 
    590   PRINT \\'Try again?? -----> y/n' 
    600   REPeat keys
    610     key$=INKEY$(-1):IF key$ INSTR 'yn':EXIT keys 
    620   END REPeat keys 
    630   IF key$=='n':STOP 
    640 END REPeat main_loop 
    645 : 
    650 DEFine PROCedure ask_question(no) 
    660   LOCal i 
    670   AT 6,0:start_word=1:end_word=1 
    680   no=no-1 
    690   REPeat quest_loop 
    700     FOR char=start_word TO question$(no,0) 
    710       IF question$(no,char)=' ':EXIT char 
    720     END FOR char
    730     end_word=char 
    740     PRINT !question$(no,start_word TO end_word)!
    750     IF end_word=question$(no,0):EXIT quest_loop 
    760     start_word=end_word+1 
    770   END REPeat quest_loop 
    780   REPeat opt_loop
    790     PRINT \ 
    800     FOR i=1 TO 3 
    810       PRINT TO 5;i;' = ';option$(no,i) 
    820     END FOR i 
    830 END DEFine 
    835 : 
    840 DEFine FuNction get_answer 
    850   REPeat keys 
    860     key$=INKEY$(-1) 
    870     IF key$ INSTR '123':RETurn key$ 
    880   END REPeat keys 
    890 END DEFine 
    895 : 
    900 DATA 'The standard Sinclair QL has how much memory?' 
    910 DATA '16K','128K','640K',2 
    920 DATA "What was the name of Sinclair's first computer?" 
    930 DATA 'Z80','ZX81','ZX80',3
    940 DATA 'Who is the main person responsible for QDOS?' 
    950 DATA 'T.Tebby','J.Jones','C.Sinclair',1 
    960 DATA "Which company created the QL's Gold Card?" 
    970 DATA 'Miracle Ltd.','Digital Precision Ltd.','Mercury',1 
    980 DATA 'Who is the main person responsible for SuperBASIC?' 
    990 DATA 'T.Tebby','J.Jones','C.Sinclair',2

Some of you may have noticed that we have used DIM option$(quest,3,25)
when we could have used DIM option$(quest,2,25). The reason for this is
to make it easier to check the text - try PRINT option$ and you will see
that each set of three options is separated by a blank string.


**Example 2**

Take the two arrays set up with::

    DIM x(2,3,4),x$(2,4,6). 

The following
sub-arrays produce the following equivalents::

    x(TO, TO 2, 1 TO) => x(0TO 2,0 TO 2,1 TO 4) 
    x$(1 TO 2, TO 2) => x$(1 TO 2,0 TO 2,1 TO LEN(x$(..))) 
    x$(TO 2, TO,1 TO) => x$(0 TO 2,0 TO 4,1 TO 6)


**Example 3**

A short example of the use of sub-arrays and subsets of undimensioned
strings::

    100 DIM a$(11) 
    110 a$='Hello World' 
    120 b$='Great World' 
    130 swap_array a$(1 TO 5),b$(1 TO 5) 
    140 PRINT a$,b$ 
    150 : 
    1000 DEFine PROCedure swap_array (a,b) 
    1010   c$=b: b=a: a=c$ 
    1020 END DEFine


**NOTE 1**

The Turbo compiler alters DIM in compiled programs to enable you to
re-dimension arrays without losing their original contents. You may
therefore need to physically set the contents of arrays to zero (or nul
strings) to ensure that a program works properly when compiled.


**NOTE 2**

On AH ROMs, a floating point array is limited to 384K size.


**NOTE 3**

A variable cannot be used as both a simple variable and an array
variable. It is set to an array variable as soon as the line containing
the relevant DIM statement is parsed. This means that if a line
containing DIM var has been entered, the array var cannot be used until
such time as the program has RUN this line, and in any case, an attempt to use var without array
descriptors (eg. var=1) is likely to fail, either resulting in a 'Bad
Name' error or 'Error in Expression'.


**NOTE 4**

You cannot assign one array to another. For example::

    DIM a$ (3,10) , z$(3,10) :z$=a$

will report a 'Not Implemented' error. 

Compare::

    z$ ( 1, 1 TO 10 )=a$ (1, 1 TO 10 ).


**NOTE 5**

The Turbo and Supercharge compilers insist that strings are all
dimensioned as string arrays. They do however also alter the way in
which string arrays work so that they operate more like un-dimensioned
strings. Un-dimensioned strings may also upset Qliberated tasks!


**NOTE 6**

On pre JS ROMs you cannot use one array as the array sub-script of
another in the DIM statement (other than as the first sub-script), for
example::

    DIM a(10):a(3)=10 
    DIM a$(10,a(3))

If you try this, you will find that previous array sub-scripts are set
to the value 0, ie. using the above example, a$(0) would be acceptable,
whereas a$(2) would cause an error. This will work okay provided that
the array is used as the first sub-script, otherwise use a temporary
variable. For example::

    subs=a(3): DIM a$(10,subs) 
    DIM a$(a(3),10)

would both work okay on all ROM versions.


**NOTE 7**

There is a bug in SMS (at least up to v2.88) if you try to DIMension a
variable which has been used as a parameter for a PROCedure or FuNction
call. 

Take the example given above to demonstrate the error 'procedure
and function parameters may not be dimensioned'. Now use:: 

    CLEAR : TEST a,b 

no error is reported (although line 140 has no effect). 

::

    PRINT a,b

is equivalent to PRINT a; and any attempt to use b (eg. x=b) reports
error in expression, even after CLEAR. 

On other ROMs no error is
reported. However, the variable passed as a parameter is not
re-dimensioned, but some of its elements will no longer be the original
value, but very small numbers and any attempt to assign another value to
those elements which have been changed may in fact fail!!


**NOTE 8**

Current versions of Qliberator treat all strings in the same way as on
the original QL, therefore although a program may RUN fine under the SMS
or Minerva intepreter, it may cause problems when compiled. The TURBO
and SuperCHARGE compilers treat strings the same as SMS, except see Note
1 and Note 5.


**MINERVA NOTE**

Minerva alters the way in which both dimensioned and undimensioned
strings are handled so that::

    PRINT a$( TO 10) 

is now acceptable! See above. 

Minerva also allows you to slice expressions and numbers. Lines
such as::

    PRINT 'abcd' (2 TO 3) 

and::

    a$=101010 (3) 

will now work. Minerva v1.96+ allows multiple index lists (see SMS Notes).


**SMS NOTES**

SMS alters the way in which both undimensioned and dimensioned strings
are handled to make them more sensible (see above). We now await a
compiler which handles strings in the same way! SMS says that it no
longer handles multiple index lists on assignments (which apparently
were allowed on earlier ROM versions - did anyone ever use these?). An
example is the line::

    100 DIM a$(3,4,5) 
    110 a$(3,4)='Hello' 
    120 a$(3,4)(2 TO 5)='ELLO'

SMS will not let you type in line 120 reporting invalid syntax. To
overcome this you have to replace the line with::

    120 a$(3,4,2 TO 5)='ELLO'

In common with Minerva, SMS will now also allow you to slice
expressions and numbers. There is a bug in current versions of SMS (at
least up to v2.90) when passing string array sub-sets by reference, for
example the following program::

    5 DIM x$(11) 
    10 x$='Hello World' 
    15 PRINT x$ 
    20 change x$(1 TO 11) 
    30 PRINT x$ 
    40 :
    1000 DEFine PROCedure change (a$)
    1010   a$(1 TO 3)='EXT' 
    1020 END DEFine

At line 30, x$ is shown to be 'HeEXT World'?? It should be 'EXTlo
World'. Try making line 20 read::

    20 change x$

Although v2.90 fixes this problem, if you pass a sub-set of an
undimensioned string, a worse problem is created. Try deleting line 5
and adding line::

    1015 PRINT a$: PAUSE 

before RUNning the program (you may need to use CLEAR beforehand).


**WARNING**

DIM and dimensioned variables can crash the system in certain instances
- refer to A8.4 for details of the possible problems and more error
messages which can be generated.


**CROSS-REFERENCE**

:ref:`dimn` allows you to find out the maximum sizes
of an array. Please see the Appendix on Compatability concerning String
Lengths. :ref:`len` allows you to find the length of a
string.

--------------


..  _dimn:

DIMN
====

+----------+----------------------------------------------------------------------------------+
| Syntax   || DIMN (array [,dimension] )  or                                                  |
|          || DIMN (array (dimension\ :sup:`1` :sup:`*`\ [,dimension\ :sup:`i`]\ :sup:`*`\ )) |
+----------+----------------------------------------------------------------------------------+
| Location || QL ROM                                                                          |
+----------+----------------------------------------------------------------------------------+

This function allows you to investigate the size of the given index of
a specified array. 

The first syntax is the most common: it will return
the specified dimension (index) used in the original DIM statement when
the array was defined. If the index did not exist, then a result of zero
is returned. 

If dimension is not specified, then the size of the first
index is returned. 

The second syntax is somewhat obscure and has no
practical advantages. This second syntax will not allow you to access
the size of the first index. It works by reference to the array itself,
for example:: 

    PRINT DIMN(a$(1))

will return the size of the second index, and::

    PRINT DIMN(a$(1,1))

will return the size of the third index and so forth. Once the number
of dimensions used within the DIMN statement has reached the number used
by the array, then the value 1 will be returned. If any more are
specified, then the error 'Out of Range' will result.


**Examples**

Take an array created with the statement::

    DIM a$(10,12)

The following results will be returned::

    PRINT DIMN(a$)

Will return 10.

::

    PRINT DIMN(a$,1)

Will return 10.

::

    PRINT DIMN(a$,2)

Will return 12. 

::

    PRINT DIMN(a$,3)

Will return 0. 

::

    PRINT DIMN(a$(1))

Will return 12. 

::

    PRINT DIMN(a$(1,1))

Will return 1. 

::

    PRINT DIMN(a$(1,1,1)) 

Will cause an 'Out of Range' error.


**CROSS-REFERENCE**

:ref:`len` will return the actual length of characters
held within a string. :ref:`dim` initialises an array.

--------------


..  _dir:

DIR
===

+----------+--------------------------------------------------------------------+
| Syntax   || DIR [#channel,] device  or                                        |
|          || DIR [#channel,] [device] (Toolkit II)  or                         |
|          || DIR \\file [,device] (Toolkit II)                                 |
+----------+--------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                                |
+----------+--------------------------------------------------------------------+

This command produces a listing to the specified channel
(default #1) of all of the files contained on the given device. 

The
listing gives the name of the device (specified with FORMAT) followed by
the number of available sectors/the number of usable sectors; followed
by a list of the files in the order they appear on the disk. If you try
to get a directory of a ram disk, eg. DIR RAM1\_
then the name of the device shown on screen will be RAM1. 

If Toolkit II
is present, and #channel is a window, a <CTRL><F5> keystroke (pausing
output) is generated at the end of each screen full of the listing. You
can however also use the third syntax to output the directory to the
specified file. If file already exists, you will be given the option of
overwriting it. If file doesn't include a device name, the data default
directory is used. 

The Toolkit II variant also supports the default data
directory, which will be used if no device name is given in device, or
if the specified device name would result in the error 'Not Found'. 

If
you have Level-2 or Level-3 device drivers, and there are any
sub-directories (created with MAKE\_DIR) in the given directory, then if
you have Toolkit II present, the names of these sub-directories will
appear with the suffix ->. 

You can then list the contents of these sub-directories by using DIR
with the original device name plus the name of the sub-directory.
Level-3 drivers take this one step further in that after the name of the
disk in the specified device, appears details of the type of disk being
read, ie. MS-DOS or QDOS followed by SD, DD, HD or ED to confirm whether
the disk is Single Density, Double Density, High Density or Extra
Density. RAM disks are listed as QDOS SD.


**Example 1**

With a cartridge in the left hand microdrive slot, 

::

    DIR mdv1_

might produce the following listing in window #1::

    QUILL 102/220 sectors
    boot 
    QUILL 
    install_exe 
    printer_dat


**Example 2**

If Level-2 device drivers are present, 

::

    DIR flp1_ 

might produce the following::

    PSION DISK 1000/2880 sectors 
    QUILL -> 
    ARCHIVE -> 

With Level-3
drivers, you would get the same output except the first line would
become::

    PSION DISK QDOS HD 

::

    DIR 'flp1\_QUILL' 

would on both Level-2 and
Level-3 drivers, then produce the following output::

    PSION DISK 1000/2880 sectors 
    QUILL_boot 
    QUILL_QUILL 
    QUILL_install_exe 
    QUILL_printer_dat


**NOTE 1**

With the Toolkit II variant, the <CTRL><F5> will be generated even where
the channel is a window which has been opened over the network (eg.
n1\_scr\_200x200), which can cause problems as the slave machine will
wait for a key to be pressed! 

This can be avoided if you have the command FIXPF
(provided as part of the QPTR documentation), which will enable you to
re-install the ROM variant of DIR. 

Alternatively write the directory to
a file and copy the file to the host machine, eg. 

::

    DIR \ram1_tmp, flp1_
    SPL ram1_tmp TO n1_scr_200x200

It is even more sophisticated to use a named pipe instead of the
temporary file ram1\_tmp for the same job::

    SPL pipe_dir TO n1_scr_200x200 
    DIR \pipe_dir_1000, flp1_


**NOTE 2**

The THOR XVI retains the original QL ROM variant of this command, which
does not support the default device, nor does it show sub-directory
names.


**NOTE 3**

Unless you have Toolkit II present, the Break key will not have any
effect on DIR. Press Break when the listing pauses at the end of a page
under Toolkit II (Minerva v1.78+ is supposed to recognise the Break key,
but it does not appear to work). The Break key is however recognised in
Minerva v1.97 (at least!).


**NOTE 4**

Prior to Toolkit II v2.25, DIR of a Level-2 device driver could cause
problems when used inside a TURBO compiled program.


**NOTE 5**

If a directory contains a file with a null string as a name (eg. SAVE
flp1\_), this file will not be listed on the directory listing. This was
used as a form of copy protection on some early QL software, but stops
the program from working on a QL with Level-2 or Level-3 Device Drivers
as they use this file to store the main directory!


**NOTE 6**

On some versions of Toolkit II, the third variant could cause problems
if you supply the name of an existing file to store the directory in,
for example::

    DIR \ram1_XDIR

if you said 'N' when asked if it was OK to Overwrite the existing
file - the display would be sent to #0 and #0 would then be CLOSEd!!
v2.49 of Toolkit II (and possibly earlier) does not cause any problems
but does not report an error. v2.85 of SMSQ/E (and possibly earlier)
also has no problems but reports the error 'Already Exists'.


**NOTE 7**

Some people try to divide up DIRectory listings by creating files such
as::

    SAVE 'flp1_----------------'

However, DIR will only list the
files in the order in which they were created if you are using a virgin
disk which has not had other files deleted from it already.


**CROSS-REFERENCE**

:ref:`data-use` sets the current data default
directory, :ref:`make-dir` creates
sub-directories, :ref:`wdir` allows wildcard names.

--------------


..  _discard:

DISCARD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  DISCARD [adr]                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Memory Toolkit (DIY Toolkit Vol H)                               |
+----------+-------------------------------------------------------------------+

This command removes memory which has been allocated with RESERVE
fairly safely, ensuring that the memory had been allocated with RESERVE
and has not already been DISCARDed. If the adr does not point to memory
set aside with RESERVE the error 'not found' is returned.


**CROSS-REFERENCE**

See :ref:`reserve` and
:ref:`linkup`. Also see
:ref:`clchp`, :ref:`rechp` and
:ref:`despr`.

--------------


..  _disp-blank:

DISP\_BLANK
===========

+----------+--------------------------------------------+
| Syntax   | DISP\_BLANK [xblank][,yblank]              |
+----------+--------------------------------------------+
| Location | QVME (Level E-19 Drivers onwards),         |
|          | SMSQ/E for Atari ST & TT (QVME cards only) |
+----------+--------------------------------------------+

The Atari range of computers can be attached to a wide range of
monitors, some of which are able to display higher resolutions than
others. A 17" multi-sync monitor, for example, can display resolutions
of up to 1024x1024 (depending on make). 

The QVME card is unable to
detect the various parameters related to monitors and therefore allows
you to set your own parameters either from SuperBASIC or by configuring
SMSQ/E. 

This command is used for setting the margins between the
currently displayed QL screen and the edges of the monitor. This
difference is known as the overscan (pixels available on the monitor
which are currently unused). xblank sets the number of horizontal pixels
x2 from the edge of the monitor to the left hand side of the QL screen.

The standard value for a 512x256 screen is 128 pixels (a standard QL
monitor linked to an Atari can display a screen 640x480) (640-512)/2=64
pixels from the left hand side of the monitor. 

If xblank is omitted or 0, then the original value is left unaltered. 

Yblank sets the number of lines x 0.5 from the top of the monitor to the top edge of the QL
screen. The standard value is 56, which gives a top margin of
(480-256)/2=112 pixels from the top of the screen. If yblank is omitted
or 0, then the original value is left unaltered.


**NOTE 1**

If you use DISP\_SIZE to alter the size of the displayed QL screen, it
will automatically adjust the parameters for the overscan.


**NOTE 2**

If the y parameter is used to alter the number of blank lines, this will
override any setting of the line scan rate with DISP\_RATE.


**CROSS-REFERENCE**

:ref:`disp-size` allows you to pass these
parameters at the same time as amending the size of the displayed QL
screen. :ref:`disp-rate` sets the frame and
line scan rates for the display - if this command is used to adjust the
line scan rate, this will alter the totoal number of lines. 

Both SMSQ/E
and QVME include programs to allow you to try out the various settings
for the various DISP\_... commands.

--------------


..  _disp-inverse:

DISP\_INVERSE
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  DISP\_INVERSE status                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Atari ST & TT                                         |
+----------+-------------------------------------------------------------------+

The Atari range of computers support a high resolution (640x400)
monochrome display mode which can be supported under SMSQ/E and SMS2. If
SMSQ/E or SMS2 is running on an Atari ST connected to a monochrome
monitor (or running on an Atari TT conected to such a monitor, without
QVME), then it will automatically start up by loading the monochrome
display driver (if available) and set the QL into the monochrome 640x400
display mode. The QL screen can then appear either as white ink on a
black background or black ink on a white background. DISP\_INVERSE
allows you to invert the QL display, with status=0
giving the default white on black and status=1 the black on white
display.


**NOTE**

This command is not available on SMS2.


**CROSS-REFERENCE**

:ref:`disp-type` allows you to find out if the
monochrome display driver is running.
:ref:`inverse` allows you to print in inverse
colours.

--------------


..  _disp-rate:

DISP\_RATE
==========

+----------+--------------------------------------------+
| Syntax   | DISP\_RATE [frame\_scan][,line\_scan]      |
+----------+--------------------------------------------+
| Location | QVME (Level E-19 Drivers onwards),         |
|          | SMSQ/E for Atari ST & TT (QVME cards only) |
+----------+--------------------------------------------+

Due to the multitude of monitors which are available for the Atari ST
range, it is necessary to be able to alter the horizontal and vertical
scan rates (default = 50Hz, the setting on standard QL monitors). 

The
first parameter specifies the frame rate (the horizontal scan rate), a
setting of 70 (or more) will reduce flicker on most Atari monitors. If
omitted or 0, the original value is unchanged. 

The second parameter
specifies the line rate (the vertical scan rate), although this is
normally not required as it is equal to the frame rate multiplied by the
total number of lines. If this parameter is omitted or zero, the
original is recalculated by reference to the number of lines and the
frame rate. 

The total number of lines and line rate can be calculated by
reference to the following program:: 

    100 INPUT #0,'Enter y size of QL screen (DISP_SIZE) ';QLy 
    110 INPUT #0,'Enter horizontal frame rate (DISP_RATE) ';Frate 
    120 INPUT #0,'Enter vertical blank pixels setting (DISP_BLANK) ';Blanky 
    130 Total_y=QLy+Blanky 
    140 total_lines=Total_y*(Qly/QLy) 
    150 PRINT 'The total number of displayed lines will be ';total_lines 
    160 PRINT 'Line scan rate will be ';total_lines*Frate

If you use DISP\_RATE to set the line scan rate, then using the total
number of lines (and hence the blank lines) are recalculated, using the
following routine::

    100 INPUT #0,'Enter y size of QL screen (DISP_SIZE) ';QLy 
    110 INPUT #0,'Enter horizontal frame rate (DISP_RATE) ';Frate 
    120 INPUT #0,'Enter vertical line scan rate (DISP_RATE) ';Lrate 
    130 Total_y=INT(Lrate/Frate) 
    140 PRINT 'Blank Lines for DISP_BLANK will be ';Total_y-QLy


**CROSS-REFERENCE**

:ref:`disp-size` allows you to pass these
parameters at the same time as amending the size of the displayed QL
screen. :ref:`disp-blank` sets the number of
horizontal and vertical blank pixels on the edge of the display. 

Both
SMSQ/E and QVME include programs to allow you to try out the various
settings for the DISP\_... commands.

--------------


..  _disp-size:

DISP\_SIZE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DISP\_SIZE                                                       |
+----------+-------------------------------------------------------------------+
| Location |  QVME (Level E-19 Drivers onwards), SMSQ/E                        |
+----------+-------------------------------------------------------------------+

This command lets you alter the size of the QL screen being displayed.

The first two parameters allow you to specify the display width in
pixels and the height in lines (the normal QL display is DISP\_SIZE
512,256). The remaining four parameters are those which can be set using
the DISP\_RATE and DISP\_BLANK commands respectively. The effect of the
first two parameters depends upon the system it is being used on:

**Extended Mode4 Emulator**

Any width up to 512 will select the standard QL resolution. Any width
over 512 will select the extended resolution (768x280).

**QVME, QXL and QPC**

The width and height of the display can only be altered in increments of
32 pixels and 8 lines respectively. If width is not a multiple of 32 or
height is not a multiple of 8, they are made into the nearest feasible
size. The minimum size is 512x256 pixels.


**NOTE 1**

If you try to use DISP\_SIZE to specify both the line rate and the
number of blank lines, the line rate is ignored and calculated according
to the internal formula (see DISP\_RATE).


**NOTE 2**

DISP\_SIZE will not work if you have already used the A\_OLDSCR
command.


**NOTE 3**

Some combinations of Super Gold Card and AURORA may cause the internal
QL clock to run too quickly unless you follow DISP\_SIZE by PROT\_DATE 0.


**NOTE 4**

This command has no effect if your implementation of the QL does not
support higher resolution displays.


**NOTE 5**

Using higher resolution displays will affect the location of the start
of the screen (see SCR\_BASE) - using DISP\_SIZE 512,256 to set the
display size back to the normal QL resolution will not set the base of
the screen back to 131072 (the normal screen base on a standard QL). See
A\_OLDSCR.


**NOTE 6**

Be careful when reducing screen resolution size - windows are not
resized and therefore you may not be able to see all of a program's
windows, or the SuperBASIC cursor!!


**CROSS-REFERENCE**

All of these parameters can be configured in SMSQ/E so that they are
available immediately on start-up. See
:ref:`disp-rate` and
:ref:`disp-blank`.

--------------


..  _disp-type:

DISP\_TYPE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DISP\_TYPE                                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function returns a number which allows you to find out the type of
display driver which is currently being used. The values returned are:

- 0 Original ST QL Emulator, QL Hardware (either of these two may support
  MODE 8) plus QXL and QPC. All of these (except the original ST QL
  emulator) may support higher resolutions. 
- 1 Extended Mode 4 Emulator (either 512x256 or 768x280 pixel screen) 
- 2 QVME Mode 4 Emulator
- 4 Monochrome display (only two colours)


**CROSS-REFERENCE**

See :ref:`disp-inverse`.
:ref:`machine` and
:ref:`processor` allow you to find out more
about the hardware which a program is being run on.

--------------


..  _disp-update:

DISP\_UPDATE
============

+----------+------------------+
| Syntax   | DISP\_UDPATE x,y |
+----------+------------------+
| Location | QXL (SMSQ only)  |
+----------+------------------+

This is an undocumented command and it is uncertain what its parameters do - it affects the rate at which the screen is updated on the QXL. The higher x and y, the faster that the screen is updated (and hence the smoother the graphics), although this also slows down the other parts of the QXL. If x and y are equal to 0, the screen is only updated when you press a key - this allows the QXL to perform complex maths routines very quickly (so long as they do not access the screen).

**NOTE 1**

Prior to SMSQ/E v2.65 if you used DISP\_UPDATE with a parameter larger
than 1 in MODE 8, this could cause problems on screen.


**NOTE 2**

Using parameters smaller than 0 could lock up some versions of QXL.
SCR\_PRIORITY is similar under Amiga QDOS.

--------------


..  _display-width:

DISPLAY\_WIDTH
==============

+----------+-------------------------------------------------------------------+
| Syntax   | bytes_in_a_line = DISPLAY\_WIDTH                                  |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function can be used to determine how many bytes of the QL's memory are used to hold the data in one line of pixels on the screen. Note that the value returned has nothing to do with any *window* width, it always refers to the total *screen* display width.

Why include this function I hear you think? If you run an ordinary QL, then the result will probably always be 128 as this is how many bytes are used to hold a line of pixels, however, many people use Atari ST/QLs, QXL etc and these have a number of other screen modes for which 128 bytes is not enough. 

This function will return the exact number of bytes required to step from one line of pixels to the next. Never assume that QDOS programs will only ever be run on a QL. What will happen when new Graphics hardware or emulators arrive? This function will still work, assuming that the unit uses standard QDOS channel definition blocks etc.

For the technically minded, the word at offset $64 in the SCR\_ or CON\_ channel's definition block is returned. This is called SD\_LINEL in 'Tebby Speak' and is mentioned in Jochen Merz's *QDOS Reference Manual* and the *QL Technical Manual* by Tony Tebby et al. Andrew Pennel's book, the *QDOS Companion* gets it wrong on page 61, guess which one I used first!


-------


..  _div:

DIV
===

+----------+-------------------------------------------------------------------+
| Syntax   |  x DIV y                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This operator returns the integer part of x divided by y. 

If x or y is
not an integer, then the given value is rounded to the nearest integer
(compare INT). 

On non-SMS implementations the answer and both parameters
must lie within the range -32768...32767. 

On SMS, the answer and both
parameters can lie anywhere within roughly -2e9...2e9 (32-bit numbers).

The result of the operation is always rounded down to the next integer
ie. x DIV y=INT(x/y). Although this leads to some unexpected results
with negative numbers this is so that the formula: x=y\*(x DIV y)+(x MOD
y) is always true.

If you wish to use 32-bit numbers on non SMS systems,
you will need to use the formula: PRINT INT(x/y) instead of PRINT x DIV
y if either x or y is outside of the specified range.


**Examples**

::

    PRINT 13 DIV 5

gives the result 2 (13 divided by 5 is 2.6) 

::

    PRINT 13.4 DIV 1.5

gives the result 6 (13 DIV 2). 

::

    PRINT -13 DIV 5

gives the result -3


**NOTE**

DIV has problems with the value -32768: PRINT -32768 DIV -1
gives the result -32768 on most implementations. On Minerva v1.76 (or
later) it gives the correct result, being an overflow error (the answer
is +32768 which cannot be stored as a short integer variable). On SMS
v2.75+, it returns the value +32768 as DIV can handle the larger
numbers!!


**CROSS-REFERENCE**

:ref:`mod` returns the modulus of x divided by y. Also
please see the alternative version of :ref:`div`.

--------------


DIV
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DIV (x,y)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function returns x/y as an integer in the same way as the ROM
based DIV operator. However, this version is not limited to 16-bit
integers (-32768..32767). It will happily handle 32-bit integer numbers
(-INTMAX..INTMAX, roughly -1E9..1E9). Division by zero is not defined
and will produce an overflow message.


**Example**

::

    PRINT -40000 DIV 3

will produce an error on a standard QL ROM. Instead, you can now use::

    PRINT DIV(-40000,3)

which gives the correct result.


**NOTE 1**

Both variants of DIV can be used in the same program, although the Turbo
and Supercharge compilers will not accept this version.


**NOTE 2**

If you try to use a program compiled under Turbo or Supercharge after
loading the Math Package, if the program uses the normal SuperBASIC
operator MOD or DIV, an error will be generated and the program will
refuse to work!


**CROSS-REFERENCE**

:ref:`mod` (as an operator or a function) returns the
remainder of a division. Compare the other version of
:ref:`div`.

--------------



..  _dj-open:

DJ\_OPEN
========

+----------+-------------------------------------------------------------------+
| Syntax   | channel = DJ\_OPEN('filename')                                    |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Open an existing file for exclusive use. See :ref:`dj-open-dir` below for details and examples.

**CROSS-REFERENCE**

:ref:`dj-open-in`, :ref:`dj-open-new`, :ref:`dj-open-over`, and :ref:`dj-open-dir`.


-------



..  _dj-open-in:

DJ\_OPEN\_IN
============

+----------+-------------------------------------------------------------------+
| Syntax   | channel = DJ\_OPEN\_IN('filename')                                |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Open an existing file for shared use. The same file can be opened by other applications running at the same time. Provided they have a compatible non-exclusive OPEN mode. See :ref:`dj-open-dir` below for details and examples.

**CROSS-REFERENCE**

:ref:`dj-open`, :ref:`dj-open-new`, :ref:`dj-open-over`, and :ref:`dj-open-dir`.


-------



..  _dj-open-new:

DJ\_OPEN\_NEW
=============

+----------+-------------------------------------------------------------------+
| Syntax   | channel = DJ\_OPEN\_NEW('filename')                               |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Create a new file for exclusive use. See :ref:`dj-open-dir` below for details and examples.

**CROSS-REFERENCE**

:ref:`dj-open`, :ref:`dj-open-in`, :ref:`dj-open-over`, and :ref:`dj-open-dir`.


-------



..  _dj-open-over:

DJ\_OPEN\_OVER
==============

+----------+-------------------------------------------------------------------+
| Syntax   | channel = DJ\_OPEN\_OVER('filename')                              |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Open existing file but overwrite all the contents. See :ref:`dj-open-dir` below for details and examples.

**CROSS-REFERENCE**

:ref:`dj-open`, :ref:`dj-open-in`, :ref:`dj-open-new`, and :ref:`dj-open-dir`.


-------



..  _dj-open-dir:

DJ\_OPEN\_DIR
=============

+----------+-------------------------------------------------------------------+
| Syntax   | channel = DJ\_OPEN\_DIR('filename')                               |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

All of these DJ\_OPEN functions return the SuperBasic channel number if the channel was opened without any problems, or, a negative error code otherwise. You can use this to check whether the open was successful or not. 

The filename must be supplied as a variable name, file$ for example, or in quotes, 'flp1_fred_dat'.

They all work in a similar manner to the normmal SuperBasic OPEN procedures, but, DJ\_OPEN\_DIR offers a new function not normally found on a standard QL.

**DJToolkit Author's Note**

I am grateful to Simon N. Goodwin for his timely article in *QL WORLD volume 2, issue 8* (marked Vol 2, issue 7!!!). I had been toying with these routines for a while and was aware of the undocumented QDOS routines to extend the SuperBasic channel table. I was, however, not able to get my routines to work properly. Simon's article was a great help and these functions are based on that article. Thanks Simon.

**EXAMPLE**

The OPEN routines work as follows::

    1000 REMark open our file for input
    1010 :
    1020 chan = DJ_OPEN_IN('filename')
    1030 IF chan < 0
    1040    PRINT 'OOPS, failed to open "filename", error ' & chan
    1050    STOP
    1060 END IF
    1070 :
    1080 REM process data in file here ....

DJ\_OPEN\_DIR is a new function to those in the normal QL range, and it works as follows::

    1000 REMark read a directory
    1010 :
    1020 INPUT 'Which device ';dev$
    1030 chan = DJ_OPEN_DIR(dev$)
    1040 IF chan < 0
    1050    PRINT 'Cannot open ' & dev$ & ', error ' & chan
    1060    STOP
    1070 END IF
    1080 :
    1090 CLS
    1100 REPeat dir_loop
    1110   IF EOF(#chan) THEN EXIT dir_loop
    1120   a$ = FETCH_BYTES(#chan, 64)
    1130   size = CODE(a$(16)):       REMark Size of file name
    1140   PRINT a$(17 TO 16 + size): REMark file name
    1150 END REPeat dir_loop
    1160 :
    1170 CLOSE #chan
    1180 STOP

In this example, no checks are done to ensure that the device actually exists, etc. You could use :ref:`dev-name` to check if it is a legal device. The data being read from a device directory file must always be read in 64 byte chunks as per this example.

Each chunk is a single directory entry which holds a copy of the file header for the appropriate file. Note, that the first 4 bytes of a file header hold the actual length of the file but when read from the directory as above, the value if 64 bytes too high as it includes the length of the file header as part of the length of a file.

The above routine will also print blank lines if a file has been deleted from the directory at some point. Deleted files have a name length of zero.

Note that if you type in a filename instead of a device name, the function will cope. For example, you type in 'flp1\_fred' instead of 'flp1\_'. You will get a list of the files on 'flp1\_' if 'fred' is a file, or even, if 'fred' is not on 'flp1\_'. If, however, you have the LEVEL 2 drivers (see :ref:`level2` below), and 'fred' is a sub-directory then you will get a listing of the sub-directory as requested.
    
**CROSS-REFERENCE**

:ref:`dj-open`, :ref:`dj-open-in`, :ref:`dj-open-new`, and :ref:`dj-open-over`.


-------


..  _djtk-ver-dlr:

DJTK\_VER$
==========

+----------+-------------------------------------------------------------------+
| Syntax   | v$ = DJTK\_VER$                                                   |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This simply sets v$ to be the 4 character string  'n.nn'  where this gives the version number of the current toolkit. If you have problems, always quote this number when requesting help.

**EXAMPLE**

::

    PRINT DJTK_VER$

-------


..  _dline:

DLINE
=====

+----------+-------------------------------------------------------------------------+
| Syntax   || DLINE [#ch,] [range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*`](Not SMS) |  
|          || DLINE [range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*`](SMS Only)       |
+----------+-------------------------------------------------------------------------+
| Location || QL ROM                                                                 |
+----------+-------------------------------------------------------------------------+

This command deletes a given range of lines from the current SuperBASIC
program. The range of lines is as per the LIST command. If an empty
range (for example DLINE) is specified, no action is taken. When the
lines have been deleted, except under SMS, the current listed lines are
re-shown in the given channel (default #2), although we cannot see any
reason why you would wish this to happen on another channel! On SMS this
command has no effect on the display.


**NOTE 1**

DLINE TO is expanded to DLINE 1 TO 32767.


**NOTE 2**

Only Minerva v1.96+ rejects invalid channel parameters.


**NOTE 3**

On Minerva pre v1.98, DLINE to the last line could crash the QL!


**CROSS-REFERENCE**

:ref:`edit` and :ref:`auto` allow
you to enter lines. :ref:`list` allows you to view
program lines.

--------------


..  _dlist:

DLIST
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DLIST [#channel]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command lists all three current default directories (otherwise
returned by the DATAD$, PROGD$ and DESTD$ functions) to the specified
channel (default #1).


**Example**

::

    DLIST

possible Output::

    flp1_Quill_letters_ 
    ram1_ 
    par


**NOTE**

Some Toolkit II manuals mention a second syntax: DLIST \\file
but it seems as though this was never implemented. This should not be a
problem since programs can read the same information from the DATAD$,
PROGD$ and DESTD$ functions.


**CROSS-REFERENCE**

:ref:`datad-dlr`
(:ref:`data-use`),
:ref:`progd-dlr`
(:ref:`prog-use`),
:ref:`destd-dlr`
(:ref:`spl-use` or
:ref:`dest-use`),
:ref:`ddown`, :ref:`dup` Compare
:ref:`devlist` and
:ref:`dev-list`.

--------------


..  _dmedium-density:

DMEDIUM\_DENSITY
================

+----------+--------------------------------------+
| Syntax   || DMEDIUM\_DENSITY [(#channel)] or    |
|          || DMEDIUM\_DENSITY (\\file)           |
+----------+--------------------------------------+
| Location || SMSQ/E v2.73+                       |
+----------+--------------------------------------+

This function returns a number representing the density of the medium
on which the specified file or directory is located, or to which the
specified channel is open. If no parameter is specified, it looks to
channel #3 (or #1 if #3 is not open). An error will occur if the
specified channel is not open or the given file does not exist. 

The value returned is: 

- 0 Non-directory device 
- 1 Double Density 
- 2 High Density
- 3 Extra Density 
- 255 Hard disk or ram disk as they have no density.


**Example**

::

    PRINT DMEDIUM_DENSITY(\flp1_)


**CROSS-REFERENCE**

:ref:`dmedium-name-dlr` gives the name of the
disk attached to the specified channel.
:ref:`dmedium-rdonly` and
:ref:`dmedium-format` are also useful.

--------------


..  _dmedium-drive-dlr:

DMEDIUM\_DRIVE$
===============

+----------+-------------------------------------------------------------------+
| Syntax   || DMEDIUM\_DRIVE$ [(#channel)] or                                  |
|          || DMEDIUM\_DRIVE$ (\\file)                                         |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns the three letter code representing the device
connected to the specified channel or file. If no parameter is specified
then it tries #1, unless channel #3 is open in which case it will access
#3. If an error occurs, for example you specify a channel which is not
open or a file which does not exist, then an error will occur. Luckily
due to the fact that directories are stored in files under Level-2 and
Level-3 drivers, this means that you can use:: 

    PRINT DMEDIUM_DRIVE$(\flp2_) 

if you wish. If the specified channel is not
open to a directory device then an empty string will be returned.


**NOTE 1**

This function does not appear to work 100%, for example on Falkenberg
hard disk interfaces it returns 'WINq' - however you can get around this
by copying the returned string to another variable and only looking at
the first three letters, for example::

    DRV$=DMEDIUM_DRIVE$ 
    IF DRV$<>"":PRINT DRV$( TO 3)


**NOTE 2**

This function will ignore the dev\_ device, returning the three letter
name of the device to which dev points, for example::

    DEV_USE 1,'flp1_quill_' 
    drv$=DMEDIUM_DRIVE$(\DEV1_) 
    IF drv$<>'':PRINT drv$(to 3)

Compare::

    PRINT DMEDIUM_DRIVE$(\DEV1_)


**CROSS-REFERENCE**

:ref:`dmedium-name-dlr` allows you to find out
the name of the disk in the specified drive.

--------------


..  _dmedium-format:

DMEDIUM\_FORMAT
===============

+----------+-------------------------------------------------------------------+
| Syntax   || DMEDIUM\_FORMAT [(#channel)] or                                  |
|          || DMEDIUM\_FORMAT (\\file)                                         |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns a number representing the operating system under
which the medium (or hard disk partition) on which the specified file or
directory is located (or to which the specified channel is open) was
created. If no parameter is specified, it looks to channel #3 (or #1 if
#3 is not open). 

The values returned currently are: 

- 1 QDOS or SMSQ or SMSQ/E 
- 2 DOS or TOS


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 255.


**CROSS-REFERENCE**

:ref:`dir` will provide this imformation also on
Level-3 device drivers.
:ref:`dmedium-density` allows you to
check the medium's density. There is currently no way to format a disk
in a format other than QDOS or SMSQ/E without the ATARI\_rext commands
which were available with the ST/QL emulators from Jochen Merz, or
without specialist software (some of which is public domain).

--------------


..  _dmedium-free:

DMEDIUM\_FREE
=============

+----------+-------------------------------------------------------------------+
| Syntax   || DMEDIUM\_FREE [(#channel)] or                                    |
|          || DMEDIUM\_FREE (\\file)                                           |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns the number of free sectors available on the
medium on which the specified file or directory is located, or to which
the specified channel is open. If no parameter is specified, it looks to
channel #3 (or #1 if #3 is not open).


**CROSS-REFERENCE**

:ref:`dmedium-total` allows you to find
out the total number of sectors available on the related medium.
:ref:`dir` can also be used to obtain this
information.

--------------


..  _dmedium-name-dlr:

DMEDIUM\_NAME$
==============

+----------+-------------------------------------------------------------------+
|Syntax    || DMEDIUM\_NAME$ [(#channel)] or                                   |
|          || DMEDIUM\_NAME$ (\\file)                                          |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns the name which was given to the medium on which
the specified file or directory is located (or to which the specified
channel is open), when that medium was FORMATted. If no parameter is
specified, it looks to channel #3 (or #1 if #3 is not open).


**Example**

A routine to re-format a floppy disk with the same details as previously
allocated to that disk (except for the files). The drive to format (eg.
flp1\_) can be passed with or without quotes, due to the use of line
120::

    100 DEFine PROCedure RE_FORMAT(drv) 
    110   v$=VER$:IF v$<>'HBA':PRINT #0,'NOT SUPPORTED':PAUSE:RETurn 
    120   drv$=PARSTR$(drv,1)
    130   CH=FOPEN(drv$) 
    140   IF CH<0:PRINT #0,'File Error - cannot access drive':PAUSE:RETurn 
    150   IF DMEDIUM_RDONLY(#CH) 
    160     PRINT #0,'Disk Write Protected, cannot proceed':PAUSE 
    170     CLOSE #CH:RETurn 
    180   END IF 
    190   dname$=DMEDIUM_NAME$(#CH) 
    200   drv_density=DMEDIUM_DENSITY(#CH) 
    210   IF DMEDIUM_FORMAT(#CH)<>1 
    220     PRINT #0,'Not QDOS / SMSQE disk, cannot proceed':PAUSE 
    230     CLOSE #CH:RETurn 
    240   END IF 
    250   IF DMEDIUM_TYPE(#CH)<>1 
    260     PRINT #0,'This routine only supports floppy disks!!':PAUSE 
    270     CLOSE #CH:RETurn 
    280   END IF 
    290   CLOSE #CH 
    300   IF LEN(dname$)>10:dname$=dname$(1 TO 10) 
    310   SELect ON drv_density 
    320     =1:dname$=dname$&'*D' 
    330     =2:dname$=dname$&'*H' 
    340     =3:dname$=dname$&'*E' 
    350   END SELect 
    360   FORMAT drv$&dname$ 
    370 END DEFine

Usage::

    REMark Without quotes:
    RE_FORMAT flp1_

or::

    REMark With quotes:
    RE_FORMAT 'flp2_'


**CROSS-REFERENCE**

The name of a medium is set with :ref:`format`. You
can read it with :ref:`dir` also.

--------------


..  _dmedium-rdonly:

DMEDIUM\_RDONLY
===============

+----------+-------------------------------------------------------------------+
|Syntax    || DMEDIUM\_RDONLY [(#channel)] or                                  |
|          || DMEDIUM\_RDONLY (\\file)                                         |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns the value 1 (true) if the the medium on which the
specified file or directory is located (or to which the specified
channel is open) is write-protected either through hardware or software
control. If no parameter is specified, it looks to channel #3 (or #1 if
#3 is not open). If the medium can be written to, the value returned is
zero.


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 1.


**CROSS-REFERENCE**

See :ref:`dmedium-name-dlr` for an example.

--------------


..  _dmedium-remove:

DMEDIUM\_REMOVE
===============

+----------+-------------------------------------------------------------------+
| Syntax   || DMEDIUM\_REMOVE [(#channel)] or                                  |
|          || DMEDIUM\_REMOVE (\\file)                                         |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns the value 1 (true) if the medium on which the
specified file or directory is located (or to which the specified
channel is open) is a removeable hard disk. Otherwise it returns 0
(false). If no parameter is specified, it looks to channel #3 (or #1 if
#3 is not open).


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 1.


**CROSS-REFERENCE**

:ref:`dmedium-rdonly` allows you to check
if a disk is write- protected. There do not appear to be any ways in
which you can check if any channels are currently open to the medium
(ie. whether it is safe to remove the disk), except for listing all
currently open channels, see :ref:`channels`.

--------------


..  _dmedium-total:

DMEDIUM\_TOTAL
==============

+----------+-------------------------------------------------------------------+
| Syntax   || DMEDIUM\_TOTAL [(#channel)] or                                   |
|          || DMEDIUM\_TOTAL (\\file)                                          |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns the number of total sectors available on the
medium on which the specified file or directory is located, or to which
the specified channel is open. If no parameter is specified, it looks to
channel #3 (or #1 if #3 is not open).


**CROSS-REFERENCE**

:ref:`dmedium-free` allows you to find out
the number of sectors which currently do not contain any data on the
related medium. :ref:`dir` can also be used to obtain
this information. :ref:`format` releases all
sectors on a disk, marking any which may be corrupt as unavailable.

--------------


..  _dmedium-type:

DMEDIUM\_TYPE
=============

+----------+-------------------------------------------------------------------+
| Syntax   || DMEDIUM\_TYPE [(#channel)] or                                    |
|          || DMEDIUM\_TYPE (\\file)                                           |
+----------+-------------------------------------------------------------------+
| Location || SMSQ/E v2.73+                                                    |
+----------+-------------------------------------------------------------------+

This function returns a number representing the type of drive on which
the specified file or directory is located (or to which the specified
channel is open). If no parameter is specified, it looks to channel #3
(or #1 if #3 is not open). 

The values currently returned are: 

- 0 RAM disk
- 1 Floppy disk drive 
- 2 Hard disk drive 
- 3 CD-ROM drive


**NOTE**

This function does not appear to work on Falkenberg hard disk interfaces
where it always returns 255.


**CROSS-REFERENCE**

See :ref:`dmedium-name-dlr` for an example.

--------------


..  _dnext:

DNEXT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DNEXT subdirectory                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to move across a directory tree by replacing
the current sub-directory with the specified subdirectory in the default
data device. 

If the default program device is the same as the default
data device, then this will also be altered by DNEXT. 

If the default
destination device is a directory device (ie. if it ends with an
underscore), DNEXT also alters the last sub-directory in this (whether
or not it points to another drive, or is further down the directory
tree). 

::

    win1_
    win1_C_
    win1_C_include_
    win1_C_objects_
    win1_BASIC_
    win1_QUILL_
    win1_QUILL_letters_
    win1_QUILL_translations
    win1_secret_

The above could be a directory tree on a hard disk. DATA\_USE
win1\_C\_ defines win1\_C\_ as the default directory device, so WDIR
will list all of the files in win1\_C\_. 

Assuming that
PROGD$='win1\_BASIC\_' and DESTD$='flp2\_C\_Include\_', entering DNEXT
Quill will result in the following: 

- DATAD$='win1\_Quill\_'
- PROGD$='win1\_BASIC\_' 
- DESTD$='flp2\_C\_Quill\_'


**NOTE 1**

DNEXT does not check if there are any files with the given prefix which
exist.


**NOTE 2**

DNEXT breaks with error -17 (error in expression) if the parameter is a
resident keyword. So append an underscore to the directory name, eg.
DNEXT NEW\_, or specify the parameter between quote marks (eg. DNEXT
'NEW').


**NOTE 3**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to extend them beyond this will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

:ref:`dup` moves up the tree,
:ref:`ddown` moves down the tree.
:ref:`datad-dlr` and :ref:`dlist`
can be used to find out about the current sub-directory and default
devices respectively.

--------------


..  _do:

DO
==

+----------+-------------------------------------------------------------------+
| Syntax   |  DO [device\_] filename                                           |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to execute a set of commands stored in a file
(acting as an overlay). 

It is intended to perform tasks dictated by a
numberless file, which enables you to do many things whilst releasing
memory once the tasks have been performed. 

DO is actually very similar to the Toolkit II variant MERGE
and will ensure that if the given file only contains numberless lines,
the channel is closed afterwards. 

It does however work just as well as MERGE on numbered files! 

A numberless program is basically a set of
SuperBASIC lines which do not have any line numbers. These can therefore
best be entered with the aid of an editor program. Each line is loaded
into the QL with the relevant command, and then executed (one line at a
time), as if they had been entered from the command line (#0). 

This therefore means that although they can call resident SuperBASIC
PROCedures and FuNctions, you can only have in-line structures, such as
IF...END IF and SELect ON...END SELect. 

Once each line has been
executed, it is lost and the memory occupied by that line released. 

One
advantage for pre JS ROMs is that if you use a numberless file to link
resident keywords, such keywords can then be used in the same program
which MERGEd the numberless file. For example, if you have a numberless
file flp1\_resident\_bas such as::

    a=RESPR(12000) 
    LBYTES flp1_Toolkit,a: CALL a

you can then link and use the Toolkit commands in the same program by
including a line such as:: 

    110 DO flp1\_resident\_bas


**NOTE**

On at least v2.28-v2.49 of Toolkit II, MERGE appears to work much better
than DO at executing numberless files. If DO is entered as a direct
command, none of the numberless lines are executed (compare MERGE which
executes the first line), and if DO
is part of a program, only the first line is executed (compare MERGE
which executes all of the commands in the numberless file). This is
fixed under SMS.


**CROSS-REFERENCE**

Please refer to :ref:`merge`. SMS allows you to
:ref:`exec`\ ute a SuperBASIC program, letting it run
in the background and perform functions on supplied data using pipes or
channels (see :ref:`ex`).

--------------


..  _dos-use:

DOS\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   | DOS\_USE device$                                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

DOS\_USE may be used to set the name of the DOS device. The name should be three characters long, in upper or lower case.

**Example**

::

    DOS_USE mdv 
    
The DOS device is renamed MDV.
    
::
    
    DOS_USE DOS 
    
The DOS device is restored to DOS.
    
::
    
    DOS_USE 
    
The DOS device is restored to DOS.


--------------



..  _dos-drive:

DOS\_DRIVE
==========

+----------+-------------------------------------------------------------------+
| Syntax   | DOS\_DRIVE drive%, directory$                                     |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This changes the directory the DOS device is connected to.

By default, DOS1\_ corresponds to C:\\, DOS2\_ to D:\\ and so on, but the base can be freely chosen in the configuration dialog or even at runtime::

    DOS_DRIVE 2, "C:\WINDOWS" 
    
will assign DOS2\_ to the windows directory on the host's C:\\ drive.

::

    PRINT DOS_DRIVE$(2) 
    
would now return "C:\\WINDOWS".

--------------



..  _dos-drive-dlr:

DOS\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   | directory$ = DOS\_DRIVE$(drive%)                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This reads back the currently connected directory of the DOS device.

**Example** 

If we continue from the example above for :ref:`dos-drive`\ , then::

    PRINT DOS_DRIVE$(2)
    
Will print "C:\\WINDOWS".


--------------



..  _dotlin:

DOTLIN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DOTLIN p1, p2, p3, col, x1, y1, x2, y2                           |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

The command DOTLIN is a variant of LDRAW - it draws a dotted line in
the specified colour col from the absolute co-ordinates (x1,y1) to
(x2,y2). 

The three first parameters are small non-negative integers
which specify after how many pixels the line is to be broken (they are
known as the periods). 

The line is drawn by plotting the first p1
pixels, then leaving a gap of p2 pixels, plotting the next p3 pixels and
once again leaving a gap of p2 pixels before recommencing the pattern.


**Examples**

::

    DOTLIN 10,10,10,3,40,40,200,60

draws a white line from the point (40,40) to the point (200,60) but
only for periods of ten pixels. 

If a pixel is represented by an asterisk, this would look like this::

    **********          ********** ... 
    |-- 10 --||-- 10 --||-- 10 --| ... 


DOTLIN with the periods 3, 5 and 10::

    ***     **********     ***     ********** 
    |3||-5-||---10---||-5-||3||-5-||---10---|

**CROSS-REFERENCE**

All the warnings relevant to SET apply.

--------------


..  _draw:

DRAW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DRAW x1,y1 TO x2,y2 ,colour                                      |
+----------+-------------------------------------------------------------------+
| Location |  Fast PLOT/DRAW Toolkit                                           |
+----------+-------------------------------------------------------------------+

This command draws a line in absolute co-ordinates on the screen. Any
windows and window attributes are ignored. x1 and x2 range from 0 to
511, y1 and y2 from 0 to 255. DRAW uses the screen base address defined
with SCRBASE (which enables it to draw on a screen stored in memory as
well as the currently visible screen. It is therefore compatible with QL
emulators and Minerva's dual screen mode, although it cannot support
higher resolutions). The range for the colour parameter is 0..7, other
values give odd results without being dangerous.


**Example**

Here is a procedure which draws a line given in polar co-ordinates. A
point in a polar system is specified by a radius and angle. 

::

    170 DEFine PROCedure POLAR_DRAW (r1,phi1,r2,phi2,col) 
    180   REMark less precise but fast version 
    190   LOCal r,phi,r_old,phi_old,dr,dphi 
    200   LOCal x1,x2,y1,y2,dist 
    210   r_old=r1: phi_old=phi1 
    220   r=r1: phi=phi1 
    230   x1=1.35*r_old*SIN(phi_old+PI/2)+255 
    240   y1=r_old*COS(phi_old+PI/2)+127 
    250   dist=(r1+r2)/2 * (phi1+phi2)/PI
    260   IF dist==0 THEN RETurn 
    270   dr=(r2-r1)/dist: dphi=(phi2-phi1)/dist
    280   REPeat Drawing 
    290     IF r>=r2 AND phi>=phi2 THEN EXIT Drawing 
    300     r=r_old+dr: phi=phi_old+dphi 
    310     x2=1.35*r*SIN(phi+PI/2)+255 
    320     y2=r*COS(phi+PI/2)+127 
    330     DRAW x1,y1 TO x2,y2 ,col 
    340     r_old=r: phi_old=phi 
    350     x1=x2: y1=y2 
    360   END REPeat Drawing 
    370 END DEFine POLAR_DRAW

::

    POLAR_DRAW 0,0 TO 100,8*PI ,7 

draws an archimedic spiral and these few lines create a polar pattern::

    10 SCLR 0 
    20 FOR a=0 TO 50 STEP 10 
    30 POLAR_DRAW a,0 TO a,2*PI ,7
    40 POLAR_DRAW 0,PI*a/25 TO 50,PI*a/25, 7 
    50 END FOR a 
    60 REFRESH


**NOTE**

DRAW is specific to the resolution of 512x256 pixels. It can however be
used to draw on Minerva's second screen by using the command SCRBASE
SCREEN(#3) (assuming that #3 is open on the second screen).


**CROSS-REFERENCE**

:ref:`plot` plots a pixel,
:ref:`sclr` clears the screen and
:ref:`refresh` makes the screen pointed to by
:ref:`scrbase` visible. See also
:ref:`dotlin` and the other variant of
:ref:`draw`.

--------------


DRAW
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DRAW [#ch,] x2,y2                                                |
+----------+-------------------------------------------------------------------+
| Location |  DRAW (DIY Toolkit - Vol G)                                       |
+----------+-------------------------------------------------------------------+

This command draws a line in absolute co-ordinates on the screen with
reference to the specified window channel (if any - default #1). The
line is drawn from the last point plotted with the PLOT
command from the same toolkit, to the point specified by x2,y2. This is
quicker than using the SuperBASIC LINE command and unlike other similar
commands, it will support the current INK
colour and OVER mode. 

<CTRL><F5> will pause the line drawing and it
will even work in MODE 4, 8 and 12 (on the THOR XVI, provided that you
have v1.6+). The main limitation on this command is that the line must
appear fully within the specified window, so x2 and y2 cannot exceed the
width or height of the specified window (in pixels) nor be less than
zero.


**NOTE**

Although DRAW will work wherever the screen base is located, it assumes
that a line of pixels takes 128 bytes - it will not therefore currently
work on higher resolutions.


**CROSS-REFERENCE**

See the other variant of\ :ref:`draw`. See also
:ref:`plot`. :ref:`line` is much
more flexible.

--------------


..  _dround:

DROUND
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DROUND (d, x)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  TRIPRODRO                                                        |
+----------+-------------------------------------------------------------------+

The function DROUND will return the floating point number x
rounded to d decimal digits, counted from the left of the number.
DROUND rounds the last digit up or down depending on the next digit
(ignoring any others).


**Example**

::

    DROUND(3, 1234.56) = 1230 
    DROUND(4, 1234.56) = 1235


**CROSS-REFERENCE**

:ref:`pround` rounds to a given precision.

--------------


..  _dup:

DUP
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DUP                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command strips off the last part of the default data device, thus
moving up the directory tree. If the default program device is the same
as the default data device, then this will also be altered by DUP. If
the default destination device is a directory device (ie. if it ends
with an underscore), DUP also alters this (whether or not it points to
another drive). 

::

    win1_
    win1_C_
    win1_C_include_
    win1_C_objects_
    win1_BASIC_
    win1_QUILL_
    win1_QUILL_letters_
    win1_QUILL_translations
    win1_secret_


If DATAD$ is win1\_, DDOWN Quill moves down to
win1\_Quill\_, whilst DUP will move DATAD$ back up to win1\_. 

If DATAD$
is win1\_Quill\_letters\_secret\_, three DUPs will change it back to
win1\_.


**NOTE**

It is not possible to move beyond the name specifying the actual device
to be used. In the above example, this is the named root, win1\_.


**CROSS-REFERENCE**

:ref:`data-use` allows you to set the absolute
directory root, :ref:`ddown` goes down the tree, and
:ref:`dnext` skips from branch to branch.
:ref:`datad-dlr` returns the current default data
device ie. the device name plus the current sub-directory.

