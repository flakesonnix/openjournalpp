#pragma once

#include <cstdint>
#include <ctime>
#include <optional>
#include <string>

#include <openjournal/journal/location.hpp>

namespace openjournal {

/// @brief Represents a journal experience entry.
/// @details An Experience encapsulates a single journal entry with title, text,
/// timestamps, favorite status, and optional location information.
class Experience {
public:
    /// @brief Constructs a new Experience.
    /// @param newId Unique identifier for the experience.
    /// @param newTitle Title of the experience.
    /// @param newText Main text content of the experience.
    /// @param newCreationDate Unix timestamp of when the experience was created.
    /// @param newSortDate Unix timestamp used for sorting experiences.
    /// @param newFavorite Whether the experience is marked as favorite (default: false).
    /// @param newLocation Optional location associated with the experience.
    Experience(
        std::int64_t newId,
        std::string newTitle,
        std::string newText,
        time_t newCreationDate,
        time_t newSortDate,
        bool newFavorite = false,
        std::optional<Location> newLocation = std::nullopt
    );

    /// @brief Gets the unique identifier.
    /// @return The experience ID.
    [[nodiscard]] std::int64_t getID() const;

    /// @brief Gets the title.
    /// @return Constant reference to the title string.
    [[nodiscard]] const std::string& getTitle() const;

    /// @brief Gets the main text content.
    /// @return Constant reference to the text string.
    [[nodiscard]] const std::string& getText() const;

    /// @brief Gets the creation date.
    /// @return Unix timestamp of creation.
    [[nodiscard]] time_t getCreationDate() const;

    /// @brief Gets the sort date.
    /// @return Unix timestamp used for sorting.
    [[nodiscard]] time_t getSortDate() const;

    /// @brief Checks if the experience is marked as favorite.
    /// @return True if favorite, false otherwise.
    [[nodiscard]] bool isFavorite() const;

    /// @brief Gets the optional location.
    /// @return Constant reference to the optional Location.
    [[nodiscard]] const std::optional<Location>& getLocation() const;

    /// @brief Sets a new title.
    /// @param newTitle The new title string.
    void setTitle(const std::string& newTitle);

    /// @brief Sets new text content.
    /// @param newText The new text string.
    void setText(const std::string& newText);

    /// @brief Sets a new sort date.
    /// @param newSortDate New Unix timestamp for sorting.
    void setSortDate(time_t newSortDate);

    /// @brief Sets the favorite status.
    /// @param newFavorite True to mark as favorite, false otherwise.
    void setFavorite(bool newFavorite);

    /// @brief Toggles the favorite status.
    void toggleFavorite();

    /// @brief Sets the location.
    /// @param newLocation The new Location to associate.
    void setLocation(const Location& newLocation);

    /// @brief Clears the associated location.
    void clearLocation();

private:
    std::int64_t id_ = 0;
    std::string title_;
    std::string text_;
    time_t creationDate_ = 0;
    time_t sortDate_ = 0;
    bool favorite_ = false;
    std::optional<Location> location_;
};

} // namespace openjournal