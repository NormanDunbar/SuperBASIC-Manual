..  _chbase:

CHBASE
======

+----------+------------------------------------------------------------------+
| Syntax   | CHBASE [(#ch)] or                                                |
|          |                                                                  |
|          | CHBASE (chidx%, chtag%)                                          |
+----------+------------------------------------------------------------------+
| Location | QBASE (DIY Toolkit Vol Q)                                        |
+----------+------------------------------------------------------------------+

CHBASE is a function which returns the start address of a window
definition block. This block contains a wide range of information about
a window, such as the size and colour settings. Refer to the QDOS
Reference manual Section 18.7 and 18.9.1 (or similar) for further
details.

The window can be either specified by its SuperBASIC channel number, eg:
CHBASE(#2), where the default is #1, or the internal channel ID; which
must be split into index (chidx%) and tag (chtag%) before being passed
to CHBASE.

The latter syntax allows you to access the windows of jobs other than
the current job.

Inside knowledge about the operating system is necessary to access these
tables. Please refer to QDOS system documentation. The structure of the
window definition block is different under Thors, original QLs and the
Pointer Environment.

CHBASE returns small negative integers if an error occurs, representing
the QDOS error code:

-  -1 = Window is currently in use, eg. awaiting input.
-  -6 = No such channel exists.
-  -15 = It's a channel but not a window.

**Example 1**

The current INK colour is found at offset $46, so: INK 7: PRINT PEEK(
CHBASE+ HEX('46') ) will print 7, because of the INK 7 command.

**Example 2**

It is usually not recommended to close and re-open SuperBASIC channel
#0. The following lines check if this has happened, although they will
only work under the SuperBASIC interpreter(!). You will find the
condition in line 100 is always true for Minerva's MultiBASIC
interpreters and SMS's SBASIC interpreters: this does no harm - the
example is more or less just an example of the syntax of CHBASE...

::

    100 IF CHBASE(0,0) <> CHBASE(#0) THEN
    110   UNDER 1: PRINT "Warning": UNDER 0
    120   PRINT "Channel #0 is not in it's original state."
    130 END IF

**CROSS-REFERENCE**

:ref:`cbase`.

See also :ref:`chan-b-pct` and related functions.

