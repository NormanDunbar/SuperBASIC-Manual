..  _rmar:

RMAR
====

+----------+-------------------------------------------------------------------+
| Syntax   |  RMAR(n) with n=0..255                                            |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools                                                       |
+----------+-------------------------------------------------------------------+

This function returns the control codes needed to set the right margin
to n characters (from the left side) on EPSON compatible printers. If
the right margin is smaller than the left margin, the printer will
ignore this setting and print to the greatest possible right margin::

    PRINT #ch,RMAR

is the same as::

    PRINT #ch,CHR$(27) & 'Q' & CHR$(n)

.. COMMENT. What is the following meant to be showing? It doesn't seem to
   make any sense or be related to the above. I've left it commented out for now.


.. ::
..
    |- LMAR -|
    |------------ RMAR ----------|
    +---------------------------------+
    |                    |
    |     .....................     |
    |   .....................     |
    |    .....................     |

**CROSS-REFERENCE**

:ref:`norm`, :ref:`bld`,
:ref:`el`, :ref:`dbl`,
:ref:`enl`, :ref:`pro`,
:ref:`si`, :ref:`nrm`,
:ref:`unl`, :ref:`alt`,
:ref:`esc`, :ref:`ff`,
:ref:`lmar`, :ref:`pagdis`,
:ref:`paglen`.

