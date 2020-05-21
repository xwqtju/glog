#ifndef GLOGHELPER_H
#define GLOGHELPER_H
#include<glog/logging.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
 
enum SeverityLevel
{
    INFO,
    WARNING,
    ERROR,
    FATAL
};
 
class GLogHelper
{
public:
    GLogHelper();
    ~GLogHelper();
 
    /**
 *   * @brief:
 *   * @param: const char *program --程序名称
 *   * @param: uint32_t log_level  --需要输出到日志等级包括：(INFO、WARNING、ERROR)
 *   * @param: const char *log_dir --存放日志到目录
 *   * @return: void
 *   * @date:  
 *   * @autor:  
 **/
    void InitLogger(const char* program="ARHUD", const uint32_t log_level = google::ERROR, const char* log_dir="log");
 
 
 
private:
 
 
};
 
 
#endif // GLOGHELPER_H


