[![Build status](https://ci.appveyor.com/api/projects/status/u7idbsek3njnh648/branch/master?svg=true&passingText=master%20-%20OK&failingText=master%20-%20Fails)](https://ci.appveyor.com/project/enriquesomolinos/dreerally/branch/master)
[![Build status](https://ci.appveyor.com/api/projects/status/u7idbsek3njnh648/branch/0.2.x?svg=true&passingText=0.2.x%20-%20OK&failingText=0.2.x%20-%20Fails)](https://ci.appveyor.com/project/enriquesomolinos/dreerally/branch/0.2.x)

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md#pull-requests)
[![Build status](https://img.shields.io/github/downloads/enriquesomolinos/dreerally/total.svg)](https://github.com/enriquesomolinos/dreerally/releases)
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/enriquesomolinos/dreerally.svg)
![GitHub contributors](https://img.shields.io/github/contributors/enriquesomolinos/dreerally.svg)
![GitHub release](https://img.shields.io/github/release-pre/enriquesomolinos/dreerally.svg)
![Dev phase](https://img.shields.io/badge/devphase-sentinel-brightgreen.svg)


# Dreerally
Death Rally engine reimplementation. To run this game you need the original Death Rally files!.

See details and status in www.dreerally.com and in our wiki https://github.com/enriquesomolinos/DreeRally/wiki

**Note**, Dreerally requires an original copy of Death Rally for Windows. None of the Death Rally game assets are provided by this project. To get a legitimate copy of the game assets, please refer to the [Windows release of Death Rally](https://www.moddb.com/groups/free-software-initiative/downloads/death-rally-windows-full-version).


# Purpose
The main objetive is to recreate the windows version of Death Rally. Then we will implement multiplayer, mods, port to Linux....

Follow us on [Dreerally](http://www.dreerally.com)


# Media
[![DreeRally](https://i9.ytimg.com/vi/QhzlMt0ZB5Q/mq2.jpg?sqp=CPDMt-kF&rs=AOn4CLBQu1NINV_5aWVEq2LPoegvlnrsKw)](https://www.youtube.com/watch?v=QhzlMt0ZB5Q "DreeRally")
![alt tag](http://www.dreerally.com/wp-content/uploads/2016/12/Captura.jpg)
![alt tag](http://www.dreerally.com/wp-content/uploads/2016/12/Captura2.jpg)
![alt tag](http://www.dreerally.com/wp-content/uploads/2016/12/Captura3.jpg)
![alt tag](http://www.dreerally.com/wp-content/uploads/2016/12/Captura4.jpg)

# Building with Visual Studio 2010-2017
- Open the project solution `DreeRally.sln`, choose `Debug` or `Release`, and then `Build Solution`.

# Installing
Once compiled, the DreeRally binary will serve as a replacement for `DeathRally.exe`. The following files from the original game need to be present: `ENDANI.haf`, `ENGINE.BPA`, `fmod.dll`, `IBFILES.BPA`,  `MENU.BPA`, `msvcr71.dll`, `MUSICS.BPA`, `SANIM.haf`, `SDL.dll`, and `TRX.BPA`.

# Multiplayer
At this moment multiplayer is not implemented.

# Contributing
[Guidelines](docs/CONTRIBUTING.md)

# Modding
At this moment you can only put your custom files in the root directory of the game. For example if you put MENU.PAL in the root directory, the game will use your custom file and not the original file!.


# Credits
- Reverse engineered by esomolinos in 2016

And a special thanks to all the support and people who work on this project to make it possible! <3

# Changelog
[From the beginning until release](docs/CHANGELOG.md)

# Tools
    
- tools/Bpadecryptor.py: allows to extract the contents of BPA files
- tools/Music.py: once music.bpk file is extracted, with this script you can decrypt the music files and play with VLC.
- tools/SavegameDecrypt.py: takes a savegame and decrypts its contents. A tthis moment it's very easy to modify your savegame :)
- tools/SavegameCrypt.py: takes a decrypted savegame and returns it to the original format. The original death rally must open this file :)
- tools/Bpkdecryptor.py: takes a BPK file and his Pal file to generate a gif file.


# Legal
DreeRally is released to the Public Domain. The documentation and function provided by DreeRally may only be utilized with assets provided by ownership of Death Rally.

DreeRally and any of its' maintainers are in no way associated with or endorsed by Remedy Entertainment(R).

