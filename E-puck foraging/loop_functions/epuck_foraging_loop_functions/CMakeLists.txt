link_directories(${CMAKE_BINARY_DIR}/controllers/epuck_foraging)
set(epuck_foraging_loop_functions_SOURCES epuck_foraging_loop_functions.cpp)

if(ARGOS_COMPILE_QTOPENGL)
  set(epuck_foraging_loop_functions_SOURCES
    ${epuck_foraging_loop_functions_SOURCES}
    epuck_foraging_qt_user_functions.cpp)
endif(ARGOS_COMPILE_QTOPENGL)

add_library(epuck_foraging_loop_functions MODULE ${epuck_foraging_loop_functions_SOURCES})
target_link_libraries(epuck_foraging_loop_functions
  epuck_foraging
  argos3core_simulator
  argos3plugin_simulator_dynamics2d
  argos3plugin_simulator_entities
  argos3plugin_simulator_epuck
  argos3plugin_simulator_genericrobot
  argos3plugin_simulator_media)

if(ARGOS_COMPILE_QTOPENGL)
  target_link_libraries(epuck_foraging_loop_functions argos3plugin_simulator_qtopengl)
endif(ARGOS_COMPILE_QTOPENGL)
