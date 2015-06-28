#include "mdgate/browser/ui/log_widget.h"
#include <QHeaderView>

//////////////////////////////////////////////////////////////////////////
LogWidget::LogWidget(QWidget* parent /* = 0 */) :
  QTableWidget(parent){
  InitUi();
}

LogWidget::~LogWidget(){

}

void LogWidget::InitUi(){
  QMap<QString, QString> dictLabels;

  dictLabels["0-Time"] = QStringLiteral("ʱ��");
  dictLabels["1-Log"] = QStringLiteral("��־");

  this->setColumnCount(dictLabels.size());
  this->setHorizontalHeaderLabels(dictLabels.values());
  this->verticalHeader()->setVisible(false);
  this->setEditTriggers(QTableWidget::NoEditTriggers);
}
