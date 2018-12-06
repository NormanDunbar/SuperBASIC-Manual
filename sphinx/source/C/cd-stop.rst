..  _cd-stop:

CD\_STOP
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_STOP                                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This command has one of two effects.

If an Audio CD is already playing, then the disk is paused.

If you have already paused the Audio CD, then a complete stop is
performed.

**Example**

The following procedure brings the CD to a complete stop -

you cannot resume playing.

::

    1000 DEFine PROCedure STOP_CD
    1010 CD_STOP
    1020 IF CD_ISPAUSED : CD_STOP
    1030 END DEFine

**WARNING**

On some laptop PCs, it has been noted that if you are playing an Audio
CD and close the case without issuing CD\_STOP, when you re-open the
case QPC will have crashed.

**CROSS-REFERENCE**

:ref:`cd-resume` allows you to resume playing
an Audio CD that has been paused.

:ref:`cd-play` allows you to play an Audio CD
that is at a complete stop.

:ref:`cd-eject` opens the drive drawer.

:ref:`cd-close` closes the drive drawer.

