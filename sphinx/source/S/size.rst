..  _size:

SIZE
====

+----------+------------------------------------------------------------------+
| Syntax   | SIZE ( array [{% \| $}] )  or                                    |
|          |                                                                  |
|          | SIZE ( variable [{% \| $}] )  or                                 |
|          |                                                                  |
|          | SIZE ( value)                                                    |
+----------+------------------------------------------------------------------+
| Location | Math Package                                                     |
+----------+------------------------------------------------------------------+

The function SIZE can take any kind of variable, array or constant. The
returned value depends very much on the type of parameter: If a simple
variable was passed, the function returns either 0 or 1, 1 if the
variable points to any value or 0 if it does not, ie. if PRINT variable
would show an asterisk to show that variable is not yet defined. Note
that even though on SMS an unset variable does not show an asterisk when
you use PRINT  variable, this does not prevent this function from returning the
correct value.

The return for a constant parameter such as::

    PRINT SIZE(-22.3)

or::

    PRINT SIZE("QL")

is always 1.

The return for arrays is entirely different. Passing an array tells SIZE to count its elements. Note the existence of a zero element, for example::

    DIM a(2,2)

gives a nine elements in all::

    a(0,0) a(0,1) a(0,2)
    a(1,0) a(1,1) a(1,2)
    a(2,0) a(2,1) a(2,2)

SIZE handles string arrays differently in that it returns the number of
strings, not the number of characters, eg. for DIM a$(2,2), SIZE(a$)
will not give 3\*3 = 9 but 3.

Generally the return value of SIZE does not
depend on the actual contents of the passed object. SIZE recognises if
part of an object (especially strings and arrays) was passed.

**Examples**

::

    DIM numbers(1,2,3,4,5)
    PRINT SIZE(numbers)

returns 2*3*4*5*6=720.

::

    yippie$="what a wonderful world"
    PRINT SIZE(yippie$)

returns 1.

::

    CLEAR PRINT SIZE(eeek)

returns 0

::

    DIM string$(12,7,10)
    PRINT SIZE(string$)

returns 13*8=104

::

    PRINT SIZE(string$(1 TO))

returns 12*8=96.

**NOTE 1**

String arrays also contain numeric values - the first element (which is
character zero) of a string contains the size of the string. For
instance, take the above string$ array and then enter::

    string$(4,4) = "knocking"

Now::

    PRINT string$(4,4)

and you will see 'knocking' in #1.

::

    PRINT string$(4,4,5)

gives the fifth character of knocking, the k, and::

    PRINT string$(4,4,1)

the first one, again a k. And::

    PRINT string$(4,4,0)

There is no character before the first, instead you will get the integer
number 8 because::

    LEN(string$(4,4))=8

This is tricky and not really necessary to know about as you can use LEN... just in case you come across the phenomenon and have wondered about it. See also DIM for a
further explanation of strings.

**NOTE 2**

Before v2.06, this function may refuse to work on some implementations,
giving 'Bad Parameter' error or returning the wrong value for string
arrays.

**NOTE 3**

If the parameter is a single dimension string array, for example::

    DIM a$(10)
    PRINT SIZE (a$)

the value returned is 0. It is hoped that this will be fixed in a
future version so that the value returned is 1.

**CROSS-REFERENCE**

:ref:`dimn` and :ref:`ndim` return
other information about an array, eg: :ref:`print`
SIZE(a$) \* DIMN(a$,NDIM(a$)) gives the total number of characters which can be stored in a string
array a$. :ref:`len` returns the length of a string.
:ref:`free-mem` allows you to check how much
memory an array uses.

--------------


