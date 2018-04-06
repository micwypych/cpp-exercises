include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 10)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(scheduler libscheduler)
add_gtest_with_memleak(schedule libscheduler)
add_gtest_with_memleak_stepped(algo 1 2 3 4 5)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab10_all_tests ${SOURCE_FILES})

target_link_libraries(lab10_all_tests ${GTEST_LIBS})
target_link_libraries(lab10_all_tests libscheduler)
target_link_libraries(lab10_all_tests libalgo)
target_link_libraries(lab10_all_tests stringutility)
memleak_target(lab10_all_tests)
