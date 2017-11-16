
Debian
====================
This directory contains files used to package tabitd/tabit-qt
for Debian-based Linux systems. If you compile tabitd/tabit-qt yourself, there are some useful files here.

## tabit: URI support ##


tabit-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install tabit-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your tabit-qt binary to `/usr/bin`
and the `../../share/pixmaps/tabit128.png` to `/usr/share/pixmaps`

tabit-qt.protocol (KDE)

