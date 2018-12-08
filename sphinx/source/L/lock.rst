..  _lock:

LOCK
====

+----------+-------------------------------------------------------------------+
| Syntax   |  LOCK file,code$,code                                             |
+----------+-------------------------------------------------------------------+
| Location |  CRYPTAGE                                                         |
+----------+-------------------------------------------------------------------+

This command encodes the given file (the full filename must be stated)
using two codes, a string and a number, for security. Code$ can be any
string and the code number (an integer) must range between 0 and 32767.
Decoding with UNLOCK is only possible if both codes are known, so do not
forget them otherwise the file will be lost.

**Example**

LOCK ram1\_secret\_txt,"Phew",7241

**CROSS-REFERENCE**

:ref:`unlock` has the same syntax as
:ref:`lock` but deciphers
:ref:`lock`\ ed files.

