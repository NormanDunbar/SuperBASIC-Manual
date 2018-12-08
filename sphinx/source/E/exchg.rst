..  _exchg:

EXCHG
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  EXCHG device\_file,old$,new$                                     |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT                                                      |
+----------+-------------------------------------------------------------------+

This command creates a Job which opens a channel to the specified file and then
works through the file, replacing every occurrence of old$ with new$. The
search for old$ is case independent. Both old$ and new$ must be the same length.

**Example**

::

    EXCHG flp1_Task_obj,'mdv','flp'

will replace all references to mdv1\_ or mdv2\_ to flp1\_ and flp2\_ respectively
in the file flp1\_task\_obj.

**NOTE**

CHR$(0) cannot be replaced!

**CROSS-REFERENCE**

See also :ref:`convert`.

