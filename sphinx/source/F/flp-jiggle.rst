..  _flp-jiggle:

FLP\_JIGGLE
===========

+----------+-------------------------------------------------------------------+
| Syntax   |  FLP\_JIGGLE [driveno,] flag                                      |
+----------+-------------------------------------------------------------------+
| Location |  Gold Cards                                                       |
+----------+-------------------------------------------------------------------+

There were originally various problems when using Mitsubishi ED disk
drives with the Gold Card and so a fix was incorporated in both the Gold
Card and Super Gold Card operating systems which forces the drive
read/write head to make a number of rapid steps.

This can however cause
problems with other ED disk drives (normally seen in the form of 'Not
Found' or 'Bad or Changed Medium' errors.

It was therefore felt
necessary to be able to enable or disable this feature at the users
request (the default is to have the feature disabled).

To enable this
feature set flag to 1, 0 will disable it.

If driveno is not specified,
then the setting will be applied to all disk drives connected to the
(Super) Gold Card and automatically stored so that it is available on
power on.

If driveno is specified, then the setting will only
apply to that specified disk drive and will be forgotten when the power
is switched off.

**CROSS-REFERENCE**

See :ref:`flp-step` and
:ref:`flp-start` which overcome various other
problems with some disk drives.

