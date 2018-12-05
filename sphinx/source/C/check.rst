..  _check:

CHECK
=====

+----------+-------------------------------------------------------------------+
| Syntax   | oops = CHECK('name')                                              |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

If name is a currently loaded  machine code procedure or function, then the variable oops will be set to 1 otherwise it will be set to 0.  This is a handy way to check that an extension command has been loaded before calling it.  In a Turbo'd or Supercharged program, the :ref:`exec` will fail and a list of  missing extensions will be displayed, a QLiberated program will only fail if the extension is actually called.

**EXAMPLE**

::

    1000 DEFine FuNction CheckTK2
    1010   REMark Is TK2 present?
    1020   RETurn CHECK('WTV')
    2030 END DEFine


-------


