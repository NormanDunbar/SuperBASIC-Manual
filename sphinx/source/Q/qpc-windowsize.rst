..  _qpc-windowsize:

QPC\_WINDOWSIZE
===============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_WINDOWSIZE x, y                                              |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This sets the size of the client area (the part that displays SMSQ/E) of the QPC window. It does NOT alter the resolution SMSQ/E runs with, so the pixels are effectively zoomed. It is equivalent to the "window size" option in the main configuration window. If QPC is currently in full screen mode it will switch to windowed mode. Window size cannot be set smaller than the SMSQ/E resolution or bigger than the desktop resolution.

**Example**

::

    DISP_SIZE 512,256
    QPC_WINDOWSIZE 1024,512

Does a 200% zoom of the QPC window.

