<?php

/**
 * @file
 * Handler for node path field.
 */

/**
 * Field handler to present the path to the node.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_node_path_query extends views_handler_field_node_path {

  function option_definition() {
    $options = parent::option_definition();
    $options['query'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['query'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add all query parameters'),
      '#default_value' => $this->options['query'],
      '#description' => t('Enable this option to output a link with all query parameters.'),
      '#fieldset' => 'alter',
    );
  }

  function render($values) {
    $nid = $this->get_value($values, 'nid');

    $query = array();
    if ($this->options['query']) {
      $query = $_GET;
      unset($query['q']);
    }

    return url("node/$nid", array('absolute' => $this->options['absolute'], 'query' => $query));
  }
}
