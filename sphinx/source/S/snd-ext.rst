..  _snd-ext:

SND\_EXT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  SND\_EXT                                                         |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v1.24 to v2.15)                                     |
+----------+-------------------------------------------------------------------+

The ST-QL Emulators contain new extensions (based upon the QSound device) to
enable programs to use the
ST's sound facilities. Unfortunately, these extensions clash with the
Turbo SuperBASIC compiler from Digital Precision. When the Emulator is
started up, these sound extensions are switched off. SND\_EXT will
switch them back on. This command was replaced in v2.15 by ATARI\_EXT.

You can test if the QSOUND interface (or these commands) are present by
using::

    PEEK_L(!! HEX('164'))

which will be 0 unless the commands are present (Turbo may also alter
this figure whilst it is compiling a program).

**WARNING**

The sound extensions may crash the hardware.

**CROSS-REFERENCE**

Some of the available extensions for sound are
:ref:`play`, :ref:`release`,
:ref:`bell`, :ref:`shoot`,
:ref:`explode`.

