..  _flp-density:

FLP\_DENSITY
============

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_DENSITY density  (density = S, D, H or E)                   |
|          |                                                                   |
|          |  FLP\_DENSITY (SMSQ/E for QPC only)                               |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards, SMS, SMSQ/E for QPC                                  |
+----------+-------------------------------------------------------------------+

There are four types of floppy disk drives which can be connected to
a QL with a Gold Card (or to other computers which are running a QL
emulator). The command FLP\_DENSITY sets the type for use with FORMAT:

+--------+---------+--------+----------+--------------+
| Sides  | Density | Abbrev | Capacity | FLP\_Density |
+========+=========+========+==========+==============+
| Single | Double  | SSDD   |  360 Kb  | S            |
+--------+---------+--------+----------+--------------+
| Double | Double  | DSDD   |  720 Kb  | D (Not QPC)  |
+--------+---------+--------+----------+--------------+
| Double | High    | DSHD   | 1440 Kb  | H            |
+--------+---------+--------+----------+--------------+
| Double | Extra   | DSED   | 3240 Kb  | E (Not QPC)  |
+--------+---------+--------+----------+--------------+

Parameters other than the four letters S, D, H and E, (including
several characters or several parameters) are not allowed.

**Examples**

::

    FLP_DENSITY h
    FLP_DENSITY 'D'

**NOTE 1**

Tests have shown that it is not always advisable to FORMAT a disk to a
lower density than would otherwise be possible, for example a high
density disk to double density. The result may be that the number of
good sectors is less than could have been achieved by formatting a disk
of the lower density.

During testing, an undamaged double density disk
was formatted to 1440 sectors and a high density disk to 2880 sectors,
but if the high density disk had been formatted to double density, eg.
with::

    FLP_DENSITY D : FORMAT flp1_

less than 1440 sectors might be good sectors.

You may also find that
some disk drives which support the higher density will be unable to read
these disks, since it will presume that they are FORMATted to their
maximum density.

**NOTE 2**

Since FLP\_DENSITY only has any affect during formatting, it should
generally be avoided. This does not really matter because a disk is
automatically formatted to the highest possible density and it would be
a waste of money to use a HD disk as a DD disk.

**NOTE 3**

If a high or extra density disk is formatted on a system which does not
support those capacities, it will be formatted to double density without
any disadvantages. Such a disk does not cause problems when used with a
Gold Card QL.

**NOTE 4**

A double density disk cannot be formatted to a higher density with HD
drives - the Level-2 (or Level-3) device driver will automatically
reduce a density which had been set at too high a figure by
FLP\_DENSITY, to the appropriate figure. An ED drive however can
successfully format HD disks and even DD disks to high and extra
density, but such disks may be unreliable, ie. data could be easily
lost.

**NOTE 4**

High density is only supported on 3.5" disks, not 5.25" disks (widely
used on MS/DOS systems). Extra density also only exists on 3.5" disks.
QL DD and HD formatted disks have the same physical (but not software)
format as MS/DOS and Atari TOS disks.

**NOTE 5**

High density and Extra density disks are much faster than double density
disks, ED disks can even be as fast as slow hard disks.

**NOTE 6**

FLP\_DENSITY overrides the in-built trial-and-error density detection
which is slow for HD drives and even slower with ED drives. This can
however cause problems when FORMATting DSDD disks - see FORMAT!

**NOTE 7**

On SQMS/E for QPC, the same code letters may be added (after a \*) to the end of the medium name to force a particular density format. (For compatibility with older drivers, if the code letter is omitted after the \*, single sided format is assumed).

- FORMAT 'FLP1\_Disk23' Format at highest density or as specified by :ref:`flp-density`\ .

- FORMAT 'FLP1\_Disk24\*' Format single sided
- FORMAT 'FLP1\_Disk25\*S' Format single sided
- FORMAT 'FLP1\_Disk25\*D' Format double sided, double density

Also, FLP\_DENSITY on it's own resets automatic density selection.

**CROSS-REFERENCE**

The same effect as :ref:`flp-density` can be
achieved with a special :ref:`format` syntax.
:ref:`flp-track` allows you to specify the
number of tracks to be formatted onto a disk.
:ref:`stat` prints the name, good and free sectors of
a medium. See also the The DMEDIUM_XXX functions, starting at :ref:`dmedium-density`.

