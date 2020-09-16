[![Gitter](https://img.shields.io/gitter/room/DAVFoundation/DAV-Contributors.svg)](https://gitter.im/DreeRally-deathrally/community#)
[![GitHub Actions build status (0.3.x)](https://github.com/enriquesomolinos/DreeRally/workflows/CI/badge.svg?branch=0.3.x)](https://github.com/enriquesomolinos/DreeRally/actions?query=branch:0.3.x)
[![AppVeyor build status (master)](https://ci.appveyor.com/api/projects/status/u7idbsek3njnh648/branch/master?svg=true&passingText=master%20-%20OK&failingText=master%20-%20Fails)](https://ci.appveyor.com/project/enriquesomolinos/dreerally/branch/master)
[![AppVeyor build status (0.3.x)](https://ci.appveyor.com/api/projects/status/u7idbsek3njnh648/branch/0.3.x?svg=true&passingText=0.3.x%20-%20OK&failingText=0.3.x%20-%20Fails)](https://ci.appveyor.com/project/enriquesomolinos/dreerally/branch/0.3.x)

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](CONTRIBUTING.md#pull-requests)
[![Download count](https://img.shields.io/github/downloads/enriquesomolinos/dreerally/total.svg)](https://github.com/enriquesomolinos/dreerally/releases)
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

# Building under Linux
- Run make -f Makefile.linux


# Installing
Once compiled, the DreeRally binary will serve as a replacement for `DeathRally.exe`. The following files from the original game need to be present: `ENDANI.haf`, `ENGINE.BPA`, `fmod.dll`, `IBFILES.BPA`,  `MENU.BPA`, `msvcr71.dll`, `MUSICS.BPA`, `SANIM.haf`, `SDL.dll`, and `TRX.BPA`.

In this version you can add a few parameters when you launch dreerally:

- -nosound: run with no music 
- -noeffect: run with no sound effects 
- -gl: run with opengl render. 
- -smooth
- -lang=lang(locale): run with a specific locale
- -mod={modName: run with a specific mod.
- -window: run in window mode

# Multiplayer
At this moment multiplayer is not implemented.

# Contributing
[Guidelines](docs/CONTRIBUTING.md)

# Translations
Here is the way to add a new language:

-Create a new file under lang directory, for example langBr.txt. Please, follow this name lang%locale%.txt
-Add your entries to this file. You can copy from langEs.txt
-Launch dreerally.exe with the parameter -lang=langBr to use your translation.
-If everything goes well, please, do a merge request to the project 

# Modding

Now, you can create mods. Mods are very simple and you need to follow this instructions
- Create a folder called mods
- Inside this directory create another one with the name of your mod. I uploaded a mod called 'sample'
- Create inside 'your mod name' folder a file called config.txt. THe config.txt file contains all thing that can be modded. You need to write the key-value pair that you want.
- Create a folder files inside 'your mod name' folder.
- Put your customized Death Rally files in uppercase. Simply name this files equals than the name of the file in Death Rally (for example FACE01.bpk or TR0-ima.bpk).
- Launch dreerally with -mod='your mod name' parameter.
- Enjoy dreerally with your custom options and files! 

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

