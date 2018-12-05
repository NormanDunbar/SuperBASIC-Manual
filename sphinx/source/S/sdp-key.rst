..  _sdp-key:

SDP\_KEY
========

+----------+-------------------------------------------------------------------+
| Syntax   |  SDP\_KEY [key$]                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card, Trump Card, SDUMP\_REXT, ST/QL                        |
+----------+-------------------------------------------------------------------+

In order to facilitate easy screen dumps, the command SDP\_KEY will set
up a hotkey which when pressed together with <ALT> will cause the whole
of the screen starting at $20000 to be sent to the SDUMP device. Under
SMS, you will first need to LRESPR SDUMP\_REXT provided on the
distribution disk to use this command. As with ALTKEY, if the specified
key$ is in upper case, you will need to press <ALT><SHIFT> together with
the key, or <ALT> with the key if capslock is on. SDP\_KEY without any
parameters inhibits the hotkey.

**Example**

::

    SDP_KEY p

will cause the screen to be dumped each time that <ALT><P> is pressed.

**CROSS-REFERENCE**

:ref:`sdp-dev` allows you to alter where the
output is to go. See :ref:`sdp-set` and
:ref:`sdump`.

--------------


