# qlBitRate

__qlBitRate__ is a QuickLook plugin that will display the bit rate (in kbps) and filename of an MP3 file in the title bar of the QuickLook window.  This plugin has been tested to work in at least OS X 10.7 (Lion), 10.8 (Mountain Lion), and 10.9 (Mavericks).


![qlBitRate Screenshot](https://raw.github.com/jordansaints/qlBitRate/master/demo.png "qlBitRate in action!")


## Installation

#### Pre-compiled

1. [Download the latest release of qlBitRate here](https://github.com/jordansaints/qlBitRate/releases/)
2. Unzip file
3. Move file into `/Library/QuickLook/` (to install for all users) or into `~/Library/QuickLook/` (to install for this user only)

#### Manually-compiled _(requires Xcode)_

1. Clone or fork the latest source code of qlBitRate
2. Using Xcode, build the `qlBitRate.qlgenerator` file
3. Move file into `/Library/QuickLook/` (to install for all users) or into `~/Library/QuickLook/` (to install for this user only)

#### Resetting QuickLook

After copying the file to the correct location, you may run the command `qlmanage -r` in the Terminal to reset QuickLook and force reload all of your plugins.


## Credits

__qlBitRate__ was authored by __Jordan Saints__, and is released under the GPLv2 license.

Website: [www.jordansaints.com](http://www.jordansaints.com)
