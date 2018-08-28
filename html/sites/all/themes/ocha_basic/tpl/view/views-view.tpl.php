<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<div class="<?php print $classes; ?>">
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <?php print $title; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($feed_icon || $feed_icons): ?>
    <div class="feed-icon text-right">
      <?php if ($feed_icons): ?>
        <?php print $feed_icons; ?>
      <?php endif; ?>
      <?php if ($feed_icon): ?>
        <div class="btn-group">
          <button type="button" class="btn btn-default dropdown-toggle" data-toggle="dropdown">
            Export
            <svg width="32" height="32" viewBox="0 0 32 32" class="arrow-down" aria-hidden="true">
              <path d="M26.2 11.7c0 0.4-0.2 0.6-0.3 0.7l-8.4 8.4c-0.4 0.4-0.9 0.6-1.5 0.6s-1.1-0.2-1.5-0.6l-8.4-8.4c-0.2-0.2-0.3-0.4-0.3-0.7s0.1-0.5 0.3-0.7c0.2-0.2 0.4-0.3 0.7-0.3s0.5 0.1 0.7 0.3l8.4 8.4c0 0 0 0 0 0s0 0 0.1 0 0.1 0 0.2 0l8.3-8.4c0.4-0.4 1-0.4 1.4 0 0.1 0.1 0.3 0.3 0.3 0.7z"></path>
            </svg>
          </button>
          <ul class="dropdown-menu">
            <?php print $feed_icon; ?>
          </ul>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php if ($header): ?>
    <div class="view-header">
      <?php print $header; ?>
    </div>
  <?php endif; ?>

  <?php if ($exposed): ?>
    <div class="view-filters">
      <?php print $exposed; ?>
    </div>
  <?php endif; ?>

  <?php if ($attachment_before): ?>
    <div class="attachment attachment-before">
      <?php print $attachment_before; ?>
    </div>
  <?php endif; ?>

  <?php if ($rows): ?>
    <div class="<?php print isset($view_content_class) ? $view_content_class : ''; ?>">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="view-empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <?php if ($pager): ?>
    <?php print $pager; ?>
  <?php endif; ?>

  <?php if ($attachment_after): ?>
    <div class="attachment attachment-after">
      <?php print $attachment_after; ?>
    </div>
  <?php endif; ?>

  <?php if ($more): ?>
    <?php print $more; ?>
  <?php endif; ?>

  <?php if ($footer): ?>
    <div class="view-footer">
      <?php print $footer; ?>
    </div>
  <?php endif; ?>

</div><?php /* class view */ ?>
