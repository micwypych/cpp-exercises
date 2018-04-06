include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 3)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak_stepped(smart_tree 1 2 3 4 5)

add_gtest_with_memleak_stepped(tiny_url 1 2)

add_gtest_with_memleak(c_counter libccounter)

add_gtest_with_memleak(minimal_time_difference libminimaltimedifference)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab3_all_tests ${SOURCE_FILES})

target_link_libraries(lab3_all_tests ${GTEST_LIBS})
target_link_libraries(lab3_all_tests libsmarttree)
target_link_libraries(lab3_all_tests libtinyurl)
target_link_libraries(lab3_all_tests libccounter)
target_link_libraries(lab3_all_tests libminimaltimedifference)
target_link_libraries(lab3_all_tests stringutility)
memleak_target(lab3_all_tests)
