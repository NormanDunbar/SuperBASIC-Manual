..  _date-dlr:

DATE$
=====

+----------+-------------------------------------------------------------------+
| Syntax   | DATE$ [(date)] or                                                 |
|          |                                                                   |
|          | DATE$ (year,month,day,hour,minute [,second])(SMS v2.57+ only)     |
+----------+-------------------------------------------------------------------+
| Location | QL ROM                                                            |
+----------+-------------------------------------------------------------------+

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

