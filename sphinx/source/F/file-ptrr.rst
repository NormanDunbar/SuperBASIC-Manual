..  _file-ptrr:

FILE\_PTRR
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  FILE\_PTRR #channel, bytes                                       |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command moves the file pointer from its current position by the
given number of bytes forward, negative numbers allow backward movement.

The file pointer cannot go beyond the limits of the file itself, so if
you try to do so, the pointer will be set to the start or end of the
file.

**Example**

A program to store several names and telephone numbers in a file and
then to search for the given name and return the relevant telephone
number::

    100 DIM a$(3,30),number(3)
    110 RESTORE
    120 FOR i=1 TO 3: READ a$(i),number(i)
    130 OPEN_NEW #3,flp2_phone_dbs
    140 FOR stores=1 TO 3
    150   PUT#3,a$(stores),number(stores)
    160 END FOR stores
    170 CLOSE#3
    180 :
    200 INPUT name$
    210 OPEN_IN#3,flp2_phone_dbs
    220 REPeat find_NAME
    230   IF EOF(#3) THEN PRINT 'NAME not found...': STOP
    240   GET#3,entry$
    250   IF entry$==name$ THEN
    260     GET#3,telno
    270     EXIT find_NAME
    280   END IF
    290   FILE_PTRR#3,6: REMark skip next phone number
    300 END REPeat find_NAME
    310 CLOSE#3
    320 PRINT entry$;'....';telno
    330 :
    350 DATA 'P.C. Green','999'
    360 DATA 'CATFLAP inc.','7212.002121'
    370 DATA 'Tim','98081'

Note that on Minerva, Integer Tokenisation will need to be disabled.

**CROSS-REFERENCE**

:ref:`file-ptra`,
:ref:`file-pos`, :ref:`fpos`,
:ref:`flen`, :ref:`file-len`,
:ref:`get`.

