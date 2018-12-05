..  _synch-pct:

SYNCH%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  SYNCH%                                                           |
+----------+-------------------------------------------------------------------+
| Location |  KMOUSE, MOUSE (DIY Toolkit - Vol I)                              |
+----------+-------------------------------------------------------------------+

This function is only used to debug the DIY Toolkit mouse drivers. It
returns a value which is in the range 1...3 for a two button mouse and
1...5 for a three button mouse. The value indicates which byte of the
mouse message is due next and therefore when being used, you should see
it circling between the upper and lower limits of the range. However, if
the byte is corrupt or lost, then the value returned by this function
will be zero. This can indicate problems with either your serial port or
the interface to the mouse - if the former, you should consider getting
Hermes for your computer.

**CROSS-REFERENCE**

See :ref:`ptr-on` and
:ref:`ptr-fn-pct`.

--------------


