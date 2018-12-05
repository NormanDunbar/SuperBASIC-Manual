..  _display-width:

DISPLAY\_WIDTH
==============

+----------+-------------------------------------------------------------------+
| Syntax   | bytes_in_a_line = DISPLAY\_WIDTH                                  |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function can be used to determine how many bytes of the QL's memory are used to hold the data in one line of pixels on the screen. Note that the value returned has nothing to do with any *window* width, it always refers to the total *screen* display width.

Why include this function I hear you think? If you run an ordinary QL, then the result will probably always be 128 as this is how many bytes are used to hold a line of pixels, however, many people use Atari ST/QLs, QXL etc and these have a number of other screen modes for which 128 bytes is not enough.

This function will return the exact number of bytes required to step from one line of pixels to the next. Never assume that QDOS programs will only ever be run on a QL. What will happen when new Graphics hardware or emulators arrive? This function will still work, assuming that the unit uses standard QDOS channel definition blocks etc.

For the technically minded, the word at offset $64 in the SCR\_ or CON\_ channel's definition block is returned. This is called SD\_LINEL in 'Tebby Speak' and is mentioned in Jochen Merz's *QDOS Reference Manual* and the *QL Technical Manual* by Tony Tebby et al. Andrew Pennel's book, the *QDOS Companion* gets it wrong on page 61, guess which one I used first!


-------


