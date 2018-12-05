..  _matmult:

MATMULT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATMULT product, matrix1, matrix2                                |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATMULT performs multiplication on matrices of floating
point type. The matrix1 is multiplied with matrix2 and the result stored
in product. Since a n x m matrix represents a linear transformation
which takes n-dimensional vectors and produces m-dimensional vectors
from them, the following conditions must be satisfied by the three
matrices supplied to MATMULT:

- All matrices must be two-dimensional.
- DIMN (matrix1, 2) = DIMN (matrix2, 1)
- DIMN (matrix1, 1) = DIMN (product, 1)
- DIMN (matrix2, 2) = DIMN (product, 2)

The latter three conditions are obviously satisfied by square matrices.

**Example**

Multiplication of two matrices means that their effect on a vector is
combined into one matrix. The following program demonstrates this on a
simple square.

The square x is a list of four vectors. x is first
rotated with ROT by 45\ :sup:`o`\, the rotated square is stored in y.

Now this y is squeezed in size by one half with SQZ and stored in z. Lines 240 to
280 perform all this and show the process.

After a keystroke, the matrix
ROTSQZ will be created as the product of ROT and SQZ. Again the original
square is transformed but this time by ROTSQZ which rotates and squeezes
in one go. This is done by lines 300 to 350.

Lines 100 to 220 initialise
the matrices and set up the window for drawing.

Due to the design of QL
graphics, line 100 can be freely omitted.

At the bottom of the listing
are three PROCedures:

MATVEC multiplies a vector with a matrix (ie. the
vector is transformed by this matrix) and MATVECS does the same for a
list of vectors, just calling MATVEC for each individual vector.
MATVEC(S) is written in a dimension independent way, just to show how
that can be done; there is no check on the parameters, just to save
space.

POLYDRAW draws a closed polygon from a supplied list of
two-dimensional points.

::

    100 WINDOW 448,200,32,16
    110 SCALE 8,-5,-4: PAPER 0: CLS
    120 :
    130 DIM ROT(2,2): rc=1/SQRT(2)
    140 ROT(1,1)=rc: ROT(1,2)=rc
    150 ROT(2,1)=-rc: ROT(2,2)=rc
    160 DIM SQZ(2,2): SQZ(1,1)=.5: SQZ(2,2)=.5
    170 :
    180 DIM x(4,2), y(4,2), z(4,2)
    190 x(1,1)=-1: x(1,2)= 1
    200 x(2,1)= 1: x(2,2)= 1
    210 x(3,1)= 1: x(3,2)=-1
    220 x(4,1)=-1: x(4,2)=-1
    230 :
    240 INK 5: POLYDRAW x
    250 MATVECS y,ROT,x
    260 INK 3: POLYDRAW y
    270 MATVECS z,SQZ,y
    280 INK 7: POLYDRAW z
    290 :
    300 PAUSE: CLS
    310 DIM ROTSQZ(2,2)
    320 INK 5: POLYDRAW x
    330 MATMULT ROTSQZ,ROT,SQZ
    340 MATVECS z,ROTSQZ,x
    350 INK 7: POLYDRAW z
    360 :
    370 :
    380 DEFine PROCedure MATVECS (vectors2, matrix, vectors1)
    390   LOCal i
    400   FOR i=1 TO DIMN(vectors1)
    410     MATVEC vectors2(i),matrix,vectors1(i)
    420   END FOR i
    430 END DEFine MATVECS
    440
    :
    450 DEFine PROCedure MATVEC (vector2, matrix, vector1)
    460   REMark vector2 = matrix * vector1
    470   LOCal i,j
    480   FOR i=1 TO DIMN(vector2)
    490     vector2(i)=0
    500     FOR j=1 TO DIMN(matrix,2)
    510       vector2(i)=vector2(i)+matrix(i,j)*vector1(j)
    520     END FOR j
    530   END FOR i
    540 END DEFine MATVEC
    550 :
    560 DEFine PROCedure POLYDRAW (vectors)
    570   LOCal i
    580   POINT vectors(1,1),vectors(1,2)
    590   FOR i=2 TO DIMN(vectors), 1
    600     LINE TO vectors(i,1),vectors(i,2)
    610   END FOR i
    620 END DEFine POLYDRAW

**NOTE**

Normally the product of two matrices A\*B is not the same as B\*A,
however, the matrices ROT and SQZ in the above example are an exception
to this rule. Replace line 330 with: 330 MATMULT ROTSQZ,SQZ,ROT
and nothing will change.

**CROSS-REFERENCE**

See :ref:`matinv` for another example of using
:ref:`matmult`.

--------------


