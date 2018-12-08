..  _peek-l:

PEEK\_L
=======

+----------+------------------------------------------------------------------+
| Syntax   | PEEK (address) where address=0,1,2,3,...  and                    |
|          |                                                                  |
|          | PEEK\_W (address) where address=0,2,4,6,...  and                 |
|          |                                                                  |
|          | PEEK\_L (address) where address=0,2,4,6,...                      |
+----------+------------------------------------------------------------------+
| Location | QL ROM                                                           |
+----------+------------------------------------------------------------------+

These three functions are complementary to POKE, POKE\_W and POKE\_L,
in that instead of setting a byte, word or longword in memory, these
three functions return the value of the byte, word or longword stored at
the given address.

**NOTE 1**

Due to the way in which values are stored in memory, it can be difficult
to read negative values. However, although PEEK will return an unsigned
byte in the range 0..255, PEEK\_W will return a
signed word in the range -32768...32767 and PEEK\_L a signed longword.

**NOTE 2**

Do not try to PEEK\_W or PEEK\_L with an odd address (eg. 10001) as this
will cause an error unless you are using Minerva (see below).

**MINERVA NOTES**

As with the POKE commands, the PEEK functions on Minerva (version 1.77
or later) are very much enhanced and different. Minerva allows you to
use PEEK\_W and PEEK\_L on odd addresses, eg::

    PRINT PEEK_W(131073)

Minerva has also added to the usefulness of the PEEK, PEEK\_W
and PEEK\_L functions by allowing them to access system variables,
Minerva's System Xtensions and SuperBASIC variables. You will need a
good book on QDOS (eg. QDOS/SMS Reference Manual) to find out what the
possible values are.

The syntax for these extra commands is:

**Look at SuperBASIC variables**

::

    PEEK (\\SBvar)
    PEEK_W (\\SBvar)
    PEEK_L (\\SBvar)

    PEEK (\SBvar\Offset)
    PEEK_W (\SBvar\Offset)
    PEEK_L (\SBvar\Offset)

**Look at System variables**

::

    PEEK (!!Sysvar)
    PEEK_W (!!Sysvar)
    PEEK_L (!!Sysvar)

    PEEK (!Sysvar!Offset)
    PEEK_W (!Sysvar!Offset)
    PEEK_L (!Sysvar!Offset)

**Look at System Xtensions**

::

    sx_base=PEEK_L(VER$(-2) + 124)
    PEEK (sx_base + offset)

**SMS NOTES**

SMS has altered the PEEK functions so that they are able to access
System variables and SuperBASIC variables, using the same format as
Minerva.

**CROSS-REFERENCE**

Please see in particular :ref:`poke`,
:ref:`poke-w`, and
:ref:`poke-l`. :ref:`peek-dlr`
reads a string stored in memory and contains some examples of the new
variants introduced on Minerva and SMS.
:ref:`peek-f` and :ref:`peeks`
are also worth a look.

