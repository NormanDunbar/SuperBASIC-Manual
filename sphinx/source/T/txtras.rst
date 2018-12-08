..  _txtras:

TXTRAS
======

+----------+-------------------------------------------------------------------+
| Syntax   |  TXTRAS [#ch]                                                     |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

This command lists extensions to SuperBASIC in the specified channel
#ch (default #1). Apart from printing the mere keyword name, it will
also report the type, ie. whether it is a function or command.

**Example**

TXTRAS might print::

    Proc RUN
    Proc STOP
    Proc OPEN
    Proc CLOSE

**NOTE**

On pre 1.10 versions of TinyToolkit, TXTRAS was named EXTRAS.

**CROSS-REFERENCE**

:ref:`extras`, :ref:`sxtras`
and :ref:`vocab` are all similar.

