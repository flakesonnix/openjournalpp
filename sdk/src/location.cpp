#include <openjournal/journal/location.hpp>

namespace openjournal {
    Location::Location(std::string newName,
                       std::optional<double> newLatitude,
                       std::optional<double> newLongitude)
        : name(std::move(newName)),
          latitude(newLatitude),
          longitude(newLongitude) {
    }

    [[nodiscard]] std::string Location::getName() const {
        return name;
    }

    void Location::setName(std::string name) {
        this->name = name;
    }

    [[nodiscard]] std::optional<double> Location::getLatitude() const {
        return latitude;
    }

    void Location::setLatitude(std::optional<double> latitude) {
        this->latitude = latitude;
    }

    void Location::setLongitude(std::optional<double> longitude) {
        this->longitude = longitude;
    }

    [[nodiscard]] bool Location::hasCoordinates() const {
        return latitude.has_value() && longitude.has_value();
    }

    void Location::clearCoordinates() {
        latitude.reset();
        longitude.reset();
    }

    [[nodiscard]] std::optional<double> Location::getLongitude() const {
        return longitude;
    }
}
