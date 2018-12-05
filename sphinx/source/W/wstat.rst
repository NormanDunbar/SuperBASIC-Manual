..  _wstat:

WSTAT
=====

+----------+------------------------------------------------------------------+
| Syntax   | WSTAT [#ch,] [wild] or                                           |
+----------+------------------------------------------------------------------+
| Syntax   | WSTAT \\file [,wild] (Toolkit II only)                           |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THORs                                                |
+----------+------------------------------------------------------------------+

The command WSTAT works in a very similar way to WDIR except that
alongside the filenames, it lists the length of each file and the update
time.

**Example**

::

    WSTAT QUILL_

will produce a list of all of the files on the data device which are in
the QUILL sub-directory.

**NOTE**

In current versions of Toolkit II (up to v2.85 at least), WSTAT cannot
cope with the DEV device where this is pointing to a sub-directory.

**CROSS-REFERENCE**

:ref:`dir` will produce a list of all of the files on
a given medium. :ref:`wcopy` contains details of how
wildcards operate.

--------------


