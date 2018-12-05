..  _qpc-syncscrap:

QPC\_SYNCSCRAP
==============

+----------+-------------------------------------------------------------------+
| Syntax   | QPC\_SYNCSCRAP                                                    |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

In order to rapidly exchange text passages between Windows and SMSQ/E the Syncscrap functionality has been introduced. The equivalent of the Windows clipboard is the scrap extension of the menu extensions.

After loading the menu extensions you can call this command, which creates a job that periodically checks for changes in either the scrap or the Windows clipboard, and synchronizes their contents if necessary. Please note that only text data is supported. The character conversion between the QL character set and the Windows ANSI set is done automatically. The line terminators (LF or LF+CR) are converted too.

--------------


