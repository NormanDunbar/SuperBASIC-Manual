..  _par-getprinter-dlr:

PAR\_GETPRINTER$
================

+----------+-------------------------------------------------------------------+
| Syntax   | name$ = PAR\_GETPRINTER$(port%)                                   |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This returns the PAR port setting: "LPT1", "LPT2" or "LPT3" if it isn't linked to a printer but directly to a printer port or the name of the printer otherwise. An empty string designates the default printer.

--------------


