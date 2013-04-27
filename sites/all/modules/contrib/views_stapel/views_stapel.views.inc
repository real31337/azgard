<?php
/**
 * @file
 * Provide views data and handlers.
 */

/**
 * Implements hook_views_plugins().
 */
function views_stapel_views_plugins() {
  $module_path = drupal_get_path('module', 'views_stapel');

  return array(
    'style' => array(
      'views_stapel_plugin_style' => array(
        'title' => t('Stapel'),
        'help' => t('Group thumbnails by a shared data-attribute into a pile'),
        'path' => $module_path . '/plugins',
        'handler' => 'ViewsStapelPluginStyle',
        'parent' => 'default',
        'theme' => 'views_stapel_plugin_style',
        'theme path' => $module_path . '/templates',
        'theme file' => 'theme.inc',
        'uses row plugin' => TRUE,
        'uses grouping' => FALSE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
    'row' => array(
      'views_stapel_plugin_rows' => array(
        'title' => t('Stapel'),
        'help' => t('Choose the fields to display in Stapel Style.'),
        'path' => $module_path . '/plugins',
        'handler' => 'ViewsStapelPluginRows',
        'theme' => 'views_stapel_plugin_rows',
        'theme path' => $module_path . '/templates',
        'theme file' => 'theme.inc',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );
}
