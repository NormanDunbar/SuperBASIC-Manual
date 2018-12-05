..  _edline-dlr:

EDLINE$
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  EDLINE$ (#ch, maxlen%, edit$)                                    |
+----------+-------------------------------------------------------------------+
| Location |  EDLINE (DIY Toolkit Vol E)                                       |
+----------+-------------------------------------------------------------------+

The function EDLINE$ prints edit$ at the current text cursor position in #ch
(there is no default channel) and allows you to edit it. A maximum length of
maxlen% characters is allowed. The edited result is returned. Unlike INPUT,
EDLINE$ will not finish with <UP> or <DOWN> but only after <ENTER> and
<CTRL><SPACE> (also <ESC> on Minerva). Instead <UP> and <DOWN> move the cursor
to the start and end of the string respectively; apart from that the usual
keys for editing are used: <CTRL><LEFT> deletes the character to the left
of the cursor, <CTRL><RIGHT> the character under the cursor.

**Example**

::

    100 CLS
    110 REPeat ask_name
    120 PRINT \"Please enter your name: ";
    130 Name$ = "Billy the Kid"
    140 Name$ = EDLINE$(#1,40,Name$)
    150 PRINT "Your name is '";Name$;"' (y/n)? ";
    160 ok$ = EDLINE$(#1,1,"y")
    170 IF ok$ INSTR "yY" THEN EXIT ask_name
    180 PRINT "Try again..."
    190 END REPeat ask_name
    200 PRINT "Hello,"!Name$;"!"

**NOTE**

You need a special version of EDLINE$ to work correctly on Minerva and
SMS. This version is included with the DIY Toolkit package.

**CROSS-REFERENCE**

:ref:`edline-dlr` can be used to input numbers but
you have to ensure that the entered text can be successfully coerced to
a number, see :ref:`check-pct` and
:ref:`checkf` for that.
:ref:`edit-dlr` is similar. Other routines for human
input are for example: :ref:`input`,
:ref:`inkey-dlr`, :ref:`ask` and
:ref:`reply`.

--------------


