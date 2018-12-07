..  _sstat:

SSTAT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  SSTAT                                                            |
+----------+-------------------------------------------------------------------+
| Location |  Ecran Manager                                                    |
+----------+-------------------------------------------------------------------+

The function SSTAT returns either 0 or 1, corresponding to the first or
second screen. The function is used to find out which of these screens
is currently the visible screen. Unless you have Minerva or Amiga QDOS
set up in dual screen mode, this is always 0.

**Example**

Force the second screen to be displayed (this only works in Minerva or
Amiga QDOS)::

    IF SSTAT = 0 THEN MODE 80,-1

**NOTE**

See SSAVE.

**CROSS-REFERENCE**

:ref:`default-scr`,
:ref:`scron`, :ref:`scrof`,
:ref:`mode`

