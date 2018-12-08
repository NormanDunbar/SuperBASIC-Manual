# SuperBASIC-Manual
RWAP Software's Online SuperBASIC manual

The old manual that Rich Mellor created has been converted to a new format, and now lives at:

[https://superbasic-manual.readthedocs.io/en/latest/](https://superbasic-manual.readthedocs.io/en/latest/ "SuperBASIC Online Manual").


This repository is a working one whereby any changes to the manual are done, tested and committed. Once committed, a new build of the docs will take place over at ReadTheDocs, and the changes will be made publicly available.


## Folders
A number of folders exist:

- html - where the original html files from RWAP are saved in a zip file. These are kept for posterity, but are now unlikely to be of much use, except where some error is discovered in one of the converted files.
- clean - where the cleaned up HTML files live. These files were used to create the original ReStructuredText source files. Again, these are of little use, and have been compressed.
- errors - a list of the errors detected in the various conversions from HTML to ReStructuredText. Highly unlikely to be useful now, so compressed.
- tools - some tools that were used to do the majority of the initial conversion. Most have been compressed out of the way as they are no longer required.

- sphinx - where we do the building. Uses the `Makefile` found here. To generate output, `make html` or `make latexpdf` are best. For a bonus, `make epub` of `make text`.
- sphinx/source - where the ReStructuredText files are kept. These are used to build stuff.
- sphinx/build/html - where the html files, created by Sphinx's `make html` command, will be found.
- sphinx/build/latex - where the latex and/or PDF files, created by Sphinx's `make latex` or `make latexpdf`, will be found.
- sphinx/build/linkcheck - where the html files, created by Sphinx's `make linkcheck`, will be found. These are used to assist in checking that links, internal and external, work ok.
- sphinx/build/doctrees - don't worry about this. Internal usage only. Don't edit any files here. (They are binary files anyway, so you can't!)


## Structure
The source files live in a separate ReStructuredText for each individual keyword, where the folder they live in is based on the first letter, upper cased, of the keyword. So `DJTK_VER$` lives in the `D` folder beneath `sphinx/source`. There are folders for 'A' to 'Z' and one for those few keywords with a leading underscore, they like in a folder named '_'. Weird but true.

The actual file names are not always the same as the keyword:

- Everything is lower cased; `DJTK_VER$` => `djtk_ver$`.
- Underscores are converted to hyphens; `djtk_ver$` => `djtk-ver$`.
- '%' is converted to '-pct';
- '$' is converted to '-dlr'; `djtk-ver$` => `djtk-ver-dlr`.
- Any spaces (such as `SELECT ON`) get converted to double hyphens.
- Finally, an `.rst` extension is added. => `djtk-ver-dlr.rst`.

The file name is exactly the same as the ReStructuredText label (for cross reference links) for the keyword in question. Doing it this way should prevent problems on systems where the percent and/or dollar etc are not permitted in file names.


## Updating the Manual
- Clone the source from git;
- Checkout the working branch;
- Do your changes;
- Clean - `cd sphinx` followed by `make clean`;
- Build HTML - `make html` - check output for errors about invalid links etc, fix and rebuild (no need to clean);
- Check generated HTML. Fix and rebuild as necessary;
- Build PDF - `make latexpdf`. There will be lots of output. Difficult to find errors;
- Check generated PDF. Fix and rebuild (HTML as well) as necessary;
- Commit to working branch;
- `git push` back to reporitory;
- Checkout master branch;
- `git merge working`;
- `git push` back to repository;
- If you are *not* Norman (that's me!) then raise a pull request. I'll then merge that with the main repository, mine, and that will trigger a rebuild of the docs online for everyone to see.

**We do not break the master branch!**

That's about it.
