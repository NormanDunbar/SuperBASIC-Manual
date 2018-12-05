..  _format:

FORMAT
======

+----------+-------------------------------------------------------------------+
| Syntax   |  FORMAT [#channel,] medium                                        |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

Each medium where data can be stored as files (disks, ramdisks,
microdrives or hard disks) has to be given a structure which is
recognisable by QDOS. This is done by FORMATting it. Each medium can
also be given a name of up to ten characters long. The command FORMAT
clears a medium from scratch so that any data stored there is
definitively lost. Be careful!

The following standard devices can be
formatted:

- MDV1\_ .. MDV8\_  - microdrive cartridges
- FLP1\_ .. FLP8\_  - floppy disks
- RAM1\_ .. RAM8\_  - ramdisks
- WIN1\_ .. WIN8\_  - hard disks

Depending on
the type of medium, several additions to the pure medium name are
possible:

**MDV** Up to ten characters can be added, these will form the name
of the cartridge, eg::

	FORMAT mdv2_SuperBASIC

**FLP** As with microdrive cartridges, a medium name can be added. If the
eleventh character of the name is an asterisk (\*), the disk will be
formatted single sided, ie. just the first side is used. In order to use
the single sided only option, is it necessary to put the whole parameter
in quotes, eg::

	FORMAT "flp1_TEST *"

This is not applicable to HD and ED disks: their density will also be
affected, making them single sided double density (SSDD). If a single
sided disk can still be bought today, it will actually be a double sided
disk of low quality.

With Super Gold Card, Gold Card and SMS, an
appended asterisk plus a letter which indicates the density will format
the disk accordingly: S, D, H and E are allowed, eg::

	FORMAT "flp1_TEST*h"

See :ref:`flp-density`.

**RAM** This depends very much on the ramdisk drivers:

With standard static ramdisks, which are built into most disk interfaces
and available as public domain, you need to specify how many sectors are
to be allocated to the ramdisk by adding the number of sectors to the
device name, eg::

	FORMAT ram1_200

formats ram2\_ to 200 sectors (100K).

These static ramdisks must be
FORMATted before use.

On the other hand, the Qjump ramprt ramdisk
(provided with Qpac 2 and various expansion boards, including Trump
Card, Gold Card and Super Gold Card) is dynamic - it adapts its size
automatically to the size of the files being stored on it - there is no
need to FORMAT the ramdisk prior to use. This can however also be used
as a static ramdisk.

Trump Card, Super Gold Card and Gold Card ROMs also
contain a special variant of a ramdisk which allows you to produce an
image of a microdrive cartridge on a ramdisk, for example by using::

	FORMAT ram4_mdv2.

Faulty files are marked with an asterisk added to the
end of their filenames. Although this may allow you to 'rescue' a
corrupt microdrive cartridge those files marked with an asterisk are
faulty and therefore unreliable.

The name of a ramdisk is always the
name of the medium without an underscore, eg. RAM1 for RAM1\_; this is
the same on dynamic ramdisks.

**WIN** A medium name can normally be stated,
as with a microdrive cartridge. Please check the documentation of the
hard disk drivers, they differ very much! For example, the firmware on
the Falkenberg interface disables FORMAT for hard disks until certain
settings have been specified with another command.

On the THOR, an
asterisk needs to be included, eg::

	FORMAT 'win1_*HARDDISK'

See below.

SMS for ATARI computers and QXL / QPC, expects you to have already
partitioned the hard disk using the computer's native commands. On
ATARIs, under SMSQ/E you then need to identify the drive and partition
using WIN\_DRIVE. After that, you can use the normal QL FORMAT command
on all these systems, however, SMSQ/E has adopted a level of protection
which insists that you must use the WIN\_FORMAT command before FORMAT
and the FORMAT command itself will display two characters on screen and ask you to
type them in.

You should then use WIN\_FORMAT to protect the partition
again.

The standard drivers for the ST/QL Emulators adopt a form of
protection in that you will need to type in the two characters shown on
screen as with SMSQ/E.

You can also only FORMAT a hard disk from
SuperBasic Job 0 and then only when Channel #0 is OPEN.

If the hard disk
has already been partitioned by the Atari ST (the first partition will
normally be marked GEM or BGM), then you will be asked to enter the
number of the first partition to be used by QDOS and the number of
subsequent partitions ot be used for this disk.

Under SMSQ/E on the QXL
or QPC, this same two- level protection is adopted. However, instead of
passing the medium name of the hard-disk, you have to pass the size of
the QL hard disk to be created in megabytes, for example::

	FORMAT WIN1_20

This will create a 20 Megabyte hard disk on PC drive C:

On early
versions, the maximum size that could be created was 23 Megabytes and
only one drive could be created. Later versions allow you to create WIN1
to WIN8 (all on drive C:).

After formatting, FORMAT will either report
that the process has failed (error -14), because there was no
cartridge/disk in the drive or if the medium was faulty.

The command
will also fail if the given device was write-protected.

If everything
was okay, a small message is printed to the specified channel (default
#1) indicating how many sectors could be achieved and how many were
good. If the two numbers differ, QDOS will have marked some sectors as
bad and will ignore them. However, experience shows that if the
difference between the two numbers is great, it can be very dangerous to
store important data on those disks/cartridges.

It is recommended that
new microdrive cartridges should be formatted 10 times before use (you
should expect to get about 220 available sectors). It may also be useful
to try formatting the cartridge in the other microdrive.

**Examples**

::

	FORMAT mdv2_Startup

formats cartridge in microdrive 2

::

	FORMAT "mdv2_Startup"

as above.

::

	FORMAT flp1_backup

formats disk in disk drive 1

::

	FORMAT "flp1_backup *"

as above but single sided

::

	FORMAT "flp1_backup*d"

double sided, double density

::

	FORMAT "flp2_backup*h"

double sided, high density

::

	FORMAT ram1_100

format ramdisk 1 to 50K

::

	FORMAT ram1_

remove ramdisk 1

::

	FORMAT ram1_mdv1

format ram1\_ to 255 sectors and copy cartridge in microdrive 1

**Notes on the different media:**

The traditional microdrive is relatively slow and unreliable, and
cartridges need to be formatted several times to give good results
(usually around 210-220 sectors) - pushing them firmly into the
microdrive slot while they are being formatted is said to be more
efficient.

However, as new cartridges are becoming more rare and
expensive today, the next best and very highly recommended upgrade are
disk drives.

It is also becoming less and less common to find users who
can read information stored on microdrive, SMS and emulators for
example, do not support microdrives.

**3.5" double density disks (720K)**

These are pretty cheap and you can get them everywhere (although the quality
does vary); they have become a standard on the QL, although it is
becoming ever more difficult to find replacement disk drives. FORMAT
should report 1440 sectors.

**3.5" high density disks (1.4Mb)**

These are also fairly cheap and you can get them everywhere (although the
quality does vary). These have become the new standard disks used by IBM
compatible computers and therefore the disk drives are easy to obtain.
FORMAT should report 2880 sectors.

**3.5" extra density disks (3.2Mb)**

These are fairly expensive and difficult to obtain as they were never really
accepted in the IBM PC world, although for a time, they looked like
becoming a new standard for the QL, being very quick and storing a lot
of information. FORMAT should report either 1600 or 6400 sectors (see
note 8).

**5.25" disks (720K)**

These are also widely spread in the QL scene, especially in the USA, although
they are now becoming less and less common. With the introduction of the
Super Gold Card and Gold Card by Miracle Systems Ltd, high density (HD,
1440K) and even extra density (ED, 3200K) drives have become available
to QDOS for the first time. These formats are several times faster and
even more reliable, not to mention the increased space for programs and
data.

**Hard disks**

These are becoming more and more common, with them being readily available to
people using Emulators on other computers, and also now the release of
relatively cheap interfaces and disk drives for the QL and AURORA.

**Ramdisks**

These are not specific to any hardware configuration because they only exist
in RAM and any stored data is lost if the machine is reset or turned
off. On the other hand, ramdisks are extremely fast.

**NOTE 1**

Unless you have a Minerva ROM (see below), do not try to FORMAT a
microdrive whilst any microdrive is still running, since this will
report an 'in use' error.

::

	PEEK(SYS_VARS+HEX('EE'))

will be zero if no microdrives are running.

**NOTE 2**

On the THOR XVI (v6.37 and earlier), there existed a bug when accessing
anything greater than win2\_.

**NOTE 3**

If there is no disk in a drive, FORMAT may also fail with a read only
error (-20) instead of reporting not found (-7).

**NOTE 4**

You cannot use FORMAT n1\_flp1\_ (for example) to FORMAT a medium over
the network.

**NOTE 5**

The ST/QL drivers cannot FORMAT the fifth and subsequent partitions on
the hard disk unless the extended partition table is in the form used by
SUPRA, ICD and similar drives.

**NOTE 6**

Minerva (pre v1.98) had some bugs in the code for FORMATting
microdrives.

**NOTE 7**

FORMAT expects the specified channel (or #1) to be OPEN, otherwise an
error will be reported.

**NOTE 8**

FORMAT cannot report a number of sectors in excess of 32768 and so may
return wrong values on large capacity drives. SMS correctly reports the
number of sectors obtained, although on an ED disk, FORMAT will report
1600 Sectors (DIR will show the figure of 6400 sectors instead!). This
is because on an ED disk, sectors are 2048 bytes long instead of the
usual 512 bytes expected by the QL device drivers (which have to be
fooled to see each sector as 4x512 byte sectors).

**MINERVA NOTE**

On Minerva v1.78 (and later), a check is carried out before performing
FORMAT to see if there are any files open on the desired medium. This
stops Digital Precision's Conqueror and Solution from working correctly.
To switch it off, use::

	POKE !124 !49, PEEK (!124 !49) || 128

**SMS NOTES**

As with Minerva, you cannot FORMAT a medium if there are any files
open on that medium ('Is In Use' error is reported). If there is a
problem during the FORMAT process, SMS will emit a series of BEEPs.
However, be warned that an error message is not always displayed and
the FORMAT may appear to have completed correctly!! SMS does not allow
you to access the QL's microdrives, nor can it solve the problem on the
QXL below. SMS can corrupt floppy disks (so they have to be thrown away)
if you try to FORMAT them to the wrong density.

Some users have reported
problems in using SMS to FORMAT
Double Density disks in ED disk drives linked to a Super Gold Card.
This appears to afflict versions of SMS after v2.85 and all makes of ED
drives. The problem only occurs if you specify the density with FORMAT
'flp1\_NAME\*D' or FLP\_DENSITY 'D'. In these cases, a noise is emitted
during FORMAT to indicate that it has failed, but SMS still reports
1440/1440 sectors, even though subsequent attempts to access the disk
report 'Not Found'. The answer is to not use FLP\_DENSITY in this
instance.

**QXL NOTES**

You cannot reliably FORMAT floppy disks from scratch on most PCs using
this emulator. FORMAT merely re-formats an already formatted disk. Prior
to v2.67 of SMS there existed several further problems with FORMAT on
QXL.

**THOR XVI NOTES**

The THOR XVI, v6.37 (and later) allows a variant of the medium name to
deal with the THOR's hard disk::

	FORMAT "win1_options*name"

The available options which can be specified are:

- /C : Certify drive before formatting - this reconstructs the THOR's defect list, describing the bad sectors and tracks;

- /Q : Quick reformat - merely sets up new directory map;

- /F : Fast reformat - does not verify the disk;

- /Gn : Set group or cluster size in blocks. Default = /G16;

- /Dn : Set directory size in number of groups or clusters. Default = /D2.

**Examples**

::

	FORMAT 'win1_/Q*Main'
	FORMAT 'win1_/G16/D2*THORDisk'

**WARNING**

Prior to v2.71 of SMS FORMAT flp3\_1 on the QXL could in fact FORMAT
WIN1\_.

**CROSS-REFERENCE**

Before formatting, the number of tracks on a disk can be specified with
:ref:`flp-track`. HD and ED disks can be
formatted to different densities if
:ref:`flp-density` was used to override
automatic detection of the density. See
:ref:`win-format` for hard disk protection.
The DMEDIUM_XXX functions, starting at :ref:`dmedium-density` return various details
about how a medium has been formatted.

--------------


