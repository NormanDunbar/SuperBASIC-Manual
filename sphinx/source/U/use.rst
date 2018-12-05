..  _use:

USE
===

+----------+-------------------------------------------------------------------+
| Syntax   |  USE [ #channel ]                                                 |
+----------+-------------------------------------------------------------------+
| Location |  USE (DIY Toolkit - Vol C)                                        |
+----------+-------------------------------------------------------------------+

Many commands and functions which are described in this manual, expect
a channel number to be passed to them and if one is not supplied, will
default to a specific channel. This command can be used to re-direct all
machine code commands and functions which normally default to #1.

After using this command, if a channel parameter is not specified, the
commands and functions will then default to the channel specified by USE
instead of #1. Also, *even* if you explicitly pass a channel number #1 as a
parameter to a command or function, then the command or function will
*still* be re-directed to the channel specified by USE. If no parameter is
specified, then this is equivalent to USE #1.

**Example**

::

    PRINT 'This is channel #1': USE #2: PRINT 'This is using Channel #2'
    PRINT #1, 'This is still channel #2' USE: PRINT 'This is channel #1 again!'

**NOTE**

There is a slight difficulty in using this command in that when you USE
#1 some of the information used by SuperBASIC for the channel which you
have been using as the default will be lost. This is the last graphics
co-ordinates, turtle graphics direction, pen status, character position
on line and line width for files (set with WIDTH) will be lost. You will
also lose the original values for these offsets for channel #1 (ie. the
values which were in use prior to the USE #ch command). Instead, the
values are set to pen up, position 0,0, width 80, direction
left-to-right. You can use::

    PEEK_W(\48\chan*40+offset)

to store these
values before the USE call and then restore them with POKE. Refer to
QDOS/SMS Reference Manual Section 18.4.1 to find out how these values
are stored.

**WARNING**

If used from within a SMS SBASIC, v0.2 (at least) of this command will
crash the computer when output is redirected to #1 using either USE or
USE#1. The problem only occurs when you try to send output to #1.

**CROSS-REFERENCE**

:ref:`print`,\ :ref:`csize`,\ :ref:`ink`,\ :ref:`paper`
and\ :ref:`strip` are just a few of the commands
which default to #1 and are therefore affected by this command.

--------------



