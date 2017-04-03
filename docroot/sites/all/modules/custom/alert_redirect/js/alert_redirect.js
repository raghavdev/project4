/**
 * Created with JetBrains PhpStorm.
 * User: leonid
 * Date: 12/13/13
 * Time: 10:14 AM
 */
jQuery(document).ready(function(){
  var cookieName = 'Drupal.alertRedirect.alertBeacon';
  var redirectPersistent = parseInt(Drupal.settings.alertRedirect.redirectPersistent);
  var cookieExpiry = parseInt(Drupal.settings.alertRedirect.cookieExpiry);
  var redirectURL = Drupal.settings.alertRedirect.redirectURL;
  var cookieDomain = Drupal.settings.alertRedirect.cookieDomain;
  var doRedirect = false;

  var cookie = jQuery.cookie(cookieName);

  // If the cookie does not exist or is == 0 OR if we are doing a persistent redirect.
  if (!cookie || redirectPersistent) {
    // Initialize the cookie and set it to expire in 1 day (default).
    jQuery.cookie(cookieName, 0, { expires: cookieExpiry, path: '/', domain: cookieDomain});
    // Perform the redirect
    doRedirect = true;
  }
  else {
    // Our counterpart site had updated the cookie, so the user had been there - no redirect needed
  }

  if (doRedirect) {
    document.location.href = redirectURL;
  }
});
