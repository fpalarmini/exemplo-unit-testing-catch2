#define CATCH_CONFIG_MAIN

#include "catch.hpp"

using namespace Catch::Matchers;

bool numeroIsPar(uint8_t numero)
{
    return (!(numero % 2));
}

inline const char* testeRetornaString()
{
    return "teste retornando uma string";
}

TEST_CASE( "teste 1", "[single-file]" ) 
{
    REQUIRE( numeroIsPar(0) == true );
    REQUIRE( numeroIsPar(1) == true );
    
}

TEST_CASE( "teste 2", "[single-file]" ) 
{
    REQUIRE( numeroIsPar(2) == true );
    REQUIRE( numeroIsPar(3) == true );
}

TEST_CASE("teste 3 - matchers", "[matchers]")
{
    REQUIRE_THAT(testeRetornaString(), Contains("retornando"));
    CHECK_THAT(testeRetornaString(), Contains("uma"));
    CHECK_THAT(testeRetornaString(), StartsWith("teste"));
    CHECK_THAT(testeRetornaString(), EndsWith("string"));
    CHECK_THAT(testeRetornaString(), (Contains("string") && Contains("retornando")));
}

// Compile & run:
// - g++ -std=c++11 -Wall -I$(CATCH_SINGLE_INCLUDE) -o 010-TestCase 010-TestCase.cpp && 010-TestCase --success
