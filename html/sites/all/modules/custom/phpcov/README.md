# PHP coverage

## Todo

- add config to run on certain paths like cron

## Install

- `composer install`
- `drush en phpcov -y`

## Run

```
curl "http://irhpc.docksal/en/api-documentation?cover=1"
curl "http://irhpc.docksal/en/applications/ir?cover=1"
curl "http://irhpc.docksal/en/applications/ir/indicators?cover=1"
curl "http://irhpc.docksal/en?cover=1"
curl "http://irhpc.docksal/en/applications/ir/indicators/global-clusters/2?cover=1"
curl "http://irhpc.docksal/en/applications/ir/indicator/p-2?cover=1"
curl "http://irhpc.docksal/connect/oauthconnector_hid_oauth?destination=node/2279&cover=1"
curl "http://irhpc.docksal/api/v1.0/indicators?cover=1"
curl "http://irhpc.docksal/api/v1.0/indicator_standards?cover=1"
curl "http://irhpc.docksal/api/v1.0/indicator_domains?cover=1"
curl "http://irhpc.docksal/api/v1.0/indicator_types?cover=1"
curl "http://irhpc.docksal/api/v1.0/indicator_units?cover=1"
```

## Generate report

- `mv /tmp/test* results`
- `vendor/bin/phpcov merge ./results --html=report`
- `google-chrome report/index.html`
