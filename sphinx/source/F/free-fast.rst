..  _free-fast:

FREE\_FAST
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FREE\_FAST                                                       |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT for QVME (v2.31+)                                    |
+----------+-------------------------------------------------------------------+

The Atari TT recognises two types of RAM, standard ST RAM (up to
10MB) and FastRAM (otherwise known as TT RAM) which is specifically
designed for the Atari TT and works about twice as fast as the standard
ST RAM.

The QL emulator can use both types of RAM but will only
recognise and use a maximum 4MB of standard ST RAM.

If FastRAM is
available, the Emulator places the device drivers into this area in
order to speed them up as well as freeing additional standard ST RAM.
However, if your programs are to access the FastRAM, they need to use
various new commands. FREE\_FAST is a function which returns the amount
of available FastRAM.

**CROSS-REFERENCE**

The other commands to access FastRAM are
:ref:`resfast`, and
:ref:`lresfast`.

Compare :ref:`respr`,
:ref:`alchp` and
:ref:`free-mem`.

