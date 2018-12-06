..  _eof:

EOF
===

+----------+-------------------------------------------------------------------+
| Syntax   |  EOF [(#ch)]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This is a logical function which actually has two uses in SuperBASIC. If no channel
number is specified, then PRINT EOF  will return 1 unless the current program
contains some DATA  lines which have not yet been READ. This is therefore useful
to create programs which can handle any amount of data. However, if a channel
number is specified, for example PRINT EOF(#1), then zero will be returned unless
the given channel is linked to a file and the file pointer is at (or beyond) the
end of that file (ie. whether or not there is data to be read from that channel).

**Example**

Two simple programs to retrieve an address from a given name (the full
name must be given on input). The first of these has the data stored in
the program, whereas the second has it stored on a file called
flp1\_address\_data::

    100 RESTORE
    110 MODE 4
    120 OPEN #3,con_448x200a32x16:BORDER#3,1,2:PAPER#3,0:INK#3,7
    130 INPUT #3,'Input name to look for:'!search$
    140 REPeat loop
    150   IF EOF:PRINT#3\\"No address stored":EXIT loop
    160   READ name$,address$
    170   IF name$==search$:PRINT #3\\name$,address$:EXIT loop
    180 END REPeat loop
    190 CLOSE #3
    200 DATA 'Fred Blogs','17 Mulberry Court'
    210 DATA 'John Peters','182 Johnson Ave.'
    220 DATA 'Martin Edwards','83 Olive Drive'

::

    100 OPEN_IN #3,flp1_Address_data
    110 MODE 4 120 OPEN #4,con_448x200a32x16:BORDER#4,1,2:PAPER#4,0:INK#4,7
    130 INPUT #4,'Input name to look for:'!search$
    140 REPeat loop
    150   IF EOF(#3):PRINT#4\\"No address stored":EXIT loop
    160   INPUT #3;name$,address$
    170   IF name$==search$:PRINT #4\\name$,address$:EXIT loop
    180 END REPeat loop
    190 CLOSE #4:CLOSE #3

**SMS NOTE**

Until v2.55 this command was the same as EOFW, which meant that it would
only return a value if there was data waiting or it had received an end
of file code - this was changed back to the original to maintain
compatibility.

**CROSS-REFERENCE**

:ref:`data` specifies a line of data statements.
:ref:`restore` resets the data pointer and
:ref:`read` will actually fetch the data.
:ref:`close` closes a given channel after it has
been used. :ref:`pend` or
:ref:`io-pend-pct` are much better for use on
pipes. See also :ref:`eofw`.

