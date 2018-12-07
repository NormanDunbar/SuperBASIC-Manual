..  _rel-job:

REL\_JOB
========

+----------+-------------------------------------------------------------------+
| Syntax   |  REL\_JOB jobname  or REL\_JOB jobnr                              |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command releases a suspended job, so that it becomes active again.

**NOTE 1**

Releasing a job which is waiting for screen input/output will normally
kill it, because it should be activated by <CTRL><C>.

**NOTE 2**

Before v1.11 of this Toolkit, jobnr could not be a variable (see JBASE).

**CROSS-REFERENCE**

Jobs can be suspended by :ref:`sjob` and removed with
:ref:`rjob`, :ref:`kjob`,
:ref:`kill`, etc. :ref:`jobs`
lists the current jobs. See :ref:`reljob`.

