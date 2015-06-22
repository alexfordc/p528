#include "chrome/browser/ui/trade_widget.h"
#include <QHeaderView>

//////////////////////////////////////////////////////////////////////////

TradeWidget::TradeWidget(QWidget* parent /* = 0 */)
  :QTableWidget(parent){
  InitUi();
}

TradeWidget::~TradeWidget(){

}

void TradeWidget::InitUi(){
  QMap<QString, QString> dictLabels;

  dictLabels["0-InstrumentID"] = QStringLiteral("��Լ����");
  dictLabels["1-ExchangeInstID"] = QStringLiteral("��������Լ����");
  dictLabels["2-ExchangeID"] = QStringLiteral("������");
  dictLabels["3-Direction"] = QStringLiteral("����");
  dictLabels["4-OffsetFlag"] = QStringLiteral("��ƽ");
  dictLabels["5-TradeID"] = QStringLiteral("�ɽ����");
  dictLabels["6-TradeTime"] = QStringLiteral("�ɽ�ʱ��");
  dictLabels["7-Volume"] = QStringLiteral("����");
  dictLabels["8-Price"] = QStringLiteral("�۸�");
  dictLabels["9-OrderRef"] = QStringLiteral("������");
  dictLabels["a-OrderSysID"] = QStringLiteral("����ϵͳ��");

  this->setColumnCount(dictLabels.size());
  this->setHorizontalHeaderLabels(dictLabels.values());
  this->verticalHeader()->setVisible(false);
  this->setEditTriggers(QTableWidget::NoEditTriggers);
}

