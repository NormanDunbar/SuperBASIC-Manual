..  _hot-stuff:

HOT\_STUFF
==========

+----------+-------------------------------------------------------------------+
| Syntax   |  HOT\_STUFF string$                                               |
+----------+-------------------------------------------------------------------+
| Location |  HOTKEY II                                                        |
+----------+-------------------------------------------------------------------+

The Hotkey System II allows you to pass information to a program by
using an area of memory known as the Hotkey Stuffer Buffer. The contents
of this buffer can be placed into the current keyboard queue by pressing
<ALT><SPACE> to read the last item to have been placed into the Stuffer
Buffer, or <ALT><SHIFT><SPACE> to read the previous item to have been
placed in the Stuffer Buffer.

The keys used to recall the Stuffer
Buffers can be configured by using the program CONFIG on the file
HOT\_REXT.

Each item can by default be a maximum of 512 characters long
(although this can be configured from between 128 and 16384 characters
if you wish). Note that two of the characters are used to store the
length of the Stuffer Buffer and must therefore be deducted from this
setting.

The command HOT\_STUFF allows you to place the specified
string$ into the Stuffer Buffer so that it may be read by other
programs. If the Stuffer Buffer was previously empty, both <ALT><SPACE>
and <ALT><SHIFT> <SPACE> will return the same, however, if something was
already in the Stuffer Buffer, this will be read by <ALT><SHIFT><SPACE>,
and the new entry as <ALT><SPACE>.

**Example 1**

Place an address in the Stuffer Buffer::

    HOT_STUFF '10 Hardacre Way' & CHR$(10) & 'Hardacre' &CHR$(10) & 'Newcastle'

**Example 2**

Presuming an empty Stuffer Buffer, after::

    HOT_STUFF 'DIR flp1_'

the Stuffer Buffer would look like this::

    <ALT><SHIFT><SPACE> --- DIR flp1_
    <ALT><SPACE> --- DIR flp1_

If you then use::

    HOT_STUFF 'DIR flp2_'

the Stuffer Buffer would look like this::

    <ALT><SHIFT><SPACE> --- DIR flp1_
    <ALT><SPACE> --- DIR flp2_

**NOTE**

HOT\_STUFF "" caused various problems until SMS v2.73 - see GET\_STUFF$.
It could even crash compiled programs!!

**CROSS-REFERENCE**

:ref:`get-stuff-dlr` allows a program to read the
contents of the Stuffer Buffer. :ref:`hot-list`
will allow you to see the contents of the Stuffer Buffer.
:ref:`hot-go` is required before <ALT><SPACE> or
<ALT><SHIFT> <SPACE> will work!

--------------


