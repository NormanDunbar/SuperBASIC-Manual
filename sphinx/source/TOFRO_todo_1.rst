

..  _year%:

YEAR%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  YEAR% [datestamp]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the DATE and DATE$ function, by returning the year
number corresponding to the given datestamp, or current date, if no datestamp
was given.

**Examples**

    PRINT YEAR% (0)

will print the year part of the QL's epoch, 1961

    PRINT YEAR%

will print the current year number.


**CROSS-REFERENCE**

See :ref:`date`
:ref:`month%`.



--------------

..  _month%:

MONTH%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MONTH% [datestamp]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the DATE and DATE$ function, by returning the month
number corresponding to the given datestamp, or current date, if no datestamp
was given.

**Examples**

    PRINT MONTH% (0)

will print the month part of the QL's epoch, 1 for January

    PRINT MONTH%

will print the current month number, (1...12, starting with January).


**CROSS-REFERENCE**

See :ref:`date`
:ref:`year%`.

--------------

..  _day%:

MONTH%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  DAY% [datestamp]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the DATE and DATE$ function, by returning the day
number corresponding to the given datestamp, or current date, if no datestamp
was given.

**Examples**

    PRINT DAY% (0)

will print the day part of the QL's epoch, 1 for 1st of January

    PRINT MONTH%

will print the current day number.


**CROSS-REFERENCE**

See :ref:`date`
:ref:`year%`.
:ref:`month%`.

--------------

..  _weekday%:

WEEKDAY%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  WEEKDAY% [datestamp]                                             |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function complements the DATE and DATE$ function, by returning the day of
the week as a number starting from 0 for Sunday corresponding to the given
datestamp, or current date, if no datestamp was given.

**Examples**

    PRINT WEEKDAY% (0)

will print the month part of the QL's epoch, 0 for Sunday, January 1st, 1961

    PRINT WEEKDAY%

will print the current weekday number, (0...6 for Sunday to Saturday).


**CROSS-REFERENCE**

See :ref:`date`
:ref:`year%`.
:ref:`month%`
:ref:`day%`

--------------

..  _hot_getstuff:

HOT_GETSTUFF$
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT_GETSTUFF$ [index]                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function returns the contents of the hotkey stuffer buffer. If given a
parameter of 0, or no parameter, it will return the current contents of the
stuffer buffer (like ALT-SPACE). A parameter of -1 gets the previous contents,
like ALT-SHIFT-SPACE

**Examples**

    result = HOT_GETSTUFF$           return current contents of stuffer buffer
    result = HOT_GETSTUFF$(0)        return current contents of stuffer buffer
    result = HOT_GETSTUFF$(-1)       return previous contents of stuffer buffer


**CROSS-REFERENCE**

See :ref:`get_stuff$`
:ref:`hot_stuff`.


--------------

..  _jobid:

JOBID
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  JOBID [({nr, tag} | <name>)]                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function returns the 32-bit job id of the job with the given details as a
decimal value. The optional parameters may be either a job number and job tag
(as displayed by the JOBS command), or the job name. If no parameters are
supplied, the Job ID number of the current job is returned.

**Examples**

    result = JOBID            returns the job ID of the current job
    result = JOBID(job_name$) returns the job ID of the job specified in job_name$
    result = JOBID$(nr, tag)  returns the job ID of the job specified by nr and tag


**CROSS-REFERENCE**

See :ref:`jobs`
:ref:`job%`.


--------------

..  _fex:

FEX
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FEX(file *[,{filex | #chx}]* [;cmd$])                                                   |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

Executes and returns the job ID of the job filename.
This function is a functional version of EX, with the same set of arguments,
that executes a job. In addition to what EX does, it returns the job ID of the
new job that was started.

**Examples**

    jId = FEX ("win1_XChange_xchange")

Will start Psion XChange in win1_xchange and return the job ID of the new job.

**NOTES**
In some combinations of SMSQ/E and FileInfo2 versions, there might be a clash of
extension names between FEX supplied as an SMSQ/E function (as described here)
and a function with the same name (but very different purpose) supplied by
FileInfo2. Later versions of FileInfo2 resolved this name clash by renaming the
corresponding function to EXF.

**CROSS-REFERENCE**

See :ref:`ex`
:ref:`fet`
:ref:`few`
:ref:`exec`.
:ref:`jobs`.


--------------

..  _fet:

FET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FET(file *[,{filex | #chx}]* [;cmd$])                                                    |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

Executes and returns the job ID of the job filename in suspended state (by
immediately setting the new job's priority to zero).
This function is a functional version of ET, with the same set of arguments,
that executes a job into suspended state for tracing with a monitor. In addition
to what ET does, it returns the job ID of the new job that was started.


**Examples**

    jId = FEX ("win1_XChange_xchange")

Will start Psion XChange in win1_xchange in suspended state and return the job
ID of the new job.



**CROSS-REFERENCE**

See :ref:`et`
:ref:`exec`.
:ref:`jobs`.

--------------

