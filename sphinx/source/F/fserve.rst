..  _fserve:

FSERVE
======

+----------+------------------------------------------------------------------+
| Syntax   | FSERVE or                                                        |
|          |                                                                  |
|          | FSERVE [device\_name] (THOR XVI - v6.41 only)                    |
+----------+------------------------------------------------------------------+
| Location | Toolkit II (hardware version only or SMS), THOR XVI              |
+----------+------------------------------------------------------------------+

This command creates a small fileserver job named Server which allows
other network stations (slaves) to access all devices on the machine
where this fileserver is running (this is the Master).

The fileserver
only works with the QNET network system, which itself only works
reliably if Toolkit II is installed as firmware (ie. on ROM or on EPROM)
(or if Toolkit II is installed as part of SMS) on all machines connected
to the network.

To access a device on the Master, a prefix has to be
added to the device name. This prefix specifies the other machine by its
network number (see NET) which may range from 1 to 8. The prefix
consists of an n, the number of the remote station and an underscore,
ie: n1\_ .. n8\_.

If an access fails for any reason, the sending machine
will not receive an acknowledgement from the receiving one. In such
cases, the network driver continues to try to get through for about 20
seconds and then reports 'Network aborted' (in #0) if it still cannot
communicate with the specified machine.

**Examples**

::

    OPEN#3,n3_scr: PRINT#3,"Bye.": FLUSH#3: CLOSE#3
    WDIR n1_flp1_

::

    FORMAT n7_win1_

Be careful with this sort of thing!

::

    SAVE n2_ram1_PROGGY_bas

**NOTE 1**

All commands which use the SD.EXTOP or SD.FOUNT machine code calls will
not work across the network: CHAR\_USE for example. This does not
necessarily mean that these commands report errors: CHAR\_USE, for
instance, changes the character set to a strange pattern. FORMAT will
also fail over the Network. ED and EDIT also cannot be used to edit a
program on a window opened over the Network.

**NOTE 2**

Although windows (scr\_ and con\_ devices) are normally not buffered,
this will be the case if they are opened across the network. This
affects just text output, all other operations (BORDER, INK, CLS, WINDOW
etc.) are performed on the host QL when issued. The buffer of 256 bytes
is located in the sending QL and flushed automatically if full.
Otherwise a CLOSE command forces the buffer contents to be sent (the
FLUSH command will not work to send the buffer contents). See the
Drivers section in the Appendix for further details on Networks.

**NOTE 3**

If a channel was opened by a slave via the network and this QL is
later removed from the network - say by unplugging the network lead or
by resetting the machine, then the channel is left open. As all such
channels are owned by the Server job, they can be flushed and closed by
removing and restarting the job::

    RJOB Server
    FSERVE

Take care that all operations being carried out by other stations on
the local machine (where the fileserver is to be removed) have finished
or have been suspended.

**NOTE 4**

Due to checksum tests, data transmission across the network is
practically error free. There is still a very small statistical
possibility of transmission errors but really extensive experiments
(moving megabytes of data) did not even produce one.

**NOTE 5**

Although a normal file name can be of any length up to a maximum of 41
characters (including the device name), if the file is to be accessed
across the network, this is reduced to a maximum of 39 characters
(including the network prefix). For example::

    OPEN #3,flp1_Quill_letters_Minerva2_update_doc239
    OPEN #3,n1_win1_Quill_letters_Minerva2b_updates

will work, whereas the following two commands report 'Not Found'
without attempting to access the drives::

    OPEN #4,flp1_Quill_letters_Minerva2_update_doc2392
    OPEN #4,n1_win1_Quill_letters2_Minerva2b_updates

**NOTE 6**

If you OPEN a con\_ device over the Network (onto a Master machine's
screen) and try to use INPUT to read a variable entered on that Master,
there are problems here in that the delete keys on the Master which is
displaying (and editing) the text displayed in the con\_ device do not
work properly, leaving splodges on the screen. You can use IO\_TRAP and
QTRAP to call cursor positioning routines on the Master and then print
spaces to overwrite the deleted characters, using IO\_TRAP or QTRAP to
move the cursor back to the correct position and possibly pan the window
to get rid of excess characters. This technique was used to good effect
in the NetPal program in DIY Toolkit (Vol N).

**NOTE 7**

If you try to use a Toolkit II command such as DIR to direct the output
onto a window which has been OPENed over the Network, when it reaches
the bottom of a page, the Toolkit II command automatically generates a
<CTRL><F5> at the slave machine end which can only be cleared by
pressing a key on the slave machine's keyboard.

**THOR XVI NOTE**

The THOR XVI version of this command allows you to send, for example, a
continuous log of status messages to a file or device, eg. FSERVE
scr\_512x256a0x0. This is however really only useful for debugging
network programs or to analyse network traffic.

**CROSS-REFERENCE**

The fileserver job can be removed with :ref:`rjob`,
:ref:`kjob`, :ref:`kill` etc. or
by using a desktop application (such as QPAC2). See
:ref:`net` and :ref:`nfs-use`
for further information on networking.

Refer to the original
documentation of Toolkit II and the Device Drivers Appendix for
technical details. :ref:`sernet` and
:ref:`midinet` create fileservers for other
Networks supported by SMSQ/E and the Atari ST Emulators.

--------------


