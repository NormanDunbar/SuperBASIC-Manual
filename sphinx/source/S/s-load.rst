..  _s-load:

S\_LOAD
=======

+----------+-------------------------------------------------------------------+
| Syntax   |  S\_LOAD adr                                                      |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit                                                      |
+----------+-------------------------------------------------------------------+

S\_LOAD takes an address (adr) returned by S\_SAVE and displays the
saved screen just like S\_SHOW does. Additionally, the reserved memory
to which adr points is released so that it can be used for other
purposes. S\_LOAD therefore only works once on a given address.

**NOTE 1**

Under odd conditions S\_LOAD will load and show more than had been
stored with S\_SAVE. The Win... set of commands replace the S\_... set
and get around these problems.

**NOTE 2**

S\_LOAD assumes that it needs to copy the stored screen to $20000 and
that will not therefore work on Minerva's second screen. It also assumes
the screen is 512x256 pixels and will not work on higher resolutions or
under dual screen mode.

**WARNING**

A wrong address leads to crashes!

--------------


