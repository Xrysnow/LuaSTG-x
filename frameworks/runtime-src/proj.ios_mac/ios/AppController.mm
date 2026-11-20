/****************************************************************************
 Copyright (c) 2010-2013 cocos2d-x.org
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#import "AppController.h"
#import "cocos2d.h"
#import "AppFrame.h"
#import "RootViewController.h"
#import "platform/ios/DirectorCaller-ios.h"

@interface AppController ()
- (BOOL)attachWindow:(UIWindow*)gameWindow;
- (void)enterBackground;
- (void)enterForeground;
@end

API_AVAILABLE(ios(13.0))
@interface LSTGWindowSceneDelegate : UIResponder <UIWindowSceneDelegate>
@property(nonatomic, retain) UIWindow* window;
@end

@implementation AppController {
    BOOL _running;
    BOOL _inBackground;
}
@synthesize window = _window;

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)options {
    if (@available(iOS 13.0, *)) {
        [[NSUserDefaults standardUserDefaults] setBool:NO forKey:@"NSAllowsDefaultLineBreakStrategy"];
        return YES; // UIKit supplies the game window in scene:willConnectToSession:options:.
    }
    UIWindow* legacyWindow = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    BOOL started = [self attachWindow:legacyWindow];
#if !__has_feature(objc_arc)
    [legacyWindow release];
#endif
    return started;
}

- (BOOL)attachWindow:(UIWindow*)gameWindow {
    if (!_viewController) {
        lstg::AppFrame::getInstance()->initGLContextAttrs();
        cc::GLViewImpl::convertAttrs();
        _viewController = [[RootViewController alloc] init];
    }

    self.window = gameWindow;
    gameWindow.rootViewController = _viewController;
    [gameWindow makeKeyAndVisible];
    if (_running) {
        return YES; // Reconnect the existing engine view after a scene disconnect.
    }

    auto view = cc::GLViewImpl::createWithEAGLView((__bridge void*)_viewController.view);
    if (view) {
        cc::Director::getInstance()->setOpenGLView(view);
        // iOS starts its display link and returns before the first frame.
        if (lstg::AppFrame::getInstance()->run() == 0) {
            _running = YES;
            return YES;
        }
        CCLOGERROR("iOS launch failed: engine initialization failed");
    } else {
        CCLOGERROR("iOS launch failed: unable to create the gfx Metal surface");
    }
    gameWindow.hidden = YES;
    gameWindow.rootViewController = nil;
    self.window = nil;
    return NO;
}

- (void)enterBackground {
    if (_running && !_inBackground) {
        _inBackground = YES;
        cc::Application::getInstance()->applicationDidEnterBackground();
    }
}

- (void)enterForeground {
    if (_running && _inBackground) {
        _inBackground = NO;
        cc::Application::getInstance()->applicationWillEnterForeground();
    }
}

// UIKit calls these on a pre-scene host.
- (void)applicationDidEnterBackground:(UIApplication*)application {
    [self enterBackground];
}

- (void)applicationWillEnterForeground:(UIApplication*)application {
    [self enterForeground];
}

- (void)applicationWillTerminate:(UIApplication*)application {
    _running = NO;
    [CCDirectorCaller destroy];
    lstg::AppFrame::destroyInstance();
}

#if !__has_feature(objc_arc)
- (void)dealloc {
    [_window release];
    [_viewController release];
    [super dealloc];
}
#endif

@end

@implementation LSTGWindowSceneDelegate

- (void)scene:(UIScene*)scene willConnectToSession:(UISceneSession*)session options:(UISceneConnectionOptions*)options {
    if (![scene isKindOfClass:UIWindowScene.class]) {
        return;
    }
    _window = [[UIWindow alloc] initWithWindowScene:(UIWindowScene*)scene];
    AppController* app = (AppController*)UIApplication.sharedApplication.delegate;
    if (![app attachWindow:_window]) {
        self.window = nil;
    }
}

- (void)sceneDidEnterBackground:(UIScene*)scene {
    AppController* app = (AppController*)UIApplication.sharedApplication.delegate;
    if (self.window == app.window) {
        [app enterBackground];
    }
}

- (void)sceneWillEnterForeground:(UIScene*)scene {
    AppController* app = (AppController*)UIApplication.sharedApplication.delegate;
    if (self.window == app.window) {
        [app enterForeground];
    }
}

- (void)sceneDidDisconnect:(UIScene*)scene {
    AppController* app = (AppController*)UIApplication.sharedApplication.delegate;
    if (self.window == app.window) {
        [app enterBackground];
        app.window = nil;
    }
    self.window.rootViewController = nil;
    self.window = nil;
}

#if !__has_feature(objc_arc)
- (void)dealloc {
    [_window release];
    [super dealloc];
}
#endif

@end
