/*
 * testMyAlgo.h
 * gtest header for MyAlgo classes
 */

#include <algorithm>
#include <iostream>

#include "Recursion.h"
#include "gtest/gtest.h"
#include "ArrayQueue.h"
#include "MatchBracket.h"
#include "ArrayPairSum.h"
#include "MyBst.h"

class RecursionTest : public ::testing::Test {
};

TEST_F(RecursionTest, FibPowTest) {
	EXPECT_EQ(1U, recursive_fib(1));
	EXPECT_EQ(1U, recursive_fib(2));
	EXPECT_EQ(2U, recursive_fib(3));
	EXPECT_EQ(5U, recursive_fib(5));
	EXPECT_EQ(8U, recursive_fib(6));

	EXPECT_EQ(1U, iterative_fib(1));
	EXPECT_EQ(1U, iterative_fib(2));
	EXPECT_EQ(2U, iterative_fib(3));
	EXPECT_EQ(5U, iterative_fib(5));
	EXPECT_EQ(8U, iterative_fib(6));

    EXPECT_EQ(1, recursive_pow(1, 4)); 
    EXPECT_EQ(1, recursive_pow(2, 0)); 
    EXPECT_EQ(1, recursive_pow(1, 0)); 
    EXPECT_EQ(0, recursive_pow(0, 4)); 
    EXPECT_EQ(81, recursive_pow(3, 4)); 
    EXPECT_EQ(1024, recursive_pow(2, 10)); 
    EXPECT_EQ(125, recursive_pow(5, 3)); 
}

// The fixture for testing ArrayQueue classes.
class ArrayQueueTest : public ::testing::Test {
    protected:
        ArrayQueueTest(){}
        virtual ~ArrayQueueTest(){}

        virtual void SetUp(){}
        virtual void TearDown(){}
        // Objects declared here can be used by all tests in the test case for ArrayQueue.
        ArrayQueue aq;
};

TEST_F(ArrayQueueTest,  TestEnDeQueue) {
    EXPECT_EQ(0U, aq.size());
    EXPECT_TRUE(aq.enqueue(1));
    EXPECT_TRUE(aq.enqueue(2));
    EXPECT_TRUE(aq.enqueue(3));
    EXPECT_TRUE(aq.enqueue(4));
    EXPECT_FALSE(aq.enqueue(5));
    EXPECT_TRUE(aq.dequeue());
    EXPECT_EQ(3U, aq.size());
    aq.print();
    EXPECT_EQ(2, aq.front());
    EXPECT_TRUE(aq.enqueue(5));
    EXPECT_TRUE(aq.dequeue());
    EXPECT_TRUE(aq.dequeue());
    EXPECT_TRUE(aq.dequeue());
    EXPECT_TRUE(aq.dequeue());
    EXPECT_FALSE(aq.dequeue());
    EXPECT_EQ(-1, aq.front());
    aq.print();
}

TEST_F(ArrayQueueTest,  TestFlush) {
    EXPECT_TRUE(aq.enqueue(1));
    EXPECT_TRUE(aq.enqueue(2));
    EXPECT_TRUE(aq.enqueue(3));
    EXPECT_TRUE(aq.enqueue(4));
    EXPECT_FALSE(aq.enqueue(5));
    EXPECT_TRUE(aq.dequeue());
    EXPECT_EQ(3U, aq.size());
    EXPECT_TRUE(aq.enqueue(5));
    aq.flush();
    EXPECT_EQ(0U, aq.size());
    aq.print();
}

class MatchBracketTest : public ::testing::Test {
    protected:
        MatchBracket mb;
};

TEST_F(MatchBracketTest,  TestMatch) {
    EXPECT_TRUE(mb.match(""));
    EXPECT_TRUE(mb.match("a"));
    EXPECT_TRUE(mb.match("()"));
    EXPECT_FALSE(mb.match(")"));
    EXPECT_TRUE(mb.match("aa(<7>)"));
    EXPECT_TRUE(mb.match("[]aa(<7>)"));
    EXPECT_TRUE(mb.match("{{{aa}(<7>)}[ddf]}"));
    EXPECT_FALSE(mb.match("aa(<[7>)]"));
}

class ArrayPairSumTest : public ::testing::Test {
    protected:
        std::vector<uint32_t> input1 = {1,11,4,3};
        std::vector<uint32_t> input2 = {1,2,0,4,5,11,4,3};
        std::vector<uint32_t> input3 = {1,2,0,4,5,11,4,3,3,3};
};

TEST_F(ArrayPairSumTest,  BasicTest) {
    EXPECT_EQ(0U, two_sum(input1,6));
    EXPECT_EQ(3U, two_sum(input2,6));
    EXPECT_EQ(6U, two_sum(input3,6));
}

class MyBstTest : public ::testing::Test {
};

TEST_F(MyBstTest, BasicBstTest) {
    MyBst bst(4);
    ASSERT_EQ(1U, bst.size());
    bst.insert(1);
    bst.insert(3);
    bst.insert(6);
    bst.insert(-1);
    bst.insert(8);
    bst.insert(5);
    bst.insert(2);
    bst.insert(7);
    EXPECT_EQ(9U, bst.size());
    
    bst.inorder();
    bst.preorder();
    bst.postorder();
    bst.bfs();
    bst.levelorder();

    std::vector<int> ser = bst.serialize();
    bst.deserialize(ser);
    bst.postorder();
    EXPECT_EQ(9U, bst.size());
    bst.toDLL();
    bst.clear();
    EXPECT_EQ(0U, bst.size());
}

