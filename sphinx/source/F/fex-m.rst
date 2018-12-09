..  _fex-m:

FEX\_M
======

+----------+-----------------------------------------------------------------------------------+
| Syntax   |  FEX\_M file :sup:`\*`\ [,{file\ :sup:`x` \| #ch\ :sup:`x`\ }]\ :sup:`\*` [;cmd$] |
+----------+-----------------------------------------------------------------------------------+
| Location |  SMSQ/E                                                                           |
+----------+-----------------------------------------------------------------------------------+

Variant of the :ref:`fex` function that executes the given file and returns the new
job ID. Differently to :ref:`fex`, which starts the new job as owned by the system,
FEX\_M starts the job as a job owned by its parent job. This means that the
newly started job will be killed whenever its owner job is killed.

**Example**

::

    jobid = FEX\_M(win1_qmac)

Will execute Qmac as a job owned by the current S*BASIC interpreter. When the
current interpreter ceases to exist, the new Qmac job will also be killed.

**NOTE**

An exhaustive explanation of the possible options can be found with the
description of :ref:`ex`. FEX\_M takes the exact same arguments.

**CROSS-REFERENCE**

See :ref:`ex`.

