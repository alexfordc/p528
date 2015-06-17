import os
import subprocess

if __name__ == "__main__":
	os.environ["GYP_GENERATORS"] = "msvs-ninja,ninja"	
	os.environ["GYP_MSVS_VERSION"] = "2013"
	os.environ["DEPOT_TOOLS_WIN_TOOLCHAIN"] = "0"	
	#os.environ["GYP_DEFINES"] = "branding=Chromium buildtype=Dev component=shared_library"
	os.environ["GYP_DEFINES"] = "branding=Chromium buildtype=Official component=static_library"
	
	#subprocess.call('python src/build/win/setup_cygwin_mount.py --win-only',shell=True)
	#subprocess.call('python src/build/util/lastchange.py -o src/build/util/LASTCHANGE',shell=True)
	#subprocess.call('python src/build/util/lastchange.py -s src/third_party/WebKit -o src/build/util/LASTCHANGE.blink',shell=True)
	subprocess.call('python src/build/gyp_chromium src/chrome/chrome.gyp',shell=True)
	#subprocess.call('python src/build/landmines.py',shell=True)
