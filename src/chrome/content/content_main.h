// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_PUBLIC_APP_CONTENT_MAIN_H_
#define CONTENT_PUBLIC_APP_CONTENT_MAIN_H_

#include <stddef.h>

#include "base/callback_forward.h"
#include "build/build_config.h"
#include "chrome/content/content_export.h"

#if defined(OS_WIN)
#include <windows.h>
#endif

//namespace sandbox {
//struct SandboxInterfaceInfo;
//}

namespace content {
class ContentMainDelegate;

struct ContentMainParams {
  explicit ContentMainParams(ContentMainDelegate* delegate)
      : delegate(delegate),
        instance(NULL),
        ui_task(NULL) {
  }

  ContentMainDelegate* delegate;
  HINSTANCE instance;

  // Used by browser_tests. If non-null BrowserMain schedules this task to run
  // on the MessageLoop. It's owned by the test code.
  base::Closure* ui_task;
};

// ContentMain should be called from the embedder's main() function to do the
// initial setup for every process. The embedder has a chance to customize
// startup using the ContentMainDelegate interface. The embedder can also pass
// in NULL for |delegate| if they don't want to override default startup.
CONTENT_EXPORT int ContentMain(const ContentMainParams& params);

}  // namespace content

#endif  // CONTENT_PUBLIC_APP_CONTENT_MAIN_H_
