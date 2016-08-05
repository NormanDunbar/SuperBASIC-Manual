# SuperBASIC-Manual
RWAP Software's Online SuperBASIC manual - for conversion purposes

It is not expected that many people will fork this repository. It exists purely as a home
for the working files etc that I create and use when I'm in the process of converting from
badly created (by a computer!) HTML to ReStructuredText (all one word it seems!) so that I
can create a nicer looking documentation system in HTML, ePub, pdf etc.

## The Workflow

- Begin Outer Loop:
  - Exit Outer Loop when no more files remain.
  - `wget` the next html file from RWAP.
  - Begin Inner Loop:
    - Run `HTML Tidy` against it to produce a clean version.
    - Manually (yuk) correct each listed error and some warnings.
  - End Inner Loop.
  - Trim off the navigation stuff from each and every page. We only want the main div contents.
  - Carry out some additional `sed` processing on the cleaned file.
  - Convert the clean file to ReStructuredText using `Pandoc`.
  - Manually do some editing to tidy up the generated text.
  - Add the new file to the index.rst file, as this defines the structure.
  - `make html` to create a nice HTML version of the completed file(s).
- End Outer Loop.


## Folders
A number of folders exist:

- html - where the original html files are saved. Can be used to `diff` to check if changes are necessary.
- clean - where the cleaned files live.
- sphinx - where we do the building. Uses the `Makefile` found here.
- sphinx/source - where the ReStructuredText files are kept. These are used to build stuff.
- sphinx/build/html - where the html files, created by Sphinx, will be found.
- sphinx/build/doctrees - don't worry about this. Internal usage only. Don't edit any files here.
