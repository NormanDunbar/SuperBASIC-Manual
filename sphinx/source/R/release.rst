..  _release:

RELEASE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RELEASE address                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command allows you to return a section of memory reserved by GRAB
to QDOS.

**NOTE**

LOAD, CLEAR, NEW and similar commands do not free GRABbed memory (unlike
memory reserved with ALCHP).

**WARNING**

Never free memory where extensions, device drivers or other code have
been loaded and started (for example with CALL) because the operating
system will continue to update these routines regularly and find code
which may have been overwritten by other programs, internal data etc.
Crash!

**CROSS-REFERENCE**

:ref:`rechp` and :ref:`clchp`
clear memory allocated with :ref:`alchp`.
:ref:`discard` releases memory allocated with
:ref:`reserve`. See also the other version of
:ref:`release`.

--------------


RELEASE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  RELEASE nr                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, QSound                                                    |
+----------+-------------------------------------------------------------------+

RELEASE activates the enhanced sound capabilities of the ST/QL (or the
QSound interface which has now been out of production for some years). A
sequence which has been previously stored with PLAY under the number nr
is 'executed' by RELEASE.

**CROSS-REFERENCE**

:ref:`play`, :ref:`snd-ext`
Beware the other version of :ref:`release`.

