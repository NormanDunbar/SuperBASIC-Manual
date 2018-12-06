..  _chanid:

CHANID
======

+----------+------------------------------------------------------------------+
| Syntax   | CHANID [(#ch)]Btool only or                                      |
|          |                                                                  |
|          | CHANID (#ch)TinyToolkit                                          |
+----------+------------------------------------------------------------------+
| Location | BTool, TinyToolkit                                               |
+----------+------------------------------------------------------------------+

QDOS uses a different sort of channel number internally to those used by
SuperBASIC. These so-called channel IDs have the advantage that two
channels will never have the same channel ID, even if some channels have
been closed for a long time.

The function CHANID expects an open SuperBASIC channel #ch (a default
channel of #1 is allowed by Btool) and returns its current internal
channel ID.

**Example**

::

    100 OPEN#3,con_2x1
    110 PRINT CHANID(#3)
    120 CLOSE#3: OPEN#3,con_2x1
    130 PRINT CHANID(#3)
    140 CLOSE#3

**CROSS-REFERENCE**

:ref:`chanid` is intended for use with
:ref:`file-open`.

:ref:`channel-id` is the same as the Btool
variant.

See SET\_CHANNEL also.

