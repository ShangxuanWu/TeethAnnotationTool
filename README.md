# TeethAnnotationTool
This is a teeth annotation tool for cropping out each individual teeth. Following two sections are the usage of binary and .

## Definition of Teeth

## Binary Usage
### Mouse Clicks
- Please use left click to define the boundary of one tooth.
- After finish defining the boundary, you can click the middle button to show the cropping result.
- If 


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

Please lauch the `a.sln` then and build using Release win32.

