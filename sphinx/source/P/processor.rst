..  _processor:

PROCESSOR
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PROCESSOR                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function returns a value which can be used to find the type of
Processor on which SuperBASIC is running (normally a member of the
Motorola 680xx family). The values returned are:

+-----------+--------------------------------------------+
| PROCESSOR | Chip Type                                  |
+===========+============================================+
| 0x        | 68000 or 68008                             |
+-----------+--------------------------------------------+
| 1x        | 68010 or an INTEL chip (QPC < 3.33)        |
+-----------+--------------------------------------------+
| 2x        | 68020 (and QPC >= 3.33)                    |
+-----------+--------------------------------------------+
| 3x        | 68030                                      |
+-----------+--------------------------------------------+
| 4x        | 68040                                      |
+-----------+--------------------------------------------+
| 6x        | 68060                                      |
+-----------+--------------------------------------------+

In the above 'x' is replaced by a value between 0 and 8 to
indicate if a maths co-processor is installed).

You can also test if a maths co-processor is installed, by using::

    coprocessor%=PEEK(!!$A1) && BIN('1111')

The following values may be returned:

+-------------+-----------------------------------------+
| Coprocessor | Meaning                                 |
+=============+=========================================+
| 0           | No FPU fitted.                          |
+-------------+-----------------------------------------+
| 1           | An Internal MMU is fitted.              |
+-------------+-----------------------------------------+
| 2           | A 68851 MMU is fitted.                  |
+-------------+-----------------------------------------+
| 4           | An internal FPU is fitted.              |
+-------------+-----------------------------------------+
| 8           | Either a 68881 or 68882 FPU is fitted.  |
+-------------+-----------------------------------------+

**NOTE**

The processor type was not stored before Level E-20 of the ST/QL
Drivers.

**QPC Note**

QPC versions prior to 3.33 will return a value of 10 for the PROCESSOR function while those from 3.33 onwards will return 20.

**CROSS-REFERENCE**

See :ref:`machine`,
:ref:`qdos-dlr` and :ref:`ver-dlr`

