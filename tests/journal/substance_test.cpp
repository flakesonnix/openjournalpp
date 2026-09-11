#include <gtest/gtest.h>

#include <openjournal/journal/substance.hpp>

namespace openjournal {

    TEST(SubstanceTest, ConstructorStoresData) {
        constexpr std::int64_t id = 42;
        const std::string name = "Ketamine";

        Substance substance(id, name);

        EXPECT_EQ(substance.getId(), id);
        EXPECT_EQ(substance.getName(), name);
    }

    TEST(SubstanceTest, GetId) {
        Substance substance(42, "Ketamine");

        EXPECT_EQ(substance.getId(), 42);
    }

    TEST(SubstanceTest, GetName) {
        Substance substance(42, "Ketamine");

        EXPECT_EQ(substance.getName(), "Ketamine");
    }

    TEST(SubstanceTest, SetName) {
        Substance substance(42, "Ketamine");

        substance.setName("MDMA");

        EXPECT_EQ(substance.getName(), "MDMA");
    }

} // namespace openjournal