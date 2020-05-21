#include "gloghelper.h"
 
 
void CoreDumped(const char *data, int size)
{
    std::string str = std::string(data,size);
    LOG(ERROR)<<str;
}
 
 
GLogHelper::GLogHelper()
{
 
}
 
GLogHelper::~GLogHelper()
{
    google::ShutdownGoogleLogging();
}
 
/**
 *  * @brief:
 *  * @param: const char *program --程序名称
 *  * @param: uint32_t log_level  --需要输出到日志等级包括：(INFO、WARNING、ERROR)
 *  * @param: const char *log_dir --存放日志到目录
 *  * @return: void
 *  * @date:   
 *  * @autor:  
 *  */
void GLogHelper::InitLogger(const char *program, const uint32_t log_level, const char* log_dir)
{
    if(access(log_dir,F_OK))
    {
        mkdir(log_dir,S_IRWXU | S_IRWXG | S_IXOTH);
    }
    //初始化应用进程名
      google::InitGoogleLogging(program);     
      char info_path[100];
      char warning_path[100];
      char error_path[100];
                    
      snprintf(info_path,sizeof(info_path),"%s%s",log_dir,"/INFO_");
      snprintf(warning_path,sizeof(warning_path),"%s%s",log_dir,"/WARNING_");
      snprintf(error_path,sizeof(error_path),"%s%s",log_dir,"/ERROR_");
                                   
      //取消默认链接文件(链接文件为最新到日志输出)
      google::SetLogSymlink(google::GLOG_INFO,"");
      google::SetLogSymlink(google::GLOG_WARNING,"");
      //google::SetLogSymlink(google::GLOG_ERROR,"");
      //google::SetLogSymlink(google::GLOG_FATAL,"");
                                                           
      //将段错误详细信息输出到日志文件
      google::InstallFailureSignalHandler();
      google::InstallFailureWriter(CoreDumped);
                                                                        
      //是否将日志输出到标准错误而不是日志文件
      FLAGS_logtostderr = false;
      //是否同时将日志发送到标准错误和日志文件中
      FLAGS_alsologtostderr = false;
      //当日志级别大于此级别时，自动将此日志输出到标准错误中
      FLAGS_stderrthreshold = google::WARNING;
      //当日志级别大于此级别时会马上输出，而不缓存

      FLAGS_logbuflevel = google::ERROR;
      //实时刷新日志到硬盘，默认是会缓存

      FLAGS_logbufsecs = 0;
      //日志大小大于30M时，创建新到日志
      FLAGS_max_log_size = 30;

      //当磁盘满时，停止输出日志文件
      FLAGS_stop_logging_if_full_disk = true;
                                                                                                                                 
      //如果未指定日志输出等级，glog不会输出日志
      //设置错误级别大于等于多少时输出到文件
      //参数2为日志存放到目录和日志文件前缀
      if(log_level == google::GLOG_INFO)
      {   
        google::SetLogDestination(google::INFO,info_path);                                    
      }      
          
      else if(log_level == google::GLOG_WARNING)
      {                                                                                                                                                   google::SetLogDestination(google::GLOG_WARNING,warning_path);
      }
                                                                                                                                                        else if(log_level == google::GLOG_ERROR)                                                                                                          {
    	google::SetLogDestination(google::ERROR,error_path);
                                                                                                                                                        }
      else                                                                                                                                              {
    	google::ShutdownGoogleLogging();
      }
                                                                                                                                                  }
