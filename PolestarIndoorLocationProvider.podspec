Pod::Spec.new do |s|
  s.name         = "PolestarIndoorLocationProvider"
  s.version      = "1.0.1"
  s.license      = { :type => 'MIT' }
  s.summary      = "Allows to use polestar to provide indoorlocation"
  s.homepage     = "https://github.com/IndoorLocation/polestar-indoor-location-provider-ios"
  s.author       = { "Indoor Location" => "indoorlocation@mapwize.io" }
  s.platform     = :ios
  s.ios.deployment_target = '8.0'
  s.source       = { :git => "https://github.com/IndoorLocation/polestar-indoor-location-provider-ios", :tag => "#{s.version}" }
  s.source_files  = "polestar-indoor-location-provider-ios/IndoorLocationProvider/*.{h,m}"
  s.dependency "IndoorLocation", "~> 1.0"
  s.dependency "NAOSDK", "~> 4.0"
end
