#add_subdirectory(greedy)

add_executable(fvs_graph_test)
target_sources(fvs_graph_test PRIVATE
	graph_test.cpp)
target_link_libraries(fvs_graph_test 
	fvs_graph
	GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(fvs_graph_test)
