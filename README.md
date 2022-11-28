# Prl Type

This is command line tool for using with [Parallels Desktop](http://www.parallels.com/products/desktop/). 

### Requirements

* [Parallels Virtualization SDK for Mac](https://www.parallels.com/download/pvsdk/), download and install it.

### Building from Source

```
make
```
All binaries are built into ```bin/``` folder

## Usage

#### prltype

A command to send text a keyboard events to a Virtual Machine.
```prltype <vm_name> <text or commands>```

Example:
```prltype Ubuntu 'Hello World' '<enter>'``` will type ```Hello World``` and press Enter to the virtual machine named Ubuntu.

List of acceptable commands:
Keyboard keys: ```<ALT>, <BACKSPACE>, <BS>, <CAPSLOCK>, <CTL>, <DEL>, <DELETE>, <DOWN>, <END>, <ENTER>, <ESC>, <F1>, <F10>, <F11>, <F12>, <F2>, <F3>, <F4>, <F5>, <F6>, <F7>, <F8>, <F9>, <HOME>, <INSERT>, <LALT>, <LCTRL>, <LEFT>, <LSHIFT>, <LWIN>, <NUMLOCK>, <PAUSE>, <PGDN>, <PGUP>, <POWER>, <PRTSCR>, <RALT>, <RCTRL>, <RIGHT>, <RSHIFT>, <RWIN>, <SCROLLLOCK>, <SHIFT>, <SLEEP>, <SPACE>, <TAB>, <UP>, <WAKE>, <WIN>, <LALT>, <LCTRL>, <LSHIFT>, <LWIN>```
Special command: ```<WAIT>``` - delay of 1 second

## License

This code is distributed under the GPL v3 license, see LICENSE.

© 2022 July Ighor

---

Parallels Desktop is a registered trademark of Parallels Software International, Inc.
