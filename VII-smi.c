#include <stdio.h>
#include <nvml.h>

int main()
{
    nvmlReturn_t result;
    unsigned int device_count, i;

    // First initialize NVML library
 result = nvmlInit();
 if (NVML_SUCCESS == result)
  { 
   result = nvmlDeviceGetCount(&device_count);
    if (NVML_SUCCESS == result)
    { 
     for (i = 0; i < device_count; i++)
     {
        nvmlDevice_t device;
        nvmlReturn_t result1;
        nvmlReturn_t result2;
        unsigned int fanspeed;
        unsigned int temperature;
        nvmlComputeMode_t sensor = 0;

       result = nvmlDeviceGetHandleByIndex(i, &device);
       if (NVML_SUCCESS == result)
       { 
        result1 = nvmlDeviceGetFanSpeed(device, &fanspeed);
        result2 = nvmlDeviceGetTemperature ( device, sensor, &temperature );
         if(NVML_SUCCESS == result1)
         { 
          printf("%i fan speed=%d\n", i, fanspeed);
         }
         else printf("Failed to get fan speed for device %i:\n", i);
         if (NVML_SUCCESS == result2)
         {
          printf("%i temperature=%d\n", i, temperature);
         }
         else printf("Failed to get temperature for device %i\n", i);
        }
       else printf("Failed to get handle for device %i\n", i);
     }
    }   
   else printf("API failed\n");

    result = nvmlShutdown();

    if (NVML_SUCCESS != result)
    {
    printf("Warning: Failed to shutdown NVML\n");
    }
   }
return 0;
}

