
==========
Keywords F
==========


TODO
====

- :ref:`ff` references ESC which is not in any source file.


..  _fact:

FACT
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FACT(n) where n=0..300                                           |
+----------+-------------------------------------------------------------------+
| Location |  Math Package, FACT                                               |
+----------+-------------------------------------------------------------------+

The FACT function takes a non-negative integer n up to 300 and
returns the factorial of the number, calculated as the product:
1\*2\*3\*...\*n

**Example**

n elements can be combined in FACT(n) different ways, eg. take the three
first letters, the FACT(3)=6 permutations of A, B and C are: 

1. ABC 
2. ACB 
3. BAC 
4. BCA 
5. CAB 
6. CBA

**CROSS-REFERENCE**

:ref:`binom`

--------------


..  _false-pct:

FALSE%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FALSE%                                                           |
+----------+-------------------------------------------------------------------+
| Location |  TRUFA                                                            |
+----------+-------------------------------------------------------------------+

The function FALSE% returns the constant 0. It is used to write
programs which are more legible or which adopt habits from the PASCAL
language.

**CROSS-REFERENCE**

:ref:`true`. See also :ref:`set` concerning user definable resident constants.

--------------


..  _fastexpand:

FASTEXPAND
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FASTEXPAND adr1,adr2                                             |
+----------+-------------------------------------------------------------------+
| Location |  COMPICT                                                          |
+----------+-------------------------------------------------------------------+

If a screen which has been compressed and saved with COMPRESS is
loaded into memory with LBYTES (for example), this command allows
quicker expansion of the screen than would otherwise be possible with
EXPAND. 

FASTEXPAND also allows you to expand the screen to any address
(provided that there is at least 32K of free memory stored there). adr1
is the address where the compressed screen is stored and adr2 the place
in RAM where the expanded screen should be moved to.

**Example**

::

    100 COMPRESS ram1_test_scr 
    110 a=ALCHP(FLEN(\ram1_test_scr)) 
    120 LBYTES ram1_test_scr,a 
    130 FASTEXPAND a,SCREEN 
    140 RECHP a

**NOTE**

FASTEXPAND will not work on screen resolutions in excess of 512x256
pixels.

**CROSS-REFERENCE**

:ref:`compress`,
:ref:`expand`.

--------------


..  _fbkdt:

FBKDT
=====

+----------+-------------------------------------------------------------------+
| Syntax   || FBKDT [(#channel)] or                                            |
|          || FBKDT (\\file)                                                   |
+----------+-------------------------------------------------------------------+
| Location || Level-2 Device Drivers, SMS                                      |
+----------+-------------------------------------------------------------------+

It is proposed that this function be used to return the date on which
a given file was last backed up. Current versions of SuperBASIC
commands, such as COPY and WCOPY do not set the back-up date of the file
being copied, although some software may do this, WinBack for example. 

The idea of a back-up
date is mainly for use in automatic back-up programs which can be told
to copy all files on a given medium within certain parameters, namely
files which have been altered since a specific date and which have been
altered since the last time that they were backed up. 

The value returned
is the date in QDOS format, ie. the number of seconds since Midnight 1st
January 1961 {check this initial date with PRINT DATE$(0)}. This backup
time currently needs to be set manually using SET\_FBKDT, although it is
hoped that future versions of COPY and WCOPY will do so automatically.

If it has not been set, FBKDT will return zero. The default data device
and sub-directories are supported, default channel is #3.

**Example**

The PROCedure below will make an intelligent backup of
all files contained in the medium specified by the first parameter to
the medium specified in the second parameter, which have been altered
since they were last backed up. TinyToolkit's TCONNECT or DIY-TK's QLINK
is necessary to use this example. This can be used for example by
entering the line::

    BACKUP flp1_ TO flp2_

Although sub-directories and the default data device are fully
supported on the medium being backed-up, the procedures would need
modificication to enable them to create similar sub-directories on the
destination device. The PROCedure makes heavy use of recursive
programming, which means that it uses a lot of memory (not all of which
is released at the end of the PROCedure). It would need a considerable
re-write to be in a form which could be safely compiled. 

::

    100 DEFine PROCedure BACKUP (dir1,dir2) 
    110   LOCal dir1$,dir2$,old_datad$,old_destd$ 
    120   LOCal ERRno,outer,sloop 
    130   dir1$=PARSTR$(dir1,1):dir2$=PARSTR$(dir2,2) 
    140   old_datad$=DATAD$:old_destd$=DESTD$ 
    150   DATA_USE '':ERRno=-7 
    160   REPeat sloop 
    170     IF FTEST(dir1$)<0 
    180       dir1$=old_datad$&dir1$ 
    190       IF FTEST(dir1$)<0:PRINT #0,dir1$;' ';:EXIT sloop 
    200     END IF 
    210     full_dir$=(dir1$&' ')(1 TO 5):orig_dir$=dir1$ 
    220     IF FTEST(dir2$)<0
    230       outer=FOP_NEW(dir2$):IF outer>0:CLOSE #outer 
    240       IF outer<0  
    250         dir2$=old_destd$&dir2$ 
    260         IF old_destd$(LEN(old_destd$))<>'_':ERRno= -15:EXIT sloop 
    270         IF FOP_OVER(dir2$)<0:PRINT #0,dir2$;' ';:EXIT sloop 
    280       END IF 
    290     END IF
    300     ERRno=0:EXIT sloop 
    310   END REPeat sloop 
    320   DATA_USE old_datad$
    330   IF ERRno<0:REPORT ERRno:RETurn 
    340   IF dir2$(LEN(dir2$))<>'_':dir2$=dir2$&'_' 
    350   main_ch=-1:max_ch=0 
    360   read_directory dir1$ 
    370   PRINT #0,'Backup complete' 
    380   FOR i=main_ch TO max_ch:CLOSE #i 
    390 END DEFine 
    400 : 
    410 DEFine PROCedure read_directory(current_dir$) 
    420   LOCal in_ch,out_ch 
    430   in_ch=FOPEN('scr_'):IF main_ch=-1:main_ch=in_ch 
    440   out_ch=FOPEN(pipe_10000):DIR #out_ch,current_dir$ 
    450   TCONNECT #out_ch TO #in_ch 
    460   CLOSE #out_ch 
    470   copy_file$ #in_ch,full_dir$,dir2$ 
    480   IF in_ch>max_ch:max_ch=in_ch 
    490 END DEFine 
    500 :
    510 DEFine PROCedure copy_file$(chan,in$,out$) 
    520   LOCal files_loop,junk$,outer,test1,test2 
    530   INPUT #chan,junk$,junk$ 
    540   REPeat files_loop 
    550     IF EOF(#chan):EXIT files_loop 
    560     INPUT #chan,in_file$ 
    570     out_file$=out$&in_file$ 
    580     in_file$=in$&in_file$ 
    590     IF LEN(in_file$)>3 
    600       IF in_file$(LEN(in_file$)-2 TO)=' ->' 
    610         read_directory in_file$(1 TO LEN(in_file$)-3) 
    620         NEXT files_loop 
    630       END IF 
    640     END IF 
    650     test1=FBKDT(\in_file$) 
    660     outer=FOPEN(out_file$) 
    670     IF outer>0  
    680       test2=FUPDT(#outer):CLOSE #outer 
    690     ELSE 
    700       test2=-7 
    710     END IF 
    720     IF test2<test1 OR test1=0 
    730       PRINT 'Backing-up'!in_file$!'=>'!out_file$
    740       DELETE out_file$:COPY in_file$ TO out_file$ 
    750       SET_FBKDT \in_file$,DATE 
    760     END IF 
    770   END REPeat files_loop 
    775   CLOSE#chan
    780 END DEFine

**CROSS-REFERENCE**

:ref:`fupdt`, :ref:`flen`,
:ref:`ftyp`, :ref:`fdat`,
:ref:`fxtra`,
:ref:`file-len`,
:ref:`file-len`,
:ref:`file-type`,
:ref:`fvers` and :ref:`fname-dlr`
return other information about a file.

--------------


..  _fdat:

FDAT
====

+----------+-------------------------------------------------------------------+
| Syntax   || FDAT [(#channel)] or                                             |
|          || FDAT (\\filename) (Toolkit II and THOR)                          |
+----------+-------------------------------------------------------------------+
| Location ||  Toolkit II, THOR XVI, BTool                                     |
+----------+-------------------------------------------------------------------+

This function returns the value of four bytes (at offset 6 to 9) in a
file header. This value represents the dataspace of executable files
(file type 1). There is no convention for any other file types. The
default data device and sub-directories are supported, the default
channel is #3.

**CROSS-REFERENCE**

:ref:`fxtra` returns the other four bytes of the
type dependent information contained in the file header.
:ref:`file-dat` is very similar to
:ref:`fdat`. See also :ref:`ftyp`.

--------------


..  _fdec-dlr:

FDEC$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FDEC$ (value,length,ndp)                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function is similar to CDEC$ except for two major differences.
FDEC$ does not assume that value is an integer, and therefore uses the
whole of value, although if the given ndp (number of decimal places) is less than 
the number of decimal places in
value, value will be rounded up or down accordingly. 

FDEC$ does not
insert commas in the characters to the left of the decimal point.

**Examples**

::

    PRINT FDEC$(100.235,6,2)

will print '100.24' 

::

    PRINT FDEC$(100,6,2)

will print '100.00'

**CROSS-REFERENCE**

Please see :ref:`cdec-dlr`.

--------------


..  _fetch-bytes:

FETCH\_BYTES
============

+----------+-------------------------------------------------------------------+
| Syntax   | a$ = FETCH\_BYTES(#channel, how\_many)                            |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function  returns the requested  number of bytes from the given channel which must have been opened for INPUT or INPUT/OUTPUT.  It will work on CON\_ channels as well, but no cursor is shown and the characters typed in are not shown on the screen.  If there is an ENTER character, or a CHR$(10), it will not signal the end of input.  The function will not return until the appropriate number of bytes have been read.

WARNING - JM and AH ROMS will cause a 'Buffer overflow' error if more than 128 bytes are fetched, this is a fault with QDOS and not with DJToolkit. See the demos file, supplied with DJToolkit, for a workaround to this problem.

**EXAMPLE**

::

    LineOfBytes$ = FETCH_BYTES(#4, 256)


-------


..  _fexp-dlr:

FEXP$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FEXP$ (value,length,ndp)                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This function is different to CDEC$ in that it always prints the
given value in exponential format. This means that there is always only
one character to the left of the decimal point (plus any sign), and ndp
(number odf decimal places) states how many characters should be to the right 
of the decimal point.

FEXP$ does not assume that value is an integer and therefore also caters
for floating point values. The length of the field must be at least
ndp+7, otherwise an empty string is returned. 

If necessary, values are
rounded up or down to fit in the specified ndp number of decimal places.

**Examples**

::

    PRINT FEXP$(-100.235,11,4) 

will print -1.0023E+02 

::

    PRINT FEXP$$(100.235,11,4) 

will print 1.0024E+02

**CROSS-REFERENCE**

:ref:`cdec-dlr`, :ref:`idec-dlr`,
:ref:`fdec-dlr` and
:ref:`print-using` all provide means of
formatting number output.

--------------


..  _ff:

FF
==

+----------+-------------------------------------------------------------------+
| Syntax   |  FF                                                               |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns CHR$(12), which performs a form feed when sent
to an EPSON compatible printer.

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`enl`, :ref:`pro`,
:ref:`si`, :ref:`nrm`,
:ref:`unl`, :ref:`alt`,
:ref:`esc`, :ref:`lmar`,
:ref:`rmar`, :ref:`pagdis`,
:ref:`paglen`.

--------------


..  _fget-pct:

FGET%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGET% [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads two bytes from #channel (default #1) and makes an
integer value from them, so these bytes should be in the internal format
of an integer to make FGET% useful. 

An integer is stored in two bytes as Integer = Byte1\*256+ byte2

**CROSS-REFERENCE**

See :ref:`get` and :ref:`mki-dlr`.
:ref:`cvi-pct` converts a string containing the internal
format of an integer to an integer number. See also
:ref:`fput-pct`

--------------


..  _fget-dlr:

FGET$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGET$ [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads a string in internal format from a specified
channel (default #1) and returns the string. 

A string is stored
internally as a two byte integer (see FGET%) specifying the length of
the string followed by the characters of the string itself.

**Example**

::

    100 OPEN_NEW#3,ram1_test 
    110 PRINT#3,MKS$("Hello World.") 
    120 FPOS_A#3,0 
    130 PRINT FGET$(#3) 
    140 CLOSE#3 
    150 DELETE ram1_test

**CROSS-REFERENCE**

:ref:`get`, :ref:`fgetb`,
:ref:`fget-pct`, :ref:`fgetl`,
:ref:`mks-dlr`. :ref:`fput-dlr` writes
a string in internal format. :ref:`cvs-dlr` converts a
string into its internal format.

--------------


..  _fgetb:

FGETB
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETB [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads a single byte (character) from a specified
channel (default #1) and returns its numeric value.

**Example**

::

    100 PRINT "Please press any key..." 
    110 CLEAR: c = FGETB 
    120 PRINT "You pressed '";CHR$(c);"', "; 
    130 PRINT "which is code"!c!"($";HEX$(c,8);")."

**CROSS-REFERENCE**

The Toolkit II equivalent is :ref:`bget`. See also
:ref:`fputb`!

--------------


..  _fgetl:

FGETL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETL [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads four bytes, being the internal representation of
a longword, from a specified channel (default #1) and returns the
longword's value.

**Example**

It is preferable to store a large integer in internal format because
this is faster than text representation and needs less memory, even if
the number could be stored in internal float format::

    100 large_int = 1.19344E7 
    110 : 
    120 REMark save value 
    130 OPEN_NEW#3,ram1_test 
    140 PRINT#3,MKL$(large_int) 
    150 CLOSE#3: CLEAR 
    160 : 
    170 REMark read value
    180 OPEN_IN#3,ram1_test 
    190 large_int = FGETL(#3) 
    200 CLOSE#3: PRINT large_int

**CROSS-REFERENCE**

:ref:`lget`, :ref:`mkl-dlr`.
:ref:`fputl` allows you to write numbers in internal
format to channels. :ref:`cvl` converts strings
containing the internal format to long integers.

--------------


..  _fgetf:

FGETF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETF [(#channel)]                                               |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function FGETF gets six bytes from a channel (default #1) in the
internal format of a floating point number.

**WARNING**

FGETF will hang SuperBASIC if the six bytes did not represent a valid
floating point, so be careful.

**CROSS-REFERENCE**

:ref:`get`, :ref:`mkf-dlr`,
:ref:`peek-f`, :ref:`fputf`.
:ref:`cvf` converts a string containing the internal
format into a floating point number.

--------------


..  _fgeth-dlr:

FGETH$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FGETH$ [(#filechan)]                                             |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function reads the file header from an open channel
linked to a file (default #3). 

Each file has a header of 64 bytes
which contains technical information about the file. FGETH$ returns a
string containing 64 characters, each of which represents one byte of 
the file header. The string contains the following information:

+-----------+---------------------------------+--------------------+---------------------+
| Character | Meaning                         | Value in string    | Equivalent Function |
+===========+=================================+====================+=====================+
|  1...4    | file length                     | CVL(h$(1 TO 4))    | FLEN                |
+-----------+---------------------------------+--------------------+---------------------+
|      5    | file access key                 | CODE(h$(5))        | None                |
+-----------+---------------------------------+--------------------+---------------------+
|      6    | file type                       | CODE(h$(6))        | FTYP                |
+-----------+---------------------------------+--------------------+---------------------+
|  7..14    | type dependent info (see below) |                    | FDAT,FXTRA          |
+-----------+---------------------------------+--------------------+---------------------+
| 15..16    | filename length                 | CVI%(h$(15 TO 16)) | LEN(FNAME$)         |
+-----------+---------------------------------+--------------------+---------------------+
| 17..52    | filename bytes                  | CVS$(h$(15 TO 52)) | FNAME$              |
+-----------+---------------------------------+--------------------+---------------------+
| 53..56    | update time                     | CVL(h$(53 TO 56))  | FUPDT               |
+-----------+---------------------------------+--------------------+---------------------+
| 57..58    | version number                  | CVI%(h$(57 TO 58)) | FVERS               |
+-----------+---------------------------------+--------------------+---------------------+
| 59..60    | reserved                        | CVI%(h$(59 TO 60)) | None                |
+-----------+---------------------------------+--------------------+---------------------+
| 61..64    | backup date                     | CVL(h$(61 TO 64))  | FBKDT               |
+-----------+---------------------------------+--------------------+---------------------+

The type dependent information is different for each file type. For
type 1 (executable files) bytes 7 to 10 hold the dataspace: CVL(h$(7 TO
10)). In early documentation, bytes 57 to 60 were reserved for a
reference date which was never implemented. The last eight bytes (57 to
64) are actually not used on level-1 drivers, level-2 drivers use every
byte. There is an *unofficial* standard for the file access key, which is
generally used by Toolkits to store file attributes in the format:

+--------+-------------------------------------------------------------------------------------------------------+
| Bit No | Meaning                                                                                               |
+--------+-------------------------------------------------------------------------------------------------------+
|     7  | Set if the file is read-only.                                                                         |
+--------+-------------------------------------------------------------------------------------------------------+
|     6  | Set if the file is hidden and will not appear on a directory of the disk. Neither can it be accessed. |
+--------+-------------------------------------------------------------------------------------------------------+
| 0 - 5  | are used to contain the User Number. Basically, this file will only be                                |
|        | accessible by someone with the same user number (0-63).                                               |
|        |                                                                                                       |
|        | Files with a                                                                                          | 
|        | user number of 0 will be visible and useable by any user.                                             |
|        |                                                                                                       |
|        | Files with a                                                                                          |
|        | user number of 63 are generally only available to a user in a special                                 |
|        | mode (normally this will require a password).                                                         |
+--------+-------------------------------------------------------------------------------------------------------+

You will need specialist toolkits such as Toolkit III and System, neither of which are
compatible with SMS if the File Access Key is to have any effect.

**Examples**

Nearly every part of a file header (apart from the two unused bytes)
can be read by special functions (see the list above), here are two
functions to read the rest::

    100 DEFine FuNction FACCKEY (chan) 
    110   LOCal h$ 
    120   h$=FGETH$(#chan) 
    130   RETurn CODE(h$(5)) 
    140 END DEFine FACCKEY
    150 :
    160 DEFine FuNction FSPEC% (chan) 
    170   LOCal h$ 
    180   h$=FGETH$(#chan) 
    190   RETurn CVI%(h$(59 TO 60)) 
    200 END DEFine FSPEC%
    

**CROSS-REFERENCE**

:ref:`fseth-dlr` is the counterpart of
:ref:`fgeth-dlr`. :ref:`headr` and
:ref:`gethead` read file headers to given memory
positions, :ref:`fseth-dlr`,
:ref:`heads` and
:ref:`sethead` set them. Functions like
:ref:`flen`, :ref:`ftyp`,
:ref:`fxtra` etc. read the file header implicitly
and return a certain piece of information from it. Use the
:ref:`cvi-pct`, :ref:`cvl` and
:ref:`cvs-dlr` functions to convert the internal
representations to actual values.

--------------


..  _file-backup:

FILE\_BACKUP
============

+----------+------------------------------------------------------------------+
| Syntax   | bk = FILE\_BACKUP(#channel)                                      |
+----------+------------------------------------------------------------------+
| Syntax   | bk = FILE\_BACKUP('filename')                                    |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function reads the backup date from the file header and returns it into the variable bk.  The parameter can either be a channel number for an open channel, or it can be the filename (in quotes) of a closed file.  If the returned value is negative, it is a normal QDOS error code.  If the value returned is positve, it can be  converted to a string be calling DATE$(bk). In normal use, a files backup date is never set by QDOS, however, users who have WinBack or a similar backup utility program will see proper backup dates if the file has been backed up.

**EXAMPLE**

::

    1000 bk = FILE_BACKUP('flp1_boot')
    1010 IF bk <> 0 THEN
    1020    PRINT "Flp1_boot was last backed up on " & DATE$(bk)
    1030 ELSE
    1040    PRINT "Flp1_boot doesn't appear to have been backed up yet."
    1050 END IF

**CROSS-REFERENCE**

:ref:`file-dataspace`, :ref:`file-length`, :ref:`file-type`, :ref:`file-update`.


-------


..  _file-dat:

FILE\_DAT
=========

+----------+-------------------------------------------------------------------+
| Syntax   || FILE\_DAT (filename) or                                          |
|          || FILE\_DAT (file$)                                                |
+----------+-------------------------------------------------------------------+
| Location || TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This is the same as FDAT except that default devices and sub-
directories are not supported.

--------------


..  _file-dataspace:

FILE\_DATASPACE
===============

+----------+------------------------------------------------------------------+
| Syntax   | ds = FILE\_DATASPACE(#channel)                                   |
+----------+------------------------------------------------------------------+
| Syntax   | ds = FILE\_DATASPACE('filename')                                 |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function returns the current dataspace requirements for the file opened as #channel or for the file which has the name given, in quotes, as filename.  If the file is an EXEC'able file (See :ref:`file-type`) then the value returned will be the amount of dataspace that that program requires to run, if the file is not an EXEC'able file, the result is undefined, meaningless and probably zero.  If the result is negative, there has been an error and the QDOS error code has been returned.

**EXAMPLE**

::

    1000 ds = FILE_DATASPACE('flp1_WinBack_exe')
    1010 IF ds <= 0 THEN
    1020    PRINT "WinBack_exe doesn't appear to exist on flp1_, or is not executable."
    1030 ELSE
    1040    PRINT "WinBack_exe's dataspace is set to " & ds & " bytes."
    1050 END IF


**CROSS-REFERENCE**

:ref:`file-backup`, :ref:`file-length`, :ref:`file-type`, :ref:`file-update`.


-------


..  _file-len:

FILE\_LEN
=========

+----------+-------------------------------------------------------------------+
| Syntax   || FILE\_LEN (filename) or                                          |
|          || FILE\_LEN (file$)                                                |
+----------+-------------------------------------------------------------------+
| Location || TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function returns the length of a file in bytes. It does not
support the default devices or sub-directories.

**Example**

A short program to show simple file statistics (without any support of
wild cards):: 

    100 dev$="FLP1_" 
    110 OPEN#3,PIPE_10000: OPEN#4,PIPE_200
    120 TCONNECT #3 TO #4 
    130 DIR#3,dev$: INPUT#4,h$\h$ 
    140 : 
    150 sum=0: count=0 
    160 REPeat add_lengths 
    170   IF NOT PEND(#4) THEN EXIT add_lengths 
    180   INPUT#4,file$ 
    185   IF " ->" INSTR file$ THEN NEXT add_lengths 
    190   sum=sum+FILE_LEN(dev$ & file$) 
    200   count=count+1 
    210 END REPeat add_lengths 
    220 : 
    230 CLS 
    240 PRINT "There are"!count!"files in"!dev$;"." 
    250 PRINT "They are altogether"!sum!"bytes long," 
    260 PRINT "the average length is"!INT(sum/count+.5)!"bytes."

TinyToolkit's TCONNECT or DIY Toolkit's QLINK is necessary

**NOTE**

It is not recommended to get a file list by writing a directory into a
file or pipe. Problems arise with sub-directories on level-2 drivers: a
sub-directory is marked with an appended " ->" in the directory list
(WDIR, WSTAT, DIR), so opening a file such a "test ->" will fail. Refer
to OPEN\_DIR and FOP\_DIR for a cleaner method.

**CROSS-REFERENCE**

:ref:`flen` has a more flexible syntax.
:ref:`file-type`,
:ref:`file-dat`,
:ref:`file-pos`,
:ref:`fname-dlr`, :ref:`fpos`,
:ref:`ftyp`, :ref:`fupdt` and
:ref:`fxtra` hold other information on a file.

--------------


..  _file-length:

FILE\_LENGTH
============

+----------+------------------------------------------------------------------+
| Syntax   | fl = FILE\_LENGTH(#channel)                                      |
+----------+------------------------------------------------------------------+
| Syntax   | fl = FILE\_LENGTH('filename')                                    |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

The file length is returned. The file may be open, in which case simply supply the channel number, or closed, supply the filename in quotes. If the returned value is negative, then it is a QDOS error code.

**EXAMPLE**

::

    1000 fl = FILE_LENGTH('flp1_WinBack_exe')
    1010 IF fl <= 0 THEN
    1020    PRINT "Error checking FILE_LENGTH: " & fl
    1030 ELSE
    1040    PRINT "WinBack_exe's file size is " & fl & " bytes."
    1050 END IF
    
**CROSS-REFERENCE**

:ref:`file-backup`, :ref:`file-dataspace`, :ref:`file-type`, :ref:`file-update`.


-------



..  _file-open:

FILE\_OPEN
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FILE\_OPEN ([#ch,] device [,{mode% \| ChID}])                    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FILE\_OPEN is a function which will open any device (default data
directory supported for files) for all kinds of tasks. If a channel
number #ch is not supplied, FILE\_OPEN will choose the channel number on
its own by searching for the next free channel number and returning it.

FILE\_OPEN returns the channel number if it was not specified or
otherwise zero. In case of failure it will return a (negative) error
code. If error -4 ('out of range') is returned when a channel number has
not been supplied, this indicates that the channel table of a compiled
job is full. 

The third parameter can be either the open mode or the
channel ID of an un-named pipe. 

The open mode (default 0) is: 

- 0 (old exclusive) - open an existing file to read and write. 
- 1 (old shared) - open an existing file to read only. 
- 2 (new exclusive) - create a new file if it does not exist.
- 3 (new overwrite) - create a new file, whether or not it exists. 
- 4 (dir open) - open a directory to read only. 

If the third parameter is the channel ID of an open input pipe, then FILE\_OPEN will
create an output pipe linked to that channel.

**Example**

Count additional keywords::

    100 ch1=FILE_OPEN(pipe_10000) 
    110 ch2=FILE_OPEN(pipe_,CHANID(#ch1)) 
    120 EXTRAS#ch1 
    130 FOR count=1 TO 1E6 
    140   IF IO_PEND%(#ch2) THEN EXIT 
    150   INPUT#ch2,keyword$ 
    160   AT 0,0: PRINT count 
    170 END FOR count 
    180 CLOSE#ch1,#ch2

**CROSS-REFERENCE**

:ref:`file-open` combines
:ref:`open`, :ref:`open-in`,
:ref:`open-new`,
:ref:`open-over`,
:ref:`open-dir`,
:ref:`fopen`, :ref:`fop-in`,
:ref:`fop-over`,
:ref:`fop-new`,
:ref:`fop-dir`,
:ref:`tteopen` and
:ref:`tconnect`. See also
:ref:`chanid` and :ref:`ernum`.

--------------


..  _file-pos:

FILE\_POS
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  FILE\_POS (#channel)                                             |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This performs the same function as FPOS, although with slightly less
flexible parameters.

--------------


..  _file-position:

FILE\_POSITION
==============

+----------+-------------------------------------------------------------------+
| Syntax   | where = FILE\_POSITION(#channel)                                  |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function will tell you exactly where you are in the file that has been opened, to a directory device, as #channel, if the result returned is negative it is a QDOS error code.  If the file has just been opened, the result will be zero, if the file is at the very end, the result will be the same as calling FILE\_LENGTH(#channel) - 1, files start at byte zero remember.

**EXAMPLE**

::

    1500 DEFine FuNction OPEN_APPEND(f$)
    1510   LOCal ch, fp
    1515   :
    1520   REMark Open a file at the end, ready for additional
    1530   REMark data to be appended.
    1540   REMark Returns the channel number. (Or error)
    1545   :
    1550   ch = DJ_OPEN(f$)
    1560   IF ch < 0 THEN
    1570      PRINT "Error: " & ch & " Opening file: " & f$
    1580      RETurn ch
    1590   END IF
    1595   :
    1600   MOVE_POSITION #ch, 6e6
    1610   fp = FILE_POSITION(#ch)
    1620   IF fp < 0 THEN
    1630      PRINT "Error: " & fp & " reading file position on: " & f$
    1640      CLOSE #ch
    1650      RETurn fp
    1660   END IF
    1665   :
    1670   PRINT "File position set to EOF at: " & fp & " on file: " &f$
    1680   RETurn ch
    1690 END DEFine  

**CROSS-REFERENCE**

:ref:`abs-position`, :ref:`move-position`.


-------


..  _file-ptra:

FILE\_PTRA
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FILE\_PTRA #channel, position                                    |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command forces the file pointer to be set to the given position.
Positions greater than the actual file length or smaller than zero will
set the pointer to the end or start of the file respectively.

**CROSS-REFERENCE**

:ref:`file-ptrr`,
:ref:`file-pos`, :ref:`fpos`,
:ref:`flen`, :ref:`file-len`,
:ref:`get`.

--------------


..  _file-ptrr:

FILE\_PTRR
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FILE\_PTRR #channel, bytes                                       |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command moves the file pointer from its current position by the
given number of bytes forward, negative numbers allow backward movement.

The file pointer cannot go beyond the limits of the file itself, so if
you try to do so, the pointer will be set to the start or end of the
file.

**Example**

A program to store several names and telephone numbers in a file and
then to search for the given name and return the relevant telephone
number:: 

    100 DIM a$(3,30),number(3) 
    110 RESTORE 
    120 FOR i=1 TO 3: READ a$(i),number(i) 
    130 OPEN_NEW #3,flp2_phone_dbs 
    140 FOR stores=1 TO 3
    150   PUT#3,a$(stores),number(stores) 
    160 END FOR stores 
    170 CLOSE#3 
    180 :
    200 INPUT name$ 
    210 OPEN_IN#3,flp2_phone_dbs 
    220 REPeat find_NAME
    230   IF EOF(#3) THEN PRINT 'NAME not found...': STOP 
    240   GET#3,entry$ 
    250   IF entry$==name$ THEN 
    260     GET#3,telno 
    270     EXIT find_NAME 
    280   END IF 
    290   FILE_PTRR#3,6: REMark skip next phone number 
    300 END REPeat find_NAME
    310 CLOSE#3 
    320 PRINT entry$;'....';telno 
    330 : 
    350 DATA 'P.C. Green','999' 
    360 DATA 'CATFLAP inc.','7212.002121' 
    370 DATA 'Tim','98081'

Note that on Minerva, Integer Tokenisation will need to be disabled.

**CROSS-REFERENCE**

:ref:`file-ptra`,
:ref:`file-pos`, :ref:`fpos`,
:ref:`flen`, :ref:`file-len`,
:ref:`get`.

--------------


..  _file-type:

FILE\_TYPE
==========

+----------+------------------------------------------------------------------+
| Syntax   | ft = FILE\_TYPE(#channel)                                        |
+----------+------------------------------------------------------------------+
| Syntax   | ft = FILE\_TYPE('filename')                                      |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function returns the files type byte. The various types currently known to me are :

- 0 = BASIC, CALL'able machine code, an extensions file or a DATA file.
- 1 = EXEC'able file.
- 2 = SROFF file used by linkers etc, a C68 Library file etc.
- 3 = THOR hard disc directory file. (I think!)
- 4 = A font file in The Painter
- 5 = A pattern file in The Painter
- 6 = A compressed MODE 4 screen in The Painter
- 11 = A compressed MODE 8 screen in The Painter
- 255 = Level 2 driver directory or sub-directory file, Miracle hard disc directory file.

There *may* be others.

**EXAMPLE**

::

    1000 ft = FILE_TYPE('flp1_boot')
    1010 IF ft <= 0 THEN
    1020    PRINT "Error checking FILE_TYPE: " & ft
    1030 ELSE
    1040    PRINT "Flp1_boot's file type is " & ft & "."
    1050 END IF

**CROSS-REFERENCE**

:ref:`file-backup`, :ref:`file-dataspace`, :ref:`file-length`, :ref:`file-update`.


-------



..  _file-update:

FILE\_UPDATE
============

+----------+------------------------------------------------------------------+
| Syntax   | fu = FILE\_UPDATE(#channel)                                      |
+----------+------------------------------------------------------------------+
| Syntax   | fu = FILE\_UPDATE('filename')                                    |
+----------+------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                   |
+----------+------------------------------------------------------------------+

This function  returns the date that the appropriate  file was last updated, either by printing to it, saving it or editing it using an editor etc.  This date is set in all known QLs and emulators etc.

**EXAMPLE**

::

    1000 fu = FILE_UPDATE('flp1_boot')
    1010 IF fu <> 0 THEN
    1020    PRINT "Flp1_boot was last written/saved/updated on " & DATE$(fu)
    1030 ELSE
    1040    PRINT "Cannot read lates UPDATE date from flp1_boot. Error: " & fu & "."
    1050 END IF

**CROSS-REFERENCE**

:ref:`file-dataspace`, :ref:`file-length`, :ref:`file-type`, :ref:`file-type`.


-------



..  _fill:

FILL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FILL [#channel,] boolean                                         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command switches Fill mode on and off. If the Fill mode is on
(after FILL 1), all points in the given window channel (default #1) that
have the same vertical co-ordinate are connected by a line in the
current ink colour so that only non-reentrant figures can be filled
correctly. This means that figures must only contain two points on each
horizontal row of pixels. The fill mode is de-activated by FILL 0.

**Example 1**

::

    FILL 1: POINT 20,20,40,20: FILL 0

draws a horizontal line from 20,20 to 40,20.

**Example 2**

::

    100 DEFine PROCedure SQUARE (x,y,size,angle) 
    110   LOCal n: POINT x,y
    120   TURNTO angle: PENDOWN: FILL 1 
    130   FOR n=1 TO 4: MOVE size: TURN 270
    140   PENUP: FILL 0 
    150 END DEFine SQUARE

**NOTE 1**

FILL only affects those graphic commands which use relative
co-ordinates, ie. which are influenced by SCALE. Commands which operate
in absolute window or screen co-ordinates will not invoke filling.

**NOTE 2**

On non-Minerva ROMs, 1K of memory may be lost if you do not issue a FILL
0 before closing a window. This is however fixed by v1.38 (or later) of
the Pointer Interface (although earlier versions will re-introduce it to
Minerva!).

**NOTE 3**

When drawing several shapes, all of which are to be filled, ensure that
you issue a FILL 0 between each shape, otherwise they will be joined
together if any points appear on the same horizontal line!

**NOTE 4**

FILL works by setting aside a buffer of approximately 1K. Whenever a
point is then plotted in the given window, FILL looks at the buffer to
see if anything appears to the left of that point on the same horizontal
line (in which case, it fills the line between the two points),
otherwise, FILL will just note the co-ordinate of the point in its
buffer. 

FILL then checks if anything appears to the right of the given
point, and if so, will fill the line between the two points. Again, the
co-ordinate of the point will be stored if nothing appears to the right
of it. 

This should explain quite a few of FILL's quirks. Whenever a new
FILL command is used on that window, the old buffer is lost, meaning
that FILL will forget about any points previously plotted.

Unfortunately, the interaction of this buffer causes a lot of problems
(and prevents re-entrant shapes), especially in view of the fact that
only FILL or CLOSE will clear the buffer. The buffer is not cleared once
a shape has been completely filled (eg. with CIRCLE), nor even when the
screen is cleared with CLS. Try this for example::

    100 INK 7:FILL 1 
    110 CIRCLE 50,50,20 
    130 CLS 
    135 INK 2 
    140 CIRCLE 70,60,20

**NOTE 5**

If OVER -1 is switched on, the same line of an image may be FILLed
twice causing that line to be left empty, unless you start drawing the
image from either the top or the bottom. You may also encounter problems
if you try to draw a line which has already been completed by FILL - for
example try::

    100 OVER -1: FILL 1 
    110 LINE 50,50 TO 60,60 TO 70,50 TO 50,50

The FILL command will complete the triangle as soon as the line
between the points (60,60) and (70,50) has been drawn, therefore this
should be re-written::

    100 OVER -1:FILL 1 
    110 LINE 50,50 TO 60,60 TO 70,50

On Minerva v1.97 and SMSQ/E, matters are further complicated - the
first example draws a complete triangle, whereas the second one doesn't!

**NOTE 6**

If OVER -1 is switched on, a shape which is drawn as FILLed will not
be wiped out by re-drawing the same shape again, unless you do a FILL 1
before re-drawing the shape. For example, try this::

    100 OVER -1:FILL 1:CIRCLE 50,50,20 
    110 PAUSE: CIRCLE 50,50,20

The answer is to insert a line::

    105 FILL 1

**NOTE 7**

On Minvera pre v1.86 FILL 0 when fill was not actually switched on would
stop SuperBASIC!!

**CROSS-REFERENCE**

The paint colour of :ref:`fill` is specified by
:ref:`ink`.

--------------


..  _fill-dlr:

FILL$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FILL$ (short$,length)                                            |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This function will generate a string of the given length and return
it. The new string will consist of a repeated series of short$ which may
be one or two characters long. The length (as with any string) ranges
from 0 to 32767.

**Examples**

::
 
    FILL$("W-",7)
    
returns "W-W-W-W".

::
 
    FILL$("+",10)
    
returns "++++++++++".

::
 
    FILL$("Jo",0)

retuns "" (the empty string).

::

    FILL$("Test",6)

returns "TeTeTe".

**NOTE 1**

A bug in the THOR XVI (v6.40) meant that the return stack could be
destroyed when appending the result to an even length string.

**NOTE 2**

A program will run more quickly (although it is more difficult to type
in) if you declare the string explicitly rather than using FILL$.

**NOTE 3**

The maximum length of string that can be produced with FILL$
depends on the ROM version - see the Compatability Appendix.

**CROSS-REFERENCE**

Refer to :ref:`dim` about strings in general.

--------------


..  _fillmem-b:

FILLMEM\_B
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FILLMEM\_B start\_address, how\_many, value                       |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Fill memory with a byte value. See :ref:`fillmem-l` below.

**CROSS-REFERENCE**

:ref:`fillmem-l`, :ref:`fillmem-w`.


-------



..  _fillmem-w:

FILLMEM\_W
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FILLMEM\_W start\_address, how\_many, value                       |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Fill memory with a 16 bit word value . See :ref:`fillmem-l` below.

**CROSS-REFERENCE**

:ref:`fillmem-l`, :ref:`fillmem-b`.


-------



..  _fillmem-l:

FILLMEM\_L
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FILLMEM\_L start\_address, how\_many, value                       |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

Fill memory with a long (32 bit) value. 


**EXAMPLE**

The screen memory is 32 kilobytes long. To fill it all black, try this::

    1000 FILLMEM_B SCREEN_BASE(#0), 32 * 1024, 0

or this::

    1010 FILLMEM_W SCREEN_BASE(#0), 16 * 1024, 0

or this::

    1020 FILLMEM_L SCREEN_BASE(#0), 8 * 1024, 0

and the screen will change to all black. Note how the second parameter is halved each time? This is because there are half as many words as bytes and half as many longs as words.

The fastest is FILLMEM\_L and the slowest is :ref:`fillmem-b`. When you use :ref:`fillmem-w` or FILLMEM\_L you must make sure that the start\_address is even or you will get a bad parameter error. :ref:`fillmem-b` does not care about its start_address being even or not.

:ref:`fillmem-b` truncates the value to the lowest 8 bits, :ref:`fillmem-w` to the lowest 16 bits and FILLMEM\_L uses the lowest 32 bits of the value. Note that some values may be treated as negatives when :ref:`peek`\ 'd back from memory. This is due to the QL treating words and long words as signed numbers.

**CROSS-REFERENCE**

:ref:`fillmem-b`, :ref:`fillmem-w`.


-------



..  _find:

FIND
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FIND (procfn$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

If procfn$ is the name of a machine code keyword (eg. "FILL$") then
the function FIND returns the address where the definition is stored in
memory. 

If, however, procfn$ contains the name of a SuperBASIC PROCedure
or FuNction then FIND will return the line number where the PROCedure or
FuNction starts. 

FIND returns 0 if the passed name is unknown.

**Example**

<ALT><r> requests a Procedure/Function name and calls Toolkit II's
full screen editor accordingly::

    ALTKEY "r","ED FIND('')"&CHR$(192)&CHR$(192)

**CROSS-REFERENCE**

:ref:`key-add`, :ref:`elis`,
:ref:`new-name` Also see
:ref:`flis`.

--------------


..  _flash:

FLASH
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FLASH [#ch,] switch                                              |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This command turns on or off flashing in the specified window channel
(default #1). Switch can only have the values 0 (to enable flashing) and
1 (to turn flashing on). 

This command will only have any effect in MODE
8. 

If flashing is enabled, then any characters PRINTed to the given
window afterwards will be shown to flash - it is first written out as
normal, but then the parts of the character which would normally be
shown in the current INK colour will alternate with the colour of the
background. 

The colour of the background can in fact be different for
each row of pixels - this is calculated by the colour of the left-most
pixel on each row for each character PRINTed.

**Example**

This short listing shows the effect of the FLASH command - note that
the display is not actually changed back to its original form. 

::

    100 PAPER 2: INK 1 
    120 CSIZE 3,1: MODE 8: CLS 
    130 FOR i=0 TO 50: LINE 80+i,80 TO 15+i,10 
    140 INK 7: CURSOR 100,120 
    150 OVER 1: FLASH 1: PRINT 'This is flashing' 
    160 CSIZE 1,0: FLASH 0

**NOTE 1**

This command only affects characters PRINTed to the screen after the
FLASH 1. There is no effect on graphics commands, or BLOCK or LINE.

**NOTE 2**

Spurious results may occur if you write over part of a flashing
character (with OVER -1).

**NOTE 3**

This command does not work on the Amiga-QDOS Emulator or ST/QL
Emulators.

**CROSS-REFERENCE**

Please also refer to :ref:`under`,
:ref:`over` and :ref:`print`.
:ref:`mode` resets the
:ref:`flash` mode to off.

--------------


..  _flen:

FLEN
====

+----------+-------------------------------------------------------------------+
| Syntax   || FLEN [(#channel)] or                                             |
|          || FLEN (\\file)(Toolkit II and THOR only)                          |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI, BTool                                      |
+----------+-------------------------------------------------------------------+

This function returns the length of a file in bytes. If the second
version is used, then Toolkit II's default data device and
sub-directories will be supported, meaning that the command will consult
the default data directory if necessary (see DATAD$). 

If you use the
first version however, you will first of all need to open a channel. If
you do not supply a channel number, then the default used by the
function is #3.

**NOTE 1**

The space on disks, cartridges, ramdisks and all other media where files
can be stored is divided up into sectors, which are normally 512 bytes
long. A file does not occupy the number of bytes returned by FLEN but a
certain number of sectors for the contents of the file itself, a few
bytes for the file header and the directory entries (sector map, etc).
The total number of sectors which are occupied by the file data are::

    sectors = 2 + CEIL(FLEN(\file)/512)
    

**NOTE 2**

If the second syntax does not work, update your Toolkit.

**CROSS-REFERENCE**

:ref:`file-len` has a slightly different syntax.
:ref:`file-type`,
:ref:`file-dat`,
:ref:`file-pos`,
:ref:`fname-dlr`, :ref:`fpos`,
:ref:`ftyp`, :ref:`fupdt` and
:ref:`fxtra` hold other information about a file.
:ref:`headr` and :ref:`heads`
allow you to directly access a file header.

--------------


..  _flis:

FLIS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FLIS (procfn$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Tiny Toolkit                                                     |
+----------+-------------------------------------------------------------------+

If procfn$ is the name of a SuperBASIC PROCedure or FuNction then
FLIS will return the line number where the PROCedure or FuNction is
defined. 

If however, it is a machine code keyword (eg. "FILL$") then the
function FLIS will return 0. 

If the name is not recognised the error 'Not Found' is reported.

**CROSS-REFERENCE**

:ref:`key-add`, :ref:`elis`,
:ref:`new-name` Also see
:ref:`find`.

--------------


..  _flp-density:

FLP\_DENSITY
============

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_DENSITY density  (density = S, D, H or E)                   |
+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_DENSITY (SMSQ/E for QPC only)                               |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, SMS, SMSQ/E for QPC                                  |
+----------+-------------------------------------------------------------------+

There are four types of floppy disk drives which can be connected to
a QL with a Gold Card (or to other computers which are running a QL
emulator). The command FLP\_DENSITY sets the type for use with FORMAT:

+--------+---------+--------+----------+--------------+
| Sides  | Density | Abbrev | Capacity | FLP\_Density |
+========+=========+========+==========+==============+
| Single | Double  | SSDD   |  360 Kb  | S            |
+--------+---------+--------+----------+--------------+
| Double | Double  | DSDD   |  720 Kb  | D (Not QPC)  |
+--------+---------+--------+----------+--------------+
| Double | High    | DSHD   | 1440 Kb  | H            |
+--------+---------+--------+----------+--------------+
| Double | Extra   | DSED   | 3240 Kb  | E (Not QPC)  |
+--------+---------+--------+----------+--------------+

Parameters other than the four letters S, D, H and E, (including
several characters or several parameters) are not allowed.

**Examples**

::

    FLP_DENSITY h 
    FLP_DENSITY 'D'

**NOTE 1**

Tests have shown that it is not always advisable to FORMAT a disk to a
lower density than would otherwise be possible, for example a high
density disk to double density. The result may be that the number of
good sectors is less than could have been achieved by formatting a disk
of the lower density. 

During testing, an undamaged double density disk
was formatted to 1440 sectors and a high density disk to 2880 sectors,
but if the high density disk had been formatted to double density, eg.
with::

    FLP_DENSITY D : FORMAT flp1_
    
less than 1440 sectors might be good sectors. 

You may also find that
some disk drives which support the higher density will be unable to read
these disks, since it will presume that they are FORMATted to their
maximum density.

**NOTE 2**

Since FLP\_DENSITY only has any affect during formatting, it should
generally be avoided. This does not really matter because a disk is
automatically formatted to the highest possible density and it would be
a waste of money to use a HD disk as a DD disk.

**NOTE 3**

If a high or extra density disk is formatted on a system which does not
support those capacities, it will be formatted to double density without
any disadvantages. Such a disk does not cause problems when used with a
Gold Card QL.

**NOTE 4**

A double density disk cannot be formatted to a higher density with HD
drives - the Level-2 (or Level-3) device driver will automatically
reduce a density which had been set at too high a figure by
FLP\_DENSITY, to the appropriate figure. An ED drive however can
successfully format HD disks and even DD disks to high and extra
density, but such disks may be unreliable, ie. data could be easily
lost.

**NOTE 4**

High density is only supported on 3.5" disks, not 5.25" disks (widely
used on MS/DOS systems). Extra density also only exists on 3.5" disks.
QL DD and HD formatted disks have the same physical (but not software)
format as MS/DOS and Atari TOS disks.

**NOTE 5**

High density and Extra density disks are much faster than double density
disks, ED disks can even be as fast as slow hard disks.

**NOTE 6**

FLP\_DENSITY overrides the in-built trial-and-error density detection
which is slow for HD drives and even slower with ED drives. This can
however cause problems when FORMATting DSDD disks - see FORMAT!

**NOTE 7**

On SQMS/E for QPC, the same code letters may be added (after a \*) to the end of the medium name to force a particular density format. (For compatibility with older drivers, if the code letter is omitted after the \*, single sided format is assumed).

- FORMAT 'FLP1\_Disk23' Format at highest density or as specified by :ref:`flp-density`\ .

- FORMAT 'FLP1\_Disk24\*' Format single sided
- FORMAT 'FLP1\_Disk25\*S' Format single sided
- FORMAT 'FLP1\_Disk25\*D' Format double sided, double density

Also, FLP\_DENSITY on it's own resets automatic density selection.

**CROSS-REFERENCE**

The same effect as :ref:`flp-density` can be
achieved with a special :ref:`format` syntax.
:ref:`flp-track` allows you to specify the
number of tracks to be formatted onto a disk.
:ref:`stat` prints the name, good and free sectors of
a medium. See also the The DMEDIUM_XXX functions, starting at :ref:`dmedium-density`.

--------------


..  _flp-drive:

FLP\_DRIVE
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FLP\_DRIVE drive%, drive$                                         |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This changes the drive/image the floppy device is connected to.

**Example**

::

    FLP_DRIVE 2,"C:\FLOPPY.IMG" 
    
Now FLP2\_ is assigned to the floppy image FLOPPY.IMG on the host computer's C:\\ drive.
    
::

    FLP_DRIVE 2,"B:\"

FLP2\_ is assigned to the physical B:\\ floppy drive of the host computer.

--------------


..  _flp-drive-dlr:

FLP\_DRIVE$
===========

+----------+-------------------------------------------------------------------+
| Syntax   | drive$ = FLP\_DRIVE$(drive%)                                      |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This reads back the current connection of the floppy device.

**Example**

::

    PRINT FLP_DRIVE$(2) 
    
will tell you the current setting for flp2\_.

--------------


..  _flp-ext:

FLP\_EXT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_EXT                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards                                                       |
+----------+-------------------------------------------------------------------+

If you use RES\_128 or RES\_SIZE to reset the computer to 128K memory
any attempts to access the floppy disk drives can be haphazard, and can
even crash the computer. 

The command FLP\_EXT resolves these problems
and adds the following commands for use: RAM\_USE, CACHE\_ON,
CACHE\_OFF, SCR2DIS, SCR2EN, AUTO\_TK2F1, AUTO\_TK2F2, AUTO\_DIS,
FLP\_JIGGLE, PAR\_USE, FSERVE, NFS\_USE, DEV\_USE, DEV\_LIST, DEV\_USE$,
DEV\_NEXT, SDUMP, SDP\_SET, SDP\_KEY, SDP\_DEV, PRT\_USE, PRT\_ABT,
RES\_128, RES\_SIZE, PROT\_DATE

**CROSS-REFERENCE**

See :ref:`res-128` and
:ref:`tk2-ext`.

--------------


..  _flp-jiggle:

FLP\_JIGGLE
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_JIGGLE [driveno,] flag                                      |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards                                                       |
+----------+-------------------------------------------------------------------+

There were originally various problems when using Mitsubishi ED disk
drives with the Gold Card and so a fix was incorporated in both the Gold
Card and Super Gold Card operating systems which forces the drive
read/write head to make a number of rapid steps. 

This can however cause
problems with other ED disk drives (normally seen in the form of 'Not
Found' or 'Bad or Changed Medium' errors. 

It was therefore felt
necessary to be able to enable or disable this feature at the users
request (the default is to have the feature disabled). 

To enable this
feature set flag to 1, 0 will disable it. 

If driveno is not specified,
then the setting will be applied to all disk drives connected to the
(Super) Gold Card and automatically stored so that it is available on
power on. 

If driveno is specified, then the setting will only
apply to that specified disk drive and will be forgotten when the power
is switched off.

**CROSS-REFERENCE**

See :ref:`flp-step` and
:ref:`flp-start` which overcome various other
problems with some disk drives.

--------------


..  _flp-sec:

FLP\_SEC
========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_SEC level                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, Trump Card, SMS, THORs, SMSQ/E for QPC               |
+----------+-------------------------------------------------------------------+

The Gold Card, Trump Card and Thor range of computers, together with
SMS provide a high standard of disk security, meaning that they are
unlikely to fail to notice when a disk has been swapped over, and
thereby try to write a file across two disks! 

However, this level of
security does affect the speed of disk access, as the system must check
to see if the disk has been altered each time that it is written to. 

The command FLP\_SEC allows you to choose between three levels of security,
the lowest of which (level 0) is still at least as secure as many other
disk operating systems (such as MSDOS). The lower the level of security,
the quicker disk access will be. The levels of security are as follows:-

Security Level 0
    The disk system will only check to see if the disk has changed if a file
    is opened and the disk has stopped (ie. the disk light will have gone
    out) since the last time it was checked. The disk map is only updated
    when a file is closed (or flushed) and no other disk access has happened
    within half a second. Confusion can be expected on both read and write
    operations whenever a disk is changed whilst the disk light is still on
    or there are files open to the disk.

Security Level 1
    The disk is checked each time that a file is opened, data is written to
    the disk, or the disk map is to be written; provided that the disk has
    stopped since the last time it was checked. The disk map is only updated
    when a file is closed (or flushed) and no other disk access has happened
    within half a second. The disk is not checked when anything is read from
    the disk, which can lead to confusion if a disk is changed whilst there
    are files still open.

Security Level 2
    The disk is checked whenever a file is opened, data is written to or
    read from the disk, or the map is to be read or written to; provided
    that the disk has stopped since the last time that it was checked. The
    disk map and directory are updated and the slave buffers flushed every
    time that a file is closed (or flushed).

**SMS NOTE**

FLP\_SEC has no effect - the security level is fixed at 2, the most
secure.

**SMSQ/E for QPC NOTE**

FLP\_SEC has no effect - the security level is fixed at 2, the most
secure.

--------------


..  _flp-start:

FLP\_START
==========

+----------+-------------------------------------------------------------------+
| Syntax   | FLP\_START time                                                   |
+----------+-------------------------------------------------------------------+
| Location | Gold Cards, Trump Card, THORs, ST/QL (level D.02+ drivers), SMS,  |
|          | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

The disk system always tries to read data from a disk as soon as it
can. However, when writing to a disk, it is necessary to ensure that the
disk is running at full speed before any information is sent to it. 

For relatively new drives, the default waiting time of 0.5 seconds should be
enough to ensure that the disk is running at full speed. 

The command FLP\_START can be used for older disks to allow a longer run-up time. You will need to specify the time in 20ms units - some older drives may
require a value of about 60.

**Example**

::

    FLP_START 13 
    
sets the start up time to 13 \* 20ms (260ms) - this may suit the most recent 3.5" drives.

**NOTE**

FLP\_START has no effect on either the QXL or QPC implementations of
SMSQ and SMSQ/E.

**CROSS-REFERENCE**

You may also need to alter the stepping rate with
:ref:`flp-step`.

--------------


..  _flp-step:

FLP\_STEP
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_STEP [drive,] rate                                          |
+----------+-------------------------------------------------------------------+
| Location |  Disk Interfaces, Gold Cards, SMS, SMSQ/E for QPC                 |
+----------+-------------------------------------------------------------------+

The step rate enables the computer to known how quickly to step
across tracks on the disk surface. Normally, this is automatically set
to 3 milliseconds (ms) for 80 track disks and 6ms for 40 track disks,
although if the system detects repeated errors on reading the disk, it
will automatically slow the step rate. 

Various old disk drives may
require a slower stepping speed (you will generally know this from the
noise the disk drive makes - it will make a repetitive knocking sound
each time that the disk is accessed). You can do this by increasing the
value specified by setting the rate using this command. 

If drive is not
specified, the new step rate is taken to apply to all disk drives
connected to the system, otherwise, you can specify the number of the
drive to which the new step rate is to apply.

**Examples**

::

    FLP_STEP 12
    
Will produce quite a slow step rate for older drives.

::

    FLP_STEP 2,12

Will produce a step rate of 12ms for the drive in FLP2\_.

**NOTE 1**

The first, optional parameter may not be available on some interfaces.

**NOTE 2**

FLP\_STEP has no effect on the QXL, QPC or Atari implementations of SMSQ
and SMS.

**CROSS-REFERENCE**

:ref:`flp-sec` will alter the security setting
for reading and writing to a disk.
:ref:`flp-start` may also be needed on older
drives.

--------------


..  _flp-track:

FLP\_TRACK
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_TRACK tracks                                                |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, Trump Card, THOR, ST/QL, SMS                         |
+----------+-------------------------------------------------------------------+

When a disk is formatted, the operating system will check to see if
there are more than 55 tracks on the disk, and if so, will presume that
it should be formatted to 80 tracks (otherwise it will presume the disk
is to be formatted to 40 tracks). 

The command FLP\_TRACK allows you to
override this setting, so that you can format a disk to, say, 75 tracks.
FLP\_TRACK 40 should be used as standard when a 40 track disk drive is
attached to the system as this will prevent the system from trying to
read track 55 (which does not exist!!), thus saving wear on the drive.

**Example**

::

    FLP_TRACK 40
    
can be used on a standard DSDD 80 track disk to format it into a form
readable on a 40 track drive.

**CROSS-REFERENCE**

:ref:`flp-density` also affects how a disk is
:ref:`format`\ ted.

--------------


..  _flp-use:

FLP\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_USE [device]                                                |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, Trump Card, THORs, ST/QL, SMS, SMSQ/E for QPC        |
+----------+-------------------------------------------------------------------+

Software which was written in the early days of the QL tended to
assume that it would always be run from microdrive, and therefore
included no facilities to alter the default devices used by the
software. 

You may even find some software was written on a non-standard
disk system and assumed that disks would be accessed via FDK rather than
the normal FLP. 

The FLP\_USE command allows you to use such software by
making the FLP device emulate any other device. You merely need to
supply a three letter parameter representing the name of the device
which is to be emulated. Once you do this, the FLP device will no longer
be recognised. If the device is not specified, then the system reverts
to using FLP to access the disk drives.

**Example**

::

    FLP_USE 'mdv'

will allow you to use software which would normally run from microdrive (unless it is copy protected!).

**CROSS-REFERENCE**

:ref:`ram-use`,
:ref:`dev-use` and
:ref:`win-use` are very similar.
:ref:`dmedium-type` can be used to find out
the type of device which a name actually refers to.
:ref:`dmedium-name-dlr` will return the default
name of a device.

--------------


..  _flush:

FLUSH
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FLUSH [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

The command FLUSH forces all of the QL's temporary buffers attached
to the specified channel (default #3) to be emptied into that channel.
This will only work on channels attached to files, any other type of
channel will return error -15 (bad parameter). 

This command is
necessary due to the use by QDOS of slave blocks whenever a file is
opened. Data can be stored partly in the slave blocks to aid speed and
when writing to a file, which will only be written to that file once the
channel has been CLOSEd or the slave blocks have become full. 

Because of
this, there is always a danger that part of the data will be lost if
there is a power failure or other accident. FLUSH helps you to avoid
this.

**NOTE**

FLUSH will not work with Micro Peripherals disk drives. Nor can it be
used to flush the Networks.

**CROSS-REFERENCE**

See :ref:`open` and :ref:`close`.

--------------


..  _flush-channel:

FLUSH\_CHANNEL
==============

+----------+-------------------------------------------------------------------+
| Syntax   | FLUSH\_CHANNEL #channel                                           |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This procedure  makes sure that all data written to the given channel number has been 'flushed' out to the appropriate device. This means that if a power cut occurs, then no data will be lost.

**EXAMPLE**

::

    1000 DEFine PROCedure SaveSettings
    1010   OPEN_OVER #3, "flp1_settings.cfg"
    1020   FOR x = 1 to 100
    1030     PRINT #3, Setting$(x), Value$(x)
    1040   END FOR x
    1050   FLUSH_CHANNEL #3
    1060   CLOSE #3
    1070 END DEFine    


-------


..  _fmake-dir:

FMAKE\_DIR
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FMAKE\_DIR (subdirectory)                                        |
+----------+-------------------------------------------------------------------+
| Location |  Level-2 Device Drivers                                           |
+----------+-------------------------------------------------------------------+

This function will only work if Level-2 or Level-3 device drivers are
available. 

FMAKE\_DIR is identical to MAKE\_DIR except that it is a
function and does not stop a program if an error occurs, instead it
returns the code of the error concerned. 

The following errors need some explanation: 

- Error -9 (in use) : There is already a sub-directory with the same name; 
- Error -8 (already exists) : File (not a sub-directory) exists already with that name; 
- Error -15 (bad parameter) : Medium does not support sub-directories.

**NOTE 1**

If MAKE\_DIR or FMAKE\_DIR fail on a ramdisk, an old type ramdisk may
have been loaded. There is no other way to activate the integral ramdisk
other than by resetting the whole system.

**NOTE 2**

If error -15 occurs (ie. if you try to created a sub-directory on a
medium where this is not possible), MAKE\_DIR and FMAKE\_DIR will leave
an empty file with the name of the desired sub-directory on the medium.
Remember to remove this.

**CROSS-REFERENCE**

See :ref:`make-dir`.

--------------


..  _fname-dlr:

FNAME$
======

+----------+-------------------------------------------------------------------+
| Syntax   || FNAME$ [(#channel)] or                                           |
|          || FNAME$ (\\file)(Toolkit II only)                                 |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, BTool                                                |
+----------+-------------------------------------------------------------------+

This function returns the filename of a file attached to the
specified channel (default #3), including the sub-directory prefix but
without the pure device name (eg. RAM1\_). 

The second syntax enables you
to find out the full filename of the specified file. 

It is hard to
understand why one should need to find out about the name of an opened
file - the second syntax is even more absurd. 

One possible usage is to
convert a Toolkit II filename, which need not include the current
sub-directory, to a full file name. However, the functions DATAD$,
PROGD$ together with some string operations are much faster and more
elegant because they skip the need to access the file header.

**CROSS-REFERENCE**

:ref:`flen`, :ref:`ftyp`,
:ref:`fdat`, :ref:`fxtra`,
:ref:`fupdt`,
:ref:`file-len` and
:ref:`file-type` return other information about a
file.

--------------


..  _fopen:

FOPEN
=====

+----------+-------------------------------------------------------------------+
| Syntax   || FOPEN (#ch, name) or                                             |
|          || FOPEN (name)                                                     |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function is designed to allow you to access files safely without
causing errors which force a program to stop. 

If the first variant of
FOPEN is used, this is actually very similar to the command OPEN in
operation, except that if for some reason opening the specified channel
(#ch) with the specified name would cause an error, FOPEN returns the
relevant error code. If the specified channel is successfully opened,
then FOPEN returns 0. 

By contrast, if the second variant of the command
is used, where no specific channel number is used, if successful, FOPEN
will return a positive number representing the number of the next
available channel (ie. the number of the lowest entry in the channel
table which is empty). 

If a negative number is returned, this is the
appropriate error number, allowing the programmer to take any necessary
action (such as requesting the user to input a new file name).

**Examples**

::

    ERRno = FOPEN(#3,scr_448x200a32x16) 
    Chan = FOPEN('flp1_Input_dat'): IF Chan>0 THEN INPUT #Chan,x

**NOTE 1**

All versions of this command (other than v2.28 of Toolkit II or later)
can be confused by filenames which exceed 36 characters, in which case
FOPEN will return 0. On later versions, FOPEN supports 41 character
filenames (including any default directory).

**NOTE 2**

Although FOPEN opens a file for both reading and writing, it will only
return an error if the file does not already exist or is in use. It does
not check whether the file is read only. Use FOP\_NEW or DMEDIUM\_RDONLY
for this. If you do not check whether the file is read only, an error
will only be reported if you try to write to the file!!

**CROSS-REFERENCE**

:ref:`ernum` contains details of the various error
messages. :ref:`when--error` allows you to
error trap a complete program. Also see
:ref:`fop-dir`,
:ref:`fop-in`,
:ref:`fop-over` and
:ref:`fop-new`. Also see
:ref:`open`. :ref:`ftest` allows
you to test the status of a file without (explicitly) opening a channel.

--------------


..  _fop-dir:

FOP\_DIR
========

+----------+-------------------------------------------------------------------+
| Syntax   || FOP\_DIR (#ch, name) or                                          |
|          || FOP\_DIR (name)                                                  |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

The function FOP\_DIR is a complementary function to OPEN\_DIR in
much the same way as FOPEN is to OPEN. This function returns the same
values and suffers from the same problem as FOPEN.

**CROSS-REFERENCE**

See :ref:`fopen`,
:ref:`tteopen` and
:ref:`open-dir`.

--------------


..  _fop-in:

FOP\_IN
=======

+----------+-------------------------------------------------------------------+
| Syntax   || FOP\_IN (#ch, name) or                                           |
|          || FOP\_IN (name)                                                   |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

The function FOP\_IN falls into the same series of functions as
FOPEN, FOP\_DIR, FOP\_NEW and FOP\_OVER. This function is a
complementary function to OPEN\_IN in much the same way as FOPEN is to
OPEN. This function returns the same values and suffers from the same
problem as FOPEN.

**CROSS-REFERENCE**

See :ref:`fopen` and
:ref:`open-in`.

--------------


..  _fop-new:

FOP\_NEW
========

+----------+-------------------------------------------------------------------+
| Syntax   || FOP\_NEW (#ch, name) or                                          |
|          || FOP\_NEW (name)                                                  |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function, together with its companions FOPEN, FOP\_IN, FOP\_DIR
and FOP\_OVER, is designed to allow you to access files safely without
causing errors which force a program to stop. This function is the
complement to OPEN\_NEW and returns the same values and suffers from the
same problem as FOPEN. If the specified file already exists, you are
asked whether you want to over-write the existing file. An error (-8) is
returned if you press N, and error (-20) is returned if the disk is read
only.

**CROSS-REFERENCE**

See :ref:`fopen` and
:ref:`open-new`.

--------------


..  _fop-over:

FOP\_OVER
=========

+----------+-------------------------------------------------------------------+
| Syntax   || FOP\_OVER (#ch, name) or                                         |
|          || FOP\_OVER (name)                                                 |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This function is the complement to OPEN\_OVER and suffers from the
same problem as FOPEN. It also returns the same values as FOP\_NEW,
except that it will implicitly over-write an existing file with the same
name.

**CROSS-REFERENCE**

See :ref:`fopen` and
:ref:`open-over`.

--------------


..  _for:

FOR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FOR var = range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*`         |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The SuperBASIC version of the classic FOR loop is *extremely* flexible.

The syntax of this SuperBASIC structure can take two forms:

    FOR var=range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*` :statement :sup:`\*`\ [:statement]\ :sup:`\*` 

or :

    FOR var=range :sup:`\*`\ [,range\ :sup:`i`]\ :sup:`\*` :sup:`\*`\ [statements]\ :sup:`\*` [EXIT var] [NEXT var] END FOR var

Where range can be one of the following:

    start\_value TO end\_value [STEP step]
    
or, simply just:

    value
    
The first of these variants is known as an in-line FOR loop. Provided
that there is at least one statement following FOR, this line will be
repeated until the end value is reached (see below). There is no need
for a related END FOR statement and therefore the shortest in-line FOR
loop possible is::

    FOR x=1 to 100: NEXT x

If an in-line loop is terminated prematurely, for example with EXIT,
control will be passed to the statement following the corresponding END
FOR statement (if one exists), or the next program line. This allows the
following::

    FOR x=1 TO 100: IF INKEY$=' ': EXIT x: END FOR x: PRINT x

The basic function of FOR is to count a floating point variable from
a given start value to an end value by adding step to var during each
pass of the loop (step may be positive or negative depending on the
start and end values). If no step is specified, STEP 1 will be assumed.

However, if step is negative when the end value is greater than the
start value (or vice versa), then the loop will immediately exit, and
nothing contained in the loop will be processed. 

A similar effect can be
achieved by using a REPeat structure::

    var=start_value 
    REPeat loop 
      ...
      IF var >= end_value THEN 
        EXIT loop
      ELSE var = var + step 
    END REPeat loop

The similarity between these two SuperBASIC loop types can be extended
to the use of EXIT and NEXT statements which can be used identically in
both structures. 

EXIT terminates the loop, and the next statement which
will be processed is the first statement after the corresponding END
FOR. NEXT forces the program to make the next pass of the loop.

**PROGRAMMING NOTES**

1. When NEXT is used within a FOR..END FOR structure, if var is
   already at the end\_value, the NEXT statement will have no effect::

       100 FOR x=1 TO 9 
       110 PRINT x;" "; 
       120 IF x MOD 2 THEN NEXT x 
       130 PRINT x^2
       140 END FOR x

   Output:: 
   
        1 2 4
        3 4 16
        5 6 36
        7 8 64
        9 81 
    
   To prevent the odd result when x=9, line 120 would need to be altered to read::

        120 IF x MOD 2 THEN NEXT x: EXIT x

2. Except on a Minerva ROM or under SMS, the loop variable is set to
   0 before the FOR is executed, therefore the following program prints the
   square roots of the numbers 0 to 9::

       100 x=3 
       110 FOR x=x TO 9 
       120 PRINT x;' '; 
       130 IF NOT RND(10) THEN EXIT x 
       140 PRINT SQRT(x) 
       150 END FOR x

   On Minerva ROMs and under SMS, this would print out all of the square
   roots of the numbers 3 to 9 (as expected). 

3. A NEXT statement directly after the FOR statement could be used to omit some 
   values of the loop variable::
   
       100 FOR x=1 TO 9 
       110 IF x MOD 2 THEN NEXT x: EXIT x 
       120 PRINT x; TO 4; x^2 
       130 END FOR x

   However, in some cases, it may be easier and shorter to write::

       100 FOR x=2,4,6,8 
       110 PRINT x; TO 4; x^2 
       120 END FOR x

4. Single values and intervals can be freely mixed after the equals
   sign. The following examples are all valid expressions::

       FOR x=2,4 TO 10 STEP 2,4.5,7 TO -4 STEP -.2 
       FOR x=1

5. To shorten program lines even further, the FOR loop can be used in
   a single line and the END FOR omitted (this is called an in-line FOR
   loop)::

       FOR x=2,4,6,8: PRINT x; TO 4; x^2

**Example 1**

A short routine to count the lines of a text file (using the oddities
of the NEXT command):: 

    100 OPEN#3,file 
    110 FOR lines=0 TO 10000 
    120   IF EOF(#3) THEN PRINT lines: EXIT lines 
    130   INPUT #3,line$: NEXT lines 
    140   PRINT 'OOPS - program is longer than 10000 lines!!' 
    150 END FOR lines
    160 CLOSE#3

**Example 2**

The next example is a routine to nest a variable number (loops) of
times which go from Value\_min to Value\_max at Value\_step:: 

    100 FOR loop=1 TO loops:Value(loop)=Value_min(loop) 
    110 REPeat Nesting 
    120 <instructions using Value(1...s) go here> 
    130   FOR loop=1 TO loops 
    140     IF Value(loop)=Value_max(loop) THEN 
    150       IF loop=loops THEN EXIT Nesting
    160       Value(loop)=Value_min(loop) 
    170       NEXT loop 
    180     ELSE 
    190       Value(loop)=Value(loop)+Value_step(loop) 
    200       EXIT loop 
    210     END IF 
    220   END FOR loop 
    230 END REPeat Nesting

**NOTE 1**

If you use multiple in-line FOR loops in the same program line, only
the inner loop will be executed. For example::

    FOR i=1 TO 3: FOR j=1 TO 10: PRINT i*j: END FOR j

Output:: 
    
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10 

This will actually work correctly under SMS. 

You can get it to work on a Minerva ROM and under
SMS (but not others) if the line is amended to read:: 

    FOR i=1 TO 3: FOR j=1 TO 10: PRINT i*j: END FOR j: END FOR i

In fact, SMS will even allow the line to work if it simply reads::

    FOR i=1 TO 3: FOR j=1 TO 10: PRINT i*j

**NOTE 2**

Unless you have SMS or a Minerva ROM, do not use GO SUB together with an 
in-line FOR loop, because this will act as an END
FOR command and will not call the desired routine::

    100 FOR i=1 TO 10: PRINT 'Junk - test';: GO SUB 200: PRINT i 
    110 STOP 
    200 PRINT ' Number ';
    210 RETurn

**NOTE 3**

On JS (except ST/QL) and MGx ROMs, you cannot use the first of several
PROCedure/FuNction parameters as the loop identifier::

    100 TEST 5,10 
    110 FOR j=1 TO 10: PRINT 'OOPS...' 
    120 FOR k=1 TO 10: PRINT 'OKAY...' 
    125 :
    130 DEFine PROCedure TEST(j,k) 
    140   AT j,k:PRINT 'Errors .....' 
    150 END DEFine

**NOTE 4**

No error will be reported and all should work okay if NEXT
is used instead of END FOR (unless you try to use EXIT which would
try to jump to the statement after the non-existent corresponding END
FOR, and may reach the end of the program without finding the END FOR,
therefore stopping without reporting any error), but you will have seen
that NEXT is intended for another purpose. 

Apart from programming
elegance, compilers may not be able to understand your meaning (they
assume that you have forgotten the END FOR) and may abort compilation or
report a warning.

**NOTE 5**

Counting downwards without a negative step has no effect at all For example::

    FOR loop=0 TO -3 
    
Omitting the STEP parameter is the same as STEP 1.

**MINERVA NOTES**

On a Minerva machine, a FOR loop can use either a single character
string variable or an integer variable:: 

    FOR A$='A' TO 'Z' STEP CHR$(2):PRINT A$;' ';
    
This prints out::

    A C E G I K M O Q S U W Y 

::

    FOR loop%=1 TO 255: ...: END FOR loop%
    
This is a little quicker than::

    FOR loop=1 to 255: ...: END FOR loop

These examples will not work on other ROMs, unless you have SMS, even
if they will let you type them in!

**SMS NOTES**

Like Minerva, SMS will allow you to use integer variables in FOR loops
(but not string variables). As from v2.57, the range is checked to
ensure that it is within the valid word integer range (-327678..32767)
when the FOR loop is started, otherwise it returns 'Error in
Expression'. 

If you try to use a string loop variable, the error
'unacceptable loop variable' is reported. EXIT, NEXT and END FOR do not
need to contain the loop identifier, SMS will presume that when used in
a program, they refer to the loop currently being executed.

**CROSS-REFERENCE**

:ref:`repeat` ... :ref:`end--repeat` is the other loop type. See also :ref:`end--for`.

--------------


..  _force-type:

FORCE\_TYPE
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  FORCE\_TYPE string$                                              |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command forces the given string to be typed into the current
keyboard queue, just as if you had typed it from the keyboard. There is
not much use for this command in connection with applications because
key macros such as ALTKEY are much easier to use. But, FORCE\_TYPE can be used 
to perform an
action without anyone actually needing to press a key.

**Example**

Your telephone rings and you talk half an hour with a friend.
Meanwhile your computer crashes - God only knows why - and the BASIC
program you were writing has now disappeared along with everything else.

You could decrease this danger by writing and compiling such a program::

	100 last_stroke = DATE 
	110 REPeat Sleeping 
	120   IF KEYROW(1) THEN last_stroke = DATE 
	130   IF DATE-last_stroke > 300 THEN 
	140     FORCE_TYPE "SAVE_O FLP1_Backup_bas" & CHR$(10) 
	150     REPeat Wait: IF KEYROW(1) THEN EXIT Wait 
	160     last_stroke=DATE 
	170   END IF 
	180 END REPeat Sleeping

This example should obviously be adapted to your specific needs, applications
and tools.

**NOTE 1**

Every console channel (ie. con\_ windows) has a keyboard queue - the
channel accessed by FORCE\_TYPE must first be activated by a dummy
INKEY$, PEND etc. to that channel.

**NOTE 2**

In earlier versions of Tinytoolkit (pre v1.10), this command was called
TYPE\_IN, which could cause problems with Turbo compiled programs.

**CROSS-REFERENCE**

:ref:`stamp` does exactly the same as
:ref:`force-type`.

--------------


..  _format:

FORMAT
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FORMAT [#channel,] medium                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

Each medium where data can be stored as files (disks, ramdisks,
microdrives or hard disks) has to be given a structure which is
recognisable by QDOS. This is done by FORMATting it. Each medium can
also be given a name of up to ten characters long. The command FORMAT
clears a medium from scratch so that any data stored there is
definitively lost. Be careful! 

The following standard devices can be
formatted: 

- MDV1\_ .. MDV8\_  - microdrive cartridges 
- FLP1\_ .. FLP8\_  - floppy disks 
- RAM1\_ .. RAM8\_  - ramdisks 
- WIN1\_ .. WIN8\_  - hard disks 

Depending on
the type of medium, several additions to the pure medium name are
possible: 

**MDV** Up to ten characters can be added, these will form the name
of the cartridge, eg::

	FORMAT mdv2_SuperBASIC

**FLP** As with microdrive cartridges, a medium name can be added. If the
eleventh character of the name is an asterisk (\*), the disk will be
formatted single sided, ie. just the first side is used. In order to use
the single sided only option, is it necessary to put the whole parameter
in quotes, eg::

	FORMAT "flp1_TEST *"

This is not applicable to HD and ED disks: their density will also be
affected, making them single sided double density (SSDD). If a single
sided disk can still be bought today, it will actually be a double sided
disk of low quality. 

With Super Gold Card, Gold Card and SMS, an
appended asterisk plus a letter which indicates the density will format
the disk accordingly: S, D, H and E are allowed, eg:: 

	FORMAT "flp1_TEST*h"

See :ref:`flp-density`. 

**RAM** This depends very much on the ramdisk drivers:

With standard static ramdisks, which are built into most disk interfaces
and available as public domain, you need to specify how many sectors are
to be allocated to the ramdisk by adding the number of sectors to the
device name, eg::

	FORMAT ram1_200

formats ram2\_ to 200 sectors (100K). 

These static ramdisks must be
FORMATted before use. 

On the other hand, the Qjump ramprt ramdisk
(provided with Qpac 2 and various expansion boards, including Trump
Card, Gold Card and Super Gold Card) is dynamic - it adapts its size
automatically to the size of the files being stored on it - there is no
need to FORMAT the ramdisk prior to use. This can however also be used
as a static ramdisk. 

Trump Card, Super Gold Card and Gold Card ROMs also
contain a special variant of a ramdisk which allows you to produce an
image of a microdrive cartridge on a ramdisk, for example by using::

	FORMAT ram4_mdv2. 

Faulty files are marked with an asterisk added to the
end of their filenames. Although this may allow you to 'rescue' a
corrupt microdrive cartridge those files marked with an asterisk are
faulty and therefore unreliable. 

The name of a ramdisk is always the
name of the medium without an underscore, eg. RAM1 for RAM1\_; this is
the same on dynamic ramdisks. 

**WIN** A medium name can normally be stated,
as with a microdrive cartridge. Please check the documentation of the
hard disk drivers, they differ very much! For example, the firmware on
the Falkenberg interface disables FORMAT for hard disks until certain
settings have been specified with another command. 

On the THOR, an
asterisk needs to be included, eg:: 

	FORMAT 'win1_*HARDDISK'

See below.

SMS for ATARI computers and QXL / QPC, expects you to have already
partitioned the hard disk using the computer's native commands. On
ATARIs, under SMSQ/E you then need to identify the drive and partition
using WIN\_DRIVE. After that, you can use the normal QL FORMAT command
on all these systems, however, SMSQ/E has adopted a level of protection
which insists that you must use the WIN\_FORMAT command before FORMAT
and the FORMAT command itself will display two characters on screen and ask you to
type them in. 

You should then use WIN\_FORMAT to protect the partition
again. 

The standard drivers for the ST/QL Emulators adopt a form of
protection in that you will need to type in the two characters shown on
screen as with SMSQ/E. 

You can also only FORMAT a hard disk from
SuperBasic Job 0 and then only when Channel #0 is OPEN. 

If the hard disk
has already been partitioned by the Atari ST (the first partition will
normally be marked GEM or BGM), then you will be asked to enter the
number of the first partition to be used by QDOS and the number of
subsequent partitions ot be used for this disk. 

Under SMSQ/E on the QXL
or QPC, this same two- level protection is adopted. However, instead of
passing the medium name of the hard-disk, you have to pass the size of
the QL hard disk to be created in megabytes, for example:: 

	FORMAT WIN1_20

This will create a 20 Megabyte harddisk on PC drive C: 

On early
versions, the maximum size that could be created was 23 Megabytes and
only one drive could be created. Later versions allow you to create WIN1
to WIN8 (all on drive C:). 

After formatting, FORMAT will either report
that the process has failed (error -14), because there was no
cartridge/disk in the drive or if the medium was faulty. 

The command
will also fail if the given device was write-protected. 

If everything
was okay, a small message is printed to the specified channel (default
#1) indicating how many sectors could be achieved and how many were
good. If the two numbers differ, QDOS will have marked some sectors as
bad and will ignore them. However, experience shows that if the
difference between the two numbers is great, it can be very dangerous to
store important data on those disks/cartridges. 

It is recommended that
new microdrive cartridges should be formatted 10 times before use (you
should expect to get about 220 available sectors). It may also be useful
to try formatting the cartridge in the other microdrive.

**Examples**

::

	FORMAT mdv2_Startup

formats cartridge in microdrive 2 

::

	FORMAT "mdv2_Startup" 

as above. 

::

	FORMAT flp1_backup 

formats disk in disk drive 1 

::

	FORMAT "flp1_backup *" 

as above but single sided 

::

	FORMAT "flp1_backup*d" 

double sided, double density 

::

	FORMAT "flp2_backup*h"

double sided, high density 

::

	FORMAT ram1_100 

format ramdisk 1 to 50K

::

	FORMAT ram1_ 

remove ramdisk 1 

::

	FORMAT ram1_mdv1

format ram1\_ to 255 sectors and copy cartridge in microdrive 1

**Notes on the different media:**

The traditional microdrive is relatively slow and unreliable, and
cartridges need to be formatted several times to give good results
(usually around 210-220 sectors) - pushing them firmly into the
microdrive slot while they are being formatted is said to be more
efficient. 

However, as new cartridges are becoming more rare and
expensive today, the next best and very highly recommended upgrade are
disk drives. 

It is also becoming less and less common to find users who
can read information stored on microdrive, SMS and emulators for
example, do not support microdrives.

**3.5" double density disks (720K)**

These are pretty cheap and you can get them everywhere (although the quality
does vary); they have become a standard on the QL, although it is
becoming ever more difficult to find replacement disk drives. FORMAT
should report 1440 sectors.

**3.5" high density disks (1.4Mb)**

These are also fairly cheap and you can get them everywhere (although the
quality does vary). These have become the new standard disks used by IBM
compatible computers and therefore the disk drives are easy to obtain.
FORMAT should report 2880 sectors.

**3.5" extra density disks (3.2Mb)**

These are fairly expensive and difficult to obtain as they were never really
accepted in the IBM PC world, although for a time, they looked like
becoming a new standard for the QL, being very quick and storing a lot
of information. FORMAT should report either 1600 or 6400 sectors (see
note 8).

**5.25" disks (720K)**

These are also widely spread in the QL scene, especially in the USA, although
they are now becoming less and less common. With the introduction of the
Super Gold Card and Gold Card by Miracle Systems Ltd, high density (HD,
1440K) and even extra density (ED, 3200K) drives have become available
to QDOS for the first time. These formats are several times faster and
even more reliable, not to mention the increased space for programs and
data.

**Hard disks**

These are becoming more and more common, with them being readily available to
people using Emulators on other computers, and also now the release of
relatively cheap interfaces and disk drives for the QL and AURORA.

**Ramdisks**

These are not specific to any hardware configuration because they only exist
in RAM and any stored data is lost if the machine is reset or turned
off. On the other hand, ramdisks are extremely fast.

**NOTE 1**

Unless you have a Minerva ROM (see below), do not try to FORMAT a
microdrive whilst any microdrive is still running, since this will
report an 'in use' error. 

::

	PEEK(SYS_VARS+HEX('EE'))

will be zero if no microdrives are running.

**NOTE 2**

On the THOR XVI (v6.37 and earlier), there existed a bug when accessing
anything greater than win2\_.

**NOTE 3**

If there is no disk in a drive, FORMAT may also fail with a read only
error (-20) instead of reporting not found (-7).

**NOTE 4**

You cannot use FORMAT n1\_flp1\_ (for example) to FORMAT a medium over
the network.

**NOTE 5**

The ST/QL drivers cannot FORMAT the fifth and subsequent partitions on
the hard disk unless the extended partition table is in the form used by
SUPRA, ICD and similar drives.

**NOTE 6**

Minerva (pre v1.98) had some bugs in the code for FORMATting
microdrives.

**NOTE 7**

FORMAT expects the specified channel (or #1) to be OPEN, otherwise an
error will be reported.

**NOTE 8**

FORMAT cannot report a number of sectors in excess of 32768 and so may
return wrong values on large capacity drives. SMS correctly reports the
number of sectors obtained, although on an ED disk, FORMAT will report
1600 Sectors (DIR will show the figure of 6400 sectors instead!). This
is because on an ED disk, sectors are 2048 bytes long instead of the
usual 512 bytes expected by the QL device drivers (which have to be
fooled to see each sector as 4x512 byte sectors).

**MINERVA NOTE**

On Minerva v1.78 (and later), a check is carried out before performing
FORMAT to see if there are any files open on the desired medium. This
stops Digital Precision's Conqueror and Solution from working correctly.
To switch it off, use:: 

	POKE !124 !49, PEEK (!124 !49) || 128

**SMS NOTES**

As with Minerva, you cannot FORMAT a medium if there are any files
open on that medium ('Is In Use' error is reported). If there is a
problem during the FORMAT process, SMS will emit a series of BEEPs.
However, be warned that an error messaage is not always displayed and
the FORMAT may appear to have completed correctly!! SMS does not allow
you to access the QL's microdrives, nor can it solve the problem on the
QXL below. SMS can corrupt floppy disks (so they have to be thrown away)
if you try to FORMAT them to the wrong density. 

Some users have reported
problems in using SMS to FORMAT
Double Density disks in ED disk drives linked to a Super Gold Card.
This appears to afflict versions of SMS after v2.85 and all makes of ED
drives. The problem only occurs if you specify the density with FORMAT
'flp1\_NAME\*D' or FLP\_DENSITY 'D'. In these cases, a noise is emitted
during FORMAT to indicate that it has failed, but SMS still reports
1440/1440 sectors, even though subsequent attempts to access the disk
report 'Not Found'. The answer is to not use FLP\_DENSITY in this
instance.

**QXL NOTES**

You cannot reliably FORMAT floppy disks from scratch on most PCs using
this emulator. FORMAT merely re-formats an already formatted disk. Prior
to v2.67 of SMS there existed several further problems with FORMAT on
QXL.

**THOR XVI NOTES**

The THOR XVI, v6.37 (and later) allows a variant of the medium name to
deal with the THOR's hard disk:: 

	FORMAT "win1_options*name"

The available options which can be specified are: 

- /C : Certify drive before formatting - this reconstructs the THOR's defect list, describing the bad sectors and tracks;

- /Q : Quick reformat - merely sets up new directory map; 

- /F : Fast reformat - does not verify the disk;

- /Gn : Set group or cluster size in blocks. Default = /G16; 

- /Dn : Set directory size in number of groups or clusters. Default = /D2.

**Examples**

::

	FORMAT 'win1_/Q*Main' 
	FORMAT 'win1_/G16/D2*THORDisk'

**WARNING**

Prior to v2.71 of SMS FORMAT flp3\_1 on the QXL could in fact FORMAT
WIN1\_.

**CROSS-REFERENCE**

Before formatting, the number of tracks on a disk can be specified with
:ref:`flp-track`. HD and ED disks can be
formatted to different densities if
:ref:`flp-density` was used to override
automatic detection of the density. See
:ref:`win-format` for hard disk protection.
The DMEDIUM_XXX functions, starting at :ref:`dmedium-density` return various details
about how a medium has been formatted.

--------------


..  _fpos:

FPOS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FPOS [(#channel)]                                                |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, BTool                                      |
+----------+-------------------------------------------------------------------+

This function returns the current position of the file pointer. 

The relevant file must already be open as #channel, default channel is #3. A
value of zero means that the file pointer is at the very beginning of a
file, whereas a position equivalent to the file length means that it
points to the very end. The file pointer is a means by which the QL can
keep track of exactly whereabouts in a file it should take the next
input from, or write to.

**CROSS-REFERENCE**

:ref:`file-pos` works exactly as
:ref:`fpos` but does not use a default channel.
:ref:`file-ptra` and
:ref:`file-ptrr` move the file pointer, which
may also be set with :ref:`get`,
:ref:`put`, :ref:`bget` and
:ref:`bput`.

--------------


..  _fpos-a:

FPOS\_A
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  FPOS\_A ([#ch,] pos)                                             |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This is the same as :ref:`file-ptra`.

--------------


..  _fpos-r:

FPOS\_R
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  FPOS\_R ([#ch,] offset)                                          |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This is the same as :ref:`file-ptrr`.

--------------


..  _fput-dlr:

FPUT$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FPUT$ [#ch,] string :sup:`\*`\ [,string\ :sup:`i`]\ :sup:`\*`    |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This command writes the given string(s) in internal format to #ch,
default is #1. The internal format of a string is a word (two bytes)
giving the length of the string followed by the contents of the string
itself.

**Example**

::

    FPUT$ 'Hello'

will produce the equivalent of PRINT CHR$(0)&CHR$(5)&'Hello'.

**CROSS-REFERENCE**

:ref:`fget-dlr`, :ref:`put`.

--------------


..  _fput-pct:

FPUT%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FPUT% [#ch,] integer :sup:`\*`\ [,integer\ :sup:`i`]\ :sup:`\*`  |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This command writes the specified integer(s) (range 0...32767) in its
internal format to #ch, default is #1. An integer is stored internally
as two bytes (one word).

**CROSS-REFERENCE**

:ref:`fget-pct`, :ref:`put`

--------------


..  _fputb:

FPUTB
=====

+----------+--------------------------------------------------------------------------------------------------+
| Syntax   |  FPUTB [#ch,] {byte \| string$} :sup:`\*`\ [,{byte\ :sup:`i` \| string\ :sup:`i`\ $}]\ :sup:`\*` |
+----------+--------------------------------------------------------------------------------------------------+
| Location |  BTool                                                                                           |
+----------+--------------------------------------------------------------------------------------------------+

FPUTB is a command which writes single or multiple bytes to a channel
#ch (default #1). FPUTB can take any kind of parameters which must be
either a numeric value byte in the range 0..255 for a single byte, in
the range 256..32767 for two bytes or a string string$.

**Example 1**

::

    CLS: FPUTB "First line",10,"Second line" 
    CLS: FPUTB "First line",2570,"Third line"

because CVI% (CHR$ (10) & CHR$ (10) ) = 2570)  
which is (10 * 256) + 10 in big-endian format, as the QL is.

**Example 2**

FPUTB is very handy for controlling printers::

    OPEN#3,par
    FPUTB#3,27,"x",1 
    CLOSE#3
    
will enable near letter quality (NLQ) on an EPSON compatible printer.

**CROSS-REFERENCE**

:ref:`bput`, :ref:`chr-dlr`,
:ref:`code`. :ref:`fgetb` is a
complementary function.

--------------


..  _fputf:

FPUTF
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FPUTF [#ch,] float :sup:`\*`\ [,float\ :sup:`i`]\ :sup:`\*`      |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This command writes the floating point number(s) float in its
internal format (six bytes) to #ch, default is #1.

**CROSS-REFERENCE**

:ref:`fgetf`, :ref:`put`

--------------


..  _fputl:

FPUTL
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FPUTL [#ch,] longint :sup:`\*`\ [,longint\ :sup:`i`]\ :sup:`\*`  |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This command writes the specified long integer(s) longint
(-231..231-2) in internal format (four bytes) to #ch, default is #1.

**CROSS-REFERENCE**

:ref:`fgetl`, :ref:`put`

--------------


..  _fract:

FRACT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FRACT (x)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  FRACT                                                            |
+----------+-------------------------------------------------------------------+

The function FRACT separates the fractional part of any floating
point number x. It could easily be rewritten in SuperBASIC as the
following::

    100 DEFine FuNction MYFRACT (x) 
    110   RETurn x - INT(x) - (x < 0) 
    120 END DEFine MYFRACT

**CROSS-REFERENCE**

:ref:`trint` is complementary to
:ref:`fract`.

--------------


..  _fread:

FREAD
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FREAD (#ch,address,bytes)                                        |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

The function FREAD reads a number of bytes (bytes) from a given
channel into memory, starting at address. The number returned by FREAD
gives the number of bytes it actually read.

**Example**

A BASIC Procedure APPEND which adds a file (file1$) to the end of a
target file (file2$). If the target file does not exist, it will be
created. 

The first file will be erased (remove line 220 if you do not
want this). The third parameter allows you to determine the working
space of the procedure; the larger this space, the quicker the
execution:: 

    100 DEFine PROCedure APPEND (file1$,file2$,bufsize) 
    110   LOCal length,buffer,file1,file2,part 
    120   file1=FOP_IN(file1$): length=FLEN(#file1) 
    130   buffer=ALCHP(length) 
    140   file2=FOPEN(file2$) 
    150   IF file2=-7 THEN file2=FOP_NEW(file2$) 
    160   GET #file2 \1E9 
    170   FOR part=0 TO INT(length/bufsize) 
    180     bufsize=FREAD(#file1,buffer,bufsize)
    190     FWRITE #file2,buffer,bufsize 
    200   END FOR part 
    210   CLOSE #file1, #file2: RECHP buffer 
    220   DELETE file1$ 
    230 END DEFine APPEND

It can be called as follows::
    
    APPEND "ram1_tumb_tmp" TO "flp2_tump_dat",20480

**NOTE**

If the channel number supplied to FREAD does not refer to a file, then
the error -15 (bad parameter) will be reported after it has done its
work. This behaviour is pretty strange.

**CROSS-REFERENCE**

:ref:`fread-dlr`, :ref:`fwrite`,
:ref:`lbytes`, :ref:`sbytes`,
:ref:`get`, :ref:`put`.

--------------


..  _fread-dlr:

FREAD$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FREAD$ ([#ch], length)                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The FREAD$ function is very similar to the FREAD command: A fixed
number of characters is read from a channel (default #0) and returned as
a string. FREAD$ does not stop with an error if the end of file is
reached - you have to detect this by testing if the length of the
returned string is really length.

**Example**

MYCOPY copies a file with flexible buffering up to 32k, eg. type::

    MYCOPY "mycopy_bas" TO "ram2_whatever_dat", 1000
    
to use a 1000 bytes buffer. The larger the buffer, the faster the
file is copied; try a one byte buffer to see the difference! Ok, here is
the listing::

    100 DEFine PROCedure MYCOPY (file1$, file2$, bufsiz%) 
    110   LOCal ch1, ch2, buffer$ 
    120   ch1 = FOP_IN(file1$) 
    130   ch2 = FOP_NEW(file2$) 
    140   REPeat copying 
    150     buffer$ = FREAD$(#ch1, bufsiz%)
    160     PRINT#ch2,buffer$; 
    170     IF LEN(buffer$) < bufsiz% THEN EXIT copying
    180   END REPeat copying 
    190   CLOSE #ch1, #ch2 
    200 END DEFine MYCOPY

**CROSS-REFERENCE**

:ref:`input-dlr`,
:ref:`fwrite-dlr`, :ref:`copy`,
:ref:`get-byte-dlr`

--------------


..  _free:

FREE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FREE                                                             |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns the largest block of the available free memory.
This can be less than the actual free memory if the heap has become
fragmented (see DEL\_DEFB).

**CROSS-REFERENCE**

See also :ref:`free-mem` and :ref:`tpfree`.

::

    x=ALCHP(FREE)
    
reserves the largest piece of memory available.

--------------
 
..  _free-fast:

FREE\_FAST
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FREE\_FAST                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT for QVME (v2.31+)                                    |
+----------+-------------------------------------------------------------------+

The Atari TT recognises two types of RAM, standard ST RAM (up to
10MB) and FastRAM (otherwise known as TT RAM) which is specifically
designed for the Atari TT and works about twice as fast as the standard
ST RAM. 

The QL emulator can use both types of RAM but will only
recognise and use a maximum 4MB of standard ST RAM. 

If FastRAM is
available, the Emulator places the device drivers into this area in
order to speed them up as well as freeing additional standard ST RAM.
However, if your programs are to access the FastRAM, they need to use
various new commands. FREE\_FAST is a function which returns the amount
of available FastRAM.

**CROSS-REFERENCE**

The other commands to access FastRAM are
:ref:`resfast`, and
:ref:`lresfast`.

Compare :ref:`respr`,
:ref:`alchp` and
:ref:`free-mem`.

--------------


..  _free-mem:

FREE\_MEM
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  FREE\_MEM                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

Exactly the same as :ref:`free`.

--------------


..  _freeze:

FREEZE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FREEZE switch (switch=ON or OFF)                                 |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The keys <CTRL><F5> cause the QL to stop working until any further
key (except <CTRL>, <SHIFT>, <ALT> and <CAPSLOCK>), including
<CTRL><F5>, is pressed, which will reactivate the QL. 

This keystroke is
generated by some commands to give the user a chance of reading the
output, eg. VIEW, EXTRAS, SXTRAS, WDIR. 

FREEZE OFF disables <CTRL><F5>, FREEZE ON reactivates it. 

**Example**

::

    FREEZE OFF 
    EXTRAS 
    FREEZE ON

--------------


..  _freeze-pct:

FREEZE%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  frozen = FREEZE%                                                 |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FREEZE% returns either 0 or 1 (for OFF or ON
respectively) if <CTRL><F5> has been disabled by FREEZE or not.

**Example**

::

    frozen = FREEZE%
    IF frozen THEN do_stuff: END IF
   
**CROSS-REFERENCE**

:ref:`on` and :ref:`off` are constant
expressions for 1 and 0. :ref:`freeze-pct` returns
the current state. Compare :ref:`freeze` and
:ref:`freeze-pct` to :ref:`break`
and :ref:`break-pct`.

--------------


..  _fserve:

FSERVE
======

+----------+-------------------------------------------------------------------+
| Syntax   || FSERVE or                                                        |
|          || FSERVE [device\_name] (THOR XVI - v6.41 only)                    |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II (hardware version only or SMS), THOR XVI              |
+----------+-------------------------------------------------------------------+

This command creates a small fileserver job named Server which allows
other network stations (slaves) to access all devices on the machine
where this fileserver is running (this is the Master). 

The fileserver
only works with the QNET network system, which itself only works
reliably if Toolkit II is installed as firmware (ie. on ROM or on EPROM)
(or if Toolkit II is installed as part of SMS) on all machines connected
to the network. 

To access a device on the Master, a prefix has to be
added to the device name. This prefix specifies the other machine by its
network number (see NET) which may range from 1 to 8. The prefix
consists of an n, the number of the remote station and an underscore,
ie: n1\_ .. n8\_. 

If an access fails for any reason, the sending machine
will not receive an acknowledgement from the receiving one. In such
cases, the network driver continues to try to get through for about 20
seconds and then reports 'Network aborted' (in #0) if it still cannot
communicate with the specified machine.

**Examples**

::

    OPEN#3,n3_scr: PRINT#3,"Bye.": FLUSH#3: CLOSE#3 
    WDIR n1_flp1_
    
::
    
    FORMAT n7_win1_

Be careful with this sort of thing!

::

    SAVE n2_ram1_PROGGY_bas

**NOTE 1**

All commands which use the SD.EXTOP or SD.FOUNT machine code calls will
not work across the network: CHAR\_USE for example. This does not
necessarily mean that these commands report errors: CHAR\_USE, for
instance, changes the character set to a strange pattern. FORMAT will
also fail over the Network. ED and EDIT also cannot be used to edit a
program on a window opened over the Network.

**NOTE 2**

Although windows (scr\_ and con\_ devices) are normally not buffered,
this will be the case if they are opened across the network. This
affects just text output, all other operations (BORDER, INK, CLS, WINDOW
etc.) are performed on the host QL when issued. The buffer of 256 bytes
is located in the sending QL and flushed automatically if full.
Otherwise a CLOSE command forces the buffer contents to be sent (the
FLUSH command will not work to send the buffer contents). See the
Drivers section in the Appendix for further details on Networks.

**NOTE 3**

If a channel was opened by a slave via the network and this QL is
later removed from the network - say by unplugging the network lead or
by resetting the machine, then the channel is left open. As all such
channels are owned by the Server job, they can be flushed and closed by
removing and restarting the job::

    RJOB Server 
    FSERVE

Take care that all operations being carried out by other stations on
the local machine (where the fileserver is to be removed) have finished
or have been suspended.

**NOTE 4**

Due to checksum tests, data transmission across the network is
practically error free. There is still a very small statistical
possibility of transmission errors but really extensive experiments
(moving megabytes of data) did not even produce one.

**NOTE 5**

Although a normal file name can be of any length up to a maximum of 41
characters (including the device name), if the file is to be accessed
across the network, this is reduced to a maximum of 39 characters
(including the network prefix). For example::

    OPEN #3,flp1_Quill_letters_Minerva2_update_doc239 
    OPEN #3,n1_win1_Quill_letters_Minerva2b_updates

will work, whereas the following two commands report 'Not Found'
without attempting to access the drives::

    OPEN #4,flp1_Quill_letters_Minerva2_update_doc2392 
    OPEN #4,n1_win1_Quill_letters2_Minerva2b_updates

**NOTE 6**

If you OPEN a con\_ device over the Network (onto a Master machine's
screen) and try to use INPUT to read a variable entered on that Master,
there are problems here in that the delete keys on the Master which is
displaying (and editing) the text displayed in the con\_ device do not
work properly, leaving splodges on the screen. You can use IO\_TRAP and
QTRAP to call cursor positioning routines on the Master and then print
spaces to overwrite the deleted characters, using IO\_TRAP or QTRAP to
move the cursor back to the correct position and possibly pan the window
to get rid of excess characters. This technique was used to good effect
in the NetPal program in DIY Toolkit (Vol N).

**NOTE 7**

If you try to use a Toolkit II command such as DIR to direct the output
onto a window which has been OPENed over the Network, when it reaches
the bottom of a page, the Toolkit II command automatically generates a
<CTRL><F5> at the slave machine end which can only be cleared by
pressing a key on the slave machine's keyboard.

**THOR XVI NOTE**

The THOR XVI version of this command allows you to send, for example, a
continuous log of status messages to a file or device, eg. FSERVE
scr\_512x256a0x0. This is however really only useful for debugging
network programs or to analyse network traffic.

**CROSS-REFERENCE**

The fileserver job can be removed with :ref:`rjob`,
:ref:`kjob`, :ref:`kill` etc. or
by using a desktop application (such as QPAC2). See
:ref:`net` and :ref:`nfs-use`
for further information on networking. 

Refer to the original
documentation of Toolkit II and the Device Drivers Appendix for
technical details. :ref:`sernet` and
:ref:`midinet` create fileservers for other
Networks supported by SMSQ/E and the Atari ST Emulators.

--------------


..  _fseth-dlr:

FSETH$
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FSETH$ [#ch,] header$                                            |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FSETH$ is a command which is the counterpart of FGETH$: it accepts
either a 14 or 64 bytes long string which contains a file header (or at
least the first part of that) and sends that file header to the
specified channel (default #3).

**CROSS-REFERENCE**

See :ref:`heads` and
:ref:`sethead`!

--------------


..  _ftest:

FTEST
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FTEST (name)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

The function FTEST is designed to allow you to test for the status of
a file with the specified name. It will return a value of 0 if the given
name can be opened for input only. It may however return a negative
number representing an error code which would result if you tried to
OPEN or OPEN\_IN that file.

**NOTE 1**

The return of -6 (channel not open) has a special meaning in relation to
this function, it means that the function could not find any room in the
channel table to try and access the file.

**NOTE 2**

Due to the nature of the command, name can be used to represent any
valid device, and could therefore, for example, be used to check if a
resolution of 768x280 pixels is supported::

    100 a$='scr_768x280a0x0' 
    110 IF FTEST(a$)<0 
    120   a$='scr_512x256a0x0' 
    130 END IF 
    140 OPEN #3,a$

**NOTE 3**

On Level-2 and Level-3 devices, there is always a file with the same
name as the actual name of the device (eg. 'flp1\_'). This therefore
allows you to check if a medium is present in a Level-2 device::

    IF FTEST(flp1\_)<0 THEN PRINT 'Please insert disk'
    
You must however be aware that on Level-1 devices, it is unlikely
that such a file will be present and that FTEST will return -7 even if
there is a disk present.

**NOTE 4**

FTEST will not warn you if a disk is read only, which can create
problems.

**CROSS-REFERENCE**

:ref:`fopen` and :ref:`fop-in`
allow you to open files safely.
:ref:`dmedium-rdonly` can be used to find
out if a disk is write protected.

--------------


..  _ftyp:

FTYP
====

+----------+-------------------------------------------------------------------+
| Syntax   || FTYP [(#channel)] or                                             |
|          || FTYP (\\file) (Toolkit II and THOR only)                         |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, THOR XVI, BTool                                      |
+----------+-------------------------------------------------------------------+

This function returns the file type of a file which is already open
as #channel (the default channel is #3) or else the second variant can
be used (which supports the Toolkit II default data device and
sub-directories) to check a given file. 

The file type is one byte in the
file header which by convention represents the type of the file. There
are only four standard types: 

- FTYP = 1 are executable jobs (normally suffixed \_exe); 
- FTYP = 2 are Sinclair Relocatable Object File (SROFF) modules (normally suffixed \_REL); 
- FTYP = 255 are sub-directories on level-2 and level-3 drivers;
- FTYP = 0 are everything else. 

However, some programmers use their own file
types for their applications, for example: 

- FTYP = 2 may also signify sub-directory declaration files used by Ralf Biedermann's flp utility and Hirschbiegel drivers; 
- FTYP = 3 are sub-directories on THOR computers.
- FTYP = 4represents font files used by the PAINTER. 
- FTYP = 5 are pattern files used by the PAINTER. 
- FTYP = 6 or 11 are compressed screens generated by the PAINTER.
- FTYP = 70 is used to represent separation files from packages distributed by the Intergroup Freeware Exchange.

**WARNING**

Sometimes machine code files (Toolkits, for instance) which should be
loaded with LBYTES, LRESPR etc. have the file type 1. Executing such a
file will lead to a crash in most cases, UNJOB changes the file type
back to 0. Authors with a lot of skill write machine code which can be
either executed as a job or loaded as a resident command executing the
job from memory when called.

**CROSS-REFERENCE**

See :ref:`headr` for reading the whole file header
and :ref:`ex` for executing jobs.
:ref:`file-type` does the same as
:ref:`ftyp` but has a slightly different syntax.

--------------


..  _function:

FuNction
========

+----------+-------------------------------------------------------------------+
| Syntax   |  ... FuNction                                                     |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This keyword forms part of the structure DEFine FuNction. As such, it
cannot be used on its own within a program - this will cause a 'bad
line' error.

**CROSS-REFERENCE**

Please refer to the individual structure descriptions for more details.

--------------


..  _fupdt:

FUPDT
=====

+----------+-------------------------------------------------------------------+
| Syntax   || FUPDT [(#channel)] or                                            |
|          || FUPDT (\\file) (Toolkit II only)                                 |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, BTool                                                |
+----------+-------------------------------------------------------------------+

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
of the file. If your machine has a battery backed realtime clock, then
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

--------------


..  _fvers:

FVERS
=====

+----------+-------------------------------------------------------------------+
| Syntax   || FVERS [(#channel)] or                                            |
|          || FVERS (\\file)                                                   |
+----------+-------------------------------------------------------------------+
| Location || Level-2 Device Drivers                                           |
+----------+-------------------------------------------------------------------+

This function reads the version number of the given file (or of the
file attached to the specified channel {default #3} if the first variant
is used). 

The version numbers can range from 0 to 2\ :sup:`16`-1 (65535)
and generally indicate how often a file has been amended. If a file was
created on a level-1 device driver system, its version number is zero
(0), while newly created files on level-2 device drivers will have the
version number 1 after they have been closed. FVERS supports Toolkit
II's default data device and sub-directories. 

If the first variant is
used, the default channel is #3 if none is specified. 

Each time that a
file is amended on level-2 and level-3 drivers, the version number is
increased by one. If the version reaches its limit of 65535, it will
start at version 1 again. A file has to be re-opened to change its
version by more than one. After the file has been amended, the version
will only increase after a FLUSH or CLOSE. 

Unfortunately current
versions of SAVE and SBYTES do not increase the version number because
they overwrite existing files instead of truncating them.

**Example**

::

    OPEN_OVER#3,test_tmp: REMark create the file 
    PRINT#3,"just a line": REMark write a line to the file 
    PRINT FVERS(#3): REMark 0, neither flushed nor closed 
    CLOSE#3: REMark close file 
    PRINT FVERS(\test_tmp): REMark 1 
    OPEN#3,test_tmp: REMark re-open file 
    PRINT FVERS(#3): REMark 1, nothing changed yet 
    PRINT#3,"replace the line": REMark amend file
    PRINT FVERS(#3): REMark still 1 not yet flushed 
    FLUSH#3: REMark write slave blocks to file 
    PRINT FVERS(#3): REMark now it's 2 
    FLUSH#3: REMark flush again 
    PRINT FVERS(#3): REMark  2
    PRINT#3,"next line": REMark change file again 
    CLOSE#3: REMark close file 
    PRINT FVERS(\test_tmp): REMark  still 2

**NOTE**

The file version number is not preserved if the file is overwritten.
However, if you make a copy of a file, this keeps the same version
number as the original, but not on Level-1 drivers.

**SMS NOTE**

If you use the SAVE command without a filename to save a previously
loaded SuperBASIC program, the file version number will be increased by
one.

**CROSS-REFERENCE**

:ref:`set-fvers` allows you to set the version
number.

--------------


..  _fwrite:

FWRITE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FWRITE #ch,address,bytes                                         |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

The command FWRITE reads a given number of bytes (bytes) from memory
(starting at address) and writes them to the given channel, which should
point to a file.

**Example**

A procedure which adds a file to another already existing file -
CONCAT cannot do so. This is a rather primitive version which grabs as
much memory as necessary and uses only TinyToolkit extensions. The
program is very primitive (not in its use of these extensions), but
because the memory management of the routine is simple (but fast) and as
FILE\_LEN does not support default devices and sub-directories, full
filenames have to be passed. 

See :ref:`fread` for an enhanced version! 

::

    100 DEFine PROCedure APPEND (file1$,file2$) 
    110   length=FILE_LEN(file1$) 
    120   buffer=GRAB(length) 
    130   LBYTES file1$,buffer 
    140   ch=FOPEN(file1$): FILE_PTRA#3,1E9 
    150   FWRITE #ch,buffer,length 
    160   CLOSE#ch: RELEASE buffer 
    170 END DEFine APPEND

The procedure is called by APPEND file1$ TO file2$, which will add
the first file to the second file. First, a buffer of the size of the
first file is reserved in RAM, then, this file is read into the buffer.
Now the second file is opened, the file pointer moved to the end of it
and the whole buffer is then appended to the end of the file. Finally,
the channel is closed and the buffer RELEASEd.

**NOTE**

If the channel number does not refer to a file or even if the channel
has not yet been opened, FWRITE will report error -15 (bad parameter)
after it has completed its work. This behaviour is pretty strange.

**CROSS-REFERENCE**

:ref:`fread`, :ref:`lbytes`,
:ref:`sbytes`, :ref:`get`,
:ref:`put`. If you intend to use
:ref:`append`, please see
:ref:`fread` for a better version.

--------------


..  _fwrite-dlr:

FWRITE$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  FWRITE$ [#ch,] string$                                           |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

FWRITE$ is a command (not a function as the $ may suggest) and writes
string$ to #ch (default #1). It's the same as PRINT#ch,string$;.

**Example**

::

    FWRITE$ "Hello World"

**NOTE**

The Line feed character {CHR$(10)} is *not* printed at the end of the
text.

--------------


..  _fxtra:

FXTRA
=====

+----------+-------------------------------------------------------------------+
| Syntax   || FXTRA [(#ch)] or                                                 |
|          || FXTRA \\file (Toolkit II only)                                   |
+----------+-------------------------------------------------------------------+
| Location || Toolkit II, BTool                                                |
+----------+-------------------------------------------------------------------+

This is a function which returns part of the file header relating to
the specified file (or the file attached to the specified channel
{default #3} if the first variant is used). See FGETH$ for what part of
the file header FXTRA returns. The Toolkit II default data device and
sub-directories are supported. If the first variant is used, the default
channel is #3.

**CROSS-REFERENCE**

See :ref:`fdat`, :ref:`fbkdt`,
:ref:`fupdt` and :ref:`ftyp`
which return similar information.

