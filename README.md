### C++ programming classes problmes ###

[![Build Status](https://travis-ci.org/micwypych/cpp-exercises.svg?branch=master)](https://travis-ci.org/micwypych/cpp-exercises)

#### CLion CMakeLists.txt template ####

In order to create new solution faster one can define template file 
in CLion based on [CMake template](scripts/Library_CMakeLists_Add_Template).
To add that template one has to right click in project menu choose
`New` from pop-up menu and and then `Edit File Templates...`. In new dialog
`File and Code Templates` click green plus and copy paste template. 

To use it just click again `New` and then it should show up in the list. 
The final step is to specify name which must be CMakeLists.txt and **space seperated**
name of the testing class name e.g. `reverse string`
