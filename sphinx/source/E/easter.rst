..  _easter:

EASTER
======

+----------+-------------------------------------------------------------------+
| Syntax   |  EASTER (year%) where year% >= 1583                               |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function calculates the date of Easter Sunday for any given year after 1583
(when the Gregorian calender was introduced by Pope Gregory XIII to replace the
Julian calender of Julius Ceasar which had been in use since 46 BC). EASTER
returns the date as a floating point number, where the day is the integer part
of the number and the month is given by the digits following the floating
point, eg. PRINT EASTER(1993)  shows 11.4 (April, 11th)

**Example**

Easter Sunday is used as a basis to fix other clerical days, so if two
years have Easter Sunday on the same day, the other holy dates are
identical, too::

    100 INPUT "Year=";year
    110 east1=EASTER(year)
    120 FOR y=year+1 TO 32767
    130   east2=EASTER(y)
    140   IF east1=east2 THEN
    150     PRINT "Next Easter Sunday on"!east1;". is in"!y;"."
    160     EXIT y
    170   END IF
    180 END FOR y

**NOTE**

EASTER does not return the correct value on SMSQ/E for some reason.

**CROSS-REFERENCE**

:ref:`gregor`

--------------


