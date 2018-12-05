..  _grab:

GRAB
====

+----------+-------------------------------------------------------------------+
| Syntax   |  GRAB (bytes)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

GRAB is a function which reserves a specified amount of space in the
common heap area of memory for use and returns the start address of the
allocated area.

**CROSS-REFERENCE**

With :ref:`grab` (unlike
:ref:`alchp`), reserved memory can only be given
back to QDOS for other purposes with
:ref:`release`. It is necessary to know the start
address returned by :ref:`grab` to do this, so a
formula like :ref:`scrbase` GRAB(32768) wastes 32k of RAM
if :ref:`scrbase` is used again. Although
:ref:`grab` is comparable to
:ref:`respr` in this respect, it will work with jobs
in memory just like :ref:`alchp`. See also
:ref:`reserve`. The amount of available memory can
be found by using :ref:`free` or :ref:`free-mem`.

--------------


