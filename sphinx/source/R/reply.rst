..  _reply:

REPLY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  REPLY [([#wind,] keys$)]                                         |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function REPLY reads a character from the keyboard (with the text
cursor in a window enabled).

If keys$ was specified, then REPLY will
only stop if the pressed key was listed in keys$, this is case-sensitive
so <a> and <SHIFT><A> are different.

The return of REPLY is the position of
the pressed key in keys$. REPLY behaves very differently if there is no
keys$ supplied. The return will be the code of the pressed key, just
like CODE(INKEY$(-1)) except that combinations of <ALT> and any other
key are recognised - if <ALT> was held and any other key pressed, REPLY
returns 256 minus the code of that key.

**Example**

Another version of the game also shown at ASK::

    100 CLS: x1 = 0: x2 = 100
    110 PRINT "I am going to find out a number"
    120 PRINT "from"!x1!"to"!x2!"which only you know."
    130 PRINT "Press <S> if the proposed number is too small,"
    140 PRINT "<L> if it's too large or <Y> if it's the result."
    150 REPeat find_out
    160   x=(x1+x2) DIV 2
    170   PRINT x;"? ";
    180   answer = REPLY("sSlLyY")
    190   SELect ON answer
    200     =1,2: x1 = x + 1: PRINT "too small"
    210     =3,4: x2 = x - 1: PRINT "too large"
    220     =5,6: EXIT find_out
    230   END SELect
    240 END REPeat find_out
    250 PRINT "ok"\"I am the best."

**CROSS-REFERENCE**


:ref:`ask`, :ref:`inkey-dlr`
See :ref:`code` also.

--------------


