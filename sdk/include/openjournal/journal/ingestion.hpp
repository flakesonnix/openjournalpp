#pragma once

#include <cstdint>
#include <ctime>
#include <optional>
#include <string>

namespace openjournal {

class Ingestion {
public:
    Ingestion(
        std::int64_t newId,
        std::int64_t newSubstanceId,
        time_t newTime,
        std::optional<time_t> newEndTime,
        time_t newCreationDate,
        std::string newAdministrationRoute,
        double newDose,
        bool newDoseEstimated = false,
        std::optional<double> newEstimatedDoseStandardDeviation = std::nullopt,
        std::string newUnits = {},
        std::optional<std::int64_t> newExperienceId = std::nullopt,
        std::string newNotes = {},
        std::optional<int> newStomachFullness = std::nullopt,
        std::optional<std::string> newConsumerName = std::nullopt,
        std::optional<std::int64_t> newCustomUnitId = std::nullopt
    );

    [[nodiscard]] std::int64_t getId() const;
    [[nodiscard]] std::int64_t getSubstanceId() const;
    [[nodiscard]] time_t getTime() const;
    [[nodiscard]] std::optional<time_t> getEndTime() const;
    [[nodiscard]] time_t getCreationDate() const;
    [[nodiscard]] const std::string& getAdministrationRoute() const;
    [[nodiscard]] double getDose() const;
    [[nodiscard]] bool isDoseEstimated() const;
    [[nodiscard]] std::optional<double> getEstimatedDoseStandardDeviation() const;
    [[nodiscard]] const std::string& getUnits() const;
    [[nodiscard]] std::optional<std::int64_t> getExperienceId() const;
    [[nodiscard]] const std::string& getNotes() const;
    [[nodiscard]] std::optional<int> getStomachFullness() const;
    [[nodiscard]] std::optional<std::string> getConsumerName() const;
    [[nodiscard]] std::optional<std::int64_t> getCustomUnitId() const;

    void setSubstanceId(std::int64_t newSubstanceId);
    void setTime(time_t newTime);
    void setEndTime(std::optional<time_t> newEndTime);
    void setAdministrationRoute(
        const std::string& newAdministrationRoute
    );
    void setDose(double newDose);
    void setDoseEstimated(bool newDoseEstimated);
    void setEstimatedDoseStandardDeviation(
        std::optional<double> newEstimatedDoseStandardDeviation
    );
    void setUnits(const std::string& newUnits);
    void setExperienceId(
        std::optional<std::int64_t> newExperienceId
    );
    void setNotes(const std::string& newNotes);
    void setStomachFullness(
        std::optional<int> newStomachFullness
    );
    void setConsumerName(
        std::optional<std::string> newConsumerName
    );
    void setCustomUnitId(
        std::optional<std::int64_t> newCustomUnitId
    );

private:
    std::int64_t id_;
    std::int64_t substanceId_;
    time_t time_;
    std::optional<time_t> endTime_;
    time_t creationDate_;
    std::string administrationRoute_;
    double dose_;
    bool doseEstimated_;
    std::optional<double> estimatedDoseStandardDeviation_;
    std::string units_;
    std::optional<std::int64_t> experienceId_;
    std::string notes_;
    std::optional<int> stomachFullness_;
    std::optional<std::string> consumerName_;
    std::optional<std::int64_t> customUnitId_;
};

} // namespace openjournal