..  _sar:

SAR
===

+----------+-------------------------------------------------------------------+
| Syntax   |  SAR file, array                                                  |
+----------+-------------------------------------------------------------------+
| Location |  ARRAY                                                            |
+----------+-------------------------------------------------------------------+

The command SAR allows you to save a given array quickly (so that it
can later be reloaded) as a whole to a specified file. The Toolkit II
default data device for the file name is supported, although an existing
file is not overwritten (use SARO) - the error 'Already exists' will be
generated instead. array is stored in an internal coded but portable
format, which makes it extremely fast to save and load arrays when
compared to storage by writing and reading each individual element of an
array.

The file format is quite simple, it is basically the same as the
way in which SuperBASIC itself would store the array. The first four
bytes of the stored array are the characters WLAF. SAR will identify
dimensions and the type of array on its own and accordingly store it.

Sub-arrays are handled, but please note that, since stored data can only
be reloaded into a readily dimensioned array (see LAR), it is important
to remember the dimensions and type of the array before loading.

**Example**

Save and load an array::

    100 DIM a%(1000)
    110 SAR file$, a%
    120 LAR file$, a%

**NOTE**

SAR's file format is not compatible with that used by Toolkit 3 (a
commercial Toolkit which has nothing to do with the famous Toolkit II),
produced with SARRAY.

**CROSS-REFERENCE**

:ref:`saro` and :ref:`lar`.
:ref:`dim` sets-up an array while
:ref:`dimn` and :ref:`ndim` read
the dimensions.

