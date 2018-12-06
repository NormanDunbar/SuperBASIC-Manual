..  _err-xx:

ERR\_XX
=======

+----------+-------------------------------------------------------------------+
| Syntax   | ERR\_NC, ERR\_NJ, ERR\_OM, ERR\_OR, ERR\_BO, ERR\_NO, ERR\_NF,    |
|          |                                                                   |
|          | ERR\_EX, ERR\_IU, ERR\_EF, ERR\_DF, ERR\_BN, ERR\_TE, ERR\_FF,    |
|          |                                                                   |
|          | ERR\_BP, ERR\_FE, ERR\_XP, ERR\_OV, ERR\_NI, ERR\_RO, ERR\_BL     |
+----------+-------------------------------------------------------------------+
| Location | QL ROM                                                            |
+----------+-------------------------------------------------------------------+

These are logical functions which return either 0 or 1 if the
corresponding error has occurred. Only one of them can have the value 1
at any time.

+----------+-------------------------+
| Function | Error Code              |
+==========+=========================+
| ERR\_NC  | NOT COMPLETE        -1  |
+----------+-------------------------+
| ERR\_NJ  | INVALID JOB         -2  |
+----------+-------------------------+
| ERR\_OM  | OUT OF MEMORY       -3  |
+----------+-------------------------+
| ERR\_OR  | OUT OF RANGE        -4  |
+----------+-------------------------+
| ERR\_BO  | BUFFER OVERFLOW     -5  |
+----------+-------------------------+
| ERR\_NO  | CHANNEL NOT OPEN    -6  |
+----------+-------------------------+
| ERR\_NF  | NOT FOUND           -7  |
+----------+-------------------------+
| ERR\_EX  | ALREADY EXISTS      -8  |
+----------+-------------------------+
| ERR\_IU  | IN USE              -9  |
+----------+-------------------------+
| ERR\_EF  | END OF FILE         -10 |
+----------+-------------------------+
| ERR\_DF  | DRIVE FULL          -11 |
+----------+-------------------------+
| ERR\_BN  | BAD NAME            -12 |
+----------+-------------------------+
| ERR\_TE  | TRANSMISSION ERROR  -13 |
+----------+-------------------------+
| ERR\_FF  | FORMAT FAILED       -14 |
+----------+-------------------------+
| ERR\_BP  | BAD PARAMETER       -15 |
+----------+-------------------------+
| ERR\_FE  | FILE ERROR          -16 |
+----------+-------------------------+
| ERR\_XP  | ERROR IN EXPRESSION -17 |
+----------+-------------------------+
| ERR\_OV  | ARITHMETIC OVERFLOW -18 |
+----------+-------------------------+
| ERR\_NI  | NOT IMPLEMENTED     -19 |
+----------+-------------------------+
| ERR\_RO  | READ ONLY           -20 |
+----------+-------------------------+
| ERR\_BL  | BAD LINE            -21 |
+----------+-------------------------+


**NOTE 1**

These functions are not affected by REPORT.

**NOTE 2**

On Minerva pre v1.98, the ERR\_XX functions were returning 1 if any higher
error had occurred!!

**WARNING**

The JS ROM version of ERR\_DF had a bug which crashed the system when
used. All later operating systems and Toolkit II, the THOR XVI, the
Amiga-QL Emulator, TinyToolkit, and BTool fix this.

**CROSS-REFERENCE**

See Appendix for other languages.

--------------

