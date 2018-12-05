..  _sdate:

SDATE
=====

+----------+------------------------------------------------------------------+
| Syntax   | SDATE year,month,day,hours,minutes,seconds                       |
|          |                                                                  |
|          | SDATE year,month,day,hours,minutes (SMS v2.57+)                  |
|          |                                                                  |
|          | SDATE time (Minerva, SMS)  or                                    |
|          |                                                                  |
|          | SDATE TO time (THOR XVI)                                         |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

The QL has an internal clock which contains the current date and time.
Unfortunately, this clock is corrupted every time that the QL is
switched on and off (and even in some cases when the QL is reset). This
means that the clock has to be set manually every time that the system
is re-booted. Because of this, various battery-backed clocks have
appeared on the market which retain the time whilst the QL is turned off
and then the QL clock is generally reset to the same time as the battery
backed clock when it is switched back on.

This command allows you to set
the internal QL clock to a specified date and time. Each parameter in
the first syntax must be a numeric value.

The second syntax is similar
to the first, but is only supported on later versions of SMS. This
variant accepts just five parameters and assumes that the seconds is to
be set to zero.

The third and fourth syntaxes allow you to set the time
and date by the number of seconds since Midnight on 1st January 1961.
This thus allows you to copy the date from one QL to another very simply
over the Network::

    100 temp_file$='n1_ram1_temp'
    110 er=FOP_NEW(temp_file$)
    120 IF er>0
    130 CLOSE #er:SDATE TO FUPDT(\temp_file$)
    140 DELETE temp_file$
    150 END IF

**Example**

::

    SDATE 1993,1,1,0,0,0

sets the internal clock to the start of 1993.

**NOTE 1**

This may also affect battery backed clocks - see their instructions. In
particular on the THOR XVI the battery backed clock is automatically
reset, whereas on earlier THORs the command SET\_CLOCK was needed.

**NOTE 2**

Unfortunately, current versions of Minerva and SMS will not accept the
THOR's syntax, nor vice versa.

**NOTE 3**

On the QXL, before v2.57 of SMS the time would not be set correctly if
seconds=0 or seconds=1. The clock could still be wrong by 1 second until
v2.73 which fixed this problem on MOST PCs.

**CROSS-REFERENCE**

:ref:`prot-date` allows you to prevent
:ref:`sdate` from altering a battery backed clock.
:ref:`adate` allows you to alter the time by a
specified number of seconds. :ref:`date` lets you
read the current date and time as a single figure.
:ref:`date-dlr` and :ref:`day-dlr`
return various details about the current date and time. These functions
can also be used to find out details concerning a given date without
having to use :ref:`sdate` beforehand to change the
system date. :ref:`a-sdate` and
:ref:`set-clock` alter the battery backed
clocks on the ST/QL Emulator and THOR respectively.

--------------


