<div class="<?php print $classes ?>">
  <div class="topbar">
    <div class="name"></div>
    <div class="close back">&larr;</div>
  </div>

  <section class="main">
    <div class="wrapper">
      <ul class="tp-grid">
        <?php foreach ($rows as $key => $row): ?>
          <?php print $row ?>
        <?php endforeach ?>
      </ul>
    </div>
  </section>
</div>
