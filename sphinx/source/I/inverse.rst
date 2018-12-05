..  _inverse:

INVERSE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  INVERSE [ #channel ]                                             |
+----------+-------------------------------------------------------------------+
| Location |  ALIAS (DIY Toolkit - Vol A)                                      |
+----------+-------------------------------------------------------------------+

This command provides the QL with a facility which is available on most
other implementations of BASIC - inverse video. What this command
actually does is swap over the values which have been set for the
specified window channel (default #1) for the STRIP and INK colours,
thereby making any further text which is PRINTed to that window stand
out. This means that for example, if you set the INK to 7 (white) and
the STRIP (or PAPER colour) to 2 (red), after INVERSE, text will be
printed in red INK on a white STRIP.

**Example**

::

    STRIP #2,7:INK #2,0:PRINT #2,'This text is normal'
    INVERSE #2:PRINT #2,'But this is in inverse video!!'

**CROSS-REFERENCE**

See also :ref:`ink` and
:ref:`strip`.

--------------


