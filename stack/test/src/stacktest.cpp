/** 
 *  @brief      Generic stack data structure testsuite
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
#include <vector>
#include <deque>
#include <list>
#include <string>
#include <exception>
#include <stdexcept>

#include "stack.h"
#include "stacktest.h"

void StackTestCase::setUp() {
}

void StackTestCase::tearDown() {
}

void StackTestCase::test_push_and_pop_chars() {
    Stack< char > stack_of_chars;

    stack_of_chars.push('A');
    stack_of_chars.push('B');
    stack_of_chars.push('C');

    CPPUNIT_ASSERT('C' == stack_of_chars.top());

    stack_of_chars.pop();
    CPPUNIT_ASSERT('B' == stack_of_chars.top());

    stack_of_chars.pop();
    CPPUNIT_ASSERT('A' == stack_of_chars.top());

    stack_of_chars.push('Z');
    CPPUNIT_ASSERT('Z' == stack_of_chars.top());
}

void StackTestCase::test_push_and_pop_integers() {
    Stack< int > stack_of_ints;

    stack_of_ints.push(10);
    stack_of_ints.push(20);
    stack_of_ints.push(30);

    CPPUNIT_ASSERT(30 == stack_of_ints.top());

    stack_of_ints.pop();
    CPPUNIT_ASSERT(20 == stack_of_ints.top());

    stack_of_ints.pop();
    CPPUNIT_ASSERT(10 == stack_of_ints.top());

    stack_of_ints.push(90);
    CPPUNIT_ASSERT(90 == stack_of_ints.top());
}

void StackTestCase::test_push_and_pop_strings() {
    Stack< std::string > stack_of_strings;

    stack_of_strings.push("Red");
    stack_of_strings.push("Green");
    stack_of_strings.push("Blue");

    CPPUNIT_ASSERT("Blue" == stack_of_strings.top());

    stack_of_strings.pop();
    CPPUNIT_ASSERT("Green" == stack_of_strings.top());

    stack_of_strings.pop();
    CPPUNIT_ASSERT("Red" == stack_of_strings.top());

    stack_of_strings.push("Cyan");
    CPPUNIT_ASSERT("Cyan" == stack_of_strings.top());
}

void StackTestCase::test_push_and_pop_integers_using_vectors() {
    Stack< int, std::vector<int> > stack_of_ints;

    stack_of_ints.push(10);
    stack_of_ints.push(20);
    stack_of_ints.push(30);

    CPPUNIT_ASSERT(30 == stack_of_ints.top());

    stack_of_ints.pop();
    CPPUNIT_ASSERT(20 == stack_of_ints.top());

    stack_of_ints.pop();
    CPPUNIT_ASSERT(10 == stack_of_ints.top());

    stack_of_ints.push(90);
    CPPUNIT_ASSERT(90 == stack_of_ints.top());
}

void StackTestCase::test_equality_using_stack_of_integers() {
    Stack< int > stack_A, stack_B;

    stack_A.push(10);
    stack_A.push(20);
    stack_A.push(30);

    stack_B.push(10);
    stack_B.push(20);
    stack_B.push(30);  /// all are equal

    CPPUNIT_ASSERT(stack_A == stack_B);
}

void StackTestCase::test_inequality_using_stack_of_integers() {
    Stack< int > stack_A, stack_B;

    stack_A.push(10);
    stack_A.push(20);  /// 20  unequal
    stack_A.push(30);

    stack_B.push(10);
    stack_B.push(50);  /// to 50
    stack_B.push(30);

    CPPUNIT_ASSERT(stack_A != stack_B);
}

void StackTestCase::test_greater_than_equal_using_stack_of_integers() {
    Stack< int > stack_A, stack_B;

    stack_A.push(10);
    stack_A.push(20);
    stack_A.push(60);  /// 60 is

    stack_B.push(10);
    stack_B.push(20);
    stack_B.push(30);  /// greater than 30 here

    CPPUNIT_ASSERT(stack_A >= stack_B);

    stack_B.pop();
    stack_B.push(60);  /// or equal to 60 here

    CPPUNIT_ASSERT(stack_A >= stack_B);
}

void StackTestCase::test_greater_than_using_stack_of_integers() {
    Stack< int > stack_A, stack_B;

    stack_A.push(10);
    stack_A.push(20);
    stack_A.push(60);  /// 60 is

    stack_B.push(10);
    stack_B.push(20);
    stack_B.push(30);  /// greater than 30 here

    CPPUNIT_ASSERT(stack_A > stack_B);
}

void StackTestCase::test_less_than_equal_using_stack_of_integers() {
    Stack< int > stack_A, stack_B;

    stack_A.push(10);
    stack_A.push(20);
    stack_A.push(30);  /// 30 is

    stack_B.push(10);
    stack_B.push(20);
    stack_B.push(40);  /// less than 40 here

    CPPUNIT_ASSERT(stack_A <= stack_B);

    stack_B.pop();
    stack_B.push(30);  /// or equal to 30 here

    CPPUNIT_ASSERT(stack_A <= stack_B);
}

void StackTestCase::test_less_than_using_stack_of_integers() {
    Stack< int > stack_A, stack_B;

    stack_A.push(10);
    stack_A.push(20);
    stack_A.push(30);

    stack_B.push(20);
    stack_B.push(30);
    stack_B.push(40);

    CPPUNIT_ASSERT(stack_A < stack_B);
}

CppUnit::Test *suite() {
    CppUnit::TestFactoryRegistry &registry =
                      CppUnit::TestFactoryRegistry::getRegistry();

    return registry.makeTest();
}

CPPUNIT_TEST_SUITE_REGISTRATION(StackTestCase);

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
