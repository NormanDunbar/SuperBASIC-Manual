..  _bgcolour-ql:

BGCOLOUR\_QL
============

+----------+-------------------------------------------------------------------+
| Syntax   |  BGCOLOUR\_QL [#ch,] colour                                       |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E v2.98+                                                    |
+----------+-------------------------------------------------------------------+

It is possible under the latest version of SMSQ/E to set a 'wallpaper' -
this is an image which covers the whole of the available screen (in any
resolution) and which forms a background for any programs which may be
running. Normally, this would appear as a black area of the screen.

A valid window channel must be open, default #1 (or #0 on a SBASIC with
only #0 open), although one may also be supplied as #ch. BGCOLOUR\_QL
allows you to specify any standard QL colour - the parameters allowed
are the same as for the INK command (in either Standard QL Colour Mode
or COLOUR\_QL mode), which thus allows for you to specify composite
colours as well as palette mapped colours with PALETTE\_QL.


**Example**

BGCOLOUR\_QL 2,7 - sets a red and white checkerboard pattern.


**CROSS-REFERENCE**

Refer to Appendix 16 and :ref:`ink` for more details
on colours.

:ref:`bgcolour-24` is similar.

:ref:`bgimage` may be used to set a screen image
as the wallpaper.

