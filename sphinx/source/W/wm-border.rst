..  _wm-border:

WM\_BORDER
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  WM\_BORDER [#channel,] palette\_index                            |
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
the list under the entry for :ref:`wm-ink`, or the decimal number equivalent.
These numbers should not be used in standard :ref:`ink`, :ref:`paper` and :ref:`border` statements –
they are not colour values, merely an index to an entry in a list of colour
values. They should be used with the WM_x equivalent commands, which will look
up the colour values to be used for the item numbers in the list.

WM\_BORDER sets the border colour for the channel indicated to the colour for the
specified item number from the system palette.

**Example**

::

    WM_BORDER #1,$20e

Sets the border colour in #1 to the information window border colour from the
current system palette.

**CROSS-REFERENCE**

See :ref:`wm-ink`,
:ref:`wm-paper`,
:ref:`wm-strip`,
:ref:`wm-block`.

