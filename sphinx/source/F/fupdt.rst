..  _fupdt:

FUPDT
=====

+----------+------------------------------------------------------------------+
| Syntax   | FUPDT [(#channel)] or                                            |
|          |                                                                  |
|          | FUPDT (\\file) (Toolkit II only)                                 |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, BTool                                                |
+----------+------------------------------------------------------------------+

This function returns the date on which a given file was last
amended. The value returned is the date in QDOS format, ie. the number
of seconds since Midnight 1st January 1961. You can check this initial date with::

    PRINT DATE$(0)

The update time is altered whenever a file is created
or amended. A file which has overwritten a previous file or is a copy is
regarded as a new file and will therefore have a different update time
to the original. The default data device and sub-directories are
supported, default channel is #3.

**Example**

It could be interesting to list all files which have been created
during a certain time period. A simple prototype of
a program which will do just that follows on below.

If you want to check all files, then
dev$ should contain no sub-directories or wild cards (just FLP2\_,
WIN1\_) and wild$ an empty string. Such a program could be used to write
an intelligent backup program.

In order to run the program you will need
TinyToolkit's TCONNECT or DIY-TK's QLINK. You could also use similar
commands in the toolkits provided with Turbo or Qliberator.

::

    100 CLS: INPUT "Device:"!dev$ \"Wild card:"!wild$
    110 INPUT "List from (dd mm yy):"!first$
    120 INPUT TO 2;"to (<ENTER>=today):"!last$\
    130 day1=first$(1 TO 2):month1=first$(4 TO 5)
    135 year1=19&first$(7 TO 8)
    140 IF LEN(last$) THEN
    150   day2=last$(1 TO 2):month2=last$(4 TO 5)
    155   year2=19&last$(7 TO 8)
    160 ELSE last=DATE
    170 END IF
    180 DATE_tmp=DATE
    190 SDATE year1,month1,day1,0,0,0: first=DATE
    200 IF LEN(last$): SDATE year2,month2,day2,23,59,58: last=DATE
    210 ADATE DATE_tmp-DATE+2
    220 :
    230 OPEN#3,pipe_10000: OPEN#4,pipe_100
    240 TCONNECT #3 TO #4: WDIR#3,dev$ & wild$
    250 yes=0: yesno=0
    260 REPeat show_those
    270   IF NOT PEND(#4) THEN EXIT show_those
    280   INPUT#4,file$: this=FUPDT(\dev$ & file$): yesno=yesno+1
    290   IF first<=this AND this<=last THEN
    300     PRINT file$;TO 20;"(";DATE$(this);")"
    310     yes=yes+1
    320   END IF
    330 END REPeat show_those
    340 PRINT \"(";yes;"/";yesno!"files)"
    350 CLOSE#3,#4

Minerva or SMS users can delete lines 180,190,200 and 210 and use the
following lines instead::

    190 first=DATE(year1,month1,day1,0,0,0)
    200 IF LEN(last$): last=DATE(year2,month2,day2,23,59,58)

**NOTE 1**

The update time of a file will only be correct if the system clock was
set to the correct time when the file was last written to, since it is
the date contained within the QL's clock which is written to the header
of the file. If your machine has a battery backed real-time clock, then
this presents no real problem; otherwise you will need to ensure that
you set the date and time after each startup.

**NOTE 2**

On some early versions of Toolkit II the machine code FS.RENAME routine
also alters the update time of a file!

**NOTE 3**

There is no legitimate way to change the update time of a file except
with level-2 or level-3 drivers. It is of course possible to set the
system clock temporarily to the desired time, amend the file and then
set the clock back, but as the time taken to change the cannot be
estimated exactly, this method will almost surely reset the system clock
to the incorrect time after carrying out such an operation a few times.
On level-2 and level-3 drivers, SET\_FUPDT can be used.

**NOTE 4**

Minerva automatically updates the update dates of files on microdrives.
Other ROM versions will not do so without Toolkit II.

**CROSS-REFERENCE**

:ref:`fbkdt`, :ref:`flen`,
:ref:`ftyp`, :ref:`fdat`,
:ref:`fxtra`,
:ref:`file-len`,
:ref:`file-type`,
:ref:`fvers` and :ref:`fname-dlr`
return other information about a file. See
:ref:`date` and :ref:`adate`
about handling the system clock and
:ref:`set-fupdt` on setting the time stamp of a
file.

