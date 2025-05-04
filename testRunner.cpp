#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <utility>

#include "Modules/Config.hpp"
import Food;
import Snake;
import Controller;
import RenderingUtils;
#include <SFML/Graphics.hpp>

class FoodMock : public Food
{
public:
    MOCK_METHOD(int, getRandom, (const int upperLimit), ());
    MOCK_METHOD(void, setPosition, (const int xPos, const int yPos), (override));
    MOCK_METHOD((std::pair<int, int>), getPosition, (), (const, override));

    FoodMock(const int size, int xPos, int yPos)
        :Food(size, xPos, yPos)
    {};
};

class FoodFixture : public testing::Test
{
public:
    Food foodFixture{20, 140, CELL_SIZE/2};
};

class FoodMockFixture : public testing::Test
{
public:
    FoodMock foodMock{20, 140, CELL_SIZE/2};
};

class SnakeFixture : public testing::Test
{
public:
    Snake snake{60, 180, CELL_SIZE};
};

class RenderableMock : public Renderable
{
public:
    RenderableMock() = default;
    MOCK_METHOD(void, updatePosition, (), (override));
    MOCK_METHOD(void, draw, (sf::RenderWindow& window), (const, override));
};

class RenderEngineFixture : public testing::Test
{
public:
    RenderEngine renderEngineFixture{};
};

TEST_F(FoodMockFixture, killTest)
{
    //GIVEN
    EXPECT_CALL(foodMock, getRandom(testing::_))
        .Times(2);
    EXPECT_CALL(foodMock, setPosition(testing::_, testing::_))
        .Times(1);

    //WHEN
    foodMock.kill();
};

TEST_F(FoodFixture, getRandomTest)
{
    //GIVEN
    const int upLimit = 10;
    //WHEN
    const int result = foodFixture.getRandom(upLimit);

    ASSERT_LE(result, upLimit);
    ASSERT_NO_THROW();
}

TEST_F(FoodFixture, getRandomTestException)
{
    ASSERT_THROW(foodFixture.getRandom(-1), std::runtime_error);
}

TEST_F(SnakeFixture, checkFoodAndSnakeCollisionTest)
{
    //GIVEN
    FoodMock foodMock{20, 140, CELL_SIZE/2};
    EXPECT_CALL(foodMock, getPosition())
        .Times(testing::AtLeast(snake.getLength()));
    
    ASSERT_FALSE(snake.checkFoodAndSnakeCollision(foodMock));
}

TEST_F(SnakeFixture, isFoodAteTest)
{
    //GIVEN
    Food food{snake.getPosition().first, snake.getPosition().second, CELL_SIZE/2};
    //WHEN
    //THEN
    ASSERT_TRUE(snake.isFoodAte(food));
}

TEST_F(SnakeFixture, directionChanged)
{
    //GIVEN
    Direction newDirection = Direction::Up;
    //WHEN
    snake.update(newDirection);
    //THEN
    ASSERT_EQ(snake.getDirection(), newDirection);
}

TEST_F(SnakeFixture, directionNotChanged)
{
    //GIVEN
    Direction newDirection = Direction::Left;
    //WHEN
    snake.update(newDirection);
    //THEN
    ASSERT_NE(snake.getDirection(), newDirection);
}

TEST_F(RenderEngineFixture, renderTest)
{
    //GIVEN
    auto mock = std::make_shared<RenderableMock>();
    renderEngineFixture.addEntity(mock);
    EXPECT_CALL(*mock, updatePosition())
        .Times(1);
    EXPECT_CALL(*mock, draw(testing::_))
        .Times(1);
    
    //WHEN
    renderEngineFixture.render();    
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
