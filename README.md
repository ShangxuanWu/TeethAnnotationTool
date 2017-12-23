# TeethAnnotationTool
This is a teeth annotation tool for cropping out each individual teeth. Following two sections are the usage of binary and how you can build from scratch.

## Definition of Teeth
![alt text](https://github.com/ShangxuanWu/TeethAnnotationTool/blob/master/TeethAnnotationTool/Teeth.png?raw=true)

- Upper Right ThirdWisdomMolar: 1 
- Upper Right SecondMolar: 2 
- Upper Right FirstMolar: 3 
- Upper Right SecondPremolar: 4 
- Upper Right FirstPremolar: 5 
- Upper Right Canine: 6 
- Upper Right LateralIncisor: 7 
- Upper Right CentralIncisor: 8 
- Upper Left CentralIncisor: 9 
- Upper Left LateralIncisor: 10 
- Upper Left Canine: 11 
- Upper Left FirstPremolar: 12 
- Upper Left SecondPremolar: 13 
- Upper Left FirstMolar: 14 
- Upper Left SecondMolar: 15 
- Upper Left ThirdWisdomMolar: 16 
- Lower Left ThirdWisdomMolar: 17 
- Lower Left SecondMolar: 18 
- Lower Left FirstMolar: 19 
- Lower Left SecondPremolar: 20 
- Lower Left FirstPremolar: 21 
- Lower Left Canine: 22 
- Lower Left LateralIncisor: 23 
- Lower Left CentralIncisor: 24 
- Lower Right CentralIncisor: 25 
- Lower Right LateralIncisor: 26 
- Lower Right Canine: 27 
- Lower Right FirstPremolar: 28 
- Lower Right SecondPremolar: 29 
- Lower Right FirstMolar: 30 
- Lower Right SecondMolar: 31 
- Lower Right ThirdWisdomMolar: 32


## Binary Usage
### Folder
- Input: Please choose the folder with `LowerJawScan.stl` and `UpperJawScan.stl` in it.
- Output: Cropped OBJ files will be stored in `cropped_mesh` folder with corresponding IDs.  

### Mouse Clicks
- Please use left click to define the boundary of one tooth.
- After finish defining the boundary, you can click the middle button to show the cropping result.
- If you are not satisfied with the cropped result, just close the window. If you think the cropped result is good, click `save`.


## Dependencies
Following are dependencies for building from source code:

1. VS 2017
2. Qt 5.9.2: Download [here](http://download.qt.io/official_releases/online_installers/qt-unified-windows-x86-online.exe).
3. Qt VS plugin: Download [here]()
4. CMake GUI: Download [here](https://cmake.org/files/v3.10/cmake-3.10.1-win64-x64.msi), for building VTK from source.
5. VTK 8.0.1: Download [here](), please see the following section to build from scratch and do not use the binary installer on the internet.

### Building VTK
We have to build VTk with QVTKWidget and OpenGL1 backend(default VTK binaries are with OpenGL2 backend and no QVTKWidget). Following are the settings of CMake:
- QT_VERSION: 5
- WITH_QT: TRUE
- 

Please lauch the `a.sln` then and build VTK using Release win32.

