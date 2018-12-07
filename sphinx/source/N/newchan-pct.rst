..  _newchan-pct:

NEWCHAN%
========

+----------+-------------------------------------------------------------------+
| Syntax   |  NEWCHAN%                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Function (DIY Toolkit - Vol R)                                   |
+----------+-------------------------------------------------------------------+

When writing / designing SuperBASIC programs, it is essential that you
try to keep the channel numbers as small as possible for two reasons -
compilers only allow a fixed number of channels to be OPENed by a
program (normally 16) and if you OPEN #100,scr (for example), space has
to be created by SuperBASIC in the channel table for channels #1 to #99,
thus wasting a lot of memory if those channels are not used.

This
function can therefore be quite useful - it looks at the channel table
and returns the number of the next available channel number which can be
OPENed.

**Example**

After::

    NEW
    PRINT NEWCHAN%

will always return 3, as the only channels OPEN will be #0, #1 and #2.

**CROSS-REFERENCE**

:ref:`open` allows you to open a channel.
:ref:`fopen` and similar functions will
automatically open the next available channel number.
