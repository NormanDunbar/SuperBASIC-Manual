..  _new-name:

NEW\_NAME
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  NEW\_NAME old\_name$, new\_name$                                 |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command allows all keywords, variables, procedures, functions and
device names to be renamed, whether they are in RAM or ROM (except
device names, which must be RAM based), BASIC or machine code
implementations. If a program is loaded when the command is issued, then
all references in that program to the given name will also altered.

**Examples**

- FORMAT can destroy a lot of data. To avoid a catastrophe when an
  alien, unknown BASIC program formats your hard disk for example, you
  could rename FORMAT::

    NEW_NAME "FORMAT" TO "FORMAT_MEDIUM"

  Note that you would need to issue this command before loading the
  program!

- Creating algorithms is very easy and fast in SuperBASIC,
  especially if short variable names like i ,n, q1 are used. But even the
  author him/herself may have difficulty in understanding source code full
  of such meaningless names. The obvious solution: Rename them! - for
  example::

    NEW_NAME "d","dog"

  BASIC programs loaded in memory are amended completely and permanently - at once.

- If you prefer to see all names in capital letters, run this short program::

    100 adr=BASICP(32)
    110 REPeat all_names
    120   length=PEEK(adr)
    130   IF NOT length THEN EXIT all_names
    140   name$=PEEK$(adr+1,length)
    150   NEW_NAME name$,UPPER$(name$)
    160   adr=adr+length+1
    170 END REPeat all_names

**NOTE**

A name may be up to 255 characters long, and because it is only stored
once (in the name table) and represented in a tokenised program by
symbols pointing to the name table, the actual speed of operation will
not be slowed down by using longer names.

**WARNING**

It is possible to rename FORMAT to FORMAT! (for example) but FORMAT! is
an illegal name, can no longer be called from BASIC and may crash some
advanced implementations of SuperBASIC.

**CROSS-REFERENCE**

:ref:`zap` and :ref:`key-rmv`
remove a resident keyword. See :ref:`replace` and
:ref:`alias` as well.
