# OPSimTool

OpsimTool is a set of additions to the Geant4 toolkit that facilitate the implementation of optical photon applications and increase the flexibility and maintainability of developed applications. It also provides interfaces for creating reusable and portable material build code. This tool has been created according to users' needs and perspectives, considering frequently asked questions, most encountered challenges, and evolving needs over time in the optical category of the Geant4 official forum page.
             
## The package structure:   

_OPSim/OPSimTool_: This directory includes the header and implementation files of OPSimTool. 

_OPSim/examples_: To demonstrate how to use OPSimTool in an application, we choose OpNovice, one of the examples in Geant4's optical category. This directory contains two versions of the selected application.  

_OPSim/examples/OpNovice_ : This is the original version provided by the Geant4 team.

_OPSim/examples/OpNoviceEx01_: This example shows the usage of MaterialPropertiesTable and OpticalSurface classes and their implementations via user interface commands. Only the OPNoviceDetectorConstruction.cc file has been modified from the source files of OPNovice. All other implementation files are the same as in OpNovice. Also, different from the original version, directories named data, macros, and OPSimTool have been added to the project source directory. 

_OPSim/examples/OpNoviceEx02_: This example shows how to use VMaterialBuilder class to decouple a material build code from the detector construction code. This example also shows users how to create an app-independent reusable material build code while working on their own projects. Only the OPNoviceDetectorConstruction.cc file has been modified from the source files of OPNovice. All other implementation files are the same as in OpNovice. Also, different from the original version, directories named data, macros, reusableMaterials, and OPSimTool have been added to the project source directory. The directory named reusableMaterials is now application-independent and can be moved across projects.

_OPSim/examples/output_: This directory contains one output from every three examples. It should be noted here that the output of all three examples(i.e., printed output of material properties table) is the same as expected. 

_OPSim/EljenScintillators_: To demonstrate how to build a material factory class using OPSimTool, we fully implement and parameterize four of the widely used Eljen scintillators on the market and made them available to users. This directory is also a good example showing how data (i.e. ASCI files), macro files, and C++ files are organized when creating a factory class. Those who want to use these scintillators in their applications should copy this directory into their project source directory.
                                                                
_OPSim/EljenScintillators/includes_: This directory includes header files of the scintillators' builder classes.

_OPSim/EljenScintillators/src_: This directory includes implementation files of the scintillators' builder classes. 

_OPSim/EljenScintillators/data_: This directory contains energy-dependent data for the optical properties of scintillators, such as emission spectrum, refractive index, and absorption length.

_OPSim/EljenScintillators/macros_ : This directory includes a macro file(file with .mac extension) for each scintilator. 

## Tested on 

* Os: Linux (Ubuntu 22.04.2 LTS)
* Architecture: x86_64
* Compiler: GCC 11.3.0
* Geant4.11.1.1

## How to run the provided example applications?   
  
1. Go to the directory where you installed the OpNovice in your system.
  ```bash	
   cd path/To/OpNovice
  ```
  
2. Create a directory named OpNovice-build in the same directory as OpNovice. 
  ```bash
   mkdir OpNovice-build
   ```

3. Now go inside this build directory and run CMake to generate the Makefiles needed to build the application. Two arguments are 
passed to CMake. The first argument to CMake is the path to the source directory that includes the CMakeList.txt file. The second argument is the path to the build directory where the generated make files will be located. CMake will now run to configure the build and generate Makefiles.
```bash
  cd OpNovice-build
  cmake -S ../OpNovice -B .
 ```
5. With the Makefile available, you can now build by simply running make: 
  ```bash
   make  
  ```
5. The application is now ready to run. If you now list the contents of your build directory, you will notice that the executable OPNovice has been created. The program can be executed in two modes: interactive and batch. To run in an interactive mode:
  ```bash
   ./OPNovice
```
All versions of OPNovice run in the same way.  
 
## Contacts 

If you have any questions or wish to notify of updates and/or modifications please contact: \
Mustafa Kandemir (mustafa.kandemir@erdogan.edu.tr)

## Citation
@article{KANDEMIR2023108873, \
title = {OPSimTool: A custom tool for optical photon simulation in Geant4}, \
journal = {Computer Physics Communications}, \
volume = {292}, \
pages = {108873}, \
year = {2023}, \
issn = {0010-4655}, \
doi = {https://doi.org/10.1016/j.cpc.2023.108873}, \
url = {https://www.sciencedirect.com/science/article/pii/S0010465523002187}, \
author = {Mustafa Kandemir}, \
keywords = {Scintillators, Scintillation photon, Light collection, Material optical properties, Eljen scintillators} \
}

