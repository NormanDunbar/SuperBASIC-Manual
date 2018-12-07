..  _ttv:

TTV
===

+----------+-------------------------------------------------------------------+
| Syntax   |  TTV [ ( x1 :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*` )]               |
+----------+-------------------------------------------------------------------+
| Location | QView Tiny Toolkit                                                |
+----------+-------------------------------------------------------------------+

The function TTV returns the address of the QView Toolkit workspace,
which is a piece of shared memory of 176 bytes which can be accessed
from any job. The idea is that this workspace is used for communication
between different parts of the same program. By default, these bytes are
set to zero, so that you can freely POKE to them without the danger of
crashes. Note that the value of TTV is the same for all jobs. The
parameters are (more or less) just for fun, their sum is added to the
start address of the QView Toolkit workspace before that address is
returned. So::

    TTV = TTV(0)
    TTV(10) = TTV+10 = TTV(3,3,3,1)

**Example**

The workspace is preceded by 64 bytes for QView Toolkit's internal use.
There is however one value that is interesting to look at::

    PEEK_L(TTV-64)

is a very precise counter, it increases once every
frame. This is ideal for checking program speed without the need for
long lasting benchmarks, the following programs demonstrates the
difference in speed between some different types of FOR constructions::

    100 TIMER_START
    110 FOR i = 1 TO 10000
    120   REMark
    130 END FOR i
    140 TIMER_STOP
    150 :
    160 TIMER_START
    170 FOR i = 1 TO 10000: REMark
    180 TIMER_STOP
    190 :
    200 TIMER_START
    210 FOR i% = 1 TO 10000: REMark
    220 TIMER_STOP
    230 :
    240 :
    250 DEFine PROCedure TIMER_START
    260   POKE_L TTV(-64),0
    270 END DEFine TIMER_START
    280 :
    290 DEFine PROCedure TIMER_STOP
    300   LOCal count
    310   count = PEEK_L(TTV-64)
    320   PRINT INT (count/5) /10;"s"
    330 END DEFine TIMER_STOP

The third test (lines 200 to 220) works on Minerva and SMS only, and is
the fastest: 78% faster than the first test! Some QLs (mainly those in
the UK using TV's) will need to amend line 320 to read::

    320 PRINT INT (count/6 )/10;'s'

**CROSS-REFERENCE**

See :ref:`t-on`, :ref:`t-off`,
:ref:`t-start` and
:ref:`t-stop`

