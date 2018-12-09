..  _few:

FEW
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FEW(filen :sup:`*`\ [,{filex | #chx}]\ :sup:`*` [;cmd$])         |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

Executes and waits for completion of the job filen, then returns the error code
from that job. FEW is a function version of :ref:`ew` and shares its argument list.


**Example**

::

    retcode = FEW ("win1_XChange_xchange")

Will start Psion XChange in win1_xchange, wait until that job has ended and will
then return the error code of that job.



**CROSS-REFERENCE**

See :ref:`ew`,
:ref:`exec-w`,
:ref:`jobs`.

