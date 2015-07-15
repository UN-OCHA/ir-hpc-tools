<?php
/**
 * This file is automatically @generated by {@link BuildMetadataPHPFromXml}.
 * Please don't modify it directly.
 */


return array (
  'generalDesc' => 
  array (
    'NationalNumberPattern' => '[68]\\d{7,8}',
    'PossibleNumberPattern' => '\\d{8,9}',
  ),
  'fixedLine' => 
  array (
    'NationalNumberPattern' => '
          6(?:
            1(?:
              17|
              2(?:
                [0189]\\d|
                [2-6]|
                7\\d?
              )|
              3(?:
                [01378]|
                2\\d
              )|
              4[01]|
              69|
              7[014]
            )|
            2(?:
              17|
              5(?:
                [0-36-8]|
                4\\d?
              )|
              69|
              70
            )|
            3(?:
              17|
              2(?:
                [0237]\\d?|
                [14-689]
              )|
              34|
              6[29]|
              7[01]|
              81
            )|
            4(?:
              17|
              2(?:
                [012]|
                7?
              )|
              4(?:
                [06]|
                1\\d
              )|
              5(?:
                [01357]|
                [25]\\d?
              )|
              69|
              7[01]
            )|
            5(?:
              17|
              2(?:
                [0459]|
                [23678]\\d?
              )|
              69|
              7[01]
            )|
            6(?:
              17|
              2(?:
                5|
                6\\d?
              )|
              38|
              42|
              69|
              7[01]
            )|
            7(?:
              17|
              2(?:
                [569]|
                [234]\\d?
              )|
              3(?:
                0\\d?|
                [13]
              )|
              69|
              7[01]
            )
          )\\d{4}
        ',
    'PossibleNumberPattern' => '\\d{8,9}',
    'ExampleNumber' => '61221234',
  ),
  'mobile' => 
  array (
    'NationalNumberPattern' => '
          (?:
            60|
            8[125]
          )\\d{7}
        ',
    'PossibleNumberPattern' => '\\d{9}',
    'ExampleNumber' => '811234567',
  ),
  'tollFree' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'premiumRate' => 
  array (
    'NationalNumberPattern' => '8701\\d{5}',
    'PossibleNumberPattern' => '\\d{9}',
    'ExampleNumber' => '870123456',
  ),
  'sharedCost' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'personalNumber' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'voip' => 
  array (
    'NationalNumberPattern' => '
          8(?:
            3\\d{2}|
            86
          )\\d{5}
        ',
    'PossibleNumberPattern' => '\\d{8,9}',
    'ExampleNumber' => '88612345',
  ),
  'pager' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'uan' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'emergency' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'voicemail' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'shortCode' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'standardRate' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'carrierSpecific' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'noInternationalDialling' => 
  array (
    'NationalNumberPattern' => 'NA',
    'PossibleNumberPattern' => 'NA',
  ),
  'id' => 'NA',
  'countryCode' => 264,
  'internationalPrefix' => '00',
  'nationalPrefix' => '0',
  'nationalPrefixForParsing' => '0',
  'sameMobileAndFixedLinePattern' => false,
  'numberFormat' => 
  array (
    0 => 
    array (
      'pattern' => '(8\\d)(\\d{3})(\\d{4})',
      'format' => '$1 $2 $3',
      'leadingDigitsPatterns' => 
      array (
        0 => '8[1235]',
      ),
      'nationalPrefixFormattingRule' => '0$1',
      'domesticCarrierCodeFormattingRule' => '',
    ),
    1 => 
    array (
      'pattern' => '(6\\d)(\\d{2,3})(\\d{4})',
      'format' => '$1 $2 $3',
      'leadingDigitsPatterns' => 
      array (
        0 => '6',
      ),
      'nationalPrefixFormattingRule' => '0$1',
      'domesticCarrierCodeFormattingRule' => '',
    ),
    2 => 
    array (
      'pattern' => '(88)(\\d{3})(\\d{3})',
      'format' => '$1 $2 $3',
      'leadingDigitsPatterns' => 
      array (
        0 => '88',
      ),
      'nationalPrefixFormattingRule' => '0$1',
      'domesticCarrierCodeFormattingRule' => '',
    ),
    3 => 
    array (
      'pattern' => '(870)(\\d{3})(\\d{3})',
      'format' => '$1 $2 $3',
      'leadingDigitsPatterns' => 
      array (
        0 => '870',
      ),
      'nationalPrefixFormattingRule' => '0$1',
      'domesticCarrierCodeFormattingRule' => '',
    ),
  ),
  'intlNumberFormat' => 
  array (
  ),
  'mainCountryForCode' => false,
  'leadingZeroPossible' => false,
  'mobileNumberPortableRegion' => false,
);
