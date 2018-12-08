..  _pend:

PEND
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PEND (#channel)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

PEND is a logical function and returns 1 if there is data waiting in
the specified channel to be read and 0 if not.

**Example 1**

If the Window Manager is present, PEND can be used to check if a window
is currently hidden, and therefore to decide whether information should
be printed to that channel or not. Under the Pointer Environment, jobs
which are trying to output data to a window channel cannot do so until
the channel is activated (eg. by pressing <CTRL><C>).

The following
program calculates a large sum and prints the current value of the
calculation in a small window, however, the calculation itself will not
stop if one switches to another window, thus hiding this one.

::

    100 n=1546: sum=0
    110 OPEN#3,"con_"&(6*LEN(n)+6)&"x12a0x0"
    120 BORDER#3,1,3: INK#3,7: CLS#3
    130 FOR i=1 TO n
    140   sum=sum+i
    150   IF PEND(#3) THEN PRINT#3;FILL$(" ",4-LEN(i));i
    160 END FOR i
    170 IF sum<>n*(n+1)/2 THEN BEEP 0,33,44,66,22,44
    180 CLOSE#3

**Example 2**

Pipes should be used for communication between jobs. It is very bad
practice to write information to a file and let the other job read it
because other tasks may be affected.

Here are two programs which have to
be compiled and executed to multitask. Both open a small window, the
first job inputs text and then sends it to the second job which shows
that text. Typing "end" will terminate both jobs.

The output job would
work without PEND but would not be able to do something else whilst
waiting for further input.

::

    100 REMark Input Job
    110 :
    120 OPEN#3,con_50x30a30x40: PAPER#3,3
    130 INK#3,7: BORDER#3,1,4: CLS#3
    140 OPEN#4,pipe_communication_200
    150 REPeat input_loop
    160   INPUT#3,text$
    170   PRINT#4,text$
    180   IF text$=="END" THEN EXIT input_loop
    190 END REPeat input_loop
    200 CLOSE#3: CLOSE#4

::

    100 REMark Output Job
    110 :
    120 OPEN#3,scr_50x30a100x40: PAPER#3,3
    130 INK#3,7: BORDER#3,1,4: CLS#3
    140 OPEN#4,pipe_communication
    150 REPeat output_loop
    160   IF PEND(#4) THEN
    170     INPUT#4,text$
    180     IF text$=="END" THEN EXIT output_loop
    190     PRINT#3,text$
    200   END IF
    210 IF NOT RND(200): d$=DATE$: PRINT#3,d$(16 TO)
    220 END REPeat output_loop
    230 CLOSE#3: CLOSE#4

By the way, in this case it is not very efficient to separate the input
and output jobs, but good terminal Emulators do this. You will also
notice that the programs use named pipes which make it much easier for
them to link up with each other. These named pipes are present in the
latest version of the ST/QL Emulator as well as SMS. They are also
provided by several public domain device drivers - See the appendix on
devices for further details.

**NOTE**

PEND only works with channels which will accept input (not scr\_) and
reports an "end of file" error (ERNUM=-10, ERR\_EF=1) if a connected
output pipe has been closed.

Unfortunately, EOF cannot be used to trap
the end of a named pipe early enough, so you have to ensure that the
output pipe tells the accompanying input pipe that it is about to be
closed.

**CROSS-REFERENCE**

See :ref:`tconnect` and
:ref:`file-open` about connecting two unnamed
pipes. :ref:`eof` checks if a file is at its end.
:ref:`io-pend-pct` and NOT :ref:`eofw` are identical to
:ref:`pend`.

