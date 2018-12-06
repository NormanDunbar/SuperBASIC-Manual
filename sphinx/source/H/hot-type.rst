..  _hot-type:

HOT\_TYPE
=========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_TYPE (key$)                                                 |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

This function is useful to find out the type of hotkey associated with
the specified keypress. The values returned by HOT\_TYPE are as follows:

- -8 Hotkey for Last line recall
- -6 Hotkey for recall previous Stuffer Buffer
- -4 Hotkey for recall current Stuffer Buffer (HOT\_STUFF)
- -2 Hotkey stuffs a defined string into the keyboard queue (HOT\_KEY)
- 0 Hotkey PICKS SuperBasic and stuffs a command into #0 (HOT\_CMD)
- 2 Hotkey DOES code
- 4/5 Hotkey executes a Thing (HOT\_THING,HOT\_RES,HOT\_CHP)
- 6 Hotkey executes a File (HOT\_LOAD)
- 8 Hotkey PICKS a Job (HOT\_PICK)
- 10/11 Hotkey WAKES or executes a Thing (HOT\_WAKE, HOT\_RES1, HOT\_CHP1)
- 12 Hotkey WAKES or executes a File (HOT\_LOAD1)

**CROSS-REFERENCE**

:ref:`hot-name-dlr` returns the name of the Thing
or the string being accessed.

