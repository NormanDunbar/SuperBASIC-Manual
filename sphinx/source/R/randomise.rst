..  _randomise:

RANDOMISE
=========

+----------+------------------------------------------------------------------+
| Syntax   | RANDOMISE [(start)] or                                           |
|          |                                                                  |
|          | RANDOMISE \\ (Minerva v1.82+ only)                               |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

SuperBASIC uses a standard method to generate pseudo random numbers.

Each time that the function RND is called, a start value specified by
the command RANDOMISE is multiplied by a large number and another number
is added, the solution is modulated and the final number is nearly
unpredictable.

This method means that after a RANDOMISE command with
parameter, RND will always generate the same numbers. If you pick
another number as the parameter (or do not specify a parameter at all),
this will let RND produce other numbers. If no parameter is specified,
RANDOMISE calculates a random number by combining some internal system
data such as the time, date, pointers etc.

**Example**

::

    100 RANDOMISE 38
    110 FOR n=1 TO 10: PRINT RND(10)

The program will always write the same ten random numbers on the
screen.

**MINERVA NOTE**

The main problem with using RANDOMISE is that even without a parameter,
the same pattern of 'random' numbers is generated if the interval
between when the computer is switched on and when the line containing
RANDOMISE is reached tends to be the same every time that a program is
run. Although v2.53+ of SMS makes RANDOMISE without a parameter more
random, the only other fix is on v1.82+ of Minerva which allows you to
use::

    RANDOMISE \

instead of the normal RANDOMISE which should alleviate this problem
somewhat.

**CROSS-REFERENCE**

:ref:`rnd` is the function that returns a random
number. :ref:`randomise` influences
:ref:`matrnd` in the same way.

