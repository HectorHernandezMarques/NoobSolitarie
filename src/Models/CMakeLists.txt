add_subdirectory (Cards)
add_subdirectory (Memento)

add_library(Models)
target_sources(Models
        PRIVATE
            Board.cpp
            BoardBuilder.cpp
            Deck.cpp
            Foundation.cpp
            Game.cpp
            Stack.cpp
            StackAddable.cpp
            Stock.cpp
            Tableau.cpp)

target_link_libraries(Models
        PRIVATE
            Cards
            Memento
)