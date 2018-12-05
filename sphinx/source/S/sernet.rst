..  _sernet:

SERNET
======

+----------+-------------------------------------------------------------------+
| Syntax   |  SERNET                                                           |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

A file SERNET\_rext is provided with SMSQ/E, QXL and the Emulators for
the Atari computers which allows you to set up a Network using the
Serial ports provided. Once the Network has been set up with the
necessary leads, and SERNET\_rext been loaded on all computers in the
Network, the command SERNET should be issued to start up the fileserver
Job on each computer. This creates a background Job called 'SERNET'
which is similar to the 'Server' Job created by FSERVE.

The two
fileservers are very similar in operation in that they both allow other
computers to access the resources of the Master machine over the
Network. As with MIDINET, SERNET has built-in protection for files which
can prevent other users in a Network accessing sensitive files. Refer to
MIDINET for details.

**CROSS-REFERENCE**

:ref:`snet` is needed to control the Network. See
also :ref:`fserve` and
:ref:`midinet`. See the Appendix on Networks for
further details.

--------------


