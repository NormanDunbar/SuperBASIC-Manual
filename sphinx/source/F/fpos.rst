..  _fpos:

FPOS
====

+----------+-------------------------------------------------------------------+
| Syntax   |  FPOS [(#channel)]                                                |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI, BTool                                      |
+----------+-------------------------------------------------------------------+

This function returns the current position of the file pointer.

The relevant file must already be open as #channel, default channel is #3. A
value of zero means that the file pointer is at the very beginning of a
file, whereas a position equivalent to the file length means that it
points to the very end. The file pointer is a means by which the QL can
keep track of exactly whereabouts in a file it should take the next
input from, or write to.

**CROSS-REFERENCE**

:ref:`file-pos` works exactly as
:ref:`fpos` but does not use a default channel.
:ref:`file-ptra` and
:ref:`file-ptrr` move the file pointer, which
may also be set with :ref:`get`,
:ref:`put`, :ref:`bget` and
:ref:`bput`.

--------------


