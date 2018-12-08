..  _qcopy:

QCOPY
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  QCOPY filename1,filename2                                        |
+----------+-------------------------------------------------------------------+
| Location |  ATARIDOS                                                         |
+----------+-------------------------------------------------------------------+

This command is similar to COPY except that it copies a file from an
Atari Format disk to a QL Format disk. No conversion takes place.

**NOTE**

You will need to pass the Atari filename in quote marks if it includes a
three letter extension preceded by a dot eg::

    QCOPY "flp1_PROGRAM.BAS", flp2_PROGRAM.BAS

**CROSS-REFERENCE**

:ref:`acopy` copies a file from a QL disk to an
Atari disk. Level-3 device drivers allow you to read and write to Atari
and IBM format disks anyway. See :ref:`aformat` and
:ref:`aqconvert`.

