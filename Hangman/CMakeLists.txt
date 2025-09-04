# CMakeList.txt : CMake project for Hangman, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Hangman "main.cpp"   "state.cpp" "console.cpp" "game.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Hangman PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
