#include "programfilepath.h"

#include <QApplication>
#include <QDir>

ProgramFilePath::ProgramFilePath()
{
    /*! <文件路径> */
    m_programPath = qApp->applicationDirPath();
    m_configPath = m_programPath + QString("/../config");

    /*! <默认保存文件名> */
    m_configFile = m_configPath + QString("/config.ini");


    /*! <动态保存文件> */

}
