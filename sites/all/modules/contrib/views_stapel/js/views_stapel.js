(function ($) {

  Drupal.behaviors.ViewsStapel = {
    attach: function(context, settings) {
      var $grid = $('.tp-grid', context),
        $name = $('.name', context),
        $close = $('.close', context),
        $loader = $('<div class="loader"><i></i><i></i><i></i><i></i><i></i><i></i><span>Loading...</span></div>').insertBefore( $grid ),

        stapel = $grid.stapel({
          randomAngle : settings.ViewsStapel.randomAngle, // TRUE
          delay : settings.ViewsStapel.delay, //50
          gutter : settings.ViewsStapel.gutter, // 70
          pileAngles : settings.ViewsStapel.pileAngles, // 5
          onLoad : function() {
            $loader.remove();
          },
          onBeforeOpen : function( pileName ) {
            $name.html( pileName );
          },
          onAfterOpen : function( pileName ) {
            $close.show();
          }
        });

      $close.on('click', function() {
        $close.hide();
        $name.empty();
        stapel.closePile();
      });
    }
  };

})(jQuery);
