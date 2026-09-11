#include <print>
#include <openjournal/journal/location.hpp>
#include <openjournal/journal/experience.hpp>

int main() {
    openjournal::Location location(
        "Berlin",
        52.52,
        13.405
    );

    openjournal::Experience experience(
        1,
        "Meow first",
        "Fist meow",
        std::time(nullptr),
        std::time(nullptr),
        false,
        location);


    std::println("ID: {}", experience.getID());
    std::println("Title: {}", experience.getTitle());
    std::println("Text: {}", experience.getText());
    std::println("Favorite: {}", experience.isFavorite());


    if (experience.getLocation().has_value()) {
        std::println("Location: {}", experience.getLocation()->getName());
    }

    return 0;
}
