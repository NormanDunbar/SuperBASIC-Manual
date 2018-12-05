..  _adate:

ADATE
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  ADATE seconds                                                    |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

ADATE adjusts the current system clock by the given number of seconds,
so ADATE 60 would advance the internal clock by a minute and ADATE
-86400 sets it back by one day.

**Example**

Apart from adjusting the clock relatively, ADATE can also be used to set
the time and date absolutely. This is because the function DATE contains
the system time in seconds after a fictional 'Birth Date' (Midnight on 1
January 1961 on all ROM implementations):-

ADATE -DATE will set the clock to that Birth Date (when DATE=0)

ADATE 1E9 advances the clock by roughly 31 years and nine months.

ADATEs can then be combined by adding values:

ADATE 1E9-DATE sets the clock to DATE$="1992 Sep 09 01:46:40"

**NOTE 1**

ADATE generally needs one second to execute because some ROMs (notably
the THOR XVI, MG ROM and Minerva) will wait for the next full second
before amending the time (therefore do not use ADATE 1 to wind the clock
on!).

**NOTE 2**

Any attempts to wind the system clock back to earlier than 1st Jan 1961
will actually deduct the difference from 6th Feb 2097. However, the
system clock (on implementations other than Minerva and SMS) runs into
trouble here because any date later than 3.14:07 on 19th Jan 2029 should
produce a negative number (!) whenever the function DATE is used.
However, on non-Minerva ROMs and non-SMS systems, a positive number is
produced, preventing DATE from recognising later dates.

The system clock itself, does however appear able to support dates and
times between 0.0:00 on 1st Jan 1961 and 6.28:15 on 6th Feb 2097.

**NOTE 3**

On Minerva v1.63 and Minerva v1.98, the ADATE command did not work
properly - use SDATE DATE+seconds instead!

**WARNING**

ADATE will affect the time on battery backed clocks unless they are
protected in some way (see PROT\_DATE).

**CROSS-REFERENCE**

:ref:`date-dlr` returns the current system date and
time as a string, :ref:`date` does the same but in a
less readable form - in seconds after the initial date.

:ref:`sdate` sets the clock to an absolute date and
time.

Battery backed clocks generally have their own methods of altering their
date and time.

--------------


