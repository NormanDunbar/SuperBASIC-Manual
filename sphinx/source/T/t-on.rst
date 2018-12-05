..  _t-on:

T\_ON
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  T\_ON                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Timings (DIY Toolkit - Vol H)                                    |
+----------+-------------------------------------------------------------------+

This toolkit provides the QL with five independent stop-watches which
can be used to make accurate timings (more accurate than using DATE).

The stop-watches are linked into the QL's 'polled list' of small
routines which are run every frame on the computer (1/50 second on a
British QL, 1/60 on most foreign QLs). There is a slight disadvantage in
using the polled interrupts in that they are sometimes disabled by
machine code routines, for example when accessing microdrives and disks.

Because of this, these commands are not much for timing programs which
depend heavily on external hardware. These stop-watches are however very
useful for comparing the speed of various program routines without
having to make thousands of loops in order to show any difference in
speed.

This command enables all the stop-watches. This must be issued
before T\_START can be used.

**CROSS-REFERENCE**

See :ref:`ttv`, :ref:`t-start`,
:ref:`t-stop`,
:ref:`t-restart`

--------------


