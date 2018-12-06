..  _gregor:

GREGOR
======

+----------+-------------------------------------------------------------------+
| Syntax   |  GREGOR (day%, month%, year%)                                     |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function GREGOR takes three integers (floats & longs are rounded to the
nearest integer) to specify a date and returns the weekday as a number
from 1 to 7 where:

- 1 = Sunday, ( See Note 1 !)
- 2 = Monday,
- 3 = Tuesday,
- 4 = Wednesday,
- 5 = Thursday,
- 6 = Friday,
- 7 = Saturday.

As the name of the function suggests GREGOR uses the Gregorian calender.

This was introduced in 1583, so GREGOR has to refuse earlier years. Invalid
parameters are not reported by breaking with an error (unless one of the
parameters is out of integer range) but by returning zero.

**Example**

Print your own calendar!

::

    100 CLS
    110 REPeat getmonth
    120   INPUT "Year:"!year;TO 12;"Month:"!month
    130   firstday$ = GREGOR(1,month,year)
    135   firstday=firstday$(1)
    140   IF NOT firstday THEN
    150     PRINT "Invalid input."
    160   ELSE EXIT getmonth
    170   END IF
    180 END REPeat getmonth
    190 FOR lastday = 28 TO 31
    200   IF NOT GREGOR(lastday+1,month,year): EXIT lastday
    210 END FOR lastday
    220 :
    230 PRINT \" Sun Mon Tue Wed Thu Fri Sat"
    240 PRINT FILL$(" ",4*(firstday-1));
    250 FOR day = 1 TO lastday
    260   PRINT FILL$(" ",4-LEN(day));day;
    265   xday$=GREGOR(day,month,year)
    270   IF xday$(1) = 7 THEN PRINT
    280 END FOR day

**NOTE 1**

GREGOR was originally intended to return 1 for Monday, 2 for Tuesday and
so on. The current version (v2.05) follows the Christian tradition where
Sunday was regarded as the first day of the week. The programming
example above corrects this by applying this interpretation and uses::

    230 PRINT " Sun Mon Tue Wed Thu Fri Sat"

instead of::

    230 PRINT " Mon Tue Wed Thu Fri Sat Sun".

**NOTE 2**

Current versions (v2.05) of this command include a bug which mean that
it will not work correctly on Minerva, SMSQ/E and possibly other ROMs.

**CROSS-REFERENCE**

:ref:`easter`, :ref:`day-dlr`

