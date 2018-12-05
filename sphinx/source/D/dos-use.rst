..  _dos-use:

DOS\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   | DOS\_USE device$                                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

DOS\_USE may be used to set the name of the DOS device. The name should be three characters long, in upper or lower case.

**Example**

::

    DOS_USE mdv

The DOS device is renamed MDV.

::

    DOS_USE DOS

The DOS device is restored to DOS.

::

    DOS_USE

The DOS device is restored to DOS.


--------------



