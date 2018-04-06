include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 4)

#######################################################################
##  TESTS
#######################################################################
add_gtest_with_memleak(simple_url libsimpleurl)

add_gtest_with_memleak(simple_template_engine libsimpletemplateengine)
add_gtest_with_memleak(simple_template_engine_injection libsimpletemplateengine)

add_gtest_with_memleak(simple_json libsimplejson)
add_gtest_with_memleak(square libsquare)
add_gtest_with_memleak(name libname)


#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab4_all_tests ${SOURCE_FILES})

target_link_libraries(lab4_all_tests ${GTEST_LIBS})
target_link_libraries(lab4_all_tests libsimpleurl)
target_link_libraries(lab4_all_tests libsimpletemplateengine)
target_link_libraries(lab4_all_tests libsimplejson)
target_link_libraries(lab4_all_tests libsqure)
target_link_libraries(lab4_all_tests libname)
memleak_target(lab4_all_tests)
target_link_libraries(lab4_all_tests stringutility)
