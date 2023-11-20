# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-src"
  "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-build"
  "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-subbuild/glm-populate-prefix"
  "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-subbuild/glm-populate-prefix/tmp"
  "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
  "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-subbuild/glm-populate-prefix/src"
  "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/annamarialannaud/Documents/imac./cours/ProgAlgo/workshop-image-manipulation/build/_deps/glm-subbuild/glm-populate-prefix/src/glm-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
