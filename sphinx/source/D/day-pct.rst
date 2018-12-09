..  _day-pct:

DAY%
====

+----------+-------------------------------------------------------------------+
| Syntax   |  DAY% [datestamp]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the :ref:`date` and :ref:`date-dlr` functions, by returning the day
number corresponding to the given datestamp, or current date, if no datestamp
was given.

**Examples**

::

    PRINT DAY% (0)

will print the day part of the QL's epoch, 1 for 1st of January

::

    PRINT DAY%

will print the current day number.


**CROSS-REFERENCE**

See :ref:`date`, :ref:`year-pct`, :ref:`month-pct`.

