/*========================================*\
    文件 : log.h
    作者 : 陈乐群
\*========================================*/

#ifndef __LOG__
#define __LOG__


/*========================================*\
    功能 : 打开日志
    参数 : (输入)日志文件路径
    返回 : (成功)0
           (失败)-1
\*========================================*/
int flogInit(char *logpath);
/*========================================*\
    功能 : 关闭日志
    参数 : (输入)正式日志文件路径
           (输入)临时日志文件路径
    返回 : (成功)0
           (失败)-1
\*========================================*/
int flogFree(char *fmlpath,char *tmppath);

/*========================================*\
    功能 : 打印日志(任何版本都打印)
    参数 : (输入)格式化字符串
    返回 : 空
\*========================================*/
void flogAnyhow(char *format,...);
/*========================================*\
    功能 : 打印日志(调试版本才打印)
    参数 : (输入)格式化字符串
    返回 : 空
\*========================================*/
void flogDepend(char *format,...);

/*========================================*\
    功能 : 获取日期
    参数 : (输入)是否添加分隔符
    返回 : 日期
\*========================================*/
char *flogDate(int split);
/*========================================*\
    功能 : 获取时间
    参数 : (输入)是否添加分隔符
    返回 : 时间
\*========================================*/
char *flogTime(int split);

#define mlogDebug(format,argument...)\
	flogDepend("*[%s][%d]"format,__FILE__,__LINE__,##argument)

#define mlogError(function,code,info,format,argument...)\
	flogAnyhow("#[%s][%s]\n#[%s][%d]\n#[%s][%s][%d][%s]\n#"format"\n",flogDate(1),flogTime(1),__FILE__,__LINE__,__FUNCTION__,function,code,info,##argument)

#define mlogEvent(format,argument...)                                \
do                                                                   \
{                                                                    \
	struct timeval tv;                                               \
	gettimeofday(&tv,NULL);                                          \
	flogAnyhow("#[%s:%06d]"format,flogTime(1),tv.tv_usec,##argument);\
}while(0)

#endif
