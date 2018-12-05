..  _del-defb:

DEL\_DEFB
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEL\_DEFB                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II                                                       |
+----------+-------------------------------------------------------------------+

QDOS stores information concerning devices and files (and in relation
to files, even their contents) in areas of memory known as 'slave
blocks' (memory permitting). These slave blocks can be very useful,
since when the computer tries to access the same device (or file) again,
the access is much quicker, since the relevent details can be loaded
from memory, rather than the device - the computer only need look at the
device to make certain that it is the same device (or disk) as was
previously used.

There are three problems with the use of these slave
blocks:

- The initial device access is slowed down as all of the
  information is effectively read twice - once into memory and once into
  the program.

- Some disk drives do not support a means of checking if a
  disk has been amended on a second computer since the last access -
  meaning that the old version of the information stored in the slave
  blocks can be loaded instead

- On some hard-disks, the hard-disk itself
  may not have been altered (you may need to use a command such as
  WIN\_FLUSH).

The command DEL\_DEFB can assist with the second of these
problems, by deleting all of the slave blocks from memory. Another
problem which can be assisted by DEL\_DEFB is 'heap fragmentation'. To
keep memory tidy, there is an internal list which says where to find
which pieces of information. These lists reserve memory and can lead to
the phenomenon known as heap fragmentation. The following example
demonstrates this::

    PRINT FREE_MEM
    a=ALCHP(10000)
    b=ALCHP(10000)
    PRINT FREE_MEM
    RECHP a
    PRINT FREE_MEM

First, we noted how much memory is free and then we reserved 20000
bytes of memory in two steps. So there are now 20000 bytes of free
memory less. Now, we release the first 10000 bytes and look again at the
free memory: it has not actually increased as much as you would have
thought! Actually, the memory isn't lost. FREE\_MEM returns the largest
piece of free memory in RAM. A further ALCHP(10000) would not reduce
FREE\_MEM in the above example.

Maybe an illustration would make memory management clearer::

    free memory          |-------------------------|
    ALCHP(10000)         |######|------------------|
    ALCHP(10000)         |######|######|-----------|
    release first block  |======|######|-----------|

Key::

    -- : free memory (returned by FREE_MEM)
    ## : reserved memory
    == : free memory (used for ramdisks)

The
above-mentioned internal list allocates a small piece of memory which
may reduce the largest piece of free RAM available to certain operations
which draw large chunks of memory at a time, causing them to fail (out
of memory), even though there would be enough memory had the 'drive
definition blocks' not fragmented it. The command DEL\_DEFB clears these
blocks, thus helping to relieve the heap fragmentation.


**NOTE**

Because DEL\_DEFB deletes the slave blocks, future device accesses will
be slowed!


**WARNING**

Do not use DEL\_DEFB if any channels are open to a file.


**CROSS-REFERENCE**

:ref:`rechp`, :ref:`clchp`,
:ref:`release`,
:ref:`free-mem`, :ref:`free`.
Dynamic RAM disks use effectively all of the free memory.
:ref:`format` lists other ways of causing heap
fragmentation.

--------------


