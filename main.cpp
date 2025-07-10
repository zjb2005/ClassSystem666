#include "widget.h"
#include "classset.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // QTranslator translator;
    // const QStringList uiLanguages = QLocale::system().uiLanguages();
    // for (const QString &locale : uiLanguages) {
    //     const QString baseName = "classsystem_" + QLocale(locale).name();
    //     if (translator.load(":/i18n/" + baseName)) {
    //         a.installTranslator(&translator);
    //         break;
    //     }
    // }
    // 设置全局字体 - 影响所有控件
    QFont defaultFont("Microsoft YaHei", 11); // 字体名称和大小
    a.setFont(defaultFont);
    Widget w;
    w.show();

    // ClassSet c;
    // c.show();
    return a.exec();
}
