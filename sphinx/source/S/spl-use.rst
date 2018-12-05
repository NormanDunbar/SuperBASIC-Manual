..  _spl-use:

SPL\_USE
========

+----------+-------------------------------------------------------------------+
| Syntax   |  SPL\_USE name                                                    |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

This command sets the default destination device and therefore has a
similar effect to DEST\_USE. However, this command is slightly improved,
in that if the supplied name does not end in an underscore, this is
taken to be an external device port (such as SER) and no underscore is
added.

**Examples**

::

    DEST_USE flp2_Quill: COPY ram2_Letter_doc

will copy the file ram2\_letter\_doc to flp2\_Quill\_letter\_doc.

::

    SPL_USE ser: COPY ram2_Letter_txt

will copy the file ram2\_Letter\_txt to the serial port, ser.

**NOTE**

SPL\_USE will overwrite the default destination device set with
DEST\_USE.

**CROSS-REFERENCE**

:ref:`destd-dlr` returns the current default
destination device. Also see :ref:`prog-use`,
:ref:`dlist`,
:ref:`data-use`,
:ref:`dest-use`,
:ref:`ddown`, :ref:`dup`, and
:ref:`dnext`.

--------------


