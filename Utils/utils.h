#pragma once

#include <string>
#include <QDir>
#include <QFileInfo>
#include <QString>

bool isValidPartName(std::string part);
bool isValidVDirectionName(std::string direction);
bool isValidHDirectionName(std::string direction);
bool isValidFolder(QString path);
bool isValidFile(QString path);
bool mkdirIfMissing(std::string abs_path);
bool mkdirIfMissing(QString abs_path);
QString getResultFolder(QString base_fd);

