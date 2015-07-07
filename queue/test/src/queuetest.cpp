/** 
 *  @brief      Generic queue data structure testsuite
 * 
 *  @author     Ashish
 *  @version    1.0
 *  Copyright (C) 2015 Ashish, MIT license
 *  @todo          Add exception checks, misc
 */

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestCase.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/extensions/HelperMacros.h>
 
#include <iostream>
#include <deque>
#include <list>
#include <string>
#include <exception>
#include <stdexcept>

#include "queue.h"
#include "queuetest.h"

void QueueTestCase::setUp() {
}

void QueueTestCase::tearDown() {
}

void QueueTestCase::test_push_and_pop_chars() {
    Queue< char > q_of_chars;

    q_of_chars.push('A');
    q_of_chars.push('B');
    q_of_chars.push('C');

    CPPUNIT_ASSERT('A' == q_of_chars.front());

    q_of_chars.pop();
    CPPUNIT_ASSERT('B' == q_of_chars.front());

    q_of_chars.pop();
    CPPUNIT_ASSERT('C' == q_of_chars.front());
    CPPUNIT_ASSERT('C' == q_of_chars.back());

    q_of_chars.push('Z');
    CPPUNIT_ASSERT('Z' == q_of_chars.back());
}

void QueueTestCase::test_push_and_pop_integers() {
    Queue< int > q_of_ints;

    q_of_ints.push(10);
    q_of_ints.push(20);
    q_of_ints.push(30);

    CPPUNIT_ASSERT(10 == q_of_ints.front());

    q_of_ints.pop();
    CPPUNIT_ASSERT(20 == q_of_ints.front());

    q_of_ints.pop();
    CPPUNIT_ASSERT(30 == q_of_ints.front());
    CPPUNIT_ASSERT(30 == q_of_ints.back());

    q_of_ints.push(90);
    CPPUNIT_ASSERT(90 == q_of_ints.back());
}

void QueueTestCase::test_push_and_pop_strings() {
    Queue< std::string > q_of_strings;

    q_of_strings.push("Red");
    q_of_strings.push("Green");
    q_of_strings.push("Blue");

	CPPUNIT_ASSERT("Red" == q_of_strings.front());
	
	q_of_strings.pop();
    CPPUNIT_ASSERT("Green" == q_of_strings.front());
	
	q_of_strings.pop();
	CPPUNIT_ASSERT("Blue" == q_of_strings.front());
	CPPUNIT_ASSERT("Blue" == q_of_strings.back());
    
	q_of_strings.push("Cyan");
    CPPUNIT_ASSERT("Cyan" == q_of_strings.back());
}

void QueueTestCase::test_push_and_pop_integers_using_list() {
    Queue< int, std::list<int> > q_of_ints;

    q_of_ints.push(10);
    q_of_ints.push(20);
    q_of_ints.push(30);

    CPPUNIT_ASSERT(10 == q_of_ints.front());

    q_of_ints.pop();
    CPPUNIT_ASSERT(20 == q_of_ints.front());

    q_of_ints.pop();
    CPPUNIT_ASSERT(30 == q_of_ints.front());
    CPPUNIT_ASSERT(30 == q_of_ints.back());

    q_of_ints.push(90);
    CPPUNIT_ASSERT(90 == q_of_ints.back());
}

void QueueTestCase::test_equality_using_queue_of_integers() {
    Queue< int > A, B;

    A.push(10);
    A.push(20);
    A.push(30);

    B.push(10);
    B.push(20);
    B.push(30);  /// all are equal

    CPPUNIT_ASSERT(A == B);
}

void QueueTestCase::test_inequality_using_queue_of_integers() {
    Queue< int > A, B;

    A.push(10);
    A.push(20);  /// 20  unequal
    A.push(30);

    B.push(10);
    B.push(50);  /// to 50
    B.push(30);

    CPPUNIT_ASSERT(A != B);
}

void QueueTestCase::test_greater_than_equal_using_queue_of_integers() {
    Queue< int > A, B;

    A.push(10);
    A.push(20);
    A.push(60);  /// 60 is

    B.push(10);
    B.push(20);
    B.push(30);  /// greater than 30 here

    CPPUNIT_ASSERT(A >= B);
}

void QueueTestCase::test_greater_than_using_queue_of_integers() {
    Queue< int > A, B;

    A.push(10);
    A.push(20);
    A.push(60);  /// 60 is

    B.push(10);
    B.push(20);
    B.push(30);  /// greater than 30 here

    CPPUNIT_ASSERT(A > B);
}

void QueueTestCase::test_less_than_equal_using_queue_of_integers() {
    Queue< int > A, B;

    A.push(10);
    A.push(20);
    A.push(30);  /// 30 is

    B.push(10);
    B.push(20);
    B.push(40);  /// less than 40 here

    CPPUNIT_ASSERT(A <= B);
}

void QueueTestCase::test_less_than_using_queue_of_integers() {
    Queue< int > A, B;

    A.push(10);
    A.push(20);
    A.push(30);

    B.push(20);
    B.push(30);
    B.push(40);

    CPPUNIT_ASSERT(A < B);
}

CppUnit::Test *suite() {
    CppUnit::TestFactoryRegistry &registry =
                      CppUnit::TestFactoryRegistry::getRegistry();

    return registry.makeTest();
}

CPPUNIT_TEST_SUITE_REGISTRATION(QueueTestCase);

int main(int argc, char* argv[]) {
    CppUnit::TestResult controller;

    CppUnit::TestResultCollector result;
    controller.addListener(&result);

    CppUnit::BriefTestProgressListener progressListener;
    controller.addListener(&progressListener);

    CppUnit::TextUi::TestRunner runner;
    runner.addTest(suite());  /// Add the top suite to the test runner

    /// Run the test
    runner.run(controller);

    /// Return error code 1 if any tests failed
    return result.wasSuccessful() ? 0 : 1;
}
