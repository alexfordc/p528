#include "chrome/browser/ui/trading_widget.h"

#include "chrome/browser/ui/messageloop_qt.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>

#include "chrome/browser/ctp/mdapi.h"
#include "chrome/browser/browser_process.h"

//////////////////////////////////////////////////////////////////////////

TradingWidget::TradingWidget(QWidget* parent /* = 0 */)
  :QWidget(parent){
  InitUi();
  RegisterEvent();
}

TradingWidget::~TradingWidget(){

}

void TradingWidget::InitUi(){
  buy_button = new QPushButton(QStringLiteral("�µ�"));
  cancel_button = new QPushButton(QStringLiteral("ȫ��"));
  login_button = new QPushButton(QStringLiteral("����"));
  logoff_button = new QPushButton(QStringLiteral("�ǳ�"));
  about_button = new QPushButton(QStringLiteral("˵��"));
  close_button = new QPushButton(QStringLiteral("�ر�"));
  init_button = new QPushButton(QStringLiteral("����"));
  connect_button = new QPushButton(QStringLiteral("����"));
  fini_button = new QPushButton(QStringLiteral("����"));

  QVBoxLayout* vBox = new QVBoxLayout();
  vBox->addWidget(buy_button);
  vBox->addWidget(cancel_button);
  vBox->addSpacing(20);
  vBox->addWidget(init_button);
  vBox->addWidget(connect_button);
  vBox->addWidget(login_button);
  vBox->addWidget(logoff_button);
  vBox->addWidget(fini_button);
  vBox->addSpacing(20);
  vBox->addWidget(about_button);
  vBox->addWidget(close_button);

  this->setLayout(vBox);
}

// refactor:conect to g_process->mdapi()
void TradingWidget::RegisterEvent(){
  QObject::connect(close_button, &QPushButton::clicked, QtApp(), &QApplication::exit);
  QObject::connect(init_button, &QPushButton::clicked, this, &TradingWidget::Setup);
  QObject::connect(connect_button, &QPushButton::clicked, this, &TradingWidget::Connect);
  QObject::connect(fini_button, &QPushButton::clicked, this, &TradingWidget::Reset);
  QObject::connect(login_button, &QPushButton::clicked, this, &TradingWidget::Login);
  QObject::connect(logoff_button, &QPushButton::clicked, this, &TradingWidget::Logout);
}

void TradingWidget::Setup(){
  CHECK(!mdapi_);
  mdapi_ = new MdApi();
  mdapi_->Setup();
}

void TradingWidget::Connect(){
  CHECK(mdapi_);
  mdapi_->Connect();
}

void TradingWidget::Login(){
  CHECK(mdapi_);
  mdapi_->Login();
}

void TradingWidget::Logout(){
  CHECK(mdapi_);
  mdapi_->Logout();
}

void TradingWidget::Reset(){
  CHECK(mdapi_);
  mdapi_->Reset();
  delete mdapi_;
  mdapi_ = nullptr;
}
