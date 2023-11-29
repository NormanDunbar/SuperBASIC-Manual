..  _disp-mode:

DISP\_MODE
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  DISP\_MODE mode                                                  |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for Q68                                                   |
+----------+-------------------------------------------------------------------+

This function sets the Q68 screen mode where mode can take the
following values:

- 0 QL 8 colour mode

  the standard 512 x 256 pixels mode in 8 colours. In this mode you
  can also set mode 4, with the usual MODE keyword. This is then
  equivalent to setting DISP_MODE 1.

- 1 QL 4 colour mode

  the standard 512 x 256 pixels in 4 colours mode. In this mode you
  can also set mode 8, with the usual MODE keyword. This is then
  equivalent to setting DISP_MODE 0.

- 2 Small 16 bit mode

  512 x 256 pixels in mode 33 (16 bits per pixel).

- 3 Large 16 bit mode

  1024 x 512 pixels in mode 33 (16 bits per pixel). Please note that
  this mode will slow down the Q68, you should not use this mode when
  doing something time-critical.

- 4 Large QL Mode 4

  1024 x 768 pixels in QL 4 colours mode (there is no mode 8 in this
  display mode).

- 5 Aurora compatible 8 bit colours

  1024 x 768 pixels in Aurora 256 colours mode. This allows you to
  have a big screen with nicer colours while still being reasonably
  fast (but slower than the QL modes).

- 6 Medium 16 bit mode

  512 x 384 pixels in mode 33 (16 bits per pixel).

- 7 Very large 16 bit mode

  1024 x 768 pixels in mode 33 (16 bits per pixel). Please note that
  this mode will severely slow down the Q68, you should not use this
  mode when doing something time-critical.

**CROSS-REFERENCE**

:ref:`mode`
      
