.. _soundfile2:

SOUNDFILE2
==========

+----------+-------------------------------------------------------------------+
| Syntax   | SOUNDFILE2 filename$[,rep%]                                       |
+----------+-------------------------------------------------------------------+
| Location | SMSQ/E for Q68                                                    |
+----------+-------------------------------------------------------------------+

Loads and plays a sound file through the SMSQ/E Sampled Sound
System. If rep% is present the file will be played rep%+1 times.

Just like SOUNDFILE except using another job owned by the caller so
that the command returns immediately.

**Note 1**

The file is not loaded into memory so it should be played from a fast
device like a ram disk.

**CROSS-REFERENCE**

:ref:`soundfile`,
:ref:`soundfile3`,
:ref:`killsound`
     
     
