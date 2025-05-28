# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\GestionaleStudenti_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\GestionaleStudenti_autogen.dir\\ParseCache.txt"
  "GestionaleStudenti_autogen"
  )
endif()
