..  _set:

SET
===

+----------+------------------------------------------------------------------+
| Syntax   | SET x, y, col                                                    |
+----------+------------------------------------------------------------------+
| Location | HCO                                                              |
+----------+------------------------------------------------------------------+

SET does the same as PLOT with SCRBASE 131072 set, ie. it does not
support virtual screens. x ranges from 0 to 511, y from 0 to 255. The
colour (col) is specified by an integer from 0 to 3, representing the
four colours available in MODE 4: 0 ... black 1 ... red 2 ... green 3

**NOTE**

Although SET is not designed to, it does work in MODE 8 but the colours
appear differently: Colour 1 is not red but magenta for example.

**WARNING 1**

SET writes directly into screen memory and assumes that it starts at
131072, so SET may crash the machine if the screen is located at another
position in memory. SET also assumes a resolution of 512 x 256 pixels.

**WARNING 2**

SET does not check for the existence of the parameters (this means for
example that it will not report 'bad parameter' for SET x, y), it may
crash if any of the parameters are omitted.

**CROSS-REFERENCE**

:ref:`plot`. We highly recommend that you use the
QDOS inbuilt window relative graphic routine,
:ref:`point` in this case.
:ref:`col` finds the colour of a screen pixel. See the
other implementation of :ref:`set` also.




SET
===

+----------+------------------------------------------------------------------+
| Syntax   | SET [#]variable TO value                                         |
+----------+------------------------------------------------------------------+
| Location | SET, ALTER (DIY Toolkit - Vol U)                                 |
+----------+------------------------------------------------------------------+

This command allows you to set up various universal constants which
allow programs to read various values which are set by other programs.
This is similar to creating machine code functions which return constant
values.

The constants to be set up appear as 'variable' in the command syntax above.

They can be string, floating point or integer but must not have
previously been used in the program (otherwise the error 'In Use' will
be reported). They must also not appear in quotes. The constants should
be SET from SuperBASIC Job 0, otherwise they do not seem to work (at
least on Minerva). However, other programs can use ALTER to change the
value of the constants and also read the constants as if they were
predefined variables.

As an added bonus, if the variable is prefixed by
a hash sign, then this is taken to be a pointer to a system variable, which
will always point to that system variable even if the system variables
move. For example to read the Network number, you could use::

    SET #NET_ID TO HEX('37')
    PRINT PEEK (NET_ID)

instead of::

    SET NET_ID TO HEX('37')
    PRINT PEEK (SYS_VARS + NET_ID)

**Example**

Set the following from SuperBASIC::

    10 SET FALSE TO 0 : SET TRUE TO 1
    20 SET YES$ TO 'Yy' : SET NO$ TO 'Nn'
    30 SET DEF_DRIVE$ TO 'flp1_'

Any other program can then just use lines such as::

    IF INKEY$(1) INSTR YES$ : PRINT 'Yes has been selected'

and::

    LBYTES DEF_DRIVE$ & 'prog_data', space

**NOTE 1**

SET does not work on SMS.

**NOTE 2**

SET #value does not appear to work on Minerva v1.97 (at least in
versions up to v1.66 of the toolkit).

**NOTE 3**

Any attempt to use SET from within a multiple BASIC will have no effect.

**CROSS-REFERENCE**

See :ref:`alter`. :ref:`true-pct`,
:ref:`false-pct` and :ref:`pi` are
predefined constants.

