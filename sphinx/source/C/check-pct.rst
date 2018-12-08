..  _check-pct:

CHECK%
======

+----------+-------------------------------------------------------------------+
| Syntax   |  CHECK% (integer$)                                                |
+----------+-------------------------------------------------------------------+
| Location |  CONTROL (DIY Toolkit Vol E)                                      |
+----------+-------------------------------------------------------------------+

Coercion is the process of converting a string which holds a number into
the actual number. It is a powerful in-built feature of SuperBASIC. This
allows you to create input routines such as:

::

    100 dage% = RND(10 TO 110)
    110 INPUT "Your age [" & dage% & "]?" ! age$;
    120 IF age$ = "" THEN
    130   age% = dage%: PRINT age%
    140 ELSE
    150   age% = age$: PRINT
    160 END IF

Although SuperBASIC coercion is very powerful, it does have its limits
when non-numeric strings are entered. If age$ was "44", age%=age$ will
assign 44 to age%. Even if the string was not really a number, eg.
"44x5", SuperBASIC will simply ignore everything behind legal characters
(ie. age%=age$ would assign 44 to age% still). However, if age$
contained something like "no thanks" it cannot be coerced and the
program will fail with an 'error in expression' (-17).

The function CHECK% exploits the fact that SuperBASIC is obviously able
to see the difference between a valid number or what comes close to that
and nonsense. CHECK% carries out an explicit coercion for integer
numbers: it will try to make a number from the supplied parameter in the
same way as SuperBASIC would. However, CHECK% will not stop with an
error for unusable strings, instead it returns -32768.

Although "-32768" is converted correctly to -32768, this value must be
reserved because the program cannot know whether the input was illegal
or -32768.

**Example**

Let's rewrite the above example for coercion with CHECK%. We have to
replace the implicit coercion age%=age$ with age%=CHECK%(age$) and put
INPUT into a loop:

::

    100 dage% = RND(10 TO 110)
    110 REPeat asking
    120   INPUT "Your age [" & dage% & "]?" ! age$;
    130   IF age$ = "" THEN
    140     age% = dage%: PRINT age%
    150   ELSE
    160     age% = CHECK%(age$): PRINT
    170     IF age% > -32768 THEN EXIT asking
    180   END IF
    190 END REPeat asking

**CROSS-REFERENCE**

:ref:`checkf` does the same as
:ref:`check-pct` but converts strings containing
floating point numbers.

:ref:`when--error` can trap the coercion
failure.

See the Coercion Appendix also.

