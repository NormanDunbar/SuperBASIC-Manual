..  _a18-configuring--programs:

18 Configuring Programs
=======================

There are many different ways of allowing a user to configure a program.
In this Appendix, we aim to highlight some of the options available,
together with details of their benefits and pitfalls.

CONFIG Level 1 & Level 2
------------------------

Many people who have used programs written for the Pointer Environment
are used to using the Config program written by Qjump, or the MenuConfig
program from Jochen Merz Software to configure programs.

These programs work by searching the program to be configured for a
special 'config block', which has to have a special format.

If a program is written in 'C' or Machine Code, it is fairly easy to
create a config block following the rules set out in the QPtr Toolkit
manual.

However, many programmers find it much easier to create a program in
compiled SuperBASIC. The only way of adding these config blocks to a
compiled program is to use the Public Domain program BASCONFIG which can
be linked into the program at compile time. This package creates a user
defined config block which can be read using new SuperBASIC keywords
.....

Unfortunately, BASCONFIG cannot be used with Turbo compiled programs as
this does not allow toolkits to be linked to a compiled program.

Level 2 Config blocks allow automatic configuration of a new version of
a program. The BASCONFIG package does not support these type of config
blocks.

Passing Parameter with EXEC
---------------------------

If only one or two configuration options are required (such as where a
program should look for a specific file), then it is sometimes easier to
pass these parameters as an option string with the EXEC command (or
similar).

The problem here is that it is all too easy to forget to include this
string when starting up a program and many programs allow a long
complicated list of parameters to be set in this way.

The option string can be read with functions such as OPTION\_CMD$ or
CMD$.

Making the configuration part of the program.
---------------------------------------------

This means that the program must be loaded to be configured and then
possibly reloaded into the machine for the configuration to take effect.

This makes the program bigger for something that may only be used once.

It is also more difficult to have several configurations of the same
program.

Using a separate configuration file.
------------------------------------

The problem here is how do you tell the main program where to load the
configuration file from!

Using Environment Variables
---------------------------

This is OK, but user may forget to set the initial Environment Variable.

DATA\_USE etc
-------------

The problem is that they can be altered externally by other programs.
Only one setting at a time is possible.
