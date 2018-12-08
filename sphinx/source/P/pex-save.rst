..  _pex-save:

PEX\_SAVE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PEX\_SAVE directory$                                             |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

This command stores the current settings of PEX in a file called
PEX19\_byt (for version 19.30) in the specified directory
so that when you next load PEX (with LBYTES directory$&PEX\_19\_byt for
example), you will not have to re-set all of the various settings. The
sub-version number of PEX is increased by one.

**Example**

::

    PEX_SAVE 'win1_start_'

will create the file win1\_start\_PEX19\_byt.

**NOTE**

An underscore must appear at the end of directory$.

**CROSS-REFERENCE**

See :ref:`peon` for more general details. The
settings which are saved are set with the command
:ref:`is-ptrap` and
IS_PXLST. :ref:`pex-dlr`
returns the sub-version number.

