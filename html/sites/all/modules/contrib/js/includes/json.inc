<?php

/**
 * @file
 * json.inc
 */

/**
 * Callback for delivering JSON responses to the browser.
 *
 * @param mixed $callback_result
 *   The result of a page callback. Can be one of:
 *   - NULL: to indicate no content.
 *   - int: An integer menu status constant: to indicate an error condition.
 *   - Array: A Drupal render array. The rendered results will be placed
 *     inside the "content" key of the JSON array. Example:
 *
 *       .success(function (json) {
 *         var content = json.content;
 *       });
 *
 *   - Array: An array of data to return.
 * @param array $info
 *   The callback definition array, may not be set.
 *
 * @see js_ajax.js
 */
function js_deliver_json($callback_result, array $info = NULL) {
  $json = array();

  $redirect_codes = array(301, 302, 303, 307);

  // Handle error responses.
  if ($callback_result === JS_MENU_NOT_FOUND) {
    drupal_set_title('Not Found');
    $json = js_http_response(404);
  }
  elseif ($callback_result === JS_MENU_ACCESS_DENIED) {
    drupal_set_title('Access Denied');
    $json = js_http_response(403);
  }
  elseif ($callback_result === JS_MENU_METHOD_NOT_ALLOWED) {
    drupal_set_title('Method Not Allowed');
    drupal_set_message(t('A request was made of a resource using a request method not supported by that resource; for example, using GET on a form which requires data to be presented via POST, or using PUT on a read-only resource. Please contact the site administrator if this problem persists.'), 'error', FALSE);
    $json = js_http_response(403);
  }
  else {
    // Extend the static JSON array with callback result.
    if (is_array($callback_result)) {
      // If returned value is a renderable, render it and place the output
      // inside the "content" key.
      if (js_is_renderable($callback_result)) {
        // Rendering requires theming, fully bootstrap Drupal.
        js_bootstrap(DRUPAL_BOOTSTRAP_FULL);
        // Set the rendered data as "content".
        $json['content'] = drupal_render($callback_result);
      }
      else {
        $json += $callback_result;
      }
    }
    // Only add a "200 OK" response if not already set or request is a redirect.
    if (empty($json['response']['code']) || in_array($json['response']['code'], $redirect_codes)) {
      $json += js_http_response();
    }
  }

  // Include general Drupal information on non-redirecting requests.
  if (!in_array($json['response']['code'], $redirect_codes)) {
    $json['title'] = drupal_get_title();
    $json['messages'] = drupal_get_messages();

    // Add in any request JS settings.
    $js = drupal_add_js();
    $settings = array();
    if (isset($js['settings']['data'])) {
      foreach ($js['settings']['data'] as $setting) {
        $settings = drupal_array_merge_deep($settings, $setting);
      }

      // Remove unnecessary core default settings.
      unset($settings['basePath']);
      unset($settings['pathPrefix']);
      unset($settings['ajaxPageState']);
    }
    $json['settings'] = $settings;
  }

  // Convert the JSON array into a string.
  $output = drupal_json_encode($json);

  // Encode the stringed $output if the browser supports gzip compression.
  if (isset($_SERVER['HTTP_ACCEPT_ENCODING']) && strpos($_SERVER['HTTP_ACCEPT_ENCODING'], 'gzip') !== FALSE) {
    $output = gzencode($output, 9);
    drupal_add_http_header('Content-Encoding', 'gzip');
    drupal_add_http_header('Vary', 'Accept-Encoding');
  }

  // Add necessary headers.
  drupal_add_http_header('Content-Type', 'application/json; charset=utf-8');
  drupal_add_http_header('Content-Length', strlen($output));

  // Add the AJAX verification header, when the AJAX backend is loaded.
  if (function_exists('ajax_set_verification_header')) {
    ajax_set_verification_header();
  }

  // Print output.
  print $output;

  // Even for AJAX requests, invoke hook_exit() implementations. There may be
  // modules that need very fast AJAX responses, and therefore, run AJAX
  // requests with an early bootstrap.
  if (drupal_get_bootstrap_phase() === DRUPAL_BOOTSTRAP_FULL && (!defined('MAINTENANCE_MODE') || MAINTENANCE_MODE != 'update')) {
    module_invoke_all('exit');
  }

  // Commit the user session.
  if (function_exists('drupal_session_commit')) {
    drupal_session_commit();
  }

  // End execution.
  exit;
}
