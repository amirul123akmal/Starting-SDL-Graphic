# Starting SDL Graphic

###### The Documentation : https://wiki.libsdl.org/APIByCategory ( Sorted into Category )
###### The Documentation : https://wiki.libsdl.org/CategoryAPI ( All of the Function Avalable )
###### Tutorial by : https://youtube.com/playlist?list=PL1H1sBF1VAKXMz8kETLHRo1LwnvB08Q2J

#### Main Purposes of This
* Start involving in graphics API
* Slowly get the way to advanced project

## Dependencies
1. Vsual Studio 2019
    * [ SDL2.0 ](https://www.libsdl.org/release/SDL2-devel-2.0.16-VC.zip)  
    * [ SDL_Image 2.0 ](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-VC.zip)
    * [ SDL_Mixer ](https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-VC.zip)
2. g++ ( clang / ming-w )
    * [ SDL2.0 ](https://www.libsdl.org/release/SDL2-devel-2.0.16-mingw.tar.gz)
    * [ SDL_Image 2.0 ](https://www.libsdl.org/projects/SDL_image/release/SDL2_image-devel-2.0.5-mingw.tar.gz )
    * [ SDL_Mixer ](https://www.libsdl.org/projects/SDL_mixer/release/SDL2_mixer-devel-2.0.4-mingw.tar.gz )

## Common Question ( maybe )
#### 1. How to run this
* Reminder, this project require Dependencies
     - Check `No.2`
* Visual Studio 2019
    1. Open `Starting SDL Graphic.sln`
    2. Build the solution
    3. Make a copy of `res` folder in `Starting SDL graphic` to { `x64\debug` or `x64\release`}
    4. Run the executable
* The youtuber uses linux, I think it wirth a while to check him out

#### 2. Manage your Dependencies
* All dependencies for the project already done by the Solution that I configured
* All that are left are `.dll` that Windows need to recognize
* Windows
    1. Etract all the dependencies Folder
    2. Move all folder to your `C:/`
    3. Open `Edit The system environment path` ->  `Environment Variables` -> double click `path`
    4. paste this at each new line
        - `C:\SDL2-2.0.16\lib\x64`
        - `C:\SDL2_image-2.0.5\lib\x64`
        - `C:\SDL2_mixer-2.0.4\lib\x64`
* The youtuber uses linux and he using `pkg-config` if im not mistaken
