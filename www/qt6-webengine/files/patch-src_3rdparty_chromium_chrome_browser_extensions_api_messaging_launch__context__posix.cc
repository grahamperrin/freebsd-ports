--- src/3rdparty/chromium/chrome/browser/extensions/api/messaging/launch_context_posix.cc.orig	2024-08-26 12:06:38 UTC
+++ src/3rdparty/chromium/chrome/browser/extensions/api/messaging/launch_context_posix.cc
@@ -86,7 +86,7 @@ std::optional<LaunchContext::ProcessState> LaunchConte
 
 // TODO(crbug.com/40118868): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   // Don't use no_new_privs mode, e.g. in case the host needs to use sudo.
   options.allow_new_privs = true;
 #endif
