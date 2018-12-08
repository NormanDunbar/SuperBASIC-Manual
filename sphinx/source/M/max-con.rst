..  _max-con:

MAX\_CON
========

+----------+-------------------------------------------------------------------+
| Syntax   | error = MAX\_CON(#channel%, x%, y%, xo%, yo%)                     |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

If the given channel is a 'CON\_' channel, this function will return a zero in the variable 'error'. The integer variables, 'x%', 'y%', 'xo%' and 'yo%' will be altered by the function, to return the maximum size that the channel can be :ref:`window`\ 'd to.

'x%' will be set to the maximum width, 'y%' to the maximum depth, 'xo%' and 'yo%' to the minimum x co-ordinate and y co-ordinate respectively.

For the technically minded reader, this function uses the IOP\_FLIM routine in the pointer Environment code, if present. If it is not present, you should get the -15 error code returned. (BAD PARAMETER).


**EXAMPLE**

::

    7080 DEFine PROCedure SCREEN_SIZES
    7090   LOCal w%,h%,x%,y%,fer
    7100   REMark how to work out maximum size of windows using iop.flim
    7110   REMark using MAX_CON on primary channel returns screen size
    7120   REMark secondaries return maximum sizes within outline where
    7130   REMark pointer environment is used.
    7140   w% = 512 : REMark width of standard QL screen
    7150   h% = 256 : REMark height of standard QL screen
    7160   x% = 0
    7170   y% = 0
    7180   :
    7190   fer = MAX_CON(#0,w%,h%,x%,y%) : REMark primary for basic
    7200   IF fer < 0 : PRINT #0,'Error ';fer : RETurn
    7210   PRINT'#0 : ';w%;',';h%;',';x%;',';y%
    7220   :
    7230   fer = MAX_CON(#1,w%,h%,x%,y%) : REMark primary for basic
    7240   IF fer < 0 : PRINT #0,'Error ';fer : RETurn
    7250   PRINT'#1 : ';w%;',';h%;',';x%;',';y%
    7260   :
    7270   fer = MAX_CON(#2,w%,h%,x%,y%) : REMark primary for basic
    7280   IF fer < 0 : PRINT #0,'Error ';fer : RETurn
    7290   PRINT'#2 : ';w%;',';h%;',';x%;',';y%
    7300 END DEFine SCREEN_SIZES

