# Feeds

On admin/structure/feeds

Obsolete?

- Infographics
- News
- Sectors
- Space categories
- Spaces

Indicators one only run on submission, so probably no longer needed.

# Cron

No custom cron function found.

# Context

ebola_datasets?

# Access modules

Obsolete

# HID

Needed

# Modules

- special_menu_items
- visualization
- "Email Contact Form Settings"
- honeypot
- linkit
- mollom
- node clone?
- calendar?
- PDF preview
- tmgmt
- RSS
- Display cache


# HR modules

## hr_admin

Not used

## hr_api

Not used

## hr_core

### hr_core.module

- view mode *search_result*
- hr_core_form_alter to hide empty select
- hr_core_entity_presave disable path auto
- hr_core_field_extra_fields not used
- hr_core_entity_view not used
- _hr_core_files_download_button not used
- hr_core_node_view not used
- hr_core_og_context_negotiation_info not needed (OG)
- hr_core_og_context_handler not needed (OG)
- hr_core_token_info not needed (OG)
- _hr_core_draft_button still needed (workflow)
- hr_core_form_node_form_alter (workflow)
- hr_core_save_draft_validate (workflow)
- hr_core_publishcontent_publish_access (workflow)
- hr_core_publishcontent_unpublish_access
- hr_core_menu_link_exists obsolete
- hr_core_addressfield_default_values_alter obsolete
- hr_core_languagefield_options_alter obsolete
- hr_core_panels_new_pane_alter needed for styling
- hr_core_node_delete (OG)
- hr_core_form_panels_ipe_edit_control_form_alter needed
- hr_core_panels_ipe_clear_cache needed
- hr_core_feeds_processor_targets_alter (Feeds) needed?
- hr_core_file_feeds_set_target (Feeds)
- hr_core_module_implements_alter (Feeds)
- hr_core_menu_alter (OG)
- hr_core_group_tab_access (OG)
- _hr_core_pane_cache_content_by_type obsolete
- _hr_core_pane_cache_simple obsolete
- _hr_core_display_cache_content obsolete
- _hr_core_display_cache_content_defaults obsolete
- _hr_core_fix_entity_reference_ajax_calls still used

## hr_indicators

Needed

## hr_layout

### hr_layout.module

Obsolete expect for

- hr_layout_block_view
  - hr_layout_login

## hr_notifications

### hr_notifications.module

- Mailchimp needed

## hr_pages

Custom code no longer needed.

## hr_panels_cache

Used.

## hr_search

Search API facets.

## hr_sectors

Rest API?

## hr_spaces

Probably no longer needed.

## hr_users

- Skype?
- HID login
