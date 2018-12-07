#include <stdio.h>
#include <nvml.h>

int main()
{
    nvmlReturn_t result;
    unsigned int device_count, i;

    // First initialize NVML library
    result = nvmlInit();
    result = nvmlDeviceGetCount(&device_count);
    if (NVML_SUCCESS == result)
    { 
     for (i = 0; i < device_count; i++)
     {
        nvmlDevice_t device;
        nvmlReturn_t  fanspeed;
        nvmlReturn_t temperature;

       result = nvmlDeviceGetHandleByIndex(i, &device);
       if (NVML_SUCCESS == result)
       { 
        fanspeed = nvmlDeviceGetFanSpeed(device, &fanspeed)
        temperature = nvmlDeviceGetTemperature ( device, 2, &temp )
         if (NVML_SUCCESS != fanspeed)
         { 
          printf("%i fan speed=%s\n", i, fanspeed);
         }
         else printf("Failed to get fan speed for device %i:\n", i)
         if (NVML_SUCCESS == temperature)
         {
          printf("%i temperature=%s\n", i, temperature)
         }
         else printf("Failed to get fan speed for device %i\n", i)
        }
       else printf("Failed to get handle for device %i\n", i,);
     }
    }   
   else printf("API failed\n", i,);

    result = nvmlShutdown();
    if (NVML_SUCCESS != result)
    {
    printf("Warning: Failed to shutdown NVML\n", nvmlErrorString(result));
    }
    return 0;
}
