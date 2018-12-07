..  _peon:

PEON
====

+----------+-------------------------------------------------------------------+
| Syntax   |  PEON [{ #ch \| chan\_ID \| job\_name$ }]                         |
+----------+-------------------------------------------------------------------+
| Location |  PEX                                                              |
+----------+-------------------------------------------------------------------+

PEX is similar to the PIE system extension (see PIE\_ON for more
details), in that it allows buried programs to access the screen in the
background. However, PEX cannot be used with PIE and is completely
independent. PEX should be loaded after the Pointer Environment (notably
the PTR\_GEN file), and after any other code which redefines the window
handling of the QL (for example Lightning or Speedscreen). It must
however be loaded before the History device (except on SMSQ/E which has
a built in History device).

People who use PEX or PIE may like to also
use another utility PICE which updates the QL screen at pre-defined time
intervals so that any part of a window which is not buried will actually
appear on screen (whether or not part of that window is buried). If you
wish to use PICE, it is recommended to set the PICE job to a priority of
1 so as not to slow the system down too much.

The PEON command allows
you to select which windows and Jobs should allow background screen
access - this is important since the more programs which continue to run
in the background, the slower your QL will appear!! If no parameter is
specified, then background screen access is enabled for all Jobs.

You can however pass any number of parameters, which can be:

#. A SuperBASIC channel number for the current program;
#. A QDOS channel number (see CHANNELS) in which case PEX will only affect that specific channel;
#. The name of a Job (passed as a string - use a null string ("") for SuperBASIC). PEX will affect all windows used by that specified Job.

**NOTE 1**

PEX will not work on pre-JS ROMs. On JS and MG ROMs, its functionality
is reduced in that it can only be used to allow a few machine code calls
which do not access the screen to operate notwithstanding that the
Pointer Environment would normally stop them from working from within a
buried program. It is equivalent to::

    FOR i=0 TO 127: x=IS_PTRAP(i,3)


**NOTE 2**

Some toolkits report errors when used alongside PEX and some Qliberated
programs refuse to work.

**CROSS-REFERENCE**

See :ref:`peoff`, :ref:`pie-on`,
:ref:`pxon`, :ref:`pex-ini`
and :ref:`is-peon` for more
details. :ref:`is-ptrap` allows you to enable
PEX for specific machine code routines.

