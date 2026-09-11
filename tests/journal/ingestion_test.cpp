#include <gtest/gtest.h>

#include <openjournal/journal/ingestion.hpp>

namespace openjournal {

TEST(IngestionTest, ConstructorStoresData) {
    constexpr std::int64_t id = 42;
    constexpr std::int64_t substanceId = 7;
    constexpr time_t time = 1000;
    constexpr std::optional<time_t> endTime = 2000;
    constexpr time_t creationDate = 3000;
    const std::string administrationRoute = "nasal";
    constexpr double dose = 500.0;
    constexpr bool doseEstimated = true;
    constexpr std::optional<double> estimatedDoseStandardDeviation = 25.0;
    const std::string units = "mg";
    constexpr std::optional<std::int64_t> experienceId = 123;
    const std::string notes = "Test ingestion";
    constexpr std::optional<int> stomachFullness = 2;
    const std::optional<std::string> consumerName = "Lucy";
    constexpr std::optional<std::int64_t> customUnitId = 456;

    Ingestion ingestion(
        id,
        substanceId,
        time,
        endTime,
        creationDate,
        administrationRoute,
        dose,
        doseEstimated,
        estimatedDoseStandardDeviation,
        units,
        experienceId,
        notes,
        stomachFullness,
        consumerName,
        customUnitId
    );

    EXPECT_EQ(ingestion.getId(), id);
    EXPECT_EQ(ingestion.getSubstanceId(), substanceId);
    EXPECT_EQ(ingestion.getTime(), time);
    EXPECT_EQ(ingestion.getEndTime(), endTime);
    EXPECT_EQ(ingestion.getCreationDate(), creationDate);
    EXPECT_EQ(ingestion.getAdministrationRoute(), administrationRoute);
    EXPECT_DOUBLE_EQ(ingestion.getDose(), dose);
    EXPECT_EQ(ingestion.isDoseEstimated(), doseEstimated);
    EXPECT_EQ(
        ingestion.getEstimatedDoseStandardDeviation(),
        estimatedDoseStandardDeviation
    );
    EXPECT_EQ(ingestion.getUnits(), units);
    EXPECT_EQ(ingestion.getExperienceId(), experienceId);
    EXPECT_EQ(ingestion.getNotes(), notes);
    EXPECT_EQ(ingestion.getStomachFullness(), stomachFullness);
    EXPECT_EQ(ingestion.getConsumerName(), consumerName);
    EXPECT_EQ(ingestion.getCustomUnitId(), customUnitId);
}

TEST(IngestionTest, ConstructorUsesOptionalDefaults) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    EXPECT_EQ(ingestion.getId(), 42);
    EXPECT_EQ(ingestion.getSubstanceId(), 7);
    EXPECT_EQ(ingestion.getTime(), 1000);
    EXPECT_FALSE(ingestion.getEndTime().has_value());
    EXPECT_EQ(ingestion.getCreationDate(), 2000);
    EXPECT_EQ(ingestion.getAdministrationRoute(), "nasal");
    EXPECT_DOUBLE_EQ(ingestion.getDose(), 500.0);
    EXPECT_FALSE(ingestion.isDoseEstimated());
    EXPECT_FALSE(
        ingestion.getEstimatedDoseStandardDeviation().has_value()
    );
    EXPECT_TRUE(ingestion.getUnits().empty());
    EXPECT_FALSE(ingestion.getExperienceId().has_value());
    EXPECT_TRUE(ingestion.getNotes().empty());
    EXPECT_FALSE(ingestion.getStomachFullness().has_value());
    EXPECT_FALSE(ingestion.getConsumerName().has_value());
    EXPECT_FALSE(ingestion.getCustomUnitId().has_value());
}

TEST(IngestionTest, GetId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    EXPECT_EQ(ingestion.getId(), 42);
}

TEST(IngestionTest, GetSubstanceId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    EXPECT_EQ(ingestion.getSubstanceId(), 7);
}

TEST(IngestionTest, GetTime) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    EXPECT_EQ(ingestion.getTime(), 1000);
}

TEST(IngestionTest, GetEndTime) {
    Ingestion ingestion(
        42,
        7,
        1000,
        2000,
        3000,
        "nasal",
        500.0
    );

    ASSERT_TRUE(ingestion.getEndTime().has_value());
    EXPECT_EQ(ingestion.getEndTime().value(), 2000);
}

TEST(IngestionTest, GetCreationDate) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    EXPECT_EQ(ingestion.getCreationDate(), 2000);
}

TEST(IngestionTest, GetAdministrationRoute) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    EXPECT_EQ(ingestion.getAdministrationRoute(), "nasal");
}

TEST(IngestionTest, GetDose) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    EXPECT_DOUBLE_EQ(ingestion.getDose(), 500.0);
}

TEST(IngestionTest, IsDoseEstimated) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        true
    );

    EXPECT_TRUE(ingestion.isDoseEstimated());
}

TEST(IngestionTest, GetEstimatedDoseStandardDeviation) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        true,
        25.0
    );

    ASSERT_TRUE(
        ingestion.getEstimatedDoseStandardDeviation().has_value()
    );
    EXPECT_DOUBLE_EQ(
        ingestion.getEstimatedDoseStandardDeviation().value(),
        25.0
    );
}

TEST(IngestionTest, GetUnits) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        "mg"
    );

    EXPECT_EQ(ingestion.getUnits(), "mg");
}

TEST(IngestionTest, GetExperienceId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        "mg",
        123
    );

    ASSERT_TRUE(ingestion.getExperienceId().has_value());
    EXPECT_EQ(ingestion.getExperienceId().value(), 123);
}

TEST(IngestionTest, GetNotes) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        "mg",
        std::nullopt,
        "Test ingestion"
    );

    EXPECT_EQ(ingestion.getNotes(), "Test ingestion");
}

TEST(IngestionTest, GetStomachFullness) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        "mg",
        std::nullopt,
        {},
        2
    );

    ASSERT_TRUE(ingestion.getStomachFullness().has_value());
    EXPECT_EQ(ingestion.getStomachFullness().value(), 2);
}

TEST(IngestionTest, GetConsumerName) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        "mg",
        std::nullopt,
        {},
        std::nullopt,
        "Lucy"
    );

    ASSERT_TRUE(ingestion.getConsumerName().has_value());
    EXPECT_EQ(ingestion.getConsumerName().value(), "Lucy");
}

TEST(IngestionTest, GetCustomUnitId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        "mg",
        std::nullopt,
        {},
        std::nullopt,
        std::nullopt,
        456
    );

    ASSERT_TRUE(ingestion.getCustomUnitId().has_value());
    EXPECT_EQ(ingestion.getCustomUnitId().value(), 456);
}

TEST(IngestionTest, SetSubstanceId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setSubstanceId(99);

    EXPECT_EQ(ingestion.getSubstanceId(), 99);
}

TEST(IngestionTest, SetTime) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setTime(5000);

    EXPECT_EQ(ingestion.getTime(), 5000);
}

TEST(IngestionTest, SetEndTime) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setEndTime(3000);

    ASSERT_TRUE(ingestion.getEndTime().has_value());
    EXPECT_EQ(ingestion.getEndTime().value(), 3000);
}

TEST(IngestionTest, ClearEndTime) {
    Ingestion ingestion(
        42,
        7,
        1000,
        2000,
        3000,
        "nasal",
        500.0
    );

    ingestion.setEndTime(std::nullopt);

    EXPECT_FALSE(ingestion.getEndTime().has_value());
}

TEST(IngestionTest, SetAdministrationRoute) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setAdministrationRoute("oral");

    EXPECT_EQ(ingestion.getAdministrationRoute(), "oral");
}

TEST(IngestionTest, SetDose) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setDose(750.0);

    EXPECT_DOUBLE_EQ(ingestion.getDose(), 750.0);
}

TEST(IngestionTest, SetDoseEstimated) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setDoseEstimated(true);

    EXPECT_TRUE(ingestion.isDoseEstimated());
}

TEST(IngestionTest, SetEstimatedDoseStandardDeviation) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setEstimatedDoseStandardDeviation(30.0);

    ASSERT_TRUE(
        ingestion.getEstimatedDoseStandardDeviation().has_value()
    );
    EXPECT_DOUBLE_EQ(
        ingestion.getEstimatedDoseStandardDeviation().value(),
        30.0
    );
}

TEST(IngestionTest, ClearEstimatedDoseStandardDeviation) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        true,
        25.0
    );

    ingestion.setEstimatedDoseStandardDeviation(std::nullopt);

    EXPECT_FALSE(
        ingestion.getEstimatedDoseStandardDeviation().has_value()
    );
}

TEST(IngestionTest, SetUnits) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setUnits("g");

    EXPECT_EQ(ingestion.getUnits(), "g");
}

TEST(IngestionTest, SetExperienceId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setExperienceId(123);

    ASSERT_TRUE(ingestion.getExperienceId().has_value());
    EXPECT_EQ(ingestion.getExperienceId().value(), 123);
}

TEST(IngestionTest, ClearExperienceId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        "mg",
        123
    );

    ingestion.setExperienceId(std::nullopt);

    EXPECT_FALSE(ingestion.getExperienceId().has_value());
}

TEST(IngestionTest, SetNotes) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setNotes("Changed notes");

    EXPECT_EQ(ingestion.getNotes(), "Changed notes");
}

TEST(IngestionTest, SetStomachFullness) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setStomachFullness(3);

    ASSERT_TRUE(ingestion.getStomachFullness().has_value());
    EXPECT_EQ(ingestion.getStomachFullness().value(), 3);
}

TEST(IngestionTest, ClearStomachFullness) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        {},
        std::nullopt,
        {},
        2
    );

    ingestion.setStomachFullness(std::nullopt);

    EXPECT_FALSE(ingestion.getStomachFullness().has_value());
}

TEST(IngestionTest, SetConsumerName) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setConsumerName("Lucy");

    ASSERT_TRUE(ingestion.getConsumerName().has_value());
    EXPECT_EQ(ingestion.getConsumerName().value(), "Lucy");
}

TEST(IngestionTest, ClearConsumerName) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        {},
        std::nullopt,
        {},
        std::nullopt,
        std::string("Lucy")
    );

    ingestion.setConsumerName(std::nullopt);

    EXPECT_FALSE(ingestion.getConsumerName().has_value());
}

TEST(IngestionTest, SetCustomUnitId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0
    );

    ingestion.setCustomUnitId(456);

    ASSERT_TRUE(ingestion.getCustomUnitId().has_value());
    EXPECT_EQ(ingestion.getCustomUnitId().value(), 456);
}

TEST(IngestionTest, ClearCustomUnitId) {
    Ingestion ingestion(
        42,
        7,
        1000,
        std::nullopt,
        2000,
        "nasal",
        500.0,
        false,
        std::nullopt,
        {},
        std::nullopt,
        {},
        std::nullopt,
        std::nullopt,
        456
    );

    ingestion.setCustomUnitId(std::nullopt);

    EXPECT_FALSE(ingestion.getCustomUnitId().has_value());
}

} // namespace openjournal