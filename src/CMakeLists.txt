add_executable(FVS_main)
target_sources(TravelingSalesmanSolver_main PRIVATE
    main.cpp)
target_link_libraries(FVS_main PUBLIC
    Boost::program_options)
set_target_properties(TravelingSalesmanSolver_main PROPERTIES OUTPUT_NAME "FVS")
install(TARGETS FVS_main)
