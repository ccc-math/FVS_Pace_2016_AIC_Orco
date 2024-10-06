add_library(FVS_graph)
target_sources(FVS_graph PRIVATE
    graph.cpp)
target_include_directories(FVS_graph PUBLIC 
	${PROJECT_SOURCE_DIR}/include)




