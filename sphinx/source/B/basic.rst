..  _basic:

BASIC
=====

+----------+-------------------------------------------------------------------+
| Syntax   | BASIC [(offset)]                                                  |
+----------+-------------------------------------------------------------------+
| Location | BTool                                                             |
+----------+-------------------------------------------------------------------+

The function BASIC is identical to BASICP except that if no parameter is
supplied, the function BASIC will return the base address of the
SuperBASIC program area.


**NOTE**

Although this function is written in such a way that it can be used from
within compiled programs to access SuperBASIC variables, it cannot
access MultiBASIC variables on Minerva nor SBASIC variables on SMS and
will always return a value representing the location of the equivalent
SuperBASIC variable.


**WARNING**

You should use commands such as the extended PEEK or POKE provided by
Minerva and SMS to read or set the tables pointed to by the values
returned by this function, as the SuperBASIC tables can move when tasks
are started up or removed from memory.


**CROSS-REFERENCE**

See :ref:`basicp` and
:ref:`basic-w`.

