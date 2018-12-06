..  _gethead:

GetHEAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  GetHEAD #ch, adr                                                 |
+----------+-------------------------------------------------------------------+
| Location |  HEADER (DIY Toolkit)                                             |
+----------+-------------------------------------------------------------------+

GetHEAD loads the header of an opened file pointed to by the channel
#ch into memory at adr, which must point to at least 64 bytes of
reserved memory.

**Example**

If the file header of an executable file is lost then you must modify it
so that the file can be executed again. Executable files need the file
type set to 1 and the dataspace to be specified, the latter must be
large enough to avoid a serious crash. MAKEJOB does this with file$,
demonstrating GetHEAD and SetHEAD::

    100 DEFine PROCedure MAKEJOB (file$, dataspace)
    110 LOCal fp
    120 fp=FOPEN(file$): IF fp<0 THEN STOP
    130 adr=ALCHP(64): IF adr=0 THEN STOP
    140 GetHEAD#fp,adr
    150 POKE adr+5,1
    160 POKE_L adr+6,dataspace
    170 SetHEAD#fp,adr
    180 CLOSE#fp: RECHP adr
    190 END DEFine MAKEJOB

**CROSS-REFERENCE**

:ref:`sethead` saves a file header. See
:ref:`fgeth-dlr` for information about the file
header. :ref:`headr` is very similar to
:ref:`gethead`. See also
:ref:`hget` and :ref:`hput`.

