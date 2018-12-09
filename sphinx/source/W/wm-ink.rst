..  _wm-ink:

WM\_INK
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_INK [#channel,] palette\_index                               |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.00                                                  |
+----------+-------------------------------------------------------------------+

Newer Window Managers maintain a table of colour settings for programs to use
as “standard colours”. This is called the *System Palette*, also known as a
‘colour theme’. Four system palette tables, or themes, are supplied with the
operating system.

The list is sorted by *usage* rather than *colour* and includes colour values
to be used for display items such as window background, border, loose items and
so on. The items are referenced by a 4-digit hex number (16-bit value) as per
the list below, or the decimal number equivalent. These numbers should not be
used in standard :ref:`ink`, :ref:`paper` and :ref:`border` statements – they are not colour values,
merely an index to an entry in a list of colour values. They should be used with
the WM_x equivalent commands, which will look up the colour values to be
used for the item numbers in the list.

WM\INK sets the ink colour for the channel indicated to the colour for the
specified item number from the system palette.

+---------+-------------------------------------------------+
| Number  | Meaning                                         |
+---------+-------------------------------------------------+
| $0200   | Window border                                   |
+---------+-------------------------------------------------+
| $0201   | Window background                               |
+---------+-------------------------------------------------+
| $0202   | Window foreground                               |
+---------+-------------------------------------------------+
| $0203   | Window middleground                             |
+---------+-------------------------------------------------+
| $0204   | Title background                                |
+---------+-------------------------------------------------+
| $0205   | Title text background                           |
+---------+-------------------------------------------------+
| $0206   | Title foreground                                |
+---------+-------------------------------------------------+
| $0207   | Loose item highlight                            |
+---------+-------------------------------------------------+
| $0208   | Loose item available background                 |
+---------+-------------------------------------------------+
| $0209   | Loose item available foreground                 |
+---------+-------------------------------------------------+
| $020a   | Loose item selected background                  |
+---------+-------------------------------------------------+
| $020b   | Loose item selected foreground                  |
+---------+-------------------------------------------------+
| $020c   | Loose item unavailable background               |
+---------+-------------------------------------------------+
| $020d   | Loose item unavailable foreground               |
+---------+-------------------------------------------------+
| $020e   | Information window border                       |
+---------+-------------------------------------------------+
| $020f   | Information window background                   |
+---------+-------------------------------------------------+
| $0210   | Information window foreground                   |
+---------+-------------------------------------------------+
| $0211   | Information window middleground                 |
+---------+-------------------------------------------------+
| $0212   | Subsidiary information window border            |
+---------+-------------------------------------------------+
| $0213   | Subsidiary information window background        |
+---------+-------------------------------------------------+
| $0214   | Subsidiary information window foreground        |
+---------+-------------------------------------------------+
| $0215   | Subsidiary information window middleground      |
+---------+-------------------------------------------------+
| $0216   | Application window border                       |
+---------+-------------------------------------------------+
| $0217   | Application window background                   |
+---------+-------------------------------------------------+
| $0218   | Application window foreground                   |
+---------+-------------------------------------------------+
| $0219   | Application window middleground                 |
+---------+-------------------------------------------------+
| $021a   | Application window item highlight               |
+---------+-------------------------------------------------+
| $021b   | Application window item available background    |
+---------+-------------------------------------------------+
| $021c   | Application window item available foreground    |
+---------+-------------------------------------------------+
| $021d   | Application window item selected background     |
+---------+-------------------------------------------------+
| $021e   | Application window item selected foreground     |
+---------+-------------------------------------------------+
| $021f   | Application window item unavailable background  |
+---------+-------------------------------------------------+
| $0220   | Application window item unavailable foreground  |
+---------+-------------------------------------------------+
| $0221   | Pan/scroll bar                                  |
+---------+-------------------------------------------------+
| $0222   | Pan/scroll bar section                          |
+---------+-------------------------------------------------+
| $0223   | Pan/scroll bar arrow                            |
+---------+-------------------------------------------------+
| $0224   | Button highlight                                |
+---------+-------------------------------------------------+
| $0225   | Button border                                   |
+---------+-------------------------------------------------+
| $0226   | Button background                               |
+---------+-------------------------------------------------+
| $0227   | Button foreground                               |
+---------+-------------------------------------------------+
| $0228   | Hint border                                     |
+---------+-------------------------------------------------+
| $0229   | Hint background                                 |
+---------+-------------------------------------------------+
| $022a   | Hint foreground                                 |
+---------+-------------------------------------------------+
| $022b   | Hint middleground                               |
+---------+-------------------------------------------------+
| $022c   | Error message background                        |
+---------+-------------------------------------------------+
| $022d   | Error message foreground                        |
+---------+-------------------------------------------------+
| $022e   | Error message middleground                      |
+---------+-------------------------------------------------+
| $022f   | Shaded area                                     |
+---------+-------------------------------------------------+
| $0230   | Dark 3D border shade                            |
+---------+-------------------------------------------------+
| $0231   | Light 3D border shade                           |
+---------+-------------------------------------------------+
| $0232   | Vertical area fill                              |
+---------+-------------------------------------------------+
| $0233   | Subtitle background                             |
+---------+-------------------------------------------------+
| $0234   | Subtitle text background                        |
+---------+-------------------------------------------------+
| $0235   | Subtitle foreground                             |
+---------+-------------------------------------------------+
| $0236   | Menu index background                           |
+---------+-------------------------------------------------+
| $0237   | Menu index foreground                           |
+---------+-------------------------------------------------+
| $0238   | Separator lines etc.                            |
+---------+-------------------------------------------------+

**Example**

::

    WM_INK #1,$206

Sets the foreground colour in #1 to the title window foreground.

**CROSS-REFERENCE**

See :ref:`wm-paper`,
:ref:`wm-strip`,
:ref:`wm-border`,
:ref:`wm-block`.

