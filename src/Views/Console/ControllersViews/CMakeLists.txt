add_library(ControllersViews
        ActionView.cpp
        FlipView.cpp
        InitialGameDecitionView.cpp
        MoveView.cpp
        PutCardInFoundationView.cpp
        PutCardInTableauView.cpp
        StartView.cpp
        TakeCardFromFoundationView.cpp
        TakeCardFromStockView.cpp
        TakeCardFromTableauView.cpp
        )

target_link_libraries(ControllersViews Controllers ModelsViews Utils)