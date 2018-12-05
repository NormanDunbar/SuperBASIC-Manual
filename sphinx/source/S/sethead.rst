..  _sethead:

SetHEAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  SetHEAD #ch, adr                                                 |
+----------+-------------------------------------------------------------------+
| Location |  HEADER (DIY Toolkit - Vol F)                                     |
+----------+-------------------------------------------------------------------+

The command SetHEAD is the counterpart of GetHEAD and is normally used
in conjunction with it. So please refer to GetHEAD for further
information about the syntax and usage. There is just one difference you
must keep in mind: whilst GetHEAD does not care in which mode (read only
or read and write) a file was opened, SetHEAD does. It expects that the
channel was opened with OPEN, FOPEN etc but not with OPEN\_IN or
FOP\_IN.

**CROSS-REFERENCE**

See :ref:`gethead`.

--------------


