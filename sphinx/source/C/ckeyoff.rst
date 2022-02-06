..  _ckeyoff:

CKEYOFF
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  CKEYOFF                                                          |
+----------+-------------------------------------------------------------------+
| Location |  Pointer Interface (v1.23 or later)                               |
+----------+-------------------------------------------------------------------+

Normally, the Pointer Interface will recognise the cursor keys in the
same way as it recognises the mouse, thus allowing you to move the
pointer around the screen using the keyboard.

You may however prefer that the cursor keys had no effect on the pointer
- the solution is simple - just use the command CKEYOFF.

**NOTE**

There were problems with this command prior to v1.56.

**Note 2**

At some point CKEYOFFstarted to have to take a channel number, ie
CKEYOFF #channel.

If you dont give a
channel number the commands try to open their own channel - that hybrid
number 0/1, as do a number of IO commands (at least in SMSQ/E). All well
and good. But if you, say, open your first channel as number 3, as happens
automatically if your first channel in a daughter SBASIC or Qlib compiled
job, and you open it with ch = FOPEN("con_") then, if that channel is
OUTLiNed to be smaller than the default channel, the call fails and returns
to the routine - which gives up. But doesnt say anything! However, now
there is dangling, open channel in the main channel table that SBASIC
doesnt know about. So next time you use this command yet another channel is
opened in the main channel table! And so it goes on ad finitum until the
job is killed - or the system chokes.

This is a rare circumstance, admittedly, but it is still a bug.


The bug fix is that
if the circumstances described pertain, the call will return with an Out of
Range error.



**CROSS-REFERENCE**

:ref:`ckeyon` tells the Pointer Interface to
recognise the cursor keys again.

