/********************************************************************************
** Form generated from reading ui file 'plugin_dialog.ui'
**
** Created: Fri Apr 30 10:34:10 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_PLUGINDIALOG_H
#define UI_PLUGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pluginDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *pluginDialog)
    {
        if (pluginDialog->objectName().isEmpty())
            pluginDialog->setObjectName(QString::fromUtf8("pluginDialog"));
        pluginDialog->resize(402, 303);
        verticalLayoutWidget = new QWidget(pluginDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 401, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(verticalLayoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(verticalLayoutWidget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(pluginDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), pluginDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), pluginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(pluginDialog);
    } // setupUi

    void retranslateUi(QDialog *pluginDialog)
    {
        pluginDialog->setWindowTitle(QApplication::translate("pluginDialog", "Show Plugins", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(pluginDialog);
    } // retranslateUi

};

namespace Ui {
    class pluginDialog: public Ui_pluginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINDIALOG_H
