add_library(fvs_graph)
target_sources(fvs_graph PRIVATE
    graph.cpp)
target_include_directories(fvs_graph PUBLIC 
	${PROJECT_SOURCE_DIR}/include)




