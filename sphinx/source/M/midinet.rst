..  _midinet:

MIDINET
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MIDINET                                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

A file MIDINET\_rext is provided with SMSQ/E and the Emulators for the
Atari computers which allows you to set up a Network using the MIDI
ports provided on the Atari computers.

Once the Network has been set up
with the necessary leads, and MIDINET\_rext been loaded on all computers
in the Network, the command MIDINET should be issued to start up the
fileserver Job on each computer. This creates a background Job called
'MIDINET' which is similar to the 'Server' Job created by FSERVE.

The two fileservers are very similar in operation in that they both allow
other computers to access the resources of the Master machine over the
Network. However, MIDINET has built-in protection for files which can
prevent other users in a Network accessing sensitive files. This is
implemented by means of recognising files which *start with* a specific
series of characters:

+------------+-----------------------------------------------------------------------+
| Characters | Effect                                                                |
+============+=======================================================================+
| \*H or \*h | These files cannot be accessed over the Network. Any attempt          |
|            | to use these files by a Slave Machine will return 'Not Found' errors. |
+------------+-----------------------------------------------------------------------+
| \*R        | These files are Read Only over the Network.                           |
+------------+-----------------------------------------------------------------------+
| \*D        | These files cannot be accessed over the Network and will              |
|            | return 'Not Implemented' - this prevents direct sector access.        |
+------------+-----------------------------------------------------------------------+

**CROSS-REFERENCE**

:ref:`mnet` is needed to control the Network. See
also :ref:`fserve` and
:ref:`sernet`. See the Appendix on Networks for
further details.

