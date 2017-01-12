==========
Keywords M
==========

TODO
====

- Sort out MIDINET table. It's way too wide.
- :ref:`matplot` references something called POINT_ABS. I can't find it anywhere.


..  _machine:

MACHINE
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MACHINE                                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, SMSQ/E for QPC                                           |
+----------+-------------------------------------------------------------------+

This function returns a value corresponding to the type of system on
which SuperBASIC is running. The values currently returned are:

+---------+-------------------------------------------------------+
| MACHINE | Machine Type                                          |
+=========+=======================================================+
| 0       | ATARI ST / STM / STF / STFM                           |
+---------+-------------------------------------------------------+
| 1       | ORDINARY STE (1040) - NOT SUPPORTED!!!                |
+---------+-------------------------------------------------------+
| 2       | MEGA ST or ST / STM / STF / STFM with REAL-TIME CLOCK |
+---------+-------------------------------------------------------+
| 4       | ATARI STACY                                           |
+---------+-------------------------------------------------------+
| 6       | ATARI STE                                             |
+---------+-------------------------------------------------------+
| 8       | MEGA STE                                              |
+---------+-------------------------------------------------------+
|10       | GOLD CARD                                             |
+---------+-------------------------------------------------------+
|12       | SUPER GOLD CARD                                       |
+---------+-------------------------------------------------------+
|16       | FALCON                                                |
+---------+-------------------------------------------------------+
|24       | ATARI TT 030                                          |
+---------+-------------------------------------------------------+
|28       | QXL                                                   |
+---------+-------------------------------------------------------+
|30       | QPC                                                   |
+---------+-------------------------------------------------------+


On Standard QLs, MACHINE returns the above value
plus 1 if HERMES is fitted. 

On ATARI Computers, MACHINE returns the
above value plus 1 is a BLITTER CHIP is fitted. 

Users without SMSQ/E can use the command:: 

    PRINT PEEK (SYS_VARS+HEX('a7')) && BIN ('0011111')
    
    
This should return the same values (except that 0 will also be returned
on a standard QL without any expansion board or a THOR computer). 

You can test for a THOR by using:: 

    PRINT PEEK (SYS_VARS+HEX('84'))
    
which will be 0 on any other implementation. We do not know what it
returns on the THOR range of computers.

**Example**

A program to test for the actual machine on which the program is
running, as well as other interesting data::

    100 v$=VER$:q$=QDOS$ 
    110 processor$='00':FPU=0:em_type=0 
    120 IF v$<>'HBA' 
    130   m_type=PEEK(SYS_BASE+HEX('A7')) 
    140   em_type=m_type && BIN('11100000') 
    150   m_type=m_type && BIN('00011111') 
    160   SELect ON em_type 
    170     =1:em_type=3 
    180     =2:em_type=1 
    190     =4:em_type=2 
    200   END SELect 
    210   IF v$='JSL1' 
    220     PRINT 'MINERVA FITTED'
    230     m_type=100 : processor$='08' 
    240   ELSE 
    250     IF m_type=0 
    260       IF PEEK (SYS_BASE+HEX('84'))<>0 
    270         IF q$(1)='4':PRINT 'THOR 1 Computer'; 
    280         IF q$(1)='5':PRINT 'THOR 20 Computer'; 
    290         IF q$(1)='6':PRINT 'THOR XVI Computer'; 
    300         IF q$(1) INSTR '456'=0:PRINT 'UNKNOWN THOR Computer' 
    310         PRINT ' v';q$:STOP 
    320       END IF 
    330     END IF 
    340   END IF 
    350 ELSE 
    360   m_type=MACHINE:processor$=PROCESSOR 
    370   FPU=processor$(2):processor$=processor$(1)&'0' 
    380   em_type=DISP_TYPE
    390 END IF 
    400 extra_chip=m_type MOD 2 
    410 m_type=(m_type DIV 2)*2
    420 SELect ON m_type 
    430   =0: IF v$='HBA' 
    440         PRINT 'ATARI ST / STM / STF / STFM'; 
    450         ELSE :PRINT 'STANDARD QL - ROM VERSION ';v$ : processor$='08' 
    460       END IF 
    470   =2: PRINT 'MEGA ST or ST / STM / STF / STFM with REAL-TIME CLOCK'; 
    480   =4: PRINT 'ATARI STACY'; 
    490   =6: PRINT 'ATARI STE'; 
    500   =8: PRINT 'MEGA STE'; 
    510   =10: PRINT 'GOLD CARD'; 
    520   =12: PRINT 'SUPER GOLD CARD'; 
    530   =16: PRINT 'FALCON'; 
    540   =24: PRINT 'ATARI TT 030'; 
    550   =28: PRINT 'QXL' 
    560   =30: PRINT 'QPC' 
    570 END SELect
    580 SELect ON extra_chip 
    590   =0: PRINT 
    600   =1: 
    610     SELect ON m_type
    620       =0,2,4,6,8,16,24:PRINT ' with BLITTER' 
    630         SELect ON em_type 
    640           =0: PRINT 'Original QL Emulator FITTED' 
    650           =1: PRINT 'Extended Mode 4 Emulator FITTED' 
    660           =2: PRINT 'QVME Emulator FITTED' 
    670           =3: PRINT 'Monochrome Display Only' 
    680         END SELect 
    690     =REMAINDER :PRINT ' with HERMES' 
    700     END SELect 
    710 END SELect 
    720 PRINT 'ROM VERSION - ';v$ 
    730 PRINT 'OS VERSION - ';q$ 
    735 IF m_type<>30 
    740   PRINT 'PROCESSOR - 680';processor$; 
    745 ELSE 
    750   PRINT 'INTEL PROCESSOR'; 
    755 END IF 
    760 SELect ON FPU 
    765   =0 : PRINT
    770   =1 : PRINT 'with Internal MMU' 
    780   =2 : PRINT 'with 68851 MMU' 
    790   =4 : PRINT 'with Internal FPU' 
    800   =8 : PRINT 'with 68881 or 68882 FPU'
    810 END SELect

**NOTE 1**

The machine type was only stored with on the ST/QL on Level E-20 drivers
onwards. E-Init v1.07+ is also required.

**NOTE 1**

The wrong value was returned for the Mega ST prior to v1.33 of E-Init.

**CROSS-REFERENCE**

See :ref:`processor`,
:ref:`disp-type`,
:ref:`ver-dlr` and :ref:`qdos-dlr`.
:ref:`ver-dlr`\ (1) and
:ref:`sys-base` replace
:ref:`sys-vars`. See also
:ref:`a-machine`.

--------------


..  _make-dir:

MAKE\_DIR
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  MAKE\_DIR subdirectory                                           |
+----------+-------------------------------------------------------------------+
| Location |  Level-2 and Level-3 Drivers, THOR XVI                            |
+----------+-------------------------------------------------------------------+

The command MAKE\_DIR creates a sub-directory which allows a group of
files to be regarded as one unit when the contents of a medium are
listed. Operations other than the standard DIR, WDIR, WSTAT and WDEL,
are not affected. A file belongs to a sub-directory if the
sub-directory's name appears as a prefix of the file, whether the file
was created before or after the sub-directory. 

Sub-directories are only
supported on Level-2 (or higher) floppy disks, hard disks and ramdisks.

A sub-directory name can be any name but any underscore at its end will
be ignored by MAKE\_DIR. 

If there is no medium in the given device, or
if you do not specify a device name, the current default data device
will be used (see DATAD$). 

Sub-directories are identified by a "->" in
directory listings and programs can identify them by examining their
file type (255). 

Empty sub-directories can be deleted as normal files,
but a sub-directory which is not empty, cannot be deleted: error -9 (in
use) will be reported. Actually, sub-directories are normal files which
hold a list of the files which are contained within them. The list
consists of the standard file headers of these files, each being 64
bytes long. 

A sub-directory file never decreases in length if a file in
the sub-directory has been deleted, instead, the file header is just
marked as deleted by setting the name to a zero string. 

All normal
operations are allowed on sub-directory files (except RENAME), and they
can be accessed using OPEN\_DIR and FOP\_DIR.

**Example**

If FLP1\_ contains an empty disk and we then save the current SuperBASIC
program as flp1\_my\_prog\_bas and a backup as flp1\_backup\_bas::

    SAVE flp1_my_prog_bas 
    SAVE flp1_backup_bas

a directory of flp1\_, produced with WDIR flp1\_ (for example), shows
the following contents::

    my_prog_bas 
    backup_bas

Now, we create the sub-directory my (or my\_) with::

    MAKE_DIR flp1_my_

or::

    MAKE_DIR flp1_my
    
(both forms are equivalent) and look at the directory again::

    my ->
    backup_bas 
    
MAKE\_DIR created a new file "my" (not "my ->") which is
marked as a sub-directory with the "->" sign by the DIR, WDIR
and WSTAT commands. The file type of my is 255, PRINT FTYP(\\flp1\_my)
will return that. 

But where is my\_prog\_bas? It was moved into the
sub-directory my\_ and DIR flp1\_my\_ will show it again.

**NOTE 1**

The QUBIDE interface does not allow you to use MAKE\_DIR to create a
sub-directory if any files already exist which would fall into that
sub-directory.

**NOTE 2**

The level-2 device drivers introduced a new standard for subdirectories
- other methods which were implemented in the past are not recognised
in this (e)book.

**NOTE 3**

If a disk with a sub-directory is read by a level-1 device driver, the
sub-directory appears as just another file and files which have been
added to a sub-directory after its creation cannot be accessed or seen
by the system. However, if a file had been created before the
sub-directory, the level-1 device driver finds this file just as if the
sub-directory did not exist. So, if you prepare a disk which should also
be readable on level-1 device drivers, either don't use sub-directories
or create them after everything else.

**NOTE 4**

Sub-directory names longer than 27 characters on Toolkit II may hang up
the SuperBASIC interpreter. Since the system does not treat nested
sub-directories differently, the above warning applies to long
sub-directory prefixes as well. However, this lock up will only occur
when creating sub-directories not when using them. This problem is
fixed on SMS v2.85.

**NOTE 5**

A filename cannot be longer than 36 characters and as described above,
sub-directories are prefixes which reduce the maximum possible length of
a filename. If you try to create a file (eg. SAVE) in a sub-directory so
that the combined length of the file name and sub-directory are longer
than 36 characters, a 'not found' error will be returned.

**WARNING 1**

It is possible to create a sub-directory so that it cannot be removed
any more **(do not try this on a hard disk, you have been warned)**\ :: 

    SAVE test_ 
    MAKE_DIR test
    
The file test\_ (with an underscore) has been moved into the test directory, but it cannot
be deleted to empty test. - This has been fixed in drivers later than
version 2.28.

**WARNING 2**

::

    MAKE_DIR net_
    MAKE_DIR "net" 
    
and similar commands lock-up the machine, so if you want you create a sub-directory called 'net' in the
current directory, use::

    MAKE_DIR DATAD$ & "net".

**WARNING 3**

::

    MAKE_DIR flp1__
    MAKE_DIR flp1___ 
    
and similar commands could create recursive directories until this was fixed in SMS v2.77.

**CROSS-REFERENCE**

:ref:`fmake-dir` is a syntactical variation of
:ref:`make-dir`.
:ref:`open-dir` and
:ref:`fop-dir` allow you to read directories of
disks as well as sub-directories on level-2 drivers. The
:ref:`dup`, :ref:`ddown`,
:ref:`dnext` and
:ref:`data-use` commands are used to move around
in a sub-directory tree. See :ref:`fop-dir` for a
program which lists a sub-directory tree. To enable programs to read
sub-directories which have not been written for that purpose, the
DEV\_ device exists (see
:ref:`dev-use`). The only legal way of
identifying a sub-directory is by examining its file type as returned by
:ref:`ftyp` or
:ref:`file-type` for example.

--------------


..  _matadd:

MATADD
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATADD sum,matrix1,matrix2                                       |
+----------+-------------------------------------------------------------------+
| Location |  Math package                                                     |
+----------+-------------------------------------------------------------------+

The command MATADD adds the two matrices contained in the arrays
matrix1 and matrix2, setting the result in the array sum. The
parameters, matrix1, matrix2 and sum, must all be arrays of the same
dimensions, the same size and the same type. They can be of any number
type, viz. floating point or integer (% suffix), but not string and (we
must stress this point) floating point and integer arguments must not be
mixed. If these conditions are not satisfied, then MATADD will break
with a 'bad parameter' error (-15). Provided that the parameters follow
this rule, the command MATADD sets all of the elements of the sum array
to the sum of the respective elements of the two other arrays, matrix1
and matrix2.

**Example**

::

    100 DIM a%(10,10,80), b%(10,10,80), c%(10,10,80) 
    110 MATRND a%,-5 TO 5: MATSEQ b% 
    120 MATADD c%,a%,b%

**CROSS-REFERENCE**

If you run this short example program (8000 internal loops!), you will
notice the extraordinary speed of :ref:`matadd`
which is representative of the other MAT...
functions; :ref:`matsub` is almost equivalent to
:ref:`matadd`.

--------------


..  _matcount:

MATCOUNT
========

+----------+-------------------------------------------------------------------+
| Syntax   || MATCOUNT (array, value)  or                                      |
|          || MATCOUNT (array1, array2)                                        |
+----------+-------------------------------------------------------------------+
| Location || Math Package                                                     |
+----------+-------------------------------------------------------------------+

MATCOUNT is a function which counts how often a certain value appears
in the given array where array and value can be of any type (even
strings) as long as they are of the same type. The second syntax allows
you to pass two arrays array1 and array2 of the same type and
dimensions, MATCOUNT will then compare these two arrays and return the
number of different elements.

**Example**

The following programs compares two random integer arrays and will
always print something around 33%::

    100 DIM x%(1000), y%(1000) 
    110 MATRND x%,2: MATRND y%,2 
    120 PRINT MATCOUNT(x%,y%)/10;"%"

**CROSS-REFERENCE**

:ref:`matcount` comparisons are exact in that two
numbers a and b are only regarded as equal if a=b in SuperBASIC terms.
The same is true for strings, it means that their comparison is
case-sensitive. :ref:`matcount1` differs from
:ref:`matcount` (see below) only in the fact that
comparisons are based on the SuperBASIC operator == instead of =.

--------------


..  _matcount1:

MATCOUNT1
=========

+----------+-------------------------------------------------------------------+
| Syntax   || MATCOUNT1 (array, value)  or                                     |
|          || MATCOUNT1 (array1, array2)                                       |
+----------+-------------------------------------------------------------------+
| Location || Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function MATCOUNT1 is just a variation of MATCOUNT which performs
comparisons not as exact as MATCOUNT. Numbers must only be almost equal,
the absolute difference must be smaller than the absolute of the second
number divided by 1E7: ABS (a-b) < ABS (b / 1E7). This is the case if
a==b. MATCOUNT1 is therefore the same as MATCOUNT if integers are being
dealt with. Comparison of strings is not case-sensitive, again this is
analogous to the == operator: "QDOS"=="Qdos" is true while "QDOS"="Qdos" is not.

**CROSS-REFERENCE**

:ref:`matcount`,
:ref:`matequ`.

--------------


..  _matequ:

MATEQU
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATEQU array1, {array2 \| value}                                 |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATEQU sets up array1 in two different ways depending on
the type of the second parameter: (1) If another array array2 of the
same dimensions is supplied then each element of array1 is set to the
corresponding element of array2; or (2) If the second parameter is not
an array but a constant, variable or expression then each element of
array1 is set to the given value. Array1, array2 and value can be of any
type: integer, floating point or string. array1 and array2 must however
be of the same type and have the same number of dimensions.

**Examples**

::

    DIM a$(4,8), a%(2,2,2,2,2), a(0), b$(4,8) 
    MATEQU a$,"Hi there" 
    MATEQU a%,6 
    MATEQU a%,-PI 
    test$=9.5: MATEQU a%,test$ 
    MATEQU a,9.5 
    MATEQU a$,b$

**NOTE**

Supercharge and Turbo users... sorry!

**CROSS-REFERENCE**

:ref:`matrnd`, :ref:`matidn`

--------------


..  _matdev:

MATDEV
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATDEV array[%]                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function takes any numeric array and calculates a number from its
values which gives information about their standard deviation.

**Example**

::

    10 DIM x(10) 
    20 PRINT MATDEV (x)

gives 0 because all elements of x are equal and therefore, have no deviation. Add
the line::

    15 MATRND x,10

and the result will be be around 3.2.

**CROSS-REFERENCE**

:ref:`matmean`

--------------


..  _matidn:

MATIDN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATIDN matrix                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This command forces the square numeric array matrix to be initialised
so that the matrix is given the algebraic identity for matrices of that
size. This gives the matrix the following format::

    1 0 0 . . . 0 0 0
    0 1 0 . . . 0 0 0
    0 0 1 . . . 0 0 0
    . . .       . . .
    . . .       . . .
    . . .       . . .
    0 0 0 . . . 1 0 0
    0 0 0 . . . 0 1 0
    0 0 0 . . . 0 0 1


All elements on the
diagonal line from the top left corner to the bottom right corner are
set to 1 and all other elements are set to 0. This forms the identity
matrix, which means that when a matrix of the same size is multiplied by
this, the resultant matrix is the same as the original matrix, ie.
matrix1 \* matrix = matrix1.

**CROSS-REFERENCE**

:ref:`matmult` multiplies matrices.

--------------


..  _matinput:

MATINPUT
========

+----------+-------------------------------------------------------------------+
| Syntax   |  MATINPUT array [{\\ \| , \| ; \| !}]                             |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATINPUT reads each element of an array in turn from #1, so
that you have to type them all in. The modifiers ';' and '!' place the
cursor behind the last entry whilst ',' moves it to the next tab
position. The default is '\\' which forces a new line between entries -
the '\\' can be omitted.

**Example**

::

    100 DIM a(1,2) 
    110 MATINPUT a,

**CROSS-REFERENCE**

:ref:`matread`,
:ref:`matrnd`, :ref:`for`

--------------


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

--------------


..  _matmax:

MATMAX
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATMAX (array[%])                                                |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function finds the largest value contained in an integer or
floating point array.

**NOTE**

This cannot be compiled with Supercharge or Turbo.

**WARNING**

A string array makes MATMAX hang the system.

**CROSS-REFERENCE**

:ref:`matmin` is the complementary function. See
also :ref:`maximum` and
:ref:`maximum-pct`.

--------------


..  _matmean:

MATMEAN
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATMEAN (array[%])                                               |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function returns the average of the array's elements, calculated
by the sum of the elements divided by the number of elements.

**NOTE**

Don't compile with Supercharge or Turbo.

**WARNING**

Avoid string parameters!

**CROSS-REFERENCE**

See :ref:`matsum` for an example.

--------------


..  _matmin:

MATMIN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATMIN (array[%])                                                |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function finds the smallest element in an integer or floating
point array.

**NOTE**

Cannot be compiled with Supercharge or Turbo.

**WARNING**

A string array makes MATMIN hang the system.

**CROSS-REFERENCE**

:ref:`matmax` is the opposite function. Refer also
to :ref:`minimum` and
:ref:`minimum-pct` which are even quicker.

--------------


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


..  _matplot:

MATPLOT
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATPLOT array [{, \| ;}]                                         |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This command takes a two-dimensional array and draws the points set out 
by the array (the first dimension identifies the number of points and
the second the co-ordinates) to the default window used by LINE
(normally #1). The array must be declared in the following way (an array
which does not fall into this category will cause an error):: 

    DIM array (points,1)
    
points is the total number of points (less one) set out in the array,
with array(p,0) the x-coordinate and array(p,1) the y- coordinate of
point number p-1. If a comma (,) appears after the name of the array
MATPLOT
will connect each point with its successor by a line. 

On the other
hand, if a semicolon (;) appears after the name of the array, an
additional line is drawn between the first point and the last point.

These lines are drawn using the QDOS line drawing routine and therefore
suffer from the same problems as the LINE command. For those of you
still uncertain of the possible uses of this command, a little hint: the
addition of a semicolon to the the parameter will always enclose the set
of lines which have been set out, thereby making this command ideal for
creating all types of shapes (for example dodecahedrons)! MATPLOT
supports INK, PAPER, OVER and FILL.

**Example**

The following fractal generator was written by John de Rivaz in
SuperBASIC and optimised by Simon N. Goodwin. Originally, both the
calculation and drawing was done in one loop which was a bit faster
(10-20%) than the following version (this calculates all points in one
loop and then uses MATPLOT to draw them quickly, creating a second
internal loop). Another disadvantage compared to the original version is
the increase in memory usage because all points have to be stored:: 

    100 MODE 4: WINDOW 512,256,0,0: PAPER 0: CLS 
    110 SCALE 20,-14,-10: iterations=10000 
    120 DIM pts(iterations-1,1): x=0: y=0 
    130 FOR loop=0 TO iterations-1 
    140   pts(loop,0)=x: pts(loop,1)=y 
    150   sy=0: IF x<0 THEN sy=-1: ELSE IF x THEN sy=1 
    160   xx=y-sy\*(ABS(x-.9))^.5: y=1.01-x: x=xx 
    170 END FOR loop 
    180 INK 7: MATPLOT pts

A nice modification of the above example would be to:

- Replace MODE 4 with MODE 8 in line 100; 
- Delete line 180; 
- Add the following block::

    180 REPeat loop 
    190 FOR n=1 TO 7 
    200 INK n 
    210 MATPLOT pts 
    220 END FOR n 
    230 END REPeat loop

It's up to you to produce more variants!

**NOTE**

The output of MATPLOT cannot be redirected to any other window and
specifically any program which uses MATPLOT (eg. the above example)
cannot be compiled. So it is perhaps best to forget about MATPLOT.

**CROSS-REFERENCE**

:ref:`matplot-r` draws the figure relative to
the graphic cursor. :ref:`point` draws a single
point to any screen, :ref:`block` can also be used
to plot points, especially of variable size.
:ref:`plot`, :ref:`apoint` and
:ref:`point-abs` plot points in absolute
co-ordinates, directly to screen memory, ignoring windows.

--------------


..  _matplot-r:

MATPLOT\_R
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  MATPLOT\_R array [{, \| ;}]                                      |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This command is the same as MATPLOT except that the output is drawn
relative to the graphic cursor.

**CROSS-REFERENCE**

:ref:`point` and all other commands related to
graphics move the graphic cursor.

--------------


..  _matprod:

MATPROD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATPROD (array)                                                  |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function MATPROD returns the product of the array's values, so
array is not allowed to be a string array.

**Example**

Can you see why MATPROD and FACT return the same number for every n? 

:: 

    100 n=8: DIM a%(n) 
    110 MATSEQ a% 
    120 PRINT MATPROD(a%) ;" = "; 
    130 PRINT FACT(n+1)

**NOTE**

MATPROD is not compatible with Turbo and Supercharge.

**CROSS-REFERENCE**

:ref:`matprod` is almost identical to
:ref:`matsum` except that it returns the product
rather than the elements' sum; so have a look at
:ref:`matsum` which is also more useful.

--------------


..  _matread:

MATREAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATREAD array                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATREAD initialises the array (of any type) by reading each
element from DATA lines. Since MATREAD does the same as the following
routine:: 

    FOR i1=0 TO DIMN(array,1) 
      FOR i2=0 TO DIMN(array,2) 
        ... 
        READ array(i1, i2) 
        ... 
      END FOR i2 
    END FOR i1
 
all of the normal errors of READ may occur.

**Example**

The following example is identical to MATSEQ a%

::

    100 DIM a%(3,2) 
    110 MATREAD a% 
    120 : 
    130 DATA 1, 2, 3, 4 
    140 DATA 5, 6, 7, 8 
    150 DATA 9,10,11,12

is identical to MATSEQ a%.

**CROSS-REFERENCE**

:ref:`matinput`

--------------


..  _matrnd:

MATRND
======

+----------+-------------------------------------------------------------------+
| Syntax   || MATRND array  or                                                 |
|          || MATRND array% [[ ,minval%] ,maxval%]                             |
+----------+-------------------------------------------------------------------+
| Location || Math Package                                                     |
+----------+-------------------------------------------------------------------+

This command initialises all of the elements of an integer or floating
point array with random numbers. Their default range depends on the type
of array: for integer arrays, the values range from -32768 to 32767,
whereas for floating point they range between 0 and 1. 

MATRND selects
the range itself if there is just one parameter, but for integer arrays
only, an extended syntax allows you to specify another range (as in the
second variant). 

If just a maximum value maxval% is specified then
values range from 0 to maxval%, if a minimum minval% is additionally
given then values range from minval% to maxval%. 

MATRND will reject any
non-integer parameters for the second syntax.

**Examples**

::

    DIM array%(4,3,2), array(1,2): min%=10 
    MATRND array 
    MATRND array% 
    MATRND array%,100 
    MATRND array%,min%,100

**NOTE**

Like all other MAT... commands, MATRND cannot be compiled with
Supercharge or Turbo.

**WARNING**

MATRND allows a string array as a parameter. This leads to odd results
and can possibly hang the machine.

**CROSS-REFERENCE**

The random values chosen by :ref:`matrnd` can be
influenced by :ref:`randomise`.

--------------


..  _matseq:

MATSEQ
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATSEQ array                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATSEQ initialises the array (which must be a numeric
array) with a constantly increasing set of integer numbers: 1 2 3 4 5
6... 

There is not really much use for MATSEQ except for demonstration. 

Array can be either a floating point or integer variable. No strings are allowed.

**CROSS-REFERENCE**

:ref:`matidn` is a useful means of initialising an
array, :ref:`matequ` can be used to set all
elements of an array to a certain value. It is worth noting that any
square matrix created with :ref:`matseq` cannot be
inverted with :ref:`matinv` because the determinant
:ref:`det` of that matrix is always zero::

    100 n=30: DIM m(n,n), minv(n,n) 
    110 MATSEQ m 
    120 MATINV minv,m 

This always fails at line 120 because :ref:`det`\ (m) = 0.

--------------


..  _matsub:

MATSUB
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATSUB difference,matrix1,matrix2                                |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

Provided that the parameters of the command MATSUB fulfil the same
conditions as for MATADD, MATSUB will store the difference between
matrix1 and matrix2 in difference. Difference(...) = matrix1(...) -
matrix2(...). Two or all of the parameters can be identical, so::

    MATSUB a,a,a

and::

    MATSUB a,b,a

etc. are valid.

**CROSS-REFERENCE**

:ref:`matadd`!

--------------


..  _matsum:

MATSUM
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATSUM (array[%])                                                |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

This function calculates the sum of all of the elements of the supplied
array. array can be any floating point or integer array, but not a
string array. The latter leads to error -15 (bad parameter). Array can
be any number of dimensions, although the following example uses just
one dimension for demonstration reasons.

**Example**

If you stored a lot of values, eg. temperatures, in an array and want to
find the average temperature, you have to divide the sum of the
temperatures by the number of values. Obviously the operation of adding
temperatures can take quite some time for a large data base, so this is
a point where MATSUM helps::

    100 values% = 200: DIM temp%(values%) 
    110 : 
    120 PRINT#0,"random initialisation..." 
    130 MATRND temp%,-20,30 
    140 PRINT#0,"equalising"; 
    150 FOR equalize = 1 TO 10 
    160   FOR i = 0 TO values%-1 
    170     temp%(i) = ( temp%(i) + temp%(i+1) ) / 2 
    180   END FOR i 
    190   PRINT#0,"."; 
    200 END FOR equalize 
    210 : 
    220 PRINT#0\\"drawing..." 
    230 WINDOW 448,200,32,16: SCALE 100,0,0 
    240 PAPER 3: CLS: INK 7: OVER 0 
    250 dist = 160 / values%: yoff = 50 
    260 FOR i = 0 TO values%-1 
    270   x1 = i*dist: x2 = x1+dist 
    280   y1 = temp%(i) + yoff: y2 = temp%(i+1) + yoff 
    290   LINE x1,y1 TO x2,y2 
    300 END FOR i 
    310 : 
    320 PRINT#0,"find medium..." 
    330 tmed = MATSUM(temp%) / values% 
    340 INK 3: OVER -1 
    350 LINE 0,tmed+yoff TO x2,tmed+yoff

The important line is 330 where MATSUM is used. Lines 150 to 200
transform the random values to more realistic temperatures: you won't
find any country where outside temperature jumps from -20 to +30 degrees
Celsius in one day! The number of equalize loops can be freely chosen.

This is also true for values%, the figure adapts itself to the number of
values (see dist in line 250).

**NOTE**

A program using MATSUM cannot be compiled with Turbo or Super-charge.

**CROSS-REFERENCE**

:ref:`matrnd` initialises an array with random
values. :ref:`matprod` is very similar to
:ref:`matsum` except that it finds the product of
an array's elements. :ref:`matmean` finds the mean
value of a matrix's values directly, so line 330 could be replaced with::

    330 tmed = MATMEAN(temp%)

--------------


..  _mattrn:

MATTRN
======

+----------+-------------------------------------------------------------------+
| Syntax   |  MATTRN array1, array2                                            |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The command MATTRN takes numeric arrays of two dimensions or string
arrays of three dimensions and reads each row of array2, placing it in
the corresponding column of array1. 

It is obligatory that both arrays
have the same type and are exactly DIMed to the needs of MATTRN. 

The
first dimension of array1 must be equal to the second of array2 and the
first dimension of array2 must be equal to the second of array1. 

For
strings, additionally, the third dimensions of both arrays have to be
equal:: 

    DIM array1(x,y), array2(y,x) 
    DIM array1%(x,y), array2%(y,x) 
    DIM array1$(x,y,z), array2$(y,x,z)

So array1 and array2 can only be of identical dimensions for square
matrices. In all other cases the contents of array1 are not modified.

**Example**

::

    100 DIM A%(2,3), B%(3,2) 
    110 MATRND B%,9: PRINT B%!\ 
    120 MATTRN A%,B%: PRINT A%!\ 
    130 MATTRN B%,A%: PRINT B%!\

--------------


..  _max:

MAX
===

+----------+-------------------------------------------------------------------+
| Syntax   |  MAX (x\ :sup:`1` :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*`)           |
+----------+-------------------------------------------------------------------+
| Location |  Math Package, MINMAX2                                            |
+----------+-------------------------------------------------------------------+

This function must be given at least one number as a parameter - it
will then return the highest value out of the given list of parameters.

**Example**

::

    PRINT MAX ( 2, 5, -10, 3.2 )

will print 5.

**CROSS-REFERENCE**

:ref:`min`. See also
:ref:`maximum` and
:ref:`matmax`.

--------------


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


-------



..  _max-devs:

MAX\_DEVS
=========

+----------+-------------------------------------------------------------------+
| Syntax   | how_many = MAX\_DEVS                                              |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This function returns the number of installed directory device drivers in your QL. It can be used to :ref:`dim`\ ension a string array to hold the device names as follows::

    1000 REMark Count directory devices
    1010 :
    1020 how_many = MAX_DEVS
    1030 :
    1040 REMark Set up array
    1050 :
    1060 DIM device$(how_many, 10)
    1070 :
    1080 REMark Now get device names
    1090 addr = 0
    1100 FOR devs = 1 to how_many
    1110   device$(devs) = DEV_NAME(addr)
    1120   IF addr = 0 THEN EXIT devs: END IF
    1130 END FOR devs


**CROSS-REFERENCE**

:ref:`dev-name`.


-------



..  _maximum:

MAXIMUM
=======

+----------+-------------------------------------------------------------------+
| Syntax   || MAXIMUM [ ( array ) ] or                                         |
|          || MAXIMUM ( :sup:`\*`\ [ value ]\ :sup:`\*` )                      |
+----------+-------------------------------------------------------------------+
| Location || Minmax (DIY Toolkit - Vol Z)                                     |
+----------+-------------------------------------------------------------------+

The effect of this function depends on the parameter supplied. It is
however an extremely fast way of comparing values. If no parameter is
supplied, then the greatest possible floating point number supported by
the QL is returned - this is equivalent to 1.61585 e616. 

If a single
parameter is supplied which is a single dimensional floating point
array, then MAXIMUM will return the value of the largest number stored
within that array. 

If you want to compare the values of an integer
array, then use MAXIMUM% (a 'bad parameter' is generated with this (MAXIMUM)
function). 

If, however, you use the second variant to pass a list of
values (either numbers or variables), then the highest value out of
those parameters will be returned. Please note that you cannot pass an
array in this instance - it is therefore the same as MAX.

**Example**

::

    PRINT MAXIMUM

Returns 1.61585e616 

::

    DIM x(3): x(0)=10: x(1)=200: x(2)=2.5: x(3)=50.4 
    PRINT MAXIMUM (x)

Returns 200.

::

    PRINT MAXIMUM (100, ax ,21*10+ac)

Returns the highest value.

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmax`,
:ref:`maximum-pct` and :ref:`max`
are similar. Refer also to :ref:`minimum` and
:ref:`minimum-pct`.

--------------


..  _maximum-pct:

MAXIMUM%
========

+----------+-------------------------------------------------------------------+
| Syntax   || MAXIMUM% [ ( array% ) ] or                                       |
|          || MAXIMUM% ( :sup:`\*`\ [ value ]\ :sup:`\*` )                     |
+----------+-------------------------------------------------------------------+
| Location || Minmax (DIY Toolkit - Vol Z)                                     |
+----------+-------------------------------------------------------------------+

This function is exactly the same as MAXIMUM except that it only
accepts integer parameters and is therefore able to work much more
quickly. As with MAXIMUM, you can use this function to find the highest
value in an array, provided that the first variant is used, and the
array is a single dimensional integer array. If no parameter is
supplied, then the greatest possible integer number supported by the QL
is returned - this is equivalent to 32767.

**Example**

::

    PRINT MAXIMUM%
    
Returns 32767 

::

    DIM x%(3): x%(0)=10: x%(1)=200: x%(2)=2: x%(3)=50 
    PRINT MAXIMUM% (x%)

Returns 200. 

::

    PRINT MAXIMUM% (100, ax ,21*10+ac)

Returns the highest value as an integer.

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmax`, :ref:`maximum`
and :ref:`max` are similar. Refer also to
:ref:`minimum-pct`.

--------------


..  _mb:

MB
==

+----------+-------------------------------------------------------------------+
| Syntax   |  MB                                                               |
+----------+-------------------------------------------------------------------+
| Location |  Minerva                                                          |
+----------+-------------------------------------------------------------------+

Early versions of Minerva (pre v1.97) did not have built-in MultiBASICs
and they had to be EXECuted from disk. However, you could make them
resident by linking in the file Mulib\_rext with the LRESPR command and
then this command, MB would be available to start up MultiBASIC
interpreters. This is not a very convenient way of starting MultiBASICs
as you cannot pass parameters to the MultiBASIC, nor can you use the
command to run filter programs.

**NOTE**

This command is redudant on Minerva v1.97+, whereby MultiBASICs can be
started up using EXEC pipep.

**CROSS-REFERENCE**

See :ref:`sbasic` and :ref:`ew`.
Also see :ref:`quit`. Check out the appendix on
Multiple BASICs.

--------------


..  _md:

MD
==

+----------+-------------------------------------------------------------------+
| Syntax   |  MD subdir                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Beuletools (Needs Level-2 Drivers)                               |
+----------+-------------------------------------------------------------------+

This command is just used as an abbreviation for the MAKE\_DIR
command on Level-2 (and higher) floppy/ winchester/ ramdisk drivers.

**CROSS-REFERENCE**

An alternative would be to rename
:ref:`make-dir` with :ref:`new-name`\ . See also :ref:`make-dir`\ .

--------------


..  _merge:

MERGE
=====

+----------+-------------------------------------------------------------------+
| Syntax   || MERGE device\_filename  or                                       |
|          || MERGE [device\_]filename (Toolkit II)                            |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

This command is similar to LOAD *except* that it does not clear the
current program and variables out of memory prior to loading the given
program file. Neither is the screen cleared, which enables loading
pictures to be shown on screen whilst the main program loads. 

This means
that any line numbers which appear in the program currently in memory
and which are repeated in the program file will be *overwritten* by the
lines in the program file, whereas any new lines will be inserted into
the program in memory. 

Again, any lines without line numbers are
automatically executed as they are loaded into memory. This could
therefore be used within a program to execute a 'command file' stored on
a directory device (however, see below).

**Example**

A short program - when typed in, save this using the command:: 

    SAVE mdv1_test1_bas

::
    
    10 REMark Test1 
    20 PRINT 'The Sinclair QL'  

Now, type NEW and enter the following short program:: 

    5 REMark Test 
    20 PRINT 'An old program line' 
    30 PRINT 'SuperComputer'  

Now, enter the command::

    MERGE mdv1_test1_bas

followed by:: 

    LIST
    
and the following will now form the program in memory:: 

    5 REMark Test 
    10 REMark Test1 
    20 PRINT 'The Sinclair QL' 
    30 PRINT 'SuperComputer'

**NOTE 1**

Unfortunately, if you MERGE a file of direct commands (ie. a program
file without line numbers), only the first line will be read and the
file will be left open, making it impossible to change the
disk/microdrive cartridge. Some compilers provide commands to ensure
that the file is closed and all of the commands executed. 

Minerva and Toolkit II close the file, but still only the first command is executed,
unless the MERGE command is used from within a program (in which case, the whole of the
command file is executed). SMS ensures that MERGE works in both of these circumstances.

**NOTE 2**

When writing command files, ensure that the lines are all checked
thoroughly before saving them without the line numbers, since a 'bad
line' error on such a file may crash the QL. However, if Toolkit II is
present, this makes a safe recovery, reporting 'bad line'.

**NOTE 3**

MERGE can become confused if used from within a PROCedure or FuNction.
Minerva and Toolkit II both report 'Not Implemented'.

**NOTE 4**

On Minerva v1.86, MERGE could become a little confused when used within
a program.

**NOTE 5**

When used within a program MERGE and MRUN are the same.

**NOTE 6**

Since Toolkit II v2.22 (and on the Minerva version), MERGE
has refused to try and load a file which does not have a file type of 0 - see FTYP.

**SMS NOTE**

MERGE follows the same rules for finding a program name as the LOAD
command.

**CROSS-REFERENCE**

:ref:`mrun` is very similar. See
:ref:`load` and :ref:`save`.
:ref:`do` is also very similar to
:ref:`merge`.

--------------


..  _midinet:

MIDINET
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MIDINET                                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

A file MIDINET\_rext is provided with SMSQ/E and the Emulators for the
Atari computers which allows you to set up a Network using the MIDI
ports provided on the Atari computers. 

Once the Network has been set up
with the necessary leads, and MIDINET\_rext been loaded on all computers
in the Network, the command MIDINET should be issued to start up the
fileserver Job on each computer. This creates a background Job called
'MIDINET' which is similar to the 'Server' Job created by FSERVE. 

The two fileservers are very similar in operation in that they both allow
other computers to access the resources of the Master machine over the
Network. However, MIDINET has built-in protection for files which can
prevent other users in a Network accessing sensitive files. This is
implemented by means of recognising files which *start with* a specific
series of characters:

+------------+-----------------------------------------------------------------------+
| Characters | Effect                                                                |
+============+=======================================================================+
| \*H or \*h | These files cannot be accessed over the Network. Any attempt          |
|            | to use these files by a Slave Machine will return 'Not Found' errors. |
+------------+-----------------------------------------------------------------------+
| \*R        | These files are Read Only over the Network.                           |
+------------+-----------------------------------------------------------------------+
| \*D        | These files cannot be accessed over the Network and will              |
|            | return 'Not Implemented' - this prevents direct sector access.        |
+------------+-----------------------------------------------------------------------+

**CROSS-REFERENCE**

:ref:`mnet` is needed to control the Network. See
also :ref:`fserve` and
:ref:`sernet`. See the Appendix on Networks for
further details.

--------------


..  _min:

MIN
===

+----------+-------------------------------------------------------------------+
| Syntax   |  MIN (x\ :sup:`1` :sup:`\*`\ [,x\ :sup:`i`]\ :sup:`\*`\ )         |
+----------+-------------------------------------------------------------------+
| Location |  Math Package, MINMAX2                                            |
+----------+-------------------------------------------------------------------+

This function must be given at least one number as a parameter - it
will then return the lowest value out of the given list of parameters.

**Example**

::

    100 INPUT "a ="!a 
    110 INPUT "b ="!b 
    120 FOR x=MIN(a,b) TO MAX(a,b): PRINT x

**CROSS-REFERENCE**

:ref:`max` is :ref:`min`'s
counterpart. Compare :ref:`minimum` and
:ref:`matmin`.

--------------


..  _minimum:

MINIMUM
=======

+----------+-------------------------------------------------------------------+
| Syntax   || MINIMUM [ ( array ) ] or                                         |
|          || MINIMUM ( :sup:`\*`\ [ value ]\ :sup:`\*` )                      |
+----------+-------------------------------------------------------------------+
| Location || Minmax (DIY Toolkit - Vol Z)                                     |
+----------+-------------------------------------------------------------------+

The effect of this function depends on the parameter supplied. It is
however an extremely fast way of comparing values. 

If no parameter is
supplied, then the smallest possible floating point number supported by
the QL is returned - this is equivalent to -1e614. 

If a single parameter
is supplied which is a single dimensional floating point array, then
MINIMUM will return the value of the smallest number stored within that
array. If you want to compare the values of an integer array, then use
MINIMUM% (a 'bad parameter' is generated with this function if you attempt to use it for integers). 

If, however, you
use the second variant to pass a list of values (either numbers or
variables), then the smallest value out of those parameters will be
returned. 

Please note that you cannot pass an array in this instance -
it is therefore the same as MIN.

**Example**

::

    DIM x(3): x(0)=10: x(1)=200: x(2)=2.5: x(3)=50.4 
    PRINT MINIMUM (x)
    
Returns 2.5

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmin`,
:ref:`minimum-pct` and :ref:`min`
are similar. Refer also to :ref:`maximum` and
:ref:`maximum-pct`.

--------------


..  _minimum-pct:

MINIMUM%
========

+----------+-------------------------------------------------------------------+
| Syntax   || MINIMUM% [ ( array% ) ] or                                       |
|          || MINIMUM% ( :sup:`\*`\ [ value ]\ :sup:`\*` )                     |
+----------+-------------------------------------------------------------------+
| Location || Minmax (DIY Toolkit - Vol Z)                                     |
+----------+-------------------------------------------------------------------+

This function is exactly the same as MINIMUM except that it only
accepts integer parameters and is therefore able to work much more
quickly. As with MINIMUM, you can use this function to find the smallest
value in an array, provided that the first variant is used, and the
array is a single dimensional integer array. If no parameter is
supplied, then the smallest possible integer number supported by the QL
is returned - this is equivalent to -32768.

**NOTE**

This function cannot be compiled with Supercharge or Turbo if you intend
to pass an array as the parameter.

**CROSS-REFERENCE**

:ref:`matmin`, :ref:`minimum`
and :ref:`min` are similar. Refer also to
:ref:`maximum-pct`.

--------------


..  _mistake:

MISTake
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MISTake                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

MISTake is a keyword which will only rarely ever be found. It cannot be
inserted into a program from the keyboard. Instead, it is generated
internally whenever LOAD, LRUN, MERGE or MRUN
commands are used and a line in the file being loaded cannot be parsed
(ie. if it would generate a 'bad line' error if typed in at the
keyboard). 

Rather than reporting an error and stopping the loading
process, the word MISTake is inserted in the offending line after the
line number. If you then try to RUN the offending line, a 'Bad Line'
error will be generated (under SMS the error 'MISTake in program' is
reported. 

You can however EDIT the offending line - you must delete the
word MISTake as well as correcting the error before the line will be
accepted by the parser. Once this is done, then the program should run
as normal.

**NOTE**

Unfortunately, QREF (from Liberation Software) cannot find lines
containing MISTake - in order to do this, you need a much more complex
system such as MasterBasic+ (from Ergon Development).

**CROSS-REFERENCE**

Please see :ref:`load` and
:ref:`merge` about loading a SuperBASIC program in
general.

--------------


..  _mkf-dlr:

MKF$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MKF$ (float)                                                     |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns a string containing the internal representation
of a floating point number (which is stored as six bytes).

**CROSS-REFERENCE**

:ref:`cvf`, :ref:`mki-dlr`,
:ref:`mks-dlr`, :ref:`mkl-dlr`,
:ref:`peek-f`, :ref:`poke-f`

--------------


..  _mki-dlr:

MKI$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MKI$ (integer%) where integer% = -32768..32767                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

The function MKI$ returns a string containing the internal
representation of an integer number (which is stored as two bytes).

**Example**

::

    MKI$(11111)
    
Would return the string "+g", because::

    CODE("+")*256 + CODE("g")
    
Equals 11111.

**CROSS-REFERENCE**

:ref:`cvi-pct` is the opposite function.
:ref:`mkf-dlr`, :ref:`mkl-dlr`,
:ref:`mks-dlr`

--------------


..  _mkl-dlr:

MKL$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MKL$ (longint) where longint = -2\*INTMAX-1..2\*INTMAX+1         |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns a string containing the internal format of a long
integer number (which is stored as four bytes).

**CROSS-REFERENCE**

:ref:`cvl` is the complementary function.
:ref:`mki-dlr`, :ref:`mkf-dlr`,
:ref:`mks-dlr`

--------------


..  _mks-dlr:

MKS$
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MKS$ (string$)                                                   |
+----------+-------------------------------------------------------------------+
| Location |  BTool                                                            |
+----------+-------------------------------------------------------------------+

This function returns a string containing the internal format of a
string {which is stored as two bytes indicating the length of the string
(as returned by MKI$) and the string itself}.

**Example**
::

    MKS$("Test") = CHR$(0)&CHR$(4) & "Test"

because:: 

    MKI$ (4)
    
returns the string CHR$(0)&CHR$(4).

**CROSS-REFERENCE**

:ref:`cvs-dlr`, :ref:`mki-dlr`,
:ref:`mkf-dlr`, :ref:`mkl-dlr`

--------------


..  _mnet:

MNET
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MNET station                                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+
 
This command is similar to the NET command in that it sets the Network
Station number of the machine on which it is issued. The only difference
is that here it sets the station number for the MIDINET Network (as
opposed to QNET).

**CROSS-REFERENCE**

See :ref:`mnet-pct`,
:ref:`mnet-use` and
:ref:`net`. Also please see
:ref:`midinet`, :ref:`sernet`
and :ref:`fserve`.

--------------


..  _mnet-pct:

MNET%
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  MNET%                                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

This function returns the current station number of the computer as set
with MNET.

**CROSS-REFERENCE**

See :ref:`mnet`. :ref:`net-id`
is similar.

--------------


..  _mnet-off:

MNET\_OFF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  MNET\_OFF                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

This command turns the MIDINET driver off temporarily so that you can
use the MIDI ports independently.

**CROSS-REFERENCE**

See :ref:`mnet-on`.

--------------


..  _mnet-on:

MNET\_ON
========

+----------+-------------------------------------------------------------------+
| Syntax   |  MNET\_ON                                                         |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

This command switches the MIDINET driver back on after it has been
disabled with MNET\_OFF.

**CROSS-REFERENCE**

See :ref:`mnet-off`. Also see
:ref:`midinet`.

--------------


..  _mnet-s-pct:

MNET\_S%
========

+----------+-------------------------------------------------------------------+
| Syntax   |  MNET\_S% (station)                                               |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

This function enables you to check whether a machine with the specified
station number is connected to the MIDINET. This can be useful to
prevent the problem of the Network retrying several times before failing
when asked to send or read data from a Network station which does not
exist.

**CROSS-REFERENCE**

See :ref:`mnet`.

--------------


..  _mnet-use:

MNET\_USE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  MNET\_USE id                                                     |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E, ATARI Emulators                                          |
+----------+-------------------------------------------------------------------+

Due to the fact that MIDINET Networks can be run on computers alongside
SERNET Networks and even QNET Networks, it may be necessary to alter the
identification letter used to access facilties on other computers in the
Network. The default letter id is n (as with FSERVE), but this can be
set to any other single letter by using this command. However, you
should avoid letters which already appear as the first letter in another
device driver (see DEVLIST).

**Example**

::

    MNET_USE m 
    OPEN #3,m2_con_512x256a0x0
    
Open an input channel covering the screen on station number 2 in the
MIDINET Network.

**CROSS-REFERENCE**

See :ref:`mnet` and
:ref:`midinet`. Refer also
to\ :ref:`mnet-s-pct`.

--------------


..  _mod:

MOD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  x MOD y                                                          |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

This operator returns the value of x to modulus y. This is defined as
x-(x DIV y)\*y. If x or y is not an integer value, then it is rounded to
the nearest integer (compare INT). On non-SMS implementations the answer
and both parameters must lie within the range -32768...32767. On SMS,
the answer and both parameters can lie anywhere within roughly -
2e9...2e9.

**Examples**

::

    PRINT 13 DIV 5

gives the result 3. This is because 13 DIV 5 is 2, 2 multiplied by 5 is 10, 13 minus 10 is 3. 

::

    PRINT 13.4 MOD 1.5

gives the result 1 (13 MOD 2).

**NOTE 1**

MOD has problems with the value -32768: PRINT -32768 MOD -1 gives the
result -1 on most implementations. On Minerva v1.76 (or later) and SMS
v2.77+ it gives the correct result, being 0.

**NOTE 2**

If you write a program for SMSQ/E which uses values outside the range
-32768...32767, this will not work on non-SMSQ/E machines - instead of::

    PRINT x MOD y 
    
you will need to use::

    PRINT x - (INT(x / y) * y)

**CROSS-REFERENCE**

:ref:`div` returns the integer part of
x divided by y. Also, please see the alternative version of :ref:`mod`.

--------------


MOD
===

+----------+-------------------------------------------------------------------+
| Syntax   |  MOD (x,y)                                                        |
+----------+-------------------------------------------------------------------+
| Location |  Math Package                                                     |
+----------+-------------------------------------------------------------------+

The function MOD returns the value x-(DIV(x,y)\*y), ie. the value of x
to modulus y, in a similar fashion to the ROM based operator MOD.

However, this version is not limited to a range of -32768 to 32767, but
will accept parameters in the range -INTMAX to INTMAX. Because both
versions of MOD return the integer remainder of a division, x MOD 0 or
MOD(x,0) lead to an overflow error, because division by zero is
undefined.

**NOTE 1**

Both versions of MOD can be used in the same program, although the Turbo
and Supercharge compilers will not accept this alternative form.

**NOTE 2**

If you try to use a program compiled under Turbo or Supercharge after
loading the Math Package, if the program uses the normal SuperBASIC
operator MOD or DIV, an error will be generated and the program will
refuse to work!

**CROSS-REFERENCE**

:ref:`div` :ref:`mod` (ROM version)

--------------


..  _mode:

MODE
====

+----------+----------------------------------------------------------------------------------+
| Syntax   || MODE mode%  or                                                                  |
|          || MODE screen\_mode [,display\_type] (Minerva, Q-Emulator, Amiga-QDOS v3.23+)  or |
|          || MODE [screen\_mode [,display\_type]](PEX only)                                  |
+----------+----------------------------------------------------------------------------------+
| Location || QL ROM, PEX                                                                     |
+----------+----------------------------------------------------------------------------------+

The original QDOS operating system will only recognise two display
modes: Low resolution and High resolution. However, the following MODEs
are currently set aside for use by QDOS compatible systems:

+------+-----------------+---------+--------------------+
| MODE | Resolution      | Colours |  System            |
+======+=================+=========+====================+
| 2    | 640 x 400       | 2       | SMS-2              |
+------+-----------------+---------+--------------------+
| 4    | <=1000 x 400    | 4       | SMS-2              |
+------+-----------------+---------+--------------------+
| 4    | 768 x 280       | 4       | ST/QL, Ext. MODE 4 |
+------+-----------------+---------+--------------------+
| 4    | <=1024 x 1024   | 4       | QVME               |
+------+-----------------+---------+--------------------+
| 4    | <=800 x 600     | 4       | QXL, QXL II, QPC   |
+------+-----------------+---------+--------------------+
| 4    | 512 x 256       | 4       | QDOS and others    |
+------+-----------------+---------+--------------------+
| 8    | 256 x 256       | 8       | QDOS and others    |
+------+-----------------+---------+--------------------+
| 8    | 256 X 256       | 4       | ST/QLs             |
+------+-----------------+---------+--------------------+
| 12   | 256 x 256       | 16      | THOR XVI           |
+------+-----------------+---------+--------------------+

The MODE command is used to select the mode and redraw all windows.
Without Qjump's Window Manager WMAN, the screen mode is set globally,
whereas if WMAN (or SMSQ/E) is installed (this is highly recommended),
MODE will only affect the current job. 

The parameter mode% can be any
legal integer between -32768 and 32767. However, to ensure compatibility
with other systems one of the above four values should be used. Normally
if a system does not support the mode type selected, MODE 4 is selected.

The MODE command also resets the current status of UNDER, FLASH, CSIZE
and OVER. 

Without specialised software, only one screen mode can be used
at a time (even with the specialised software contained in the Quanta
library, the screen can only be split in two horizontally). 

The second
variant is supported on Minerva, Q-Emulator (for the MacIntosh), PEX and
the Amiga QDOS Emulator (v3.23+) and allows you to dictate the type of
display used. The display\_type can be one of four values (the default is -1):

+---------------+---------------------------------------+
| Display\_type | Effect                                |
+===============+=======================================+
| 0             | Set to monitor mode                   |
+---------------+---------------------------------------+
| 1             | Set to TV (625 lines) mode (European) |
+---------------+---------------------------------------+
| 2             | Set to TV (525 lines) mode (American) |
+---------------+---------------------------------------+
| -1            | Leave display type as it is           |
+---------------+---------------------------------------+

On the PEX variant, if you do not specify any parameters, MODE will default to MODE
4,0

**NOTE 1**

Normally, High resolution is described as MODE 4 because this value
represents a characteristic of the mode (4 colours) as well as setting
it. Equally, MODE 8 stands for Low resolution. However, with the ability
of QDOS to access much higher resolution screens, these terms now tend
to be somewhat unecessary.

**NOTE 2**

Unfortunately for Minerva users who wish to run software in dual screen
mode, current versions of the Pointer Interface do not allow you to have
different MODEs on each of the two screens (the pointer interface fails
to recognise that a program is running on the second screen only and
does not therefore affect the main display screen located at $20000).
Speedscreen may also give problems in Minerva's dual screen mode unless
the 'p' version is used.

**NOTE 3**

If you want to make your programs appear more professional, you should
always seek to cut out unnecessary MODE commands (see RMODE), also
because of the fact that MODE tends to re-draw all of the current
windows (clearing them in their current paper and border colours as it
works), it is always an idea to ensure that all currently opened windows
are set to black paper and black (or no) border before issuing this
command.

**NOTE 4**

On an American JSU QL (which was adapted for use with the American
525-line TV picture, as opposed to the British 625-line TV picture),
only 192 lines of pixels are allowed instead of the normal 256 in MODE 4
and MODE 8 (when the QL is linked to a TV). There are less and less
users using their QL with a TV set nowadays and therefore this can be
largely ignored. In any event, software should generally still run on an
American QL without modification (the lower number of available lines on
the TV screen ensures that pictures still appear to retain the same
height/width ratio).

**NOTE 5**

If you are planning to use the dual screen mode, it is essential that
you ensure that the current screen is also the displayed screen before
opening windows or using the MODE command - see below.

**NOTE 6**

The standard screen modes are MODE 4 and MODE 8. MODE 8 is however only
supported on a limited number of implementations. It is supported by the
original QL, some early ST-QL Emulators and Amiga-QDOS (v3.23+).

**DUAL SCREEN MODE**

Minerva and some other implementations allow you to have two screens
which can both be accessed by the user (and can be switched between by
pressing <CTRL><TAB>). Each of these two screens (if you are in dual
screen mode), can support a different mode. In order to cater for these
new features, screen\_mode is very complex, and to make it worse, it is
important to know which screen is the default screen (see DEFAULT\_SCR).

Programs which use the normal MODE commands will still work under dual
screen mode, since the new version of the MODE
command will only work if the display\_type is specified. 

When the QL
is first started, unless you choose <F3> or <F4> (on Minerva), only one
screen will be available for use by programs, otherwise Minerva is
placed into Dual Screen Mode. 

In the dual screen mode, after starting up
the QL, the default screen is scr0 (located at $20000 - the normal QL
display screen). The second screen (scr1) is located at $28000 and is
known as the Other Screen. 

To make matters worse, each job present in
the QL's memory will be allocated its own default screen, being the
current default when it was started. A job can therefore alter its own
current default screen without upsetting the rest of the system. 

Before proceeding any further it is important to realise that the Displayed
Screen (what you can see on your TV/monitor) and the Default Screen are
not necessarily one and the same thing. Oh, it is also important to know
that a screen can also be either visible or blank (this is so that work
can be prepared on a screen without the user being able to see the
process). Perhaps some definitions might help: 

Displayed Screen:
    This is the screen which is currently in front of the user on his/her monitor or TV. 

Default Screen:
    The screen on which a program's windows will be opened and upon which the normal MODE 4 and MODE 8 commands will have an effect. 

Other Screen:
    The opposite to the Default Screen (ie. if the Default Screen is scr0, then the Other Screen will be scr1). 

Visible Screen:
    This means that the specified screen can actually be seen by the user. 

Blank Screen:
    The specified screen is invisible to the user (allows background work to be carried out). 

That's the definitions out of the way, and hopefully, they will provide a better understanding of what is to follow. The command::
    
    OPEN#3,scr_448x200a32x16
    
will open a new window on the current Default Screen. After this, any
subsequent commands using #3 will be shown on that screen (whether or
not it is still the current Default Screen). 

Problems may exist with
some Toolkit functions which do not check to see where the screen starts
for the given window, and just assume that the screen starts at $20000.

Unfortunately, current versions of Lightning and the Pointer Interface
introduce various problems to the Dual Screen Mode, the most important
one of which is that the screen will not be re-drawn unless the current
screen is also the Displayed Screen. 

Another plus to the altered MODE
command is that there is no forced re-draw of all the current windows
unless you specify that this must be carried out (or if you use the
original MODE variants). 

In order to try and explain the new display\_mode
parameters, it is easier to split it into two sections: toggling current
values and setting absolute values.

**Toggling the Screen Parameters**

This uses the format MODE 64+n,-1, where:

+----+----------------------------+----------+------------+
| n  | Effect                     | From:    | To:        |
+====+============================+==========+============+
| 1  | Toggle Other Screen        | Visible  | Blank      |
+----+----------------------------+----------+------------+
| 2  | Toggle Default Screen      | Visible  | Blank      |
+----+----------------------------+----------+------------+
| 4  | Toggle Other Screen Mode   | 4-colour | 8-colour   |
+----+----------------------------+----------+------------+
| 8  | Toggle Default Screen Mode | 4-colour | 8-colour   |
+----+----------------------------+----------+------------+
| 16 | Toggle Displayed Screen    | scr0     | scr1       |
+----+----------------------------+----------+------------+
| 32 | Toggle Default Screen      | scr0     | scr1       |
+----+----------------------------+----------+------------+

Adding together different values of n will combine these
effects (although if one of the values is to be 32, the default screen
will be toggled before anything else is carried out).

**Examples**

::

    MODE 64+16,-1: PAUSE: MODE 64+16,-1

Show both screens. 

::

    MODE 64+4+8,-1

Toggle the mode of both screens Details of the values used to set
absolute screen parameters appear on the next page.

**Setting Absolute Screen Parameters**

This uses the format MODE -128 + m - 256 \* t + c, -1

where: 

- m = k1\*n1 + k2\*n2 + k3\*n3 +...
- t = n1 + n2 + n3 +...n
- c = (see below) 
- n can have the same values as above, depending on which effect is to be altered. 
- k1, k2, k3 etc. have the following effect upon the corresponding values of n1, n2, n3, etc.


+---+---------------------------+
| k | Sets n to:                |
+===+===========================+
| 0 | The 'from..' column above |
+---+---------------------------+
| 1 | The 'to..' column above   |
+---+---------------------------+

+--------+----------------------------+
| c      | Effect                     |
+========+============================+
| 0      | Do not redraw any screens  |
+--------+----------------------------+
| -16384 | Re-draw the Other Screen   |
+--------+----------------------------+
| 32768  | Re-draw the Default Screen |
+--------+----------------------------+
| 16384  | Re-draw both screens       |
+--------+----------------------------+
 
Again, different effects can now be combined
with relevant values for each n and k. If you wish to toggle any effects
at the same time, simply add the corresponding value of n to the first
parameter. Some Minerva manuals do not have the correct formula for
calculating these values, which can lead to some peculiar results.
Changing the default screen will again take precedence to all other
changes.

**Dual Screen Examples**

::

    MODE 4

change the Default Screen to MODE 4 and re-draw all currently opened
windows on the Default Screen. 

::

    MODE 64+32,-1

toggle current Default Screen. 

::

    MODE 64+32+16,-1

toggle current Default Screen and show to user. 

::

    MODE -17791,-1

blank out Other Screen and then force it into 4-colour mode, redrawing
all windows, Where does -17791 come from? The formula given above::

    -128 + m - 256*t + c

Into which we substitute the following::
    
    t = 1 + 4 
    m = 1*1 + 0*4 
    c = -16384

Care must however be taken when opening channels if the two screens are
in different modes - on versions of Minerva earlier than v1.97, if you
open a channel on the non-Displayed Screen, it will have the
characteristics of a window opened in the mode of the Displayed Screen
(although sadly this does not mean that you can have a MODE 4 window in
the middle of a MODE 8  screen). To ensure that the current Default 
Screen is the current Displayed Screen, use:: 

    MODE -128 + DEFAULT_SCR * 16 - 256 * 16, -1

**Q-EMULATOR NOTE**

Q-Emulator for the Apple MacIntosh computer supports Minerva's dual
screen mode and the extended MODE command.

**AMIGA-QDOS NOTE**

From v3.23, the Amiga-QDOS Emulator also supports Minerva's dual screen
mode and the extended MODE command. Before this version, it did not
support MODE 8. Even now, FLASH is not supported in MODE 8.

**WARNING 1**

Changing the display\_type may have odd effects, especially if Qjump's
Button Frame (part of QPAC2) is present.

**WARNING 2**

On pre JS ROMs, if you open a screen (scr\_) or console (con\_) channel
after a MODE command, the ink and paper colours for the new channel
could both be 0 (black).

**WARNING 3**

On pre Minerva ROMs, MODE alters the value contained in the system
variable SYS.DTYP (also known as SV.TMOD) which normally contains a
value from 0...2 showing the type of TV/Monitor the QL is set up for.
Speedscreen, the Pointer Environment and Lightning all fix this.

**CROSS-REFERENCE**

:ref:`rmode` can be used to read the current screen
mode (and even whether the second screen is available) and
:ref:`default-scr` will tell you which is the
current default screen. :ref:`screen`\ (#3) will
tell you the address of the start of the screen on which window #3 is
situated. :ref:`disp-size` can be used to set
the size of the displayed screen on extended resolutions.

--------------


..  _more:

MORE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MORE [#ch,] filename                                             |
+----------+-------------------------------------------------------------------+
| Location |  MORE (DIY Toolkit - Vol V)                                       |
+----------+-------------------------------------------------------------------+

This command adds a quite sophisticated file viewing facility to the QL
which far surpasses the simple Toolkit II VIEW command. 

In its simplest
form, MORE will open a channel to the specified filename (adding the
data default directory if the file does not exist) and display it in the
specified window channel (default #1). If #ch does not refer to a window
or is #0, then bad parameter will be reported. The file will then be
displayed in the specified channel, one window full at a time. #0 is
used by the command to display the length of the file in bytes and the
number of the last byte displayed in the window. 

You can move around the
file by using the following keys: 

- <ENTER> - Allows you to enter a file position to look at (this will be the first byte displayed in the window). 
- <ALT><UP> - This moves back up the file one page at a time.
- <ALT><DOWN> - This moves down the file one page at a time. 
- <DOWN> - Move down the file one line.
- <ESC> - Leave MORE. 

MORE can however, also be used to look at the QL's memory (or that on a networked computer) by using the
MEM device. In this mode, only the address of the last byte on screen is
shown in #0 - there is no file length. For example:: 

    MORE #2,MEM
    
will allow you to use MORE to page through the whole of the QL's
memory. 

::

    MORE #2,n2_MEM

allows you to page through the whole of another computer's memory. 

::

    OPEN #3,MEM7_60p: PRINT #3,'Hello World': CLOSE #3

creates a permanent buffer (MEM7) and stores two words in it. If you follow the above by::

    MORE #2,MEM7

then you will be able to look at the contents of the buffer MEM7.

**NOTE**

Trying to use MORE on anything other than files or MEM
devices (for example on named pipes) will cause problems - press
<CTRL><SPACE> a few times to escape from this.

**CROSS-REFERENCE**

Refer to the Devices Appendix for more details on MEM. 

Compare::

    COPY flp1_test_bas to SCR

and::


    VIEW flp1_test_bas


--------------


..  _mouse-speed:

MOUSE\_SPEED
============

+----------+------------------------------------------------------------------+
| Syntax   | MOUSE\_SPEED [#ch,] acceleration, wakeup                         |
+----------+------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                   |
+----------+------------------------------------------------------------------+

This function adjusts the mouse acceleration and wake up factor. The acceleration factor is of no consequence to QPC2. The wakeup values, however, may still be set. They range from 1 to 9, with 1 being the most sensitive.

--------------


..  _mouse-stuff:

MOUSE\_STUFF
============

+----------+-------------------------------------------------------------------+
| Syntax   | MOUSE\_STUFF [#ch,] hot$                                          |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for QPC                                                    |
+----------+-------------------------------------------------------------------+

This function adjusts the string that is stuffed into the keyboard queue when the middle mouse button is pressed (or both left and right buttons are pressed simultaneously). The string cannot be longer than two characters, but this is enough to trigger any hotkey, which in turn, can do almost anything.

**Example**

::

    MOUSE_STUFF '.'
    
Generates a dot if middle mouse button is pressed.

::

    MOUSE_STUFF CHR$(255) & '.' 
    
Generates hotkey <Alt><.> which will activate whatever has been defined on that key combination.

--------------


..  _move:

MOVE
====

+----------+-------------------------------------------------------------------+
| Syntax   |  MOVE [#ch,] distance                                             |
+----------+-------------------------------------------------------------------+
| Location |  QL ROM                                                           |
+----------+-------------------------------------------------------------------+

The QL supports a simplified means of drawing pictures known as turtle
graphics. This was based upon an early educational tool, whereby simple
commands could be entered into a computer to drive a small robot turtle
which moved around the floor and held a pen. This pen could either be up
in which case the turtle would just move around, or down in which case a
line would be left by the turtle on the floor as it moved. 

When a window
is first opened, an invisible turtle appears at the graphics origin
(altered with SCALE) facing to the right, with its pen in the up
position. 

The command MOVE forces the turtle in the specified window
(default #1) to move in the current direction by the specified distance.

The actual distance moved on screen depends on the current SCALE
applicable to that window. If distance is negative, the turtle will move
backwards. MOVE always works from the current graphics cursor position,
and after using this command, the current graphics cursor is placed at
the turtle's position on screen. MOVE is affected by the current INK
colour, FILL and also OVER, just like any other graphics command.

**Example**

A simple procedure to draw a shape of a set number of equal length
sides::

    100 DEFine PROCedure POLYGON (chan, sides, side_length) 
    110   TURNTO #chan,0: PENDOWN #chan 
    120   FOR k = 1 TO sides 
    130     MOVE #chan, side_length
    140     TURN #chan, 360 / sides 
    150   END FOR k 
    155   PENUP #chan 
    160 END DEFine

Try for example, POLYGON #2,5,10.

**NOTE**

The THOR XVI v6.40 tended to crash when using turtle graphics,
especially if a channel number was specified.

**CROSS-REFERENCE**

:ref:`pendown` forces the pen into the down
position, leaving a trail on screen. :ref:`penup`
allows the turtle to move without leaving a trail.
:ref:`turn` and :ref:`turnto`
allow you to alter the direction of the turtle.

--------------


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



..  _move-position:

MOVE\_POSITION
==============

+----------+-------------------------------------------------------------------+
| Syntax   | MOVE\_POSITION #channel, relative\_position                       |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

This is a similar  procedure to :ref:`abs-position`, but the file pointer is set to a position relative to the current one.  The direction given can be positive to move forward in the file, or negative to move backwards. The channel must of course be opened to a file on a directory  device.  If the position given would take you back to before the start of the file, the position is left at the start, position 0.  If the move would take you past the end of file, the file is left at end of file.

After a MOVE\_POSITION command, the next access to the given channel, whether read or write, will take place from the new position.


**EXAMPLE**

::

    MOVE_POSITION #3, 0
    
moves the current file pointer on channel 3 to the start of the file.    

::

    MOVE_POSITION #3, 6e6
    
moves the current file pointer on channel 3 to the end of the file.    


**CROSS-REFERENCE**

:ref:`abs-position`.


-------



..  _mrun:

MRUN
====

+----------+-------------------------------------------------------------------+
| Syntax   || MRUN device\_filename  or                                        |
|          || MRUN [device\_]filename (Toolkit II)                             |
+----------+-------------------------------------------------------------------+
| Location || QL ROM, Toolkit II                                               |
+----------+-------------------------------------------------------------------+

This command is similar to MERGE except that once the two programs have
been merged, if MRUN was issued as a direct command, then the merged
program is RUN from line 1. However, if MRUN was used from within the
program, the statement following the MRUN statement is executed, thus
making this command the same as MERGE when used within a program.

**CROSS-REFERENCE**

See :ref:`merge`!

--------------


..  _msearch:

MSEARCH
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  MSEARCH (add1 TO add2, tofind$)                                  |
+----------+-------------------------------------------------------------------+
| Location |  MSEARCH (DIY Toolkit - Vol X)                                    |
+----------+-------------------------------------------------------------------+

This function is very similar to the Tiny Toolkit version of the SEARCH
function except that it performs an extremely fast case-independent
search through memory (much more quickly than other implementations).

**CROSS-REFERENCE**

See :ref:`search` and
:ref:`ttfindm` also.
:ref:`search-mem` is a variant on this
version.

--------------


..  _mt:

MT
==

+----------+-------------------------------------------------------------------+
| Syntax   |  MT (i,n)                                                         |
+----------+-------------------------------------------------------------------+
| Location |  Toolfin                                                          |
+----------+-------------------------------------------------------------------+

The function MT returns the value of (1+i)\ :sup:`n` where i and n can be
any floating point numbers. Instead of reporting an overflow error for
values which cannot be computed (eg. i=-1, n=-1) MT returns 1. If the
returned value would be too large, a modulated value is returned. It is
therefore imperative that the programmer takes care that the parameters
are correct, otherwise the return values may not make much sense.

**Example 1**

MT gives you a factor which indicates the increase (i>1) or decrease
(i<1) of capital at an interest rate i over a number of periods n. The
gain is known as compound interest. If you give any sum to a bank at an
interest rate of five percent (ie. annual 5 per 100 increase) for (say)
ten years, you will gain 62.9% because: MT(0.05, 10) = 1.628895

**Example 2**

::

    MT(1/n,n) 
    
approximates EXP(1) for large values of n.

**CROSS-REFERENCE**

:ref:`va`, :ref:`vfr`,
:ref:`var`, :ref:`tca`,
:ref:`tnc`, :ref:`tee`,
:ref:`rae`, :ref:`rafe`

--------------


..  _mtrap:

MTRAP
=====

+----------+-------------------------------------------------------------------+
| Syntax   || MTRAP key [,d1 [,d2 [,d3 [,a0 [,a1 ]]]]] or                      |
|          || MTRAP key\\jobnr [,d2 [,d3 [,a0 [,a1 ]]]]]                       |
+----------+-------------------------------------------------------------------+
| Location || TRAPS (DIY Toolkit Vol T)                                        |
+----------+-------------------------------------------------------------------+

This command is similar to QTRAP in that it allows you to access the
machine code TRAP #1 system calls directly. Unless you are using the
second variant, you will need to pass at least one parameter, the
operation key to be carried out (this is equivalent to the value in D0
when TRAP #1 is performed). The other parameters allow you to pass the
various register values which may be required by the system calls. 

The
second variant is useful for when you are using a TRAP #1 call which
requires a job ID - you can merely pass the jobnr of the required job,
obtained from the JOBS list (rather than having to set D1 to the Job
ID). For example to force remove Job 12, use the command:: 

    MTRAP 5\12,0,0

**WARNING**

Several TRAP #1 calls can crash the computer - make certain that you
know what you are doing!

**CROSS-REFERENCE**

See :ref:`io-trap`,
:ref:`qtrap` and :ref:`btrap`.
:ref:`remove-task` and
:ref:`rjob` are better for removing Jobs. Any return
parameters can be read with :ref:`datareg` and
:ref:`addreg`. Refer to the QDOS/SMS Reference
Manual (Section 15) for details of the various system TRAP #3 calls.

