..  _bclear:

BCLEAR
======

+----------+-------------------------------------------------------------------+
| Syntax   |  BCLEAR                                                           |
+----------+-------------------------------------------------------------------+
| Location |  BeuleTools, TinyToolkit, BTool                                   |
+----------+-------------------------------------------------------------------+

Each console channel has what is known as an input queue, a small area
of memory where key presses are stored before they are read by INPUT,
INKEY$ etc. The command BCLEAR clears the buffer of the current input
queue so that any key presses which have not yet been processed are not
seen by the program. This is useful to prevent overrun on keys.


**Examples**

(1) Type this line as a direct command into the interpreter, press
<ENTER> and then type some keys. REPeat a: REMark

Now press break and all of those key presses which you performed after
entering the line will be shown. Replace REMark by BCLEAR and try the
same.

Normally it is okay for all key presses to be stored in a buffer - if a
program cannot cope with the typist's speed, no key presses will be lost.
But sometimes this feature may not be welcome.

(2) Even on very good keyboards the phenomenon of key-bounce appears,
where the user has pressed a key once but the program thinks that the
same key has been pressed a few times. This generally happens with poor
quality keyboards or if the user is not used to either the keyboard or
program speed.

This is a queue clearing version of the GETCHAR% function shown at CUR.
Dangerous inputs should always clear the keyboard queue, for example
where the program is asking the question: "Do you really want to format
that disk (y/n) ?"

::

    100 DEFine FuNction GETCHAR% (channel,timeout)
    110  LOCal char$,dummy
    120  dummy=PEND(#channel): BCLEAR
    130  CUR #channel,1
    140  char$=INKEY$(#channel,timeout)
    150  CUR #channel,0
    160  RETurn CODE(char$)
    170 END DEFine GETCHAR%


**CROSS-REFERENCE**

The current keyboard queue can be selected by a dummy
:ref:`inkey-dlr` or :ref:`pend`.

