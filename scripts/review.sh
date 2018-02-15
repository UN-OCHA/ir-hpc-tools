test ! -d ./html/sites/all/modules/custom || find -L ./html/sites/all/modules/custom -name '*' -print0 | xargs -0 -n 1 -P 4 php -l
test ! -d ./html/sites/all/modules/features || find -L ./html/sites/all/modules/features -name '*' -print0 | xargs -0 -n 1 -P 4 php -l
test ! -d ./html/sites/all/themes/custom || find -L ./html/sites/all/themes/custom -name '*' -print0 | xargs -0 -n 1 -P 4 php -l

./bin/phpcs --config-set installed_paths vendor/drupal/coder/coder_sniffer
test ! -d ./html/sites/all/modules/custom || ./bin/phpcs -p --report=full ./html/sites/all/modules/custom
test ! -d ./html/sites/all/modules/features || ./bin/phpcs -p --report=full ./html/sites/all/modules/features
test ! -d ./html/sites/all/themes/custom || ./bin/phpcs -p --report=full ./html/sites/all/themes/custom

test ! -d ./html/sites/all/modules/custom || ./bin/phpmd ./html/sites/all/modules/custom text .phpmd.xml --suffixes=php,inc,module,install
test ! -d ./html/sites/all/modules/features || ./bin/phpmd ./html/sites/all/modules/features text .phpmd.xml --suffixes=php,inc,module,install
test ! -d ./html/sites/all/themes/custom || ./bin/phpmd ./html/sites/all/themes/custom text .phpmd.xml --suffixes=php,inc,module,install

# test ! -d ./html/sites/all/modules/custom || ./bin/phpcpd ./html/sites/all/modules/custom/*/*
# test ! -d ./html/sites/all/modules/features || ./bin/phpmd ./html/sites/all/modules/features/*/*
# test ! -d ./html/sites/all/themes/custom || ./bin/phpmd ./html/sites/all/themes/custom/*/*
