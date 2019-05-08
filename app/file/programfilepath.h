/*!
 *  @brief    系统文件配置信息
 *  @details  定义了系统中各个文件夹路径、文件名全路径等信息
 *  @author   yzg
 *  @version
 *  @date     20190506
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef PROGRAMFILEPATH_H
#define PROGRAMFILEPATH_H

#include <QObject>

class ProgramFilePath
{
public:
    ProgramFilePath();

    /*! <文件夹路径> */
    QString m_programPath;      /*! <文件路径> */
    QString m_configPath;       /*! <config 配置文件路径> */
    /*! <文件全路径> */
    QString m_configFile;       /*! <config 配置文件> */
};

#endif // PROGRAMFILEPATH_H
