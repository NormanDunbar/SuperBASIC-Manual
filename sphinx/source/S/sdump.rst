..  _sdump:

SDUMP
=====

+----------+------------------------------------------------------------------+
| Syntax   | SDUMP #ch  or                                                    |
|          |                                                                  |
|          | SDUMP [width,height,xpos,ypos] or                                |
|          |                                                                  |
|          | SDUMP [{address \| address,width,height,xpos,ypos}]              |
+----------+------------------------------------------------------------------+
| Location | Gold Card, Trump Card, SDUMP\_REXT, ST/QL                        |
+----------+------------------------------------------------------------------+


The command SDUMP allows you to dump a screen (or part of a screen) to
a printer (or a file), using one of the in-built formats (one of which
will hopefully work on your printer!) - see SDP\_SET.

Under SMS, you
will first need to LRESPR SDUMP\_REXT provided on the distribution disk
to use this command.

The first variant is the simplest, it will dump the
whole of the contents of the specified window #ch to the printer. If the
second variant is used, SDUMP will dump the whole of the screen defined
by widthXheightAxposXypos (using absolute pixel co-ordinates).

If no
parameters are supplied, SDUMP will dump the whole screen. The third
variant of the command is intended to dump a screen which has been
stored under the Pointer Environment's PSAVE function. The address
returned by PSAVE should be used as the first parameter of the SDUMP
command. If no further parameters are specified, the whole area stored
at the specified address will be dumped, otherwise you can specify the
area of that buffer to be dumped in much the same way that you can
specify an area of the screen to be dumped.

**Example**

::

    OPEN #3,scr_448x200a32x16:SDUMP #3:CLOSE #3

and::

    SDUMP 448,200,32,16

are the same.

**NOTE 1**

Some early versions of SDUMP expect the screen to start at 131072 and be
512x256 pixels in size and can therefore get very confused in dual
screen mode on Minerva and Amiga QDOS. However, later versions supplied
with SMS check the screen size and base when the toolkit is linked into
memory and expect it to remain the same afterwards!

**NOTE 2**

SDUMP does not work on Minerva, unless you have v2.23 (or later) of the
Trump Card / Gold Card. If you have an earlier version of Toolkit II and
want to use SDUMP, you have to ensure that another Job (such as FSERVE)
is running when SDUMP is issued.

**NOTE 3**

Once SDUMP has started its work, it is not easy to abort it early - any
further attempt to use the serial port will result in the error 'In
Use'.

**NOTE 4**

If you have directed the output to a file, the file will be
automatically overwritten if necessary.

**CROSS-REFERENCE**

:ref:`sdp-set` allows you to alter the printer
format. :ref:`sdp-key` allows you to set up a
hotkey to dump the screen. :ref:`sdp-dev` allows
you to alter the device where the dump is to be sent.

