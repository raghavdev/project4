/**
* @file
* mta3_global_header module
* README.TXT
* Module developed for MTA Drupal site v3 by Randall Goya "decibel.places" November 21, 2013
*/


This module scrapes the HTML code from the header of the "source" site
and writes it to a file "raw_header.php" 
along with the css styles for the header contained in stylesheets
and some additional css rules
*

raw_header.php also generates the header necessary to allow Cross Origin Resource Sharing
using CORS http://www.nczonline.net/blog/2010/05/25/cross-domain-ajax-with-cross-origin-resource-sharing/ 
*
The target site adds a script tag linking back to the script in this module 
example <script src="http://new.mta.info/sites/all/modules/custom/mta3_global_header/mta3_global_header.js"></script>
the script replaces the static HTML inside the DOM container for the header on the target site
with the HTML scraped from the source site in raw_header.php.
It also changes relative paths in the source header for the MTA logo and the Search Form action to absolute URLs.
*
If the AJAX request to load the raw_header.php file fails, the target site degrades gracefully to display the header that is already there.
*
We use the simplehtmldom module to provide the simple_html_dom PHP library instead of loading it directly from a file in the module. 
see http://simplehtmldom.sourceforge.net/manual.htm
Some Drupal modules also require the simplehtmldom module so we don't want to load it twice. 
We also need to set our module weight "heavier" than simplehtmldom in the .install file
*
UPDATE HEADER SOURCE FILE
There is a menu item at admin/structure/update_global_header to update the header source file manually
%TODO% schedule updating file
*

 
PERMISSIONS
MTA Global Header
administer MTA global header
Update source file for mta global header.
*
CAVEATS:
1. We assume that the target site has it's header markup in a div with the id "topbar" or else the header has been wrapped in a div with the id "mta-global-header"
2. We assume that the target site menu is using csshorizontalmenu.js for its menu, for which we proivide the id of the menu from the source site
3. For testing the module writes the header source file on every page load. In production, we would want to schedule it and provide a menu callback to the function to create the file on demand
4. WARNING INFINITE LOOP
If the line that runs the mta3_global_header_write() function on every page load is uncommented
and the $sourceDomain is the same site where the module is installed, it will create an infinite loop condition
Use the menu link to update the raw_header.php file, or point the $sourceDomain somewhere else
5 MISSING BLOCKS ON RESPONSIVE SITES
If block or other content is missing, check the responsive theme settings, media queries, and breakpoints (and permissions)
simplehtmldom uses file_get_contents() and does not give any info to the responsive detection methods
*
