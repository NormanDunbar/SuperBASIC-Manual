..  _slug:

SLUG
====

+----------+-------------------------------------------------------------------+
| Syntax   |  SLUG msecs                                                       |
|          |                                                                   |
|          |  SLUG num (Q68)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  Gold Card (v2.24+), SMS, SMSQ/E for Q68                          |
+----------+-------------------------------------------------------------------+

A disadvantage of the speed improvements by Gold Card (and later
expansion boards) is that most games become simply too fast. The
command SLUG can slow down the whole system by advising the operating
system to read the keyboard less often (other solutions install
background interrupts but some games suspend these). The parameter
specifies the delay in milliseconds. The higher msecs, the slower the
general operating speed will be. SLUG 5 to SLUG 10 on a Gold Card
gives roughly the speed of a normal QL, but this depends very much on
the software. Programs which do not spend a lot of time waiting for
keyboard input such as interactive games, will not slow down so
much. Only keyboard access is slowed down.

For the Q68 num must be in the range 0...255

**Example**

::
   
    100 FOR n=0 to 1000 STEP 10
    110   SLUG n
    120   PRINT n
    130   dummy=KEYROW(0)
    140 END FOR n

**Note 1**

Since SLUG only slows down keyboard access (this is especially designed
for arcade games), the above example would not be affected without line
130. All other lines run at maximum speed; the advantage is that screen
output, which is a limiting factor for arcade games, is not affected by
SLUG.

**Note 2**

SLUG for the Q68 is for the same purpose but operates in a different
manner from SLUG on the Gold Card so line 130 is not actually
necessary.

**CROSS-REFERENCE**

:ref:`scr2dis` and
:ref:`cache-on` can be used to speed up the
computer's speed.

