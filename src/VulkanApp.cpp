/* -------------------------------------------------------------------------- */
/*!
 * \file VulkanApp.cpp
 *
 * Definition of the VulkanApp class, basic class that encapsulates the
 * functionality of a Vulkan based application
 *
 * (c) 2019 Julio Martinez
 */

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanApp/VulkanApp.hpp"

/* -------------------------------------------------------------------------- */
/*!
 * Initializes the Application object.
 */
VulkanApp::VulkanApp::VulkanApp()
{
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
	exitCode = 0;

	if (!Initialize())
		return -1;

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
	}

	return exitCode;
}


/* -------------------------------------------------------------------------- */
/*!
 * Internal method that will initialize GLFW and Vulkan systems.
 */
bool VulkanApp::VulkanApp::Initialize()
{
	if (OnInit())
	{
		if (glfwInit() != GLFW_TRUE)
			return false;

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

		window = glfwCreateWindow(windowWidth, windowHeight, windowName ? windowName : "VulkanApp", nullptr, nullptr);
		
		glfwSetWindowUserPointer(window, this);
		glfwSetFramebufferSizeCallback(window, FrameBufferResizeCB);
	}

	return true;
}


/* -------------------------------------------------------------------------- */
/*!
 * Callback that will be invoked when the size of the window changes.
 */
void VulkanApp::VulkanApp::FrameBufferResizeCB(GLFWwindow* window, int width, int height)
{
	auto app = reinterpret_cast<VulkanApp*>(glfwGetWindowUserPointer(window));
	app->framebufferResized = true;
}