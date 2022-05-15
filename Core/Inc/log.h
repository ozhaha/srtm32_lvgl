//
// Created by ozcom on 2022/4/6.
//

#ifndef STM32F407VE_DEMO3_LOG_H
#define STM32F407VE_DEMO3_LOG_H

#define SHOW_LOG 1

#if SHOW_LOG

#include <stdio.h>

#define LOGI(...) printf(__VA_ARGS__)

#define LOGD(...) do{ \
    printf("[%s %s] D/%s: ",__DATE__,__TIME__,__FUNCTION__);         \
    printf(__VA_ARGS__);   \
    printf("\n");\
}while(0)

#define LOGW(...) do{ \
    printf("[%s %s] line:%d W/%s: ",__DATE__,__TIME__,__LINE__,__FUNCTION__);         \
    printf(__VA_ARGS__);   \
    printf("\n");\
}while(0)

#define LOGE(...) do{ \
    printf("[%s %s] %s line:%d E/%s: ",__DATE__,__TIME__,__FILE__,__LINE__,__FUNCTION__);         \
    printf(__VA_ARGS__);   \
    printf("\n");\
}while(0)


#else

#define LOGI(...) ((void)0)
#define LOGD(...) ((void)0)
#define LOGW(...) ((void)0)
#define LOGE(...) ((void)0)

#endif

#endif //STM32F407VE_DEMO3_LOG_H
