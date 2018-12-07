..  _outl:

OUTL
====

+----------+-------------------------------------------------------------------+
| Syntax   |  OUTL [#]chan [,width,height,x,y]                                 |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

This command is similar to OUTLN except for a few variations:

#. If chan is not preceded by # then it is taken to be a QDOS channel number (and this command can therefore be used to redefine an Outline for any Job).
#. You cannot specify a shadow.
#. If only the chan parameter is used (with or without a #), then the current maximum sizes of the Jobs
   windows are used (similar to :ref:`outln` without any parameters).

**CROSS-REFERENCE**

See :ref:`outln`.
:ref:`channels` allows you to find out about QDOS
channel numbers.
