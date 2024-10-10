enable_testing()

add_executable(fvs_greedy_test)
target_sources(fvs_greedy_test PRIVATE
	greedy_test.cpp)
target_link_libraries(fvs_greedy_test 
	fvs_greedy
	GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(fvs_greedy_test)
