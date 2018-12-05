..  _fbkdt:

FBKDT
=====

+----------+------------------------------------------------------------------+
| Syntax   | FBKDT [(#channel)] or                                            |
|          |                                                                  |
|          | FBKDT (\\file)                                                   |
+----------+------------------------------------------------------------------+
| Location | Level-2 Device Drivers, SMS                                      |
+----------+------------------------------------------------------------------+

It is proposed that this function be used to return the date on which
a given file was last backed up. Current versions of SuperBASIC
commands, such as COPY and WCOPY do not set the back-up date of the file
being copied, although some software will do this, WinBack for example.

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
since they were last backed up. TinyToolkit's :ref:`tconnect` or DIY-TK's
:ref:`qlink` is necessary to use this example. This can be used for example by
entering the line::

    BACKUP flp1_ TO flp2_

Although sub-directories and the default data device are fully
supported on the medium being backed-up, the procedures would need
modification to enable them to create similar sub-directories on the
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


