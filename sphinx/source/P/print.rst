..  _print:

PRINT
=====

+----------+----------------------------------------------------------------------------------------------------------------------------------+
| Syntax   | PRINT [#chan,] :sup:`\*`\ [ [separator] [strg\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\*` or                               |
|          |                                                                                                                                  |
|          | PRINT :sup:`\*`\ [ [#chan,] [separator] [strg\ :sup:`i`\ $ separator] var\ :sup:`i`]\ :sup:`\*` (THOR XVI & Minerva v1.97+ only) |
+----------+----------------------------------------------------------------------------------------------------------------------------------+
| Location | QL ROM                                                                                                                           |
+----------+----------------------------------------------------------------------------------------------------------------------------------+

This command will send a string of bytes to the specified channel
(default #1).

If any variables (var) are specified, the contents of
those variables are PRINTed in the specified channel.

If the channel is a window, the characters printed appear at the current text cursor
position, in the current INK colour on the current STRIP colour, and will also be affected by the
settings of CSIZE, UNDER, FLASH and OVER.

If you tell PRINT to use an unset variable, an asterisk ('\*') will be PRINTed on screen rather than
an error being reported (except on SMS where an unset variable is given
the value 0 (if a numeric variable) or '' for a string). Beware, however
that if you try to use an unset variable in a calculation inside the
PRINT statement, an 'Error in Expression' error will be generated, for
example::

    a=10 : PRINT 'A is :'! a ,'B is :'! b : PRINT 'A*B is :' !a*b

If a channel is specified, this must be followed by a comma. It may
however also be followed by one or more separators, as with INPUT.

At the end of the PRINT command, the text cursor is placed at the start of
the next print line (unless an end separator of '!', '\\' or ';' is
used). When using a separator of '!', TO or ',' on a non-window channel,
the PRINT statement will always assume the end of each line to be the
number of characters specified with the WIDTH
command, thus allowing you to format your output on a printer, for
example.

**Example**

The following procedure allows you to print text to a given channel
without splitting words when the text wraps onto the next line::

    100 DEFine PROCedure PRINT_TEXT(ch,txt$)
    110   LOCal print_loop
    120   REPeat print_loop%
    130     IF LEN(txt$)=0:PRINT #ch:RETurn
    140     I%=' ' INSTR txt$
    150     IF I%=0:PRINT #ch!!txt$:RETurn
    160     PRINT #ch!!txt$(1 TO I%-1)!
    170     IF I%<LEN(txt$):txt$=txt$(I%+1 TO):ELSE txt$=''
    180   END REPeat print_loop%
    190 END DEFine

Try::

    WINDOW #1,50,100,32,16: PRINT_TEXT #1,'This is a test line'

Compare::

    PRINT #1,'This is a test line'

**NOTE 1**

Version 6.40 of the THOR XVI ROM can crash if you try to use PRINT with
the '!' separator in a non-window channel.

**NOTE 2**

The THOR XVI (all versions) and non-Minerva ROMs (unless SMS is
installed) have problems with the concatenation of values which should
produce an 'Overflow Error'. For example::

    PRINT 'hello'&(1/0)

may crash the computer rather than producing an overflow error.

**NOTE 3**

PRINT can only show a maximum of six *integer* digits. If a number is
larger than this, it will be represented by the E function (eg. 1E2 is
the same as 100). If on the other hand, the figure is a *floating point*\ ,
then the QL can cope with seven digits excluding the decimal point, eg.
123.4567. Any more digits will cause the number to be rounded up or down
as appropriate.

**MINERVA NOTE**

v1.97+ allows different channels part way through statement as per THOR
XVI.

**THOR XVI NOTE**

Version 6.41 of the THOR XVI allows you to put channel numbers part way
through a statement, for example::

    PRINT 'Name:'!name$ \#0; 'Address:' !address$

instead of::

    PRINT 'Name '!name$ : PRINT #0;'Address:'!address$

**CROSS-REFERENCE**

See also :ref:`input` which contains a description
of the different types of separators. Please also see
:ref:`width`. :ref:`to` has other
meanings - see :ref:`to`.
:ref:`vg-print` allows you to print using
scalable fonts on screen. :ref:`char-use` and
:ref:`char-def` allow you to alter the fonts
used for printing characters on screen.

--------------


