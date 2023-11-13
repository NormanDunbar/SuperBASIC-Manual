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

At some point CKEYOFF required a channel number parameter, ie CKEYOFF
#channel. If you don't specify a channel number the command falls back on the current
S*BASIC's channel #0. 

Unfortunately, if there isn't already a channel #0 open, for example, a program might have opened
its first channel using:

1500 main = FOPEN("con\_")

In this case, the the CKEYOFF command will open a new console 
channel and then try to set the window size of that 
channel to the default size of 256x62. If, however, the program had already OUTLN'ed
#main to a smaller size, in any dimension, than 256x62, then this call will fail.

And here's the bug: Instead of closing the failed console channel, the command
simply returns without error. This leaves a "dangling" console channel open
without an S*BASIC handle. And each repeated call to CKEYOFF/CKEYON opens
another such channel!

As of ptr_gen 2.07 and SMSQ/E 3.39, this bug should be fixed, in that an "Out of
Range" error will be returned should the situation described above arise.

The workaround for earlier versions is: Always use this command with a
channel number *unless* there is definitely an available console channel #0!


The bug fix is that, if the circumstances described pertain, the call will return with an "Out of
Range" error.



**CROSS-REFERENCE**

:ref:`ckeyon` tells the Pointer Interface to recognise the cursor keys again.

