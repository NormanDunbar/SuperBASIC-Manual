..  _pe-bgoff:

PE\_BGOFF
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  PE\_BGOFF                                                        |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E  >= 3.12                                                  |
+----------+-------------------------------------------------------------------+

Classic versions of the Pointer Environment suspend any jobs that are "buried"
in the window stack and try to output onto their window. Some system extensions
like :ref:`pie`, :ref:`pice` and :ref:`pex` implemented work-arounds for this, allowing jobs to
continue running in the background even with output to the screen.

Starting from version 3.12, SMSQ/E supports background window I/O and update
natively. This feature is enabled and disabled by the commands :ref:`pe-bgon` and
PE\_BGOFF.

**Example**

::

    PE_BGOFF

Disables background window I/O.

**CROSS-REFERENCE**

See :ref:`peoff`,
:ref:`pie-on`,
:ref:`pxoff`,
:ref:`pe-bgon`.

