..  _default-scr:

DEFAULT\_SCR
============

+----------+-------------------------------------------------------------------+
| Syntax   |  DEFAULT\_SCR                                                     |
+----------+-------------------------------------------------------------------+
| Location |  Fn (v1.02 or later)                                              |
+----------+-------------------------------------------------------------------+

This function is really only useful on a Minerva ROM (although it will
work quite happily on any other ROM). It is sometimes useful when
writing programs which are to run in Minerva's dual screen mode to
discover which is the default screen. This is made necessary because all
new windows which are opened, and all MODE commands operate on the
current default screen.

This therefore means that if a program is badly
written, it is possible that whilst the program is running the default
screen is switched, giving the result that some of its windows are
opened on scr0 and some on scr1. PRINT DEFAULT\_SCR
will return 0 or 1 depending whether the default screen is scr0 or
scr1. If Minerva is not in dual screen mode, or if Minerva is not
present, 0 will be returned.


**Example**

A program to change the MODE of the current program safely (ie. it will
only alter the MODE of the screen in which the program is running)::


    100 This_JOB=DEFAULT_SCR
    110 SET_MODE 8
    120 :
    200 DEFine PROCedure SET_MODE (alp)
    210   IF RMODE(This_JOB)=alp:RETurn
    220   IF This_JOB=DEFAULT_SCR:MODE alp:RETurn
    230   MODE 64+32,-1:MODE alp:MODE 64+32,-1
    240 END DEFine


**CROSS-REFERENCE**

:ref:`mode` alters the mode of the current screen and
job and can be used to alter the current default screen,
:ref:`rmode` returns the mode of the given screen.

