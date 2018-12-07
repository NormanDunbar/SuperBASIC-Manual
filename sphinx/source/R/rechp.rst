..  _rechp:

RECHP
=====

+----------+---------------------------------------------------------------------------------+
| Syntax   | RECHP address  or                                                               |
|          |                                                                                 |
|          | RECHP address\ :sup:`1` :sup:`\*`\ [,address\ :sup:`i`]\ :sup:`\*` (BTool only) |
+----------+---------------------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI, BTool                                                     |
+----------+---------------------------------------------------------------------------------+

The common heap is an area in memory where all programs may store data,
this space being only limited by the memory available. A BASIC program
can reserve space in the common heap with the function ALCHP.

The command RECHP allows you to recover this memory. The parameter of RECHP
must be the address which was returned by ALCHP. The Btool variant of
this command allows you to recover several addresses at once.

**Example**

Loading a title screen::

    100 Title$="FLP1_TITLE_SCR"
    110 IF FREE_MEM < 38*1024 THEN
    120   LBYTES Title$,SCREEN
    130 ELSE
    140   TitleAdr=ALCHP(32768)
    150   LBYTES Title$,TitleAdr
    160   SCRBASE TitleAdr: REFRESH
    170   RECHP TitleAdr
    180 END IF

**NOTE**

RECHP reports error -15 if the address was not reserved with ALCHP or if
the memory has already been given back to QDOS.

**CROSS-REFERENCE**

:ref:`clchp` clears all memory reserved by
:ref:`alchp`, :ref:`clear`
deletes the values of all variables. See also
:ref:`discard`, :ref:`ttrel`
and :ref:`release`.

