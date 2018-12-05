..  _par-buff:

PAR\_BUFF
=========

+----------+------------------------------------------------------------------+
| Syntax   | PAR\_BUFF [size] or                                              |
|          |                                                                  |
|          | PAR\_BUFF port\_number, size(SMSQ/E only)                        |
+----------+------------------------------------------------------------------+
| Location | ST/QL, SMSQ/E                                                    |
+----------+------------------------------------------------------------------+

Normally, SMSQ/E and the Emulator will use all available memory as a
buffer for its serial and parallel ports (this is known as a dynamic
buffer). Although this enables control to be returned to programs very
quickly after sending output to one of the ports, it can however mean
that the whole of the memory can be filled up with printer output.

The command PAR\_BUFF therefore allows you to specify a fixed size in bytes
for the parallel buffer for each channel opened to it.

If no size is specified, or a size of 0 bytes is set, then the parallel buffer becomes
dynamic once again. Otherwise, size should be at least 5 bytes to ensure future compatibility.

**Example**

::

    PAR_BUFF 10000

sets the parallel buffer to 10000 bytes.

**NOTE**

Although the SMSQ/E implementation allows a port to be specified, there
are currently no implementations of the QL which have more than one
parallel port, therefore trying to pass a port\_number at present
results in a bad parameter error.

**CROSS-REFERENCE**

:ref:`prt-use` sets up a dynamic printer buffer
except under SMSQ/E.

--------------


