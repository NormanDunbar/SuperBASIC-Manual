..  _set-yinc:

SET\_YINC
=========

+----------+-------------------------------------------------------------------+
| Syntax   | SET\_YINC #channel, increment                                     |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

These two functions change the spacing between characters horizontally, :ref:`set-xinc`, or vertically, SET\_YINC. This allows slightly more information to be displayed on the screen. :ref:`set-xinc` allows adjacent characters on a line of the screen to be positioned closer or further apart as desired. SET\_YINC varies the spacing between the current line of characters and the next.

By choosing silly values, you can have a real messy screen, but try experimenting with :ref:`over` as well to see what happens. Use of the :ref:`mode` or :ref:`csize` commands in SuperBasic will overwrite your new values.


**EXAMPLE**

::

    SET_XINC #2, 22
    SET_YINC #2, 16
    PRINT #2, "This is a line of text"
    PRINT #2, "This is another line of text"
    PRINT #2, "This is yet another!"


**CROSS-REFERENCE**

:ref:`set-xinc`.


