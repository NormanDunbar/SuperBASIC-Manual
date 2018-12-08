..  _det:

DET
===

+----------+-------------------------------------------------------------------+
| Syntax   |  DET [array]                                                      |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function DET returns the determinant of a square matrix, meaning
that the array (or the part passed) must have two dimensions of equal
size, otherwise DET breaks with error -15 (bad parameter).

The array
needs to be a floating point array, any other type (including integer
arrays) will also produce error -15.

If no parameter is given, DET will
use the array that has been supplied to the previously executed MATINV
command as its source. If however, this command has not yet been used,
DET without a parameter will stop with the error -7 (not found).

You may
ask what a determinant is? Briefly speaking, it represents a square
matrix by a single number so that important characteristics of the
matrix can be deduced from it, eg. the matrix cannot be inverted if the
determinant is zero.


**Example**

We will try to approach the eigenvalues of a matrix and list them all
(the so-called "spectrum" of a matrix). Due to approximation errors and
the simple algorithm employed, there can be more output values than
there should be. This can be improved by increasing estep in line 130,
but at the cost of speed.

The range of expected eigenvalues (eval1 to
eval2) is adapted to the chosen matrix whose random elements only range
between 0 and 1. There is no limit for the positive size n of the
matrix, n=0 is allowed but does not make sense because CHARPOLY becomes
constant::

    100 CLEAR: RANDOMISE 10: PRINT "Eigenvalues:"
    110 n=2: DIM matrix(n,n), one(n,n)
    120 MATRND matrix: MATIDN one
    130 :
    140 eval1=-1: eval2=1: esteps=200
    150 eprec<(eval2-eval1)/estep)
    160 c1=CHARPOLY(matrix,eval1): count%=0
    170 FOR eval=eval1+eprec TO eval2 STEP eprec
    180 c2=CHARPOLY(matrix,eval)
    190 IF SGN(c1)<>SGN(c2) THEN PRINT eval
    200 c1=c2: count%=count%+1
    210 AT#0,0,0: PRINT#0,INT(100*count%/esteps);"%"
    220 END FOR eval
    230 PRINT "absolute fault:"!eprec
    240 :
    250 DEFine FuNction CHARPOLY(matrix,lambda)
    260   LOCal diff(n,n),i
    270   FOR i=1 TO n: one(i,i)=lambda
    280   MATSUB diff,matrix,one
    290   RETurn DET(diff)
    300 END DEFine CHARPOLY

In practice, a Newton iteration algorithm (or better) would be used.


**CROSS-REFERENCE**

:ref:`matinv` co-operates closely with
:ref:`det`, so that for each of them a matrix
parameter can be omitted if the other function has been called before;
:ref:`matinv` calls :ref:`det`
internally. In the example, we used the
:ref:`matrnd`, :ref:`matidn`,
:ref:`sgn` and :ref:`matsub`
keywords which are all part of the same Toolkit.

