..  _cd-isclosed:

CD\_ISCLOSED
============

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_ISCLOSED                                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This function will return 1 (True) if the CD drawer is closed, otherwise
it will return 0.

**Example**

::

    100 IF NOT CD_ISPLAYING
    110   IF NOT CD_ISCLOSED : CD_CLOSE
    120   IF CD_ISINSERTED : CD_PLAY
    130 END IF

**CROSS-REFERENCE**

:ref:`cd-close` closes the CD drawer.

--------------


