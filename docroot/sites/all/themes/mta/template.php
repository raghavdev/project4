<?php
function mta_js_alter(&$js) {
    unset($js['misc/tableheader.js']);
}


function mta_preprocess_page(&$vars) {
	
  if (isset($vars['node']->type)) {
	   if($vars['node']->type == 'news_article'){
	      $vars['title'] ='default';
	      
	    if (!empty($vars['node']->field_news_page_headline['und'][0]['value'])) {
	      $vars['title'] = $vars['node']->field_news_page_headline['und'][0]['value'];
	    }elseif (!empty($vars['node']->field_headline['und'][0]['value'])) {
	      $vars['title'] = $vars['node']->field_headline['und'][0]['value'];
	    }elseif (!empty($vars['node']->field_emergency_headline['und'][0]['value'])) {
	      $vars['title'] = $vars['node']->field_emergency_headline['und'][0]['value'];
	    }
   }
  	
  		if ($vars['node']->type == "page_with_ad" || $vars['node']->type == "news_article")  {
    	 $vars['theme_hook_suggestions'][] = 'page__ad';
  		} 
  		
  		if ($vars['node']->type == "weekender" || $vars['node']->type == "weekender") {
  			$vars['theme_hook_suggestions'][] = 'page__weekender';
  		}
                if ($vars['node']->type == "weekendertwo" || $vars['node']->type == "weekendertwo") {
                        $vars['theme_hook_suggestions'][] = 'page__weekendertwo';
                }
  		
  		if ($vars['node']->type == "page_with_ad" || $vars['node']->type == "news_story")  {
  			$vars['theme_hook_suggestions'][] = 'page__ad';
  		}
  		
  		if ($vars['node']->type == "page_with_ad" || $vars['node']->type == "gallery_page")  {
  			$vars['theme_hook_suggestions'][] = 'page__ad';
  		}
  		
  		
  		if($vars['node']->type == 'press_release'){
  			$vars['title'] = '<a href="/press-releases">MTA Press Releases</a>';
  		}
  		
  		  		 		  		  	
  		else {
  	if ($vars['node']->type == "home_page") {
    	 $vars['theme_hook_suggestions'][] = 'page__home';
  		} 
  	}  
  }
  
 
  
  
  
  
 // adds the colorbox image gallery
 
  
  $vars['node']= '';
		if (isset($vars['node']->field_gallery_image)) {
  	foreach ($vars['node']->field_gallery_image[$vars['node']->language] as $key => $val) {
  		$full_img_url = file_create_url($val['uri']);
  		if ($key == 0) {
  			$thumbnail_url = image_style_url('thumbnail', $val['uri']);
  			$vars['gallery'] .= '<a class="colorbox-load" rel="gallery" href="'. $full_img_url .'"><img src="'. $thumbnail_url .'" alt="Gallery image" /></a>';
  		}
  		else {
  			$vars['node'] .= '<a class="colorbox-load" rel="gallery" href="'. $full_img_url .'"></a>';
  		}
  	}
  }
  
}
