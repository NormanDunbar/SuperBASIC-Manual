..  _eprom-load:

EPROM\_LOAD
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  EPROM\_LOAD device\_file                                         |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT (v1.21+), SMS                                        |
+----------+-------------------------------------------------------------------+

You cannot plug QL EPROM cartridges into the various other computers which now
support QL software, which would normally make some software which contains part
of its code on EPROM, unusable. In order that you can use such software on other
computers, you need to create a file on an original QL containing an image of the
EPROM cartridge plugged into the QL's ROM port. To do this, use the command::

    SBYTES flp1_EPROM_image,49152,16384

It is hoped that software producers who sell software which requires an EPROM
cartridge will make versions available with ready-made images of the cartridge,
so that the software can be used by users without access to an original QL.

Having
done this, you will need to have the ST/QL Emulator switched on (or SMS loaded on
the other computer), then insert that disk into the Atari's disk drive, and use
the command: EPROM\_LOAD flp1\_EPROM\_image  This will then copy the EPROM code
into the same address on the Emulator or other computer as the EPROM cartridge
occupies on the QL, thus making it usable.

**NOTE 1**

If you make images of several EPROM cartridges in this way, then
additional ones which are loaded with EPROM\_LOAD will be stored in
arbitrary addresses under SMS or the emulator. Therefore you will need
to ensure that cartridges which insist on being loaded at the address
$C000 (the QL's ROM port address), will need to be loaded first with
EPROM\_LOAD.

**NOTE 2**

On early versions of the Emulator, this was called ROM\_LOAD.

**NOTE 3**

On SMS before v2.52, this could crash the system if used on a Gold Card
or Super Gold Card without the specified file being present.

**CROSS-REFERENCE**

See also :ref:`rom`, :ref:`roms`
and ROM\_TEST.

