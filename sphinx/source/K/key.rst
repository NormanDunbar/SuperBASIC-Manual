..  _key:

KEY
===

+----------+------------------------------------------------------------------+
| Syntax   | KEY keynr, string$  or                                           |
|          |                                                                  |
|          | KEY keynr (KEYMAN only) or                                       |
|          |                                                                  |
|          | KEY (KEYMAN only)                                                |
+----------+------------------------------------------------------------------+
| Location | FKEY, KEYMAN                                                     |
+----------+------------------------------------------------------------------+

The KEY command allows you to install keyboard short-cuts: that means
if a certain key (specified with keynr) is pressed the specified string$
will be typed into the current keyboard queue. The actual implementation
of the command under the two Toolkits is different, in that the FKEY
variant only allows keynr to be in the range 1..5 representing the five
function keys (F1 to F5) (see table below).

The KEYMAN version allows
keynr to be in the range 1...60 which represents the following key
presses:

+----------------------+----------------------+
| Key Result           | Key Result           |
+======================+======================+
| 1 <F1>               | 31 <CTRL><K>         |
+----------------------+----------------------+
| 2 <F2>               | 32 <CTRL><L>         |
+----------------------+----------------------+
| 3 <F3>               | 33 <CTRL><M>         |
+----------------------+----------------------+
| 4<F4>                | 34 <CTRL><N>         |
+----------------------+----------------------+
| 5<F5>                | 35 <CTRL><O>         |
+----------------------+----------------------+
| 6<SHIFT><F1>,  <F6>  | 36 <CTRL><P>         |
+----------------------+----------------------+
| 7<SHIFT><F2>,  <F7>  | 37 <CTRL><Q>         |
+----------------------+----------------------+
| 8<SHIFT><F3>,  <F8>  | 38 <CTRL><R>         |
+----------------------+----------------------+
| 9<SHIFT><F4>,  <F9>  | 39 <CTRL><S>         |
+----------------------+----------------------+
| 10<SHIFT><F5>, <F10> | 40 <CTRL><T>         |
+----------------------+----------------------+
| 11<CTRL><F1>,  <F11>\| 41 <CTRL><U>         |
+----------------------+----------------------+
| 12<CTRL><F2>,  <F12>\| 42 <CTRL><V>         |
+----------------------+----------------------+
| 13<CTRL><F3>         | 43 <CTRL><W>         |
+----------------------+----------------------+
| 14<CTRL><F4>         | 44 <CTRL><X>         |
+----------------------+----------------------+
| 15<CTRL><SHIFT><ESC> | 45 <CTRL><Y>         |
+----------------------+----------------------+
| 16<CTRL><SHIFT><F1>  | 46 <CTRL><Z>         |
+----------------------+----------------------+
| 17<CTRL><SHIFT><F2>  | 47 <CTRL><SHIFT><1>  |
+----------------------+----------------------+
| 18<CTRL><SHIFT><F3>  | 48 <CTRL><SHIFT><K>  |
+----------------------+----------------------+
| 19<CTRL><SHIFT><F4>  | 49 <CTRL><SHIFT><L>  |
+----------------------+----------------------+
| 20<CTRL><SHIFT><F5>  | 50 <CTRL><SHIFT><M>  |
+----------------------+----------------------+
| 21<CTRL><A>          | 51 <CTRL><SHIFT><N>  |
+----------------------+----------------------+
| 22<CTRL><B>          | 52 <CTRL><SHIFT><O>  |
+----------------------+----------------------+
| 23 <CTRL><SHIFT><C>  | 53 <CTRL><SHIFT><P>  |
+----------------------+----------------------+
| 24 <CTRL><D>         | 54 <CTRL><SHIFT><Q>  |
+----------------------+----------------------+
| 25 <CTRL><E>         | 55 <CTRL><SHIFT><R>  |
+----------------------+----------------------+
| 26 <CTRL><F>         | 56 <CTRL><SHIFT><S>  |
+----------------------+----------------------+
| 27 <CTRL><G>         | 57 <CTRL><SHIFT><T>  |
+----------------------+----------------------+
| 28 <CTRL><H>         | 58 <CTRL><SHIFT><W>  |
+----------------------+----------------------+
| 29 <CTRL><SHIFT><I>  | 59 <CTRL><SHIFT><X>  |
+----------------------+----------------------+
| 30 <CTRL><SHIFT><J>  | 60 <CTRL><SHIFT><Y>  |
+----------------------+----------------------+


Once initiated, each time that the
specified keying is pressed, the given string will be typed into the
keyboard queue, (note there is a maximum of 80 characters). The KEYMAN
variant allows the second syntax, KEY keynr, which allows you to check
the current definition of keynr, which is then written to #0.

KEY without any parameters activates the key translation if necessary. KEY
keynr, "" can be used to clear a definition with the KEYMAN variant.

**Example**

::

    KEY 5,"STAT"&CHR$(10)

**NOTE 1**

In applications such as word-processors many of these key- presses are
already used for other purposes and this may cause problems - if you do
use KEY to set a function key and then load a program which uses those
function keys, the program will first of all register that the function
key has been pressed and will then receive a stream of other keypresses
(ie. the defined string).

**NOTE 2**

Key is quite a common variable name and so there is a large danger of
errors occurring if KEY has been loaded into the computer alongside a
program which uses such a variable name - for example, the statement::

    key = KEYROW(1)

will make the program stop with error -17, (Error in expression).

Another problem would exist if key was declared in a program as a BASIC
procedure or function, for example::

    DEFine PROCedure Key

in which case, this would overwrite the machine code definition and
even the command NEW will not restore it, however all stored KEY
definitions are kept active, and they can no longer be altered because
the keyword KEY is no longer recognised by the system.

**NOTE 3**

Neither of these Toolkits should be linked into a Qliberated job,
otherwise it is possible that the code used for KEY will exist twice in
memory, which would crash the machine. Also, the Toolkits should not be
loaded into a MultiBASIC or Multiple SBASIC unless you are certain that
this Interpreter will never disappear.

**CROSS-REFERENCE**

:ref:`nokey` under KEYMAN is equivalent to
:ref:`key` without parameters. See
:ref:`altkey` for a concept similar to this one
here.

--------------


