<?php

/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>
<div class="page-wrapper">
  <a href="#main-content" class="skip-link element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>

  <?php include 'cd/cd-header/cd-header.inc'; ?>

  <?php if($messages): ?>
    <div class="cd-container">
      <?php print $messages; ?>
    </div>
  <?php endif; ?>

  <div id="main-content" role="main" class="main">

    <div class="cd-container" id="main-content">

      <?php if ($page['sidebar_first']): ?>
        <aside id="sidebar-first" class="col-lg-3" role="complementary">
          <?php print render($page['sidebar_first']); ?>
        </aside>
      <?php endif; ?>

      <div id="content-wrapper" class="<?php if ($page['sidebar_first']): ?>col-lg-9<?php else: ?>col-xs-12<?php endif; ?>">

        <?php if ($title): ?>
          <h1 class="page-heading"><?php print $title; ?></h1>
        <?php endif; ?>

        <?php if ($tabs): ?>
          <?php print render($tabs); ?>
        <?php endif; ?>

        <div id="content" class="col-md-12">
          <?php print render($page['content']); ?>
        </div>

      </div>

    </div>

  </div>

</div>

<?php include 'cd/cd-footer/cd-footer.inc'; ?>
