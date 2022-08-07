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

    auto *chooseSound = new QSound(":/assets/TapButtonSound.wav", this);
    auto *backSound = new QSound(":/assets/BackButtonSound.wav", this);

    // 返回按钮
    auto *backBtn = new MyPushButton(":/assets/BackButton.png", ":/assets/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());

    connect(backBtn, &MyPushButton::clicked, [=]() {
        backSound->play();
        QTimer::singleShot(500, this, [=]() {
            emit this->chooseSceneBack();
        });
    });


    // 创建选择关卡的按钮
    for (int i = 0; i < 20; ++i) {
        auto *menuBtn = new MyPushButton(":/assets/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i % 4 * 70, 130 + i / 4 * 70);

        // 监听每个按钮的点击事件
        connect(menuBtn, &MyPushButton::clicked, [=]() {
            chooseSound->play();

            this->hide();
            play = new PlayScene(i + 1);
            play->setGeometry(this->geometry());
            play->show();

            connect(play, &PlayScene::chooseSceneBack, [=]() {
                this->setGeometry(play->geometry());
                this->show();
                delete play;
                play = nullptr;
            });
        });

        auto *label = new QLabel;
        label->setParent(this);
        label->setFixedSize(menuBtn->width(), menuBtn->height());
        label->setText(QString::number(i + 1));
        label->move(25 + i % 4 * 70, 130 + i / 4 * 70);

        // 设置label上文字对齐方式，水平垂直居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // 设置让鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
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
