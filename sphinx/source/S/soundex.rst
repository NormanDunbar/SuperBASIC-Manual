..  _soundex:

SOUNDEX
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  SOUNDEX (word$)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Ähnlichkeiten                                                    |
+----------+-------------------------------------------------------------------+

This function returns an integer which represents the word contained in the string passed as a parameter, in
such a way that for two English words which sound similar, the same
results are returned. Internally, each character is replaced by a cipher
and then all double (triple etc) ciphers are removed.

**Examples**

::

    SOUNDEX ("user"): REMark 26
    SOUNDEX ("looser"): REMark 426
    SOUNDEX ("l'user"): REMark 426

**NOTE**

The difference between two SOUNDEX results is not proportional to the
phonetic difference between the parameters.

**CROSS-REFERENCE**

:ref:`wld` calculates such a difference,
:ref:`phonem` is similar to
:ref:`soundex`.

--------------


