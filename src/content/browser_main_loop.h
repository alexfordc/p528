// Copyright by wangtianping. All rights reserved.

#ifndef CONTENT_BROWSER_BROWSER_MAIN_LOOP_H_
#define CONTENT_BROWSER_BROWSER_MAIN_LOOP_H_

#include "base/basictypes.h"
#include "base/files/file_path.h"
#include "base/memory/ref_counted.h"
#include "base/memory/scoped_ptr.h"
#include "base/timer/timer.h"
#include "content/browser_process_sub_thread.h"
#include "content/browser_main_runner.h"

namespace base {
class CommandLine;
class FilePath;
class HighResolutionTimerManager;
class MessageLoop;
class PowerMonitor;
}  // namespace base

namespace content {
class BrowserMainParts;
class BrowserShutdownImpl;
class BrowserThreadImpl;
class StartupTaskRunner;
struct MainFunctionParams;

// Implements the main browser loop stages called from BrowserMainRunner.
// See comments in browser_main_parts.h for additional info.
class CONTENT_EXPORT BrowserMainLoop {
 public:
  // Returns the current instance. This is used to get access to the getters
  // that return objects which are owned by this class.
  static BrowserMainLoop* GetInstance();

  explicit BrowserMainLoop(const MainFunctionParams& parameters);
  virtual ~BrowserMainLoop();

  void Init();

  void EarlyInitialization();
  // Initializes the toolkit. Returns whether the toolkit initialization was
  // successful or not.
  bool InitializeToolkit();
  void MainMessageLoopStart();

  // Create and start running the tasks we need to complete startup. Note that
  // this can be called more than once (currently only on Android) if we get a
  // request for synchronous startup while the tasks created by asynchronous
  // startup are still running.
  void CreateStartupTasks();

  // Perform the default message loop run logic.
  void RunMainMessageLoopParts();

  // Performs the shutdown sequence, starting with PostMainMessageLoopRun
  // through stopping threads to PostDestroyThreads.
  void ShutdownThreadsAndCleanUp();

  int GetResultCode() const { return result_code_; }

 private:
  // For ShutdownThreadsAndCleanUp.
  friend class BrowserShutdownImpl;

  void InitializeMainThread();

  // Called just before creating the threads
  int PreCreateThreads();

  // Create all secondary threads.
  int CreateThreads();

  // Called right after the browser threads have been started.
  int BrowserThreadsStarted();

  int PreMainMessageLoopRun();

  void MainMessageLoopRun();

  // Members initialized on construction ---------------------------------------
  const MainFunctionParams& parameters_;
  const base::CommandLine& parsed_command_line_;
  int result_code_;
  // True if the non-UI threads were created.
  bool created_threads_;

  // Members initialized in |MainMessageLoopStart()| ---------------------------
  scoped_ptr<base::MessageLoop> main_message_loop_;
  scoped_ptr<base::PowerMonitor> power_monitor_;
  scoped_ptr<base::HighResolutionTimerManager> hi_res_timer_manager_;

  // The startup task runner is created by CreateStartupTasks()
  scoped_ptr<StartupTaskRunner> startup_task_runner_;

  // Destroy parts_ before main_message_loop_ (required) and before other
  // classes constructed in content (but after main_thread_).
  scoped_ptr<BrowserMainParts> parts_;

  // Members initialized in |InitializeMainThread()| ---------------------------
  // This must get destroyed before other threads that are created in parts_.
  scoped_ptr<BrowserThreadImpl> main_thread_;

  // Members initialized in |RunMainMessageLoopParts()| ------------------------
  scoped_ptr<BrowserProcessSubThread> db_thread_;
  scoped_ptr<BrowserProcessSubThread> file_user_blocking_thread_;
  scoped_ptr<BrowserProcessSubThread> file_thread_;
  scoped_ptr<BrowserProcessSubThread> process_launcher_thread_;
  scoped_ptr<BrowserProcessSubThread> cache_thread_;
  scoped_ptr<BrowserProcessSubThread> io_thread_;

  DISALLOW_COPY_AND_ASSIGN(BrowserMainLoop);
};

}  // namespace content

#endif  // CONTENT_BROWSER_BROWSER_MAIN_LOOP_H_
