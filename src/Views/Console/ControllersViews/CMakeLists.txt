add_library(ControllersViews)

target_sources(ControllersViews
        PRIVATE
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

target_link_libraries(ControllersViews
        PRIVATE
            Controllers
            ModelsViews
            Utils
)