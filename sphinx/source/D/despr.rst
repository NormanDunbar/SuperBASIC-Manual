..  _despr:

DESPR
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DESPR (bytes)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  DESPR                                                            |
+----------+-------------------------------------------------------------------+

The function DESPR uses an un-documented system call to try and release
a given number of bytes from the resident procedure memory on the QL. It
is unknown how the ROM tries to decide which bytes to release.


**WARNING**

The system call used only works properly on Minerva ROMs and can crash
some versions of the QL. This function should not be used!!


**CROSS-REFERENCE**

Use :ref:`respr` to allocate resident procedure
memory, and do not try to release it at a later stage. Use
:ref:`alchp` and :ref:`rechp` to
allocate areas of memory which may be later released.

--------------


