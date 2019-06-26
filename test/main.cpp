/* -------------------------------------------------------------------------- */
/*!
 * \file main.cpp
 *
 * Entry point for the VulkanAppTest application, an application used to test
 * the VulkanApp library.
 *
 * (c) 2019 Julio Martinez
 */


#include "VulkanApp/VulkanApp.hpp"


#ifdef _WIN32
#include <Windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // _WIN32


/* -------------------------------------------------------------------------- */
/*!
 * Entry code for the application.
 */
int main()
{
	VulkanApp::VulkanApp app;

	return static_cast<int>(app.Run());
}