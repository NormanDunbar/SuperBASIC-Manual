..  _get:

GET
===

+----------+-----------------------------------------------------------------------------------------------+
| Syntax   | GET [#channel\\file\_position,] [var\ :sup:`1` :sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*` ...] or |
|          |                                                                                               |
|          | GET [#channel,] [var\ :sup:`1` :sup:`\*`\ [,var\ :sup:`i`]\ :sup:`\*` ...]                    |
+----------+-----------------------------------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                                                          |
+----------+-----------------------------------------------------------------------------------------------+


This command, together with PUT, helps to provide the QL with a means
of using a file as a store for variables. The QL stores variables in one
of four ways: short%(range -128 to 127) is stored as 2 bytes. Short
integers are only available on Minerva ROMs, when integer tokenisation
is enabled. integer%(range -32768 to 32767) is stored as 4 bytes.
float(eg. 1.23 or any numbers outside the integer%
range) is stored as 6 bytes. string$(eg. 'Hello') is stored as 2 bytes
containing the length of the string followed by the string itself.

GET enables variables which have been stored in this manner to be retrieved
from a file opened to the given channel (default #3). The variable
stored at the current position in the file (or the file position given
with the command, if the first variant is used) is read directly into
the variable name given with the command.

If you provide more than one
variable name as the second, third parameter etc, then more variables
will be read from the file in one go.

If the first variant is used, the
file position is always calculated as an absolute distance from the
start of the file. However, to help you, if you supply a variable for
the file\_position (eg. GET \\pointer), this variable will always be
updated to the current file pointer at the end of the command.

Compare
GET \\pointer+3 which supplies an expression for the file\_pointer and
cannot therefore be updated automatically by the command.

If no variable
is specified, the file pointer will be set to the specified position if
the first variant is used.

If the second variant is used, this will have
no effect.

**Example**

A program to store three names on a file and then to retrieve them (this
would be useful in a database for instance)::

    100 RESTORE
    110 DIM a$(3,20)
    120 FOR i=1 TO 3: READ a$(i)
    130 OPEN_NEW #3,ram1_storage
    140 PUT #3,a$(1),a$(2),a$(3)
    150 CLOSE #3 160 :
    170 REPeat opt_loop
    180   CLS: INPUT 'Which Number Name do you want?',no$
    190   IF no$='':NEXT opt_loop
    200   IF no$(1) INSTR '123': opt=no$(1): EXIT opt_loop
    210 END REPeat opt_loop
    220 OPEN_IN#3, ram1_storage
    230 FOR i=1 TO opt:GET#3,retrieve$
    240 PRINT retrieve$
    250 CLOSE #3
    260 DATA 'Fred Bloggs','Filthy Rich','Peter Rabbit'

**NOTE 1**

The example works fine if only a few fields have to be stored.
Generally, it is better to move around a file using file pointers in a
file based database.

**NOTE 2**

Current versions of the Turbo and Supercharge compilers are not able to
compile programs which use GET.

**NOTE 3**

Except under SMS v2.81+, this command can crash the system if you try to
GET a string variable which has been dimensioned {or even set with LOCal
a$(512) for example}. This can be avoided by using::

    a$=FILL$(' ',512)

to initialise the string instead.

**NOTE 4**

Although it is possible to use this command with non-file related
channels, this is inadvisable, as each entry would need to be typed in
from the keyboard in its internal form, which can be rather difficult.
If you do use the command on a non-file related channel by accident,
press the Break key to escape.

**CROSS-REFERENCE**

See :ref:`put`, :ref:`bput`,
:ref:`bget`, :ref:`lget`,
:ref:`wget`.

--------------


