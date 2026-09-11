#pragma once

#include <cstdint>
#include <ctime>
#include <optional>
#include <string>

namespace openjournal {

/// @brief Represents a substance ingestion event in the journal.
/// @details Contains all relevant metadata about a substance ingestion including
/// timing, dosage, route of administration, and optional links to experiences.
class Ingestion {
private:
    std::int64_t id{0};
    std::string substanceName;
    time_t time{0};
    time_t endTime{0};
    time_t creationDate{0};
    std::string administrationRoute;
    double dose{0.0};
    bool doseEstimated{false};
    std::optional<double> estimatedDoseStandardDeviation;
    std::string units;
    std::optional<std::int64_t> experienceId;
    std::string notes;
    std::optional<int> stomachFullness;
    std::optional<std::string> consumerName;
    std::optional<std::int64_t> customUnitId;

public:
    Ingestion() = default;

    [[nodiscard]] std::int64_t getId() const { return id; }
    void setId(std::int64_t value) { id = value; }

    [[nodiscard]] const std::string& getSubstanceName() const { return substanceName; }
    void setSubstanceName(std::string value) { substanceName = std::move(value); }

    [[nodiscard]] time_t getTime() const { return time; }
    void setTime(time_t value) { time = value; }

    [[nodiscard]] time_t getEndTime() const { return endTime; }
    void setEndTime(time_t value) { endTime = value; }

    [[nodiscard]] time_t getCreationDate() const { return creationDate; }
    void setCreationDate(time_t value) { creationDate = value; }

    [[nodiscard]] const std::string& getAdministrationRoute() const { return administrationRoute; }
    void setAdministrationRoute(std::string value) { administrationRoute = std::move(value); }

    [[nodiscard]] double getDose() const { return dose; }
    void setDose(double value) { dose = value; }

    [[nodiscard]] bool isDoseEstimated() const { return doseEstimated; }
    void setDoseEstimated(bool value) { doseEstimated = value; }

    [[nodiscard]] std::optional<double> getEstimatedDoseStandardDeviation() const { return estimatedDoseStandardDeviation; }
    void setEstimatedDoseStandardDeviation(std::optional<double> value) { estimatedDoseStandardDeviation = value; }

    [[nodiscard]] const std::string& getUnits() const { return units; }
    void setUnits(std::string value) { units = std::move(value); }

    [[nodiscard]] std::optional<std::int64_t> getExperienceId() const { return experienceId; }
    void setExperienceId(std::optional<std::int64_t> value) { experienceId = value; }

    [[nodiscard]] const std::string& getNotes() const { return notes; }
    void setNotes(std::string value) { notes = std::move(value); }

    [[nodiscard]] std::optional<int> getStomachFullness() const { return stomachFullness; }
    void setStomachFullness(std::optional<int> value) { stomachFullness = value; }

    [[nodiscard]] std::optional<std::string> getConsumerName() const { return consumerName; }
    void setConsumerName(std::optional<std::string> value) { consumerName = std::move(value); }

    [[nodiscard]] std::optional<std::int64_t> getCustomUnitId() const { return customUnitId; }
    void setCustomUnitId(std::optional<std::int64_t> value) { customUnitId = value; }
};

} // namespace openjournal