make

PREFIX=/usr/local
MANDIR=$PREFIX/share/man
DATADIR=$PREFIX/share

sudo mkdir -p $PREFIX/bin
sudo rm -f $PREFIX/bin/dwl
sudo cp -f dwl $PREFIX/bin
sudo chmod 755 $PREFIX/bin/dwl
sudo mkdir -p $MANDIR/man1
sudo cp -f dwl.1 $MANDIR/man1
sudo chmod 644 $MANDIR/man1/dwl.1
sudo mkdir -p $DATADIR/wayland-sessions
sudo cp -f dwl.desktop $DATADIR/wayland-sessions/dwl.desktop
sudo chmod 644 $DATADIR/wayland-sessions/dwl.desktop
