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

	protected:
		virtual bool OnInit();

	private:
		int32_t exitCode;							//!< Exit code for the application
	};

}