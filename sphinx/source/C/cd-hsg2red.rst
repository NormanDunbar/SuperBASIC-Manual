..  _cd-hsg2red:

CD\_HSG2RED
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  CD\_HSG2RED (address)                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E for QPC                                                   |
+----------+-------------------------------------------------------------------+

There are two common formats used to address sectors on a CD directly.
The standard format is REDBOOK format, which uses a time index to
calculate the sector to address.

This time index is in the form $00MMSSFF where MM is the minute, SS the
second and FF the frame.

There are 75 frames in one second.

The other format is HSG FORMAT where the sector is calculated by
reference to the formula:

HSG=(minute\*60+second)\*75+frame

This function takes the address in HSG format and converts this to
REDBOOK format.

**CROSS-REFERENCE**

:ref:`cd-red2hsg` allows you to convert
REDBOOK format addresses to HSG format.

:ref:`cd-hour`,
:ref:`cd-minute` and
:ref:`cd-second` allow you to find out the
hours, minutes and seconds referred to by a REDBOOK address.

