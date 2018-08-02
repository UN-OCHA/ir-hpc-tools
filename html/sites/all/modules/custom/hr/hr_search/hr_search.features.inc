<?php
/**
 * @file
 * hr_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hr_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hr_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function hr_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "local",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "100",
      "published_safe" : 0,
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "contact_real_name",
                "type" : "fulltext",
                "fields" : [ "field_last_name", "field_first_name" ],
                "description" : "A Fulltext aggregation of the following fields: Last name, First name."
              },
              "search_api_aggregation_2" : {
                "name" : "indicator_code_fulltext",
                "type" : "fulltext",
                "fields" : [ "field_ind_code" ],
                "description" : "A Fulltext aggregation of the following fields: Code."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_infographic_type:parents_all" : "field_infographic_type:parents_all",
              "field_document_type:parents_all" : "field_document_type:parents_all",
              "field_ind_cross_tagging:parents_all" : "field_ind_cross_tagging:parents_all",
              "field_ind_domain:parents_all" : "field_ind_domain:parents_all",
              "field_dataset_categories:parents_all" : "field_dataset_categories:parents_all"
            }
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_code" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "field_last_name" : true,
              "field_first_name" : true,
              "body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_code" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "field_last_name" : true,
              "field_first_name" : true,
              "body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "body:value" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "title_field" : true,
              "field_ind_disaggregation" : true,
              "field_ind_unit_desc" : true,
              "field_ind_denominator" : true,
              "field_ind_code" : true,
              "field_ind_numerator" : true,
              "field_ind_general_guidance" : true,
              "field_ind_threshold" : true,
              "field_ind_guidance_baseline" : true,
              "field_ind_guidance_phases" : true,
              "field_ind_data_sources" : true,
              "field_ind_comments" : true,
              "field_last_name" : true,
              "field_first_name" : true,
              "body:value" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_ind_code" : { "type" : "string" },
        "field_ind_comments" : { "type" : "text", "boost" : "0.5" },
        "field_ind_cross_tagging" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_data_sources" : { "type" : "text", "boost" : "0.5" },
        "field_ind_denominator" : { "type" : "text", "boost" : "0.5" },
        "field_ind_disaggregation" : { "type" : "text", "boost" : "0.5" },
        "field_ind_domain" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_general_guidance" : { "type" : "text", "boost" : "0.5" },
        "field_ind_guidance_baseline" : { "type" : "text", "boost" : "0.5" },
        "field_ind_guidance_phases" : { "type" : "text", "boost" : "0.5" },
        "field_ind_key" : { "type" : "boolean" },
        "field_ind_numerator" : { "type" : "text", "boost" : "0.5" },
        "field_ind_response" : { "type" : "boolean" },
        "field_ind_standards" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_threshold" : { "type" : "text", "boost" : "0.5" },
        "field_ind_types" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ind_unit" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_ind_unit_desc" : { "type" : "text", "boost" : "0.5" },
        "field_sectors" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_aggregation_2" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_field" : { "type" : "text" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "sorts_widget" : { "enabled" : 1, "autosubmit" : 1, "autosubmit_hide" : 1, "title" : "" }
    },
    "enabled" : "1",
    "read_only" : "0",
    "path" : { "pathauto" : "0" }
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function hr_search_default_search_api_server() {
  $items = array();
  $items['local'] = entity_import('search_api_server', '{
    "name" : "Local",
    "machine_name" : "local",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 1,
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "language",
            "type" : "string",
            "boost" : "1.0"
          },
          "url" : {
            "table" : "search_api_db_default_node_index",
            "column" : "url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_default_node_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_ind_code" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_ind_code",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_ind_comments" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_data_sources" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_denominator" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_disaggregation" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_general_guidance" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_guidance_baseline" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_guidance_phases" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_numerator" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_threshold" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "field_ind_unit_desc" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "0.5"
          },
          "title_field" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_sectors" : {
            "table" : "search_api_db_default_node_index_field_sectors",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_ind_cross_tagging" : {
            "table" : "search_api_db_default_node_index_field_ind_cross_tagging",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_ind_domain" : {
            "table" : "search_api_db_default_node_index_field_ind_domain",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_ind_key" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_ind_key",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_ind_response" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_ind_response",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "field_ind_standards" : {
            "table" : "search_api_db_default_node_index_field_ind_standards",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_ind_types" : {
            "table" : "search_api_db_default_node_index_field_ind_types",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_ind_unit" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_ind_unit",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_aggregation_1" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_aggregation_2" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_default_node_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_default_node_index",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "path" : { "pathauto" : "0" }
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function hr_search_default_search_api_sort() {
  $items = array();
  $items['default_node_index__changed'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "changed",
    "name" : "Last updated",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__changed",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Date changed" },
    "path" : { "pathauto" : "0" }
  }');
  $items['default_node_index__created'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "created",
    "name" : "Date created",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__created",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "Date created" },
    "path" : { "pathauto" : "0" }
  }');
  $items['default_node_index__field_asst_date:value'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_asst_date:value",
    "name" : "Assessment Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_asst_date:value",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "field_asst_date:value" },
    "path" : { "pathauto" : "0" }
  }');
  $items['default_node_index__field_ds_date'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_ds_date",
    "name" : "Dataset Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_ds_date",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "field_ds_date" },
    "path" : { "pathauto" : "0" }
  }');
  $items['default_node_index__field_first_name'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_first_name",
    "name" : "First name",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_first_name",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "field_first_name" },
    "path" : { "pathauto" : "0" }
  }');
  $items['default_node_index__field_last_name'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_last_name",
    "name" : "Last name",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_last_name",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "field_last_name" },
    "path" : { "pathauto" : "0" }
  }');
  $items['default_node_index__field_publication_date'] = entity_import('search_api_sort', '{
    "index_id" : "default_node_index",
    "field" : "field_publication_date",
    "name" : "Publication Date",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "default_node_index__field_publication_date",
    "default_sort" : "0",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "field_publication_date" },
    "path" : { "pathauto" : "0" }
  }');
  return $items;
}
