..  _copy-l:

COPY\_L
=======

+----------+------------------------------------------------------------------+
| Syntax   |  COPY\_L adr1, adr2, n or                                        |
|          |                                                                  |
|          | COPY\_L adr1, n TO adr2                                          |
+----------+------------------------------------------------------------------+
| Location |  BTool                                                           |
+----------+------------------------------------------------------------------+

The command COPY\_L copies n longwords (each being 4 bytes) from address
adr1 to adr2. The two memory locations can overlap (this is also true
for COPY\_B and COPY\_W).

If you are using Minerva, you will probably find it quicker to use it's
specialised CALL routines.

**Example**

::

    100 a=ALCHP(48*1024)
    110 COPY_L 0,12*1024 TO a

**NOTE**

Both adr1 and adr2 must be even addresses.

**CROSS-REFERENCE**

:ref:`copy-w`,
:ref:`copy-b`, :ref:`odd`.

