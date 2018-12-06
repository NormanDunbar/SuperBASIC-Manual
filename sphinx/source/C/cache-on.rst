..  _cache-on:

CACHE\_ON
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  CACHE\_ON                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMS, Super Gold Card                                             |
+----------+-------------------------------------------------------------------+

This command enables any internal caches which may be available on your
operating system. This is in fact the default.

Caches are a means of storing computer instructions in fast memory and
cutting down on the time taken by a computer to execute those
instructions.

Normally a computer chip works is fed a program in a series of numbers
representing commands, a format which is known as machine code. This
machine code operates at a very low level - the SuperBASIC command PRINT
a$ would need several hundred machine code commands to have any effect
on screen). The later Motorola chips (not 68000 or 68008) used by QLs
and Amigas (and also the newer chips on PCs and ATARIs) all have
on-board caches which can hold a certain number of these machine code
instructions. If, while the program is running, it accesses those
instructions again within a short time (ie. before the cache becomes
full), then the chip can execute that series of commands again very
quickly.

Although caches can therefore speed up many programs, some computer
programs were written in the days before caches were available for the
QL and compatibles, and therefore will not work if the cache is switched
on. This is particularly true of some of the commands used by the Turbo
compiler which contain self-modifying code, thus meaning that storage of
a chunk of instructions is self-defeating.

**CROSS-REFERENCE**

:ref:`cache-off` allows you to disable the
caches.

