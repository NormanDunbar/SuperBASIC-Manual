..  _poke-f:

POKE\_F
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  POKE\_F address,float                                            |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

Floating point numbers are internally stored as six bytes. POKE\_F will
store any float at address in memory where ODD(address)=0.

**Example**

Floating point numbers can be stored in internal format in a file with
PUT. The disadvantage of that method is low disk access speed if you
need to store a large number of values.

Compare the following two
programs which store the same amount of data at different speeds.

Slow but minimal memory usage::

    100 n=1000: file$="flp1_test_dat"
    120 fp=FOP_NEW(file$)
    130 FOR i=1 TO n: PUT#fp,RND
    140 CLOSE#fp

Fast but 6K buffer required::

    100 n=1000: file$="flp1_test_dat"
    120 a=ALCHP(6*(n+1))
    130 FOR i=0 TO n: POKE_F a+i*6,RND
    140 SBYTES file$,a,6*(n+1)
    150 RECHP a

**CROSS-REFERENCE**

:ref:`poke`, :ref:`poke-w` and
:ref:`poke-l` store different ranges of integer
numbers. :ref:`mkf-dlr` returns the internal
representation of a floating point number as a string.
:ref:`get` and :ref:`put` write all
kinds of data types in their internal format to a channel,
:ref:`fputf` and :ref:`fgetf`
are specialised variants for floats only. See also
:ref:`peek-f`!

--------------


