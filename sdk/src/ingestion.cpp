#include <openjournal/journal/ingestion.hpp>

#include <utility>

namespace openjournal {

Ingestion::Ingestion(
    std::int64_t newId,
    std::int64_t newSubstanceId,
    time_t newTime,
    std::optional<time_t> newEndTime,
    time_t newCreationDate,
    std::string newAdministrationRoute,
    double newDose,
    bool newDoseEstimated,
    std::optional<double> newEstimatedDoseStandardDeviation,
    std::string newUnits,
    std::optional<std::int64_t> newExperienceId,
    std::string newNotes,
    std::optional<int> newStomachFullness,
    std::optional<std::string> newConsumerName,
    std::optional<std::int64_t> newCustomUnitId
)
    : id_(newId),
      substanceId_(newSubstanceId),
      time_(newTime),
      endTime_(newEndTime),
      creationDate_(newCreationDate),
      administrationRoute_(std::move(newAdministrationRoute)),
      dose_(newDose),
      doseEstimated_(newDoseEstimated),
      estimatedDoseStandardDeviation_(newEstimatedDoseStandardDeviation),
      units_(std::move(newUnits)),
      experienceId_(newExperienceId),
      notes_(std::move(newNotes)),
      stomachFullness_(newStomachFullness),
      consumerName_(std::move(newConsumerName)),
      customUnitId_(newCustomUnitId) {
}

std::int64_t Ingestion::getId() const {
    return id_;
}

std::int64_t Ingestion::getSubstanceId() const {
    return substanceId_;
}

time_t Ingestion::getTime() const {
    return time_;
}

std::optional<time_t> Ingestion::getEndTime() const {
    return endTime_;
}

time_t Ingestion::getCreationDate() const {
    return creationDate_;
}

const std::string& Ingestion::getAdministrationRoute() const {
    return administrationRoute_;
}

double Ingestion::getDose() const {
    return dose_;
}

bool Ingestion::isDoseEstimated() const {
    return doseEstimated_;
}

std::optional<double> Ingestion::getEstimatedDoseStandardDeviation() const {
    return estimatedDoseStandardDeviation_;
}

const std::string& Ingestion::getUnits() const {
    return units_;
}

std::optional<std::int64_t> Ingestion::getExperienceId() const {
    return experienceId_;
}

const std::string& Ingestion::getNotes() const {
    return notes_;
}

std::optional<int> Ingestion::getStomachFullness() const {
    return stomachFullness_;
}

std::optional<std::string> Ingestion::getConsumerName() const {
    return consumerName_;
}

std::optional<std::int64_t> Ingestion::getCustomUnitId() const {
    return customUnitId_;
}

void Ingestion::setSubstanceId(std::int64_t newSubstanceId) {
    substanceId_ = newSubstanceId;
}

void Ingestion::setTime(time_t newTime) {
    time_ = newTime;
}

void Ingestion::setEndTime(std::optional<time_t> newEndTime) {
    endTime_ = newEndTime;
}

void Ingestion::setAdministrationRoute(
    const std::string& newAdministrationRoute
) {
    administrationRoute_ = newAdministrationRoute;
}

void Ingestion::setDose(double newDose) {
    dose_ = newDose;
}

void Ingestion::setDoseEstimated(bool newDoseEstimated) {
    doseEstimated_ = newDoseEstimated;
}

void Ingestion::setEstimatedDoseStandardDeviation(
    std::optional<double> newEstimatedDoseStandardDeviation
) {
    estimatedDoseStandardDeviation_ = newEstimatedDoseStandardDeviation;
}

void Ingestion::setUnits(const std::string& newUnits) {
    units_ = newUnits;
}

void Ingestion::setExperienceId(
    std::optional<std::int64_t> newExperienceId
) {
    experienceId_ = newExperienceId;
}

void Ingestion::setNotes(const std::string& newNotes) {
    notes_ = newNotes;
}

void Ingestion::setStomachFullness(
    std::optional<int> newStomachFullness
) {
    stomachFullness_ = newStomachFullness;
}

void Ingestion::setConsumerName(
    std::optional<std::string> newConsumerName
) {
    consumerName_ = std::move(newConsumerName);
}

void Ingestion::setCustomUnitId(
    std::optional<std::int64_t> newCustomUnitId
) {
    customUnitId_ = newCustomUnitId;
}

} // namespace openjournal