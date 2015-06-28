#include "mdgate/browser/ui/order_widget.h"
#include <QHeaderView>

//////////////////////////////////////////////////////////////////////////

OrderWidget::OrderWidget(QWidget* parent /* = 0 */)
  :QTableWidget(parent){
  InitUi();
}

OrderWidget::~OrderWidget(){

}

void OrderWidget::InitUi(){
  QMap<QString, QString> dictLabels;

  dictLabels["0-OrderRef"] = QStringLiteral("������");
  dictLabels["1-OrderSysID"] = QStringLiteral("ϵͳ���");
  dictLabels["2-InstrumentID"] = QStringLiteral("��Լ����");
  dictLabels["3-ExchangeInstID"] = QStringLiteral("��������Լ����");
  dictLabels["4-Direction"] = QStringLiteral("����");
  dictLabels["5-CombOffsetFlag"] = QStringLiteral("��ƽ");
  dictLabels["6-LimitPrice"] = QStringLiteral("�۸�");
  dictLabels["7-VolumeTotalOriginal"] = QStringLiteral("ί������");
  dictLabels["8-VolumeTraded"] = QStringLiteral("�ɽ�����");
  dictLabels["9-InsertTime"] = QStringLiteral("ί��ʱ��");
  dictLabels["a-CancelTime"] = QStringLiteral("����ʱ��");
  dictLabels["b-StatusMsg"] = QStringLiteral("״̬��Ϣ");

  this->setColumnCount(dictLabels.size());
  this->setHorizontalHeaderLabels(dictLabels.values());
  this->verticalHeader()->setVisible(false);
  this->setEditTriggers(QTableWidget::NoEditTriggers);
}
