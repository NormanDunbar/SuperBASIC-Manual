..  _ser-buff:

SER\_BUFF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  SER\_BUFF [port, ] output\_size [,input\_size]                   |
+----------+-------------------------------------------------------------------+
| Location |  ST/QL, SMSQ/E                                                    |
+----------+-------------------------------------------------------------------+

Used with one parameter, this is the same as PAR\_BUFF except that it
sets the size of the output buffer attached to each SER channel. The
input buffer is normally a dynamic buffer, unless input\_size is
specified. The output buffer should be a minimum of 5 to avoid confusion
with the port number.

You can also use SER\_BUFF to alter the size of
the input buffer, by using the form::

    SER_BUFF output_size, input_size

Although you will need to specify the output\_size, you can set this to
0 to enable a dynamic output buffer. You can also specify which serial
port number is to be used to allow this command to work on machines with
more than one serial port (this defaults to SER1).

**Examples**

::

    SER_BUFF 200

Set the output buffer size to 200 bytes, with a dynamic input buffer.

::

    SER_BUFF 200,500

Have an output buffer of 200 bytes, with an input buffer of 500 bytes.

**NOTE 1**

The actual usable input buffer will be calculated by the value set by
SER\_BUFF less the value set by SER\_ROOM.

**NOTE 2**

In version E-17 of the device drivers for the Atari Emulator (and later
implementations of this command, including SMSQ/E), whenever you use
this command, the value set by SER\_ROOM

is re-calculated so that it is set to one quarter of the input buffer
size. Earlier versions may (after Level B09) would report an error if
the input buffer was not at least twice the size of the value set by
SER\_ROOM.

**CROSS-REFERENCE**

See :ref:`par-buff`! You should also refer to
:ref:`ser-room`.

--------------


