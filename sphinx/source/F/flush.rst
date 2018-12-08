..  _flush:

FLUSH
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  FLUSH [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

The command FLUSH forces all of the QL's temporary buffers attached
to the specified channel (default #3) to be emptied into that channel.
This will only work on channels attached to files, any other type of
channel will return error -15 (bad parameter).

This command is
necessary due to the use by QDOS of slave blocks whenever a file is
opened. Data can be stored partly in the slave blocks to aid speed and
when writing to a file, which will only be written to that file once the
channel has been CLOSEd or the slave blocks have become full.

Because of
this, there is always a danger that part of the data will be lost if
there is a power failure or other accident. FLUSH helps you to avoid
this.

**NOTE**

FLUSH will not work with Micro Peripherals disk drives. Nor can it be
used to flush the Networks.

**CROSS-REFERENCE**

See :ref:`open` and :ref:`close`.

