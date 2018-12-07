..  _res-size:

RES\_SIZE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  RES\_SIZE ram\_top                                               |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card                                                        |
+----------+-------------------------------------------------------------------+

To get the few old programs which still do not work with the Gold
Card's 1920K RAM running and to simulate a system with less RAM for
debugging, RES\_SIZE resets the system and adjusts the RAMTOP to the
desired value.

If you use RES\_SIZE 128, high density and extra density
disks cannot be accessed until the next reset. Secondly, the realtime
clock runs by default in protected mode. Thirdly, the ramdisks cannot be
accessed by the system. This should simulate the unexpanded, original
QL. Normal disk drives (DD) can still be accessed, although this can be
temperamental.

**Examples**

::

    RES_SIZE 640
    RES_SIZE 128
    RES_SIZE 1024

**NOTE**

You may find that some programs will still not work following RES\_SIZE,
especially if they use a line such as::

    x=RESPR(0): start=RESPR(x-131072)

This appears to happen because RESPR(0) returns the address of RAMTOP
which is still over 2MB even though only 128K is available. Minerva
users should use::

    CALL 390,x

instead.

**WARNING**

At least up to Gold Card's firmware v2.28, RES\_SIZE does not check the
range of the supplied parameter. If values lower than 56 or higher than
1920 are used, this can lead to crashes of a particularly serious
character. Either the QL hangs during or after the resets, or there will
not be enough free memory to enter any commands.

There is even a danger
that a fatal crash will occur which can destroy data on hard disks,
disks or microdrive cartridges, or the realtime clock can be affected or
even combinations of these different crashes can occur. As hard disk
drives cannot be removed or protected from any malfunction of the
operating system or programs, they are in extreme danger.

It is also not
advisable to use values other than multiples of 64 because software
tends to expect a ramtop which is a multiple of 64 and memory is wasted.

**CROSS-REFERENCE**

:ref:`res-128` is identical to :ref:`res-size` 128. See also
:ref:`reset`. See :ref:`ramtop`
and :ref:`free-mem` about available and free
memory. :ref:`flp-ext` improves the reliability
of the floppy disk drives and allows RAM disks to be used.

