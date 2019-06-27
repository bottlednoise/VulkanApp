#include "VulkanApp/VulkanDrv.hpp"
#include <vulkan/vulkan_core.h>


/* -------------------------------------------------------------------------- */
/*!
 * Constructor that will initialize the object.
 */
VulkanApp::VulkanDrv::VulkanDrv()
{
	validationLayers =
	{
		"VK_LAYER_KHRONOS_validation"
	};

#if _DEBUG
	enableValidationLayers = true;
#else
	enableValidationLayers = false;
#endif // _DEBUG
}


/* -------------------------------------------------------------------------- */
/*!
 * Destructor that will release all the resources allocated by the class.
 */
VulkanApp::VulkanDrv::~VulkanDrv()
{
}


/* -------------------------------------------------------------------------- */
/*!
 * Method that will initialize the device and a minimum set of resources 
 * required to use Vulkan.
 */
bool VulkanApp::VulkanDrv::Initialize()
{
	if (enableValidationLayers && !CheckValidationLayersSupport())
	{
		return false;
	}

	return true;
}


/* -------------------------------------------------------------------------- */
/*!
 * \return true if the validation layers requested are supported and false 
 * otherwise
*/
bool VulkanApp::VulkanDrv::CheckValidationLayersSupport()
{
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}

		if (!layerFound) {
			return false;
		}
	}

	return true;
}
