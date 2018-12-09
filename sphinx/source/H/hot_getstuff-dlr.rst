..  _hot_getstuff-dlr:

HOT_GETSTUFF$
=============

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT_GETSTUFF$ [index]                                            |
+----------+-------------------------------------------------------------------+
| Location |  SMSQ/E                                                           |
+----------+-------------------------------------------------------------------+

This function returns the contents of the hotkey stuffer buffer. If given a
parameter of 0, or no parameter, it will return the current contents of the
stuffer buffer (like ALT-SPACE). A parameter of -1 gets the previous contents,
like ALT-SHIFT-SPACE

**Examples**

::

    result = HOT_GETSTUFF$     : REMark Return current contents of stuffer buffer
    result = HOT_GETSTUFF$(0)  : REMark Return current contents of stuffer buffer
    result = HOT_GETSTUFF$(-1) : REMark Return previous contents of stuffer buffer


**CROSS-REFERENCE**

See :ref:`get_stuff-dlr`, :ref:`hot_stuff`.

