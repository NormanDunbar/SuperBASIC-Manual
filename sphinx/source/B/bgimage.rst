..  _bgimage:

BGIMAGE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  BGIMAGE [#ch,] filename                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

This command allows you to load a screen image as a wallpaper to cover
the whole of the available screen (in any resolution).

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

The file will need to be a screen snapshot - the Photon JPEG viewer can
be used to convert JPEG files to screen snapshots.


**Example**

BGIMAGE win1\_wallpapers\_cats - load a wallpaper.


**NOTE**

The command expects the screen to have been saved in the current
resolution and colour depth, therefore any attempt to load a screen
image in a different resolution or colour depth to the one in existence
when the screen was saved will result in a corrupt image.


**CROSS-REFERENCE**

:ref:`sbytes` gives details on how to store a
screen on disk.

In many ways, this command is similar to
:ref:`loadpic`, except that it caters for
non-standard QL resolutions and colour depths.

:ref:`bgcolour-ql` and
:ref:`bgcolour-24` can be used to set a
single colour wallpaper.

