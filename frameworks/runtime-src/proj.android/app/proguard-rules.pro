# Add project specific ProGuard rules here.
# By default, the flags in this file are appended to flags specified
# in E:\developSoftware\Android\SDK/tools/proguard/proguard-android.txt
# You can edit the include path and order by changing the proguardFiles
# directive in build.gradle.
#
# For more details, see
#   http://developer.android.com/guide/developing/tools/proguard.html

# Add any project specific keep options here:

# If your project uses WebView with JS, uncomment the following
# and specify the fully qualified class name to the JavaScript interface
# class:
#-keepclassmembers class fqcn.of.javascript.interface.for.webview {
#   public *;
#}

-dontobfuscate

# Proguard cocos for release

-keep public class org.cocos.** { *; }
-dontwarn org.cocos.**
-keep public class com.chukong.** { *; }
-dontwarn com.chukong.**
-keep public class com.huawei.android.** { *; }
-dontwarn com.huawei.android.**
-keep public class com.cocos.** { *; }
-dontwarn com.cocos.**

# Proguard Apache HTTP for release

-keep class org.apache.http.** { *; }
-dontwarn org.apache.http.**

# Proguard Android Webivew for release

-keep public class android.net.http.SslError
-dontwarn android.net.http.SslError
-keep public class android.webkit.WebViewClient
-dontwarn android.webkit.WebViewClient
-dontwarn android.webkit.WebView

-keep public class com.google.** { *; }
