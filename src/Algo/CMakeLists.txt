add_library(FVS_algo)
target_sources(FVS_algo PRIVATE
    algo.cpp)
target_link_libraries(FVS_algo PUBLIC
	FVS_graph)
target_include_directories(FVS_graph PUBLIC 
	${PROJECT_SOURCE_DIR}/include)




