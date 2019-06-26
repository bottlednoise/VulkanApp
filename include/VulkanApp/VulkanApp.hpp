/* -------------------------------------------------------------------------- */
/*!
 * \file VulkanApp.hpp
 *
 * Declaration of the VulkanApp class, basic class that encapsulates the 
 * functionality of a Vulkan based application
 *
 * (c) 2019 Julio Martinez
 */

#pragma once

#include <cstdint>

namespace VulkanApp
{
	class VulkanApp
	{
	public:
		//! Default constructor.
		VulkanApp();

		//! Method tha executes the application.
		int32_t Run();

		//! Function to set the size of the window.
		/*!
		 * \param width width of the window.
		 * \param height height of the window.
		 */
		inline void SetWindowSize(int32_t width, int32_t height)
		{
			windowWidth = width;
			windowHeight = height;
			framebufferResized = true;
		}

		//! Function to get the width of the window.
		/*!
		 * \return window's width.
		 */
		inline int32_t GetWindowWidth()
		{
			return windowWidth;
		}

		//! Function to get the height of the window.
		/*!
		 * \return window's height.
		 */
		inline int32_t GetWindowHeight()
		{
			return windowHeight;
		}

	protected:
		virtual bool OnInit();

	private:
		struct GLFWwindow* window;					//!< GLFW window handler.
		int32_t windowWidth = 800;					//!< Width of the window.
		int32_t windowHeight = 600;					//!< Height of the window.
		char* windowName = nullptr;					//!< Name of the window.
		int32_t exitCode = 0;						//!< Exit code for the application.
		bool framebufferResized = false;			//!< Flag to check if the window has been resized.

		//! Vulkan internal initialization.
		bool Initialize();

		//! Window resize callback.
		static void FrameBufferResizeCB(struct GLFWwindow* window, int width, int height);
	};
}