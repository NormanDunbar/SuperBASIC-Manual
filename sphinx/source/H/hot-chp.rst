..  _hot-chp:

HOT\_CHP
========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_CHP (key$,filename [;cmd$] [,JobName$] [,options])          |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The main idea behind the Hotkey System II is that you can have access
to any number of QL programs by pressing one simple hotkey in order to
access each program, rather than having to use <CTRL><C> to cycle
through all of the programs currently stored in the QL's memory.

The function HOT\_CHP will load an executable file with the specified
filename into the common heap and make it into an Executable Thing. Now,
each time that you press <ALT> plus the specified key$, a new copy of
the program will be started up in memory (although the same code is
used, meaning that very little memory is used by each additional copy).

As from v2.03 of Hotkey System II, if you use an upper case key$, then
you will need to press the upper case character, compare where you use a
lower case key$, which will recognise both the upper and lower case
character (if the upper case character has not been assigned to another
hotkey).

HOT\_CHP will support the current program default device if
Toolkit II is loaded, otherwise it will use its own default device which
can be configured by using the program CONFIG on the file HOT\_REXT.

When the program is loaded using this command, HOT\_CHP will look to see
whether the start of the program contains a Job name, if not, then the
program file name is used as the Job name (unless an alternative is
stipulated, using the Jobname$  parameter).

As with EXEP, you can pass a command string to the program
which will be passed to each copy of the program as and when they are
started up. You can also supply a specific Job name for the program and
pass various options to the Pointer Interface to tell it how to treat
the program. As well as those options supported by EXEP, the following
option is also supported:

- -I This tells the Hotkey System that the program code is 'impure'
  (ie. it modifies its own code). This means that
  code cannot be shared by every copy of the program - this therefore
  means that each time that the program is called, a copy of the original
  code is made from which the program runs. For this reason, you should
  consider using HOT\_LOAD for such programs. The most common programs
  which fall within this category have been written under BCPL or compiled
  with Supercharge or Turbo.

If the program is successfully loaded into
memory and set up as an executable Thing, HOT\_CHP will return 0,
otherwise one of the following error codes will be returned:

- -2 Specified filename is not executable
- -3 Not enough memory to load the file
- -7 The specified filename cannot be found
- -9 The specified hotkey has already been defined, or the file is in use.
- -12 The specified filename is not supported (bad filename).

**NOTE 1**

Any programs which are to be loaded into the Hotkey System II should be
re-entrant so that the same code can be shared by any number of copies
of the program, otherwise label them as Impure.

**NOTE 2**

Versions of the Hotkey System pre v2.21 do not allow you to pass a
command string.

**WARNING**

You should not specify a Job name for impure programs as this may cause
problems.

**CROSS-REFERENCE**

If you do not intend to remove the program in the future, use
:ref:`hot-res` or
:ref:`hot-res1` as these will ensure that the
program starts up more quickly. :ref:`hot-chp1`,
:ref:`hot-load`,
:ref:`hot-load1` are similar. The hotkey will
not be available until you enable the Hotkey System with HOT\_GO.

--------------


