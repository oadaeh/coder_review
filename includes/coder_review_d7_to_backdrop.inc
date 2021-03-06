<?php
/**
 * @file
 * This include file implements coder functionality for 7.x -> 8.x upgrades.
 */

/**
 * Implements hook_reviews().
 */
function coder_review_d7_to_backdrop_reviews() {
  $argex = '(((&?\$?)[a-zA-Z_]+((\([^)]*\))|\[[^\]]*\])?)|[0-9]+(\.[0-9]*)?|\'\'|"")';

  $rules[] = array(
    '#type' => 'callback',
    '#value' => '_coder_review_d7_to_backdrop_variable_callback',
  );
  $rules[] = array(
    '#source' => 'all',
    '#type' => 'regex',
    '#value' => '\$classes_array',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $classes_array is now $classes (flatten in template file)',
      '#link' => _backdropnode(28554),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$attributes_array',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $attributes_array is now $attributes (flatten in template file)',
      '#link' => _backdropnode(28554),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$content_attributes_array',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $content_attributes_array is now $content_attributes (flatten in template file)',
      '#link' => _backdropnode(28554),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$html_attributes_array',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $html_attributes_array is now $html_attributes (flatten in template file)',
      '#link' => _backdropnode(28554),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$body_attributes_array',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $body_attributes_array is now $body_attributes (flatten in template file)',
      '#link' => _backdropnode(28554),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$item_attributes_array',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $item_attributes_array is now $item_attributes (flatten in template file)',
      '#link' => _backdropnode(28554),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$title_attributes_array',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $item_attributes_array has been removed',
      '#link' => _backdropnode(28554),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'print\s*\$head\;',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $head variable has been removed. Use backdrop_get_html_head()',
      '#link' => _backdropnode(28554),
    ),
    '#filename' => array('tpl.php'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'print\s*\$styles\;',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $styles variable has been removed. Use backdrop_get_css()',
      '#link' => _backdropnode(28554),
    ),
    '#filename' => array('tpl.php'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'print\s*\$scripts\;',
    '#warning' => array(
      '#text' => 'Process layer has been removed. $scripts variable has been removed. Use backdrop_get_js()',
      '#link' => _backdropnode(28554),
    ),
    '#filename' => array('tpl.php'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]_color_page_alter\s*\(',
    '#warning' => array(
      '#text' => 'Function _color_page_alter() layer has been removed.',
      '#link' => _backdropnode(28554),
    ),
    '#filename' => array('tpl.php'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]contextual_process\s*\(',
    '#warning' => array(
      '#text' => 'Function contextual_process() layer has been removed.',
      '#link' => _backdropnode(28554),
    ),
    '#filename' => array('contextual.module'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]template_process_username\s*\(',
    '#warning' => array(
      '#text' => 'Function template_process_username() layer has been removed.',
      '#link' => _backdropnode(28554),
    ),
    '#filename' => array('user.module'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]template_process_views_view\s*\(',
    '#warning' => array(
      '#text' => 'Function template_process_views_view() layer has been removed.',
      '#link' => _backdropnode(28554),
    ),
    '#filename' => array('theme.inc'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#source' => 'all',
    '#value' => 'file\[\]\s*\=',
    '#warning' => array(
      '#text' => 'The class registry has been replaced with a static class map.',
      '#link' => _backdropnode(26859),
    ),
    '#filename' => array('info'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s*getInfo\s*\(',
    '#warning' => array(
      '#text' => 'getInfo() is deprecated. Information about tests should now be in module.tests.info.',
      '#link' => _backdropnode(26860),
    ),
    '#filename' => array('test'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '(block_role|block_node_type)', // @todo: maybe this should search for db queries using these tables.
    '#warning' => array(
      '#text' => 'Block module no longer provides database tables.',
      '#link' => _backdropnode(26861),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(block_view)\s*\(\s*\$delta\s*=\s*\'\'\s*\)',
    '#warning' => array(
      '#text' => 'hook_block_view() now receives two additional arguments for $settings and $contexts.',
      '#link' => _backdropnode(26861),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(block_save)\s*\(\s*\$delta\s*=\s*\'\'\s*,\s*\$edit',
    '#warning' => array(
      '#text' => 'hook_block_save() now takes the $edit parameter by reference, as in &$edit.',
      '#link' => _backdropnode(26861),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]block_custom_block_get\s*\(',
    '#warning' => array(
      '#text' => 'block_custom_block_get() is now block_custom_block_load() and takes a block $delta as parameter rather than $bid.',
      '#link' => _backdropnode(26861),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$page',
    '#warning' => array(
      '#text' => '$page variable has been removed.',
      '#link' => _backdropnode(26861),
    ),
    '#filename' => array('tpl.php'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(page_alter|page_build)\s*\(\s*(&\$page)',
    '#warning' => array(
      '#text' => 'hook_page_alter() and hook_page_build() have been removed.',
      '#link' => _backdropnode(26861),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$page\[\'\#show_messages\'\]\s*=\s*FALSE',
    '#warning' => array(
      '#text' => 'As the $page renderable no longer exists, the function backdrop_display_messages(FALSE) should be used to hide (or show) messages for a page request.',
      '#link' => _backdropnode(26861),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]drupal_set_page_content\s*\(',
    '#warning' => array(
      '#text' => 'drupal_set_page_content() has been removed. Block content is now managed by Layout module\'s UI.',
      '#link' => _backdropnode(26861),
    ),
  );
  $rules[] = array(
    '#type' => 'callback',
    '#value' => '_coder_review_d7_to_backdrop_htmltpl_callback',
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '(\$action_links|\$node|\$is_admin)',
    '#warning' => array(
      '#text' => '$action_links, $node, $is_admin variables have been removed.',
      '#link' => _backdropnode(26861),
    ),
    '#filename' => array('tpl.php'),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#source' => 'quote',
    '#value' => 'admin\/appearance\/settings\'',
    '#warning' => array(
      '#text' => 'The global theme settings page at "/admin/appearance/settings" has been removed.',
      '#link' => _backdropnode(26863),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '(\$node|\$account|\$file|\$entity|\$term)\s*=\s*new\sstdClass\(\)',
    '#warning' => array(
      '#text' => 'Nodes, Users, Files, Terms and Entities are now classed objects. Consider initializing with entity_create()',
      '#link' => _backdropnode(26881),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '(\$vocabulary)\s*=\s*new\sstdClass\(\)',
    '#warning' => array(
      '#text' => 'Vocabularies are now classed objects. Consider initializing with <code>$vocabulary = new TaxonomyVocabulary</code>',
      '#link' => _backdropnode(26881),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]user_save\s*\(\s*(' . $argex . '\s*,\s*){1,}(' . $argex . ')\s*\)',
    '#warning' => array(
      '#text' => 'user_save() now only takes one parameter: a User entity.',
      '#link' => _backdropnode(26867),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(user_insert|user_update|user_presave)\s*\(\s*&\$edit,\s*\$account,\s*\$category\s*\)',
    '#warning' => array(
      '#text' => 'User hooks now take a single argument: $account',
      '#link' => _backdropnode(26867),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'taxonomy->vid',
    '#warning' => array(
      '#text' => 'Vocabularies no longer have numerically indexed vid. Instead, vocabularies are referenced exclusively by the $vocabulary->machine_name property',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'term->vid',
    '#warning' => array(
      '#text' => '$term->vid has been removed. Parent vocabularies are referenced by $term->vocabulary property',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_vocabulary_load\s*\(\s*\$vid',
    '#warning' => array(
      '#text' => 'taxonomy_vocabulary_load() parameters have changed. Now takes "$vocabulary_name" instead of "$vid".',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_vocabulary_delete\s*\(\s*\$vid',
    '#warning' => array(
      '#text' => 'taxonomy_vocabulary_delete() parameters have changed. Now takes "$vocabulary_name" instead of "$vid".',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_get_tree\s*\(\s*\$vid',
    '#warning' => array(
      '#text' => 'taxonomy_get_tree() parameters have changed. Now takes "$vocabulary_name" instead of "$vid".',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_vocabulary_load_multiple\s*\(\s*\$vids',
    '#warning' => array(
      '#text' => 'taxonomy_vocabulary_load_multiple() parameters have changed. Now takes "$vocabulary_names" instead of "$vids".',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_term_load_children\s*\(\s*(' . $argex . '\s*,\s*)\$vid',
    '#warning' => array(
      '#text' => 'taxonomy_term_load_children() parameters have changed. Now takes "$vocabulary_name" instead of "$vid".',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'taxonomy_vocabulary_machine_name_load',
    '#warning' => array(
      '#text' => 'taxonomy_vocabulary_machine_name_load() has been removed.',
      '#link' => _backdropnode(26869),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]user_role_load\s*\(\s*\$rid',
    '#warning' => array(
      '#text' => 'user_role_load() parameters have changed. Now takes "$role_name" instead of "$rid".',
      '#link' => _backdropnode(26870),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'user_role_load_by_name',
    '#warning' => array(
      '#text' => 'user_role_load_by_name() has been removed.',
      '#link' => _backdropnode(26870),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'BACKDROP_ANONYMOUS_RID',
    '#warning' => array(
      '#text' => 'BACKDROP_ANONYMOUS_RID  is now BACKDROP_ANONYMOUS_ROLE and is the value \'anonymous\' instead of the integer 1.',
      '#link' => _backdropnode(26870),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'BACKDROP_AUTHENTICATED_RID',
    '#warning' => array(
      '#text' => 'BACKDROP_AUTHENTICATED_RID  is now BACKDROP_AUTHENTICATED_ROLE and is the value \'authenticated\' instead of the integer 2.',
      '#link' => _backdropnode(26870),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'field_info_field_by_ids',
    '#warning' => array(
      '#text' => 'field_info_field_by_ids() has been removed.',
      '#link' => _backdropnode(26871),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'theme_checkboxes',
    '#warning' => array(
      '#text' => 'theme_checkboxes() has been removed.',
      '#link' => _backdropnode(26874),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'theme_radios',
    '#warning' => array(
      '#text' => 'theme_radios() has been removed.',
      '#link' => _backdropnode(26874),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]theme\s*\(\s*\'checkboxes',
    '#warning' => array(
      '#text' => 'theme_checkboxes() has been removed.',
      '#link' => _backdropnode(26874),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]theme\s*\(\s*\'radios',
    '#warning' => array(
      '#text' => 'theme_radios() has been removed.',
      '#link' => _backdropnode(26874),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'system_admin_compact_mode',
    '#warning' => array(
      '#text' => 'system_admin_compact_mode() has been removed.',
      '#link' => _backdropnode(26874),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'theme_system_compact_link',
    '#warning' => array(
      '#text' => 'theme_system_compact_link() has been removed.',
      '#link' => _backdropnode(26874),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]theme\s*\(\s*\'system_compact_link',
    '#warning' => array(
      '#text' => 'theme_system_compact_link() has been removed.',
      '#link' => _backdropnode(26874),
    ),
  );
  $rules[] = array(
    '#source' => 'php',
    '#type' => 'callback',
    '#value' => '_coder_review_d7_to_backdrop_removed_module_callback',
    '#severity' => 'minor'
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'php_eval',
    '#warning' => array(
      '#text' => 'php_eval() has been removed.',
      '#link' => _backdropnode(28538),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(help)\s*\(\s*\$path,\s*\$arg',
    '#warning' => array(
      '#text' => 'hook_help() has been removed.',
      '#link' => _backdropnode(28538),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#function' => '_form$',
    '#value' => 'return\s*system_settings_form\(\$[a-z0-9_]+\)',
    '#warning' => array(
      '#text' => 'system_settings_form() now requires a \'#config\' key.',
      '#link' => _backdropnode(28552),
    ),
    '#severity' => 'minor'
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'locale_language_list',
    '#warning' => array(
      '#text' => 'locale_language_list() has been removed.',
      '#link' => _backdropnode(29321),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'navigation',
    '#source' => 'quote',
    '#function' => '(_menu$|_menu_alter$)',
    '#warning' => array(
      '#text' => 'The Navigation menu has been removed.',
      '#link' => _backdropnode(26875),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_get_parents\s*\(',
    '#warning' => array(
      '#text' => 'taxonomy_get_parents() has been renamed to taxonomy_term_load_parents().',
      '#link' => _backdropnode(41635),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_get_parents_all\s*\(',
    '#warning' => array(
      '#text' => 'taxonomy_get_parents_all() has been renamed to taxonomy_term_load_parents_all().',
      '#link' => _backdropnode(41635),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_get_children\s*\(',
    '#warning' => array(
      '#text' => 'taxonomy_get_children() has been renamed to taxonomy_term_load_children().',
      '#link' => _backdropnode(41635),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_get_term_by_name\s*\(',
    '#warning' => array(
      '#text' => 'taxonomy_get_term_by_name() has been renamed to taxonomy_term_load_multiple_by_name().',
      '#link' => _backdropnode(41635),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]file_delete\s*\(\s*(' . $argex . '\s*,\s*){1,}(' . $argex . ')\s*\)',
    '#warning' => array(
      '#text' => 'file_delete() now only takes one parameter: a file ID ($fid).',
      '#link' => _backdropnode(41637),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]file_delete\s*\(\s*\$file',
    '#warning' => array(
      '#text' => 'file_delete() now takes a file ID ($fid), not a File object.',
      '#link' => _backdropnode(41637),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '\$[a-zA-Z_]+\s*=\s*file_delete\s*\(',
    '#warning' => array(
      '#text' => 'file_delete() no longer has a return value.',
      '#link' => _backdropnode(41637),
    ),
  );
  $rules[] = array(
    '#type' => 'grep',
    '#value' => 'theme_dblog_message',
    '#warning' => array(
      '#text' => 'theme_dblog_message() has been removed.',
      '#link' => _backdropnode(41638),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]theme\s*\(\s*\'dblog_message',
    '#warning' => array(
      '#text' => 'theme_dblog_message() has been removed.',
      '#link' => _backdropnode(41638),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]format_username\s*\(',
    '#warning' => array(
      '#text' => 'format_username() has been renamed to user_format_name().',
      '#link' => _backdropnode(41640),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]system_get_date_types\s*\(',
    '#warning' => array(
      '#text' => 'system_get_date_types() deprecated; use system_get_date_formats().',
      '#link' => _backdropnode(41648),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]element_sort\s*\(',
    '#warning' => array(
      '#text' => 'element_sort() deprecated; use backdrop_sort().',
      '#link' => _backdropnode(41649),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]element_sort_by_title\s*\(',
    '#warning' => array(
      '#text' => 'element_sort_by_title() deprecated; use backdrop_sort().',
      '#link' => _backdropnode(41649),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]_filter_list_cmp\s*\(',
    '#warning' => array(
      '#text' => '_filter_list_cmp() deprecated; use backdrop_sort().',
      '#link' => _backdropnode(41649),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]_image_effect_definitions_sort\s*\(',
    '#warning' => array(
      '#text' => '_image_effect_definitions_sort() deprecated; use backdrop_sort().',
      '#link' => _backdropnode(41649),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]uasort\s*\(',
    '#function-not' => '^backdrop_sort$',
    '#warning' => array(
      '#text' => 'Consider using backdrop_sort() instead of uasort().',
      '#link' => _backdropnode(41649),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#source' => 'allphp',
    '#value' => '\$form\[\'\#node_edit_form\'\].',
    '#warning' => array(
      '#text' => '$form[\'#node_edit_form\'] is no longer set..',
      '#link' => _backdropnode(41660),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]date_iso8601\s*\(',
    '#warning' => array(
      '#text' => 'date_iso8601() has been removed.',
      '#link' => _backdropnode(41662),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]system_date_format_locale\s*\(',
    '#warning' => array(
      '#text' => 'system_date_format_locale() has been removed.',
      '#link' => _backdropnode(41663),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(node_info)\s*\(',
    '#warning' => array(
      '#text' => 'hook_node_info() has been removed.',
      '#link' => _backdropnode(41664),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]user_pass_rehash\s*\(\s*(' . $argex . '\s*,\s*){2}(' . $argex . ')\s*\)',
    '#warning' => array(
      '#text' => 'user_pass_rehash() now requires the user account ID as a fourth parameter.',
      '#link' => _backdropnode(26867),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(library)\s*\(',
    '#warning' => array(
      '#text' => 'hook_library() has been renamed to hook_library_info().',
      '#link' => _backdropnode(41686),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(library_alter)\s*\(',
    '#warning' => array(
      '#text' => 'hook_library_alter() has been renamed to hook_library_info_alter().',
      '#link' => _backdropnode(41686),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]language_list\s*\(\s*' . $argex . '\s*\)',
    '#warning' => array(
      '#text' => 'language_list() now accepts a second parameter parameter.',
      '#link' => _backdropnode(26867),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(user_categories)\s*\(',
    '#warning' => array(
      '#text' => 'The hook_user_categories() has been removed.',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]locale_language_selector_form\s*\(\s*&\$form\s*,\s*&\$form_state\s*,\s*\$user\s*\)',
    '#warning' => array(
      '#text' => 'locale_language_selector_form() now only takes one parameter: $user.',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]user_module_invoke\s*\(\s*\$type\s*,\s*&\$edit\s*,\s*\$account\s*,\s*\$category',
    '#warning' => array(
      '#text' => 'The categories parameter has been removed from user_module_invoke().',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]user_profile_form\s*\(\s*\$form\s*,\s*&\$form_state\s*,\s*\$account\s*,\s*\$category',
    '#warning' => array(
      '#text' => 'The categories parameter has been removed from user_profile_form().',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]user_element_info\s*\(',
    '#warning' => array(
      '#text' => 'user_element_info() has been removed.',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]user_category_load\s*\(',
    '#warning' => array(
      '#text' => 'user_category_load() has been removed.',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(preprocess_user_profile_item)\s*\(',
    '#warning' => array(
      '#text' => 'The template_preprocess_user_profile_item() has been removed.',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'function\s+[a-z0-9_]+_(preprocess_user_profile_category)\s*\(',
    '#warning' => array(
      '#text' => 'The template_preprocess_user_profile_category() has been removed.',
      '#link' => _backdropnode(43511),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'element_validate_integer_positive',
    '#source' => 'quote',
    '#warning' => array(
      '#text' => 'element_validate_integer_positive() has been removed in favor of the number element type.',
      '#link' => _backdropnode(43955),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'element_validate_integer',
    '#source' => 'quote',
    '#warning' => array(
      '#text' => 'element_validate_integer() has been removed in favor of the number element type.',
      '#link' => _backdropnode(43955),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]drupal_is_denied\s*\(',
    '#warning' => array(
      '#text' => 'drupal_is_denied() has been removed.',
      '#link' => _backdropnode(44866),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => '[\s\(]taxonomy_term_uri\s*\(',
    '#warning' => array(
      '#text' => 'taxonomy_term_uri() has been removed.',
      '#link' => _backdropnode(44866),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'drupal',
    '#source' => 'all',
    '#warning' => array(
      '#text' => '"drupal" replaced by "backdrop".',
      '#link' => _backdropnode(26857),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'Drupal',
    '#source' => 'all',
    '#warning' => array(
      '#text' => '"Drupal" replaced by "Backdrop".',
      '#link' => _backdropnode(26857),
    ),
  );
  $rules[] = array(
    '#type' => 'regex',
    '#value' => 'DRUPAL',
    '#source' => 'all',
    '#warning' => array(
      '#text' => '"DRUPAL" replaced by "BACKDROP".',
      '#link' => _backdropnode(26857),
    ),
  );

  $review = array(
    '#title' => 'Converting 7.x modules to Backdrop',
    '#link' => 'https://api.backdropcms.org/change-records',
    '#rules' => $rules,
    '#severity' => 'critical',
    '#version' => 2,
    '#image' => 'images/bd.png',
  );

  return array('upgrade_d7_to_backdrop' => $review);
}


/**
 * @todo: add a function header comment.
 */
function _coder_review_d7_to_backdrop_variable_callback(&$coder_args, $review, $rule, $lines, &$results) {
  $states = array(
    'block_test_caching',
    'block_test_content',
    'config_sync',
    'cron_key',
    'cron_last',
    'css_js_query_string',
    'dependencies',
    'dependency_test',
    'entity_cache_test_label',
    'file_test_hook_file_url_alter',
    'image_module_test_file_download',
    'install_profile_modules',
    'install_task',
    'install_time',
    'javascript_parsed',
    'js_version_query_string',
    'locale_test_content_language_type',
    'locale_test_domain',
    'locale_test_language_negotiation_info',
    'locale_test_language_negotiation_info_alter',
    'locale_test_language_types',
    'maintenance_mode',
    'menu_masks',
    'menu_rebuild_needed',
    'node_access_needs_rebuild',
    'node_access_test_private',
    'node_test_node_access_all_uid',
    'path_alias_whitelist',
    'test_dynamic_access_argument1',
    'test_dynamic_access_argument2',
    'test_email_collector',
    'test_module_disable_order',
    'test_module_enable_order',
    'test_verbose_module_hooks',
    'update_last_check',
    'update_last_email_notification',
    'update_script_test_requirement_type',
    'update_test_system_info',
    'update_test_update_status',
    'update_test_xml_map',
    'views_test_schema',
    'views_test_views_data',
    'views_test_views_data_count',
    'views_test_views_plugins',
  );

  $settings = array(
    '404_fast_html',
    '404_fast_paths',
    '404_fast_paths_exclude',
    'allow_insecure_uploads',
    'cache_backends',
    'css_gzip_compression',
    'file_chmod_directory',
    'file_chmod_file',
    'filter_allowed_protocols',
    'js_gzip_compression',
    'lock_inc',
    'mail_line_endings',
    'mail_system',
    'maximum_replication_lag',
    'page_cache_invoke_hooks',
    'page_cache_without_database',
    'password_count_log2',
    'password_inc',
    'queue_class_*',
    'queue_default_class',
    'queue_default_reliable_class',
    'session_inc',
    'session_write_interval',
    'stale_file_threshold',
  );

  $argex = '(((&?\$?)[a-zA-Z_]+((\([^)]*\))|\[[^\]]*\])?)|[0-9]+(\.[0-9]*)?|\'\'|"")';
  $filename = $coder_args['#filename'];
  if (file_exists($filename)) {
    $lines = file($filename);
    if ($lines) {
      foreach ($lines as $lineno => $line) {
        if (preg_match('/[\s\(](variable_get|variable_set|variable_del)+\s*\(\s*[\'\$]([a-zA-Z_]+)\'/', $line, $match)) {
          if (in_array($match[2], $states)) {
            $severity_name = _coder_review_severity_name($coder_args, $review, $rule);
            $tmprule = $rule;
            $tmprule['#warning'] = array(
              '#text' => 'Non-configuration variables have been converted to states system.',
              '#link' => _backdropnode(28553),
            );
            _coder_review_error($results, $tmprule, $severity_name, $lineno, $line, $coder_args['#ignores']);
          }
          elseif (in_array($match[2], $settings)) {
            $severity_name = _coder_review_severity_name($coder_args, $review, $rule);
            $tmprule = $rule;
            $tmprule['#warning'] = array(
              '#text' => 'Non-configuration variables have been converted to settings system.',
              '#link' => _backdropnode(28553),
            );
            _coder_review_error($results, $tmprule, $severity_name, $lineno, $line, $coder_args['#ignores']);
          }
          else {
            $severity_name = _coder_review_severity_name($coder_args, $review, $rule);
            $tmprule = $rule;
            $tmprule['#warning'] = array(
              '#text' => 'Variable_get, variable_set, and variable_del deprecated by CMI.',
              '#link' => _backdropnode(28616),
            );
            _coder_review_error($results, $tmprule, $severity_name, $lineno, $line, $coder_args['#ignores']);
          }
        }
      }
    }
  }
}

/**
 * @todo: add a function header comment.
 */
function _coder_review_d7_to_backdrop_htmltpl_callback(&$coder_args, $review, $rule, $lines, &$results) {
  // Todo: figure out how to detect page.tpl.php.
}

/**
 * @todo: add a function header comment.
 */
function _coder_review_d7_to_backdrop_removed_module_callback(&$coder_args, $review, $rule, $lines, &$results) {
  $removed_module = array(
    'aggregator',
    'dashboard',
    'forum',
    'openid',
    'overlay',
    'poll',
    'rdf',
    'shortcut',
    'statistics',
    'tracker',
    'trigger',
    'toolbar',
    'xmlrpc',
  );

  $filename = $coder_args['#filename'];
  if (file_exists($filename)) {
    $lines = file($filename);
    if ($lines) {
      foreach ($lines as $lineno => $line) {
        foreach ($removed_module as $module) {
          if (preg_match('/_?' . $module . '_?/', $line)) {
            $severity_name = _coder_review_severity_name($coder_args, $review, $rule);
            $tmprule = $rule;
            $tmprule['#warning'] = array(
              '#text' => 'The !module module has been removed from core. Check that this line does not reference a non-existent module.',
              '#args' => array(
                '!module' => $module,
              ),
              '#link' => _backdropnode(28538),
            );
            _coder_review_error($results, $tmprule, $severity_name, $lineno, $line, $coder_args['#ignores']);
          }
        }
      }
    }
  }
}
