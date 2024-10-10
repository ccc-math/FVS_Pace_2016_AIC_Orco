add_library(fvs_greedy)
target_sources(fvs_greedy PRIVATE
    greedy.cpp)
target_link_libraries(fvs_greedy PUBLIC
	fvs_graph)
target_include_directories(fvs_graph PUBLIC 
	${PROJECT_SOURCE_DIR}/include)




