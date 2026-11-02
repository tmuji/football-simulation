# CMakeList.txt : CMake project for football-simulation, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (football-simulation "src/main.cpp"  "include/team.h" "src/team.cpp" "include/league.h" "src/league.cpp" "include/match.h" "src/match.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET football-simulation PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
