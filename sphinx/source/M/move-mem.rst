..  _move-mem:

MOVE\_MEM
=========

+----------+-------------------------------------------------------------------+
| Syntax   | MOVE\_MEM destination, length                                     |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This procedure will copy the appropriate number of bytes from the given source address to the destination address. If there is an overlap in the addresses, then the procedure will notice and take the appropriate action to avoid corrupting the data being moved. Most moves will take place from source to destination, but in the event of an overlap, the move will be from (source + length -1) to (destination + length -1).

This procedure tries to do the moving as fast as possible and checks the addresses passed as parameters to see how it will do this as follows :-

- If both addresses are odd, move one byte, increase the source & destination addresses by 1 and drop in to treat them as if both are even, which they now are!

- If both addresses are even, calculate the number of long word moves (4 bytes at a time) that are to be done and do them. Now calculate how many single bytes need to be moved (zero to 3 only) and do them.

- If one address is odd and the other is even the move can only be done one byte at a time, this is quite a lot slower than if long words can be moved.

The calculations to determine which form of move to be done adds a certain overhead to the function and this can be the slowest part of a memory move that is quite small.


**EXAMPLE**

::

    MOVE_MEM SCREEN_BASE(#0), SaveScreen_Addr, 32 \* 1024


-------



