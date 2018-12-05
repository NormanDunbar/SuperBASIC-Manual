..  _outln:

OUTLN
=====

+----------+------------------------------------------------------------------+
| Syntax   | OUTLN [#chan,] width,height,x,y [,x\_shad,y\_shad] or            |
|          |                                                                  |
|          | OUTLN (SMSQ/E only)                                              |
+----------+------------------------------------------------------------------+
| Location | ATARI\_REXT (v2.12+), SMSQ/E                                     |
+----------+------------------------------------------------------------------+

This command is used within the Pointer Environment to signal that a
specified window (default #0) which must already be open, is to be
looked after by the Pointer Environment (managed).

Because of the way in
which the Pointer Environment works, it is always a good idea to use
OUTLN on the first window to be used for input/output by a program (this
is known as the Primary Window), as this will ensure that all windows
which are subsequently OPENed by the program will be what is known as
Secondary Windows and also managed.

Because of this, if a program is to
be run under the SuperBASIC interpreter, OUTLN
should be used on #0, whereas in a compiled program, OUTLN needs to be
used on the first channel which is OPENed (ensure that the program is
compiled without any windows open).

Hints on writing programs to run
under the Pointer Environment appear below, showing how OUTLN should be
used.

If an OUTLN has been defined, any attempt to OPEN a window which
would fall outside of the managed Primary Window will cause an 'out of
range' error. If you then use OUTLN on a Secondary window, the first
time that OUTLN is encountered after the window is OPENed, the contents
of the screen under that window will be stored. Then, if you again use
OUTLN on the same window, the contents of the screen under the Secondary
Window are restored (see the example).

With the first syntax of the
command, the first five parameters supplied to OUTLN are exactly the
same as with WINDOW, however, you can also add two further parameters,
x\_shad and y\_shad to specify the width of a shadow which will appear
to the right and bottom (respectively) of the window to make it stand
out. They both default to zero (no shadow).

SMSQ/E v2.53+ allows the
second syntax, which will allow you to use OUTLN without any parameters
at all. In this case, the primary window will be outlined to the
smallest area which can encompass all currently OPEN windows at the time
that OUTLN is used.

**Writing programs to use the Pointer Environment**

Some information concerning this appears in Section 4, however, when
designing a program to use the Pointer Environment, it is useful to
follow this procedure:

#. Open a main channel to define the maximum screen area available to the job, eg: OPEN #1,con\_
   This should be the first window OPENed by the program - if it is compiled, compile the program without Windows enabled.

#. Fetch the screen limits, eg::

     scr_width%=QFLIM (#1,0)
     scr_height%=QFLIM (#1,1)

#. Ensure that the screen is in the right mode::

     IF RMODE<>0: MODE 4

#. Outline #1 (the main channel) to the size of the program::

     OUTLN #1,450,210,0,0

The program will then have a maximum screen area of 450x210 pixels
available. When you wish to resize the program's display, you will need
to mark the main channel (#1) as unmanaged and then use OUTLN to resize
the main channel. For example, the following method was used (using
commands from EasyPTR by Jochen Merz Software) to allow the user to re-
size the program Q-Route (available from Q Branch):

The procedure is
called when the user highlights the Resize Loose Item on the main menu
(which is drawn on #1). In order for this to work, the main menu had to
be loaded as a separate file into the common heap area pointed to by the
variable m\_store (as there is no way in current versions of EasyPTR to allow you to find
the address of the original menu definition in an Appended definition
file - this is not the working menu definition used by the Window
Manager).

For more general information on EasyPTR, you are directed to
the EasyPTR tutorial contained in the Quanta magazine in 1994. The
outline of a routine (excuse the pun) to re-size the main menu used by a
program appears on the next page (note that this requires EasyPTR (c)
Albin Hessler, and substantial additions to the code in order to work)::

    9620 DEFine PROCedure RESIZE_MAIN
    9621   sel_key%=0
    9622   DIM result%(16)
    9630   PVAL #Main_menu,result%
    9635   old_x%=result%(14):old_y%=result%(15)
    9637   : REMark Fetch original pointer co-ordinates
    9640   pxpos%=old_x%:pypos%=old_y%
    9650   RDPT #Main_menu,130,pxpos%,pypos%
    9651   : REMark Draw and move re-size ICON
    9652   : REMark NOTE THIS CRASHES SUPERBASIC!!
    9655   PVAL #Main_menu,result%
    9660   IF result%(6)=27:st%=MSTAT%(#Main_menu,-3,0):RETurn:
    9662   : REMark ESC pressed therefore ignore new setting
    9665   Menu_add=m_store
    9667   : REMark Look at where original Menu definition is stored.
    9670   pwidth=PEEK_W(Menu_add+28):pheight=PEEK_W(Menu_add+30)
    9675   : REMark These offsets contain the size of the existing menu
    9675   px=prog_x:py=prog_y
    9685   pwidth=pwidth-(pxpos%-old_x%):IF pwidth MOD 2:pwidth=pwidth+1
    9690   pwidth=MAX(pwidth,450)
    9695   pwidth=MIN(pwidth,scr_width%-12)
    9700   px=MIN(pxpos%-34,(scr_width%-pwidth)-12)
    9705   px=MAX(px,0)
    9710   pheight=MAX(pheight-(pypos%-old_y%),210)
    9715   pheight=MIN(pheight,scr_height%-10)
    9720   py=MIN(pypos%-5,(scr_height%-pheight)-10)
    9725   py=MAX(py,0)
    9726   : REMark the lines 9675-9725 calculate the new width and height
    9727   : REMark of the menu (minimum size 450x210)
    9728   : REMark (maximum size scr_width%-12 x scr_height%-10)
    9755   prog_x=px:prog_y=py
    9760   MCLEAR #Main_menu:CLPT #1
    9762   : REMark Remove the old working menu definition
    9765   OUTL #1,pwidth,pheight,px,py
    9770   : REMark Resize outline & main window dimensions
    9775   POKE_W Menu_add+28,pwidth:POKE_W Menu_add+30,pheight
    9780   POKE_W Menu_add+76,pwidth:POKE_W Menu_add+78,pheight
    9782   : REMark Alter the menu sizes in the menu definition
    9784   :
    9785   : REMark You will now need to re-position various loose items as necessary
    9787   : REMark There is no easy way to find the offsets of the definitions
    9788   : REMark within the original menu definition.
    9790   : REMark You will also need to re-size Information and Application Sub-Windows
    9795   : REMark as necessary.
    9795   :
    9865   MDRAW #1,m_store,px,py:Main_menu=MWDEF(#1)
    9866   : REMark Redraw the main menu, creating a new Working Menu Definition
    9870   : REMark you will now need to redraw any information which is normally shown in the
    9875   : REMark main menu but not contained in the menu when it was designed.
    9885 END DEFine

**Example**

A short program which produces a graphical effect and then provides a
pull-down menu on a secondary window, using OUTLN
to restore the screen after you have used the menu.

::

    100 OUTLN #0,512,256,0,0
    110 PAPER #0,0:CLS#0
    120 REMark Force #0 to Primary Window
    130 WINDOW #0,448,40,32,216
    140 WINDOW 448,200,32,16
    150 PAPER 2:INK 7:CLS
    180 PRINT 'This is a Secondary Window'
    190 REPeat loop
    200   INK RND(3 TO 7)
    210   FOR i=0 TO 360 STEP RND(10 TO 30)
    220     x=RAD(i):LINE 50,50 TO 50-40*SIN(x),50-40*COS(x)
    230   END FOR i
    235   OPEN #3,scr_400x100a56x20
    236   PAPER #3,0:INK #3,7
    240   OUTLN #3,400,100,56,20:CLS#3
    250   PRINT #3,' MENU'
    260   PRINT #3,'Press <ESC> to leave'
    270   PRINT #3,'Press <SPACE> to continue'
    280   REPeat keys
    290     x$=INKEY$(-1):IF x$ INSTR ' '&CHR$(27):EXIT keys
    300   END REPeat keys
    310   OUTLN #3,400,100,56,20
    315   CLOSE #3
    320   IF x$=CHR$(27):EXIT loop
    330 END REPeat loop

Note the need to CLOSE #3 each time that it is removed from the screen.

If #3 was OPENed outside of the loop, OUTLN would only save the contents
of the screen under #3 the first time that line 240 was encountered, and
each subsequent time that it was used, will try to restore the contents
of the screen!

**NOTE 1**

If you use OUTLN to reduce the area of a Primary Window, any Secondary
Windows which would contain an area outside of the new Primary Window
will be re-sized so that they have exactly the same size and position as
the new Primary Window. Any saved contents will be lost. This is also
true of any windows which are OPENed after an OUTLN command - if they
would fall outside of the area defined by OUTLN, then the newly OPENed
window will occupy the same area as the OUTLN. Compare WINDOW which will
cause an error.

**NOTE 2**

Before v2.58 of SMSQ/E, OUTLN without any parameters did not work if an
OUTLN was already set.

**CROSS-REFERENCE**

See :ref:`qflim`. :ref:`outl` is
similar. :ref:`wmon` and :ref:`wtv`
also add an outline to a program.

--------------


