<?php

/**
 * Bootstrap theme wrapper function for the primary menu links
 */
function azgard_menu_tree__primary(&$variables) {
  return '<ul id="navigation" class="nav nav-pills">' . $variables['tree'] . '</ul>';
}


function azgard_preprocess_page(&$vars, $hooks) {
  // Add 'active' class to active menu items.
  foreach ($vars['primary_nav'] as &$item) {
    if (isset($item['#href'])) {
      $link_is_same = ($item['#href'] == $_GET['q']);
      $is_front_page = ($item['#href'] == "<front>" && drupal_is_front_page());

      if ($link_is_same || $is_front_page) {
        $item['#attributes']['class'][] = 'active';
      }
    }
  }
}