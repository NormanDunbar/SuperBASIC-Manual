..  _month-pct:

MONTH%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MONTH% [datestamp]                                               |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the :ref:`date` and :ref:`date-dlr` functions, by returning the month
number corresponding to the given datestamp, or current date, if no datestamp
was given.

**Examples**

::

    PRINT MONTH% (0)

will print the month part of the QL's epoch, 1 for January

::

    PRINT MONTH%

will print the current month number, (1...12, starting with January).


**CROSS-REFERENCE**

See :ref:`date`, :ref:`year-pct`.

