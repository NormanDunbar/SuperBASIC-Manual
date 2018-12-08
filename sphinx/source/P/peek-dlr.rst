..  _peek-dlr:

PEEK$
=====

+----------+------------------------------------------------------------------+
| Syntax   | PEEK$ (start\_address,bytes)  or                                 |
|          |                                                                  |
|          | PEEK$ (start\_address [,bytes])(BTool only)                      |
+----------+------------------------------------------------------------------+
| Location | ATARI\_REXT, SMS, TinyToolkit, BTool                             |
+----------+------------------------------------------------------------------+

This function will read a specified number of bytes from start\_address
in memory onwards and return the result as a string.

For BTool the second parameter is optional. If bytes is not specified then BTool's
PEEK$ will try to read a string in QDOS format (ie. two bytes specifying
the length of the string followed by the string itself) from the
location start\_address, just like CVS$ does. This string will then be
returned. Note that start\_address must always be even if bytes is omitted.

**Example**

Do you know how many keywords, filenames, variables etc. are currently
known to the interpreter? This program lists and counts them.

::

    100 adr=BASICP(32): num=0
    110 REPeat all_names
    120   length=PEEK(adr)
    130   IF NOT length THEN EXIT all_names
    140   name$=PEEK$(adr+1,length)
    150   PRINT name$,
    160   adr=adr+length+1: num=num+1
    170 END REPeat all_names
    180 PRINT\\num!"names"

**SMS NOTE**

PEEK$ allows you to access the System Variables and SuperBASIC variables
in the same way as PEEK (etc.). For example, the above short program may
be re-written as::

    100 adr=0: num=0
    110 REPeat all_names
    120   length=PEEK(\$20\adr)
    130   IF NOT length THEN EXIT all_names
    140   name$=PEEK$(\$20\\adr+1,length)
    150   PRINT name$,:PAUSE 160 adr=adr+length+1: num=num+1
    170 END REPeat all_names
    180 PRINT\\num!"names"

**WARNING**

A string cannot be longer than 32766 characters and so an expression
such as a$=PEEK$(0,40000) may lead to unpredictable effects. Be careful!

**CROSS-REFERENCE**

:ref:`poke-dlr` is the complementary procedure to
:ref:`peek-dlr`. :ref:`peek`,
:ref:`peek-w` and
:ref:`peek-l` read single bytes, words and long
words from memory. :ref:`ttpeek-dlr` is the same as
this function.

