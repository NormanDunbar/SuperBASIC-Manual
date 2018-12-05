..  _language:

LANGUAGE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  LANGUAGE [(code)]                                                |
+----------+-------------------------------------------------------------------+
| Location |  SMS                                                              |
+----------+-------------------------------------------------------------------+

This function returns a number representing the international dialling
code for the current language implementation (if code is not specified).
Otherwise it will return the dialling code of the language which would
be used if the language represented by code was installed using
LANG\_USE (in which case code can be either the international dialling
code or the car registration code).

**CROSS-REFERENCE**

:ref:`language-dlr` returns the car registration
code. :ref:`lang-use` allows you to set the
language for the messages.

--------------


