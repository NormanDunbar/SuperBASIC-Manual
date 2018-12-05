..  _net-id:

NET\_ID
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  NET\_ID                                                          |
+----------+-------------------------------------------------------------------+
| Location |  THOR XVI                                                         |
+----------+-------------------------------------------------------------------+

This function returns the computer's station number set with NET. Other
ROMs can also find out their station number by using::

    PRINT PEEK (SYS_VARS+55)

or::

    PRINT PEEK (!!55)

(the latter syntax being accepted by Minerva and SMS).

**CROSS-REFERENCE**

See :ref:`net` which sets the station number. Also see
:ref:`mnet-pct` and :ref:`snet-pct`

--------------


