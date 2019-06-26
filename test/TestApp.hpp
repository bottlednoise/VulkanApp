/* -------------------------------------------------------------------------- */
/*!
 * \file TestApp.hpp
 *
 * Class that implements the App object.
 *
 * (c) 2019 Julio Martinez
 */

#pragma once


#include <VulkanApp/VulkanApp.hpp>


/* -------------------------------------------------------------------------- */
/*!
 * Class that implements the application.
 */
class TestApp : public VulkanApp::VulkanApp
{
public:

protected:
	bool OnInit() override;
};