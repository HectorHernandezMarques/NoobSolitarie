add_subdirectory(Local)

add_library(Controllers)

target_sources(Controllers
        PRIVATE
            CardChoice.cpp
)
