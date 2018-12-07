..  _ttefp:

TTEFP
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEFP (floatvar, floatstr$)                                      |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

This function tries to convert the string given as the second parameter
into a floating point number and assign this value to the floating point
variable given as the first argument. There is no difference to the
assignment::

    floatvar = floatstr$

except where an error occurs, ie. if floatstr$ cannot be converted to a
float. Whereas the assignment above will break with an error, TTEFP will
allow you to track that down by checking its return; the number returned
by TTEFP is the QDOS error code (or 0 if the assignment was successful).

**Example**

A piece of code which asks for the age of the user would look similar to
this::

    100 CLS
    110 REPeat question
    120   INPUT "How old are you?"!age$
    130   ec = TTEFP(age, age$)
    140   SELect ON ec
    150     = 0: IF age < 13 OR age > 100 THEN
    160            PRINT "You're surely kidding!!"
    170          ELSE EXIT question
    180          END IF
    190     = -17: PRINT "Digits, not letters, ok?"
    200     = -18: PRINT "Reasonable numbers, please."
    210     = REMAINDER : PRINT "What's this about?"
    220   END SELect
    230 END REPeat question
    240 PRINT "So you are"!age!"years old... :-)"

**CROSS-REFERENCE**

:ref:`check-pct`, :ref:`checkf`.

