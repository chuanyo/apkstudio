#ifndef APKTOOL_H
#define APKTOOL_H

#include <QStringList>
#include "macros.h"
#include "java.h"

APP_NAMESPACE_START

class ApkTool : public Java
{
private:
    QString _jar;
    static ApkTool *_self;
private:
    explicit ApkTool(QObject *parent = 0);
public:
    Result build(const QString &src, const QString &dest);
    Result decode(const QString &src, const QString &dest, const QString &framework);
    inline Result exec(const QString &arg) { return exec(QStringList(arg)); }
    Result exec(const QStringList &args = QStringList());
    static ApkTool *get();
    QString getVersion();
};

APP_NAMESPACE_END

#endif // APKTOOL_H
