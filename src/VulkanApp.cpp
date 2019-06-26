/* -------------------------------------------------------------------------- */
/*!
 * \file VulkanApp.cpp
 *
 * Definition of the VulkanApp class, basic class that encapsulates the
 * functionality of a Vulkan based application
 *
 * (c) 2019 Julio Martinez
 */

#include "VulkanApp/VulkanApp.hpp"

/* -------------------------------------------------------------------------- */
/*!
 * Initializes the Application object.
 */
VulkanApp::VulkanApp::VulkanApp()
{
	exitCode = 0;
}


/* -------------------------------------------------------------------------- */
/*!
 * This is a virual method that applications should override to initialize the
 * application.
 * \returns true if successful and false otherwise.
 */
bool VulkanApp::VulkanApp::OnInit()
{
	return true;
}


/* -------------------------------------------------------------------------- */
/*!
 * Method that implements the execution of the application.
 * \returns the return code of the application.
 */
int32_t VulkanApp::VulkanApp::Run()
{
	return exitCode;
}