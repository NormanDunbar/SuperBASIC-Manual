..  _extras:

EXTRAS
======

+----------+------------------------------------------------------------------+
| Syntax   | EXTRAS [#channel] or                                             |
|          |                                                                  |
|          | EXTRAS \\file (Toolkit II, THOR only)  or                        |
|          |                                                                  |
|          | EXTRAS [#channel][,width] (BTool only)                           |
+----------+------------------------------------------------------------------+
| Location | Toolkit II, THOR XVI, QSound, BTool                              |
+----------+------------------------------------------------------------------+

This command lists all of the machine code Procedures and Functions
(keywords) which are recognised by the SuperBASIC interpreter in the
given channel (default #1), or the given file (if the second variant is
used), which will be automatically opened and even overwritten if it
already exists (after asking the user to confirm that this is okay).

The file will be closed at the end of the operation.

The THOR XVI version
will not list those keywords which are resident in ROM (ie. available
when the THOR is first powered up).

The BTool version lists the keywords
in columns and as such is the same as EXTRAS\_W. The number of columns
is adapted automatically to a window's width; if this is too wide for
your needs then you can specify a width in characters.

The QSound
variant is intended for output to a non-screen channel (see WIDTH), in
which case an empty line appears between each name. If output is sent to
a window, then the words are all printed on the same line, obscuring
output.

**NOTE 1**

BTool's EXTRAS does not support the SuperBASIC WIDTH command and you
will therefore need to specify an absolute width as the second parameter
to format output.

**NOTE 2**

Versions of Tiny Toolkit pre v1.10 contained a different implementation
of this command, now renamed TXTRAS.

**NOTE 3**

Within an SBASIC (on SMS), EXTRAS only lists those keywords used in that
SBASIC to date - this is because the whole name table is not copied when
an SBASIC is started up, allowing different SBASICs to use the same name
for different things.

**CROSS-REFERENCE**

Use :ref:`sxtras` if you have a lot of extensions
in memory and you are looking for a specific one. See also
:ref:`txtras`, :ref:`vocab` and
:ref:`new-name`.

--------------


