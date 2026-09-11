#include <openjournal/journal/experience.hpp>

#include <utility>

namespace openjournal {
Experience::Experience(
    std::int64_t newId,
    std::string newTitle,
    std::string newText,
    time_t newCreationDate,
    time_t newSortDate,
    bool newFavorite,
    std::optional<Location> newLocation
)
    : id_(newId),
      title_(std::move(newTitle)),
      text_(std::move(newText)),
      creationDate_(newCreationDate),
      sortDate_(newSortDate),
      favorite_(newFavorite),
      location_(std::move(newLocation)) {
}

std::int64_t Experience::getID() const {
    return id_;
}

const std::string& Experience::getTitle() const {
    return title_;
}

const std::string& Experience::getText() const {
    return text_;
}

time_t Experience::getCreationDate() const {
    return creationDate_;
}

time_t Experience::getSortDate() const {
    return sortDate_;
}

bool Experience::isFavorite() const {
    return favorite_;
}

const std::optional<Location>& Experience::getLocation() const {
    return location_;
}

void Experience::setTitle(const std::string& newTitle) {
    title_ = newTitle;
}

void Experience::setText(const std::string& newText) {
    text_ = newText;
}

void Experience::setSortDate(time_t newSortDate) {
    sortDate_ = newSortDate;
}

void Experience::setFavorite(bool newFavorite) {
    favorite_ = newFavorite;
}

void Experience::toggleFavorite() {
    favorite_ = !favorite_;
}

void Experience::setLocation(const Location& newLocation) {
    location_ = newLocation;
}

void Experience::clearLocation() {
    location_.reset();
}
} // namespace openjournal