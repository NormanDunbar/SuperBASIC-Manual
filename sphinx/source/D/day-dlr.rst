..  _day-dlr:

DAY$
====

+----------+-------------------------------------------------------------------+
| Syntax   | DAY$ [(date)] or                                                  |
|          |                                                                   |
|          | DAY$ (year,month,day,hour,minute [,second]) (SMS v2.57+ only)     |
+----------+-------------------------------------------------------------------+
| Location | QL ROM                                                            |
+----------+-------------------------------------------------------------------+

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


