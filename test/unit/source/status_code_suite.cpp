/*
 * Copyright (c) 2013 Corvusoft
 */

#ifdef __APPLE__
#define GTEST_USE_OWN_TR1_TUPLE 1 //See issue tracker #11
#endif

//System Includes
#include <map>
#include <string>
#include <stdexcept>

//Project Includes

//External Includes
#include <gtest/gtest.h>
#include <restbed/status_code>

//System Namespaces
using std::map;
using std::string;
using std::invalid_argument;

//Project Namespaces

//External Namespaces
using restbed::StatusCode;

TEST( StatusCode, to_string_with_valid_status_code )
{
    const string result = StatusCode::to_string( StatusCode::OK );
    
    ASSERT_TRUE( result == "OK" );
}

TEST( StatusCode, to_string_with_invalid_status_code )
{
    ASSERT_THROW( StatusCode::to_string( 9999 ), invalid_argument );
}

TEST( StatusCode, set_status_code_strings )
{
    const map< int, string > values = {
    	{ 109, "Custom Error Message" },
    	{ 222, "Inhouse Error Message" }
    };

    StatusCode::set_mappings( values );
    
    ASSERT_TRUE( StatusCode::get_mappings( ) == values );
}
