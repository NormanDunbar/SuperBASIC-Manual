..  _cd-alltime:

CD\_ALLTIME
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_ALLTIME                                                      |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function returns the actual elapsed time in REDBOOK format from the
start of the CD which is being played at present.

**Example**

A procedure to give the currently elapsed time:

::

    100 DEFine PROCedure SHOW_TIME
    110 elapse%=CD_ALLTIME
    120 PRINT 'TOTAL ELAPSED TIME: ';CD_HOUR (elapse%);' HRS ';CD_MINUTE (elapse%);' MINS ';:
    130 PRINT CD_SECOND (elapse%);' SECS'
    130 END DEFine

**CROSS-REFERENCE**

:ref:`cd-play` plays specified tracks.

:ref:`cd-track` allows you to find out which
track is being played.

:ref:`cd-tracktime` allows you to find out
the total elapsed time on the current track.

:ref:`cd-red2hsg` allows you to convert
REDBOOK format to HSG Format.

:ref:`cd-hour`,
:ref:`cd-minute`,
:ref:`cd-second` allow you to convert REDBOOK
format into a more understandable form.

--------------


