#include <gtest/gtest.h>

#include <openjournal/journal/location.hpp>

namespace openjournal {

TEST(LocationTest, ConstructorStoresName) {
    Location location("Berlin");

    EXPECT_EQ(location.getName(), "Berlin");
}

TEST(LocationTest, ConstructorStoresCoordinates) {
    Location location("Berlin", 52.5200, 13.4050);

    ASSERT_TRUE(location.getLatitude().has_value());
    ASSERT_TRUE(location.getLongitude().has_value());

    EXPECT_DOUBLE_EQ(location.getLatitude().value(), 52.5200);
    EXPECT_DOUBLE_EQ(location.getLongitude().value(), 13.4050);
}

TEST(LocationTest, CoordinatesAreEmptyByDefault) {
    Location location("Berlin");

    EXPECT_FALSE(location.getLatitude().has_value());
    EXPECT_FALSE(location.getLongitude().has_value());
    EXPECT_FALSE(location.hasCoordinates());
}

TEST(LocationTest, HasCoordinatesReturnsTrueWhenBothCoordinatesExist) {
    Location location("Berlin", 52.5200, 13.4050);

    EXPECT_TRUE(location.hasCoordinates());
}

TEST(LocationTest, HasCoordinatesReturnsFalseWhenOnlyLatitudeExists) {
    Location location("Berlin", 52.5200, std::nullopt);

    EXPECT_FALSE(location.hasCoordinates());
}

TEST(LocationTest, HasCoordinatesReturnsFalseWhenOnlyLongitudeExists) {
    Location location("Berlin", std::nullopt, 13.4050);

    EXPECT_FALSE(location.hasCoordinates());
}

TEST(LocationTest, SetNameChangesName) {
    Location location("Berlin");

    location.setName("Leipzig");

    EXPECT_EQ(location.getName(), "Leipzig");
}

TEST(LocationTest, SetLatitudeChangesLatitude) {
    Location location("Berlin");

    location.setLatitude(52.5200);

    ASSERT_TRUE(location.getLatitude().has_value());
    EXPECT_DOUBLE_EQ(location.getLatitude().value(), 52.5200);
}

TEST(LocationTest, SetLongitudeChangesLongitude) {
    Location location("Berlin");

    location.setLongitude(13.4050);

    ASSERT_TRUE(location.getLongitude().has_value());
    EXPECT_DOUBLE_EQ(location.getLongitude().value(), 13.4050);
}

TEST(LocationTest, SetCoordinatesCreatesCoordinates) {
    Location location("Berlin");

    location.setLatitude(52.5200);
    location.setLongitude(13.4050);

    EXPECT_TRUE(location.hasCoordinates());
}

TEST(LocationTest, ClearCoordinatesRemovesCoordinates) {
    Location location("Berlin", 52.5200, 13.4050);

    location.clearCoordinates();

    EXPECT_FALSE(location.getLatitude().has_value());
    EXPECT_FALSE(location.getLongitude().has_value());
    EXPECT_FALSE(location.hasCoordinates());
}

TEST(LocationTest, CanClearOnlyLatitude) {
    Location location("Berlin", 52.5200, 13.4050);

    location.setLatitude(std::nullopt);

    EXPECT_FALSE(location.getLatitude().has_value());
    EXPECT_TRUE(location.getLongitude().has_value());
    EXPECT_FALSE(location.hasCoordinates());
}

TEST(LocationTest, CanClearOnlyLongitude) {
    Location location("Berlin", 52.5200, 13.4050);

    location.setLongitude(std::nullopt);

    EXPECT_TRUE(location.getLatitude().has_value());
    EXPECT_FALSE(location.getLongitude().has_value());
    EXPECT_FALSE(location.hasCoordinates());
}

} // namespace openjournal