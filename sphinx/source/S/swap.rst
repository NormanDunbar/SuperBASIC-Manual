..  _swap:

SWAP
====

+----------+------------------------------------------------------------------+
| Syntax   | SWAP var1,var2  or                                               |
|          |                                                                  |
|          | SWAP var1$,var2$                                                 |
+----------+------------------------------------------------------------------+
| Location | SWAP, Math Package                                               |
+----------+------------------------------------------------------------------+

This command exchanges the values of the two variables. The parameters
can be either numeric variables (integer and floating point) or strings.
Arrays are not allowed and both variables have to be the same type: SWAP
a$,b is illegal, even if a$ contained a valid number. Also, constant
expressions such as SWAP a%,3 are not allowed, since this would not make
any sense. Unfortunately, it is not possible to SWAP two elements of an
array, the example shows why this would be practicable. The Math Package
variant also allows you to swap whole arrays.

**Example**

In most kinds of sorting routines, a lot of swapping is necessary and an
assembler routine which takes over this work makes the process quicker.
Here is a Quicksort algorithm as a general subroutine. field$ is sorted
from the left element to the right.

::

    100 DEFine PROCedure QSort (field$,left,right)
    110   LOCal i,j,last$
    120   i=left: j=right: last$=field$(j)
    130   REPeat SortLoop1
    140     REPeat SortLoop2:IF field$(i)<last$:i=i+1:ELSE EXIT SortLoop2
    150     REPeat SortLoop2:IF field$(j)>last$:j=j-1:ELSE EXIT SortLoop2
    160     IF i<=j THEN
    170       f1$=field$(i): f2$=field$(j): SWAP f1$,f2$
    180       field$(i)=f1$: field$(j)=f2$
    190       i=i+1: j=j-1
    200     END IF
    210     IF i>j THEN EXIT SortLoop1
    220   END REPeat SortLoop1
    230   IF left<j THEN QSort field$,left,j
    240   IF right>i THEN QSort field$,i,right
    250 END DEFine QSort

Compilers have a fixed stack size - you might have to raise this
because this procedure iterates (ie. calls itself), which is something
which eats up the stack very quickly. The SuperBASIC interpreter uses a
flexible stack.

**CROSS-REFERENCE**

:ref:`let`

