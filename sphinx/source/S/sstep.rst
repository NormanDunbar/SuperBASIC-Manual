..  _sstep:

SSTEP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  SSTEP [{#ch \| device\_file}] [; [first] [TO [last]]]            |
+----------+-------------------------------------------------------------------+
| Location |  Minerva (TRACE)                                                  |
+----------+-------------------------------------------------------------------+

Minerva is supplied with a very simple trace routine on the utility
disk supplied with Minerva, stored in the file trace\_bin. Before using
the trace function, you will need to link in trace\_bin with the line::

    LRESPR flp1_trace_bin

or something similar. Having done this, you can turn on the tracing
function with SSTEP which will print to the given channel (default #0)
or file, each line number and statement just before it is performed in
the format: line\_no : statement\_no.

You can also supply the trace function with a line range, so that it
will only report on statements being executed within the given line
range. The line range defaults to: 1 TO 32767.

Whilst the trace function is enabled and the program is running within
the given range, the interpreter will wait for a key to be pressed
between each statement. As each command in each statement is executed, a
single character is shown by the trace routine to represent the type of
the command to be executed. However, the meaning of these symbols has
never been revealed. In single-step mode, you need to press a key
between each command!!

**NOTE**

This trace toolkit will only work on Minerva.

**CROSS-REFERENCE**

See :ref:`tron` and :ref:`troff`.

--------------


