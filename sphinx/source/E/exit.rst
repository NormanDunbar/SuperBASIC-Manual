..  _exit:

EXIT
====

+----------+-------------------------------------------------------------------+
| Syntax   | EXIT loop\_variable (FOR loops)  or                               |
|          |                                                                   |
|          | EXIT loop\_name (REPeat loops)  or                                |
|          |                                                                   |
|          | EXIT(SMS only)                                                    |
+----------+-------------------------------------------------------------------+
| Location | QL ROM                                                            |
+----------+-------------------------------------------------------------------+

Using the first two variants of this command, the specified loop
(either a FOR or a REPeat structure) will be finished and the program
will jump to the first statement after the relative END FOR
loop\_variable or END REPeat loop\_name.

The third variant only exists
under SMS and will force the interpreter to jump out of the current loop
being executed, whether it is a FOR loop or a REPeat loop - the
interpreter will just search the program for the next END REPeat or END
FOR statement.

**NOTE 1**

If two or more loops are nested together, it is possible to EXIT the
outer loop from within the inner loop::

    REPeat loop1
      ...
      REPeat loop2
        ...
        IF condition THEN EXIT loop1 ---+
        ...                             |
      END REPeat loop2                  |
      ...                               |
    END REPeat loop1                    |
    ...                    <------------+


Such a structure is not regarded as elegant by some people because it is
not possible to draw a structogram from this.

**NOTE 2**

If a program is badly written, this can lead to confusion - for example,
try::

    100 REPeat loop
    120   PRINT 'Hello'
    130   EXIT loop
    140 END REPeat loop
    150 END REPeat loop

The interpreter fails to notice the misplaced END REPeat at line 150.

The first time that EXIT loop is encountered, the interpreter leaves the
loop at line 140 - however, line 150 forces the interpreter to execute
the loop a second time. This time, EXIT loop forces the interpreter to
jump out the loop at line 150. The same thing happens if you use FOR ...
END FOR instead of REPeat ... END REPeat

This feature allows you to jump back into a loop from anywhere in the
program (although this should be avoided). Compare what happens if NEXT
loop is used instead of END REPeat loop in line 150, EXIT loop will
always exit the loop at line 140. This means that NEXT loop can also be
used to jump back into a loop from anywhere in the program (although
again, this should be avoided).

Note that in any event, these latter two
features will only work if the named loop has already been RUN (setting
up the loop variables)!!

**CROSS-REFERENCE**

Please see :ref:`for` and
:ref:`repeat` for more details.

