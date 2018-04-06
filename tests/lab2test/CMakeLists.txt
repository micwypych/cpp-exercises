include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_LAB_NUMBER 2)


#######################################################################
##  TESTS
#######################################################################
add_gtest(array_2d_step1 libarray2d)

add_gtest_with_memleak_stepped(array_2d 2 3 4)

add_gtest_with_memleak_stepped(polybius 1 2)

add_gtest_with_memleak_stepped(greatest_product 1 2 3)

add_gtest_with_memleak_stepped(simple_forward_list 1 2 3)

add_gtest_with_memleak(xor_cypher_breaker libxorcypherbreaker)

#######################################################################
##  ALL TESTS
#######################################################################
add_executable(lab2_all_tests ${SOURCE_FILES})

target_link_libraries(lab2_all_tests ${GTEST_LIBS})
target_link_libraries(lab2_all_tests libarray2d)
target_link_libraries(lab2_all_tests libpolybius)
target_link_libraries(lab2_all_tests libgreatestproduct)
target_link_libraries(lab2_all_tests libsimpleforwardlist)
target_link_libraries(lab2_all_tests libxorcypherbreaker)
target_link_libraries(lab2_all_tests stringutility)
memleak_target(lab2_all_tests)
