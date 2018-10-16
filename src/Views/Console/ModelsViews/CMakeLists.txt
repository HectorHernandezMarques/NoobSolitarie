add_library(ModelsViews
        BoardView.cpp
        CardChoiceView.cpp
        CardView.cpp
        ClosedIntervalView.cpp
        FoundationView.cpp
        InitialGameDecitionNameView.cpp
        LimitedIntDialogView.cpp
        NumberView.cpp
        StockView.cpp
        SuitView.cpp
        TableauView.cpp
        )

target_link_libraries(ModelsViews Controllers Utils)