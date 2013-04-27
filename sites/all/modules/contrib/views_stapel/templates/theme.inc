<?php

/**
 * Implementation of template preprocess for the view.
 */
function template_preprocess_views_stapel_plugin_style(&$vars) {
  $style = $vars['view']->style_options;

  drupal_add_js(libraries_get_path('stapel') . '/js/jquery.stapel.js');
  drupal_add_css(libraries_get_path('stapel') . '/css/stapel.css');

  drupal_add_js(drupal_get_path('module', 'views_stapel') . '/js/views_stapel.js');
  drupal_add_css(drupal_get_path('module', 'views_stapel') . '/css/views_stapel.css');

  // Convert values to integer;
  foreach ($style as &$value) {
    $value = (int)$value;
  }

  drupal_add_js(array('ViewsStapel' => $style), 'setting');

  $vars['classes_array'][] = 'views-stapel';
}

/**
 * Implementation of template preprocess for the view fields.
 */
function template_preprocess_views_stapel_plugin_rows(&$vars) {
  $view = &$vars['view'];

  foreach ($vars['options'] as $id => $field) {
    $vars[$id] = $view->field[$field]->theme($vars['row']);
  }

  // Delete html shit.
  $vars['stapel_group'] = strip_tags($vars['stapel_group']);
  $vars['stapel_title'] = strip_tags($vars['stapel_title']);
}
