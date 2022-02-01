..  _ckeyon:

CKEYON
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CKEYON [#channel]                                                |
+----------+-------------------------------------------------------------------+
| Location |  Pointer Interface (v1.23 or later)                               |
+----------+-------------------------------------------------------------------+

See :ref:`ckeyoff`.

**NOTE**

There were problems with this command prior to v1.56.

In v2.06 if no channel number is given, and there is no default channel #0, a new 
"ghost" channel is opened on every call to CKEYOFF or CKEYON.

