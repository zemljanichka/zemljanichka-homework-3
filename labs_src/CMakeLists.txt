add_library(labs)

target_sources(labs
        PRIVATE
        lab3/BackupJob.cpp
        lab3/JobObject.cpp
        lab3/Object.cpp
        lab3/Repository.cpp
        lab3/RestorePoint.cpp
        PUBLIC
        lab3/BackupJob.h
        lab3/JobObject.h
        lab3/Object.h
        lab3/Repository.h
        lab3/RestorePoint.h
        )

target_include_directories(labs
        PUBLIC
        .
        )

target_compile_options(labs
        PRIVATE
        -Wall -Wextra -Wpedantic
        )

add_executable(
        lab3_test
        lab3/test.cpp
)

target_link_libraries(lab3_test
        PRIVATE
        labs
        )

target_compile_options(lab3_test
        PRIVATE
        -Wall -Wextra -Wpedantic
        )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(labs
          PUBLIC
          "--coverage"
          )
  target_link_options(labs
          INTERFACE
          "--coverage"
          )
endif()
