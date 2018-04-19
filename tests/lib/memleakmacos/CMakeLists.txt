project(memleakmacos)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(MEM_LEAK_SOURCE_FILES MemLeakTest.cpp)

add_library(memleakmacos STATIC ${MEM_LEAK_SOURCE_FILES})
target_link_libraries(memleakmacos ${GTEST_LIBS})
target_include_directories(memleakmacos PUBLIC .)