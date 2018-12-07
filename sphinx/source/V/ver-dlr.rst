..  _ver-dlr:

VER$
====

+----------+------------------------------------------------------------------+
| Syntax   | VER$  or                                                         |
|          |                                                                  |
|          | VER$ [(n)] with n=1, 0, -1, -2(Minerva and SMS only)             |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

The function VER$, which is the same as VER$(0) returns a short
identification code for the version of the current system ROM. Here are
most of the possible values (in order of development):

**Original ROMs**

.. DO NOT add a double pipe at the start of the first line. If you do then the whole table is
   completely useless in the rendered output. As it is, each time we build, we get a Latex error
   for the ||, but pressing ENTER seems to get past it. Plus, it builds!

.. tabularcolumns::   |p{0.05\linewidth}| p{0.9\linewidth}|

..  table::
    :class: longtable

    +------+--------------------------------------------------------------------------+
    | VER$ | Explanation                                                              |
    +======+==========================================================================+
    || FB  | This is the first ROM sold in April 1984, QDOS version                   |
    |      | 1.00. It comes with a 'Dongle' - a board which needed to be plugged into |
    |      | the QL's ROM port. It is very unreliable and should be replaced!!        |
    +------+--------------------------------------------------------------------------+
    || PM  | These three ROMs were developed during the following two months.         |
    || EL  | (May, June & July 1984.)                                                 |
    || TB  |                                                                          |
    +------+--------------------------------------------------------------------------+
    || AH  | Released as the "definitive" version in June 1984.                       |
    +------+--------------------------------------------------------------------------+
    || JM  | British QL, QDOS v1.03, the first version which was exported.            |
    +------+--------------------------------------------------------------------------+
    || JS  | Released in spring 1985, QDOS v1.10. Also found on early Thors and       |
    |      | patched in ST/QL and early Amiga Emulators.                              |
    +------+--------------------------------------------------------------------------+
    || JSU | American QL.                                                             |
    +------+--------------------------------------------------------------------------+
    | The following versions were only sold in their respective countries.            |
    | All are QDOS v1.03.                                                             |
    +------+--------------------------------------------------------------------------+
    || MGD || Danish                                                                  |
    || MGE || Spanish                                                                 |
    || MGF || French                                                                  |
    || MGG || German                                                                  |
    || MGI || Italian                                                                 |
    || MGN || Norwegian                                                               |
    || MGS || Swedish                                                                 |
    || MGB || Swedish                                                                 |
    || MGY || Finish                                                                  |
    || MG$ || Greek                                                                   |
    || $FP || Greek                                                                   |
    +------+--------------------------------------------------------------------------+


**Patches**

.. DO NOT add a double pipe at the start of the first line. If you do then the whole table is
   completely useless in the rendered output. As it is, each time we build, we get a Latex error
   for the ||, but pressing ENTER seems to get past it. Plus, it builds!

.. tabularcolumns::   |p{0.05\linewidth}| p{0.9\linewidth}|

..  table::
    :class: longtable

    +------+--------------------------------------------------------------------------+
    | VER$ | Explanation                                                              |
    +======+==========================================================================+
    | MGUK | A version of the MGx ROM produced independently for the UK market.       |
    +------+--------------------------------------------------------------------------+
    | MG   | Another patched version, mainly distributed in Germany.                  |
    +------+--------------------------------------------------------------------------+
    | MGUS | Out of the three patches, this is the only legal one and was produced    |
    |      | for the United States.                                                   |
    +------+--------------------------------------------------------------------------+

**New developments**

.. DO NOT add a double pipe at the start of the first line. If you do then the whole table is
   completely useless in the rendered output. As it is, each time we build, we get a Latex error
   for the ||, but pressing ENTER seems to get past it. Plus, it builds!

.. tabularcolumns::   |p{0.05\linewidth}| p{0.9\linewidth}|

..  table::
    :class: longtable

    +------+--------------------------------------------------------------------------+
    | VER$ | Explanation                                                              |
    +======+==========================================================================+
    | CS   |                                                                          |
    | PT   | Different ROMs used on the THOR XVI.                                     |
    | PO   |                                                                          |
    +------+--------------------------------------------------------------------------+
    | JSL1 | QL with Minerva ROM, a very much debugged and enhanced                   |
    |      | version of the JS ROM, available in all languages for all kinds of QLs.  |
    +------+--------------------------------------------------------------------------+
    | HBA  | Either the SMSQ or SMSQ/E replacement operating system for QXLs,         |
    |      | Atari ST/STE and TT series computers and the Miracle Gold Card family of |
    |      | add-on cards.                                                            |
    +------+--------------------------------------------------------------------------+

**NOTE 1**

VER$ can be used to write flexible programs which adapt themselves to
specific features of computers and ROM implementations. However, if you
intend to test VER$, for example::

    IF VER$= 'JM'

to retain compatibility with the different ROM versions, you must first
assign the contents of VER$ to a variable::

    100 a$=VER$
    110 IF a$(1 TO 2)='MG': PRINT 'MG ROM'

**NOTE 2**

The names of the original ROMs were derived from names of Clive
Sinclair's secretaries, taxi drivers he met and so on. (Just in case you
are looking for any sense behind the abbreviations.)

**MINERVA NOTES**

On Minerva, VER$ accepts a parameter:

- VER$(0)as per above VER$.
- VER$(-2) returns the base address of the system variables (normally $28000 = 163840 on a standard QL).
- VER$(-1)returns the current job identification number.
- VER$(1)returns the version of QDOS (see also QDOS$).

**SMS NOTES**

VER$ has been amended to provide the same facilities as on Minerva.

**WARNING**

If you fail to assign VER$ to a variable before testing its value, then
you can crash a JS (or JSU) ROM. This will also happen on Minerva ROMs
(pre v1.77) with Minerva's extended variant VER$(n).

**CROSS-REFERENCE**

:ref:`qdos-dlr` returns the version number of QDOS in
the same way as :ref:`ver-dlr`\ (1). See also
:ref:`machine` and
:ref:`processor`.

