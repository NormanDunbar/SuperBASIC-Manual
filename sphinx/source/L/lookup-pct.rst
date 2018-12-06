..  _lookup-pct:

LOOKUP%
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  LOOKUP% (search$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  Function (DIY Toolkit - Vol R)                                   |
+----------+-------------------------------------------------------------------+

This function expects you to pass a string parameter which contains a
name used by the SuperBASIC interpreter. This name can be a machine code
Procedure or Function (such as are described here in this manual), or a
SuperBASIC variable, PROCedure or FuNction. If the specified name is
recognised then LOOKUP% returns the number of its entry in the name
list. If the name is not recognised, then the value -7 is returned.

**Examples**

::

    PRINT LOOKUP% ('PRINT')

will return 0 on most QL ROMs as this is normally the first name in the
name list.

::

    PRINT LOOKUP% ('FSERVE')

can be used to see if Toolkit II's fileserver is available.

**NOTE 1**

This function will only look at the name list for SuperBASIC Job 0, so
although it can be used from within a compiled task to look at Job 0, it
cannot be used to look at a multiple BASIC interpreter!!

**NOTE 2**

This function will only work correctly with machine code Procedures and
Functions on SMS.

**CROSS-REFERENCE**

See\ :ref:`elis`, :ref:`key-add`.
:ref:`-name-dlr` allows you to look at the name list.
See also :ref:`flis` and
:ref:`find`.

