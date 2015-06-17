// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Wrapper to the parameter list for the "main" entry points (browser, renderer,
// plugin) to shield the call sites from the differences between platforms
// (e.g., POSIX doesn't need to pass any sandbox information).

#ifndef CONTENT_PUBLIC_COMMON_MAIN_FUNCTION_PARAMS_H_
#define CONTENT_PUBLIC_COMMON_MAIN_FUNCTION_PARAMS_H_

#include "base/callback_forward.h"
#include "base/command_line.h"

namespace content {

struct MainFunctionParams {
  explicit MainFunctionParams(const base::CommandLine& cl)
      : command_line(cl),
        ui_task(NULL) {
  }

  const base::CommandLine& command_line;

  // Used by InProcessBrowserTest. If non-null BrowserMain schedules this
  // task to run on the MessageLoop and BrowserInit is not invoked.
  base::Closure* ui_task;
};

}  // namespace content

#endif  // CONTENT_PUBLIC_COMMON_MAIN_FUNCTION_PARAMS_H_
