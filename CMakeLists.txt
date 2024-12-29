# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(CustomSTL VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory for headers
include_directories(include)

# Add the source files
add_executable(main src/main.cpp)

# Install headers to include/
install(DIRECTORY include/ DESTINATION include)

# Install the executable to bin/
install(TARGETS main DESTINATION bin)

# Include CPack for packaging
include(CPack)

# Configure CPack settings
set(CPACK_PACKAGE_NAME "CustomSTL")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Custom STL Implementation")
set(CPACK_PACKAGE_VENDOR "Your Name or Organization")
set(CPACK_PACKAGE_CONTACT "your.email@example.com")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION}")
set(CPACK_GENERATOR "TGZ;ZIP") # Generate both .tar.gz and .zip files