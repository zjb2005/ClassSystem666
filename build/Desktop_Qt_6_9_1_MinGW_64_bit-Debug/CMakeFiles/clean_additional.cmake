# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\classsystem_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\classsystem_autogen.dir\\ParseCache.txt"
  "QXlsx\\CMakeFiles\\QXlsx_autogen.dir\\AutogenUsed.txt"
  "QXlsx\\CMakeFiles\\QXlsx_autogen.dir\\ParseCache.txt"
  "QXlsx\\QXlsx_autogen"
  "classsystem_autogen"
  )
endif()
