..  _fex:

FEX
===

+----------+-------------------------------------------------------------------+
| Syntax   |  FEX(file :sup:`*`\ [,{filex | #chx}]\ :sup:`*` [;cmd$])          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

Executes and returns the job ID of the job filename.
This function is a functional version of :ref:`ex`, with the same set of arguments,
that executes a job. In addition to what :ref:`ex` does, it returns the job ID of the
new job that was started.

**Example**

::

    jId = FEX ("win1_XChange_xchange")

Will start Psion XChange in win1_xchange and return the job ID of the new job.

**NOTES**
In some combinations of SMSQ/E and FileInfo2 versions, there might be a clash of
extension names between FEX supplied as an SMSQ/E function (as described here)
and a function with the same name (but very different purpose) supplied by
FileInfo2. Later versions of FileInfo2 resolved this name clash by renaming the
corresponding function to EXF.

**CROSS-REFERENCE**

See :ref:`ex`, :ref:`fet`, :ref:`few`, :ref:`exec`, :ref:`jobs`.

