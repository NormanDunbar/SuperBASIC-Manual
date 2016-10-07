# SuperBASIC-Manual
RWAP Software's Online SuperBASIC manual - for conversion purposes

It is not expected that many people will fork this repository. It exists purely as a home
for the working files etc that I create and use when I'm in the process of converting from
badly created (by a computer!) HTML to ReStructuredText (all one word it seems!) so that I
can create a nicer looking documentation system in HTML, ePub, pdf etc.

## The Workflow
The following is a rough version of the nightmare that I went through, repeatedly, to get to where we are today!

````
Begin Outer Loop
   Exit Outer Loop when no more (original HTML) files remain.
   `git checkout working` to ensure we are on the working branch.
   `wget` the next HTML file from RWAP.
   
   Begin Inner Loop
     Run `Process.sh` against the HTML.
     If file is clean, or only has warnings, exit Inner Loop.
     Manually (yuk) correct *every* error and *some* warnings.
   End Inner Loop
   
   Trim off the navigation stuff from each HTML page. We only want the main div contents.
   Carry out some additional `sed` processing on the cleaned file.
   Convert the clean file to ReStructuredText using `Pandoc`.
   `git add` the various files - html, clean, errors, source - to the (working) repository.
   Add the new source file to the index.rst file, which defines the structure.
   `make clean` or the new file won't appear in the TOC.  
   Add a Keywords xxx Section heading to the source file.
   
   Repeat Edit Loop
     `make html` to test the build with the current file.
     View the HTML generated in a browser.
     If all ok and finished with this file, exit Edit Loop.
     Manually do some (more) editing to tidy up the generated source text.
   End Repeat Edit Loop  
   
   `make html` to create a nice HTML version of the completed file(s).
   `git add --all` to add all the finished files to the (working) repository.
   `git push` to push them to GitHub. This forces a build of the 'working' docs on ReadTheDocs.
   `git checkout master` to checkout the main clean master repository.
   `git merge working` to merge recent changes.
   `git push` to update GitHub and force a 'latest' build on ReadTheDocs.
End Outer Loop.
````

````
Begin Tidy Loop
   `make linkcheck`
   Attempt to locate invalid links, and correct them.
   Tidy up any tables etc that look like they need it.
End Tidy Loop
````

## Folders
A number of folders exist:

- html - where the original html files are saved. Can be used to `diff` to check if changes are necessary. These are the files as downloaded from RWAPs web site.
- clean - where the cleaned files live. Clean files are assumed to have survived the `Process.sh` execution, and have had quite a lot of problems automatically resolved. There will still be much to do though. These files are used to create the ReStructuredText source files.
- sphinx - where we do the building. Uses the `Makefile` found here.
- sphinx/source - where the ReStructuredText files are kept. These are used to build stuff.
- sphinx/build/html - where the html files, created by Sphinx's `make html` command, will be found.
- sphinx/build/latex - where the latex and/or PDF files, created by Sphinx's `make latex` or `make latexpdf`, will be found.
- sphinx/build/linkcheck - where the html files, created by Sphinx's `make linkcheck`, will be found. These are used to assist in checking that links, internal and external, work ok.
- sphinx/build/doctrees - don't worry about this. Internal usage only. Don't edit any files here.
