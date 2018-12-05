..  _ddown:

DDOWN
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  DDOWN subdirectory                                               |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command adds the specified subdirectory to the default data device
as a suffix.

If the default program device is the same as the default
data device, then this will also be altered by DDOWN.

If the default
destination device is a directory device (ie. if it ends with an
underscore), DDOWN also alters this (whether or not it points to another
drive).

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


The above could be a directory tree on a hard disk.

DATA\_USE win1\_ defines win1\_ as the default directory device, so WDIR will list
all of the files on win1\_.

DDOWN C will move into the C sub-directory, ie. DATAD$ is now win1\_C\_.

DDOWN include will make WDIR list all of
the files on the hard disk which are prefixed by C\_include\_ (eg.
win1\_C\_include\_math\_h).


**NOTE 1**

DDOWN does not check if there are any files with the given prefix which
exist.


**NOTE 2**

DDOWN breaks with error -17 (error in expression) if the parameter is a
resident keyword. So append an underscore to the directory name, eg.
DDOWN NEW\_, or specify the parameter between quote marks (eg. DDOWN
'NEW').


**NOTE 3**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to extend them beyond this will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

:ref:`dup` moves up the tree,
:ref:`dnext` skips from branch to branch.
:ref:`datad-dlr` and :ref:`dlist`
can be used to find out about the current sub-directory and default
devices respectively.

--------------


