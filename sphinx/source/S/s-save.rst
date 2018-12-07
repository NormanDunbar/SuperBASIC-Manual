..  _s-save:

S\_SAVE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  S\_SAVE (#wind)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This function causes the contents of the window #wind to be stored in
memory and the address is then returned. Do not forget the return value!
#wind must be a window or a bad parameter error (-15) is reported.

**Example**

::

    100 CLS
    110 PRINT PEEK$(0,1000)
    120 adr1 = S_SAVE(#1)
    130 CLS
    140 PRINT PEEK$(100,1000)
    150 adr2 = S_SAVE(#1)
    160 FOR n=1 TO 20: S_SHOW adr1: S_SHOW adr2
    170 S_LOAD adr1: S_LOAD adr2

**NOTE**

Although S\_SAVE will save a window stored on the second screen provided
by Minerva and Amiga QDOS, it assumes the screen resolution is 512x256
pixels and cannot work with higher resolutions.

**CROSS-REFERENCE**

:ref:`s-load` and
:ref:`s-show` view the saved screen part. Memory
taken by :ref:`s-save` cannot be freed with
:ref:`rechp` or :ref:`clchp`,
only with :ref:`s-load`. See also
:ref:`scr-store` and
:ref:`savepic` for alternatives.

