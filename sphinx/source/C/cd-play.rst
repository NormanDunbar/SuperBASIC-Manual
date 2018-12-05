..  _cd-play:

CD\_PLAY
========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_PLAY [start [,end]]                                          |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

This command allows you to play the tracks on an audio CD once it has
been initialised. If no parameters are specified, QPC will play the
whole of the CD in the CD-ROM drive.

This command will not slow the operation of SMSQ/E and returns
immediately that the CD starts playing.

The parameters allow you to specify the start and end tracks to be
played. These parameters are given either as track numbers or as sectors
in REDBOOK format (if bit 31 of the parameter is set). A sector on an
Audio CD is 2352 bytes.

To set bit 31, add the value $80000000 or 2^31

**Examples**

CD\_PLAY

plays the whole disk

CD\_PLAY 10

play track 10 to the end of the disk

CD\_PLAY 5,CD\_TRACKSTART(5)+$80000000

play track 5 only.

A program which will play all of the tracks on an Audio CD in a random
order:

::

    100 INPUT 'Has the CD-ROM Drive already been initialised ? [y] ';an$
    110 IF an$=='n': CD_INIT
    120 IF NOT CD_ISINSERTED
    130   IF CD_ISCLOSED : CD_EJECT
    140   INPUT 'Place a CD in the drive and press <ENTER> ';an$
    150   CD_CLOSE
    160   IF NOT CD_ISINSERTED
    170     PRINT 'NO CD LOADED ':PAUSE :STOP
    180   END IF
    190 END IF
    200 tracks=CD_LASTTRACK-CD_FIRSTTRACK
    210 DIM played% (tracks)
    220 FOR i=1 to tracks
    230   REPeat Floop
    240     play=RND(1 TO tracks)
    250     IF played%(play)=0: played%(play)=1: EXIT Floop
    260   END REPeat Floop
    270   CD_PLAY play,play
    280   REPeat Ploop: IF NOT CD_ISPLAYING: EXIT Ploop
    290 END FOR i

**CROSS-REFERENCE**

:ref:`cd-init` allows SMSQ/E to recognise a CD
drive.

:ref:`cd-stop` pauses playing

:ref:`cd-eject` opens the disk drawer to allow
you to insert a new CD.

:ref:`cd-close` closes the disk drawer.

:ref:`cd-isinserted` allows you to check if
a CD is in the drive.

--------------


