..  _hot:

HOT
===

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT key, executable\_file                                        |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command will load the given executable job into memory and start
it running from memory each time that the specified key (together with
<ALT>) is pressed, so there will not be any need to access the drive,
but the code has to be stored twice: once as the code loaded by HOT, and
then the job created from that code. Thus it is only practical to load
small programs such as system utilities with this command.

**Examples**

::

    HOT c,FLP1_COLOURS_exe
    HOT s,FLP1_tk2flp
    HOT "4",FLP1_QED

**NOTE 1**

Any ALTKEY definitions which use the same hotkeys will be ignored.

**NOTE 2**

Non-standard machine code cannot be used (Supercharged or Turbo compiled
SuperBASIC for instance): the code has to be re-entrant, ie. when the
job stops it should disappear. Jobs which relocate themselves, redefine
the trap table, change their own code (ie. are not ROMable), or can only
be started one at a time, tend to produce system crashes and other
problems.

**WARNING**

Memory used by HOT-loaded programs cannot always be freed for use by
SuperBASIC.

**CROSS-REFERENCE**

:ref:`clear-hot` clears a hotkey defined with
:ref:`hot` and (hopefully!) returns the occupied
memory to QDOS. Use the Hotkey System if you have this available!!

--------------

