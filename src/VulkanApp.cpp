/* -------------------------------------------------------------------------- */
/*!
 * \file VulkanApp.cpp
 *
 * Definition of the VulkanApp class, basic class that encapsulates the
 * functionality of a Vulkan based application
 *
 * (c) 2019 Julio Martinez
 */

#include <string.h>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "VulkanApp/VulkanApp.hpp"
#include "VulkanApp/VulkanDrv.hpp"


/* -------------------------------------------------------------------------- */
/*!
 * Initializes the Application object.
 */
VulkanApp::VulkanApp::VulkanApp()
{
	vulkanDrv = new VulkanDrv();
}


/* -------------------------------------------------------------------------- */
/*!
 * Releases the resources allocated by the application.
 */
VulkanApp::VulkanApp::~VulkanApp()
{
	if (vulkanDrv)
	{
		delete vulkanDrv;
		vulkanDrv = nullptr;
	}

	if (window)
	{
		glfwDestroyWindow(window);
		window = nullptr;
	}

	glfwTerminate();
}


/* -------------------------------------------------------------------------- */
/*!
 * This is a virtual method that applications should override to initialize the
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
	bool result = true;

	if (OnInit())
	{
		result = InitializeGLFW();
		result |= InitializeVulkan();
	}

	return result;
}


/* -------------------------------------------------------------------------- */
/*!
 * Initialization part for GLFW.
 * \return true in case of success or false on error.
 */
bool VulkanApp::VulkanApp::InitializeGLFW()
{
	if (glfwInit() != GLFW_TRUE)
		return false;

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	window = glfwCreateWindow(windowWidth, windowHeight, windowCaption.c_str(), nullptr, nullptr);

	glfwSetWindowUserPointer(window, this);
	glfwSetFramebufferSizeCallback(window, FrameBufferResizeCB);

	return true;
}


/* -------------------------------------------------------------------------- */
/*!
 * Initialization part for GLFW.
 * \return true in case of success or false on error.
 */
bool VulkanApp::VulkanApp::InitializeVulkan()
{
	bool result = vulkanDrv->Initialize(applicationName.c_str());

	return result;
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


/* -------------------------------------------------------------------------- */
/*!
 * \param caption New caption for the window.
 */
void VulkanApp::VulkanApp::SetWindowCaption(const std::string caption)
{
	windowCaption = caption;

	if (window != nullptr)
		glfwSetWindowTitle(window, windowCaption.c_str());
}
