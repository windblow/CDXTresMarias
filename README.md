# CDXTresMarias

An old clicker game developed in 2004 as part of my associate's degree course in Game Development @ Pontifícia Universidade Católica do Rio de Janeiro (PUC-Rio).

Uses the CDX game development kit (https://sourceforge.net/projects/cdx/) with a few tweaks in order to make it compatible with modern libraries.

Also uses a window creation wrapper class called EasyWindow by Rafael A. Costa

Originally developed in VC++ 6 and now ported to VS2022 Community + Windows 10 SDK

## Getting Started

Download Microsoft Visual Studio Community 2022 and install it with the workloads for Desktop Developent in C++ and Game Development in C++ selected.

Open the solution file in the project root directory, set the solution platform to x86, and build. Executable is generated in the CDXTresMarias subdirectory (the one that has the resources directory).

NOTE: Currently, the project does not build for x64 platforms.

### Running the game

Double click the executable found in the \CDXTresMarias subdirectory after building it. Use the Escape key to exit the game.

## Playing the game

The game is based on the ages-old game of "three marys" (Três Marias), in which the players must throw one or more small sandbags in the air and pick up as many other sandbags they can from the floor before catching the thrown ones on its way down. Using the spacebar to throw the airborne bags, click on every other bag and then click the airborne ones before they hit the ground. The faster the player is at clearing the stage, the more points they earn. Only after clicking every grounded bag will the game let the player catch the flying one(s). If one of the flying bags hits the floor before being catched, the game is over. Every stage adds more sandbags in the ground, and every five stages, the number of thrown bags increases. The game has 20 levels.

## Resources

The music and the sound of school playground chatter were downloaded from free assets collections on the internet. The background was created with royalty-free images and textures and pre-rendered using Blender. The sandbag sprites were made by pre-rendering frames in Blender and stiching them together with Photoshop.

## Authors

CDX Game Development Kit by Bil Simser and Michael Rich

EasyWindows class by Rafael A. Costa

Game code and assets by Rafael Pagani Savastano (me).

## License

Whatever, just don't @ me if something doesn't work lol.

## Screenshots

![image](https://user-images.githubusercontent.com/713061/233803044-5c91abac-64d5-40e8-bff6-fe78b7bb7d93.png)

![image](https://user-images.githubusercontent.com/713061/233803063-53fafe5a-e55a-4400-bd57-404d0f7bc849.png)

