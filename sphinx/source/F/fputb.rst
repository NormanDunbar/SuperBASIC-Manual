..  _fputb:

FPUTB
=====

+----------+--------------------------------------------------------------------------------------------------+
| Syntax   |  FPUTB [#ch,] {byte \| string$} :sup:`\*`\ [,{byte\ :sup:`i` \| string\ :sup:`i`\ $}]\ :sup:`\*` |
+----------+--------------------------------------------------------------------------------------------------+
| Location |  BTool                                                                                           |
+----------+--------------------------------------------------------------------------------------------------+

FPUTB is a command which writes single or multiple bytes to a channel
#ch (default #1). FPUTB can take any kind of parameters which must be
either a numeric value byte in the range 0..255 for a single byte, in
the range 256..32767 for two bytes or a string string$.

**Example 1**

::

    CLS: FPUTB "First line",10,"Second line"
    CLS: FPUTB "First line",2570,"Third line"

because CVI% (CHR$ (10) & CHR$ (10) ) = 2570)
which is (10 * 256) + 10 in big-endian format, as the QL is.

**Example 2**

FPUTB is very handy for controlling printers::

    OPEN#3,par
    FPUTB#3,27,"x",1
    CLOSE#3

will enable near letter quality (NLQ) on an EPSON compatible printer.

**CROSS-REFERENCE**

:ref:`bput`, :ref:`chr-dlr`,
:ref:`code`. :ref:`fgetb` is a
complementary function.

--------------


