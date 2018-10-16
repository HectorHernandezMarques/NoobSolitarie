add_subdirectory(ControllersViews)
add_subdirectory(ModelsViews)

add_library(Console
        NoobSolitarieView.cpp
        )

target_link_libraries(Console ControllersViews)