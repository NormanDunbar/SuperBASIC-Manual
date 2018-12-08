..  _print-using:

PRINT\_USING
============

+----------+----------------------------------------------------------------------+
| Syntax   |  PRINT\_USING [#ch,] format$, :sup:`\*`\ [item\ :sup:`i`]\ :sup:`\*` |
+----------+----------------------------------------------------------------------+
| Location |  Toolkit II                                                          |
+----------+----------------------------------------------------------------------+

This command allows you to send output to the specified channel
(default #1) in a particular format. This for example, allows you to
print neat columns of figures easily, all lined up on the decimal point.

The format$ is made up of a mixture of special characters, text and
fields. Basically, PRINT\_USING will print out format$ as normal, until
one of these special characters is met. The special characters currently
supported are: © (copyright) + - ( # \* , . ! \\ ' " and $. These have
the following effects:

..  tabularcolumns::    |c|p{0.8\textwidth}|

+-----------+----------------------------------------------------------------------+
| Character | Effect                                                               |
+===========+======================================================================+
| ©         | This forces PRINT\_USING to print out the next character in format$  |
|           | even if it is a special character. If you want to print some text    |
|           | including one of the special characters, this must be used.          |
+-----------+----------------------------------------------------------------------+
| \+        | This is used to either prefix or postfix a decimal field. If         |
|           | present, then the sign of the decimal number is written out in       |
|           | this position.                                                       |
+-----------+----------------------------------------------------------------------+
| \-        | This is used to either prefix or postfix a decimal field. The sign   |
|           | of the decimal number will only be written in this position if the   |
|           | number is negative.                                                  |
|           | This and the closing bracket can be used to surround a               |
|           | decimal field, in which case if the number is negative, it will      |
|           | appear in brackets.                                                  |
+-----------+----------------------------------------------------------------------+
| #         | (Hash) This is used to mark a type of field (see below).             |
+-----------+----------------------------------------------------------------------+
| \*        | (Asterisk) This is also used to mark a type of field (see below).    |
+-----------+----------------------------------------------------------------------+
| \\        | This will force a newline to take place. Unlike PRINT, PRINT\_USING  |
|           | does not automatically carry out a newline after finishing its work. |
+-----------+----------------------------------------------------------------------+
| " and '   | Anything between either single or double quotation marks will be     |
|           | printed out without looking for special characters.                  |
+-----------+----------------------------------------------------------------------+
| $         | This is used to signify the start of a currency field. Any           |
|           | characters between this sign and the next '#' symbol are taken to be |
|           | the name of the currency and are pushed right to line up with the    |
|           | actual amount.                                                       |
+-----------+----------------------------------------------------------------------+

The fields in the format$ allow you to print
text and/or figures in specific formats. Each item following format$ is
then read and inserted in place of each field. If however, a numeric
field is not long enough to hold the specified figure, then the field
appears as just '#' marks on screen. Text fields will just truncate the
text supplied to fit. The fields which are recognised are:

..  tabularcolumns::    |l|p{.8\textwidth}|

+----------------+-----------------------------------------------------------------------+
| Field          | Meaning                                                               |
+================+=======================================================================+
| \####          | If item is text, write it left justified and truncate to fit size of  |
|                | field if necessary. If item is a number, write the integer part of    |
|                | the number right justified (eg. PRINT\_USING '###','Hello'            |
|                | will print Hel).                                                      |
+----------------+-----------------------------------------------------------------------+
| \*\*\*\*       | This is the same as #### except that any unused part of the field to  |
|                | the left of the characters is filled with '\*' characters.            |
|                | (eg. PRINT\_USING '\*\*\*\*',1.234 will print \*\*\*1).               |
+----------------+-----------------------------------------------------------------------+
| ###.##         | Print a fixed decimal point number right justified to a set number of |
|                | decimal places. (eg. PRINT\_USING '##.#',1.26 will print 1.3).        |
+----------------+-----------------------------------------------------------------------+
| \*\*\*.\*\*    | The same as ###.## except that any unused part of the field is        |
|                | filled with '\*' characters.                                          |
+----------------+-----------------------------------------------------------------------+
| #,###.##       | This is the same as ###.## except that a comma will be used to        |
|                | separate thousands.                                                   |
+----------------+-----------------------------------------------------------------------+
| \*,\*\*\*.\*\* | This is similar to #,###.## except that any unused part of the        |
|                | field will be filled with '\*'.                                       |
+----------------+-----------------------------------------------------------------------+
| -#.###!!!!     | This is used for an exponential field with the sign only being        |
|                | shown if the figure is negative.                                      |
|                | (eg. PRINT\_USING '-#.##!!!!',3120 will print 3.12E+03).              |
|                | An exponential field must always begin with a sign followed by        |
|                | one # mark and a decimal point, and always end with four !            |
|                | marks.                                                                |
+----------------+-----------------------------------------------------------------------+
| +#.###!!!!     | This is the same as -#.###!!!! except that the sign of the            |
|                | number is always shown.                                               |
+----------------+-----------------------------------------------------------------------+
| ###.>>         | This is introduced by SMSQ/E v2.73+ and is the same as ###.##         |
|                | except that it is for fixed point decimal figures, scaled             |
|                | accordingly. This allows you, for example, to convert a               |
|                | calculation from pennies into pounds.                                 |
|                | (eg. PRINT\_USING '###.>>',312.01 will print 3.12).                   |
|                | You can add more > characters after the decimal point if you          |
|                | need to convert to three decimal places.                              |
+----------------+-----------------------------------------------------------------------+
| \*\*\*.>>      | This is introduced by SMSQ/E v2.73+ and is the same as ###.>> except  |
|                | that any unused part of the field is filled with '\*' characters.     |
+----------------+-----------------------------------------------------------------------+

**Example**

A program which prints out a stocklist, which might be useful for a
small business::

    100 RESTORE
    110 MODE 4
    120 WINDOW 448,200,32,16:PAPER 0:INK 7:CLS
    130 CSIZE 2,0:AT 1,10:UNDER 1:PRINT 'STOCK LIST'
    140 CSIZE 1,0:AT 5,0
    150 PRINT 'NO ITEM IND. PRICE TOTAL'
    160 UNDER 0
    170 total=0:Lines=6
    180 REPeat loop
    190   IF EOF:EXIT loop
    200   READ equipment$,items,ind_price
    210   price=ind_price*items
    220   total=total+price:Lines=Lines+1
    230   PRINT_USING '#,###. ##############',items,equipment$
    240   PRINT_USING ' $##.## $##,###.##\',ind_price,price
    250   END REPeat loop
    260 OVER 1:AT Lines-1,0:UNDER 1
    270 PRINT FILL$(' ',45):UNDER 0
    280 IF INT(total)<>total:total=total*100
    290 PRINT TO 23;'Total Stock £';CDEC$(total,9,2)
    1000 DATA 'Minerva',110,40,'Minerva MKII',205,65.61
    1010 DATA 'Hermes',100,25,'68008 CPU',1230,8.7


**NOTE 1**

On Toolkit II versions before v2.08, this command could cause problems
if an empty string was passed to it.

**NOTE 2**

Some versions of the Toolkit II manual get the copyright symbol ('©')
mixed up with the 'at' symbol ('@'). The latter has no special
meaning.

**NOTE 3**

Because of variations in the way in which numbers are represented in
different countries, either a comma or full stop is recognised as a
decimal point by PRINT\_USING. If a field only contains one comma or
full stop, that is taken to be the decimal point, however, if more than
one comma and/or full stop appears in the field, the last one is taken
to be the decimal point, the others being assumed to be thousands
separators. If you want numbers to be printed with thousands separators
but no decimal point, use a comma or full stop as the last character of
the field.

**CROSS-REFERENCE**

See also :ref:`fdec-dlr`,
:ref:`idec-dlr` and :ref:`cdec-dlr`.

