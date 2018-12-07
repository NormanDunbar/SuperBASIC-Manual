..  _tteopen:

TTEOPEN
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  TTEOPEN (#channel [,openmode], device$)                          |
+----------+-------------------------------------------------------------------+
| Location |  QView Tiny Toolkit                                               |
+----------+-------------------------------------------------------------------+

The TTEOPEN function opens the specified #channel to any device given
as a string. The type of open is optional and ranges from 0 to 4 - the
meaning is the same as for Minerva's extended OPEN or FILE\_OPEN. If
TTEOPEN is called from the interpreter (Multiple BASICs included) then
channel must either be an existing channel number (which would be then
closed by TTEOPEN prior to being reopened) or lower than the highest
channel number currently used: TTEOPEN will break with 'bad parameter'
if that is not the case.

**CROSS-REFERENCE**

:ref:`open`, :ref:`file-open` and the various FOP_XXX keywords.

