..  _hot-name-dlr:

HOT\_NAME$
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_NAME$ (key$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The function HOT\_NAME$ returns the name of the Thing or the string
associated with the specified hotkey. A null string is returned if the
hotkey is not defined.

**Example**

::


    ERT HOT_RES ('/',flp2_Qram): ERT HOT_KEY ('s','Yours Sincerely','')
    HOT_GO
    PRINT HOT_NAME$ ('/') , HOT_NAME$('s')

will show the following: Qram Yours Sincerely

**CROSS-REFERENCE**

:ref:`hot-list` will list details about all
currently defined hotkeys, :ref:`hot-type`
allows you to verify the type of hotkey defined.

--------------


