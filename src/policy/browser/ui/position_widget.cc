#include "chrome/browser/ui/position_widget.h"
#include <QHeaderView>

//////////////////////////////////////////////////////////////////////////
PositionWidget::PositionWidget(QWidget* parent /* = 0 */)
  :QTableWidget(parent){
  InitUi();
}

PositionWidget::~PositionWidget(){

}

void PositionWidget::InitUi(){
  QMap<QString, QString> dictLabels;

  dictLabels["0-InstrumentID"] = QStringLiteral("��Լ����");
  dictLabels["1-PosiDirection"] = QStringLiteral("����");
  dictLabels["2-Position"] = QStringLiteral("�ֲ�");
  dictLabels["3-LongFrozen"] = QStringLiteral("��ͷ����");
  dictLabels["4-ShortFrozen"] = QStringLiteral("��ͷ����");
  dictLabels["5-PositionCost"] = QStringLiteral("�ֲֳɱ�");
  dictLabels["6-OpenCost"] = QStringLiteral("���ֳɱ�");

  this->setColumnCount(dictLabels.size());
  this->setHorizontalHeaderLabels(dictLabels.values());
  this->verticalHeader()->setVisible(false);
  this->setEditTriggers(QTableWidget::NoEditTriggers);
}
