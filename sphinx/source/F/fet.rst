..  _fet:

FET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FET(file :sup:`*`\ [,{filex | #chx}]\ :sup:`*` [;cmd$])          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

Executes and returns the job ID of the job filename in suspended state (by
immediately setting the new job's priority to zero).
This function is a functional version of :ref:`et`, with the same set of arguments,
that executes a job into suspended state for tracing with a monitor. In addition
to what :ref:`et` does, it returns the job ID of the new job that was started.


**Examples**

::

    jId = FEX ("win1_XChange_xchange")

Will start Psion XChange in win1_xchange in suspended state and return the job
ID of the new job.



**CROSS-REFERENCE**

See :ref:`et`, :ref:`exec`, :ref:`jobs`.

