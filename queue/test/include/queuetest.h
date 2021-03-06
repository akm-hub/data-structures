/** 
 *  @brief      Generic queue data structure testsuite header
 * 
 *  @author     Ashish
 *  @version    1.0
 *  Copyright (C) 2015 Ashish, MIT license
 * 
 */

#ifndef _INCLUDE_QUEUETEST_H_
#define _INCLUDE_QUEUETEST_H_

class QueueTestCase : public CppUnit::TestCase {
 private:
    CPPUNIT_TEST_SUITE(QueueTestCase);
    CPPUNIT_TEST(test_push_and_pop_chars);
    CPPUNIT_TEST(test_push_and_pop_integers);
    CPPUNIT_TEST(test_push_and_pop_strings);
    CPPUNIT_TEST(test_push_and_pop_integers_using_list);
    CPPUNIT_TEST(test_equality_using_queue_of_integers);
    CPPUNIT_TEST(test_inequality_using_queue_of_integers);
    CPPUNIT_TEST(test_greater_than_equal_using_queue_of_integers);
    CPPUNIT_TEST(test_greater_than_using_queue_of_integers);
    CPPUNIT_TEST(test_less_than_equal_using_queue_of_integers);
    CPPUNIT_TEST(test_less_than_using_queue_of_integers);
    CPPUNIT_TEST_SUITE_END();

    /// method to test the push and pop of chars
    void test_push_and_pop_chars();

    /// method to test the push and pop of integers
    void test_push_and_pop_integers();

    /// method to test the push and pop of strings
    void test_push_and_pop_strings();

    /// method to test the push and pop of integers, using list
    void test_push_and_pop_integers_using_list();

    /// methods to test the relational operators on a stack of integers
    void test_equality_using_queue_of_integers();
    void test_inequality_using_queue_of_integers();
    void test_greater_than_equal_using_queue_of_integers();
    void test_greater_than_using_queue_of_integers();
    void test_less_than_equal_using_queue_of_integers();
    void test_less_than_using_queue_of_integers();

 public:
    void setUp();
    void tearDown();
};

#endif
