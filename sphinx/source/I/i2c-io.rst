..  _i2c-io:

I2C\_IO
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  I2C\_IO (cmd$, res\_len [,device [,param ]] )                    |
+----------+-------------------------------------------------------------------+
| Location |  Minerva extensions                                               |
+----------+-------------------------------------------------------------------+

The Minerva MKII operating system comes complete with a battery backed
clock and a small amount of on-board RAM (256 bytes) which can be used
to store various details whilst a machine is switched off, using some of
those details to dictate the state of the machine when it is first
switched on (or re-set).

An on-board serial bus is also included which
can be used to link add-on interfaces and can transfer data at speeds up
to 100kbits per second.

Interfaces currently exist to allow the QL to
drive motors (up to 4 amps), relay switches (up to 3 amps) and an
Analogue to Digital converter.

The I2C\_IO function allows you to access the
battery backed clock, RAM and other interfaces provided by Minerva MKII,
through what is known as the I\ :sup:`2`\ C bus. The results of the
function will be returned by way of a string.

The cmd$ should contain a
series of bytes which are sent to the I\ :sup:`2`\ C bus to be sent to
the device pointed to by the other parameters. This is normally a byte
which represents a command, followed by the parameters for that command.

For the battery backed clock and RAM supplied with Minerva MKII, there
are only three commands which are required:

- CHR$(164) -Write param bytes to the specified device. The first byte to be written should in fact be
  the memory address to write to. Param can be altered by preceding the
  command character in the cmd$ by the number of bytes to write (eg.
  CMD$=CHR$(6)&CHR$(164)&CHR$(36)&'HELLO' will write the string 'HELLO' to
  memory address 36 in the RAM). If you only use this to write one byte,
  then this will merely set the memory address for access by further Write
  or Read commands.

- CHR$(188) -Read param bytes from the specified device.
  Again, you can precede this command character by the number of bytes to
  be read if you wish. The bytes which are read will be returned as the
  resultant string.

- CHR$(255) -This signifies the end of the command
  string.

The other parameters allowed by the function are:

- Res\_len which signifies the expected length of the return string , which must not be too short!!
- Device signifies which device is to be accessed. The value 80 is used to access the battery backed RAM.
- Param depends upon the command being sent via cmd$.

The on-board RAM is allocated as follows:

+---------+-----------------------------------------------------------------------------+
| Bytes   | Meaning                                                                     |
+=========+=============================================================================+
| 0-15    | Reserved for the clock and other things set by the configuration program.   |
+---------+-----------------------------------------------------------------------------+
| 16-19   | QDOS version number (if this is different to the string returned by VER$,   |
|         | then the rest of the configuration data stored in the RAM will be ignored). |
+---------+-----------------------------------------------------------------------------+
| 20-23   | Warm reset value (as per CALL 390) to be used when the QL is re-booted.     |
+---------+-----------------------------------------------------------------------------+
| 24-25   | Year\*2+month DIV 10 (do not amend!)                                        |
+---------+-----------------------------------------------------------------------------+
| 26-27   | Copy of locations 22 and 23 - this is used to reset the system if the the   |
|         | values in locations 20-23 do not make any real sense (do not amend)         |
+---------+-----------------------------------------------------------------------------+
| 28-29   | Each bit in these two locations can be set to disable up to 16 plug-in ROMs |
|         | linked to the QL (bit 7 of location 28 represents the ROM which             |
|         | appears at the top of the F1...F2 screen when the QL is reset, bit 6        |
|         | represents the second ROM and so on).                                       |
+---------+-----------------------------------------------------------------------------+
| 30      | NET station number                                                          |
+---------+-----------------------------------------------------------------------------+
| 31      | System Enhancements (equivalent to POKE !124!49,x)                          |
+---------+-----------------------------------------------------------------------------+
| 32      | SuperBasic Enhancements (equivalent to POKE \\\\212,x)                      |
+---------+-----------------------------------------------------------------------------+
| 33-34   | RESERVED                                                                    |
+---------+-----------------------------------------------------------------------------+
| 35      | Length of boot string (0 to 128)                                            |
+---------+-----------------------------------------------------------------------------+
| 36-163  | Boot string or user area                                                    |
+---------+-----------------------------------------------------------------------------+
| 164-251 | RESERVED                                                                    |
+---------+-----------------------------------------------------------------------------+
| 252     | SER1 device (see below)                                                     |
+---------+-----------------------------------------------------------------------------+
| 253     | SER2 device (see below)                                                     |
+---------+-----------------------------------------------------------------------------+
| 254     | PAR device (see below)                                                      |
+---------+-----------------------------------------------------------------------------+
| 255     | RESERVED                                                                    |
+---------+-----------------------------------------------------------------------------+

The bytes contained in locations
252 - 254 are intended for use by programs to find out if printers or modems are
connected and what type they are. The values currently supported are:-

- 0: Nothing connected to this port
- 1-23: Printer type (as per SDUMP command)
- 253: Tandata Modem
- 254: Astracom 'Native' Modem
- 255: Astracom Hayes-Compatible Modem

**Example**

You can use this command to make the QL always start up by loading a
specified program::

    startup$ = CHR$(232) & 'LRUN win1_ROUTE_boot' & CHR$(10)
    command$ = CHR$(164) & CHR$(35) & CHR$ (LEN (startup$)) & startup$ & CHR$ (255)
    PRINT IC2_IO (command$, 0, 80, LEN (startup$) + 1)

**CROSS-REFERENCE**

Some expansion boards have their own in-built battery backed clock,
which may need to be protected from programs which re-set the system
clock for their own purposes using :ref:`sdate`.

See :ref:`prot-date`.

Because Minerva MKII's battery backed clock is read through the I\ :sup:`2`\ C bus, it cannot
be affected by programs, unless you abuse the :ref:`i2c-io` function!!

--------------


