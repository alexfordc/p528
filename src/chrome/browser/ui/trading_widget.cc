#include "chrome/browser/ui/trading_widget.h"

#include "chrome/browser/ui/messageloop_qt.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>

//////////////////////////////////////////////////////////////////////////

TradingWidget::TradingWidget(QWidget* parent /* = 0 */)
  :QWidget(parent){
  InitUi();
}

TradingWidget::~TradingWidget(){

}

void TradingWidget::InitUi(){
  QPushButton* buy_button = new QPushButton(QStringLiteral("�µ�"));
  QPushButton* cancel_button = new QPushButton(QStringLiteral("ȫ��"));
  QPushButton* login_button = new QPushButton(QStringLiteral("����"));
  QPushButton* logoff_button = new QPushButton(QStringLiteral("�ǳ�"));
  QPushButton* about_button = new QPushButton(QStringLiteral("˵��"));
  QPushButton* close_button = new QPushButton(QStringLiteral("�ر�"));

  QVBoxLayout* vBox = new QVBoxLayout();
  vBox->addWidget(buy_button);
  vBox->addWidget(cancel_button);
  vBox->addSpacing(100);
  vBox->addWidget(login_button);
  vBox->addWidget(logoff_button);
  vBox->addSpacing(20);
  vBox->addWidget(about_button);
  vBox->addWidget(close_button);

  this->setLayout(vBox);

  QObject::connect(close_button, &QPushButton::clicked, QtApp(), &QApplication::exit);
}

