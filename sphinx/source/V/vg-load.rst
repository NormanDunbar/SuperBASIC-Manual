..  _vg-load:

VG\_LOAD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_LOAD fontnr, file$ fontnr=0..15                              |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

This toolkit allows the QL to use BGI vector fonts (common on the PC)
to draw on the screen. There are now numerous fonts available in this
format for the QL, being the same format as used by the PROWESS
programming system from PROGS.

The advantage of vector fonts is that
they can be drawn on screen at any size and angle without affecting the
legibility. Each character is not made up by a bit-map (as with the
original QL fonts), but by a description of how each line is drawn to
make up a character.

This command forces a BGI font file$ to be loaded
from a file into memory. Fontnr is the number of the font Up to 16 fonts
can be loaded at the same time; Fontnr may range from 0 to 15. The file$
can be any font in standard BGI format, for example those which are
delivered with Turbo Pascal and Turbo C by Borland. The format used on
the QL with this Toolkit is binary compatible.

If VG\_LOAD fails to load
a file for external reasons (eg. if the file is not found), the font
which was previously attached to fontnr will have been lost.

**Example**

::

    VG_LOAD 1, "flp1_goth_chr"

**WARNING**

You have to ensure that file is actually a BGI font. Otherwise your
machine will almost surely crash.

**CROSS-REFERENCE**

See :ref:`vg-print` about displaying text using
a vector font and the other VG_XXX commands.

--------------


