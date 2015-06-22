#include "chrome/browser/ui/marketdata_widget.h"
#include <QHeaderView>

//////////////////////////////////////////////////////////////////////////

MarketDataWidget::MarketDataWidget(QWidget* parent /* = 0 */)
  :QTableWidget(parent){
  InitUi();
}

MarketDataWidget::~MarketDataWidget(){

}

void MarketDataWidget::InitUi(){
  QMap<QString, QString> dictLabels;

  dictLabels["0-Name"] = QStringLiteral("��Լ����");
  dictLabels["1-InstrumentID"] = QStringLiteral("��Լ����");
  dictLabels["2-ExchangeInstID"] = QStringLiteral("��Լ����������");
  dictLabels["3-BidPrice1"] = QStringLiteral("��һ��");
  dictLabels["4-BidVolume1"] = QStringLiteral("��һ��");
  dictLabels["5-AskPrice1"] = QStringLiteral("��һ��");
  dictLabels["6-AskVolume1"] = QStringLiteral("��һ��");
  dictLabels["7-LastPrice"] = QStringLiteral("���¼�");
  dictLabels["8-Volume"] = QStringLiteral("�ɽ���");
  dictLabels["9-UpdateTime"] = QStringLiteral("����ʱ��");
  
  this->setColumnCount(dictLabels.size());
  this->setHorizontalHeaderLabels(dictLabels.values());
  this->verticalHeader()->setVisible(false);
  this->setEditTriggers(QTableWidget::NoEditTriggers);
}
