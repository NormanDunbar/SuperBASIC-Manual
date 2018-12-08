..  _type:

TYPE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  TYPE (name$)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

The function TYPE returns the internal identification number of any
variable, device name, keyword, command, function etc. as a decimal
number. Each type corresponds to a certain number:

+------+------+-------------------------------+-------------------------+
| Hex  | Dec  | Type                          | Example                 |
+======+======+===============================+=========================+
| 0001 | 1    | undefined string              | Name$                   |
+------+------+-------------------------------+-------------------------+
| 0002 | 2    | undefined floating point      | Size                    |
+------+------+-------------------------------+-------------------------+
| 0003 | 3    | undefined integer             | Age%                    |
+------+------+-------------------------------+-------------------------+
| 0201 | 513  | string variable               | Name$="Smith"           |
+------+------+-------------------------------+-------------------------+
| 0202 | 514  | floating point number         | Size=1.85               |
+------+------+-------------------------------+-------------------------+
| 0203 | 515  | integer number                | Age%=38                 |
+------+------+-------------------------------+-------------------------+
| 0301 | 769  | string array                  | DIM a$(10,20)           |
+------+------+-------------------------------+-------------------------+
| 0302 | 770  | floating point array          | DIM a(221)              |
+------+------+-------------------------------+-------------------------+
| 0303 | 771  | integer array                 | DIM a%(10000)           |
+------+------+-------------------------------+-------------------------+
| 0400 | 1024 | BASIC PROCedure               | DEFine PROCedure QUIT   |
+------+------+-------------------------------+-------------------------+
| 0501 | 1281 | BASIC string FuNction         | DEFine FuNction Who$    |
+------+------+-------------------------------+-------------------------+
| 0502 | 1282 | BASIC floating point FuNction | DEFine FuNction Tm(day) |
+------+------+-------------------------------+-------------------------+
| 0503 | 1283 | BASIC integer FuNction        | DEFine FuNction Age%    |
+------+------+-------------------------------+-------------------------+
| 0602 | 1538 | REPeat loop name              | REPeat forever          |
+------+------+-------------------------------+-------------------------+
| 0702 | 1794 | FOR loop name                 | FOR i=1 TO n            |
+------+------+-------------------------------+-------------------------+
| 0800 | 2048 | machine code procedure        | RUN, ED, NEW            |
+------+------+-------------------------------+-------------------------+
| 0900 | 2304 | machine code function         | QDOS$, VER$, FILL$      |
+------+------+-------------------------------+-------------------------+

**NOTE 1**

Parameters must be given in quotes if you want to find out the type of
the actual name, eg::

    PRINT TYPE ('RUN')

If quote marks are not used,
then the value of the parameter is passed instead - eg::

    name$="RUN"
    PRINT TYPE(name$)

will not return the type of name$ but the type of RUN.

**NOTE 2**

TYPE can also take any kind of expression, whether or not they are
valid.

**CROSS-REFERENCE**

:ref:`key-add` and :ref:`elis`
return the address where a machine code keyword is stored.
:ref:`defined` checks if a variable is set.

