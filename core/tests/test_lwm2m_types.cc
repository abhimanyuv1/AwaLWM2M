/************************************************************************************************************************
 Copyright (c) 2016, Imagination Technologies Limited and/or its affiliated group companies.
 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 following conditions are met:
     1. Redistributions of source code must retain the above copyright notice, this list of conditions and the
        following disclaimer.
     2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
        following disclaimer in the documentation and/or other materials provided with the distribution.
     3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
        products derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
 USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
************************************************************************************************************************/

#include <gtest/gtest.h>
#include <string>
#include <stdio.h>
#include "lwm2m_types.h"

class Lwm2mTypesTestSuite : public testing::Test
{
  void SetUp() { }
  void TearDown() { }
};

TEST_F(Lwm2mTypesTestSuite, ResourceType_Strings_are_consistent)
{
    ASSERT_EQ(static_cast<size_t>(AwaResourceType_ObjectLink + 1), Lwm2mCore_GetNumberOfResourceTypeStrings()); // +1 for starting at 0
}

TEST_F(Lwm2mTypesTestSuite, ResourceType_ToString)
{
    EXPECT_STREQ("Invalid", Lwm2mCore_ResourceTypeToString(AwaResourceType_Invalid));
    EXPECT_STREQ("ObjectLink", Lwm2mCore_ResourceTypeToString(AwaResourceType_ObjectLink));
}

TEST_F(Lwm2mTypesTestSuite, ResourceType_FromString)
{
    EXPECT_EQ(AwaResourceType_Invalid, Lwm2mCore_ResourceTypeFromString("Invalid"));
    EXPECT_EQ(AwaResourceType_ObjectLink, Lwm2mCore_ResourceTypeFromString("ObjectLink"));
}
