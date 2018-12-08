..  _pth-add:

PTH\_ADD
========

+----------+-------------------------------------------------------------------+
| Syntax   |  PTH\_ADD [n,] directory                                          |
+----------+-------------------------------------------------------------------+
| Location |  Path device                                                      |
+----------+-------------------------------------------------------------------+

First we need to explain the PTH device before you can understand what
the command PTH\_ADD and its related commands/ functions do.

Using sub-directories helps to clean up disk storage - even if you know on
which disk a file is kept, if you are using a large storage media like
HD/ED disks or even hard disks, you will soon find yourself searching
through the whole directory tree with a desktop or WDIR. That's why PTH
was created.

This virtual device interfaces with any kind of drive and
searches through a list of directories when a file is to be opened. For
instance, instead of being forced to type::

    VIEW win1_games_defender_manual_txt

a short::

    VIEW pth1_manual_txt


would be enough to show the manual\_txt if the directory
win1\_games\_defender\_ is in the path list.

The size of the search list
is only limited by memory available; a list of 30000 entries has been
tested, 900k was necessary to store it - but this is not a realistic
limitation. Who works with several thousand directories?

PTH\_ADD modifies that list which can have as many entries as necessary.

PTH\_ADD (the name says it already) adds a directory to the path list, it can be
inserted (you cannot replace pathnames!) at a certain position by
directly specifying the position n (a non-negative integer) in the list.

If n is not specified, the new directory is merely added to the end of
the list. The example will clarify this.

**Example**

We assume the path list is empty.

::

    PTH_ADD flp1_

will add flp1\_ to the list which will now look like this (the list can
be obtained with::

    PTH_LIST

::

    0 flp1_

The first column is the number of the entry, programmers tend to start
counting with zero, that's why the first entry has the number 0. If you
type, for example::

    SPL pth1_pth_bin,#1

the binary file pth\_bin in flp1\_ will be spooled to channel #1
(usually a window under the interpreter).

Now let's add a few more entries to exploit the power of the path device::

    PTH_ADD flp1_basic_
    PTH_ADD flp2_
    PTH_ADD ram1_

The list is now::

    0 flp1_
    1 flp1_basic_
    2 flp2_
    3 ram1_

Assume the file myprog\_bas is in ram1\_::

    LOAD pth1_myprog_bas

tries to load the following files one by one and skips to the next one
in case of failure:

- flp1\_myprog\_bas
- flp1\_basic\_myprog\_bas
- flp2\_myprog\_bas
- ram1\_myprog\_bas

If myprog\_bas does not appear in any of the directories, the usual
'Not Found' error would appear.

**NOTE 1**

The name of the path device can be freely configured with the Qjump
standard configuration program Config (or MenuConfig). We use the
default in this manual, which is PTH. The name can be changed
temporarily with PTH\_USE.

**NOTE 2**

PTH suffers from the same problem as the DEV device, see the note at
DEV\_USE.

**NOTE 3**

An underscore is added to the directory if it's missing. On this point
PTH\_ADD behaves differently from DEV\_USE.

**WARNING**

Some applications do not co-operate happily with PTH so that a file may
get spread over all directories if you save it from some editors etc.
There are no crashes, do not worry, but this strange behaviour could
lead to a loss of data if you are not aware of the strange phenomenon.

**CROSS-REFERENCE**

The path device is very similar to the dev\_
device, please read through :ref:`dev-use` to
understand the idea behind both devices. It's pretty useful to set the
Toolkit II :ref:`datad-dlr` and
:ref:`progd-dlr` to pth1\_::

    DATA_USE pth1_
    PROG\_USE pth1_

Do this preferably in your
BOOT program. - Look at the other 'PTH_XXX' keywords starting at :ref:`pth-add`!
