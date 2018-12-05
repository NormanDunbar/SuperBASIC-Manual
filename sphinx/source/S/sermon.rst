..  _sermon:

SERMON
======

+----------+-------------------------------------------------------------------+
| Syntax   |  SERMON                                                           |
+----------+-------------------------------------------------------------------+
| Location |  SERMouse                                                         |
+----------+-------------------------------------------------------------------+

The serial mouse driver must always be loaded into Resident Procedure
Space (for example with RESPR or LRESPR) before any Jobs are EXECuted.
However, if you have Hermes or SuperHermes fitted, you can configure the
Serial Mouse driver so that it does not automatically start up after
being linked into BASIC.

This command can be used to initialise and
startup the driver either following a SERMOFF command or if you have
configured the driver not to automatically start up after being linked
into BASIC. SERMON should also be used to reactivate the driver
following a SERMWAIT command.

**CROSS-REFERENCE**

:ref:`sermoff` and
:ref:`sermwait` are complementary functions. See
the Appendix on Mouse Drivers for further details.

--------------


