..  _env-del:

ENV\_DEL
========

+----------+-------------------------------------------------------------------+
| Syntax   |  ENV\_DEL name$                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Environment Variables                                            |
+----------+-------------------------------------------------------------------+

This command is used to remove a specified environment variable. Please note that
the name of the environment variable is case sensitive. If an empty string is
passed as the argument, then an error will be reported.

**Example**

A boot program may specify where the files for the main program are
stored and then pass it to subsequently called programs with. Once the
program has finished, the environment variable may be deleted.

::

    1000 source$='win1_PROGS_utils\_'
    1010 SETENV "PROGLOC="&source$
    1020 EXEC_W source$&'main_exe'
    1030 ENV_DEL "PROGLOC"

**CROSS-REFERENCE**

Please see SETENV.

--------------


