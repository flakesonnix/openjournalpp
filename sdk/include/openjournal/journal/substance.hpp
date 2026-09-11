#pragma once
#include <cstdint>
#include <string>

namespace openjournal {
    class Substance {
    private:
        std::int64_t id_;
        std::string name_;
    public:
        Substance(std::int64_t newId, std::string newName);
        std::int64_t getId() const;
        const std::string& getName() const;
        void setName(const std::string& newName);
    };
}
