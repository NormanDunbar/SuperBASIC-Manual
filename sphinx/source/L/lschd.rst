..  _lschd:

LSCHD
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  LSCHD [#ch]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This command lists all scheduler loop tasks with their linked pointers
to the specified channel (default #1). While this text was being
written, the following list was produced::

    List of scheduler loop tasks:
    link pointer routine
    1. $0002B848 $0009E9C0
    2. $0002D140 $000ACC2A
    3. $0002C0F0 $000B685C
    4. $0002B648 $000C1572
    5. $000B3964 $000AFAEE
    6. $000B5FDA $000B50FE
    7. $00001206 $0000120E
    8. $00002D7C $00002D90
    9. $00003504 $0000350C

An in-depth knowledge of the operating system and
machine code is necessary to understand this list. Please refer to the
operating system documentation.

**CROSS-REFERENCE**

:ref:`lpoll`, :ref:`lint2`.

--------------


