# this script is run automaticly in firts `sudo make clean install`
git submodule add -f https://gitlab.freedesktop.org/wlroots/wlroots.git wlroots
git submodule init
cd wlroots
meson setup build && ninja -C build
