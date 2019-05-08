#include "globalconfigfile.h"

/**
 * @brief GlobalConfigFile::GlobalConfigFile
 */
GlobalConfigFile::GlobalConfigFile()
    :m_settings(nullptr)
{

}

/**
 * @brief 设置setting 读写ini文件
 * @param setting
 */
void GlobalConfigFile::setSettings(QSettings *setting)
{
    this->m_settings = setting;
}

/**
 * @brief 用于保存 .ini 配置文件
 */
void GlobalConfigFile::saveConfigFile()
{
    if(m_settings == nullptr)
    {
        return;
    }
    /* 配置文件 */
    m_settings->beginGroup(QString("11"));

    m_settings->endGroup();
}

/**
 * @brief 解析.ini 配置文件
 */
bool GlobalConfigFile::parseConfigFile()
{
    if(m_settings == nullptr)
    {
        return false;
    }


}
