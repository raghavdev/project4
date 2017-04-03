/**
 * Check value of cache_block to see if
 * we need to hide or show the additional settings.
 */
function BlockCacheAlterCheck() {
  var blockcache = jQuery('#edit-cache-block');
  var selected = blockcache[0].options[blockcache[0].selectedIndex].value;
  if (selected == '-1') {
    toggleBlockCacheAlter('hide');
  }
  else {
    toggleBlockCacheAlter('show');
  }
}

/**
 * Show or hide additional blockcache settings.
 */
function toggleBlockCacheAlter(type) {
  if (type == 'hide') {
    jQuery('#blockcache_alter_wrapper').hide('slow');
  }
  else {
    jQuery('#blockcache_alter_wrapper').show('slow');
  }
}
