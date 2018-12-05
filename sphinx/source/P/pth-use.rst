..  _pth-use:

PTH\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_USE [path\_name]                                            |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

The default name used for the path device is PTH. If you don't like
that, you can change it with PTH\_USE to any other combination of three
letters, including existing drive names. If no parameter is used, the
default name is restored.

**Examples**

::
    PTH_USE huh
    PTH_USE flp
    PTH_USE

**NOTE**

The default name can be permanently configured with Qjump's Config
program.

**CROSS-REFERENCE**

:ref:`pth-use-dlr` returns the current setting.

--------------


