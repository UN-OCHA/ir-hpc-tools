<?php
/**
 * @file
 * hr_layout.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function hr_layout_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_clusters';
  $page->task = 'page';
  $page->admin_title = 'Clusters';
  $page->admin_description = '';
  $page->path = 'clusters';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Clusters',
    'name' => 'main-menu',
    'weight' => '4',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_clusters_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_clusters';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_clusters_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'clusters text',
    'title' => '',
    'body' => '<p>When emergencies occur coordination is necessary. Good coordination means less gaps and overlaps in the assistance delivered by humanitarian organizations.</p>

<p>The foundations of the current international humanitarian coordination system were set by General Assembly resolution 46/182 in December 1991. Almost 15 years later, in 2005, a major reform of humanitarian coordination, known as the Humanitarian Reform Agenda, introduced a number of new elements to enhance predictability, accountability and partnership. The Cluster Approach was one of these new elements.</p>

<p>Clusters are groups of humanitarian organizations, both UN and non-UN, in each of the main sectors of humanitarian action, e.g. water, health and logistics. They are designated by the Inter-Agency Standing Committee (IASC) and have clear responsibilities for coordination.</p>

<p class="text-center"><a class="btn btn-primary" href="/clusters/space">Read all the information about clusters</a></p>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2532dff5-41bf-471e-a491-cee72a7612f5';
  $display->content['new-2532dff5-41bf-471e-a491-cee72a7612f5'] = $pane;
  $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane = new stdClass();
  $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/clusters.png" class="img-responsive" alt="Cluster Approach" />',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->content['new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e'] = $pane;
  $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_clusters'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_coordination';
  $page->task = 'page';
  $page->admin_title = 'Coordination';
  $page->admin_description = '';
  $page->path = 'coordination';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Coordination',
    'name' => 'main-menu',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hr_coordination_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_coordination';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_hr_coordination_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Coordination text',
    'title' => '',
    'body' => '<p>Humanitarian coordination involves bringing together humanitarian actors to ensure a coherent and principled response to emergencies. The aim is to assist people when they most need relief or protection.</p>

<p>Humanitarian coordination seeks to improve the effectiveness of humanitarian response by ensuring greater predictability, accountability and partnership. Coordination involves assessing situations and needs; agreeing common priorities; developing common strategies to address issues such as negotiating access, mobilizing funding and other resources; clarifying consistent public messaging; and monitoring progress.</p>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2532dff5-41bf-471e-a491-cee72a7612f5';
  $display->content['new-2532dff5-41bf-471e-a491-cee72a7612f5'] = $pane;
  $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane = new stdClass();
  $pane->pid = 'new-029e719e-a02b-4a49-a595-69273bc5306d';
  $pane->panel = 'column1';
  $pane->type = 'views_panes';
  $pane->subtype = 'hr_spaces-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '029e719e-a02b-4a49-a595-69273bc5306d';
  $display->content['new-029e719e-a02b-4a49-a595-69273bc5306d'] = $pane;
  $display->panels['column1'][1] = 'new-029e719e-a02b-4a49-a595-69273bc5306d';
  $pane = new stdClass();
  $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/coordination.jpg" class="img-responsive" alt="Coordination" />',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'hr_highlighted',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->content['new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e'] = $pane;
  $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_coordination'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hr_home__home';
  $handler->task = 'page';
  $handler->subtask = 'hr_home';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'home',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'home',
  );
  $display = new panels_display();
  $display->layout = 'radix_sutro';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'footer' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'column3' => NULL,
      'quarter1' => NULL,
      'quarter2' => NULL,
      'half' => NULL,
      'secondarycolumn1' => NULL,
      'secondarycolumn2' => NULL,
      'secondarycolumn3' => NULL,
    ),
    'contentmain' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array(
    'method' => 'hr_content',
    'settings' => array(
      'granularity' => array(
        'args' => 'args',
        'user_role' => 'user_role',
      ),
      'granularity_url' => 'base_url_system',
      'granularity_roles_as_anon' => array(),
      'granularity_role_selection' => 'all',
      'lifetime' => 922,
      'content_type' => 'hr_operation',
    ),
  );
  $display->title = 'Home';
  $display->uuid = 'b4f0cdd8-1e4b-4d49-b201-90e3bbd936dc';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_hr_home__home';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-af40011a-0d43-4229-8c50-de2904878c60';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Clusters - Column 1',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="icons-list">
	<p>
		<a href="/en/indicators/global-clusters/1">
		<span class="icon-cccm"></span>Camp Coordination and Camp Management</a>
	</p>
	<p>
		<a href="/en/indicators/global-clusters/2"><span class="icon-early-recovery"></span>Early Recovery</a>
	</p>
	<p>
		<a href="/en/indicators/global-clusters/3"><span class="icon-education"></span>Education</a>
	</p>
	<p>
		<a href="/en/indicators/global-clusters/5"><span class="icon-telecom"></span>Emergency Telecommunications</a>
	</p>
	<p>
		<a href="/en/indicators/global-clusters/6"><span class="icon-foodsecurity"></span>Food Security</a>
	</p>
	<p>
		<a href="/en/indicators/global-clusters/7"><span class="icon-health"></span>Health</a>
	</p>
</div>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'af40011a-0d43-4229-8c50-de2904878c60';
  $display->content['new-af40011a-0d43-4229-8c50-de2904878c60'] = $pane;
  $display->panels['column1'][0] = 'new-af40011a-0d43-4229-8c50-de2904878c60';
  $pane = new stdClass();
  $pane->pid = 'new-b55cb90f-4739-4a96-aad1-f0d3bc8b2ddb';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Clusters - Column 2',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="icons-list">

<p>
<a href="/en/indicators/global-clusters/8">

<span class="icon-logistics"></span>Logistics</a>

</p>

<p>

<a href="/en/indicators/global-clusters/9"><span class="icon-nutrition"></span>Nutrition</a>

</p>

<p>

<a href="/en/indicators/global-clusters/10"><span class="icon-protection"></span>Protection</a>

</p>

<p>

<a href="/en/indicators/global-clusters/4"><span class="icon-shelter"></span>Shelter</a>

</p>

<p>

<a href="/en/indicators/global-clusters/11"><span class="icon-wash"></span>Water, Sanitation and Hygiene</a>

</p>

</div>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b55cb90f-4739-4a96-aad1-f0d3bc8b2ddb';
  $display->content['new-b55cb90f-4739-4a96-aad1-f0d3bc8b2ddb'] = $pane;
  $display->panels['column2'][0] = 'new-b55cb90f-4739-4a96-aad1-f0d3bc8b2ddb';
  $pane = new stdClass();
  $pane->pid = 'new-1ac6444b-b388-457e-9182-d0b290fde368';
  $pane->panel = 'header';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'About text',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="col-sm-9">
<p><strong>Background</strong> : The humanitarian indicator registry is complimentary to the Inter-Agency Standing Committee (IASC) Humanitarian Programme Cycle (HPC) reference module. The indicators listed in the registry have been developed by the global clusters. While recognising that indicators cannot be fully standardised across countries, given the vast range of emergencies and country contexts, it is recommend to adopt and use the indicators listed as &lsquo;key&rsquo;&nbsp; to allow comparison of needs and response monitoring across countries.</p>
<p>The registry will be reviewed and enhanced over the next few months to allow for periodic updates from the field and better compilation of multi-sectoral indicator selections.&nbsp;Clusters/Sectors at the field level are encouraged to contact their Global Cluster Coordinators for further guidance.</p>

<p><strong>Purpose</strong> : The registry is a guidance tool for countries to select indicators, and where possible seek standard definitions and applications of those indicators. It lists the principal needs and response monitoring indicators for each cluster and provides a unique identifier, similar to a p-code, for every indicator. The registry offers also search, filter and export functions.</p>

<p>The reference indicators may be used to track needs over time and to support monitoring along the programme cycle. They can be used for analysis and reporting and may feature in humanitarian needs overviews, strategic planning and monitoring documents, humanitarian dashboards and bulletins.</p>

<p><strong>Scope</strong> : This registry is a point of reference for Humanitarian Country Teams and clusters at the country level for indicators which are recommended for monitoring the humanitarian situation, needs and the humanitarian response. &nbsp;The registry does not capture (long-term) impact or input indicators (as many input indicators can feed into one output). There may be other indicators which some global clusters recommend, or other indicators which are only locally appropriate which may not be captured in the registry.</p>
</div>
<div class="col-sm-3"><div class="center-block"><a href="/sites/default/files/qaindicatorregistry.pdf" target="_blank"><img alt="IR Q&amp;A" class="img-responsive center-block" src="/sites/default/files/irqa.jpg" /></a></div></div>',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1ac6444b-b388-457e-9182-d0b290fde368';
  $display->content['new-1ac6444b-b388-457e-9182-d0b290fde368'] = $pane;
  $display->panels['header'][0] = 'new-1ac6444b-b388-457e-9182-d0b290fde368';
  $pane = new stdClass();
  $pane->pid = 'new-449e22da-bf76-436e-ba96-93f3f8aea945';
  $pane->panel = 'header';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Intro blurb',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="col-sm-12">
<p>The registry is a guidance tool for countries to select indicators, and where possible to seek standard definitions and applications of those indicators. It lists the principal needs and response monitoring indicators for each cluster and provides a unique identifier, similiar to a p-code, for every indicator. This registry offers also: search, filter, and export functions.</p></div>
',
    'format' => 'full_html',
    'substitute' => TRUE,
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '604800',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '449e22da-bf76-436e-ba96-93f3f8aea945';
  $display->content['new-449e22da-bf76-436e-ba96-93f3f8aea945'] = $pane;
  $display->panels['header'][1] = 'new-449e22da-bf76-436e-ba96-93f3f8aea945';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_home'] = $page;

  $page = new stdClass();
  $page->disabled = TRUE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'hr_programme_cycle';
  $page->task = 'page';
  $page->admin_title = 'Programme Cycle';
  $page->admin_description = '';
  $page->path = 'programme-cycle';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Programme Cycle',
    'name' => 'main-menu',
    'weight' => '6',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array();
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_hr_programme_cycle_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'hr_programme_cycle';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Landing page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'radix_phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd4221dbc-34fc-4b55-9af5-da36c1017271';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_hr_programme_cycle_panel_context';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane->panel = 'column1';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Programme Cycle text',
    'title' => '',
    'body' => '<p>Welcome to the Humanitarian Programme Cycle space on HumanitarianResponse.info</p><p>The Humanitarian Programme Cycle (HPC) is the way in which humanitarian actors work together to help people affected by disasters and conflict. In these pages, you will find guidance, practical tools and templates as well as background information on the various elements which together make up the programme cycle.</p>',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2532dff5-41bf-471e-a491-cee72a7612f5';
  $display->content['new-2532dff5-41bf-471e-a491-cee72a7612f5'] = $pane;
  $display->panels['column1'][0] = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $pane = new stdClass();
  $pane->pid = 'new-aae1a8c7-93d3-4578-8cc4-52f705db0898';
  $pane->panel = 'column1';
  $pane->type = 'views_panes';
  $pane->subtype = 'hr_spaces-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'aae1a8c7-93d3-4578-8cc4-52f705db0898';
  $display->content['new-aae1a8c7-93d3-4578-8cc4-52f705db0898'] = $pane;
  $display->panels['column1'][1] = 'new-aae1a8c7-93d3-4578-8cc4-52f705db0898';
  $pane = new stdClass();
  $pane->pid = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $pane->panel = 'column2';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'body' => '<img src="/sites/all/themes/humanitarianresponse/assets/images/programme-cycle.png" class="img-responsive" alt="Programme Cycle" />',
    'format' => 'panopoly_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
    'style' => 'hr_highlighted',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->content['new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e'] = $pane;
  $display->panels['column2'][0] = 'new-4f09f2dc-c52b-4a71-abe8-4f3a8037042e';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-2532dff5-41bf-471e-a491-cee72a7612f5';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['hr_programme_cycle'] = $page;

  return $pages;

}
