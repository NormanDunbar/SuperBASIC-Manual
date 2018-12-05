..  _read-header:

READ\_HEADER
============

+----------+-------------------------------------------------------------------+
| Syntax   | error = READ\_HEADER(#channel, buffer)                            |
+----------+-------------------------------------------------------------------+
| Location | DJToolkit 1.16                                                    |
+----------+-------------------------------------------------------------------+

The file that is opened on the given channel has its header data read into memory starting at the given address (buffer). The buffer address must have been reserved using :ref:`reserve-heap`, or some similar command.

The buffer must be at least 64 bytes long or unpredictable results will occur. The function will read the header but any memory beyond the end of the buffer will be overwritten if the buffer is too short. After a successful call to this function, the contents of the buffer will be as follows :

+---------------+-----------------+------------------------------------------+
| Address       | Value           | Size                                     |
+===============+=================+==========================================+
| Buffer + 0    | File length     | 4 bytes long (see :ref:`file-length`)    |
+---------------+-----------------+------------------------------------------+
| Buffer + 4    | File access     | 1 byte long - currently zero             |
+---------------+-----------------+------------------------------------------+
| Buffer + 5    | File type       | 1 byte long  (see :ref:`file-type`)      |
+---------------+-----------------+------------------------------------------+
| Buffer + 6    | File dataspace  | 4 bytes long (see :ref:`file-dataspace`) |
+---------------+-----------------+------------------------------------------+
| Buffer + 10   | Unused          | 4 bytes long                             |
+---------------+-----------------+------------------------------------------+
| Buffer + 14   | Name length     | 2 bytes long, size of filename           |
+---------------+-----------------+------------------------------------------+
| Buffer + 16   | Filename        | 36 bytes long                            |
+---------------+-----------------+------------------------------------------+

Directory devices also have the following additional data :

+---------------+-----------------+------------------------------------------+
| Address       | Value           | Size                                     |
+===============+=================+==========================================+
| Buffer + 52   | Update date     | 4 bytes long (see :ref:`file-update`)    |
+---------------+-----------------+------------------------------------------+
| Buffer + 56   | Reference date  | 4 bytes long - see below                 |
+---------------+-----------------+------------------------------------------+
| Buffer + 60   | Backup date     | 4 bytes long (see :ref:`file-backup`)    |
+---------------+-----------------+------------------------------------------+

Miracle Systems hard disc's users and level 2 users will find the files version number stored as the the 2 bytes starting at buffer + 56, the remaining 2 bytes of the reference date seem to be hex 094A or decimal 2378 which has no apparent meaning, this of course may change at some point!

This function returns an error code if something went wrong while attempting to read the file header or zero if everything  went ok.  It can be used as a more efficient method of finding out the details for a particular file rather than calling all the various FILE_XXX functions. Each of these functions internally call the READ\_HEADER routine.

To extract data, use :ref:`peek` for byte values, :ref:`peek-w` for the filename length and version number (if level 2 drivers are present, see LEVEL2), or :ref:`peek-l` to extract 4 byte data items.

The filename can be extracted from the buffer by something like::

    f$ = PEEK_STRING(buffer + 16, PEEK_W(buffer + 14)).

**EXAMPLE**
The following example allows you to change the current dataspace requirements for an :ref:`exec`\ utable file::

    6445 DEFine PROCedure ALTER_DATASPACE
    6450   LOCal base, loop, f$, ft, nv
    6455   base = RESERVE_HEAP (64)
    6460   IF base < 0 THEN
    6465     PRINT "ERROR: " & base & ", reserving heap space."
    6470     RETurn
    6475   END IF
    6480   REPeat loop
    6485     INPUT'Enter filename:';f$
    6490     IF f$ = '' THEN EXIT loop
    6495     ft = FILE_TYPE(f$)
    6500     IF ft < 0 THEN
    6465       PRINT "ERROR: " & ft & ", reading file type for " & f$ & "."
    6510     END IF
    6515     IF ft <> 1 THEN
    6520       PRINT f$ & 'is not an executable file!'
    6525       NEXT loop
    6530     END IF
    6535     PRINT 'Current dataspace is:'; FILE_DATASPACE(f$)
    6540     INPUT 'Enter new value:'; nv
    6545     OPEN #3,f$ : fer = READ_HEADER (#3,base)
    6550     IF fer < 0 : CLOSE #3 : PRINT "READ_HEADER error: " & fer : NEXT loop
    6555     POKE_L base + 6,nv
    6560     fer = SET_HEADER(#3,base)
    6565     IF fer < 0 : PRINT "SET_HEADER error: " & fer
    6570     CLOSE #3
    6575   END REPeat loop
    6580   RELEASE_HEAP base
    6585 END DEFine ALTER_DATASPACE


**CROSS-REFERENCE**

:ref:`set-header`, :ref:`file-length`,
:ref:`file-type`, :ref:`file-dataspace`,
:ref:`file-update`, :ref:`file-backup`.


-------


