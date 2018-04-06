include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 8)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(pesel libpesel)
add_gtest_with_memleak(movie_subtitles libmoviesubtitles)
add_gtest_with_memleak(micro_dvd_correct_cases libmoviesubtitles)
add_gtest_with_memleak(micro_dvd_error_cases libmoviesubtitles)
add_gtest_with_memleak(sub_rip_correct_cases libmoviesubtitles)
add_gtest_with_memleak(sub_rip_error_cases libmoviesubtitles)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab8_all_tests ${SOURCE_FILES})

target_link_libraries(lab8_all_tests ${GTEST_LIBS})
target_link_libraries(lab8_all_tests libpesel)
target_link_libraries(lab8_all_tests libmoviesubtitles)
target_link_libraries(lab8_all_tests stringutility)
memleak_target(lab8_all_tests)
