..  _poke-dlr:

POKE$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  POKE$ address,string$                                            |
+----------+-------------------------------------------------------------------+
| Location |  ATARI\_REXT, TinyToolkit, BTool, SMS                             |
+----------+-------------------------------------------------------------------+

The standard version of this command pokes the code of each of the
given string's characters to memory from address onwards. In SuperBASIC,
the procedure might look similar to::

    100 DEFine PROCedure POKE$ (address,string$)
    110   LOCal i
    120   FOR i=1 TO LEN(string$)
    130   POKE address+i-1,CODE(string$(i))
    140   END FOR i
    150 END DEFine POKE$

The BTool version writes the string in QDOS internal format: the
string's contents are preceded by two additional bytes (one word)
indicating the length of the string. address must be even. If you pass
an empty string, all versions of this command will not do anything.

**SMS NOTE**

This command is now very similar to POKE in that POKE allows you to pass
a string as a parameter. POKE$ can also now access the System Variables
and SuperBASIC variables directly as with POKE.

**CROSS-REFERENCE**

:ref:`peek-dlr` reads strings from memory.
:ref:`mks-dlr` returns the internal format of a given
string. :ref:`ttpoke-dlr` is the same as this
command.

