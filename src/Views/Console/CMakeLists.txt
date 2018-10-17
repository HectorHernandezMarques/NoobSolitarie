add_subdirectory(ControllersViews)
add_subdirectory(ModelsViews)

add_library(Console)

target_sources(Console
        PRIVATE
            NoobSolitarieView.cpp
)

target_link_libraries(Console
        PRIVATE
            ControllersViews
)