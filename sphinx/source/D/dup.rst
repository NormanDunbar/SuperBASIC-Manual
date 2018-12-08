..  _dup:

DUP
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DUP                                                              |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

This command strips off the last part of the default data device, thus
moving up the directory tree. If the default program device is the same
as the default data device, then this will also be altered by DUP. If
the default destination device is a directory device (ie. if it ends
with an underscore), DUP also alters this (whether or not it points to
another drive).

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


If DATAD$ is win1\_, DDOWN Quill moves down to
win1\_Quill\_, whilst DUP will move DATAD$ back up to win1\_.

If DATAD$
is win1\_Quill\_letters\_secret\_, three DUPs will change it back to
win1\_.


**NOTE**

It is not possible to move beyond the name specifying the actual device
to be used. In the above example, this is the named root, win1\_.


**CROSS-REFERENCE**

:ref:`data-use` allows you to set the absolute
directory root, :ref:`ddown` goes down the tree, and
:ref:`dnext` skips from branch to branch.
:ref:`datad-dlr` returns the current default data
device ie. the device name plus the current sub-directory.

