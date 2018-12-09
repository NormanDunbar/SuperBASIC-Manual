..  _weekday-pct:

WEEKDAY%
========

+----------+-------------------------------------------------------------------+
| Syntax   |  WEEKDAY% [datestamp]                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the :ref:`date` and :ref:`date-dlr` functions, by returning the day of
the week as a number starting from 0 for Sunday corresponding to the given
datestamp, or current date, if no datestamp was given.

**Examples**

::

    PRINT WEEKDAY% (0)

will print the month part of the QL's epoch, 0 for Sunday, January 1st, 1961

::

    PRINT WEEKDAY%

will print the current weekday number, (0...6 for Sunday to Saturday).


**CROSS-REFERENCE**

See :ref:`date`, :ref:`year-pct`, :ref:`month-pct`, :ref:`day-pct`.

