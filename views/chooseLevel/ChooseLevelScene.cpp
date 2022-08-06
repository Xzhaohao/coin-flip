#include "ChooseLevelScene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent) {

    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/assets/Coin0001.png"));
    setWindowTitle("选择关卡");
    setWindowFlags(Qt::WindowCloseButtonHint);

    // 创建菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quitAction = startMenu->addAction("退出");

    connect(quitAction, &QAction::triggered, [=]() {
        this->close();
    });

    // 返回按钮
    auto *backBtn = new MyPushButton(":/assets/BackButton.png", ":/assets/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &MyPushButton::clicked, [=]() {
        QTimer::singleShot(500, this, [=]() {
            emit this->chooseSceneBack();
        });
    });
}

void ChooseLevelScene::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/assets/OtherSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    pixmap.load(":/assets/Title.png");
    pixmap = pixmap.scaled((int) (pixmap.width() * 0.5), (int) (pixmap.height() * 0.5));
    painter.drawPixmap((int) ((this->width() - pixmap.width()) * 0.5), 30, pixmap);
}
