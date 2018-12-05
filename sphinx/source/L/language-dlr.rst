..  _language-dlr:

LANGUAGE$
=========

+----------+------------------------------------------------------------------+
| Syntax   | LANGUAGE$  or                                                    |
|          |                                                                  |
|          | LANGUAGE$ (code)(SMS only)                                       |
+----------+------------------------------------------------------------------+
| Location | THOR range of computers, SMS                                     |
+----------+------------------------------------------------------------------+

This function returns a string representing the current language layout
of the keyboard which is linked into the QL. Unfortunately, the string
returned is different on THORs and SMS's. For a list of the strings
returned on THOR computers, see :ref:`set-language`. Under SMS the string
returned is the international car registration code for the language
currently loaded (if code is not specified). The second variant returns
the car registration code of the language which would be used if the
language represented by code
was installed using LANG\_USE (in which case code can be either the
international dialling code or the car registration code).

**CROSS-REFERENCE**

:ref:`set-language` allows you to alter
the current keyboard. See also :ref:`language`
and :ref:`lang-use`.

--------------


