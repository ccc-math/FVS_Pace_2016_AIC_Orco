add_library(fvs_graph)
add_library(fvs_multigraph)
target_sources(fvs_graph PRIVATE
    graph.cpp)
target_sources(fvs_multigraph PRIVATE
    multigraph.cpp)
target_include_directories(fvs_graph PUBLIC 
	${PROJECT_SOURCE_DIR}/include)
target_include_directories(fvs_multigraph PUBLIC 
	${PROJECT_SOURCE_DIR}/include)




