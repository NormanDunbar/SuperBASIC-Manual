..  _hot-thing:

HOT\_THING
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_THING (key$,Thingname$ [;cmd$] [,Jobname$] )                |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The function HOT\_THING allows you to define a hotkey which will start
up a new copy of an Executable Thing whenever the hotkey is pressed (if
the Thing is present at that stage). You can pass a command string to
the Executable Thing and even change the name of the Job which will be
created by passing Jobname$.

More and more utilities are being written
for QDOS which are set-up as Executable Things (for example, most of the
menus provided by QPAC2 are in fact Executable Things), which is a means
of providing various resources which a program can make use of (if they
are present).

Executable Things can be seen as an executable program
stored in memory, several copies of which can be started up at any time,
but the same piece of machine code will be used by all of the copies,
meaning that very little memory is required for each additional copy.

**Example**

::

    ERT HOT_CHP('p',flp1_Perfection,'Perfection WP')
    ERT HOT_THING('P','Perfection WP')

Both <ALT><p> and <ALT><P> will now have the same effect.

**NOTE 1**

Thingname$ should contain the full name of the Thing, otherwise it will
not be recognised.

**NOTE 2**

Versions of the Hotkey System prior to v2.21 do not allow you to pass a
command string. You also need v2.24+ to pass a job name.

**CROSS-REFERENCE**

:ref:`hot-chp` and
:ref:`hot-res` turn a file into an Executable
Thing. :ref:`thing` allows you to test if a Thing is
present.

