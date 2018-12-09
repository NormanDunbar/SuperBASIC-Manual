..  _year-pct:

YEAR%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  YEAR% [datestamp]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the :ref:`date` and :ref:`date-dlr` functions, by returning the year
number corresponding to the given datestamp, or current date, if no datestamp
was given.

**Examples**

::

    PRINT YEAR% (0)

will print the year part of the QL's epoch, 1961

::

    PRINT YEAR%

will print the current year number.


**CROSS-REFERENCE**

See :ref:`date`, :ref:`month-pct`.

