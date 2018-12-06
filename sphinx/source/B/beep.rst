..  _beep:

BEEP
====

+----------+----------------------------------------------------------------------------+
| Syntax   | BEEP length, pitch [,pitch\_2, grd\_x, grd\_y [,wrap [,fuzz [,rndom ]]]] or|
|          |                                                                            |
|          | BEEP                                                                       |
+----------+----------------------------------------------------------------------------+
| Location | QL ROM                                                                     |
+----------+----------------------------------------------------------------------------+

This command allows you to access the QL's rather poor sound generation
chip. It can be extremely difficult to use this command, and a lot of
trial and error will generally be needed before you can find anything
similar to the sound you are after.

BEEP without any parameters will turn off the sound altogether. You must
also be aware of the fact that as soon as a BEEP command is encountered,
the QL will cancel the current sound and emit the new one (whether or
not the earlier sound had finished).

Each of the various parameters have different ranges and different
effects on the sound produced:

-  `length` This specifies the duration of the sound in 72 microsecond
   units (there are one million microseconds in a second). A length of
   zero means emit the sound until another BEEP command is encountered.
   The range is 0...32767 (a value of 32767 lasts for approximately 2.36
   seconds).

-  `pitch` This affects the tone of the sound produced. The allowable
   range is 0...255. A pitch of 0 is the highest which can be produced,
   ranging to 255 which is the deepest tone. The purity of the sound
   will be affected if any other parameters are specified.

-  `pitch_2` This represents a second pitch level, which will have no
   effect if the tone is the same (or higher) than pitch. If however,
   the value of this parameter is higher (the tone is lower) than that
   of pitch, this specifies a range between which the sound can 'bounce'
   by use of the next two parameters, creating a sequence of notes (the
   length of the sequence will depend on the length parameter).

-  `grd_x` Assuming that the BEEP command is now being used to produce a
   sequence of notes, this parameter specifies the time interval (in 72
   microsecond units) of each note in the sequence. The permitted range
   is again 0...32767. Larger time intervals make each note in the
   sequence more distinct (low values tend to produce just buzzing).

-  `grd_y` This parameter specifies the step between each note in the
   sequence. This must be in the range 0...15. However, this may make
   more sense if the correct range was said to be -7..8.

   A value of zero produces no step - you are returned to a single note
   again.

   A value between 1 and 7 means that each note will be that many
   pitches below the last one (unless that would bring the pitch below
   `pitch_2`).

   A value of 8 makes the BEEP command fit as many notes into the
   sequence (in the range) as possible.

   Values of 9 to 15 (or -7 to -1) mean that each note will be that many
   pitches above the last one (these correspond to the values 7 to 1
   respectively), unless this would bring the pitch above pitch. When
   the top or bottom of the range pitch to pitch\_2 is reached, the step
   direction is reversed to cause the sound to 'bounce'.

-  `wrap` If this parameter is specified, the range of notes between the
   two pitch parameters will be repeated the specified number of times
   before the step direction is altered. The range for this parameter is
   0..15.

   The last note in the range will not be sounded, but will appear as
   the first note in the opposite direction.

-  `fuzz` This affects the purity of each note, by blurring its sound. The
   effective range is 8...15, with a value of 15 producing an awful
   buzz.

-  `rndom` This parameter allows you to specify a certain amount of
   'randomness' which is to be added to each note.

   The effective range is once again 8...15, with the given value being
   used to alter from how far away from the original sequence the QL can
   pick a note. The higher the value, the more random notes appear in
   the sequence.


**Examples**

BEEP 0,20,40,10070,2

will keep sounding every other note between 20 and 40 moving down and
then up the scale.

BEEP 0,20,30,10070,2,1

will sound the notes in the following sequence 20, 22, 24, 26, 28, 20,
22, 24, 26, 28, 30, 28, 26, 24, 22, 30, 28, 26,....


**NOTE 1**

On all ROMs if you set a very high pitch value, the QL finds it very
difficult to read the keyboard. BEEP 0,0 and BEEP 0,1 will make typing
rather difficult.


**NOTE 2**

Unless used on a THOR XVI, BEEP does not enter the QL into supervisor
mode and therefore if BASIC is trying to use BEEP whilst a task is
loaded or unloaded, then the system is likely to crash!


**NOTE 3**

BEEP does not do anything on ST/QLs or the Amiga-QDOS Emulator (pre
v3.23).


**NOTE 4**

The pitch of the sound is actually shifted on QLs by different values of
length, fuzz and rndom. The length of the sound is also somewhat
dependent on the pitch! Both of these problems are however fixed by the
replacement co-processor Hermes.


**CROSS-REFERENCE**

:ref:`beeping` allows you to check if a sound is
currently being emitted.

:ref:`pause` allows you to specify a time interval
during which the computer will wait (allowing you to play much longer
notes).

