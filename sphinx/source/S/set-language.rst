..  _set-language:

SET\_LANGUAGE
=============

+----------+------------------------------------------------------------------+
| Syntax   | SET\_LANGUAGE country$  or                                       |
|          |                                                                  |
|          | SET\_LANGUAGE [country$] (THOR XVI v6.41 only)                   |
+----------+------------------------------------------------------------------+
| Location | THOR range                                                       |
+----------+------------------------------------------------------------------+

The command SET\_LANGUAGE takes a string or name parameter and attempts
to change the keyboard layout to the first one with a name of which the
given parameter is an abbreviation (this comparison is
case-independent). If the parameter is an empty string (or not
specified), the next keyboard layout is selected. Ideally, in a program,
the full name of the layout would be used for clarity. The search is
circular which means that for example, if SET\_LANGUAGE d was used, the
Danish (Dansk) keyboard layout would be adopted rather than the German
(Deutsch) layout, unless the Danish layout was already selected. The
current keyboard layouts are supported:

+--------+---------------+-----------------------+
| Number | Country$      | Language              |
+--------+---------------+-----------------------+
| 1      | International | None specific         |
+--------+---------------+-----------------------+
| 2      | British       | English               |
+--------+---------------+-----------------------+
| 3      | Dansk         | Danish                |
+--------+---------------+-----------------------+
| 4      | Deutsch       | German                |
+--------+---------------+-----------------------+
| 5      | Espanol       | Spanish (v4.20+ only) |
+--------+---------------+-----------------------+
| 6      | Français      | French                |
+--------+---------------+-----------------------+
| 7      | HELLAS        | Greek                 |
+--------+---------------+-----------------------+
| 8      | Suisse        | Swiss                 |
+--------+---------------+-----------------------+
| 9      | Svensk        | Swedish (v4.20+ only) |
+--------+---------------+-----------------------+

**Examples**

::

    SET_LANGUAGE ""

jump to next keyboard layout in list.

::

    SET_LANGUAGE 'Esp'

set layout to Spanish layout.

**NOTE 1**

Connected with each keyboard layout, there is also a national
translation table, which you will need to install by using the command
TRA 1.

**NOTE 2**

On THOR's equipped with a JS ROM, Français must be enclosed in quotation
marks as it is an invalid variable name.

**NOTE 3**

The second variant of the command should not really be used as it is
only supported on the v6.41 ROM for the THOR XVI. This has the same
effect as::

    SET_LANGUAGE "".

**CROSS-REFERENCE**

:ref:`language-dlr` returns the name of the current
keyboard layout in use. Before v6.41 of the THOR XVI, the keys
<ALT><SYSREQ> had the same effect as :ref:`set-language`. On v6.41, this keying was altered
to call a Job called Alt\_SysReq (Case dependent).
:ref:`lang-use` allows SMS to use different
languages for messages and errors. See also
:ref:`kbd-table`.

