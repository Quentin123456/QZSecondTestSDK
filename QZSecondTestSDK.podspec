#
# Be sure to run `pod lib lint QZSecondTestSDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'QZSecondTestSDK'
  s.version          = '0.2.0'
  s.summary          = '更新一版.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = '只是测试上传pod库'

  s.homepage         = 'https://github.com/Quentin123456/QZSecondTestSDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'QuentinZang' => 'quentinzang@outlook.com' }
  s.source           = { :git => 'https://github.com/Quentin123456/QZSecondTestSDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '12.0'
  s.requires_arc = true
  s.library   = "c++.1"
  s.vendored_frameworks ='framework/TencentOpenAPI.framework','framework/BrickSDK.xcframework'
  s.resource = 'framework/*.{bundle}'

  #s.source_files = 'QZSecondTestSDK/Classes/**/*'
  
  # s.resource_bundles = {
  #   'QZSecondTestSDK' => ['QZSecondTestSDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
  s.dependency 'WechatOpenSDK', '~> 2.0.4'
  s.dependency 'AlipaySDK-iOS', '~> 15.8.16'
end
