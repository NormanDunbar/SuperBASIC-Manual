..  _th-ver-dlr:

TH\_VER$
========

+----------+-------------------------------------------------------------------+
| Syntax   |  TH\_VER$ (thingname$)                                            |
+----------+-------------------------------------------------------------------+
| Location |  Fn                                                               |
+----------+-------------------------------------------------------------------+

Things in QDOS terms refer to an extension of QDOS which was introduced
by the Thing System provided by Qjump's Extended Pointer Interface and
was also implemented (although slightly differently) on the THOR XVI
computer. It is an universal storage method for named resources.

A Thing
List is created by the Thing System which lists all of these named
resources, which can range from a piece of machine code to a printer
driver (and much more). The idea is that any program which wants to
access a specified utility or driver need only search in this list to
see if the Thing is installed in the current system, and then pointers
contained in this list allows the program to access the Thing (if
available).

Each Thing can be usable by several users at the same time
or can be restricted so that it can only be accessed if nothing else is
using it. Things are identified by their name and have a version number
which is returned by the function TH\_VER$. The version number of a
Thing can be something like 1.03, or it can actually be representative
of the functions provided in this version (eg. 1001100) - although it is
not certain if this second type of 'version number' will be correctly
returned by the current version of TH\_VER$, since at the time of
writing we have not come across anything which uses this.

If a Thing was
not found in memory or another error occurred, TH\_VER$ will return the
standard error code (see ERNUM).

**Example**

The Hotkey System (HOT\_REXT), a part of the Extended Pointer
Environment (regarded as standard today), is installed as a Thing. Get
its version with::

    PRINT TH_VER$ ("HOTKEY")

**NOTE 1**

In versions prior to version 1.02, this function could return the wrong
value for some Things.

**NOTE 2**

The current version of this command will not work on a THOR XVI
computer.

**CROSS-REFERENCE**

:ref:`thing`, :ref:`th-fix`.

