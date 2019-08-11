cmake_minimum_required(VERSION 3.2)

project(MathAlg CXX)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

#Test
add_executable(testMathAlg Tests/test.cpp)

target_include_directories(testMathAlg PUBLIC MathAlg ${Boost_INCLUDE_DIR} ${Boost_INCLUDE_DIR} External/IArray/Array )

#Дополнительный свойста компилятора для всех проектов
set_target_properties( testMathAlg PROPERTIES
	CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)
