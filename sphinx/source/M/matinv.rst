..  _matinv:

MATINV
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATINV matrix2,matrix1                                           |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATINV takes the array matrix1, inverts it and stores the
result in matrix2.

Inverting is a mathematical term and produces a
result from a matrix which is similar to finding the reciprocal of a
number, namely, the relation is expressed by the fact that the product
of a number and its reciprocal is one and the product of a matrix and
its inverse matrix is the identity matrix::

    n=10: DIM A(n,n), B(n,n), C(n,n)
    MATRND A

A is a random matrix.

::

    MATINV A,B

makes B the inverted matrix of A.

::

    MATMULT C,A,B

Multiply A with B and store the result in C. C will be almost identical to the matrix ONE defined with::

    DIM ONE(n,n): MATIDN ONE

C and ONE do not have exactly the same values because of the limited
precision of the QL maths package. Two conditions are absolutely
necessary for MATINV to work::

- DET (matrix1) <> 0
- matrix1 and matrix2 must be square matrices

**Example**

A matrix A and an array b form a so-called "linear equation system"
which has a solution x which is an array like b. This example will find
the solutions x(i) of the system, for any positive value of n (the size
of the matrix)::

    100 n=5
    110 DIM A(n,n), AINV(n,n), b(n), x(n)
    120 MATRND A: MATRND b
    130 :
    140 MATINV A,AINV
    150 MATSCALM AINV,b TO x
    160 PRINT "Solutions:"\x
    170 IF ABS(DET)<1E-6 THEN PRINT "(dubious results)"
    180 :
    190 DEFine PROCedure MATSCALM (matrix,array1,array2)
    200   LOCal i,j
    210   FOR i=0 TO DIMN(matrix,1)
    220     array2(i)=0
    230     FOR j=0 TO DIMN(matrix,2)
    240       array2(i)=array2(i)+array1(j)\*matrix(i,j)
    250     END FOR j
    260   END FOR i
    270 END DEFine MATSCALM

The method of solving a linear equation system by calculating the
inverted matrix is known as Cramer's Rule. The advantage is that if the
matrix A is constant and only the array b varies for other situations,
MATINV needs only be called once and not afterwards for each value of
the array b.

**NOTE**

Calculation time takes longer as the size of the matrix increases eg.
the above example will take nearly an hour to calculate n=100. MATINV
cannot be stopped with <CTRL><SPACE> whilst number crunching.

**CROSS-REFERENCE**

It is highly recommended to check if :ref:`det` is
very close to zero after :ref:`matinv` has been
executed, if this is the case, :ref:`matinv` may
have found a result which does not exist::

    IF ABS(DET) < 1E-6 THEN PRINT "dubious result"

This works because :ref:`matinv` calls :ref:`det`
internally.

