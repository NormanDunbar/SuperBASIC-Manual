..  _wman-dlr:

WMAN$
=====

+----------+-------------------------------------------------------------------+
| Syntax   |  WMAN$                                                            |
+----------+-------------------------------------------------------------------+
| Location |  TinyToolkit, BTool                                               |
+----------+-------------------------------------------------------------------+

This function returns the version number of the Window Manager. If no
Window Manager is present, WMAN$ returns an empty string.

**Example 1**

SCR\_SIZE is incompatible with the Window Manager because the channel
definition blocks for windows are different from those used when no
Window Manager is present, causing SCR\_SIZE to return wrong values or
produce errors. But calculating the result of SCR\_SIZE is so simple
that it can be replaced by a BASIC procedure to be used whenever the
Window Manager is detected. w\_width and w\_height define the window
size.

::

    100 IF LEN(WMAN$) THEN
    110   size=8+w_width*w_height/8
    120 ELSE size=SCR_SIZE
    130 END IF

**Example 2**

Non-destructible windows can be simulated by programs if there is no
Window Manager present to take over that work.

::

    100 OPEN#3,con_200x50a100x50
    110 IF WMAN$="" THEN ScrTmp=S_SAVE(#3)
    120 BORDER#3,1,4: PAPER#3,3: CLS#3

    ...... (main program using #3) ...

    800 CLOSE#3
    810 IF WMAN$="" THEN S_LOAD ScrTmp
    820 STOP

**CROSS-REFERENCE**

:ref:`qram-dlr` returns the version number of the
Pointer Interface.

