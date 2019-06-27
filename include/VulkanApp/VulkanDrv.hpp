#pragma once
#include <vector>

namespace VulkanApp
{
	//! Class that will handle all the functionality related to Vulkan.
	class VulkanDrv
	{
	public:
		//! Constructor.
		VulkanDrv();

		//! Destructor.
		~VulkanDrv();

		//! Initialization function.
		bool Initialize(const char* applicationName);

	private:
		VkInstance vkInstance;						//!< Vulkan instance.
		std::vector<const char*> validationLayers;	//!< Validation layers to set.
		bool enableValidationLayers = false;		//!< Enable validation layers flag.

		//! Method that checks for the existence of validation layers.
		bool CheckValidationLayersSupport();

		//! Method used to enumerate the required extensions.
		std::vector<const char*> GetRequiredExtensions();
	};
}
