..  _date:

DATE
====

+----------+-------------------------------------------------------------------+
| Syntax   | DATE or                                                           |
|          |                                                                   |
|          | DATE (year,month,day,hour,minute,second)(Minerva & NewDate)  or   |
|          |                                                                   |
|          | DATE (year,month,day,hour,minute [,second])(SMS v2.57+)           |
+----------+-------------------------------------------------------------------+
| Location | QL ROM                                                            |
+----------+-------------------------------------------------------------------+


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


