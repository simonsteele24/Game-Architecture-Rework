# Game-Architecture-Rework

How to Set up the project

- Go into final.sln

NOTE: Make sure you are in Debug and X86

- When loaded into visual studio, right click on the main solution file and go to retarget projects, make sure the latest verion of windows is included

- Right click onto the final subfolder and go to properties
- Make sure that configuration and platform are set to active
- From here, go to C/C++ submenu and redo all file locations in additional dependencies with the correct final locations
- Go to the linker submenu and do the same thing in the additional library directories

- Hit apply and go onto the graphicslib subfolder properties
- Make sure that configuration and platform are set to active
- Go to the C/C++ subfolder and again, redo all file locations in the additional include directories
- Hit apply and you should be good to go
