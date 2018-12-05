..  _hot-res1:

HOT\_RES1
=========

+----------+------------------------------------------------------------------+
| Syntax   | HOT\_RES1 (key$,filename [;cmd$] [,Jobname$] [,options] )  or    |
|          |                                                                  |
|          | HOT\_RES1 (key$,filename [;cmd$] !Wakename$ [,options] )         |
+----------+------------------------------------------------------------------+
| Location | HOTKEY II                                                        |
+----------+------------------------------------------------------------------+

HOT\_RES1 is the same as HOT\_CHP1 except that the program is loaded
into the resident procedure area. If this cannot be accessed for any
reason, the common heap will be used.

**CROSS-REFERENCE**

See :ref:`hot-res` and
:ref:`hot-chp1`.

--------------


