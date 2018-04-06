include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 13)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(arabic_to_roman libarabicroman)
add_gtest_with_memleak(roman_to_arabic libarabicroman)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab13_all_tests ${SOURCE_FILES})

target_link_libraries(lab13_all_tests ${GTEST_LIBS})
target_link_libraries(lab13_all_tests libarabicroman)
memleak_target(lab13_all_tests)
