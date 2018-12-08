..  _search-i:

SEARCH\_I
=========

+----------+-------------------------------------------------------------------+
| Syntax   | address = SEARCH\_I(start, length, what_for$)                     |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function, and :ref:`search-c` above, search through memory looking for the given string. :ref:`search-c` searches for an EXACT match whereas SEARCH\_I ignores the difference between lower & UPPER case letters.

If the address  returned is zero, the string was not found,  otherwise it is the address where the first character of what_for$ was found, or negative for any errors that may have occurred.

If the string  being  searched for is empty ("") then zero will be returned, if the length of the buffer is negative or 0, you will get a 'bad parameter' error (-15).  The address is considered to be unsigned, so negative addresses will be considered to be very large positive addresses, this allows for any future enhancements which will allow the QL to use a lot more memory than it does now!

**EXAMPLE**

::

    1000 PRINT SEARCH_C(0, 48 * 1024, 'sinclair')
    1010 PRINT SEARCH_I(0, 48 * 1024, 'sinclair')
    1020 PRINT
    1030 PRINT SEARCH_C(0, 48 * 1024, 'Sinclair')
    1040 PRINT SEARCH_I(0, 48 * 1024, 'Sinclair')

The above fragment, on my Gold Card JS QL, prints::

    0
    47314

    47314
    47314

Looking into the ROM at that address using

::

    PEEK_STRING(47314, 21)

gives::

    Sinclair Research Ltd

which is part of the copyright notice that comes up when you switch on your QL. The reason for zero in line 1000 is because the 's' is lower case, case is significant and the ROM has a capital 'S', so the text was not found in the ROM.


**CROSS-REFERENCE**

:ref:`search-c`.


