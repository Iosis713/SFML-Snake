#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Headers/Food.hpp"
#include "Headers/Global.hpp"

class FoodMock : public Food
{
public:
    MOCK_METHOD(int, getRandom, (const int upperLimit), (override));
    MOCK_METHOD(void, setIsAlive, (bool life), (override));
    MOCK_METHOD(void, setPosition, (const int& xPos, const int& yPos), (override));

    FoodMock(const int size, int xPos, int yPos)
        :Food(size, xPos, yPos)
    {};
};

class FoodMockFixture : public testing::Test
{
public:
    
    FoodMock foodMock{20, 140, CELL_SIZE/2};
};

TEST_F(FoodMockFixture, killTest)
{
    //GIVEN
    EXPECT_CALL(foodMock, setIsAlive(testing::_))
        .Times(2);
    EXPECT_CALL(foodMock, getRandom(testing::_))
        .Times(2);
    EXPECT_CALL(foodMock, setPosition(testing::_, testing::_))
        .Times(1);

    foodMock.kill();
};

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}