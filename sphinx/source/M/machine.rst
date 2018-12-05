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


