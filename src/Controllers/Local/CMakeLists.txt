add_library(Local
        ActionController.cpp
        ActionControllerBuilder.cpp
        Controller.cpp
        FlipController.cpp
        InitialGameDecitionController.cpp
        Logic.cpp
        MoveController.cpp
        OperationController.cpp
        PutCardController.cpp
        PutCardInFoundationController.cpp
        PutCardInTableauController.cpp
        RedoController.cpp
        StartController.cpp
        TakeCardController.cpp
        TakeCardFromFoundationController.cpp
        TakeCardFromStockController.cpp
        TakeCardFromTableauController.cpp
        UndoController.cpp
        )

target_link_libraries(Local Controllers Models)