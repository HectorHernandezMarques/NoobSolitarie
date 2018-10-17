add_library(Memento)
target_sources(Memento
        PRIVATE
            BoardMemento.cpp
            BoardMementoCareTaker.cpp
            FoundationMemento.cpp
            StockMemento.cpp
            TableauMemento.cpp)

target_link_libraries(Memento
        PRIVATE
            Utils
            Cards
)