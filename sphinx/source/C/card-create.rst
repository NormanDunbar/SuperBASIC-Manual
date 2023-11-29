.. _card-create:

CARD\_CREATE
============

+----------+-------------------------------------------------------------------+
| Syntax   | CARD\_CREATE card,size,filename$                                  |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for Q68                                                    |
+----------+-------------------------------------------------------------------+

Creates a new file on an SD card that is size MB in size with the name
given by $filename.

Being a complex comand, it can return many different errors depending
on what has gone wrong.

.. table::
  :widths: 10 10 80

  +----------+-----+-----------------------------------------------------------+
  | Error    | Num | Description                                               |
  +----------+-----+-----------------------------------------------------------+
  | err.drfl | -1  | Drive full                                                |
  |          |     |  there is no space for a file of this size within         |
  |          |     |  contiguous sectors on the card.                          |
  +----------+-----+-----------------------------------------------------------+
  | err.imem | -3  | Insufficient memory for operation                         |
  |          |     |  you shouldn't actuall get this error                     |
  +----------+-----+-----------------------------------------------------------+
  | err.orng | -4  | File size out of range                                    |
  |          |     |  the projected size of the file is too big, or 0 or       |
  |          |     |  negative.                                                |
  +----------+-----+-----------------------------------------------------------+
  | err.bffl | -5  | Buffer full                                               |
  |          |     |  there is no space in the first 16 directory entries for  |
  |          |     |  a  new file.                                             |
  +----------+-----+-----------------------------------------------------------+
  | err.fex  | -8  | File already exists                                       |
  |          |     |  a file with this name already exists in the first 16     |
  |          |     |  directory entries for a new file                         |
  +----------+-----+-----------------------------------------------------------+
  | err.inam | -12 | Invalid file name                                         |
  |          |     |  not an 8.3 name.                                         |
  +----------+-----+-----------------------------------------------------------+
  | err.ipar | -15 | Wrong card number                                         |
  |          |     |  not 1 or 2.                                              |
  +----------+-----+-----------------------------------------------------------+
  | err.mchk | -16 | Medium check failed                                       |
  |          |     |  card wasn't readable (perhaps absent / not initialised)  |
  |          |     |  or this isn't a valid FAT32 partition.                   |
  +----------+-----+-----------------------------------------------------------+

**Example**

::

   10 CARD_CREATE 1,200,"test.win" : REMark create empty file, 200 MB in size
   20 WIN_DRIVE 4,1,"test.win"     : REMark point win4_ to it
   30 WIN_FORMAT 4                 : REMark allow formatting of win4_
   40 FORMAT win4_name             : REMark format win4_
   
**Note 1**

There must be an empty slot in the first 16 entries of the FAT32
volume and the file name must obey the "8.3 rule".

**Note 2**

The file is not zeroed out and may contain random data.

**Note 3**

The maximum file size is dependant on the cluster size for the FAT32 volume.

+--------------+------------------+
| Cluster size | Max file size    |
+--------------+------------------+
| 2            | just under 8 GB  |
+--------------+------------------+
| 4            | just under 16 GB |
+--------------+------------------+
| 8            | just under 32 GB |
+--------------+------------------+

**Note 4**

SMSQ/E only checks the first 16 entries. If there are more than 16 and
an empty entry exists in the first 16, if may be possible to create an
duplicate entry with the name of an existing file.

**CROSS-REFERENCE**

:ref:`card-init`,
:ref:`card-dir-dlr`
