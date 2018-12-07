..  _tconnect:

TCONNECT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TCONNECT #pipechan TO #anychan                                   |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

Pipes are serial devices for buffered data transfer, they have two
sides:

- The input pipe which puts any data into the buffer until it's full and;
- the output pipe which reads the data from the buffer::

    input pipe ---> buffer ---> output pipe

There are two kinds of pipes on the QL:

- Standard pipes are part of the original QL ROM, the input pipe
  device name is pipe\_<buffer> where <buffer> is the buffer size in bytes
  (1..32767). It is necessary to know the CHANID of the input pipe to open
  the output pipe, see FILE\_OPEN.

- The second type are named pipes which
  have the same concept except that the output pipe can be identified by
  name: The input pipe is pipe\_<name>\_<buffer> and the output pipe
  pipe\_<name>. See the Appendix on Device Drivers regarding Pipes for
  more information.

TCONNECT makes standard pipes useable: the command
expects two opened channels where the first, #pipechan, must be an input
pipe and the second, #anychan can be anything. TCONNECT changes the
internal meaning of #anychan so that it becomes an output pipe connected
to the input pipe #pipechan:

Before TCONNECT::

    #pipechan -> input pipe -> buffer scr_2x2 <- #anychan

After TCONNECT::

    #pipechan -> input pipe -> buffer -> output pipe -> #anychan

**Example**

DEVLIST$ returns the devices listed by DEVLIST in a string, separated by
spaces. ISDEVICE takes a device and checks with the help of DEVLIST$ if
it is a legal device::

    100 DEFine FuNction DEVLIST$
    110   LOCal list$,dev$: list$=""
    120   OPEN#3,pipe_80
    130   OPEN#4,scr_
    140   TCONNECT #3 TO #4
    150   DEVLIST#3
    160   INPUT#4,dev$\dev$
    170   REPeat read_devs
    180     IF NOT PEND(#4) THEN EXIT read_devs
    190     INPUT#4,dev$
    200     list$=list$&" "&dev$
    210   END REPeat read_devs
    220   CLOSE#3: CLOSE#4
    230   RETurn list$
    240 END DEFine DEVLIST$

A legal drive device consists of three letters (the device name), a
drive number (1..8) and an underscore::

    250 :
    260 DEFine FuNction ISDEVICE(dev$)
    270   IF LEN(dev$)<>5 THEN RETurn 0
    280   IF dev$(5)<>"_" THEN RETurn 0
    290   IF dev$(4)<"1" OR dev$(4)>"8" THEN RETurn 0
    300   IF NOT (dev$(1 TO 3) INSTR DEVLIST$) THEN RETurn 0
    310   RETurn 1
    320 END DEFine ISDEVICE

**CROSS-REFERENCE**

See :ref:`file-open`,
:ref:`chanid`, pipes and
especially :ref:`pend`. Some more examples appear at
:ref:`file-len` and
:ref:`fupdt`. :ref:`qlink` is
the same. Qliberator gives the QCONNECT
command which is the same.

