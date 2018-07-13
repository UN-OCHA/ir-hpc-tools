/**
 * @file
 * Custom scripts for theme.
 */
(function ($) {

  $(document).ready(function () {

    // Facets.
    $("#sidebar-first .block.block-facetapi h4").live("click", function () {
      $(this).toggleClass('opened')
      $(this).parent().find('.block__content').slideToggle('fast');
    });

	if ($("#sidebar-first .block.block-current-search .content .current-search-item-reset").length > 0) {
      $("#sidebar-first .block.block-current-search .block__content .current-search-item-reset").appendTo('#sidebar-first .block.block-current-search .block__content');
    }

    $("#sidebar-first .block.block-facetapi .facetapi-active").each(function () {
      $(this).closest('.content').show().prev("h4").addClass("opened");
      $(this).parent().addClass('redactive');
    });

    // Table responsive.
    $(".table-responsive").each(function () {
      var head = $("th", this);
      var i = 0;
      $("td").each(function () {
        if (i >= head.length) {
          i = 0;
        }
        if ($.trim($(this).html()) != "") {
          $(this).attr('data-title', $(head[i]).text());
        }
        i++;
      });
    });

  });

})(jQuery);
