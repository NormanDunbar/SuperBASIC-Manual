Structure of this Book
======================

This book consists basically of three parts.

The first part forms those obligatory sections, from *Introduction* to 
*Writing Programs*.

The second part is the main part which is explained below.

Finally the *Appendices* make up the third part. These appendices have
been added to prevent repeated explanations in the main section, they
are not a full-blown concepts section.

The main part of this book is the *Keywords* section. This section is
sorted alphabetically and for each keyword there will appear (at least)
a description of the keyword's syntax, where it can be found and a short
description. In most cases, you will also find examples and
cross-references to other keywords, and from time to time some notes on
using the commands. You may even come across warnings.

The alphabetical list is arranged in the following order (it is not case
sensitive):

ABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789 % $ \_

This means for example that the keywords such as S\_LOAD appear at the
end of all other keywords beginning with S.

Syntax
------

Compressing all possible variations of a keyword's syntax in usually one
abstract line can be difficult for those readers who are not familiar
with syntax schemes. That's why we want to explain our notation in
detail.

Throughout the book, almost everything that can be typed into the
computer or returned by it, is written in a different typeface (italics)
so that you can always easily distinguish those parts of the text which
can be entered into the computer. We have tried to be as consistent as
possible in this respect.

The syntax scheme itself contains symbols which are not to be typed in
and thus appear in the normal typeface:-

Square Brackets ([ ])
^^^^^^^^^^^^^^^^^^^^^

These indicate that the enclosed parts are optional. Optional parameters
(ie. parameters which can be omitted without producing an error) are
always in square brackets.

Example:

    DLIST [#ch]

Both DLIST and DLIST #2 are valid.

Square Brackets With Superscript Asterisks (:sup:`\*`\ [ ]\ :sup:`\*`)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

These suggest that the number of optional parameters is not limited, ie.
there can be any number of such parameters. Another symbol for the same
meaning are nested square brackets with three dots inside.

Example:

POINT x,y [,x\ :sup:`2`\ ,y\ :sup:`2` [,x\ :sup:`3`\ ,y\ :sup:`3`\ , ...]]

or

POINT x,y :sup:`\*`\ [,x\ :sup:`i`\ ,y\ :sup:`i`]\ :sup:`\*`

Any non-zero number of co-ordinate pairs are allowed. Note that the
indices are also symbols, used to make reading easier. Of course you
cannot type POINT x\ :sup:`1`\ ,y\ :sup:`1` but just POINT x1,y1 without
any subscript characters will work.

Curly Brackets ({ })
^^^^^^^^^^^^^^^^^^^^

These mean that the parameter can be chosen from a limited variety of
types which are given in the brackets. The options are mutually
exclusive and separated by a vertical line (\|).

Example:

KEYWORD {test$ \| test%}

Either KEYWORD test$ or KEYWORD test% is valid.

The vertical line (\|) can also appear in square brackets. In this case,
the parameter is optional and has to be selected from one of the types
listed in the brackets.

Example:

SIZE test[%\|$]

SIZE test%

SIZE test$

SIZE test

are all valid.

We generally assume that you have some basic idea of SuperBASIC syntax
because this book is not a SuperBASIC tutorial but a reference book for
toolkit keywords.

Channels (#ch)
^^^^^^^^^^^^^^

Many Syntax definitions refer to a channel parameter, which is normally
shown as #ch or #channel.

These channels can have two main types, a channel connected to a Device
(or File) and a channel connected to a Window (a scr\_ or con\_ device).
The type of a channel is specified when that channel is OPENed - see the
description of OPEN for further details.

Normally the description for each keyword will specify if the channel
used by that keyword has to be of a specific type. If no mention is
made, then presume that the keyword can be used on any type of channel.

Location
^^^^^^^^
This is just the name of the toolkit(s) where you will find the keyword.

Some locations are not separately available toolkits, eg. QL ROM, Super
Gold Card, Gold Card, Trump Card, ST/QL and more.

Where the Location is given as QL ROM, this means that the keyword is
available on all versions of the QL, QL compatible computers and
Emulators (unless specified).

Where the Location is given as Gold Cards, this covers the whole of the
Gold Card range of expansion boards, namely Super Gold Card and Gold
Card. However, note that commands given by these boards will not be
available under SMSQ/E unless specifically stated.

Some keywords are available as part of the Level-2 or Level-3 device
drivers.

Level-2 device drivers are built into Gold Card, Super Gold Card and the
QUBIDE disk interface, as well as forming part of SMSQ on the QXL and
the ST emulators. Level-2 device drivers are also available separately
for the Trump Card.

Level-3 device drivers are provided with SMSQ/E and incorporate all of
the features of Level-2 device drivers and more. Therefore if the
location is said to be Level-2 Device Drivers, these commands will also
work on Level-3 Drivers.

SMSQ/E is a new operating system which is compatible with QDOS and
incorporates all of the original QL ROM keywords, Toolkit II, the
Pointer Interface, Window Manager, Hotkey System II and Level-3 device
drivers. Therefore if a keyword is listed as appearing in any of these,
then it will be available to the SuperBASIC programmer under SMSQ/E.

SMSQ is the operating system built into QXL which can be replaced by
SMSQ/E. Both operating systems are very similar in how they treat
SuperBASIC keywords and we have therefore used to SMS to indicate that a
comment may apply to both SMSQ/E and SMSQ. Their individual names have
been used if there is a difference.

ST/QL refers to the full range of QL Hardware Emulators for the Atari ST
(Extended Mode-4 Emulator, QVME and the original ST-QL Emulator). Any
comments which refer specifically to one of the boards are covered
separately.

Refer to the Emulators Appendix for more details on the various
emulators available.

Description
-----------

The description of the function of a keyword is usually abstract and
relatively short. You may have to read it carefully to understand it
fully. Technical details are limited to the needs of a SuperBASIC
programmer, but we document the current standards in QL programming and
environments.

Examples
--------

The examples demonstrate the different syntax variations of a keyword
and explain concrete usages. We have tried to write some short example
programs which make sense outside pure computer applications, meaning
that a brief explanation is seldom necessary.

All listings have been directly imported from the SuperBASIC interpreter
into the word-processor via an intermediate file or pipe. The
exceptional multitasking capabilities of the QL with Tony Tebby's
Pointer Environment allowed us to write text, try out toolkits and
develop examples, all at the same time. Due to the direct import of the
latter, mistakes in the examples have been minimised. However, we are
all only human.

It is not our intention to praise a particular style of programming.
Book space, layout, typefaces and didactic considerations posed various
limits. For this reason, examples or parts of examples which are
designed as modules (procedures or functions), will usually not check
the supplied arguments for wrong parameters.

All example listings are freely distributable subject to restrictions.
You are allowed to develop applications from examples or make use of
examples in other programs under the condition that this book and its
authors are given credit accordingly.

Notes
-----

These (sometimes extensive) comments vary from strange side-effects of
keywords to off-topic remarks. They have been added for completeness.
Very often the original documentation did not recognise all possible
implementations for practical reasons: a certain configuration did not
exist at the time of writing, the author did not expect users to exploit
parameter ranges to the full, etc.

It is not necessary to know the notes but when struggling against odd
phenomena, reading the notes could clarify seeming mysteries.

[Implementation] Notes
----------------------

When bringing out new implementations of the QL ROM, the authors are
limited by the amount of memory into which they have to squeeze all
additions, modifications and corrections. They therefore tend to extend
the syntax instead of adding new keywords. That is why the
Implementation Notes are usually a further description of syntax and
usages, possibly including examples. POKE is a good example.

The more common Implementation Notes are for Minerva, THOR and SMS.
Please note that throughout references to SMS refer to both the SMSQ and
SMSQ/E operating systems (see above).

Implementation Notes may also appear for each of the different Emulators
and Expansion Boards which can be used with the QL.

Warning
-------

An absolutely obligatory section! Some commands and functions crash the
machine under certain circumstances: the warnings are intended to help
you avoid frustration and disappointment. Please do not blame the
authors of the toolkits for the bugs, writing a fool-proof program is
very time consuming and nobody is perfect (neither the toolkits' authors
nor the writers of this book). If we forget to mention a dangerous
situation, this is because we were not aware of it.

Cross-Reference
---------------

Keywords can be connected by a couple of links. They can do almost the
same or perform similar functions, in these cases we did not make use of
the word-processor's block copying facilities to artificially enlarge
the book but simply referred to another text passage. If the
relationship between keywords is emphasised by their name,
cross-references may be extremely short or missing; due to the
alphabetical order of the keywords, the reference is not too far away in
most cases anyway.

Cross-references may also give notice of other keywords where the
relation is rather indirect, this has been done to encourage liberally
skipping through the pages.


