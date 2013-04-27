<?php
/**
 * @file
 * Definition of views_stapel_plugin_style.
 */

/**
 * Class to define a style plugin handler.
 */
class ViewsStapelPluginStyle extends views_plugin_style {
  /**
   * Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['randomAngle'] = array('default' => true);
    $options['delay'] = array('default' => 50);
    $options['gutter'] = array('default' => 70);
    $options['pileAngles'] = array('default' => 5);
    return $options;
  }

  /**
   * Form.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['randomAngle'] = array(
      '#type' => 'checkbox',
      '#title' => t('randomAngle'),
      '#default_value' => $this->options['randomAngle'],
    );

    $form['delay'] = array(
      '#type' => 'textfield',
      '#title' => t('delay'),
      '#default_value' => $this->options['delay'],
    );

    $form['gutter'] = array(
      '#type' => 'textfield',
      '#title' => t('gutter'),
      '#default_value' => $this->options['gutter'],
    );

    $form['pileAngles'] = array(
      '#type' => 'textfield',
      '#title' => t('pileAngles'),
      '#default_value' => $this->options['pileAngles'],
    );
  }
}
