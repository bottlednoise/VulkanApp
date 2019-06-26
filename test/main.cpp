/* -------------------------------------------------------------------------- */
/*!
 * \file main.cpp
 *
 * Entry point for the VulkanAppTest application, an application used to test
 * the VulkanApp library.
 *
 * (c) 2019 Julio Martinez
 */

#ifdef _WIN32
#include <Windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif // _WIN32


#include "TestApp.hpp"


/* -------------------------------------------------------------------------- */
/*!
 * Entry code for the application.
 */
int main()
{
	TestApp app;

	return static_cast<int>(app.Run());
}