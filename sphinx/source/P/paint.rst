..  _paint:

PAINT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  PAINT x, y, col, bufadr, buflen                                  |
+----------+-------------------------------------------------------------------+
| Location |  HCO                                                              |
+----------+-------------------------------------------------------------------+

The command PAINT addresses the screen directly and fills a closed
figure with the colour col (which must be in the range 0..4, see SET).

The command requires a buffer of at least 4K whose start address is
passed to PAINT as bufadr and whose length as buflen (which must be a
minimum of 4096 bytes). The larger the buffer, the better, but very
large buffers (say, 100K) seem to confuse PAINT and will make it stop
before it has finished - therefore keep the buffer below 32K.

**Example 1**

Random drawing::

    100 WINDOW 512,256,0,0: BORDER 1,3: PAPER 0: CLS
    110 buflen = 10240
    120 :
    130 FOR i = 1 TO 15
    140   LDRAW RND(511),RND(255) TO RND(511),RND(255), 3
    150 END FOR i
    160 :
    170 buffer = ALCHP(buflen)
    180 PAINT RND(1 TO 510), RND(1 TO 255), 2, buffer, buflen
    190 RECHP buffer

**Example 2**

A spectacular crash!
::

    PAINT 50,50,4,131072,32768

**WARNING 1**

See those at SET.

**WARNING 2**

PAINT will crash the machine if it runs out of the screen, so you have
to ensure that the figure to be filled is closed. Another means of
protection is to use a BORDER, as in the example.

**CROSS-REFERENCE**

:ref:`fill`, :ref:`set`,
:ref:`ldraw`

