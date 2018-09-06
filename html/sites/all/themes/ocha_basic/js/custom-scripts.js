/**
 * @file
 * Custom scripts for theme.
 */

(function ($, Drupal) {
  Drupal.behaviors.customScripts = {
    attach: function (context, settings) {

      /* Expand / collapse filters on small screens */
      function mobileFilters() {
        $("#sidebar-first .block-facetapi").wrapAll("<div class='facets-container mobile-hidden'></div>");
        $('.block-current-search').append('<button id="showMobileFilters" type="button" class="show-facets-btn">Show filters</button>');
        $('#showMobileFilters').click(function () {
          $('.facets-container').toggleClass('mobile-hidden');
          $(this).toggleClass('active');
        });
      }

      /* Add buttons to filter headings so are focusable */
      function formatFilters() {
        $("#sidebar-first .block.block-facetapi h2").each(function () {
          var label = $(this).text();
          $(this).html('<button type="button">' + label + '</button>');
        });
      }

      $(document).ready(function () {

        //trigger resize
        $(window).resize();

        mobileFilters();
        formatFilters();

        //facets
        $("#sidebar-first .block.block-facetapi").on("click", "h4", function () {
          $(this).toggleClass('opened').next('.block__content').slideToggle('fast');
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

    }
  };
}(jQuery, Drupal));
