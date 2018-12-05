..  _cbase:

CBASE
=====

+----------+--------------------------+
| Syntax   | CBASE [(#ch)](Btool) and |
|          |                          |
|          | CBASE (#ch)(TinyToolkit) |
+----------+--------------------------+
| Location |  BTool, TinyToolkit      |
+----------+--------------------------+

The function CBASE finds the start address of the channel definition
block which belongs to #ch. This is an area in memory where QDOS stores
a lot of information about the channel, for example, which kind of
device is connected to the channel.

The Btool variant returns the base of channel #1 if #ch is not
specified.

**CROSS-REFERENCE**

The Pointer Interface modifies the structure of channel definition
blocks for windows.

If you want to access these, preferably use
WINCTRL instead of
:ref:`cbase`. See also
:ref:`chbase`.

You can also use the `CHAN\_ <KeywordsC.clean.html#chan_>`\ xx functions to
look at the channel definition block.

--------------


