add_subdirectory(Graph)
add_subdirectory(Algo)



add_executable(fvs_main)
target_sources(fvs_main PRIVATE
    main.cpp)
target_link_libraries(fvs_main PUBLIC
    fvs_graph
    fvs_multigraph
    fvs_greedy
    fvs_precomputations)


