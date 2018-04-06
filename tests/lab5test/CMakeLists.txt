include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 5)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(memory_chunk libmemorychunk)
add_gtest_with_memleak(text_pool libtextpool)
add_gtest_with_memleak(matrix libmatrix)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab5_all_tests ${SOURCE_FILES})

target_link_libraries(lab5_all_tests ${GTEST_LIBS})
target_link_libraries(lab5_all_tests libmemorychunk)
target_link_libraries(lab5_all_tests libtextpool)
target_link_libraries(lab5_all_tests libmatrix)
memleak_target(lab5_all_tests)
target_link_libraries(lab5_all_tests stringutility)
