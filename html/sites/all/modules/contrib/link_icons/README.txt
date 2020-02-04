CONTENTS OF THIS FILE
---------------------
 * Introduction
 * Requirements
 * Installation
 * Configuration
 * Troubleshooting
 * FAQ
 * Maintainers


INTRODUCTION
------------

The Link Icons module is a field formatter for the Link field to display an
icon for the service being linked to - ex. Facebook, Twitter or LinkedIn, with
various display options available as settings of the formatter. The icons
themselves are provided from the Font Awesome project.

Services/icons currently supported are:
- 500px.com
- amazon.com
- amazon.co.uk
- angel.co
- apple.com
- bandcamp.com
- behance.net
- bitbucket.org
- chrome.google.com
- codepen.io
- del.icio.us
- deviantart.com
- digg.com
- dribbble.com
- dropbox.com
- drupal.org
- eercast.com
- etsy.com
- facebook.com
- flickr.com
- fontawesome.com
- fontawesome.io
- foursquare.com
- freecodecamp.com
- getgrav.com
- github.com
- google.com
- imdb.com
- instagram.com
- joomla.org
- jsfiddle.net
- last.fm
- linkedin.com
- linode.com
- medium.com
- meetup.com
- paypal.com
- paypal.me
- pinterest.com
- play.google.com
- plus.google.com
- producthunt.com
- quora.com
- ravelry.com
- reddit.com
- slideshare.net
- snapchat.com
- soundcloud.com
- spotify.com
- spotlight.com
- stackexchange.com
- stackoverflow.com
- steamcommunity.com
- steampowered.com
- stumbleupon.com
- telegram.org
- thetalentmanager.com
- tripadvisor.com
- tripadvisor.co.uk
- tumblr.com
- twitch.tv
- twitter.com
- viadeo.com
- vimeo.com
- vine.co
- wikipedia.org
- wordpress.com
- wordpress.org
- wpexplorer.com
- xing.com
- yahoo.com
- yelp.com
- yelp.co.uk
- youtube.com

The generic globe icon is used if a link URL does not have one of the hostnames
above.

 * For a full description of the module, visit the project page:
  https://drupal.org/project/link_icons

 * To submit bug reports and feature suggestions, or to track changes:
  https://drupal.org/project/issues/link_icons


REQUIREMENTS
------------

The link field module, obviously, and the Font Awesome module that adds the FA
project to Drupal allowing the icons to be displayed:
 * Link (https://drupal.org/project/link)
 * Font Awesome (https://drupal.org/project/fontawesome) (at least version
   7.x-2.6)

Don't forget to add/upgrade to the latest version of Font Awesome in your
sites/all/libraries/fontawesome directory.


INSTALLATION
------------
Install as you would normally install a contributed drupal module. See:
https://drupal.org/documentation/install/modules-themes/modules-7 for further
information.


CONFIGURATION
-------------
 * Just head to a content type display management tab
   (ex. http://yoursite.com/admin/structure/types/manage/yourtype/display) where
   you have a link field/fields. In the format column for the link field that
   you want to use this formatter, select the 'Service icon (with options)'
   format, and save the form to put it into use.
 * Click the settings cog/gear button to view and edit the (hopefully)
   self-explanatory options for how the links should be displayed. These exploit
   most of the Font Awesome features, as listed at
   http://fortawesome.github.io/Font-Awesome/examples/
 * To customise the icons further, just theme your pages as usual. With the
   icons rendered as text characters using Font Awesome, you can style them with
   CSS as you wish.


TROUBLESHOOTING
---------------
 * Try clearing all your caches using the performance configuration page should
   you encounter any issues.
 * Edit the settings for the problematic field, using the cog/gear button, to
   flush out any invalid settings from previous versions of this module.
 * Don't forget to add/upgrade to the latest version of Font Awesome in your
   sites/all/libraries/fontawesome directory.


FAQ
---
None, yet.


MAINTAINERS
-----------
 * Dave Nattriss (natts) - https://drupal.org/user/378513

Thanks to Bobík (bobik) who published a sandbox project which was the starting
point for this module:
 * https://drupal.org/sandbox/bobik/1914102

The icons are from the Font Awesome project, by Greg Loucas and Dave Gandy:
 * https://twitter.com/gregoryLpaul
 * https://twitter.com/fontawesome
 * http://fortawesome.github.io/Font-Awesome/

The font has been made available to Drupal in the fontawesome module by Rob
Loach (RobLoach) and Inder Singh (inders)
