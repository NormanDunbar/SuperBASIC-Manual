..  _p-env:

P\_ENV
======

+----------+-------------------------------------------------------------------+
| Syntax   |  P\_ENV (#ch)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  MULTI                                                            |
+----------+-------------------------------------------------------------------+

This function detects whether the given channel is running under the
Pointer Environment and returns:

*   0 if the Pointer Environment is not connected to that channel, or no parameter was used, or #ch is not a screen channel;
*   1 if the Pointer Interface (ptr\_gen) is active in that channel;
*   2 if the Pointer Interface and the Window Manager (wman) are present for that channel.

**Example**

All programs which need the Pointer Environment to work, should check to
see if it is present. This short program does so::

    100 ch=FOPEN(con_2x2a0x0): p=P_ENV(#ch): CLOSE#ch
    110 IF p<2 THEN
    120   PRINT "This program does not run without the P.E.,"
    130   PRINT "so program execution has to stop here."
    140   PRINT " Press any key...": PAUSE 400
    150   STOP
    160 END IF

**CROSS-REFERENCE**

:ref:`wman-dlr` finds the version of the Window Manager
and :ref:`qram-dlr` the version of the Pointer
Interface. These functions can also be used to detect the presence of
the Pointer Environment (=Window Manager & Pointer Interface).

