..  _get-stuff-dlr:

GET\_STUFF$
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  GET\_STUFF$                                                      |
+----------+-------------------------------------------------------------------+
| Location |  GETSTUFF                                                         |
+----------+-------------------------------------------------------------------+

The Hotkey System II uses the keys <ALT><SPACE> and <ALT><SHIFT><SPACE>
to type into the current keyboard buffer the contents of a certain piece
of memory, known as the Hotkey Stuffer Buffer. The command HOT\_STUFF
text$ puts text$ into this buffer.

The function GET\_STUFF$ returns the
contents of the hotkey stuffer or "0" if it does not contain anything.
If the FILES Thing of QPAC2 is present, this will be started first,
prior to returning the stuffer contents. This means that a program can
easily ask for a filename - just by calling GET\_STUFF$.

**NOTE**

GET\_STUFF$ returns cryptic numbers in unusual circumstances, for
example::

    HOT_STUFF ""
    PRINT GET_STUFF$

**WARNING**

This function crashes SMSQ/E and Minerva when you Quit the Files Menu of
QPAC 2.

**CROSS-REFERENCE**

See :ref:`hot-stuff`.

