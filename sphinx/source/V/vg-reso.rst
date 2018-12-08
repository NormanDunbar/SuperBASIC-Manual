..  _vg-reso:

VG\_RESO
========

+----------+-------------------------------------------------------------------+
| Syntax   |  VG\_RESO scradr, xres, yres                                      |
+----------+-------------------------------------------------------------------+
| Location |  BGI                                                              |
+----------+-------------------------------------------------------------------+

This command defines the screen base address and the screen size for
printing the BGI fonts. The default is::

    VG_RESO 131072,512,256

This will need to be changed if the screen offset is not 131072. A
fixed screen address should never be assumed. VG\_RESO can also be used
to write to the second screen on a dual screen system.

**CROSS-REFERENCE**

The settings of :ref:`vg-wind` are dependent on
:ref:`vg-reso`'s. See
:ref:`scrbase`, :ref:`peek` and
:ref:`mode`.

