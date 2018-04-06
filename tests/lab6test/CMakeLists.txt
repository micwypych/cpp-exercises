include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 6)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(student_repository libstudentrepository)
add_gtest_with_memleak(student_repository_study_year libstudentrepository)
add_gtest_with_memleak(student_repository_student libstudentrepository)
add_gtest_with_memleak(word_counter libwordcounter)
add_gtest_with_memleak(zipper libzipper)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab6_all_tests ${SOURCE_FILES})

target_link_libraries(lab6_all_tests ${GTEST_LIBS})
target_link_libraries(lab6_all_tests libstudentrepository)
target_link_libraries(lab6_all_tests libwordcounter)
target_link_libraries(lab6_all_tests libzipper)
memleak_target(lab6_all_tests)
target_link_libraries(lab6_all_tests stringutility)
