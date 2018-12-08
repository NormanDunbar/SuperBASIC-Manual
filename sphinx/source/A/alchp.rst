..  _alchp:

ALCHP
=====

+----------+------------------------------------------------------------------+
| Syntax   | ALCHP (space) or                                                 |
|          |                                                                  |
|          | ALCHP (space [,[jobID]]) (BTool only)                            |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI, BTool                                      |
+----------+------------------------------------------------------------------+

The function ALCHP allocates space bytes in the common heap and returns
the start address of the memory set aside to be altered freely. This,
unlike RESPR, works even if there is a task running in memory.

If ALCHP fails due to lack of available memory, then it will return 0
instead of breaking with error -3 (Out of Memory).

The BTool version of ALCHP allows an extended syntax. If space is
followed by a comma ',' then the allocated memory can only be removed
with RECHP or CLCHP (unlike the other versions where this is done
automatically with NEW and CLEAR). If the jobID is specified then not
only will this be done, but the memory will also be linked to the Job
identified by jobID.

**Example 1**

The following program loads two uncompressed screens from

disk into memory and shows them alternately:

::

    100 adr=ALCHP(2*32768)
    110 LBYTES flp1_Screen1_scr,adr
    120 LBYTES flp1_Screen2_scr,adr+32768
    130 REPeat Picture_Show
    140   SCRBASE adr : REFRESH : PAUSE 150
    150   SCRBASE adr+32768 : REFRESH : PAUSE 150
    160 END REPeat Picture_Show

**Example 2**

This is an alternative to the LRESPR command (although see Note 2
below):

::

    100 DEFine PROCedure LALCHP (mc_file$)
    110  LOCal length,adress
    120  length=FLEN(\mc_file$)
    130  adress=ALCHP(length)
    140  LBYTES mc_file$,adress
    150  CALL adress
    160 END DEFine LALCHP

**NOTE 1**

ALCHP reserves memory in 512 byte chunks.

**NOTE 2**

Memory reserved by ALCHP is indirectly cleared by NEW, CLEAR, LOAD and
LRUN (this does not apply to the Btool extended variant - see above).

**WARNING 1**

Never run device drivers in the common heap - this memory can be easily
cleared, causing a spectacular crash if a device driver was stored
there. This is true for other machine code, too.

**WARNING 2**

There is no checking on the parameter for ALCHP - accordingly negative
values can be supplied. These are likely to lead to unexpected results
and will probably crash the computer - for example, x=ALCHP(-100)
crashes a JM ROM. On a Minerva ROM, values below -5 will return 0. On
SMS although only values below -20 return 0, any attempt to reclaim the
areas set aside with CLCHP or RECHP will crash the system.

**WARNING 3**

Since ALCHP returns 0 if there is not enough memory, you should always
check the value returned by ALCHP for this before writing to the
address. Otherwise, it is possible that you will be over-writing the
operating system... crash!

**CROSS-REFERENCE**

The reserved parts of memory can be given back to QDOS' memory
management by :ref:`rechp` base\_address or
:ref:`clchp`.

:ref:`respr`, :ref:`ttall`,
:ref:`allocation` and especially
:ref:`grab` and :ref:`reserve`
work similar to :ref:`alchp`.

See :ref:`del-defb` concerning heap
fragmentation.

