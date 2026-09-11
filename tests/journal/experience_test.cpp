#include <gtest/gtest.h>

#include <openjournal/journal/experience.hpp>

namespace openjournal {

TEST(ExperienceTest, ConstructorStoresData) {
    Location location("Berlin", 52.5200, 13.4050);

    Experience experience(
        42,
        "My Ketamine",
        "500mg Ketamine",
        1000,
        2000,
        true,
        location
    );

    EXPECT_EQ(experience.getID(), 42);
    EXPECT_EQ(experience.getTitle(), "My Ketamine");
    EXPECT_EQ(experience.getText(), "500mg Ketamine");
    EXPECT_EQ(experience.getCreationDate(), 1000);
    EXPECT_EQ(experience.getSortDate(), 2000);
    EXPECT_TRUE(experience.isFavorite());

    ASSERT_TRUE(experience.getLocation().has_value());
    EXPECT_EQ(experience.getLocation()->getName(), "Berlin");
    EXPECT_DOUBLE_EQ(
        experience.getLocation()->getLatitude().value(),
        52.5200
    );
    EXPECT_DOUBLE_EQ(
        experience.getLocation()->getLongitude().value(),
        13.4050
    );
}

TEST(ExperienceTest, ConstructorWithoutLocation) {
    Experience experience(
        42,
        "My Experience",
        "Something happened",
        1000,
        2000
    );

    EXPECT_FALSE(experience.getLocation().has_value());
    EXPECT_FALSE(experience.isFavorite());
}

TEST(ExperienceTest, GetID) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000
    );

    EXPECT_EQ(experience.getID(), 42);
}

TEST(ExperienceTest, GetTitle) {
    Experience experience(
        42,
        "My Experience",
        "Text",
        1000,
        2000
    );

    EXPECT_EQ(experience.getTitle(), "My Experience");
}

TEST(ExperienceTest, GetText) {
    Experience experience(
        42,
        "Title",
        "My experience text",
        1000,
        2000
    );

    EXPECT_EQ(experience.getText(), "My experience text");
}

TEST(ExperienceTest, GetCreationDate) {
    Experience experience(
        42,
        "Title",
        "Text",
        1234,
        2000
    );

    EXPECT_EQ(experience.getCreationDate(), 1234);
}

TEST(ExperienceTest, GetSortDate) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        5678
    );

    EXPECT_EQ(experience.getSortDate(), 5678);
}

TEST(ExperienceTest, IsFavorite) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000,
        true
    );

    EXPECT_TRUE(experience.isFavorite());
}

TEST(ExperienceTest, SetTitle) {
    Experience experience(
        42,
        "Old Title",
        "Text",
        1000,
        2000
    );

    experience.setTitle("New Title");

    EXPECT_EQ(experience.getTitle(), "New Title");
}

TEST(ExperienceTest, SetText) {
    Experience experience(
        42,
        "Title",
        "Old Text",
        1000,
        2000
    );

    experience.setText("New Text");

    EXPECT_EQ(experience.getText(), "New Text");
}

TEST(ExperienceTest, SetSortDate) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000
    );

    experience.setSortDate(3000);

    EXPECT_EQ(experience.getSortDate(), 3000);
}

TEST(ExperienceTest, SetFavorite) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000
    );

    experience.setFavorite(true);

    EXPECT_TRUE(experience.isFavorite());

    experience.setFavorite(false);

    EXPECT_FALSE(experience.isFavorite());
}

TEST(ExperienceTest, ToggleFavoriteFromFalse) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000,
        false
    );

    experience.toggleFavorite();

    EXPECT_TRUE(experience.isFavorite());
}

TEST(ExperienceTest, ToggleFavoriteFromTrue) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000,
        true
    );

    experience.toggleFavorite();

    EXPECT_FALSE(experience.isFavorite());
}

TEST(ExperienceTest, SetLocation) {
    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000
    );

    Location location("Berlin", 52.5200, 13.4050);

    experience.setLocation(location);

    ASSERT_TRUE(experience.getLocation().has_value());
    EXPECT_EQ(experience.getLocation()->getName(), "Berlin");
}

TEST(ExperienceTest, ClearLocation) {
    Location location("Berlin", 52.5200, 13.4050);

    Experience experience(
        42,
        "Title",
        "Text",
        1000,
        2000,
        false,
        location
    );

    experience.clearLocation();

    EXPECT_FALSE(experience.getLocation().has_value());
}

} // namespace openjournal