..  _a17-networks:

A17 Networks
============

A Network is a means of communicating with several other computers and
sharing their resources. The way in which networks work on a QL or
deriviative depends upon the hardware being used.

Standard QLs and the THOR family of computers have two network ports
which work in exactly the same way, and enable up to 64 computers to be
connected together serially.

Unfortunately, the protocol used for the Network is peculiar to Sinclair
machines and only QLs (including AURORA), QXLs, THORs and ZX Spectrums
may be connected together in this way. This is known as QNet. If you
only need to network these machines together then you can take advantage
of several different options to get the most out of the original QNet.

To enable ATARIs and PCs to be connected together in a Network with
Sinclair QLs, you will need to use the SERNET and MIDINET drivers which
allow the machines to be connected via serial ports and MIDI ports
respectively (although MIDI ports can only be connected between ATARI
computers).

These networks will work alongside the standard QNet and therefore you
can have several circles of computers networked together, all controlled
by one central machine, say with some linked via SERNET, some via
MIDINET and others linked via QNet.

Another option available to users wishing to join machines together in a
Network is to use Amadeus Interlink (© Di - Ren), which allows you to
connect up to 255 machines in a Network. These machines can be either
QLs, THORs or PCs at present and this Network system is significantly
faster than the original QNet.

Di-Ren also produce a QL-PC Fileserver which allows you to link a QL to
a PC with a cable and then this allows the QL to use the PC's DOS
devices (including floppy disks, CD-Rom drive, hard disks, Networks and
Serial ports). This will allow you to use PC format disks and on later
versions, you can even use the PC's screen to display the QL's output.
This is therefore similar to a small Network device.

In DIY Toolkit Volume N there is a very interesting program NETPAL which
allows one computer to completely control another computer - this works
by machine 2 opening a channel on machine 1 where the user can enter his
commands, which are then executed on machine 2. This can be very useful
to allow you to use several QLs with only one Monitor (or keyboard), but
unfortunately, this program does have its limitations due to problems
with sending control characters over the Network (such as CTRL C) and
also a CON device opened over the Network does not seem to delete
characters from the screen properly..

A17.1 QNet
----------

This system allows Standard QLs, QXLs, AURORAs, THOR computers and ZX
Spectrums (with Interface 1 attached) to be connected together in a
network. However, although data can be sent to a ZX Spectrum, the data
is corrupted if the Spectrum tries to send more than one byte to another
type of machine.

Minerva, SMSQ/E and Toolkit II all improve the reliability of this
Network system. if you are not using Toolkit II, Minerva v1.96 is
ideally required to ensure reliable input of data over the Network.

A17.1.1 Connecting Machines
^^^^^^^^^^^^^^^^^^^^^^^^^^^

To connect the machines, a cable must be used to connect one network
port on each computer to one of the ports on the next computer in line.
Having chained all of the computers together in this fashion, the
Network should be completed by connecting the last computer in the chain
to the first, thus completing a circle (although this is not always
necessary).

The cable need only be twin core, and it is advisable in a large Network
to use low-capacitance cable (eg. bell wire), connecting the centres of
each jack to each other and the outsides to each other. The maximum
amount of cable that can be reliably used is approximately 100 metres,
however, the less the better.

Unfortunately the network hardware on the standard QL is not always
reliable, but if you experience problems, it might be worth trying
either a different QL or swapping the leads over. THOR XVIs should work
without any problems, however, if you intend linking several QLs
together, it is advisable to install Toolkit II on ROM (or SMSQ/E) in
each of them (the memory only version of Toolkit II cannot improve the
network due to timing). Minerva or SMSQ/E on all of the machines will
also improve the Network handling.

Each computer (known as a station) must be given a separate station
number so that it can be clearly identified within the Network. This
station number is given to the machine when it is turned on (this will
always be one) and so must be reset on each machine by the command NET.

A17.1.2 The Device Driver
^^^^^^^^^^^^^^^^^^^^^^^^^

Data is sent through the Network ports normally by using the NET device
driver, which has the format:

NET<direction><station>    (QL ROM)

NET<direction><station>\_<buffer>    (Toolkit II, THOR XVI)

The parameters of the NET device have the following meanings:

<direction>This is the direction in which data is to be sent. There is
no default and this therefore must be one of the following letters:

- I - This is a listening station (input only)
- O - This is a transmitting station (output only)

- <station> This is the number of the station to communicate with and is in
  the form \_n, where n represents the station number of the other machine
  you wish to communicate with.

  n=0 is treated as a special case - see below.

  The default is \_0.

This Device Driver allows data to either be transmitted to a specific
machine, or broadcast to any machine which is listening to the Network.

A17.1.3 Sending / Receiving Data
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To broadcast data (sending it to all machines in the Network) you need
to open a channel to NETO\_0, for example::

    OPEN_NEW #3,NETO_0

To listen to data which is being Broadcast, the listening stations will
need to open a channel NETI\_0, for example with::

    OPEN_IN #4,NETI_0

If you open a net-in channel and specify your own station number, this
is treated as a general listening station, allowing you to receive any
data sent to that station by any machine in the Network. For example,
you could use::

    NET 12: OPEN_IN #4, NETI_12

to set up a general listening station.

If you want to open a net-in channel which will only listen for data
from a specific machine in the Network, you will need to specify the
station number of that machine, for example:

On station 3, enter::

    NET 3: OPEN_NEW #3, NETO_12

Then on station 12, enter:

    NET 12:OPEN_IN #3, NETI_3

will set up a link between stations 3 and 12 which only those machines
can use. To allow station 12 to send data to station 3, you will also
need to open a net-out channel, with::

    OPEN_NEW #4, NETO_3

and to enable station 3 to listen to it, you could use on station 3::

    OPEN_IN #4, NETI_3

(this allows station 3 to listen to any messages sent to it over the
network by any other machine).

Each network channel can be input only or output only, thus
bi-directional channels are not allowed. However, you can open as many
channels as you like onto the Network on each machine, some of which may
be output channels whilst others are input channels. If you try to send
data down an input channel (or read data from an output channel), then a
'Bad Parameter' error will be returned.

Due to the way in which the data being sent over the Network ports is
tested, you will need to open the output side of a Network link before
the input side is opened, as otherwise, the two computers may miss each
other's data header. If you later need to close the output port, you
will need to inform the computers which are listening for data before
the port is closed, as they themselves will need to close their input
ports (any attempt to read any further data once the output port has
been closed will result in an 'End of File' error). Only once the output
port has been re-opened is it safe for them to re-open the input ports.

For this reason, if you plan to write a program which may open and close
the output port several times in a session, it would be useful to have a
secondary output port open at all times, which can be used to Broadcast
to the listening stations when to open and/or close their own input
ports.

Data is transmitted in packets of a specified size (the size depends on
the type of device driver). The size of the packet determines the
smallest amount of data that can be sent - any spare values will be set
to zero. If the amount of data is greater than the packet size, then it
will be sent as several packets. However, a packet will only be sent
down the Network if it is full, therefore if some data remains to be
sent which does not completely fill a packet, the sending machine will
need to CLOSE the channel, or flush the network (this requires a
specialised routine - FLUSH will not work on a network device) in order
to send the remaining pieces of data.

The NET device is greatly improved if Toolkit II is present (or a THOR
XVI is being used), and we shall deal with this separately.

A17.1.4 QNet without Toolkit II
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Data is transmitted in packets of 255 bytes preceded by a small Network
header in the following format:

+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| Offset   | Name       | Size   | Description                                                                                                                  |
+==========+============+========+==============================================================================================================================+
| 0        | NET.HEDR   | byte   | Destination station number (equivalent to NCIRIS on the Spectrum)                                                            |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| 1        | NET.SELF   | byte   | Number of sending station                                                                                                    |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| 2        | NET.BLKL   | byte   | LSB of data block number                                                                                                     |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| 3        | NET.BLKH   | byte   | MSB of data block number (note the reverse order because of the way in which words are stored for the Z80 on the Spectrum)   |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| 4        | NET.TYPE   | byte   | Packet type: 0 data, 1 last block (EOF)                                                                                      |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| 5        | NET.NBYT   | byte   | Number of bytes in data block (0 to 255)                                                                                     |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| 6        | NET.DCHK   | byte   | Data checksum                                                                                                                |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+
| 7        | NET.HCHK   | byte   | Header checksum                                                                                                              |
+----------+------------+--------+------------------------------------------------------------------------------------------------------------------------------+

The effects of the header depend on whether the sending machine is
Broadcasting (ie. using NETO\_0), in which case there is no handshaking,
or not (in which case handshaking is enabled).

Before the packet is sent down the Network, the sending machine listens
to the Network to check if it is being used. Once it is free, the
sending machine then sends the header and if handshaking is enabled,
waits for an acknowledgement from the destination machine that it is
ready to receive.

Having received this acknowledgement (or if it is Broadcasting), the
packet is sent. Once this is sent, if handshaking is enabled, then the
sending machine again waits for the destination machine to acknowledge
safe receipt; and if no such acknowledgement is received, tries all over
again.

This means that no check is made on the data if the sending machine is
Broadcasting, in which case it makes it very unreliable to Broadcast
messages of more than 255 bytes (unless you have Toolkit II, a THOR XVI
or Minerva; all of which improve the reliability, although it is still
not 100%). This does also mean that if no stations are actually
listening, the whole of the data will be lost.

When receiving data through the Network, the command EOF will only
detect the end of the data if there are no more bytes to be read from
the channel and the NET.TYPE in the header was set to EOF. The receiving
machine will need to use the command PEND or EOFW to check if there is
any data in the channel waiting to be read, unless you wish the program
to just wait around for the data to be sent.

When the channel is closed, the device will try to output one final
packet of data (this means that a minimum of one packet can be sent). If
it fails to send the packet, then it will try a further 1399 times
(causing an extremely long delay), after which the QL will give up. No
error message is returned to tell the sending computer that it has
failed to send the data. This means that CLOSEing a NETO channel, even
though no data has been sent through the Network, produces an extremely
long delay before the computer can do anything else (and may even crash
some versions of the QL ROM if nothing has been written to the port -
see CLOSE).

**Example**

::

    COPY flp1_boot TO neto_2

copies the file flp1\_boot to station 2.

A17.1.5 QNet Under Toolkit II
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This is basically the same as the standard QNet driver, except that
improvements have been made to improve handshaking and also to ensure
that when an output channel is closed, whilst the driver keeps trying to
send the last packet, the Break key is also checked for on the sending
machine, allowing you to break into this early.

The Net header for the fileserver has also been improved to allow blocks
of up to 1000 bytes to be sent at a time and also to improve the
checksum.

If the driver fails to send the last packet (despite retrying 1399
times), or the Break key is detected, the message 'Net Aborted' is
printed to #0 (although this does not stop the program), warning the
user that the Network has failed.

The syntax has been extended to include a parameter <buffer> which
represents the size of a buffer to be opened to receive bytes over the
Network. It is in the form \_n kilobytes and is really only applicable
where the channel is NETI\_0, as it specifies the size of the buffer (in
kilobytes) to store the whole of a Broadcast message as it is
transmitted. If no <buffer> is specified, it will use all but 2K of the
free memory.

Toolkit II also implements a fileserver which allows a machine to
directly access resources on another computer, by OPENing channels over
the Network. Please refer to the FSERVE and NFS\_USE keywords for
details about the fileserver.

The MEM device can also be used to access another machine's resources
over the Network. This is discussed in the Appendix on Device Drivers.

A17.2 Flexynet (DIY Toolkit - VOL X)
------------------------------------

This can be used alongside the standard and Toolkit II QNet (subject to
certain limitations - see below). The code will need to be loaded into
either ROM (if you have an EPROM blower) or fast RAM (not the QL's
internal 128K RAM - an expanded machine is therefore needed). Current
versions of Flexynet will not work on machines which do not use a 68000
or 68008 chip (such as QXLs or Super Gold Cards), unless the cache has
been disabled.

It has been implemented with a view to speeding up the transfer of data
across the QNet, by allowing you to set the speed at which the data is
to be transmitted (using the NETRATE command). The speed which the
Networks will support depends upon the machines which are connected to
QNet, with faster machines being able to receive data much faster than
under the standard QNet (although transmission speed depends upon the
speed of the machine at the other end of the QNet).

Although this can be used alongside QNet, there are really only two
commands which allow you to send or receive multiple bytes sent over the
network (NETSEND and NETREAD). There is currently no way of specifying
which machine the data is to be sent to and therefore all machines in
the network will be able to read the data sent.

You should not try to use both the standard QNet and Flexynet at the
same time - we would recommend that a message is broadcast over the
Network to all of the other machines first of all specifying that
Flexynet is to be used and which machine is to receive the data and that
the sending machine should then wait to hear that all other machines
have closed down their network channels and that the receiving machine
is ready to receive the data.

The commands NETBEEP and NETPOLL have also been added to allow the QL to
use the Networks as a rudimentary form of digital sampling and even to
generate sounds through the Network ports.

A17.3 Midinet
-------------

This extension provided with the Atari Emulators and SMSQ/E allows you
to connect several ATARI computers in a Network by linking their MIDI
ports together using suitable leads. As with QNet the machines must be
arranged to form a complete circle with the MIDI OUT port of each
machine being connected to the MIDI IN port of the next machine in the
Network.

The Network will not work unless all machines are switched on (as with
QNet) and unless all machines are running the MIDINET device driver,
installed with LRESPR flp1\_MIDINET\_REXT (although the fileserver job
need not be running except on the master machine).

Once connected, this system works very much in the same way as the QNet
under Toolkit II, except that some file protection is provided to stop
other machines on the Network accessing important files (see MIDINET).

The following commands are provided:

-  MNET - Set the station number of this machine.

-  MNET% - Return the station number.

-  MNET\_S% - Confirm whether a machine with a given station number is
   connected to the Network.
   
-  MNET\_ON - Switch on the device driver.

-  MNET\_OFF - Switch off the device driver (this allows the MIDI port
   to be used independently).
   
-  MNET\_USE - Change the letter which identifies the device driver
   (normally N).
   
-  MIDINET - Start up the fileserver.

A17.4 Sernet
------------

This extension provided with the Atari Emulators and SMSQ/E allows you
to connect several different computers in a Network by linking their
serial ports together using suitable leads.

This can therefore be used to connect all machines which currently are
able to run QL software.

If you only have two machines in a Network, you can connect them by
using a Null-Modem-Cable. However, with more than two machines, as with
QNet the machines must be arranged to form a complete circle so that all
of the output signals from one machine are connected to the input
signals of the next machine.

The Network will not work unless all machines are switched on (as with
QNet), all machines are running the SERNET device driver (installed with
LRESPR flp1\_SERNET\_REXT) and SERNET has been configured on each
machine to inform it which serial port it is to use for communications.
Also, all of the machines must be set to the same BAUD rate before
SERNET is loaded.

In order to improve the network, handshaking should be implemented on
all ports, therefore to allow SERNET to use ser3 you may configure it to
use: SER3hd (presuming hardware handshaking is available). If hardware
handshaking is not available to some machines on the Network, you will
need to use SER3xd on all the machines.

Once connected, this system works very much in the same way as the
MIDINET.

The following commands are provided:

-  SNET - Set the station number of this machine.

-  SNET% - Returns the station number.

-  SNET\_S% - Confirm whether a machine with a given station number is
   connected to the Network.
   
-  SNET\_ROPEN - Re-opens the serial ports in case you have closed one
   from another program.
   
-  SNET\_USE - Change the letter which identifies the device driver
   (normally S).
   
-  SERNET - Start up the fileserver.

A17.5 Amadeus Interlink
-----------------------

This is a box which can be linked to a QL or PC computer and allows you
to connect up to 255 devices to a computer - these devices can be other
Amadeus-fitted computers, printers or sound interfaces. If you use this
to link computers together it provides in effect an extremely fast
Network system, with more speed the faster the computer!

We do not have details of how the Network system works at present.

A17.6 QL - PC Fileserver
------------------------

This is a software package which allows you (with the use of a cable
which can be supplied) to link a QL to a PC computer via a free serial
port and allows you to access the various devices provided by the PC.
However, if you wish to use the package with Minerva, you will need at
least v1.02 of the QL-PC Fileserver package. The original version will
not work with the Super Gold Card and these users will need the QL-PC
Fileserver II version (see below).

Basically, once the system has been set up and linked into both the QL
and PC, you have to create a fileserver task on the PC by entering a new
command on the PC (QLNET) and then on the QL side, simply set the
correct BAUD rate (for the PC) and enter the command PCSERVE to inform
the QL which serial port on the QL is linked to the PC.

Having done this, you are provided with various commands to find out
details of the drives connected to the PC and can access them by simply
using the device pcd, where DIR pcd1\_ will provide a directory listing
of drive A: on the PC, and DIR pcd3\_ will provide a directory listing
of drive C: on the PC (normally the hard disk).

Files can be saved onto the PC's devices in QL format to be read at a
later stage by any other QL. You can also access the PC's printer
(PC\_DEV ser2,lpt1 redirects all output to ser2 to the lpt1 device on
the PC) and even the PC's screen (the device PSCR is used to signify a
channel is to be OPENed on the PC's screen, replacing the QL's SCR
device).

Although speed is somewhat slower than using devices plugged into the
QL, at least this means that you could get away without having to buy
any disk drives (floppy or hard disk) for the QL.

One other thing that this package does is allow the QL to connect into a
PC network, thus opening up the world of the PC in a cost-effective
manner.

QL-PC Fileserver II is a newer version of the package which is much
enhanced, allowing the QL to be connected to the PC via Amadeus
Interlink as well as the serial ports. Full QL filename lengths are
supported in this version and if you use the PC's screen to display the
QL's output, this now supports QL windowing, colour and CON devices.
