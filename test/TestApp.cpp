/* -------------------------------------------------------------------------- */
/*!
 * \file TestApp.cpp
 *
 * Class that implements the App object.
 *
 * (c) 2019 Julio Martinez
 */


#include "TestApp.hpp"


bool TestApp::OnInit()
{
	SetWindowSize(640, 480);
	SetWindowCaption("VulkanApp Test");
	SetApplicationName("VulkanApp Test");

	return true;
}