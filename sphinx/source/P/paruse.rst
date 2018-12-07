..  _paruse:

PARUSE
======

+----------+-------------------------------------------------------------------+
| Syntax   |  PARUSE (name)                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

PARUSE is a companion function to PARTYP. PARUSE also expects only one
parameter - the name of the parameter from the definition line to be
looked at. PARUSE will then return one of the following values depending
on the actual parameter passed:

+--------+-----------------------------------------+
| PARUSE | Meaning                                 |
+========+=========================================+
| 0      | An unset variable has been passed.      |
+--------+-----------------------------------------+
| 2      | A variable (or value) has been passed.  |
+--------+-----------------------------------------+
| 3      | An array has been passed.               |
+--------+-----------------------------------------+

**NOTE 1**

The Toolkit II Manual gives incorrect values.

**NOTE 2**

There is a difference in the way that PARUSE will report an omitted
parameter, depending on whether you implicitly omit the parameter or
explicitly omit it - see Note 1 relating to PARTYP. Under current
versions of Qliberator a program, PARUSE will always return 2 whether
the parameter is implicitly or explicitly omitted.

**NOTE 3**

TURBO and SuperCHARGE cannot compile programs which use PARUSE.

**CROSS-REFERENCE**

Please see :ref:`partyp`.

