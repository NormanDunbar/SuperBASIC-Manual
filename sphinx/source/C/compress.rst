..  _compress:

COMPRESS
========

+----------+-------------------------------------------------------------------+
| Syntax   |  COMPRESS filename                                                |
+----------+-------------------------------------------------------------------+
| Location |  COMPICT                                                          |
+----------+-------------------------------------------------------------------+

This command takes the current screen contents and compresses them,
saving the picture in its compressed form in the stated file - the full
filename (eg. ram1\_test\_scr) has to be used.

This compressed form does not represent that great a saving over the
original 32768 bytes required to hold the details of the screen before
compression - the amount of space required for a compressed screen
depends upon the amount of adjacent pixels on the screen which have the
same colour.

Whilst the screen is compressed, a pattern is drawn over the screen,
which although annoying, is harmless.

**Example**

COMPRESS flp2\_TITLE\_scr

**NOTE 1**

COMPRESS temporarily needs 64K of working space and will report an error
if this is not available. Unfortunately the file stays open if this
happens and cannot be accessed until is is closed with CLOSE% or a
desktop program such as QPAC 2 (channels menu).

**NOTE 2**

COMPRESS does not work in supervisor mode, ie. it multitasks, thus if
you were doing something else whilst the screen was being compressed,
the saved picture may look pretty strange when expanded.

**NOTE 3**

COMPRESS assumes that the screen starts at $20000 and cannot therefore
be used with Minerva's second screen or some emulator display modes.

**NOTE 4**

COMPRESS assumes a screen resolution of 512x256 and cannot work on
higher resolution screens.

**CROSS-REFERENCE**

Screens which have been saved with
:ref:`compress` can be loaded with
:ref:`expand` or re-loaded from memory with
:ref:`fastexpand`.

See also :ref:`scr-store`.

