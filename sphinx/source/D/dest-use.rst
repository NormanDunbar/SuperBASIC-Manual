..  _dest-use:

DEST\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEST\_USE name                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command sets the current default destination device to the named
directory device. An underscore will be added to the end of the name if
one is not supplied. If you supply name as an empty string, this will
turn off the default destination directory.


**Example**

::

    DEST_USE win1_Quill


**NOTE 1**

DEST\_USE will overwrite the default set with SPL\_USE.


**NOTE 2**

The default devices cannot exceed 32 characters (plus a final
underscore) - any attempt to assign a longer string will result in the
error 'Bad Parameter' (error -15).


**CROSS-REFERENCE**

Please see :ref:`destd-dlr` and
:ref:`spl-use`.

