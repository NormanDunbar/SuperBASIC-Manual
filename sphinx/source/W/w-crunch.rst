..  _w-crunch:

W\_CRUNCH
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  W\_CRUNCH ( #channel, colour )                                   |
+----------+-------------------------------------------------------------------+
| Location |  Windows (DIY Toolkit - Vol W)                                    |
+----------+-------------------------------------------------------------------+

This toolkit is designed (like the SuperWindow Toolkit) to provide you
with facilities for storing parts of the QL's screen in memory so that
you can recall them at a later date, thus providing the QL with
non-destructible windows inside programs.

Whilst the Pointer Environment
provides programs with non- destructible windows, this only ensures that
when a program ends, the area of the screen which was occupied by that
program is restored so that it looks the same as when the program
started. Also, when you switch to another program, the whole of that
program's display area appears on screen, overwriting anything else (see
OUTLN) - the display covered by the newly activated program is then
stored in memory to be recalled at a later date. However, unless you use
specific functions (for example those supplied as part of the Qptr
Toolkit, or supplied with this toolkit), if a program OPENs one window
over the top of another window owned by that program, when that second
window is CLOSEd, the area underneath is not restored (see the example
below).

This function allows you to store the area under a specified
window channel in memory in a compressed form. Ideally the window should
be a number of pixels wide which is divisible by eight and also have its
left boundary (after taking any BORDER into account) on a pixel which is
divisible by eight (if not then this function will store a slightly
larger area of the screen than that covered by the window). This
function compresses the screen by reference to the colour parameter -
this should either be 4 to store the green pixels or 2 to store the red
pixels.

The function is therefore only really of use in MODE 4 since
other MODEs may use a lot more colours. Other pixels are ignored and
will therefore not be copied back onto the screen with W\_SHOW. Since
most screens have text in one colour on top of another background, this
function is ideal for those circumstances. This function is also very
useful for storing Icons and other symbols, since the image, once stored
with this function, can be copied back to the screen with W\_SHOW again
and again. The value returned by W\_CRUNCH is the address of the area in
memory where the copy of the screen is stored - you will need to keep
this address for use by the other functions in the toolkit.

**Example**

Try the short program which follows and note how when
you press <ENTER> to close the temporary window, the display does not
alter::

    100 OPEN #2,con_448x200a32x16: PAPER #2,0: CLS #2: INK #2,2
    110 FOR i=1 TO 15
    120   PRINT #2, 'This is window #2 - Line number '; i
    130 END FOR i
    140 INK #2,4: PRINT #2,'PRESS A KEY TO OPEN TEMPORARY WINDOW'
    150 PAUSE
    160 OPEN #3,con_230x40a80x100: PAPER #3,2: CLS #3
    170 INK #3,7: PRINT #3, 'This is a temporary window'
    180 INPUT #3, 'Press <ENTER> to close this window ';a$
    190 CLOSE #3

Instead, you can use W\_CRUNCH to store #2 and then restore it once #3
has been closed - add the following lines::

    155 base=W_CRUNCH(#2,2)
    200 CLS #2
    210 W_SHOW #2,base

Note how only the characters which were printed in Red Ink were stored.
You could have just stored the area under the temporary
window by taking the original example and adding the lines::

    160 OPEN #3,con_230x40a80x100: PAPER #3,2
    165 base = W_CRUNCH(#3,2): CLS #3
    185 PAPER #3,0: CLS #3
    187 W_SHOW #3,base

Note the need to store the contents of the window with W\_CRUNCH before
it is cleared with CLS !!.

**NOTE 1**

This function will only work on screen resolutions of 512x256 pixels.

**NOTE 2**

The memory used by the function will be reclaimed by CLCHP, or LOAD,
LRUN or NEW. You can also use DISCARD address or RECHP address+4
to remove it specifically (although note the different address
requirement for RECHP).

**CROSS-REFERENCE**

See :ref:`scr-refresh` and
:ref:`scr-store`. See also
:ref:`w-store`,
:ref:`w-show`.
:ref:`w-swap`,
:ref:`set-red` and
:ref:`set-green` allow you to recolour windows.

--------------


