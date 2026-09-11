#pragma once
#include <optional>
#include <string>

namespace openjournal {
    class Location {
    private:
        std::string name;
        std::optional<double> latitude;
        std::optional<double> longitude;

    public:
        Location(
            std::string newName,
            std::optional<double> newLatitude = std::nullopt,
            std::optional<double> newLongitude = std::nullopt);

        [[nodiscard]] std::string getName() const;

        void setName(std::string name);

        void setLatitude(std::optional<double> latitude);
        void setLongitude(std::optional<double> longitude);

        bool hasCoordinates() const;

        void clearCoordinates();

        [[nodiscard]] std::optional<double> getLatitude() const;

        [[nodiscard]] std::optional<double> getLongitude() const;
    };
}
