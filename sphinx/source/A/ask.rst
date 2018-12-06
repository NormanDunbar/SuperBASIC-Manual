..  _ask:

ASK
===

+----------+-------------------------------------------------------------------+
| Syntax   |  ASK ([#wind,] question$)                                         |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

ASK is a function which prints the question$ (plus a question mark (?)
if this was not found at the end of the string), enables the text cursor
and reads the keyboard. If the next key pressed is <Y> (for Yes), <J>
(for Ja) or <N> (for No or Nein) then ASK will disable the cursor, echo
the key next to the prompt and return 1 if either <Y> or <J> was
pressed, or 0 if <N> was pressed. If any other key is pressed, ASK will
BEEP and try again.

**Example**

In early computer days, this was a classical game which needed a hundred
lines on a (modern at the time) programmable pocket calculator:

::

    100 CLS: x1 = 0: x2 = 100
    110 PRINT "I am going to find out a number"
    120 PRINT "from"!x1!"to"!x2!"which only you know."\\
    130 REPeat find_out
    140   PRINT x1;"..";x2
    150   x = (x2+x1) DIV 2
    160   ok = ASK("Is it "&x)
    170   IF ok THEN EXIT find_out
    180   IF x1 = x2 THEN PRINT "You are cheating.": STOP
    190   large = ASK(x&" too large")
    200   IF large THEN x2 = x-1: ELSE x1 = x+1
    210 END REPeat find_out
    220 PRINT "Yippee, I found it."

**NOTE**

ASK is set up for 'yes' and 'no' in English and 'ja' and 'nein' in
German. For other languages where 'yes' is not usually connected with
<Y>, eg. 'oui' in French or 'si' in Spanish, you will need to write your
own routine.

**CROSS-REFERENCE**

:ref:`cur`, :ref:`reply`.

