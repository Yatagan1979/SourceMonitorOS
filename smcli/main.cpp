//******************************************************************************
// Copyright (C) 1999 Jim Wanner and the SourceMonitor team.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//******************************************************************************

#include <QCoreApplication>
#include <QLocale>
#include <QString>
#include <QTranslator>
#include <QDirIterator>
#include "smpreader.h"
#include <QDir>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages)
    {
        const QString baseName = "smcli_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }
    //smos::smcore::SMPReader smpReader;
    //if (!smpReader.Open("d:\\SourceMonitor\\SourceMonitorOS\\test2.smp"))
    //return 1;

    //QStringList strList();
    QDirIterator it("d:\\SourceMonitor\\SM-Test-Files", QStringList() << "*.smp", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QString filePath(it.next());
        qDebug() << filePath;
        smos::smcore::SMPReader smpReader;
        if (!smpReader.Open(filePath.toStdString()))
            return 1;
        smos::smcore::Project project;
        if (!smpReader.Read(project))
            return 1;
    }

    //smos::smcore::Project project;
    //if (!smpReader.Read(project))
    //return 1;
    return 0; //a.exec();
}
