..  _spl:

SPL
===

+----------+-------------------------------------------------------------------+
| Syntax   |  SPL {input \| #ch} [TO {output \| #ch}]                          |
+----------+-------------------------------------------------------------------+
| Location |  Toolkit II, THOR XVI                                             |
+----------+-------------------------------------------------------------------+

It can sometimes be useful to copy a file in the background. The
command SPL sets up a small Job which runs at a low priority and acts as
a print spooler, reading the whole of the input data from the given
input device as quickly as possible and then just outputting the data
when it can. Although control is returned to the calling program quite
quickly, both the input and output files are left open until SPL
has completed its job.

SPL is mainly for outputting files to a printer
in the background (allowing you to carry on other work in the meantime).

If however, a file is specified as the output, the SPL
command acts like COPY\_O, except in the background. If output is not
specified, the SPL command uses the default destination device. Existing
channel numbers may also be specified as the input
and output names, provided that both channels are already open for
input and output respectively.

**Examples**

::

    SPL flp1_Example_txt TO SER

prints the file flp1\_Example\_txt in the background.

::

    SPL_USE SER:
    SPL flp1_Example_txt

this is the same as example 1.

**WARNING**

If the default destination device is a directory device and you do not
specify a file for output, the SPL job may never complete its task and
leave files open.

**CROSS-REFERENCE**

See :ref:`copy-o` and
:ref:`splf`. :ref:`spl-use`
and :ref:`dest-use` allow you to alter the
default destination device.

