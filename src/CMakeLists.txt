add_library(FVS_graph)
target_sources(FVS_graph PRIVATE
    graph.cpp)

add_executable(FVS_main)
target_sources(FVS_main PRIVATE
    main.cpp)
target_link_libraries(FVS_main PUBLIC
    FVS_graph)


