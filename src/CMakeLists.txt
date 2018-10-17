add_subdirectory(Models)

add_subdirectory(Utils)

add_subdirectory(Controllers)

add_subdirectory(Views)

add_executable(NoobSolitarie)

target_sources(NoobSolitarie
        PRIVATE
            NoobSolitarie.cpp
            main.cpp)

target_link_libraries (NoobSolitarie
        PRIVATE
            Console
            Local
)