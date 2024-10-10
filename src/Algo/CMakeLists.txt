add_library(fvs_greedy)
add_library(fvs_precomputations)
target_sources(fvs_greedy PRIVATE
    greedy.cpp)
target_sources(fvs_precomputations PRIVATE
    precomputations.cpp)
target_link_libraries(fvs_greedy PUBLIC
	fvs_graph)
target_link_libraries(fvs_precomputations PUBLIC
	fvs_graph)
target_include_directories(fvs_graph PUBLIC 
	${PROJECT_SOURCE_DIR}/include)




