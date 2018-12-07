..  _put-float:

PUT\_FLOAT
==========

+----------+-------------------------------------------------------------------+
| Syntax   | PUT\_FLOAT #channel, byte                                         |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The given float value is converted to the internal  QDOS format for floating point  numbers and those 6 bytes are sent to the given channel  number.  The full range of QL numbers can be sent including all the negative values. :ref:`get-float` will return negative values correctly (unless an error occurs).


**EXAMPLE**

::

    PUT_FLOAT #3, PI


**CROSS-REFERENCE**

:ref:`put-byte`, :ref:`put-long`, :ref:`put-string`, :ref:`put-word`.
