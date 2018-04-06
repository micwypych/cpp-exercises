include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 7)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(array_fill_uniform libarrayfill)
add_gtest_with_memleak(array_fill_incremental libarrayfill)
add_gtest_with_memleak(array_fill_squared libarrayfill)
add_gtest_with_memleak(array_fill_random libarrayfill)
add_gtest_with_memleak(comparable libcomparable)
add_gtest_with_memleak(iterable libiterable)
add_gtest_with_memleak(iterable_zipper libiterable)
add_gtest_with_memleak(iterable_enumeration libiterable)
add_gtest_with_memleak(iterable_product libiterable)
add_gtest_with_memleak(student_repository_query libstudentrepositoryqueries)
add_gtest_with_memleak(student_repository_query_by_first_name libstudentrepositoryqueries)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab7_all_tests ${SOURCE_FILES} IterableProductTest.cpp)

target_link_libraries(lab7_all_tests ${GTEST_LIBS})
target_link_libraries(lab7_all_tests libarrayfill)
target_link_libraries(lab7_all_tests libcomparable)
target_link_libraries(lab7_all_tests libiterable)
target_link_libraries(lab7_all_tests libstudentrepositoryqueries)
target_link_libraries(lab7_all_tests stringutility)
memleak_target(lab7_all_tests)
