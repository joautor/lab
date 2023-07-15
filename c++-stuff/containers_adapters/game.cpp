/*
This is similar to "Tower of Hanaoi" game.
The goal of the game is to put all items in stack 1 to stack 3.
initial:
    stack1: 1 2 3 4 5
    stack2:
    stack3:
goal:
    stack1:
    stack2:
    stack3: 1 2 3 4 5

You can only move 1 item at a time.
You cannot place an item on top of an item with higher value

*/


#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <algorithm>


class Game
{
public:
    Game() = default;
    ~Game()
    {
    }

    void setup()
    {
        _isGameEnd = false;
        _moveCounter = 0;

        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::stack<int, std::vector<int>> dummyStack(vec);
        _stack1 = dummyStack; 

        std::vector<int> emptyVec;
        std::stack<int, std::vector<int>> dummyStack2(emptyVec);

        _stack2 = dummyStack2;
        _stack3 = dummyStack2;
    }

    bool moveObject(int source, int destination)
    {
        auto getStack = [=](int id)
        {
            switch(id)
            {
                case 1:
                    return &_stack1;
                case 2:
                    return &_stack2;
                case 3:
                    return &_stack3;
                default:
                    return &_stack1;
            }
        };
        auto srcStack = getStack(source);
        auto destStack = getStack(destination);

        if (!srcStack->empty() && !destStack->empty() && srcStack->top() < destStack->top())
        {
            std::cout << "Invalid move! Cannot put object on top of an object with a higher value." << std::endl;
            return false;
        }
        if (!srcStack->empty())
        {
            destStack->push(srcStack->top());
            srcStack->pop();
        }
        return true;
    }

    void displayStackElements() const
    {
        auto display = [](std::stack<int, std::vector<int>> stk)
        {
            std::stringstream ss;
            while (!stk.empty())
            {
               ss << " " << stk.top();
               stk.pop();
            }
            std::string myStr = ss.str();
            std::reverse(myStr.begin(), myStr.end());
            return myStr;
        };
        std::cout << "Stack1:" << display(_stack1) << std::endl;
        std::cout << "Stack2:" << display(_stack2) << std::endl;
        std::cout << "Stack3:" << display(_stack3) << std::endl;
    }

    void start()
    {
        setup();
        playGame();
    }

    void getUserInputs(int* src, int* dest)
    {
        std::cout << "Enter src and dest: ";
        std::cin >>  *src >> *dest;
    }

    void updateGameState()
    {
        auto isStackDescending = [](std::stack<int, std::vector<int>> stk)
        {
            int temp = stk.top();
            stk.pop();
            while(!stk.empty())
            {
                if (temp < stk.top())
                {
                    return false;
                }
                stk.pop();
            }
            return true;
        };

        if (MAX_STACK_SIZE == _stack3.size() && isStackDescending(_stack3))
        {
            _isGameEnd = true;
        }
        else
        {
            _isGameEnd = false;
        }
    }

    void playGame()
    {
        int srcStack;
        int destStack;

        displayStackElements();

        do
        {
            getUserInputs(&srcStack, &destStack);
        }
        while(!moveObject(srcStack, destStack));

        ++_moveCounter;
        updateGameState();

        if (!isGameEnd())
        {
            playGame();
        }
        else
        {
            displayStackElements();
            std::cout << "Game finished!" << " Total moves made: " << _moveCounter << std::endl;
        }
    }

    bool isGameEnd()
    {
        return _isGameEnd;
    }

private:
    bool _isGameEnd;
    const int MAX_STACK_SIZE = 5;
    int _moveCounter;
    std::stack<int, std::vector<int>> _stack1;
    std::stack<int, std::vector<int>> _stack2;
    std::stack<int, std::vector<int>> _stack3;
};


int main()
{
    Game game;
    game.start();

    return 0;
}
