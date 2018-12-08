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
        nvmlReturn_t result3;
        unsigned int fanspeed=0;
        unsigned int temperature=0;
        unsigned int power=0;
        nvmlComputeMode_t sensor = 0;

       result = nvmlDeviceGetHandleByIndex(i, &device);
       if (NVML_SUCCESS == result)
       { 
        result1 = nvmlDeviceGetFanSpeed(device, &fanspeed);
        result2 = nvmlDeviceGetTemperature ( device, sensor, &temperature );
        result3 = nvmlDeviceGetPowerUsage ( device, &power );
         if(NVML_SUCCESS == result1)
         { 
          printf("GPU %i fan speed=%d\n", i, fanspeed);
         }
         else printf("GPU %i fan speed=failed to get\n", i);
         if (NVML_SUCCESS == result2)
         {
          printf("GPU %i temperature=%d\n", i, temperature);
         }
         else printf("GPU %i temperature=failed to get\n", i);
         if(NVML_SUCCESS == result3)
         {
         printf("GPU %i power=%d\n", i, power/1000);
         }
         else printf("GPU %i power=failed to get\n", i);
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

