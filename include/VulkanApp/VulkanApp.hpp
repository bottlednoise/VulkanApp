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
#include <string>


namespace VulkanApp
{
	class VulkanApp
	{
	public:
		//! Default constructor.
		VulkanApp();

		virtual ~VulkanApp();

		//! Method tha executes the application.
		int32_t Run();

		//! Function to set the size of the window.
		/*!
		 * \param width width of the window.
		 * \param height height of the window.
		 */
		void SetWindowSize(int32_t width, int32_t height)
		{
			windowWidth = width;
			windowHeight = height;
			framebufferResized = true;
		}

		//! Function to get the width of the window.
		/*!
		 * \return window's width.
		 */
		[[nodiscard]] int32_t GetWindowWidth() const
		{
			return windowWidth;
		}

		//! Function to get the height of the window.
		/*!
		 * \return window's height.
		 */
		[[nodiscard]] int32_t GetWindowHeight() const
		{
			return windowHeight;
		}

		//! Method to set the application name.
		void SetApplicationName(const std::string name)
		{
			applicationName = name;
		}

		//! Function to set the caption of the window.
		void SetWindowCaption(const std::string caption);

	protected:
		virtual bool OnInit();

	private:
		std::string applicationName;				//!< Application name.
		struct GLFWwindow* window = nullptr;		//!< GLFW window handler.
		class VulkanDrv* vulkanDrv = nullptr;		//!< Vulkan driver object.
		int32_t windowWidth = 800;					//!< Width of the window.
		int32_t windowHeight = 600;					//!< Height of the window.
		std::string windowCaption;					//!< Name of the window.
		int32_t exitCode = 0;						//!< Exit code for the application.
		bool framebufferResized = false;			//!< Flag to check if the window has been resized.

		//! Vulkan internal initialization.
		bool Initialize();

		//! Initialize glfw system.
		bool InitializeGLFW();

		//! Vulkan initialization method.
		bool InitializeVulkan();

		//! Window resize callback.
		static void FrameBufferResizeCB(struct GLFWwindow* window, int width, int height);
	};
}