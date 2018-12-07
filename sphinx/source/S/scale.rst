..  _scale:

SCALE
=====

+----------+------------------------------------------------------------------+
| Syntax   | SCALE [#ch,] size,x,y  or                                        |
|          |                                                                  |
|          | SCALE [#ch,] -size,x,y (Minerva v1.76+)                          |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

Many of the QL's graphics commands rely upon the graphics co-ordinate
system to dictate whereabouts in a window they should appear. The
command SCALE allows you to set the graphics scale in a specified window
(default #1).

Size dictates the graphics scale for that window by
representing the length of a line which would be drawn from the bottom
left hand corner of a window to the top left hand corner, hence the
larger the size, the more information which can appear on screen
(although this is somewhat limited by the actual resolution of the
screen!). The default size is 100.

The co-ordinates x,y specify the
co-ordinate which appears in the bottom left hand corner of the screen.
When a window is opened, the scale is reset with the equivalent of `SCALE
#ch,100,0,0`.

Although a line drawn up the side of a window will be size
units long, the length required to draw a line along the whole of the
bottom of the window, not only depends on the value of size, but also on
the screen resolution and the shape of the given window.

::

    size|
    Y   |
        |
        |
        |
        |
        |__________________________________
        (0,0)        size*factor
                          X


**Example**

The following short program will draw a diagonal cross through the
middle of any given size of window, on any given screen resolution::

    100 INPUT 'Screen Resolution Width :'!ScreenX
    110 INPUT 'Screen Resolution Height :'!ScreenY
    120 INPUT 'Window Width : ';wid
    130 INPUT 'Window Height : ';hi
    140 INPUT 'Scale : ';size
    150 WINDOW wid,hi,32,16
    160 PAPER 2:INK 7:CLS
    170 SCALE size,0,0
    180 Xratio=ScreenX/512:Yratio=ScreenY/256
    190 line_diff=(101*Yratio/hi)*wid/('135.5041505'*Xratio)
    200 LINE 0,0 TO size*line_diff,size
    210 LINE 0,size TO size*line_diff,0

**NOTE 1**

Graphics drawn using the QL graphics co-ordinate system will appear in
the same place on screen in any screen MODE.

**NOTE 2**

Due to the QL's arithmetic routines, the maximum length of a line which
can be drawn upwards in a window is slightly larger than size.

**NOTE 3**

On JSU ROMs, the screen ratio is different to other ROMs, presumably due
to the different number of lines on American TVs - you would need to
change line 190 in the above example to read::

    90 line_diff=(101*Yratio/hi)*wid/('159.593001'*Xratio)


**MINERVA NOTES**

Minerva ROMs (v1.76 or later) allow you to use a negative SCALE, so that
you may easily draw a picture upside down without altering all of the
different drawing commands. This is achieved by using the second syntax
of the SCALE command. Before trying to use this new variant of the
command, you will have to give your drawing some careful thought.

For
instance, when designing a screen, it is best to draw this using the
normal SCALE command, and then to use Minerva's new syntax at that
stage. For example, take the following short demonstration drawing::

    100 MODE 8
    110 WINDOW 448,200,32,16
    120 SCALE 100,0,0:PAPER 0:CLS
    130 INK 2:FILL 1
    140 LINE 0,0 TO 0,10
    150 LINE 0,10 TO 40,30 TO 60,27
    160 LINE 60,27 TO 40,24 TO 10,0 TO 0,0
    170 FILL 1
    180 LINE 166,0 TO 166,10
    190 LINE 166,10 TO 126,30 TO 106,27
    200 LINE 106,27 TO 126,24 TO 156,0 TO 166,0
    210 INK 4,3
    220 FILL 1:CIRCLE 83,50,32:FILL 0

Now, to turn it upside down on Minerva, try changing line 120 to read::

    120 SCALE -100,0,0:PAPER 0:CLS

If you now try running the program, you will find that your picture no
longer appears!

This is because instead of Minerva moving the graphics
origin to the top right hand corner of the window (as you might have
expected), Minerva has in effect turned the graphics output around by
180 degrees about the graphics origin (ie. the bottom left hand corner
of the window).

This means that to get your picture to re-appear on
screen, you will need to redefine the graphics origin so that it has the
same values as you would expect to be in the top right hand corner of
the screen before it was turned around. Thus, the following diagram will
explain the current layout of the screen::

    -size|
     Y   |
         |
         |
         |
         |
         |_____________________________
         (0,0)    -size*factor
                       -X


In other words, in the above example, you will need to alter line
120 to read::

    120 SCALE -100,166,100:PAPER 0:CLS

The program will now display the picture upside down, having now
altered the orientation of the display to the following diagram::

         X
         ______________________________________(0,0)
    size|                                      |
        |                                      |
        |                                      |
        |                                      |
        |                                      |
        |                                      | Y
        |______________________________________|
        (166,100)           size*factor

**CROSS-REFERENCE**

:ref:`circle`, :ref:`arc`,
:ref:`line` and :ref:`point` all
rely on the current :ref:`scale`.

