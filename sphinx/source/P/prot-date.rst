..  _prot-date:

PROT\_DATE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  PROT\_DATE flag                                                  |
+----------+-------------------------------------------------------------------+
| Location |  SMS, Gold Card                                                   |
+----------+-------------------------------------------------------------------+

Many systems which can run SMS (including QXL, the Gold Card and Super
Gold Card) include a battery backed clock (also known as a real-time
clock). In this case, there are actually two clocks running:

One is run by the operating system (the QL internal clock) which is found on each
QL implementation. The internal clock forgets the time if the computer
is switched off and has to be set each time the machine is powered up.

The other clock is the battery backed clock which keeps the time even
when the QL is switched off (until the battery runs flat) and this
normally sets the Internal Clock each time the QL is reset (or switched
on).

It may be necessary to adjust the QL's internal clock whilst the QL
is being used, without wishing to disrupt the battery backed clock -
some software alters the QL's internal clock when there is no need, the
internal clock can also be affected by crashes during program
development.

Some battery backed clocks may alter their time when the
QL's internal clock is altered and therefore some form of protection is
needed - you will normally need to enable the protection by using the
command::

    PROT_DATE 1

::

    PROT_DATE 0

will disable the protection.

**NOTE 1**

This has no effect on the battery backed clock provided by Minerva MKII
which has to be altered using the configuration program.

**NOTE 2**

If you reset the Gold Card or Super Gold Card to 128K, PROT\_DATE 1 is
executed.

**NOTE 3**

Serious crashes and some old games may disturb the battery backed clock
even in protected mode.

**NOTE 4**

On some combinations of AURORA and Super Gold Card, if you use
PROT\_DATE 1, the QL's internal clock will run too quickly (see also the
notes on DISP\_SIZE).

**WARNING**

SMS, the Gold Card and Super Gold Card do not automatically protect the
battery backed clock. It is therefore advisable to include the line::

    PROT_DATE 1

in your boot program.

**CROSS-REFERENCE**

:ref:`sdate` and :ref:`adate`
alter the QL's internal clock.\ :ref:`date-dlr` and
:ref:`day-dlr` can be used to read the time on the QL's
internal clock.

--------------


