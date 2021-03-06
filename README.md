# Polestar IndoorLocation Provider for iOS

This modules allows you to use the Indoor Location provided by [Pole Star](https://www.polestar.eu/) and connect it to [Mapwize](https://www.mapwize.io/) in one line of code.

Using this provider requires you to be both a Mapwize and a Pole Star customer. You can sign up for a free Mapwize account at [www.mapwize.io](https://www.mapwize.io/). To purchase the Pole Star solution, please visit [www.polestar.eu/](https://www.polestar.eu/).

## Use

Instanciate the provider using your credentials:

```c
provider = [[ILPolestarIndoorLocationProvider alloc] initWithPolestarKey:@"POLESTAR API KEY"];
```

Set the provider in your Mapwize SDK:

```c
[self.mapwizePlugin setIndoorLocationProvider:provider];
```

The Pole Star locationHandle is available as property of the provider so developers can access it directly.

## Manage altitude

The locations provided by Polestar manages altitude in meters while in IndoorLocation, the elevation is in floors. The default conversion is to divide the altitude by 5 to get the floor. If you need more granularity in the conversion, you can use `floorByAltitude` to specify your mapping. The map takes altitudes (NSNumber) as keys and floors (NSNumber) as values.

## Demo app

A simple demo application to test the provider is available in this project.

You will need to set your Mapwize credentials in the `info.plist` file and your Pole Star key in `ViewController.m`.

Please make sure to call `pod install` before running the app.

## Contribute

Contributions are welcome. We will be happy to review your PR.

## Support

For any support with this provider, please do not hesitate to contact [support@polestar.eu](mailto:support@polestar.eu) and [support@mapwize.io](mailto:support@mapwize.io)

## License

This IndoorLocation Provider is made available under the MIT.

Mapwize and Pole Star SDKs used in this project are proprietary of their respective suppliers and are not open-source.