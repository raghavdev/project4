/**
 * Created with JetBrains PhpStorm.
 * User: leonid
 * Date: 12/13/13
 * Time: 2:13 PM
 */
jQuery(document).ready(function(){
  var cookieName = 'Drupal.alertRedirect.alertBeacon';
  var cookieExpiry = parseInt(Drupal.settings.alertRedirect.cookieExpiry);
  var cookieDomain = Drupal.settings.alertRedirect.cookieDomain;

  var cookie = jQuery.cookie(cookieName);

  // If cookie exists and == 0, set it = time().
  if (cookie == 0) {
    // Update the cookie with a timestamp.
    jQuery.cookie(cookieName, new Date().getTime(), { expires: cookieExpiry, path: '/' , domain: cookieDomain});
  }
});
