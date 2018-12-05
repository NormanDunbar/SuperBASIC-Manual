..  _nfs-use:

NFS\_USE
========

+----------+------------------------------------------------------------------+
| Syntax   | NFS\_USE newdrive, drive1 [,drive2 [..., drive8]] or             |
|          |                                                                  |
|          | NFS\_USE [newdrive]                                              |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI                                             |
+----------+------------------------------------------------------------------+

Two QLs, both fitted with Toolkit II on EPROM (or SMS) and connected
via a network cable, can use Toolkit II's file server which is activated
by the FSERVE command. All of the devices on the other QL (provided the
Server job is running on that QL) can then be accessed as if they were a
normal device on the QL wishing to use the facilities. This is achieved
by prefixing the device name by: n<netnr>\_, eg::

    DIR n2_flp1_

will show the directory of flp1\_ on station number 2.

:ref:`net` sets this
station number.

Two problems do however arise from using this technique:
Firstly, it is a bit annoying to have to type n2\_flp1\_. Secondly, a
lot of programs check the validity of a device by checking if the length
is five characters, the first three characters of which must be letters,
and the fourth character of which must be a digit from 1 to 8 with an
underscore at the end. These programs therefore only allow device names
such as ram6\_, mdv1\_, etc. To fool these programs (and also to shorten
names)::

    NFS_USE

can be used to create a new device which has a shorter name. The first
parameter is the name of the new drive which can be any description up
to four characters long (there is no need to include a number or
underscore). After this up to eight parameters (each of which can be up
to a maximum of 15 characters) can follow which specify the drive which
should be accessed as (for example): flop1\_, ... flop8\_. It is neither
possible to rename a local drive with::

    NFS_USE test,ram1_

(error -12), nor indirectly with NET1::

    NFS_USE test,n1_ram1_

The second example can be entered but any attempted access to test1\_
will lead to a Network aborted message after half a minute of complete
silence.

The second syntax is used to remove a specified set of
definitions (or, if no parameter is supplied, then all definitions will
be removed) which have been created with NFS\_USE.

**Examples**

::

    NFS_USE flop,n2_flp1_,n3_flp1_

creates a device name flop where flop1\_ refers to flp1\_ on QL2 and
flop2\_ to flp1\_ on QL3. NFS\_USE flop clears the above definition.

NFS\_USE without any parameters clears all such definitions.

**NOTE**

Devices can be shared by several remote QLs. Although a file can be read
by several jobs (or QLs) at the same time, QDOS will ensure that a file
cannot be opened by one job (or QL) for writing to whilst another is
trying to read from it (or vice versa). If this occurs, then an error -9
(IN USE) will be reported.

**CROSS-REFERENCE**

QRD renames any local device. See also
:ref:`flp-use`,
:ref:`ram-use` and
:ref:`dev-use`.
:ref:`midinet` and
:ref:`sernet` set up similar fileservers to
:ref:`fserve` -
:ref:`nfs-use` can be used with these fileservers
also, provided that you use :ref:`snet-use` n or :ref:`mnet-use` n to ensure that they are identified by the letter n.

--------------


