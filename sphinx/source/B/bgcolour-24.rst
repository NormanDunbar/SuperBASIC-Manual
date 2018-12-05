..  _bgcolour-24:

BGCOLOUR\_24
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BGCOLOUR\_24 [#ch,] colour                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

This is similar to BGCOLOUR\_QL in that it allows you to set a wallpaper
to cover the whole of the available screen (in any resolution).

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch.

BGCOLOUR\_24 allows you to specify any 24 Bit Colour - the parameters
allowed are the same as for the INK command (in COLOUR\_24 mode), which
thus allows for you to specify composite colours.


**Example**

BGCOLOUR\_24 $920000,$ff0092,3 -sets a checkerboard pattern of Dark Red
and Shocking Pink.


**CROSS-REFERENCE**

Refer to Appendix 16 and :ref:`ink` for more details
on colours.

:ref:`bgcolour-ql` gives more detail.

:ref:`bgimage` may be used to set a screen image
as the wallpaper.

--------------


