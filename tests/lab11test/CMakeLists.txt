include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 11)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(factory_method libfactorymethod)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab11_all_tests ${SOURCE_FILES})

target_link_libraries(lab11_all_tests ${GTEST_LIBS})
target_link_libraries(lab11_all_tests libfactorymethod)
target_link_libraries(lab11_all_tests memleak)
