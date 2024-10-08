add_subdirectory(Graph)
add_subdirectory(Algo)



add_executable(FVS_main)
target_sources(FVS_main PRIVATE
    main.cpp)
target_link_libraries(FVS_main PUBLIC
    FVS_graph
    FVS_algo)


