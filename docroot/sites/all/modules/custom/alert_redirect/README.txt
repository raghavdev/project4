Alert Redirect
==============

Redirects users to the 'alert' site in case of an emergency event.

## Installation instructions

Install as any other contrib module. See https://drupal.org/node/895232 for details.
Some features of this module (non-persistent one-time redirect) require a counterpart installation on the target site.

## Configuration

1. Once the module is enabled, proceed to the configuration page - admin/config/system/alert_redirect
2. Depending on the site role ("main" site or "alert") select the appropriate "Site Mode" and save settings.
3. Configure the "main" site - "Redirect settings":
 - "Cookie Domain" - Cookie domain to be used.
   E.g. ".example.com" (notice the leading dot) will make cookie visible for all sub domains (*.example.com).
 - "Enable redirect" - Check to have redirect enabled, uncheck to disable.
 - "Redirect URL" - This is the URL for the "alert" site, or any other redirect target.
 - "Persistent redirect" - Check to always redirect users. Otherwise redirect will be performed once.
   When set to the "persistent redirect" mode, the module ignores the cookie timestamp set by the counterpart
   on the "alert" site. If a "one-time redirect" behaviour is required, then uncheck this and make sure a counterpart is
   installed on the "alert" site and set to the "Beacon" site mode. The counterpart is responsible for updating the
   cookie timestamp. This way the "main" site knows whether a redirect has been performed for a given user.
 - "Redirect scope" - this works similar to the core block visibility scope.
   Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard.
   Example paths are blog for the blog page and blog/* for every personal blog. <front> is the front page.
 - Advanced: Beacon Cookie Expiry - The number of days the beacon cookie will be preserved for (default: 1).
   This setting defines the beacon cookie lifetime. The cookie will expire after X days of a user not visiting
   the "alert" site (the "alert" site counterpart updates the cookie and thus the expiry timestamp).
   If the cookie expires and the main site is configured to perform a non-persistent (one-time) redirect, then a user
   will be redirected to the alert site again.
4. Configuring the "alert" site
 - "Cookie Domain" - see #3 for details.
5. Configure module permissions at admin/people/permissions
 - "Administer Alert Redirect" - Perform administration tasks for Alert Redirect module.

## Other considerations

Please note that most of the module settings and functionality are exported and handled in Javascript.
This allows the module to function properly in a reverse-proxy/page-cached environment (behind Varnish, Akamai, etc.)
There however may be a delay with the settings propagation based on the caching strategies used.
