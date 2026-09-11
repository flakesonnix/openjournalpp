#include "openjournal/journal/substance.hpp"

namespace openjournal {
    Substance::Substance(const std::int64_t newId, std::string newName):
        id_(newId),
        name_(std::move(newName)) {}

    std::int64_t Substance::getId() const {
        return id_;
    }

    const std::string& Substance::getName() const {
        return name_;
    }

    void Substance::setName(const std::string& newName) {
        name_ = newName;
    }
}
