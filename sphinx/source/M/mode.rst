..  _mode:

MODE
====

+----------+---------------------------------------------------------------------------------+
| Syntax   | MODE mode%  or                                                                  |
|          |                                                                                 |
|          | MODE screen\_mode [,display\_type] (Minerva, Q-Emulator, Amiga-QDOS v3.23+)  or |
|          |                                                                                 |
|          | MODE [screen\_mode [,display\_type]](PEX only)                                  |
+----------+---------------------------------------------------------------------------------+
| Location | QL ROM, PEX                                                                     |
+----------+---------------------------------------------------------------------------------+

The original QDOS operating system will only recognise two display
modes: Low resolution and High resolution. However, the following MODEs
are currently set aside for use by QDOS compatible systems:

+------+-----------------+---------+--------------------+
| MODE | Resolution      | Colours |  System            |
+======+=================+=========+====================+
| 2    | 640 x 400       | 2       | SMS-2              |
+------+-----------------+---------+--------------------+
| 4    | <=1000 x 400    | 4       | SMS-2              |
+------+-----------------+---------+--------------------+
| 4    | 768 x 280       | 4       | ST/QL, Ext. MODE 4 |
+------+-----------------+---------+--------------------+
| 4    | <=1024 x 1024   | 4       | QVME               |
+------+-----------------+---------+--------------------+
| 4    | <=800 x 600     | 4       | QXL, QXL II, QPC   |
+------+-----------------+---------+--------------------+
| 4    | 512 x 256       | 4       | QDOS and others    |
+------+-----------------+---------+--------------------+
| 8    | 256 x 256       | 8       | QDOS and others    |
+------+-----------------+---------+--------------------+
| 8    | 256 X 256       | 4       | ST/QLs             |
+------+-----------------+---------+--------------------+
| 12   | 256 x 256       | 16      | THOR XVI           |
+------+-----------------+---------+--------------------+

The MODE command is used to select the mode and redraw all windows.
Without Qjump's Window Manager WMAN, the screen mode is set globally,
whereas if WMAN (or SMSQ/E) is installed (this is highly recommended),
MODE will only affect the current job.

The parameter mode% can be any
legal integer between -32768 and 32767. However, to ensure compatibility
with other systems one of the above four values should be used. Normally
if a system does not support the mode type selected, MODE 4 is selected.

The MODE command also resets the current status of UNDER, FLASH, CSIZE
and OVER.

Without specialised software, only one screen mode can be used
at a time (even with the specialised software contained in the Quanta
library, the screen can only be split in two horizontally).

The second
variant is supported on Minerva, Q-Emulator (for the MacIntosh), PEX and
the Amiga QDOS Emulator (v3.23+) and allows you to dictate the type of
display used. The display\_type can be one of four values (the default is -1):

+---------------+---------------------------------------+
| Display\_type | Effect                                |
+===============+=======================================+
| 0             | Set to monitor mode                   |
+---------------+---------------------------------------+
| 1             | Set to TV (625 lines) mode (European) |
+---------------+---------------------------------------+
| 2             | Set to TV (525 lines) mode (American) |
+---------------+---------------------------------------+
| -1            | Leave display type as it is           |
+---------------+---------------------------------------+

On the PEX variant, if you do not specify any parameters, MODE will default to MODE
4,0

**NOTE 1**

Normally, High resolution is described as MODE 4 because this value
represents a characteristic of the mode (4 colours) as well as setting
it. Equally, MODE 8 stands for Low resolution. However, with the ability
of QDOS to access much higher resolution screens, these terms now tend
to be somewhat unnecessary.

**NOTE 2**

Unfortunately for Minerva users who wish to run software in dual screen
mode, current versions of the Pointer Interface do not allow you to have
different MODEs on each of the two screens (the pointer interface fails
to recognise that a program is running on the second screen only and
does not therefore affect the main display screen located at $20000).
Speedscreen may also give problems in Minerva's dual screen mode unless
the 'p' version is used.

**NOTE 3**

If you want to make your programs appear more professional, you should
always seek to cut out unnecessary MODE commands (see RMODE), also
because of the fact that MODE tends to re-draw all of the current
windows (clearing them in their current paper and border colours as it
works), it is always an idea to ensure that all currently opened windows
are set to black paper and black (or no) border before issuing this
command.

**NOTE 4**

On an American JSU QL (which was adapted for use with the American
525-line TV picture, as opposed to the British 625-line TV picture),
only 192 lines of pixels are allowed instead of the normal 256 in MODE 4
and MODE 8 (when the QL is linked to a TV). There are less and less
users using their QL with a TV set nowadays and therefore this can be
largely ignored. In any event, software should generally still run on an
American QL without modification (the lower number of available lines on
the TV screen ensures that pictures still appear to retain the same
height/width ratio).

**NOTE 5**

If you are planning to use the dual screen mode, it is essential that
you ensure that the current screen is also the displayed screen before
opening windows or using the MODE command - see below.

**NOTE 6**

The standard screen modes are MODE 4 and MODE 8. MODE 8 is however only
supported on a limited number of implementations. It is supported by the
original QL, some early ST-QL Emulators and Amiga-QDOS (v3.23+).

**DUAL SCREEN MODE**

Minerva and some other implementations allow you to have two screens
which can both be accessed by the user (and can be switched between by
pressing <CTRL><TAB>). Each of these two screens (if you are in dual
screen mode), can support a different mode. In order to cater for these
new features, screen\_mode is very complex, and to make it worse, it is
important to know which screen is the default screen (see DEFAULT\_SCR).

Programs which use the normal MODE commands will still work under dual
screen mode, since the new version of the MODE
command will only work if the display\_type is specified.

When the QL
is first started, unless you choose <F3> or <F4> (on Minerva), only one
screen will be available for use by programs, otherwise Minerva is
placed into Dual Screen Mode.

In the dual screen mode, after starting up
the QL, the default screen is scr0 (located at $20000 - the normal QL
display screen). The second screen (scr1) is located at $28000 and is
known as the Other Screen.

To make matters worse, each job present in
the QL's memory will be allocated its own default screen, being the
current default when it was started. A job can therefore alter its own
current default screen without upsetting the rest of the system.

Before proceeding any further it is important to realise that the Displayed
Screen (what you can see on your TV/monitor) and the Default Screen are
not necessarily one and the same thing. Oh, it is also important to know
that a screen can also be either visible or blank (this is so that work
can be prepared on a screen without the user being able to see the
process). Perhaps some definitions might help:

Displayed Screen:
    This is the screen which is currently in front of the user on his/her monitor or TV.

Default Screen:
    The screen on which a program's windows will be opened and upon which the normal MODE 4 and MODE 8 commands will have an effect.

Other Screen:
    The opposite to the Default Screen (ie. if the Default Screen is scr0, then the Other Screen will be scr1).

Visible Screen:
    This means that the specified screen can actually be seen by the user.

Blank Screen:
    The specified screen is invisible to the user (allows background work to be carried out).

That's the definitions out of the way, and hopefully, they will provide a better understanding of what is to follow. The command::

    OPEN#3,scr_448x200a32x16

will open a new window on the current Default Screen. After this, any
subsequent commands using #3 will be shown on that screen (whether or
not it is still the current Default Screen).

Problems may exist with
some Toolkit functions which do not check to see where the screen starts
for the given window, and just assume that the screen starts at $20000.

Unfortunately, current versions of Lightning and the Pointer Interface
introduce various problems to the Dual Screen Mode, the most important
one of which is that the screen will not be re-drawn unless the current
screen is also the Displayed Screen.

Another plus to the altered MODE
command is that there is no forced re-draw of all the current windows
unless you specify that this must be carried out (or if you use the
original MODE variants).

In order to try and explain the new display\_mode
parameters, it is easier to split it into two sections: toggling current
values and setting absolute values.

**Toggling the Screen Parameters**

This uses the format MODE 64+n,-1, where:

+----+----------------------------+----------+------------+
| n  | Effect                     | From:    | To:        |
+====+============================+==========+============+
| 1  | Toggle Other Screen        | Visible  | Blank      |
+----+----------------------------+----------+------------+
| 2  | Toggle Default Screen      | Visible  | Blank      |
+----+----------------------------+----------+------------+
| 4  | Toggle Other Screen Mode   | 4-colour | 8-colour   |
+----+----------------------------+----------+------------+
| 8  | Toggle Default Screen Mode | 4-colour | 8-colour   |
+----+----------------------------+----------+------------+
| 16 | Toggle Displayed Screen    | scr0     | scr1       |
+----+----------------------------+----------+------------+
| 32 | Toggle Default Screen      | scr0     | scr1       |
+----+----------------------------+----------+------------+

Adding together different values of n will combine these
effects (although if one of the values is to be 32, the default screen
will be toggled before anything else is carried out).

**Examples**

::

    MODE 64+16,-1: PAUSE: MODE 64+16,-1

Show both screens.

::

    MODE 64+4+8,-1

Toggle the mode of both screens Details of the values used to set
absolute screen parameters appear on the next page.

**Setting Absolute Screen Parameters**

This uses the format MODE -128 + m - 256 \* t + c, -1

where:

- m = k1\*n1 + k2\*n2 + k3\*n3 +...
- t = n1 + n2 + n3 +...n
- c = (see below)
- n can have the same values as above, depending on which effect is to be altered.
- k1, k2, k3 etc. have the following effect upon the corresponding values of n1, n2, n3, etc.


+---+---------------------------+
| k | Sets n to:                |
+===+===========================+
| 0 | The 'from..' column above |
+---+---------------------------+
| 1 | The 'to..' column above   |
+---+---------------------------+

+--------+----------------------------+
| c      | Effect                     |
+========+============================+
| 0      | Do not redraw any screens  |
+--------+----------------------------+
| -16384 | Re-draw the Other Screen   |
+--------+----------------------------+
| 32768  | Re-draw the Default Screen |
+--------+----------------------------+
| 16384  | Re-draw both screens       |
+--------+----------------------------+

Again, different effects can now be combined
with relevant values for each n and k. If you wish to toggle any effects
at the same time, simply add the corresponding value of n to the first
parameter. Some Minerva manuals do not have the correct formula for
calculating these values, which can lead to some peculiar results.
Changing the default screen will again take precedence to all other
changes.

**Dual Screen Examples**

::

    MODE 4

change the Default Screen to MODE 4 and re-draw all currently opened
windows on the Default Screen.

::

    MODE 64+32,-1

toggle current Default Screen.

::

    MODE 64+32+16,-1

toggle current Default Screen and show to user.

::

    MODE -17791,-1

blank out Other Screen and then force it into 4-colour mode, redrawing
all windows, Where does -17791 come from? The formula given above::

    -128 + m - 256*t + c

Into which we substitute the following::

    t = 1 + 4
    m = 1*1 + 0*4
    c = -16384

Care must however be taken when opening channels if the two screens are
in different modes - on versions of Minerva earlier than v1.97, if you
open a channel on the non-Displayed Screen, it will have the
characteristics of a window opened in the mode of the Displayed Screen
(although sadly this does not mean that you can have a MODE 4 window in
the middle of a MODE 8  screen). To ensure that the current Default
Screen is the current Displayed Screen, use::

    MODE -128 + DEFAULT_SCR * 16 - 256 * 16, -1

**Q-EMULATOR NOTE**

Q-Emulator for the Apple MacIntosh computer supports Minerva's dual
screen mode and the extended MODE command.

**AMIGA-QDOS NOTE**

From v3.23, the Amiga-QDOS Emulator also supports Minerva's dual screen
mode and the extended MODE command. Before this version, it did not
support MODE 8. Even now, FLASH is not supported in MODE 8.

**WARNING 1**

Changing the display\_type may have odd effects, especially if Qjump's
Button Frame (part of QPAC2) is present.

**WARNING 2**

On pre JS ROMs, if you open a screen (scr\_) or console (con\_) channel
after a MODE command, the ink and paper colours for the new channel
could both be 0 (black).

**WARNING 3**

On pre Minerva ROMs, MODE alters the value contained in the system
variable SYS.DTYP (also known as SV.TMOD) which normally contains a
value from 0...2 showing the type of TV/Monitor the QL is set up for.
Speedscreen, the Pointer Environment and Lightning all fix this.

**CROSS-REFERENCE**

:ref:`rmode` can be used to read the current screen
mode (and even whether the second screen is available) and
:ref:`default-scr` will tell you which is the
current default screen. :ref:`screen`\ (#3) will
tell you the address of the start of the screen on which window #3 is
situated. :ref:`disp-size` can be used to set
the size of the displayed screen on extended resolutions.

