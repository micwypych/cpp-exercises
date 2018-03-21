
project(examplelibrary)

set(HEDEAR_FILES ExampleLibrary.h)
set(SOURCE_FILES ExampleLibrary.cpp)

add_library(libexamplelibrary STATIC ${SOURCE_FILES})
target_include_directories(libexamplelibrary PUBLIC .)

