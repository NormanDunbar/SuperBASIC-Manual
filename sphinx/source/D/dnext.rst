..  _dnext:

DNEXT
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DNEXT subdirectory                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command allows you to move across a directory tree by replacing
the current sub-directory with the specified subdirectory in the default
data device.

If the default program device is the same as the default
data device, then this will also be altered by DNEXT.

If the default
destination device is a directory device (ie. if it ends with an
underscore), DNEXT also alters the last sub-directory in this (whether
or not it points to another drive, or is further down the directory
tree).

::

    win1_
    win1_C_
    win1_C_include_
    win1_C_objects_
    win1_BASIC_
    win1_QUILL_
    win1_QUILL_letters_
    win1_QUILL_translations
    win1_secret_

The above could be a directory tree on a hard disk. DATA\_USE
win1\_C\_ defines win1\_C\_ as the default directory device, so WDIR
will list all of the files in win1\_C\_.

Assuming that
PROGD$='win1\_BASIC\_' and DESTD$='flp2\_C\_Include\_', entering DNEXT
Quill will result in the following:

- DATAD$='win1\_Quill\_'
- PROGD$='win1\_BASIC\_'
- DESTD$='flp2\_C\_Quill\_'


**NOTE 1**

DNEXT does not check if there are any files with the given prefix which
exist.


**NOTE 2**

DNEXT breaks with error -17 (error in expression) if the parameter is a
resident keyword. So append an underscore to the directory name, eg.
DNEXT NEW\_, or specify the parameter between quote marks (eg. DNEXT
'NEW').


**NOTE 3**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to extend them beyond this will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

:ref:`dup` moves up the tree,
:ref:`ddown` moves down the tree.
:ref:`datad-dlr` and :ref:`dlist`
can be used to find out about the current sub-directory and default
devices respectively.

