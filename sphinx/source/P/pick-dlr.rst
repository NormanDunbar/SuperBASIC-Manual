..  _pick-dlr:

PICK$
=====

+----------+-----------------------------------------------------------------------------+
| Syntax   |  PICK$ (n, slct\ :sup:`1`\ $ :sup:`\*`\ [,slct\ :sup:`i`\ $]\ :sup:`\*`\ )  |
+----------+-----------------------------------------------------------------------------+
| Location |  CONTROL (DIY Toolkit Vol E)                                                |
+----------+-----------------------------------------------------------------------------+

The function PICK$ takes one positive integer n and one or more other
parameters slct1$, slct2$, etc. The function returns the value of the
nth parameter, so n must be smaller than or equal to the number of
supplied slctx$. Don't forget, n must be greater than zero!

**Example**

PICK$ is intended to simplify expressions, here are some silly examples::

    100 bool%=RND (0 TO 1)
    110 IF bool% THEN PRINT "yes": ELSE PRINT "no"

becomes::

    100 bool%=RND (0 TO 1)
    110 PRINT PICK$ (bool%+1,"no","yes")

Whereas::

    100 members = RND (4)
    110 PRINT "The team has ";
    120 IF members>0: PRINT members;: ELSE PRINT "no";
    130 PRINT " member";
    140 IF members<>1 THEN PRINT "s": ELSE PRINT

becomes::

    100 members = RND(4)
    110 PRINT "The team has ";
    120 PRINT PICK$ (1+(members<>0),"no",members);
    130 PRINT " member";PICK$ (1+(members<>1),"","s")

The slightly more complex::

    100 DIM num$ (9,5)
    110 RESTORE : FOR i=0 TO 9: READ num$(i)
    120 DATA "zero","one","two","three","four"
    130 DATA "five","six","seven","eight","nine","ten"
    140 :
    150 REPeat typing
    160 key = CODE (INKEY$ (-1))-48
    170 IF key<0 OR key>9 THEN EXIT typing
    180 PRINT num$ (key)!!
    190 END REPeat typing

becomes::

    100 REPeat typing
    110 key = CODE (INKEY$(-1))-48
    120 IF key<0 OR key>9 THEN EXIT typing
    130 PRINT PICK$ (key+1,"zero","one","two","three","four","five","six","seven","eight", "nine", "ten")
    140 END REPeat typing

**CROSS-REFERENCE**

Note that conditions have a numeric value, see
:ref:`if`, :ref:`and` and
:ref:`or` for details. :ref:`select--on`\ .. END
SELect <KeywordsS.clean.html#-end-select>`__ is a less
restrictive alternative to :ref:`pick-dlr`.

