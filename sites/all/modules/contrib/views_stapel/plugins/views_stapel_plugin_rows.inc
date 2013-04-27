<?php
/**
 * @file
 * Definition of views_stapel_plugin_rows.
 */

/**
 * Class to define a row plugin handler.
 */
class ViewsStapelPluginRows extends views_plugin_row {
  /**
   * Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['stapel_title'] = array('default' => '');
    $options['stapel_image'] = array('default' => '');
    $options['stapel_group'] = array('default' => '');
    return $options;
  }

  /**
   * Form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    // Pre-build all of our option lists for the dials and switches that follow.
    $fields = array('' => t('<None>'));
    foreach ($this->display->handler->get_handlers('field') as $field => $handler) {
      if ($label = $handler->label()) {
        $fields[$field] = $label;
      }
      else {
        $fields[$field] = $handler->ui_name();
      }
    }

    $form['stapel_title'] = array(
      '#type' => 'select',
      '#title' => t('Title'),
      '#options' => $fields,
      '#default_value' => $this->options['stapel_title'],
      '#description' => t('Select the field that will be used as the title field.'),
    );

    $form['stapel_image'] = array(
      '#type' => 'select',
      '#title' => t('Image'),
      '#options' => $fields,
      '#default_value' => $this->options['stapel_image'],
      '#description' => t('Select the field that will be used as the image field.'),
    );

    $form['stapel_group'] = array(
      '#type' => 'select',
      '#title' => t('Group'),
      '#options' => $fields,
      '#default_value' => $this->options['stapel_group'],
      '#description' => t('Select the field that will be used for grouping.'),
    );
  }
}
