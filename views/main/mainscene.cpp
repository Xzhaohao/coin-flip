#include "mainscene.h"
#include "ui_mainscene.h"

MainScene::MainScene(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainScene) {
    ui->setupUi(this);

    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/assets/Coin0001.png"));
    setWindowTitle("翻金币");
    // 去掉最大化按钮
    setWindowFlags(Qt::WindowCloseButtonHint);

    // 退出按钮实现
    connect(ui->subMenuQuit, &QAction::triggered, [=]() {
        this->close();
    });

    auto *startSound = new QSound(":/assets/TapButtonSound.wav", this);

    // 开始按钮
    auto *startButton = new MyPushButton(":/assets/MenuSceneStartButton.png");
    startButton->setParent(this);
    startButton->move(
            (int) (this->width() * 0.5 - startButton->width() * 0.5),
            (int) (this->height() * 0.7)
    );

    chooseScene = new ChooseLevelScene;

    // 监听选择选择关卡的返回按钮的信号
    connect(chooseScene, &ChooseLevelScene::chooseSceneBack, this, [=]() {
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });

    connect(startButton, &MyPushButton::clicked, [=]() {
        startSound->play();

        startButton->zoom(1);
        startButton->zoom(-1);

        // 延迟进入下一个页面
        QTimer::singleShot(500, this, [=]() {
            chooseScene->setGeometry(this->geometry());

            this->hide();
            chooseScene->show();
        });
    });
}

void MainScene::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pixmap;
    pixmap.load(":/assets/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pixmap);

    // 画背景上的图标
    pixmap.load(":/assets/Title.png");
    pixmap = pixmap.scaled((int) (pixmap.width() * 0.5), (int) (pixmap.height() * 0.5));
    painter.drawPixmap(10, 30, pixmap);
}

MainScene::~MainScene() {
    delete ui;
}
