..  _dev-list:

DEV\_LIST
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  DEV\_LIST [#channel]                                             |
+----------+-------------------------------------------------------------------+
| Location |  DEV device, GOLD CARD, ST/QL, SMS                                |
+----------+-------------------------------------------------------------------+

This command lists all DEV\_USE definitions to the given channel,
default #1. You can also use a public domain utility, DEV Manager, to
set and list DEV definitions on a per-program basis.


**Example**

DEV\_LIST for example 4a of DEV\_USE prints::

    DEV1_ FLP2_SOURCES_ -> DEV4_
    DEV2_ FLP1_COMPILER_ -> DEV3_
    DEV3_ FLP1_COMPILER_UTILS_ -> DEV4_
    DEV4_ RAM1_ -> DEV5_
    DEV5_ FLP1_SOURCES_OTHER_ -> DEV1_


**CROSS-REFERENCE**

:ref:`dev-use`,
:ref:`dev-use-dlr`,
:ref:`dev-next` Compare
:ref:`devlist` and
:ref:`dlist`.

--------------


