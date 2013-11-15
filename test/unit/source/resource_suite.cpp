/*
 * Copyright (c) 2013 Corvusoft
 */

#ifdef __APPLE__
#define GTEST_USE_OWN_TR1_TUPLE 1 //See issue tracker #11
#endif

//System Includes
#include <string>
#include <stdexcept>

//Project Includes

//External Includes
#include <gtest/gtest.h>
#include <restbed/resource>

//System Namespaces
using std::string;
using std::invalid_argument;

//Project Namespaces

//External Namespaces
using restbed::Resource;

TEST( Resource, constructor )
{
    const Resource resource;
    
    EXPECT_TRUE( resource.get_path( ) == ".*" );
    EXPECT_TRUE( resource.get_content_type( ) == ".*" );
}

TEST( Resource, copy_constructor )
{
    const string path = "/event/.*";

    Resource original;
    original.set_path( path );

    const Resource copy( original );
    
    EXPECT_TRUE( copy.get_path( ) == path );
}

TEST( Resource, default_destructor )
{
    ASSERT_NO_THROW({
        Resource* resource = new Resource( );
        
        delete resource;
    });
}

TEST( Resource, path_accessor )
{
    const string path = "Super important test data.";

    Resource resource;
    resource.set_path( path );

    EXPECT_TRUE( resource.get_path( ) == path );
}

TEST( Resource, content_type_accessor )
{
    const string type = "application/json";

    Resource resource;
    resource.set_content_type( type );

    EXPECT_TRUE( resource.get_content_type( ) == type );
}

TEST( Resource, less_than_operator )
{
    Resource lhs;
    lhs.set_path( "a" );

    Resource rhs;
    rhs.set_path( "abc" );

    EXPECT_TRUE( lhs < rhs );
}

TEST( Resource, greater_than_operator )
{
    Resource lhs;
    lhs.set_path( "123456" );

    Resource rhs;
    rhs.set_path( "123" );

    EXPECT_TRUE( lhs > rhs );
}

TEST( Resource, equality_operator )
{
    Resource lhs;
    lhs.set_path( "/api" );
    
    Resource rhs;
    rhs.set_path( "/api" );
    
    EXPECT_TRUE( lhs == rhs );
}

TEST( Resource, negated_equality_operator )
{
    Resource lhs;
    lhs.set_path( "/api" );
    
    Resource rhs;
    rhs.set_path( "/resources" );
    
    EXPECT_TRUE( lhs != rhs );
}

TEST( Resource, assignment_operator )
{
    Resource original;
    original.set_path( "/api/login" );
    original.set_content_type( "text/data" );

    Resource copy = original;

    EXPECT_TRUE( original == copy );
}
