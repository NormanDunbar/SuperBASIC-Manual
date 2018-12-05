..  _sbytes:

SBYTES
======

+----------+------------------------------------------------------------------------------+
| Syntax   | SBYTES device\_file,start,length  or                                         |
|          |                                                                              |
|          | SBYTES device\_file,start[,length[,data[,extra[,type]]] (Minerva v1.80+)  or |
|          |                                                                              |
|          | SBYTES [device\_]file,start,length(Toolkit II)  or                           |
|          |                                                                              |
|          | SBYTES #channel,start,length(SMS only)                                       |
+----------+------------------------------------------------------------------------------+
| Location | QL ROM, Toolkit II                                                           |
+----------+------------------------------------------------------------------------------+

It can sometimes be useful to save part of the QL's memory to a file so
that it can be loaded back into the computer at a later date. The area
of memory saved may for example, contain a program, some machine code or
some data.

The command SBYTES allows you to save length number of bytes
from the QL's memory, starting from the specified start address. The
area of memory is saved to the specified file which must include the
name of the device to be used, unless Toolkit II is present, in which
case the default data device is supported. The Toolkit II variant will
also provide you with the option of overwriting the file if it already
exists.

**Example**

To save the currently displayed screen on a standard QL, use the
command::

    SBYTES flp1_Example_scr,SCREEN,32768

Or under SMS, you can save any size screen using::

    SBYTES flp1_Example_scr, SCR_BASE, SCR_LLEN * SCR_YLIM


The start of a program which was protected by a password could be
written along the lines of this::

    100 a=ALCHP(100)
    110 IF FTEST(flp1_pass)=0
    120   LBYTES flp1_pass,a
    130 END IF
    140 pass$=''
    150 PAPER#0,0:CLS#0:INK#0,7
    160 PRINT #0,'Enter Password :';
    170 FOR letter=1 TO 4
    180   pass$=pass$&INKEY$(-1)
    190   PRINT#0,'*';
    200 END FOR letter
    210 PRINT #0
    220 IF PEEK(a)=0
    230   offset=RND(1 TO 50)
    240   POKE a,offset
    250   FOR i=1 TO 4
    260     POKE a+i,CODE(pass$(i))+i+offset
    270   END FOR i
    280   FOR i=5 TO 100:POKE a+i,RND(100)
    290   SBYTES flp1_pass,a,100
    300 ELSE
    310   offset=PEEK(a)
    320   FOR i=1 TO 4
    330     IF CODE(pass$(i))<>PEEK(a+i)-i-offset
    340       PRINT 'Access Denied':RECHP a:STOP
    350     END IF
    360   END FOR i
    370 END IF
    380 PRINT 'Access Granted' 390 RECHP a


**NOTE 1**

On Minerva ROMs (pre v1.80), if SBYTES was aborted for some reason
whilst writing to a file, the file would be deleted. On later versions
of Minerva and all other QL ROMs, the incomplete file is kept and on
Toolkit II, the error 'Medium Full' is reported.

**NOTE 2**

On Minerva ROMs (pre v1.83) SBYTES set the wrong file type.

**NOTE 3**

The Minerva variant is unfortunately overwritten by the Toolkit II
version of this command.

**MINERVA NOTES**

On Minerva v1.80 (or later) the commands SBYTES and SEXEC have
practically become interchangeable, as both support exactly the same
parameters. All of the parameters except for the start address and
device\_file where the data is to be stored, are optional and will
default to 0 if not specified.

These additional parameters have the
following uses:

- Extra This sets the value which is normally returned with FXTRA (which would normally have to be altered with SetHEAD).
- Type This allows you to set two file attributes:

  - the file type - this is normally 0 for data, or 1 for executable programs. This is calculated by PRINT type && 255.
  - the file access key - it is generally used by Toolkits such as QL-System to store various file attributes (such as whether a file is read-only). This is calculated by PRINT type DIV 256.

The only problem with using this extended version of SBYTES instead of using SEXEC is that you must remember to specify a file type of 1 if the file is later to be EXECuted (as this defaults to 0 in the
case of SBYTES!).

For example, both of these are the same::

    SBYTES ram1_test_exe, code_start, 20000, 500, 0, 1
    SEXEC ram1_test_exe, code_start, 20000, 500

**SMS NOTE**

The fourth variant of the command allows you to save the bytes to an
existing channel which is already OPEN to a file, thus allowing you to
work more efficiently. You can use the following to error trap the
saving routine::

    100 REPeat loop
    110   ch=FOP_NEW (ram1_test_bin)
    120   IF ch<0
    130     REPORT ch
    140     PRINT "Press <y> to retry, <n> to stop"
    150     REPeat kLoop
    160       key$=INKEY$(-1)
    170       IF key$ INSTR 'yn':EXIT kLoop
    180     END REPeat kLoop
    190     IF key$=='y':NEXT loop
    200     STOP
    210   END IF
    220   SBYTES #ch,131072,32768
    230   EXIT loop
    240 END REPeat loop
    250 CLOSE #ch

**CROSS-REFERENCE**

:ref:`sbytes-o` and
:ref:`sexec` are very similar.
:ref:`data-use` allows you to alter the current
default data device. :ref:`lbytes` allows you to
load in a block of code which has been saved with
:ref:`sbytes` or :ref:`sexec`.

--------------


